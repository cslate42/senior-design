/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * File: gm_mpu6050_interface.c
 *
 * Code generated for Simulink model 'gm_mpu6050_interface'.
 *
 * Model version                  : 1.262
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Fri Dec 01 17:20:00 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "gm_mpu6050_interface.h"
#include "gm_mpu6050_interface_private.h"
#define gm_mpu6050_RegisterOffset_hljdm (300U)
#define gm_mpu6050__RegisterOffset_hljd (296U)
#define gm_mpu6050_i_RegisterOffset_hlj (292U)
#define gm_mpu6050_in_RegisterOffset_hl (272U)
#define gm_mpu6050_int_RegisterOffset_h (268U)
#define gm_mpu6050_inter_RegisterOffset (264U)
#define gm_mpu605_RegisterOffset_hljdmo (288U)
#define gm_mpu60_RegisterOffset_hljdmom (284U)
#define gm_mpu6_RegisterOffset_hljdmomx (280U)
#define gm_mpu_RegisterOffset_hljdmomxq (276U)

/* user code (top of source file) */
/* System '<Root>/I2C_MPU6050_IP' */
#include "axi_lct.h"

/* Block states (auto storage) */
DW_gm_mpu6050_interface_T gm_mpu6050_interface_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_gm_mpu6050_interface_T gm_mpu6050_interface_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_gm_mpu6050_interface_T gm_mpu6050_interface_Y;

/* Real-time model */
RT_MODEL_gm_mpu6050_interface_T gm_mpu6050_interface_M_;
RT_MODEL_gm_mpu6050_interface_T *const gm_mpu6050_interface_M =
  &gm_mpu6050_interface_M_;

/* Model step function */
void gm_mpu6050_interface_step(void)
{
  /* local block i/o variables */
  int16_T rtb_AXI4Lite_Read_AccelX_DTC;
  int16_T rtb_AXI4Lite_Read_AccelY_DTC;
  int16_T rtb_AXI4Lite_Read_AccelZ_DTC;
  int16_T rtb_AXI4Lite_Read_GyroX_DTC;
  int16_T rtb_AXI4Lite_Read_GyroY_DTC;
  int16_T rtb_AXI4Lite_Read_GyroZ_DTC;
  boolean_T rtb_AXI4Lite_Read_validout_DTC;
  boolean_T rtb_EXTERNALPORT_SCL_DTC;
  AXI4_struct * p_state;
  uint32_T rtb_AXI4Lite_Write_RegAddr_DTC;

  /* Outputs for Atomic SubSystem: '<Root>/I2C_MPU6050_IP' */

  /* DataTypeConversion: '<S4>/AXI4Lite_Write_RegAddr_DTC' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  rtb_AXI4Lite_Write_RegAddr_DTC = gm_mpu6050_interface_P.Constant2_Value;

  /* Start for MATLABSystem: '<S14>/AXI4-Interface Write' incorporates:
   *  MATLABSystem: '<S14>/AXI4-Interface Write'
   */
  p_state = (AXI4_struct *)(gm_mpu6050_interface_DW.obj_nw.DeviceState);
  AXI4LITE_WRITE(p_state, &rtb_AXI4Lite_Write_RegAddr_DTC,
                 gm_mpu_RegisterOffset_hljdmomxq, 4U);

  /* Start for MATLABSystem: '<S5>/AXI4-Interface Read' incorporates:
   *  MATLABSystem: '<S5>/AXI4-Interface Read'
   */
  p_state = (AXI4_struct *)(gm_mpu6050_interface_DW.obj_fu.DeviceState);
  AXI4LITE_READ(p_state, &rtb_AXI4Lite_Write_RegAddr_DTC,
                gm_mpu6050_inter_RegisterOffset, 4U);

  /* DataTypeConversion: '<S3>/AXI4Lite_Read_AccelX_DTC' incorporates:
   *  MATLABSystem: '<S5>/AXI4-Interface Read'
   */
  rtb_AXI4Lite_Read_AccelX_DTC = (int16_T)rtb_AXI4Lite_Write_RegAddr_DTC;

  /* Start for MATLABSystem: '<S6>/AXI4-Interface Read' incorporates:
   *  MATLABSystem: '<S6>/AXI4-Interface Read'
   */
  p_state = (AXI4_struct *)(gm_mpu6050_interface_DW.obj_n.DeviceState);
  AXI4LITE_READ(p_state, &rtb_AXI4Lite_Write_RegAddr_DTC,
                gm_mpu6050_int_RegisterOffset_h, 4U);

  /* DataTypeConversion: '<S3>/AXI4Lite_Read_AccelY_DTC' incorporates:
   *  MATLABSystem: '<S6>/AXI4-Interface Read'
   */
  rtb_AXI4Lite_Read_AccelY_DTC = (int16_T)rtb_AXI4Lite_Write_RegAddr_DTC;

  /* Start for MATLABSystem: '<S7>/AXI4-Interface Read' incorporates:
   *  MATLABSystem: '<S7>/AXI4-Interface Read'
   */
  p_state = (AXI4_struct *)(gm_mpu6050_interface_DW.obj_fh.DeviceState);
  AXI4LITE_READ(p_state, &rtb_AXI4Lite_Write_RegAddr_DTC,
                gm_mpu6050_in_RegisterOffset_hl, 4U);

  /* DataTypeConversion: '<S3>/AXI4Lite_Read_AccelZ_DTC' incorporates:
   *  MATLABSystem: '<S7>/AXI4-Interface Read'
   */
  rtb_AXI4Lite_Read_AccelZ_DTC = (int16_T)rtb_AXI4Lite_Write_RegAddr_DTC;

  /* Start for MATLABSystem: '<S13>/AXI4-Interface Read' incorporates:
   *  MATLABSystem: '<S13>/AXI4-Interface Read'
   */
  p_state = (AXI4_struct *)(gm_mpu6050_interface_DW.obj.DeviceState);
  AXI4LITE_READ(p_state, &rtb_AXI4Lite_Write_RegAddr_DTC,
                gm_mpu6_RegisterOffset_hljdmomx, 4U);

  /* DataTypeConversion: '<S3>/AXI4Lite_Read_validout_DTC' incorporates:
   *  MATLABSystem: '<S13>/AXI4-Interface Read'
   */
  rtb_AXI4Lite_Read_validout_DTC = (rtb_AXI4Lite_Write_RegAddr_DTC != 0U);

  /* Start for MATLABSystem: '<S12>/AXI4-Interface Read' incorporates:
   *  MATLABSystem: '<S12>/AXI4-Interface Read'
   */
  p_state = (AXI4_struct *)(gm_mpu6050_interface_DW.obj_h.DeviceState);
  AXI4LITE_READ(p_state, &rtb_AXI4Lite_Write_RegAddr_DTC,
                gm_mpu60_RegisterOffset_hljdmom, 4U);

  /* Start for MATLABSystem: '<S11>/AXI4-Interface Read' incorporates:
   *  MATLABSystem: '<S11>/AXI4-Interface Read'
   */
  p_state = (AXI4_struct *)(gm_mpu6050_interface_DW.obj_k.DeviceState);
  AXI4LITE_READ(p_state, &rtb_AXI4Lite_Write_RegAddr_DTC,
                gm_mpu605_RegisterOffset_hljdmo, 4U);

  /* Start for MATLABSystem: '<S8>/AXI4-Interface Read' incorporates:
   *  MATLABSystem: '<S8>/AXI4-Interface Read'
   */
  p_state = (AXI4_struct *)(gm_mpu6050_interface_DW.obj_km.DeviceState);
  AXI4LITE_READ(p_state, &rtb_AXI4Lite_Write_RegAddr_DTC,
                gm_mpu6050_i_RegisterOffset_hlj, 4U);

  /* DataTypeConversion: '<S3>/AXI4Lite_Read_GyroX_DTC' incorporates:
   *  MATLABSystem: '<S8>/AXI4-Interface Read'
   */
  rtb_AXI4Lite_Read_GyroX_DTC = (int16_T)rtb_AXI4Lite_Write_RegAddr_DTC;

  /* Start for MATLABSystem: '<S9>/AXI4-Interface Read' incorporates:
   *  MATLABSystem: '<S9>/AXI4-Interface Read'
   */
  p_state = (AXI4_struct *)(gm_mpu6050_interface_DW.obj_fp.DeviceState);
  AXI4LITE_READ(p_state, &rtb_AXI4Lite_Write_RegAddr_DTC,
                gm_mpu6050__RegisterOffset_hljd, 4U);

  /* DataTypeConversion: '<S3>/AXI4Lite_Read_GyroY_DTC' incorporates:
   *  MATLABSystem: '<S9>/AXI4-Interface Read'
   */
  rtb_AXI4Lite_Read_GyroY_DTC = (int16_T)rtb_AXI4Lite_Write_RegAddr_DTC;

  /* Start for MATLABSystem: '<S10>/AXI4-Interface Read' incorporates:
   *  MATLABSystem: '<S10>/AXI4-Interface Read'
   */
  p_state = (AXI4_struct *)(gm_mpu6050_interface_DW.obj_f.DeviceState);
  AXI4LITE_READ(p_state, &rtb_AXI4Lite_Write_RegAddr_DTC,
                gm_mpu6050_RegisterOffset_hljdm, 4U);

  /* DataTypeConversion: '<S3>/AXI4Lite_Read_GyroZ_DTC' incorporates:
   *  MATLABSystem: '<S10>/AXI4-Interface Read'
   */
  rtb_AXI4Lite_Read_GyroZ_DTC = (int16_T)rtb_AXI4Lite_Write_RegAddr_DTC;

  /* DataTypeConversion: '<S3>/EXTERNALPORT_SCL_DTC' */
  rtb_EXTERNALPORT_SCL_DTC = false;

  /* End of Outputs for SubSystem: '<Root>/I2C_MPU6050_IP' */

  /* Outport: '<Root>/SCL' */
  gm_mpu6050_interface_Y.SCL = rtb_EXTERNALPORT_SCL_DTC;

  /* Outport: '<Root>/SDA' */
  gm_mpu6050_interface_Y.SDA = false;

  /* Outport: '<Root>/CS' */
  gm_mpu6050_interface_Y.CS = false;

  /* Outport: '<Root>/AddrAlt' */
  gm_mpu6050_interface_Y.AddrAlt = false;
}

/* Model initialize function */
void gm_mpu6050_interface_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(gm_mpu6050_interface_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&gm_mpu6050_interface_DW, 0,
                sizeof(DW_gm_mpu6050_interface_T));

  /* external inputs */
  gm_mpu6050_interface_U.TmpCnfDevice = false;

  /* external outputs */
  (void) memset((void *)&gm_mpu6050_interface_Y, 0,
                sizeof(ExtY_gm_mpu6050_interface_T));

  {
    AXI4_struct * p_state;
    static const char_T tmp[14] = { '/', 'd', 'e', 'v', '/', 'm', 'w', 'i', 'p',
      'c', 'o', 'r', 'e', '\x00' };

    char_T tmp_0[14];
    int32_T i;

    {
      /* user code (Start function Header) */

      /* System '<Root>/I2C_MPU6050_IP' */
      AXI4LITE_RESET_IPCORE("/dev/mwipcore");

      /* Start for Atomic SubSystem: '<Root>/I2C_MPU6050_IP' */

      /* Start for MATLABSystem: '<S14>/AXI4-Interface Write' */
      gm_mpu6050_interface_DW.obj_nw.isInitialized = 0;
      gm_mpu6050_interface_DW.obj_nw.isInitialized = 1;
      gm_mpu6050_interface_DW.obj_nw.DeviceState = 0U;
      for (i = 0; i < 14; i++) {
        tmp_0[i] = tmp[i];
      }

      p_state = AXI4LITE_INIT(tmp_0);
      gm_mpu6050_interface_DW.obj_nw.DeviceState = (uint32_T)p_state;

      /* End of Start for MATLABSystem: '<S14>/AXI4-Interface Write' */

      /* Start for MATLABSystem: '<S5>/AXI4-Interface Read' */
      gm_mpu6050_interface_DW.obj_fu.isInitialized = 0;
      gm_mpu6050_interface_DW.obj_fu.isInitialized = 1;
      gm_mpu6050_interface_DW.obj_fu.DeviceState = 0U;
      for (i = 0; i < 14; i++) {
        tmp_0[i] = tmp[i];
      }

      p_state = AXI4LITE_INIT(tmp_0);
      gm_mpu6050_interface_DW.obj_fu.DeviceState = (uint32_T)p_state;

      /* End of Start for MATLABSystem: '<S5>/AXI4-Interface Read' */

      /* Start for MATLABSystem: '<S6>/AXI4-Interface Read' */
      gm_mpu6050_interface_DW.obj_n.isInitialized = 0;
      gm_mpu6050_interface_DW.obj_n.isInitialized = 1;
      gm_mpu6050_interface_DW.obj_n.DeviceState = 0U;
      for (i = 0; i < 14; i++) {
        tmp_0[i] = tmp[i];
      }

      p_state = AXI4LITE_INIT(tmp_0);
      gm_mpu6050_interface_DW.obj_n.DeviceState = (uint32_T)p_state;

      /* End of Start for MATLABSystem: '<S6>/AXI4-Interface Read' */

      /* Start for MATLABSystem: '<S7>/AXI4-Interface Read' */
      gm_mpu6050_interface_DW.obj_fh.isInitialized = 0;
      gm_mpu6050_interface_DW.obj_fh.isInitialized = 1;
      gm_mpu6050_interface_DW.obj_fh.DeviceState = 0U;
      for (i = 0; i < 14; i++) {
        tmp_0[i] = tmp[i];
      }

      p_state = AXI4LITE_INIT(tmp_0);
      gm_mpu6050_interface_DW.obj_fh.DeviceState = (uint32_T)p_state;

      /* End of Start for MATLABSystem: '<S7>/AXI4-Interface Read' */

      /* Start for MATLABSystem: '<S13>/AXI4-Interface Read' */
      gm_mpu6050_interface_DW.obj.isInitialized = 0;
      gm_mpu6050_interface_DW.obj.isInitialized = 1;
      gm_mpu6050_interface_DW.obj.DeviceState = 0U;
      for (i = 0; i < 14; i++) {
        tmp_0[i] = tmp[i];
      }

      p_state = AXI4LITE_INIT(tmp_0);
      gm_mpu6050_interface_DW.obj.DeviceState = (uint32_T)p_state;

      /* End of Start for MATLABSystem: '<S13>/AXI4-Interface Read' */

      /* Start for MATLABSystem: '<S12>/AXI4-Interface Read' */
      gm_mpu6050_interface_DW.obj_h.isInitialized = 0;
      gm_mpu6050_interface_DW.obj_h.isInitialized = 1;
      gm_mpu6050_interface_DW.obj_h.DeviceState = 0U;
      for (i = 0; i < 14; i++) {
        tmp_0[i] = tmp[i];
      }

      p_state = AXI4LITE_INIT(tmp_0);
      gm_mpu6050_interface_DW.obj_h.DeviceState = (uint32_T)p_state;

      /* End of Start for MATLABSystem: '<S12>/AXI4-Interface Read' */

      /* Start for MATLABSystem: '<S11>/AXI4-Interface Read' */
      gm_mpu6050_interface_DW.obj_k.isInitialized = 0;
      gm_mpu6050_interface_DW.obj_k.isInitialized = 1;
      gm_mpu6050_interface_DW.obj_k.DeviceState = 0U;
      for (i = 0; i < 14; i++) {
        tmp_0[i] = tmp[i];
      }

      p_state = AXI4LITE_INIT(tmp_0);
      gm_mpu6050_interface_DW.obj_k.DeviceState = (uint32_T)p_state;

      /* End of Start for MATLABSystem: '<S11>/AXI4-Interface Read' */

      /* Start for MATLABSystem: '<S8>/AXI4-Interface Read' */
      gm_mpu6050_interface_DW.obj_km.isInitialized = 0;
      gm_mpu6050_interface_DW.obj_km.isInitialized = 1;
      gm_mpu6050_interface_DW.obj_km.DeviceState = 0U;
      for (i = 0; i < 14; i++) {
        tmp_0[i] = tmp[i];
      }

      p_state = AXI4LITE_INIT(tmp_0);
      gm_mpu6050_interface_DW.obj_km.DeviceState = (uint32_T)p_state;

      /* End of Start for MATLABSystem: '<S8>/AXI4-Interface Read' */

      /* Start for MATLABSystem: '<S9>/AXI4-Interface Read' */
      gm_mpu6050_interface_DW.obj_fp.isInitialized = 0;
      gm_mpu6050_interface_DW.obj_fp.isInitialized = 1;
      gm_mpu6050_interface_DW.obj_fp.DeviceState = 0U;
      for (i = 0; i < 14; i++) {
        tmp_0[i] = tmp[i];
      }

      p_state = AXI4LITE_INIT(tmp_0);
      gm_mpu6050_interface_DW.obj_fp.DeviceState = (uint32_T)p_state;

      /* End of Start for MATLABSystem: '<S9>/AXI4-Interface Read' */

      /* Start for MATLABSystem: '<S10>/AXI4-Interface Read' */
      gm_mpu6050_interface_DW.obj_f.isInitialized = 0;
      gm_mpu6050_interface_DW.obj_f.isInitialized = 1;
      gm_mpu6050_interface_DW.obj_f.DeviceState = 0U;
      for (i = 0; i < 14; i++) {
        tmp_0[i] = tmp[i];
      }

      p_state = AXI4LITE_INIT(tmp_0);
      gm_mpu6050_interface_DW.obj_f.DeviceState = (uint32_T)p_state;

      /* End of Start for MATLABSystem: '<S10>/AXI4-Interface Read' */

      /* End of Start for SubSystem: '<Root>/I2C_MPU6050_IP' */
    }
  }
}

/* Model terminate function */
void gm_mpu6050_interface_terminate(void)
{
  AXI4_struct * p_state;

  /* Terminate for Atomic SubSystem: '<Root>/I2C_MPU6050_IP' */

  /* Start for MATLABSystem: '<S14>/AXI4-Interface Write' incorporates:
   *  Terminate for MATLABSystem: '<S14>/AXI4-Interface Write'
   */
  if (gm_mpu6050_interface_DW.obj_nw.isInitialized == 1) {
    gm_mpu6050_interface_DW.obj_nw.isInitialized = 2;
    p_state = (AXI4_struct *)(gm_mpu6050_interface_DW.obj_nw.DeviceState);
    AXI4LITE_TERMINATE(p_state);
  }

  /* End of Start for MATLABSystem: '<S14>/AXI4-Interface Write' */

  /* Start for MATLABSystem: '<S5>/AXI4-Interface Read' incorporates:
   *  Terminate for MATLABSystem: '<S5>/AXI4-Interface Read'
   */
  if (gm_mpu6050_interface_DW.obj_fu.isInitialized == 1) {
    gm_mpu6050_interface_DW.obj_fu.isInitialized = 2;
    p_state = (AXI4_struct *)(gm_mpu6050_interface_DW.obj_fu.DeviceState);
    AXI4LITE_TERMINATE(p_state);
  }

  /* End of Start for MATLABSystem: '<S5>/AXI4-Interface Read' */

  /* Start for MATLABSystem: '<S6>/AXI4-Interface Read' incorporates:
   *  Terminate for MATLABSystem: '<S6>/AXI4-Interface Read'
   */
  if (gm_mpu6050_interface_DW.obj_n.isInitialized == 1) {
    gm_mpu6050_interface_DW.obj_n.isInitialized = 2;
    p_state = (AXI4_struct *)(gm_mpu6050_interface_DW.obj_n.DeviceState);
    AXI4LITE_TERMINATE(p_state);
  }

  /* End of Start for MATLABSystem: '<S6>/AXI4-Interface Read' */

  /* Start for MATLABSystem: '<S7>/AXI4-Interface Read' incorporates:
   *  Terminate for MATLABSystem: '<S7>/AXI4-Interface Read'
   */
  if (gm_mpu6050_interface_DW.obj_fh.isInitialized == 1) {
    gm_mpu6050_interface_DW.obj_fh.isInitialized = 2;
    p_state = (AXI4_struct *)(gm_mpu6050_interface_DW.obj_fh.DeviceState);
    AXI4LITE_TERMINATE(p_state);
  }

  /* End of Start for MATLABSystem: '<S7>/AXI4-Interface Read' */

  /* Start for MATLABSystem: '<S13>/AXI4-Interface Read' incorporates:
   *  Terminate for MATLABSystem: '<S13>/AXI4-Interface Read'
   */
  if (gm_mpu6050_interface_DW.obj.isInitialized == 1) {
    gm_mpu6050_interface_DW.obj.isInitialized = 2;
    p_state = (AXI4_struct *)(gm_mpu6050_interface_DW.obj.DeviceState);
    AXI4LITE_TERMINATE(p_state);
  }

  /* End of Start for MATLABSystem: '<S13>/AXI4-Interface Read' */

  /* Start for MATLABSystem: '<S12>/AXI4-Interface Read' incorporates:
   *  Terminate for MATLABSystem: '<S12>/AXI4-Interface Read'
   */
  if (gm_mpu6050_interface_DW.obj_h.isInitialized == 1) {
    gm_mpu6050_interface_DW.obj_h.isInitialized = 2;
    p_state = (AXI4_struct *)(gm_mpu6050_interface_DW.obj_h.DeviceState);
    AXI4LITE_TERMINATE(p_state);
  }

  /* End of Start for MATLABSystem: '<S12>/AXI4-Interface Read' */

  /* Start for MATLABSystem: '<S11>/AXI4-Interface Read' incorporates:
   *  Terminate for MATLABSystem: '<S11>/AXI4-Interface Read'
   */
  if (gm_mpu6050_interface_DW.obj_k.isInitialized == 1) {
    gm_mpu6050_interface_DW.obj_k.isInitialized = 2;
    p_state = (AXI4_struct *)(gm_mpu6050_interface_DW.obj_k.DeviceState);
    AXI4LITE_TERMINATE(p_state);
  }

  /* End of Start for MATLABSystem: '<S11>/AXI4-Interface Read' */

  /* Start for MATLABSystem: '<S8>/AXI4-Interface Read' incorporates:
   *  Terminate for MATLABSystem: '<S8>/AXI4-Interface Read'
   */
  if (gm_mpu6050_interface_DW.obj_km.isInitialized == 1) {
    gm_mpu6050_interface_DW.obj_km.isInitialized = 2;
    p_state = (AXI4_struct *)(gm_mpu6050_interface_DW.obj_km.DeviceState);
    AXI4LITE_TERMINATE(p_state);
  }

  /* End of Start for MATLABSystem: '<S8>/AXI4-Interface Read' */

  /* Start for MATLABSystem: '<S9>/AXI4-Interface Read' incorporates:
   *  Terminate for MATLABSystem: '<S9>/AXI4-Interface Read'
   */
  if (gm_mpu6050_interface_DW.obj_fp.isInitialized == 1) {
    gm_mpu6050_interface_DW.obj_fp.isInitialized = 2;
    p_state = (AXI4_struct *)(gm_mpu6050_interface_DW.obj_fp.DeviceState);
    AXI4LITE_TERMINATE(p_state);
  }

  /* End of Start for MATLABSystem: '<S9>/AXI4-Interface Read' */

  /* Start for MATLABSystem: '<S10>/AXI4-Interface Read' incorporates:
   *  Terminate for MATLABSystem: '<S10>/AXI4-Interface Read'
   */
  if (gm_mpu6050_interface_DW.obj_f.isInitialized == 1) {
    gm_mpu6050_interface_DW.obj_f.isInitialized = 2;
    p_state = (AXI4_struct *)(gm_mpu6050_interface_DW.obj_f.DeviceState);
    AXI4LITE_TERMINATE(p_state);
  }

  /* End of Start for MATLABSystem: '<S10>/AXI4-Interface Read' */

  /* End of Terminate for SubSystem: '<Root>/I2C_MPU6050_IP' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
