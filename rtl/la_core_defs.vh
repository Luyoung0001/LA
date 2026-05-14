`ifndef LA_CORE_DEFS_VH
`define LA_CORE_DEFS_VH

// Global architectural widths.
`define LA_XLEN              32
`define LA_ILEN              32
`define LA_REG_ADDR_WIDTH     5
`define LA_CSR_ADDR_WIDTH    14
`define LA_EPOCH_WIDTH        2
`define LA_PRED_META_WIDTH    8
`define LA_MEM_SEQ_WIDTH      4

// Feature switches. Makefile may override these with Verilator/Vivado
// defines, but every RTL module should consume the normalized macros below.
`ifndef LA_TLB_ENABLE
`define LA_TLB_ENABLE 0
`endif

`ifndef LA_L1I_ENABLE
`define LA_L1I_ENABLE 0
`endif

`ifndef LA_L1D_ENABLE
`define LA_L1D_ENABLE 0
`endif

`ifndef LA_L2_ENABLE
`define LA_L2_ENABLE 0
`endif

`ifndef LA_BPU_ENABLE
`define LA_BPU_ENABLE 0
`endif

`ifndef LA_FETCH_BUFFER_ENABLE
`define LA_FETCH_BUFFER_ENABLE 0
`endif

`ifndef LA_ITCM_ENABLE
`define LA_ITCM_ENABLE 0
`endif

`ifndef LA_CACHE_OP_STRICT_ENABLE
`define LA_CACHE_OP_STRICT_ENABLE 0
`endif

// Cache/memory defaults. These are interface constants, not implementation
// promises for the current stubs.
`define LA_L1_LINE_BYTES     16
`define LA_L2_LINE_BYTES     32

// Operation classes.
`define LA_OP_CLASS_WIDTH     4
`define LA_OP_CLASS_NONE      4'd0
`define LA_OP_CLASS_ALU       4'd1
`define LA_OP_CLASS_BRANCH    4'd2
`define LA_OP_CLASS_LOAD      4'd3
`define LA_OP_CLASS_STORE     4'd4
`define LA_OP_CLASS_CSR       4'd5
`define LA_OP_CLASS_MDU       4'd6
`define LA_OP_CLASS_TLB       4'd7
`define LA_OP_CLASS_BARRIER   4'd8

// ALU operations.
`define LA_ALU_OP_WIDTH       5
`define LA_ALU_ADD            5'd0
`define LA_ALU_SUB            5'd1
`define LA_ALU_SLT            5'd2
`define LA_ALU_SLTU           5'd3
`define LA_ALU_AND            5'd4
`define LA_ALU_OR             5'd5
`define LA_ALU_XOR            5'd6
`define LA_ALU_NOR            5'd7
`define LA_ALU_SLL            5'd8
`define LA_ALU_SRL            5'd9
`define LA_ALU_SRA            5'd10
`define LA_ALU_LU12I          5'd11
`define LA_ALU_PASS1          5'd12
`define LA_ALU_PASS2          5'd13

// Branch operations.
`define LA_BR_OP_WIDTH        4
`define LA_BR_NONE            4'd0
`define LA_BR_B               4'd1
`define LA_BR_BL              4'd2
`define LA_BR_JIRL            4'd3
`define LA_BR_BEQ             4'd4
`define LA_BR_BNE             4'd5
`define LA_BR_BLT             4'd6
`define LA_BR_BGE             4'd7
`define LA_BR_BLTU            4'd8
`define LA_BR_BGEU            4'd9

// Memory operations.
`define LA_MEM_OP_WIDTH       4
`define LA_MEM_NONE           4'd0
`define LA_MEM_LD_B           4'd1
`define LA_MEM_LD_H           4'd2
`define LA_MEM_LD_W           4'd3
`define LA_MEM_LD_BU          4'd4
`define LA_MEM_LD_HU          4'd5
`define LA_MEM_ST_B           4'd6
`define LA_MEM_ST_H           4'd7
`define LA_MEM_ST_W           4'd8
`define LA_MEM_LL_W           4'd9
`define LA_MEM_SC_W           4'd10

// CSR/MDU operations.
`define LA_CSR_OP_WIDTH       3
`define LA_CSR_NONE           3'd0
`define LA_CSR_RD             3'd1
`define LA_CSR_WR             3'd2
`define LA_CSR_XCHG           3'd3

`define LA_MDU_OP_WIDTH       4
`define LA_MDU_NONE           4'd0
`define LA_MDU_MUL_W          4'd1
`define LA_MDU_MULH_W         4'd2
`define LA_MDU_MULH_WU        4'd3
`define LA_MDU_DIV_W          4'd4
`define LA_MDU_DIV_WU         4'd5
`define LA_MDU_MOD_W          4'd6
`define LA_MDU_MOD_WU         4'd7

// Redirect reasons.
`define LA_REDIRECT_REASON_WIDTH 4
`define LA_REDIRECT_NONE         4'd0
`define LA_REDIRECT_BRANCH       4'd1
`define LA_REDIRECT_EXCEPTION    4'd2
`define LA_REDIRECT_ERTN         4'd3
`define LA_REDIRECT_INTERRUPT    4'd4

// Packet widths.
`define LA_FETCH_PKT_WIDTH   109
`define LA_UOP_PKT_WIDTH     211
`define LA_PROD_STATUS_WIDTH  50
`define LA_MEM_REQ_WIDTH      83
`define LA_MEM_RESP_WIDTH     40
`define LA_REDIRECT_PKT_WIDTH  44
`define LA_COMMIT_PKT_WIDTH  126

// fetch_pkt slices.
`define LA_FETCH_VALID           0
`define LA_FETCH_PC_H           32
`define LA_FETCH_PC_L            1
`define LA_FETCH_INST_H         64
`define LA_FETCH_INST_L         33
`define LA_FETCH_EPOCH_H        66
`define LA_FETCH_EPOCH_L        65
`define LA_FETCH_PRED_TAKEN     67
`define LA_FETCH_PRED_TARGET_H  99
`define LA_FETCH_PRED_TARGET_L  68
`define LA_FETCH_PRED_META_H   107
`define LA_FETCH_PRED_META_L   100
`define LA_FETCH_FAULT         108

// uop_pkt slices.
`define LA_UOP_VALID             0
`define LA_UOP_PC_H             32
`define LA_UOP_PC_L              1
`define LA_UOP_INST_H           64
`define LA_UOP_INST_L           33
`define LA_UOP_EPOCH_H          66
`define LA_UOP_EPOCH_L          65
`define LA_UOP_OP_CLASS_H       70
`define LA_UOP_OP_CLASS_L       67
`define LA_UOP_ALU_OP_H         75
`define LA_UOP_ALU_OP_L         71
`define LA_UOP_BR_OP_H          79
`define LA_UOP_BR_OP_L          76
`define LA_UOP_MEM_OP_H         83
`define LA_UOP_MEM_OP_L         80
`define LA_UOP_CSR_OP_H         86
`define LA_UOP_CSR_OP_L         84
`define LA_UOP_MDU_OP_H         90
`define LA_UOP_MDU_OP_L         87
`define LA_UOP_SRC1_H           95
`define LA_UOP_SRC1_L           91
`define LA_UOP_SRC2_H          100
`define LA_UOP_SRC2_L           96
`define LA_UOP_SRC3_H          105
`define LA_UOP_SRC3_L          101
`define LA_UOP_SRC1_USED       106
`define LA_UOP_SRC2_USED       107
`define LA_UOP_SRC3_USED       108
`define LA_UOP_RD_H            113
`define LA_UOP_RD_L            109
`define LA_UOP_RD_WE           114
`define LA_UOP_IMM_H           146
`define LA_UOP_IMM_L           115
`define LA_UOP_PRED_TAKEN      147
`define LA_UOP_PRED_TARGET_H   179
`define LA_UOP_PRED_TARGET_L   148
`define LA_UOP_PRED_META_H     187
`define LA_UOP_PRED_META_L     180
`define LA_UOP_EXCEPTION       188
`define LA_UOP_ECODE_H         194
`define LA_UOP_ECODE_L         189
`define LA_UOP_ESUBCODE_H      203
`define LA_UOP_ESUBCODE_L      195
`define LA_UOP_BADV_H          210
`define LA_UOP_BADV_L          204

// producer_status slices.
`define LA_PROD_VALID            0
`define LA_PROD_EPOCH_H          2
`define LA_PROD_EPOCH_L          1
`define LA_PROD_RD_H             7
`define LA_PROD_RD_L             3
`define LA_PROD_RD_WE            8
`define LA_PROD_DATA_VALID       9
`define LA_PROD_DATA_H          41
`define LA_PROD_DATA_L          10
`define LA_PROD_STAGE_H         45
`define LA_PROD_STAGE_L         42
`define LA_PROD_READY_CYCLE_H   47
`define LA_PROD_READY_CYCLE_L   46
`define LA_PROD_IS_LOAD         48
`define LA_PROD_IS_MDU          49

// mem_req slices.
`define LA_MEM_REQ_VALID         0
`define LA_MEM_REQ_OP_H          4
`define LA_MEM_REQ_OP_L          1
`define LA_MEM_REQ_ADDR_H       36
`define LA_MEM_REQ_ADDR_L        5
`define LA_MEM_REQ_WDATA_H      68
`define LA_MEM_REQ_WDATA_L      37
`define LA_MEM_REQ_WSTRB_H      72
`define LA_MEM_REQ_WSTRB_L      69
`define LA_MEM_REQ_SIZE_H       74
`define LA_MEM_REQ_SIZE_L       73
`define LA_MEM_REQ_UNCACHED     75
`define LA_MEM_REQ_EPOCH_H      77
`define LA_MEM_REQ_EPOCH_L      76
`define LA_MEM_REQ_SEQ_H        81
`define LA_MEM_REQ_SEQ_L        78
`define LA_MEM_REQ_FAULT        82

// mem_resp slices.
`define LA_MEM_RESP_VALID        0
`define LA_MEM_RESP_FAULT        1
`define LA_MEM_RESP_RDATA_H     33
`define LA_MEM_RESP_RDATA_L      2
`define LA_MEM_RESP_EPOCH_H     35
`define LA_MEM_RESP_EPOCH_L     34
`define LA_MEM_RESP_SEQ_H       39
`define LA_MEM_RESP_SEQ_L       36

// redirect_pkt slices.
`define LA_REDIRECT_VALID        0
`define LA_REDIRECT_TARGET_H    32
`define LA_REDIRECT_TARGET_L     1
`define LA_REDIRECT_REASON_H    36
`define LA_REDIRECT_REASON_L    33
`define LA_REDIRECT_SOURCE_H    40
`define LA_REDIRECT_SOURCE_L    37
`define LA_REDIRECT_EPOCH_NEW_H 42
`define LA_REDIRECT_EPOCH_NEW_L 41
`define LA_REDIRECT_KILL_YOUNGER 43

// commit_pkt slices.
`define LA_COMMIT_VALID          0
`define LA_COMMIT_PC_H          32
`define LA_COMMIT_PC_L           1
`define LA_COMMIT_INST_H        64
`define LA_COMMIT_INST_L        33
`define LA_COMMIT_RD_WE         65
`define LA_COMMIT_RD_H          70
`define LA_COMMIT_RD_L          66
`define LA_COMMIT_WDATA_H      102
`define LA_COMMIT_WDATA_L       71
`define LA_COMMIT_IS_STORE     103
`define LA_COMMIT_STORE_SEQ_H  107
`define LA_COMMIT_STORE_SEQ_L  104
`define LA_COMMIT_CSR_WE       108
`define LA_COMMIT_EXCEPTION    109
`define LA_COMMIT_DEBUG_RF_WEN_H 113
`define LA_COMMIT_DEBUG_RF_WEN_L 110
`define LA_COMMIT_PERF_RETIRED 114
`define LA_COMMIT_PERF_EXCEPTION 115
`define LA_COMMIT_ECODE_H      121
`define LA_COMMIT_ECODE_L      116
`define LA_COMMIT_ESUBCODE_H   125
`define LA_COMMIT_ESUBCODE_L   122

`endif
