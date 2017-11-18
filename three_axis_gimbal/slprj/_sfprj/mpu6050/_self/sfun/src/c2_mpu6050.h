#ifndef __c2_mpu6050_h__
#define __c2_mpu6050_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "rtw_capi.h"
#include "rtw_modelmap.h"

/* Type Definitions */
#ifndef typedef_SFc2_mpu6050InstanceStruct
#define typedef_SFc2_mpu6050InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c2_sfEvent;
  uint8_T c2_tp_idle;
  uint8_T c2_tp_stop_ext;
  uint8_T c2_tp_ready;
  uint8_T c2_tp_stop;
  uint8_T c2_tp_start_n;
  uint8_T c2_tp_mastr_ack_data_cnf1;
  uint8_T c2_tp_mastr_ack_data_cnf;
  uint8_T c2_tp_scl_ext_p;
  uint8_T c2_tp_start_p;
  uint8_T c2_tp_scl_ext_n;
  uint8_T c2_tp_mastr_ack_data;
  uint8_T c2_tp_cmd_slave_addr_n;
  uint8_T c2_tp_Increment_Byte_count1;
  uint8_T c2_tp_cmd_slave_addr_p;
  uint8_T c2_tp_write_n;
  uint8_T c2_tp_ack_end1;
  uint8_T c2_tp_cmd_reg_read_data_p;
  uint8_T c2_tp_ack_end;
  uint8_T c2_tp_write_p;
  uint8_T c2_tp_ack_recv_wr3;
  uint8_T c2_tp_ack_data;
  uint8_T c2_tp_ack_slv;
  uint8_T c2_tp_cmd_reg_read_data_n;
  uint8_T c2_tp_ack_recv_wr;
  uint8_T c2_tp_cmd_reg_data_p;
  uint8_T c2_tp_ack_addr_m_cnf;
  uint8_T c2_tp_ack_wr_p;
  uint8_T c2_tp_error_ack;
  uint8_T c2_tp_cmd_reg_data_n;
  uint8_T c2_tp_delay;
  uint8_T c2_tp_cmd_reg_addr_n;
  uint8_T c2_tp_repeat_strt_n;
  uint8_T c2_tp_ready_repeated;
  uint8_T c2_tp_cmd_reg_addr_p;
  uint8_T c2_tp_repeat_strt_p;
  uint8_T c2_tp_ready_repeated_dummy;
  uint8_T c2_tp_ack_addr_m;
  uint8_T c2_tp_ack_recv_wr1;
  uint8_T c2_tp_ack_recv_wr2;
  uint8_T c2_tp_cmd_slave_addr_n1;
  uint8_T c2_tp_cmd_slave_addr_p1;
  uint8_T c2_tp_ack_addrm1;
  uint8_T c2_tp_read_n;
  uint8_T c2_tp_ack_wr_p2;
  uint8_T c2_tp_read_p;
  uint8_T c2_tp_ack_slv1;
  uint8_T c2_tp_ack_slv_cnf1;
  boolean_T c2_doneDoubleBufferReInit;
  uint8_T c2_is_active_c2_mpu6050;
  uint8_T c2_is_c2_mpu6050;
  uint8_T c2_bit_cnt;
  uint8_T c2_reg_byte_cnt;
  uint8_T c2_temp_data;
  boolean_T c2_dataWrittenToVector[12];
  uint8_T c2_doSetSimStateSideEffects;
  const mxArray *c2_setSimStateSideEffectsInfo;
  void *c2_dataSetLogObjVector[1];
  rtwCAPI_ModelMappingInfo c2_testPointMappingInfo;
  void *c2_testPointAddrMap[1];
  void *c2_fEmlrtCtx;
  boolean_T *c2_enb;
  boolean_T *c2_rd_wr;
  boolean_T *c2_mode;
  boolean_T *c2_busy;
  boolean_T *c2_scl;
  boolean_T *c2_sda;
  uint8_T *c2_slv_addr;
  uint8_T *c2_reg_addr;
  boolean_T *c2_reg_addr_burstIn;
  uint8_T *c2_reg_data;
  boolean_T *c2_sda_in;
  boolean_T *c2_ack;
  boolean_T *c2_n_ack;
  boolean_T *c2_reg_data_burst;
  boolean_T *c2_reg_addr_burst;
  boolean_T *c2_mstr_ack;
  uint8_T *c2_data_out;
} SFc2_mpu6050InstanceStruct;

#endif                                 /*typedef_SFc2_mpu6050InstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c2_mpu6050_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_mpu6050_get_check_sum(mxArray *plhs[]);
extern void c2_mpu6050_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
