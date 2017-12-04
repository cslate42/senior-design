#ifndef __c4_mpu6050_working_h__
#define __c4_mpu6050_working_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc4_mpu6050_workingInstanceStruct
#define typedef_SFc4_mpu6050_workingInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  uint8_T c4_deviceAddr;
  uint8_T c4_powerRegAddr;
  uint8_T c4_AccelXRegAddr;
  uint8_T c4_AccelYRegAddr;
  uint8_T c4_AccelZRegAddr;
  boolean_T c4_dataWrittenToVector[8];
  uint8_T c4_doSetSimStateSideEffects;
  const mxArray *c4_setSimStateSideEffectsInfo;
  void *c4_fEmlrtCtx;
  int32_T *c4_sfEvent;
  uint8_T *c4_is_active_c4_mpu6050_working;
  uint8_T *c4_is_c4_mpu6050_working;
  boolean_T *c4_sda;
  boolean_T *c4_scl;
  boolean_T *c4_sda_out;
  uint8_T *c4_addr;
  uint8_T *c4_bit_idx;
  uint8_T *c4_data;
  boolean_T *c4_rw;
  uint8_T *c4_reg_idx;
  uint8_T *c4_rd_cnt;
} SFc4_mpu6050_workingInstanceStruct;

#endif                                 /*typedef_SFc4_mpu6050_workingInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c4_mpu6050_working_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c4_mpu6050_working_get_check_sum(mxArray *plhs[]);
extern void c4_mpu6050_working_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
