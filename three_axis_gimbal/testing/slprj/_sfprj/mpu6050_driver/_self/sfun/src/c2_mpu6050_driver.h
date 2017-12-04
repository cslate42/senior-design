#ifndef __c2_mpu6050_driver_h__
#define __c2_mpu6050_driver_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "rtw_capi.h"
#include "rtw_modelmap.h"

/* Type Definitions */
#ifndef typedef_SFc2_mpu6050_driverInstanceStruct
#define typedef_SFc2_mpu6050_driverInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c2_dataWrittenToVector[12];
  uint8_T c2_doSetSimStateSideEffects;
  const mxArray *c2_setSimStateSideEffectsInfo;
  void *c2_dataSetLogObjVector[1];
  rtwCAPI_ModelMappingInfo c2_testPointMappingInfo;
  void *c2_testPointAddrMap[1];
  void *c2_fEmlrtCtx;
  int32_T *c2_sfEvent;
  boolean_T *c2_doneDoubleBufferReInit;
  uint8_T *c2_is_active_c2_mpu6050_driver;
  uint8_T *c2_is_c2_mpu6050_driver;
  boolean_T *c2_enb;
  boolean_T *c2_rd_wr;
  boolean_T *c2_mode;
  boolean_T *c2_busy;
  uint8_T *c2_bit_cnt;
  boolean_T *c2_scl;
  boolean_T *c2_sda;
  uint8_T *c2_slv_addr;
  uint8_T *c2_reg_addr;
  boolean_T *c2_reg_addr_burstIn;
  uint8_T *c2_reg_data;
  boolean_T *c2_sda_in;
  boolean_T *c2_ack;
  boolean_T *c2_n_ack;
  uint8_T *c2_reg_byte_cnt;
  boolean_T *c2_reg_data_burst;
  boolean_T *c2_reg_addr_burst;
  boolean_T *c2_mstr_ack;
  uint8_T *c2_data_out;
  uint8_T *c2_temp_data;
} SFc2_mpu6050_driverInstanceStruct;

#endif                                 /*typedef_SFc2_mpu6050_driverInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c2_mpu6050_driver_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_mpu6050_driver_get_check_sum(mxArray *plhs[]);
extern void c2_mpu6050_driver_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
