#include <main.h>
#include <paddr.h>
#include <stdbool.h>
#include <stdint.h>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <dlfcn.h>
#include <string>
#include <unistd.h>

#include "Vverilator_top.h"
#include "Vverilator_top___024root.h"
#include "Vverilator_top_verilator_top.h"
#include "verilated_fst_c.h"

VerilatedFstC* tfp = new VerilatedFstC;
vluint64_t main_time = 0;
Vverilator_top* top = new Vverilator_top;

namespace {

enum : uint32_t { DIFFTEST_TO_REF = 1 };

static constexpr uint32_t kDefaultStopPc = 0x1c000100u;

using difftest_init_t = void (*)();
using difftest_memcpy_t = void (*)(uint64_t addr, void* buf, size_t n,
                                   bool direction);
using difftest_exec_t = void (*)(uint64_t n);
using isa_reg_display_t = void (*)();

static constexpr size_t kRefPcOffset = 0x100;

struct ShadowState {
    uint32_t gpr[32];
    uint32_t pc;
};

struct CommitInfo {
    bool valid;
    bool wen;
    uint32_t pc;
    uint32_t inst;
    uint32_t wnum;
    uint32_t wdata;
};

struct DifftestProxy {
    void* handle = NULL;
    const char* so_path = NULL;
    difftest_init_t init = NULL;
    difftest_memcpy_t memcpy = NULL;
    difftest_exec_t exec = NULL;
    uint8_t* cpu = NULL;
    isa_reg_display_t isa_reg_display = NULL;

    void close() {
        if (handle != NULL) {
            dlclose(handle);
            handle = NULL;
        }
    }
};

DifftestProxy proxy;
ShadowState dut_shadow = {};
uint64_t commit_cnt = 0;
bool verbose_commit = false;
uint32_t stop_pc = kDefaultStopPc;
bool difftest_failed = false;

static bool try_file(const char* path) {
    return (path != NULL && path[0] != '\0' && access(path, F_OK) == 0);
}

static const char* resolve_ref_so() {
    const char* env_so = getenv("LA_DIFFTEST_REF_SO");
    if (try_file(env_so)) {
        return env_so;
    }

    const char* chiplab_home = getenv("CHIPLAB_HOME");
    if (chiplab_home != NULL && chiplab_home[0] != '\0') {
        static std::string by_env;
        by_env = std::string(chiplab_home) +
                 "/toolchains/nemu/la32r-nemu-interpreter-so";
        if (try_file(by_env.c_str())) {
            return by_env.c_str();
        }
    }

    const char* candidates[] = {
        "/home/luyoung/chiplab/toolchains/nemu/la32r-nemu-interpreter-so",
        "../chiplab/toolchains/nemu/la32r-nemu-interpreter-so",
        "../../chiplab/toolchains/nemu/la32r-nemu-interpreter-so",
        NULL,
    };

    for (int i = 0; candidates[i] != NULL; i++) {
        if (try_file(candidates[i])) {
            return candidates[i];
        }
    }
    return NULL;
}

static uint32_t parse_stop_pc() {
    const char* env = getenv("LA_STOP_PC");
    if (env == NULL || env[0] == '\0') {
        return kDefaultStopPc;
    }

    char* end = NULL;
    unsigned long v = strtoul(env, &end, 0);
    if (end == env || *end != '\0' || v > 0xffffffffUL) {
        fprintf(stderr,
                "Warning: invalid LA_STOP_PC='%s', fallback to 0x%08x\n", env,
                kDefaultStopPc);
        return kDefaultStopPc;
    }
    return (uint32_t)v;
}

static bool parse_verbose() {
    const char* env = getenv("LA_DIFFTEST_VERBOSE");
    if (env == NULL || env[0] == '\0') {
        return false;
    }
    return !(strcmp(env, "0") == 0 || strcmp(env, "false") == 0 ||
             strcmp(env, "FALSE") == 0);
}

static bool must_dlsym(void** out, const char* symbol) {
    dlerror();
    *out = dlsym(proxy.handle, symbol);
    const char* err = dlerror();
    if (err != NULL || *out == NULL) {
        fprintf(stderr, "dlsym('%s') failed: %s\n", symbol,
                err == NULL ? "(null)" : err);
        return false;
    }
    return true;
}

static bool init_difftest() {
    const char* so = resolve_ref_so();
    if (so == NULL) {
        fprintf(stderr,
                "Cannot find la32r-nemu-interpreter-so.\n"
                "Set LA_DIFFTEST_REF_SO or CHIPLAB_HOME first.\n");
        return false;
    }

#if defined(__linux__)
    int flags = RTLD_LAZY;
#ifdef RTLD_DEEPBIND
    flags |= RTLD_DEEPBIND;
#endif
    proxy.handle = dlopen(so, flags);
#else
    proxy.handle = dlopen(so, RTLD_LAZY);
#endif
    if (proxy.handle == NULL) {
        fprintf(stderr, "dlopen('%s') failed: %s\n", so, dlerror());
        return false;
    }
    proxy.so_path = so;

    if (!must_dlsym((void**)&proxy.init, "difftest_init") ||
        !must_dlsym((void**)&proxy.memcpy, "difftest_memcpy") ||
        !must_dlsym((void**)&proxy.exec, "difftest_exec") ||
        !must_dlsym((void**)&proxy.cpu, "cpu")) {
        proxy.close();
        return false;
    }

    dlerror();
    proxy.isa_reg_display =
        (isa_reg_display_t)dlsym(proxy.handle, "isa_reg_display");
    (void)dlerror();

    proxy.init();

    size_t img_size = get_loaded_img_size();
    const char* img_path = get_loaded_img_path();
    if (img_size == 0) {
        fprintf(stderr,
                "Invalid loaded image size = 0. Make sure load_inst() succeeds.\n");
        return false;
    }

    void* img_base = padd2host(RESET_VECTOR);
    proxy.memcpy(RESET_VECTOR, img_base, img_size, DIFFTEST_TO_REF);

    memset(&dut_shadow, 0, sizeof(dut_shadow));
    dut_shadow.pc = RESET_VECTOR;

    printf("Use NEMU ref so: %s\n", proxy.so_path);
    printf("Sync image to REF: %s (size=%zu, base=0x%08x)\n",
           img_path == NULL ? "(unknown)" : img_path, img_size, RESET_VECTOR);
    return true;
}

static CommitInfo sample_commit() {
    CommitInfo info = {};
    info.valid = top->rootp->verilator_top->debug_wb_valid;
    info.pc = top->rootp->verilator_top->debug_wb_pc;
    info.inst = top->rootp->verilator_top->debug_wb_inst;
    info.wen = (top->rootp->verilator_top->debug_wb_rf_wen == 0xf);
    info.wnum = top->rootp->verilator_top->debug_wb_rf_wnum;
    info.wdata = top->rootp->verilator_top->debug_wb_rf_wdata;
    return info;
}

static uint32_t ref_gpr(uint32_t idx) {
    return reinterpret_cast<uint32_t*>(proxy.cpu)[idx];
}

static uint32_t ref_pc() {
    return *reinterpret_cast<uint32_t*>(proxy.cpu + kRefPcOffset);
}

static void apply_commit(const CommitInfo& c) {
    dut_shadow.pc = c.pc;
    if (c.wen && c.wnum != 0) {
        dut_shadow.gpr[c.wnum] = c.wdata;
    }
    dut_shadow.gpr[0] = 0;
}

static void print_reg_mismatch(uint32_t idx, uint32_t dut, uint32_t ref,
                               uint32_t pc) {
    printf("  gpr[%02u] mismatch at pc=0x%08x: DUT=0x%08x REF=0x%08x\n", idx, pc,
           dut, ref);
}

static bool compare_with_ref(const CommitInfo& c, uint32_t ref_pc_before_exec) {
    bool ok = true;

    if (dut_shadow.pc != ref_pc_before_exec) {
        printf("  pc mismatch: DUT=0x%08x REF=0x%08x\n", dut_shadow.pc,
               ref_pc_before_exec);
        ok = false;
    }

    for (uint32_t i = 0; i < 32; i++) {
        uint32_t ref_val = ref_gpr(i);
        if (dut_shadow.gpr[i] != ref_val) {
            print_reg_mismatch(i, dut_shadow.gpr[i], ref_val, c.pc);
            ok = false;
        }
    }

    if (c.wen && c.wnum != 0 && ref_gpr(c.wnum) != c.wdata) {
        printf("  wb mismatch: pc=0x%08x wnum=%u DUT=0x%08x REF=0x%08x\n", c.pc,
               c.wnum, c.wdata, ref_gpr(c.wnum));
        ok = false;
    }

    if (!ok) {
        printf("Commit #%llu failed: pc=0x%08x inst=0x%08x wen=%u wnum=%u "
               "wdata=0x%08x\n",
               (unsigned long long)commit_cnt, c.pc, c.inst,
               c.wen ? 1u : 0u, c.wnum, c.wdata);
        if (proxy.isa_reg_display != NULL) {
            printf("\nREF register dump:\n");
            proxy.isa_reg_display();
        }
    }

    return ok;
}

enum class StepResult {
    kContinue,
    kPass,
    kMismatch,
};

static StepResult difftest_step() {
    CommitInfo c = sample_commit();
    if (!c.valid) {
        return StepResult::kContinue;
    }

    commit_cnt++;

    if (verbose_commit) {
        printf("[commit %llu] pc=0x%08x inst=0x%08x wen=%u wnum=%u wdata=0x%08x\n",
               (unsigned long long)commit_cnt, c.pc, c.inst,
               c.wen ? 1u : 0u, c.wnum, c.wdata);
    }

    apply_commit(c);
    uint32_t ref_pc_before_exec = ref_pc();

    proxy.exec(1);

    if (!compare_with_ref(c, ref_pc_before_exec)) {
        return StepResult::kMismatch;
    }

    if (c.pc == stop_pc) {
        return StepResult::kPass;
    }

    return StepResult::kContinue;
}

}  // namespace

void step() {
    top->clk = 0;
    top->eval();
    tfp->dump(main_time);
    main_time++;

    top->clk = 1;
    top->eval();
    tfp->dump(main_time);
    main_time++;
}

void reset(int n) {
    top->rst = 1;
    while (n--) {
        step();
    }
    top->rst = 0;
}

void stepi() {
    step();
}

void cpu_exec(uint64_t n) {
    while (n) {
        StepResult result = difftest_step();
        if (result == StepResult::kMismatch) {
            difftest_failed = true;
            printf("\nDifftest failed after %llu committed instructions.\n",
                   (unsigned long long)commit_cnt);
            break;
        }
        if (result == StepResult::kPass) {
            printf("\033[32mPassed all the tests at stop pc 0x%08x\033[0m\n",
                   stop_pc);
            break;
        }

        stepi();
        n--;
    }

    printf("Committed instructions: %llu\n", (unsigned long long)commit_cnt);

    top->final();
    tfp->close();
    proxy.close();
}

void init_system() {
    verbose_commit = parse_verbose();
    stop_pc = parse_stop_pc();

    init_mem();
    load_inst();
    if (!init_difftest()) {
        exit(1);
    }

    printf("Difftest config: stop_pc=0x%08x, verbose=%s\n", stop_pc,
           verbose_commit ? "on" : "off");
}

int main(int argc, char* argv[]) {
    init_system();
    Verilated::traceEverOn(true);
    top->trace(tfp, 99);
    tfp->open("wave.vcd");
    reset(1);
    cpu_exec((uint64_t)-1);
    return difftest_failed ? 1 : 0;
}
