#include <sys/time.h>
#include "testbench.h"
#include <chrono>

#if defined(PERF_IC) || defined(PERF_DC) || defined(PERF_BPU)
namespace {

double percent(unsigned long long value, unsigned long long total) {
    return total == 0 ? 0.0 : 100.0 * (double)value / (double)total;
}

}  // namespace
#endif

CpuTestbench::CpuTestbench(int argc, char **argv, char **env, vluint64_t *main_time) : CpuTool(nullptr) {
    m_trace = NULL;
    this->parse_args(argc, argv, env);
    rand64 = new Rand64(rand_path);
    top = new Vtop;
    struct UART_STA uart_status;
    if (restore_bp_time != 0) {
        restore_model(main_time, top_restore_bp_file);
        if (restore_bp_time != *main_time) {
            printf("Warning: restore_bp_time is not equal with %s's main_time\n", top_restore_bp_file);
        }
    }
    emu = new Emulator(top, "./", simu_trace_file, uart_output_file, ram_file, data_vlog_file);
    ram = new CpuRam(top, rand64, *main_time, &uart_status, mem_trace_file);
    if (restore_bp_time != 0) {
        uart_config = uart_status.uart_config;
        uart_div_set = uart_status.uart_div_set;
        div_reinit = uart_status.div_reinit;
        div_val_1 = uart_status.div_val_1;
        div_val_2 = uart_status.div_val_2;
        div_val_3 = uart_status.div_val_3;
    }
    //printf("uart_config is %d\n", uart_config);
    //printf("uart_div_set is %d\n", uart_div_set);
    //printf("div_reinit is %d\n", div_reinit);
    //printf("div_val_1 id %d\n", div_val_1);
    //printf("div_val_2 id %d\n", div_val_2);
    //printf("div_val_3 id %d\n", div_val_3);
    time_limit = new CpuTimeLimit();
    uart = new UARTSIM(0, uart_output_file); //output to terminal
    //uart->setup(0x000010); //param set
    //uart->setup(288); //param set
    uart->setup(uart_config);
}

void CpuTestbench::save_model(vluint64_t main_time, const char *top_filename) {
#ifndef RAND_TEST
    VerilatedSave os;
    os.open(top_filename);
    os << main_time;
    os << *top;
    printf("save top model break point %ldns to %s\n", main_time, top_filename);
#endif
}

void CpuTestbench::restore_model(vluint64_t *main_time, const char *top_filename) {
#ifndef RAND_TEST
    VerilatedRestore os;
    os.open(top_filename);
    os >> *main_time;
    os >> *top;
    printf("restore top model break point %ldns from %s\n", *main_time, top_filename);
#endif
}

void CpuTestbench::display_exit_cause(vluint64_t& main_time,int emask) {
    if(simu_quiet)return;
    fprintf(stderr,"\n");
    fprintf(stderr,"Terminated at %lu ns.\n",main_time);
    if(emask&status_exit) {
        fprintf(stderr,"Test exit.\n");
        if(emask&status_time_limit){
            fprintf(stderr,"Time limit exceeded.\n");
        }
        if(emask&status_test_end) {
            fprintf(stderr,"Reached test end PC.\n");
        }
    }
    if(emask&status_trace_err) {
        fprintf(stderr,"%s Error(Code:0x%x)\n",
                (emask&status_trace_err_pc)?
                (emask&status_trace_err_rf)?"Both":"Path":
                (emask&status_trace_err_rf)?"Data":"Perf"
                ,emask);
    }
    if(emask&status_unhandled) {
        fprintf(stderr,"Reached unhandled situation.\n");
    }
    if(emask&status_fork_forward){
        fprintf(stderr,"Reached fork forwar(error point + 10 clk).\n");
    }
}

#if defined(PERF_IC) || defined(PERF_DC) || defined(PERF_BPU)
void CpuTestbench::sample_perf() {
#ifdef PERF_IC
    perf_ic_access += top->perf_ic_access;
    perf_ic_hit    += top->perf_ic_hit;
    perf_ic_miss   += top->perf_ic_miss;
    perf_ic_refill += top->perf_ic_refill;
#endif

#ifdef PERF_DC
    perf_dc_access += top->perf_dc_access;
    perf_dc_read   += top->perf_dc_read;
    perf_dc_write  += top->perf_dc_write;
    perf_dc_hit    += top->perf_dc_hit;
    perf_dc_miss   += top->perf_dc_miss;
    perf_dc_refill += top->perf_dc_refill;
    perf_dc_evict  += top->perf_dc_evict;
#endif

#ifdef PERF_BPU
    if (top->bpu_perf_valid) {
        bool is_branch = top->bpu_perf_is_branch;
        bool is_jump = top->bpu_perf_is_jump;
        bool is_direct_jump = top->bpu_perf_is_direct_jump;
        bool is_jirl = top->bpu_perf_is_jirl;
        bool is_ret_jirl = top->bpu_perf_is_ret_jirl;
        bool is_indirect_jirl = top->bpu_perf_is_indirect_jirl;
        bool correct = top->bpu_perf_correct;
        bool direction_miss = top->bpu_perf_direction_miss;
        bool target_miss = top->bpu_perf_target_miss;

        perf_bpu_resolve++;
        perf_bpu_branch += is_branch;
        perf_bpu_jump += is_jump;
        perf_bpu_pred_taken += top->bpu_perf_pred_taken;
        perf_bpu_actual_taken += top->bpu_perf_actual_taken;
        perf_bpu_correct += correct;
        perf_bpu_wrong += !correct;
        perf_bpu_direction_miss += direction_miss;
        perf_bpu_target_miss += target_miss;
        perf_bpu_exu_flush += top->bpu_perf_exu_flush;

        perf_bpu_branch_correct += is_branch && correct;
        perf_bpu_jump_correct += is_jump && correct;
        perf_bpu_branch_direction_miss += is_branch && direction_miss;
        perf_bpu_jump_direction_miss += is_jump && direction_miss;
        perf_bpu_branch_target_miss += is_branch && target_miss;
        perf_bpu_jump_target_miss += is_jump && target_miss;

        perf_bpu_direct_jump += is_direct_jump;
        perf_bpu_direct_jump_correct += is_direct_jump && correct;
        perf_bpu_direct_jump_direction_miss += is_direct_jump && direction_miss;
        perf_bpu_direct_jump_target_miss += is_direct_jump && target_miss;

        perf_bpu_jirl += is_jirl;
        perf_bpu_jirl_correct += is_jirl && correct;
        perf_bpu_jirl_direction_miss += is_jirl && direction_miss;
        perf_bpu_jirl_target_miss += is_jirl && target_miss;

        perf_bpu_ret_jirl += is_ret_jirl;
        perf_bpu_ret_jirl_correct += is_ret_jirl && correct;
        perf_bpu_ret_jirl_direction_miss += is_ret_jirl && direction_miss;
        perf_bpu_ret_jirl_target_miss += is_ret_jirl && target_miss;

        perf_bpu_indirect_jirl += is_indirect_jirl;
        perf_bpu_indirect_jirl_correct += is_indirect_jirl && correct;
        perf_bpu_indirect_jirl_direction_miss += is_indirect_jirl && direction_miss;
        perf_bpu_indirect_jirl_target_miss += is_indirect_jirl && target_miss;
    }
#endif
}

void CpuTestbench::print_perf() const {
#ifdef PERF_IC
    printf("Biloong ICache:\n");
    printf("  access=%llu hit=%llu miss=%llu refill=%llu hit_rate=%.2f%%\n",
           perf_ic_access, perf_ic_hit, perf_ic_miss, perf_ic_refill,
           percent(perf_ic_hit, perf_ic_access));
#endif

#ifdef PERF_DC
    printf("Biloong DCache:\n");
    printf("  access=%llu read=%llu write=%llu hit=%llu miss=%llu refill=%llu evict=%llu hit_rate=%.2f%% read_rate=%.2f%% write_rate=%.2f%%\n",
           perf_dc_access, perf_dc_read, perf_dc_write, perf_dc_hit,
           perf_dc_miss, perf_dc_refill, perf_dc_evict,
           percent(perf_dc_hit, perf_dc_access),
           percent(perf_dc_read, perf_dc_access),
           percent(perf_dc_write, perf_dc_access));
#endif

#ifdef PERF_BPU
    printf("Biloong BPU:\n");
    printf("  resolve=%llu branch=%llu jump=%llu correct=%llu wrong=%llu accuracy=%.2f%% pred_taken=%llu actual_taken=%llu\n",
           perf_bpu_resolve, perf_bpu_branch, perf_bpu_jump,
           perf_bpu_correct, perf_bpu_wrong,
           percent(perf_bpu_correct, perf_bpu_resolve),
           perf_bpu_pred_taken, perf_bpu_actual_taken);
    printf("  miss: direction=%llu target=%llu exu_flush=%llu\n",
           perf_bpu_direction_miss, perf_bpu_target_miss,
           perf_bpu_exu_flush);
    printf("  branch: total=%llu correct=%llu accuracy=%.2f%% direction_miss=%llu target_miss=%llu\n",
           perf_bpu_branch, perf_bpu_branch_correct,
           percent(perf_bpu_branch_correct, perf_bpu_branch),
           perf_bpu_branch_direction_miss, perf_bpu_branch_target_miss);
    printf("  jump: total=%llu correct=%llu accuracy=%.2f%% direction_miss=%llu target_miss=%llu\n",
           perf_bpu_jump, perf_bpu_jump_correct,
           percent(perf_bpu_jump_correct, perf_bpu_jump),
           perf_bpu_jump_direction_miss, perf_bpu_jump_target_miss);
    printf("  direct_jump: total=%llu correct=%llu accuracy=%.2f%% direction_miss=%llu target_miss=%llu\n",
           perf_bpu_direct_jump, perf_bpu_direct_jump_correct,
           percent(perf_bpu_direct_jump_correct, perf_bpu_direct_jump),
           perf_bpu_direct_jump_direction_miss,
           perf_bpu_direct_jump_target_miss);
    printf("  jirl: total=%llu correct=%llu accuracy=%.2f%% direction_miss=%llu target_miss=%llu\n",
           perf_bpu_jirl, perf_bpu_jirl_correct,
           percent(perf_bpu_jirl_correct, perf_bpu_jirl),
           perf_bpu_jirl_direction_miss, perf_bpu_jirl_target_miss);
    printf("  ret_jirl: total=%llu correct=%llu accuracy=%.2f%% direction_miss=%llu target_miss=%llu\n",
           perf_bpu_ret_jirl, perf_bpu_ret_jirl_correct,
           percent(perf_bpu_ret_jirl_correct, perf_bpu_ret_jirl),
           perf_bpu_ret_jirl_direction_miss, perf_bpu_ret_jirl_target_miss);
    printf("  indirect_jirl: total=%llu correct=%llu accuracy=%.2f%% direction_miss=%llu target_miss=%llu\n",
           perf_bpu_indirect_jirl, perf_bpu_indirect_jirl_correct,
           percent(perf_bpu_indirect_jirl_correct, perf_bpu_indirect_jirl),
           perf_bpu_indirect_jirl_direction_miss,
           perf_bpu_indirect_jirl_target_miss);
#endif
}
#endif

long long inst_total = 0;

void CpuTestbench::simulate(vluint64_t& main_time) {
    if(!simu_quiet)fprintf(stderr,"Verilator Simulation Start.\n");
    int emask = status_call_finish;
    vluint8_t& clock = top->aclk;
    vluint8_t& reset = top->aresetn;
    long long clock_total = 0;
    int p_config;
    static const int reset_valid = 0;

    /* calculate the time of simulation */
    auto start = std::chrono::steady_clock::now();
    double timer;

#define EVAL ((clock=!clock),main_time+=1,this->eval(main_time))

    if (restore_bp_time == 0) {
        reset = reset_valid;
        clock = 0;
        //top->enable_delay = simu_bus_delay;
        //top->random_seed = simu_bus_delay_random_seed;
        //printf("random seed is %d\n", simu_bus_delay_random_seed);
        for(int i=0;i<10;i+=1){if(EVAL)break;}
    }
    clock = 0;
    top->enable_delay = simu_bus_delay;
    top->random_seed = simu_bus_delay_random_seed;

    emu->init_emu(&main_time);

    if(!EVAL) {
        reset = !reset_valid;
        emask = 0;
    #ifdef RAND_TEST
        int init_error = rand64->init_all();
        if (init_error) {
            printf("RAND TEST INIT FAILED\n");
            return ;
        }
	ram->read_random_vlog();
    #endif
        printf("Start\n");
        while(true){
            // Simulate until exit
            if ((main_time <= (save_bp_time+1) && main_time >= (save_bp_time-1)) && (break_once == 0)) {
                if (main_time != save_bp_time) {
                    printf("Warning: real break point main time is %ld\n", main_time);
                }

                struct UART_STA uart_status;
                uart_status.uart_config = uart_config;
                uart_status.uart_div_set = uart_div_set;
                uart_status.div_reinit = div_reinit;
                uart_status.div_val_1 = div_val_1;
                uart_status.div_val_2 = div_val_2;
                uart_status.div_val_3 = div_val_3;

                ram->breakpoint_save(main_time, ram_save_bp_file, &uart_status);
                save_model(main_time, top_save_bp_file);
                printf("save break point over!\n");
                break_once = 1;
            }
            emask|= ram->process(main_time);
            //uart receive
            top->uart_rx = (*uart)(top->uart_tx);
            //uart reconfig
            if(top->uart_ctr_bus[UART_BUS_ENAB] && top->uart_ctr_bus[UART_BUS_RW]) {
                switch(top->uart_ctr_bus[UART_BUS_ADDR]) {
                    case 0:
                        if(uart_div_set == true) {
                            div_val_1 = top->uart_ctr_bus[UART_BUS_DATAI];
                            div_reinit = true;
                        }
                        break;
                    case 1:
                        if(uart_div_set == true) {
                            div_val_2 = top->uart_ctr_bus[UART_BUS_DATAI] << 8;
                            div_reinit = true;
                        }
                        break;
                    case 2:
                        if(uart_div_set == true) {
                            div_val_3 = top->uart_ctr_bus[UART_BUS_DATAI] << 16;
                            div_reinit = true;
                        }
                        break;
                    case 3:
                        if(uart_div_set == false && (top->uart_ctr_bus[UART_BUS_DATAI] & 0x80) == 0x80) {
                            uart_div_set = true;
                        }
                        else if(uart_div_set == true && (top->uart_ctr_bus[UART_BUS_DATAI] & 0x80) == 0) {
                            if (div_reinit == true) {
                                uart_config = (uart_config & 0xff000000) | ((div_val_1 + div_val_2 + div_val_3) * 16);
                                div_val_1 = 0;
                                div_val_2 = 0;
                                div_val_3 = 0;
                                div_reinit = false;
                            }
                            uart_div_set = false;
                        }
                        switch (top->uart_ctr_bus[UART_BUS_DATAI] & 0x30) {
                            case 0x00:
                                p_config = 0x0;
                                break;
                            case 0x10:
                                p_config = 0x1;
                                break;
                            case 0x20:
                                p_config = 0x3;
                                break;
                            case 0x30:
                                p_config = 0x2;
                                break;
                            default:
                                p_config = 0x0;
                        }
                        uart_config = (uart_config & 0x00ffffff) | ((3 - (top->uart_ctr_bus[UART_BUS_DATAI] & 0x3)) << 28)
                                      | ((top->uart_ctr_bus[UART_BUS_DATAI] & 0x4) << 25)
                                      | ((top->uart_ctr_bus[UART_BUS_DATAI] & 0x8) << 23)
                                      | (p_config << 24);
                        /*
                        //set bit
                        uart_config = (uart_config & 0x0fffffff) | ((3 - (top->datai & 0x3)) << 28);
                        //set stop
                        uart_config = (uart_config & 0xf7ffffff) | ((top->datai & 0x4) << 25);
                        //set parity
                        uart_config = (uart_config & 0xfbffffff) | ((top->datai & 0x8) << 23);
                        //set fixdp and evenp
                        uart_config = (uart_config & 0xfcffffff) | (p_config << 24);
                        */
                        //debug
                        //printf("uart datai is %x\n", top->uart_ctr_bus[UART_BUS_DATAI]);
                        //printf("uart config is %x\n", uart_config);
                        uart->setup(uart_config);
                        break;
                }
            }
            if(EVAL)break;
            emask |= time_limit->process(main_time);
            emask |= emu->process();
    #ifdef TRACE_COMP
            if(emu->dm->check_end()) {
                emask |= status_test_end;
                // printf("RECEIVE NEMU END HERE, emask = %x\n",emask);
            }
    #endif
            if(EVAL)break;
            if(emask)break;
            clock_total += 1;
        }
    }
    printf("total clock is %lld\n", clock_total);
    auto end = std::chrono::steady_clock::now();
    #ifdef TRACE_COMP
    if(!(emask & status_test_end)){
        emu->set_need_wakeup();
        for (int i = 0; i < NUM_CORES; i++) {
            difftest[i]->display();
        }
    }
    #endif

    printf("\n==============================================================\n");
    printf("total clock \t\tis %lld\n", clock_total);
    printf("total instruction \tis %lld\n", inst_total);
    printf("instruction per cycle\tis %lf\n", (double) inst_total / clock_total);
#if defined(PERF_IC) || defined(PERF_DC) || defined(PERF_BPU)
    print_perf();
#endif
    printf("simulation time \tis %lf s\n", std::chrono::nanoseconds(end-start).count() / 1000000000.0);
    printf("difftest time \t\tis %lf s\n", diff_nano_seconds.count() / 1000000000.0);
    printf("nemu_step time \t\tis %lf s\n", nemu_nano_seconds.count() / 1000000000.0);
    printf("verilator eval time \tis %lf s\n", total_nano_seconds.count() / 1000000000.0);
    printf("==============================================================\n");

    EVAL;
#undef EVAL
    display_exit_cause(main_time,emask);
    delete emu;
    close();
}

void CpuTestbench::opentrace(const char *wavename) {
#if defined(DUMP_VCD) || defined(DUMP_FST)
    if (!m_trace&&!enable_fork) {
    #ifdef DUMP_VCD
        m_trace = new VerilatedVcdC;
    #endif
    #ifdef DUMP_FST
        m_trace = new VerilatedFstC;
    #endif
        top->trace(m_trace, 99);
        m_trace->open(wavename);
    }
#else
    (void)wavename;
#endif
}

void CpuTestbench::close(void) {
#if defined(DUMP_VCD) || defined(DUMP_FST)
    if (m_trace) {
        m_trace->flush();
        m_trace->close();
        m_trace = NULL;
    }
#endif
}

CpuTestbench::~CpuTestbench() {
    // Final model cleanup
    top->final();
    //  Coverage analysis (since test passed)
#if VM_COVERAGE
    Verilated::mkdir("logs");
    VerilatedCov::write("logs/coverage.dat");
#endif
    // Destroy model
    delete time_limit;
    time_limit = nullptr;
    delete ram;
    ram = nullptr;
    delete top;
    top = nullptr;
}
