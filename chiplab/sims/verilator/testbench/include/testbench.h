#ifndef CHIPLAB_TESTBENCH_H
#define CHIPLAB_TESTBENCH_H

#ifdef DUMP_FST
#include <verilated_fst_c.h>
#endif
#ifdef DUMP_VCD
#include <verilated_vcd_c.h>
#endif
#include <verilated_threads.h>
#include <verilated_save.h>
#include <chrono>
#include "common.h"
#include "ram.h"
#include "time_limit.h"
#include "rand64.h"
#include "emu.h"

class CpuTestbench:CpuTool {
public:
    Emulator *emu;
    CpuRam* ram;
    CpuTimeLimit* time_limit;
    Rand64* rand64; 
    UARTSIM* uart;
#if defined(DUMP_VCD) || defined(DUMP_FST)
    #ifdef DUMP_VCD
    VerilatedVcdC	*m_trace; 
    #endif 
    #ifdef DUMP_FST 
    VerilatedFstC	*m_trace;
    #endif
#else
    void* m_trace;
#endif

    /* control information to satisfy different waveform generation requirements */
    unsigned long dump_next_start;
	unsigned long tail_base;
	char break_once = 0;

	/* uart */
    unsigned int uart_config = 16;
    bool uart_div_set = false;
    bool div_reinit = false;
    unsigned int div_val_1 = 0;
    unsigned int div_val_2 = 0;
    unsigned int div_val_3 = 0;

#if defined(PERF_IC) || defined(PERF_DC) || defined(PERF_BPU)
    void sample_perf();
    void print_perf() const;
#endif

#ifdef PERF_IC
    unsigned long long perf_ic_access = 0;
    unsigned long long perf_ic_hit = 0;
    unsigned long long perf_ic_miss = 0;
    unsigned long long perf_ic_refill = 0;
#endif

#ifdef PERF_DC
    unsigned long long perf_dc_access = 0;
    unsigned long long perf_dc_read = 0;
    unsigned long long perf_dc_write = 0;
    unsigned long long perf_dc_hit = 0;
    unsigned long long perf_dc_miss = 0;
    unsigned long long perf_dc_refill = 0;
    unsigned long long perf_dc_evict = 0;
#endif

#ifdef PERF_BPU
    unsigned long long perf_bpu_resolve = 0;
    unsigned long long perf_bpu_branch = 0;
    unsigned long long perf_bpu_jump = 0;
    unsigned long long perf_bpu_pred_taken = 0;
    unsigned long long perf_bpu_actual_taken = 0;
    unsigned long long perf_bpu_correct = 0;
    unsigned long long perf_bpu_wrong = 0;
    unsigned long long perf_bpu_direction_miss = 0;
    unsigned long long perf_bpu_target_miss = 0;
    unsigned long long perf_bpu_exu_flush = 0;
    unsigned long long perf_bpu_branch_correct = 0;
    unsigned long long perf_bpu_jump_correct = 0;
    unsigned long long perf_bpu_branch_direction_miss = 0;
    unsigned long long perf_bpu_jump_direction_miss = 0;
    unsigned long long perf_bpu_branch_target_miss = 0;
    unsigned long long perf_bpu_jump_target_miss = 0;
    unsigned long long perf_bpu_direct_jump = 0;
    unsigned long long perf_bpu_direct_jump_correct = 0;
    unsigned long long perf_bpu_direct_jump_direction_miss = 0;
    unsigned long long perf_bpu_direct_jump_target_miss = 0;
    unsigned long long perf_bpu_jirl = 0;
    unsigned long long perf_bpu_jirl_correct = 0;
    unsigned long long perf_bpu_jirl_direction_miss = 0;
    unsigned long long perf_bpu_jirl_target_miss = 0;
    unsigned long long perf_bpu_ret_jirl = 0;
    unsigned long long perf_bpu_ret_jirl_correct = 0;
    unsigned long long perf_bpu_ret_jirl_direction_miss = 0;
    unsigned long long perf_bpu_ret_jirl_target_miss = 0;
    unsigned long long perf_bpu_indirect_jirl = 0;
    unsigned long long perf_bpu_indirect_jirl_correct = 0;
    unsigned long long perf_bpu_indirect_jirl_direction_miss = 0;
    unsigned long long perf_bpu_indirect_jirl_target_miss = 0;
#endif

    /*  */
    void save_model(vluint64_t main_time, const char* top_filename);
    void restore_model(vluint64_t* main_time, const char* top_filename);

    CpuTestbench(int argc, char** argv, char** env, vluint64_t* main_time);
    ~CpuTestbench();

    /* called after simulation is over to display exit cause */
    void display_exit_cause(vluint64_t& main_time,int emask);

    /* simulate [significant function] */
    void simulate(vluint64_t& main_time);

    /* open waveform file */
    virtual	void opentrace(const char *wavename);

    /* Close a trace file */
    virtual void close(void);

    std::chrono::nanoseconds total_nano_seconds = std::chrono::nanoseconds(0);

    /* Time passes */
    inline int eval(vluint64_t& main_time) {
        auto start = std::chrono::steady_clock::now();
        top->eval();
        auto end = std::chrono::steady_clock::now();
        std::chrono::nanoseconds elapsed_seconds = std::chrono::nanoseconds(end-start);
        total_nano_seconds += elapsed_seconds;

#if defined(PERF_IC) || defined(PERF_DC) || defined(PERF_BPU)
        if (top->aclk && top->aresetn) {
            sample_perf();
        }
#endif

#if defined(DUMP_VCD) || defined(DUMP_FST)
        char waveform_name[128];
        if(m_trace != NULL) {
            if(!enable_fork){
                #ifdef SLICE_WAVEFORM 
                    #ifdef TAIL_WAVEFORM
                        if (main_time >= tail_base+WAVEFORM_TAIL_SIZE) {
                            tail_base += WAVEFORM_TAIL_SIZE;
                        }
                        if(main_time >= dump_next_start) {
                            close();
                            dump_next_start += WAVEFORM_SLICE_SIZE; 
                            #ifdef DUMP_VCD
                            sprintf(waveform_name, "./logs/simu_trace_%ldns_%ldns.vcd", main_time - tail_base, dump_next_start - tail_base);
                            #endif
                            #ifdef DUMP_FST
                            sprintf(waveform_name, "./logs/simu_trace_%ldns_%ldns.fst", main_time - tail_base, dump_next_start - tail_base);
                            #endif
                            opentrace(waveform_name);
                        }
                    #else
                        if(main_time >= dump_next_start) {
                            close();
                            dump_next_start += WAVEFORM_SLICE_SIZE; 
                            #ifdef DUMP_VCD
                            sprintf(waveform_name, "./logs/simu_trace_%ldns_%ldns.vcd", main_time, dump_next_start);
                            #endif
                            #ifdef DUMP_FST
                            sprintf(waveform_name, "./logs/simu_trace_%ldns_%ldns.fst", main_time, dump_next_start);
                            #endif
                            opentrace(waveform_name);
                        }
                    #endif
                #endif
                #ifdef TAIL_WAVEFORM
                if (main_time >= tail_base+WAVEFORM_TAIL_SIZE) {
                    tail_base += WAVEFORM_TAIL_SIZE;
                    close();
                    #ifdef DUMP_VCD 
                    opentrace("./logs/simu_trace.vcd");
                    #endif 
                    #ifdef DUMP_FST
                    opentrace("./logs/simu_trace.fst"); 
                    #endif 
                }
                #endif
            }
            m_trace->dump(main_time);
        } else if (main_time >= dump_delay && dump_waveform && !enable_fork) {
            #ifdef SLICE_WAVEFORM 
            	#ifdef TAIL_WAVEFORM
                	dump_next_start = dump_delay+WAVEFORM_SLICE_SIZE;
					tail_base = dump_delay;
                	#ifdef DUMP_VCD
                	sprintf(waveform_name, "./logs/simu_trace_%ldns_%ldns.vcd", dump_delay - tail_base, dump_next_start - tail_base);
                	#endif
                	#ifdef DUMP_FST
                	sprintf(waveform_name, "./logs/simu_trace_%ldns_%ldns.fst", dump_delay - tail_base, dump_next_start - tail_base);
                	#endif
                	opentrace(waveform_name);
				#else
                	dump_next_start = dump_delay+WAVEFORM_SLICE_SIZE;
                	#ifdef DUMP_VCD
                	sprintf(waveform_name, "./logs/simu_trace_%ldns_%ldns.vcd", dump_delay, dump_next_start);
                	#endif
                	#ifdef DUMP_FST
                	sprintf(waveform_name, "./logs/simu_trace_%ldns_%ldns.fst", dump_delay, dump_next_start);
                	#endif
                	opentrace(waveform_name);
				#endif
			#else
				tail_base = dump_delay;
                #ifdef DUMP_VCD 
                opentrace("./logs/simu_trace.vcd");
                #endif 
                #ifdef DUMP_FST
                opentrace("./logs/simu_trace.fst"); 
                #endif 
            #endif
            printf("Dump Start at %ld ns\n",main_time);
            m_trace->dump(main_time);
        }
#endif
        return Verilated::gotFinish();
    }

};

#endif  // CHIPLAB_TESTBENCH_H
