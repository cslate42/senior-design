#ifndef __c6_mpu6050_driver_h__
#define __c6_mpu6050_driver_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc6_mpu6050_driverInstanceStruct
#define typedef_SFc6_mpu6050_driverInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c6_dataWrittenToVector[2];
  uint8_T c6_doSetSimStateSideEffects;
  const mxArray *c6_setSimStateSideEffectsInfo;
  void *c6_fEmlrtCtx;
  int32_T *c6_sfEvent;
  boolean_T *c6_doneDoubleBufferReInit;
  uint8_T *c6_is_active_c6_mpu6050_driver;
  uint8_T *c6_is_c6_mpu6050_driver;
  uint32_T *c6_ESCPeriod;
  uint32_T *c6_pw;
  boolean_T *c6_pwm;
  uint32_T *c6_cnt;
} SFc6_mpu6050_driverInstanceStruct;

#endif                                 /*typedef_SFc6_mpu6050_driverInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c6_mpu6050_driver_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c6_mpu6050_driver_get_check_sum(mxArray *plhs[]);
extern void c6_mpu6050_driver_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
