#ifndef __c5_mpu6050_h__
#define __c5_mpu6050_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc5_mpu6050InstanceStruct
#define typedef_SFc5_mpu6050InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  uint8_T c5_SlvAddr;
  uint8_T c5_AccelXRegAddr;
  uint8_T c5_AccelYRegAddr;
  uint8_T c5_AccelZRegAddr;
  uint8_T c5_powerRegData;
  uint8_T c5_powerRegAddr;
  uint8_T c5_GyroXRegAddr;
  uint8_T c5_doSetSimStateSideEffects;
  const mxArray *c5_setSimStateSideEffectsInfo;
  void *c5_fEmlrtCtx;
  int32_T *c5_sfEvent;
  boolean_T *c5_doneDoubleBufferReInit;
  uint8_T *c5_is_active_c5_mpu6050;
  uint8_T *c5_is_c5_mpu6050;
  boolean_T *c5_enb;
  boolean_T *c5_rw;
  boolean_T *c5_mode;
  uint8_T *c5_slv_addr;
  uint8_T *c5_reg_addr;
  boolean_T *c5_reg_byte_mode;
  uint8_T *c5_data_out;
  boolean_T *c5_busy;
  boolean_T *c5_n_ack;
  boolean_T *c5_byte_mode;
  boolean_T *c5_reg_mode;
  uint32_T *c5_cnt;
  uint8_T *c5_data_in;
  boolean_T *c5_mstr_ack;
  int16_T *c5_AccelX;
  int16_T *c5_AccelY;
  int16_T *c5_AccelZ;
  boolean_T *c5_Valid_Out;
  uint8_T *c5_tempVal;
  uint8_T *c5_deviceId;
  uint8_T *c5_regdata;
  uint8_T *c5_userRegAddr;
  boolean_T *c5_configDevice;
  boolean_T *c5_selfInit;
  int16_T *c5_GyroX;
  int16_T *c5_GyroY;
  int16_T *c5_GyroZ;
  boolean_T *c5_tmp;
  boolean_T *c5_tmpConfig;
  boolean_T *c5_tmpCheckCng;
  boolean_T *c5_tmpReadGyro;
  boolean_T *c5_tmpReadAccel;
  boolean_T *c5_tmpValid;
  boolean_T *c5_tmpReadDevice;
  boolean_T *c5_tmpHere;
  uint8_T *c5_tmpData;
} SFc5_mpu6050InstanceStruct;

#endif                                 /*typedef_SFc5_mpu6050InstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c5_mpu6050_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c5_mpu6050_get_check_sum(mxArray *plhs[]);
extern void c5_mpu6050_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
