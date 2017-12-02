/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * File: gm_mpu6050_interface.c
 *
 * Code generated for Simulink model 'gm_mpu6050_interface'.
 *
 * Model version                  : 1.297
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Sat Dec 02 13:17:33 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "gm_mpu6050_interface.h"
#include "gm_mpu6050_interface_private.h"
#include "gm_mpu6050_interface_dt.h"
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

/* Block signals (auto storage) */
B_gm_mpu6050_interface_T gm_mpu6050_interface_B;

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
  AXI4_struct * p_state;
  uint32_T rtb_AXI4Lite_Write_RegAddr_DTC;

  /* Outputs for Atomic SubSystem: '<Root>/I2C_MPU6050_IP' */

  /* DataTypeConversion: '<S3>/AXI4Lite_Write_RegAddr_DTC' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  rtb_AXI4Lite_Write_RegAddr_DTC = gm_mpu6050_interface_P.Constant2_Value;

  /* Start for MATLABSystem: '<S13>/AXI4-Interface Write' incorporates:
   *  MATLABSystem: '<S13>/AXI4-Interface Write'
   */
  p_state = (AXI4_struct *)(gm_mpu6050_interface_DW.obj_a.DeviceState);
  AXI4LITE_WRITE(p_state, &rtb_AXI4Lite_Write_RegAddr_DTC,
                 gm_mpu_RegisterOffset_hljdmomxq, 4U);

  /* Start for MATLABSystem: '<S4>/AXI4-Interface Read' incorporates:
   *  MATLABSystem: '<S4>/AXI4-Interface Read'
   */
  p_state = (AXI4_struct *)(gm_mpu6050_interface_DW.obj_bm.DeviceState);
  AXI4LITE_READ(p_state, &rtb_AXI4Lite_Write_RegAddr_DTC,
                gm_mpu6050_inter_RegisterOffset, 4U);

  /* DataTypeConversion: '<S2>/AXI4Lite_Read_AccelX_DTC' incorporates:
   *  MATLABSystem: '<S4>/AXI4-Interface Read'
   */
  gm_mpu6050_interface_B.AXI4Lite_Read_AccelX_DTC = (int16_T)
    rtb_AXI4Lite_Write_RegAddr_DTC;

  /* Start for MATLABSystem: '<S5>/AXI4-Interface Read' incorporates:
   *  MATLABSystem: '<S5>/AXI4-Interface Read'
   */
  p_state = (AXI4_struct *)(gm_mpu6050_interface_DW.obj_hs.DeviceState);
  AXI4LITE_READ(p_state, &rtb_AXI4Lite_Write_RegAddr_DTC,
                gm_mpu6050_int_RegisterOffset_h, 4U);

  /* DataTypeConversion: '<S2>/AXI4Lite_Read_AccelY_DTC' incorporates:
   *  MATLABSystem: '<S5>/AXI4-Interface Read'
   */
  gm_mpu6050_interface_B.AXI4Lite_Read_AccelY_DTC = (int16_T)
    rtb_AXI4Lite_Write_RegAddr_DTC;

  /* Start for MATLABSystem: '<S6>/AXI4-Interface Read' incorporates:
   *  MATLABSystem: '<S6>/AXI4-Interface Read'
   */
  p_state = (AXI4_struct *)(gm_mpu6050_interface_DW.obj_h.DeviceState);
  AXI4LITE_READ(p_state, &rtb_AXI4Lite_Write_RegAddr_DTC,
                gm_mpu6050_in_RegisterOffset_hl, 4U);

  /* DataTypeConversion: '<S2>/AXI4Lite_Read_AccelZ_DTC' incorporates:
   *  MATLABSystem: '<S6>/AXI4-Interface Read'
   */
  gm_mpu6050_interface_B.AXI4Lite_Read_AccelZ_DTC = (int16_T)
    rtb_AXI4Lite_Write_RegAddr_DTC;

  /* Start for MATLABSystem: '<S12>/AXI4-Interface Read' incorporates:
   *  MATLABSystem: '<S12>/AXI4-Interface Read'
   */
  p_state = (AXI4_struct *)(gm_mpu6050_interface_DW.obj.DeviceState);
  AXI4LITE_READ(p_state, &rtb_AXI4Lite_Write_RegAddr_DTC,
                gm_mpu6_RegisterOffset_hljdmomx, 4U);

  /* DataTypeConversion: '<S2>/AXI4Lite_Read_validout_DTC' incorporates:
   *  MATLABSystem: '<S12>/AXI4-Interface Read'
   */
  gm_mpu6050_interface_B.AXI4Lite_Read_validout_DTC =
    (rtb_AXI4Lite_Write_RegAddr_DTC != 0U);

  /* Start for MATLABSystem: '<S11>/AXI4-Interface Read' incorporates:
   *  MATLABSystem: '<S11>/AXI4-Interface Read'
   */
  p_state = (AXI4_struct *)(gm_mpu6050_interface_DW.obj_k.DeviceState);
  AXI4LITE_READ(p_state, &rtb_AXI4Lite_Write_RegAddr_DTC,
                gm_mpu60_RegisterOffset_hljdmom, 4U);

  /* DataTypeConversion: '<S2>/AXI4Lite_Read_deviceID_DTC' incorporates:
   *  MATLABSystem: '<S11>/AXI4-Interface Read'
   */
  gm_mpu6050_interface_B.AXI4Lite_Read_deviceID_DTC = (uint8_T)
    rtb_AXI4Lite_Write_RegAddr_DTC;

  /* Start for MATLABSystem: '<S10>/AXI4-Interface Read' incorporates:
   *  MATLABSystem: '<S10>/AXI4-Interface Read'
   */
  p_state = (AXI4_struct *)(gm_mpu6050_interface_DW.obj_f.DeviceState);
  AXI4LITE_READ(p_state, &rtb_AXI4Lite_Write_RegAddr_DTC,
                gm_mpu605_RegisterOffset_hljdmo, 4U);

  /* DataTypeConversion: '<S2>/AXI4Lite_Read_RegData_DTC' incorporates:
   *  MATLABSystem: '<S10>/AXI4-Interface Read'
   */
  gm_mpu6050_interface_B.AXI4Lite_Read_RegData_DTC = (uint8_T)
    rtb_AXI4Lite_Write_RegAddr_DTC;

  /* Start for MATLABSystem: '<S7>/AXI4-Interface Read' incorporates:
   *  MATLABSystem: '<S7>/AXI4-Interface Read'
   */
  p_state = (AXI4_struct *)(gm_mpu6050_interface_DW.obj_b.DeviceState);
  AXI4LITE_READ(p_state, &rtb_AXI4Lite_Write_RegAddr_DTC,
                gm_mpu6050_i_RegisterOffset_hlj, 4U);

  /* DataTypeConversion: '<S2>/AXI4Lite_Read_GyroX_DTC' incorporates:
   *  MATLABSystem: '<S7>/AXI4-Interface Read'
   */
  gm_mpu6050_interface_B.AXI4Lite_Read_GyroX_DTC = (int16_T)
    rtb_AXI4Lite_Write_RegAddr_DTC;

  /* Start for MATLABSystem: '<S8>/AXI4-Interface Read' incorporates:
   *  MATLABSystem: '<S8>/AXI4-Interface Read'
   */
  p_state = (AXI4_struct *)(gm_mpu6050_interface_DW.obj_d.DeviceState);
  AXI4LITE_READ(p_state, &rtb_AXI4Lite_Write_RegAddr_DTC,
                gm_mpu6050__RegisterOffset_hljd, 4U);

  /* DataTypeConversion: '<S2>/AXI4Lite_Read_GyroY_DTC' incorporates:
   *  MATLABSystem: '<S8>/AXI4-Interface Read'
   */
  gm_mpu6050_interface_B.AXI4Lite_Read_GyroY_DTC = (int16_T)
    rtb_AXI4Lite_Write_RegAddr_DTC;

  /* Start for MATLABSystem: '<S9>/AXI4-Interface Read' incorporates:
   *  MATLABSystem: '<S9>/AXI4-Interface Read'
   */
  p_state = (AXI4_struct *)(gm_mpu6050_interface_DW.obj_c.DeviceState);
  AXI4LITE_READ(p_state, &rtb_AXI4Lite_Write_RegAddr_DTC,
                gm_mpu6050_RegisterOffset_hljdm, 4U);

  /* DataTypeConversion: '<S2>/AXI4Lite_Read_GyroZ_DTC' incorporates:
   *  MATLABSystem: '<S9>/AXI4-Interface Read'
   */
  gm_mpu6050_interface_B.AXI4Lite_Read_GyroZ_DTC = (int16_T)
    rtb_AXI4Lite_Write_RegAddr_DTC;

  /* End of Outputs for SubSystem: '<Root>/I2C_MPU6050_IP' */

  /* Outport: '<Root>/SCL' */
  gm_mpu6050_interface_Y.SCL = false;

  /* Outport: '<Root>/SDA' */
  gm_mpu6050_interface_Y.SDA = false;

  /* Outport: '<Root>/CS' */
  gm_mpu6050_interface_Y.CS = false;

  /* Outport: '<Root>/AddrAlt' */
  gm_mpu6050_interface_Y.AddrAlt = false;

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.2s, 0.0s] */
    rtExtModeUpload(0, gm_mpu6050_interface_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.2s, 0.0s] */
    if ((rtmGetTFinal(gm_mpu6050_interface_M)!=-1) &&
        !((rtmGetTFinal(gm_mpu6050_interface_M)-
           gm_mpu6050_interface_M->Timing.taskTime0) >
          gm_mpu6050_interface_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(gm_mpu6050_interface_M, "Simulation finished");
    }

    if (rtmGetStopRequested(gm_mpu6050_interface_M)) {
      rtmSetErrorStatus(gm_mpu6050_interface_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  gm_mpu6050_interface_M->Timing.taskTime0 =
    (++gm_mpu6050_interface_M->Timing.clockTick0) *
    gm_mpu6050_interface_M->Timing.stepSize0;
}

/* Model initialize function */
void gm_mpu6050_interface_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)gm_mpu6050_interface_M, 0,
                sizeof(RT_MODEL_gm_mpu6050_interface_T));
  rtmSetTFinal(gm_mpu6050_interface_M, -1);
  gm_mpu6050_interface_M->Timing.stepSize0 = 0.2;

  /* External mode info */
  gm_mpu6050_interface_M->Sizes.checksums[0] = (3824400405U);
  gm_mpu6050_interface_M->Sizes.checksums[1] = (3007023022U);
  gm_mpu6050_interface_M->Sizes.checksums[2] = (1056273578U);
  gm_mpu6050_interface_M->Sizes.checksums[3] = (3677805042U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[12];
    gm_mpu6050_interface_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(gm_mpu6050_interface_M->extModeInfo,
      &gm_mpu6050_interface_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(gm_mpu6050_interface_M->extModeInfo,
                        gm_mpu6050_interface_M->Sizes.checksums);
    rteiSetTPtr(gm_mpu6050_interface_M->extModeInfo, rtmGetTPtr
                (gm_mpu6050_interface_M));
  }

  /* block I/O */
  (void) memset(((void *) &gm_mpu6050_interface_B), 0,
                sizeof(B_gm_mpu6050_interface_T));

  /* states (dwork) */
  (void) memset((void *)&gm_mpu6050_interface_DW, 0,
                sizeof(DW_gm_mpu6050_interface_T));

  /* external inputs */
  (void)memset((void *)&gm_mpu6050_interface_U, 0, sizeof
               (ExtU_gm_mpu6050_interface_T));

  /* external outputs */
  (void) memset((void *)&gm_mpu6050_interface_Y, 0,
                sizeof(ExtY_gm_mpu6050_interface_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    gm_mpu6050_interface_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

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

      /* Start for MATLABSystem: '<S13>/AXI4-Interface Write' */
      gm_mpu6050_interface_DW.obj_a.isInitialized = 0;
      gm_mpu6050_interface_DW.obj_a.isInitialized = 1;
      gm_mpu6050_interface_DW.obj_a.DeviceState = 0U;
      for (i = 0; i < 14; i++) {
        tmp_0[i] = tmp[i];
      }

      p_state = AXI4LITE_INIT(tmp_0);
      gm_mpu6050_interface_DW.obj_a.DeviceState = (uint32_T)p_state;

      /* End of Start for MATLABSystem: '<S13>/AXI4-Interface Write' */

      /* Start for MATLABSystem: '<S4>/AXI4-Interface Read' */
      gm_mpu6050_interface_DW.obj_bm.isInitialized = 0;
      gm_mpu6050_interface_DW.obj_bm.isInitialized = 1;
      gm_mpu6050_interface_DW.obj_bm.DeviceState = 0U;
      for (i = 0; i < 14; i++) {
        tmp_0[i] = tmp[i];
      }

      p_state = AXI4LITE_INIT(tmp_0);
      gm_mpu6050_interface_DW.obj_bm.DeviceState = (uint32_T)p_state;

      /* End of Start for MATLABSystem: '<S4>/AXI4-Interface Read' */

      /* Start for MATLABSystem: '<S5>/AXI4-Interface Read' */
      gm_mpu6050_interface_DW.obj_hs.isInitialized = 0;
      gm_mpu6050_interface_DW.obj_hs.isInitialized = 1;
      gm_mpu6050_interface_DW.obj_hs.DeviceState = 0U;
      for (i = 0; i < 14; i++) {
        tmp_0[i] = tmp[i];
      }

      p_state = AXI4LITE_INIT(tmp_0);
      gm_mpu6050_interface_DW.obj_hs.DeviceState = (uint32_T)p_state;

      /* End of Start for MATLABSystem: '<S5>/AXI4-Interface Read' */

      /* Start for MATLABSystem: '<S6>/AXI4-Interface Read' */
      gm_mpu6050_interface_DW.obj_h.isInitialized = 0;
      gm_mpu6050_interface_DW.obj_h.isInitialized = 1;
      gm_mpu6050_interface_DW.obj_h.DeviceState = 0U;
      for (i = 0; i < 14; i++) {
        tmp_0[i] = tmp[i];
      }

      p_state = AXI4LITE_INIT(tmp_0);
      gm_mpu6050_interface_DW.obj_h.DeviceState = (uint32_T)p_state;

      /* End of Start for MATLABSystem: '<S6>/AXI4-Interface Read' */

      /* Start for MATLABSystem: '<S12>/AXI4-Interface Read' */
      gm_mpu6050_interface_DW.obj.isInitialized = 0;
      gm_mpu6050_interface_DW.obj.isInitialized = 1;
      gm_mpu6050_interface_DW.obj.DeviceState = 0U;
      for (i = 0; i < 14; i++) {
        tmp_0[i] = tmp[i];
      }

      p_state = AXI4LITE_INIT(tmp_0);
      gm_mpu6050_interface_DW.obj.DeviceState = (uint32_T)p_state;

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

      /* Start for MATLABSystem: '<S7>/AXI4-Interface Read' */
      gm_mpu6050_interface_DW.obj_b.isInitialized = 0;
      gm_mpu6050_interface_DW.obj_b.isInitialized = 1;
      gm_mpu6050_interface_DW.obj_b.DeviceState = 0U;
      for (i = 0; i < 14; i++) {
        tmp_0[i] = tmp[i];
      }

      p_state = AXI4LITE_INIT(tmp_0);
      gm_mpu6050_interface_DW.obj_b.DeviceState = (uint32_T)p_state;

      /* End of Start for MATLABSystem: '<S7>/AXI4-Interface Read' */

      /* Start for MATLABSystem: '<S8>/AXI4-Interface Read' */
      gm_mpu6050_interface_DW.obj_d.isInitialized = 0;
      gm_mpu6050_interface_DW.obj_d.isInitialized = 1;
      gm_mpu6050_interface_DW.obj_d.DeviceState = 0U;
      for (i = 0; i < 14; i++) {
        tmp_0[i] = tmp[i];
      }

      p_state = AXI4LITE_INIT(tmp_0);
      gm_mpu6050_interface_DW.obj_d.DeviceState = (uint32_T)p_state;

      /* End of Start for MATLABSystem: '<S8>/AXI4-Interface Read' */

      /* Start for MATLABSystem: '<S9>/AXI4-Interface Read' */
      gm_mpu6050_interface_DW.obj_c.isInitialized = 0;
      gm_mpu6050_interface_DW.obj_c.isInitialized = 1;
      gm_mpu6050_interface_DW.obj_c.DeviceState = 0U;
      for (i = 0; i < 14; i++) {
        tmp_0[i] = tmp[i];
      }

      p_state = AXI4LITE_INIT(tmp_0);
      gm_mpu6050_interface_DW.obj_c.DeviceState = (uint32_T)p_state;

      /* End of Start for MATLABSystem: '<S9>/AXI4-Interface Read' */

      /* End of Start for SubSystem: '<Root>/I2C_MPU6050_IP' */
    }
  }
}

/* Model terminate function */
void gm_mpu6050_interface_terminate(void)
{
  AXI4_struct * p_state;

  /* Terminate for Atomic SubSystem: '<Root>/I2C_MPU6050_IP' */

  /* Start for MATLABSystem: '<S13>/AXI4-Interface Write' incorporates:
   *  Terminate for MATLABSystem: '<S13>/AXI4-Interface Write'
   */
  if (gm_mpu6050_interface_DW.obj_a.isInitialized == 1) {
    gm_mpu6050_interface_DW.obj_a.isInitialized = 2;
    p_state = (AXI4_struct *)(gm_mpu6050_interface_DW.obj_a.DeviceState);
    AXI4LITE_TERMINATE(p_state);
  }

  /* End of Start for MATLABSystem: '<S13>/AXI4-Interface Write' */

  /* Start for MATLABSystem: '<S4>/AXI4-Interface Read' incorporates:
   *  Terminate for MATLABSystem: '<S4>/AXI4-Interface Read'
   */
  if (gm_mpu6050_interface_DW.obj_bm.isInitialized == 1) {
    gm_mpu6050_interface_DW.obj_bm.isInitialized = 2;
    p_state = (AXI4_struct *)(gm_mpu6050_interface_DW.obj_bm.DeviceState);
    AXI4LITE_TERMINATE(p_state);
  }

  /* End of Start for MATLABSystem: '<S4>/AXI4-Interface Read' */

  /* Start for MATLABSystem: '<S5>/AXI4-Interface Read' incorporates:
   *  Terminate for MATLABSystem: '<S5>/AXI4-Interface Read'
   */
  if (gm_mpu6050_interface_DW.obj_hs.isInitialized == 1) {
    gm_mpu6050_interface_DW.obj_hs.isInitialized = 2;
    p_state = (AXI4_struct *)(gm_mpu6050_interface_DW.obj_hs.DeviceState);
    AXI4LITE_TERMINATE(p_state);
  }

  /* End of Start for MATLABSystem: '<S5>/AXI4-Interface Read' */

  /* Start for MATLABSystem: '<S6>/AXI4-Interface Read' incorporates:
   *  Terminate for MATLABSystem: '<S6>/AXI4-Interface Read'
   */
  if (gm_mpu6050_interface_DW.obj_h.isInitialized == 1) {
    gm_mpu6050_interface_DW.obj_h.isInitialized = 2;
    p_state = (AXI4_struct *)(gm_mpu6050_interface_DW.obj_h.DeviceState);
    AXI4LITE_TERMINATE(p_state);
  }

  /* End of Start for MATLABSystem: '<S6>/AXI4-Interface Read' */

  /* Start for MATLABSystem: '<S12>/AXI4-Interface Read' incorporates:
   *  Terminate for MATLABSystem: '<S12>/AXI4-Interface Read'
   */
  if (gm_mpu6050_interface_DW.obj.isInitialized == 1) {
    gm_mpu6050_interface_DW.obj.isInitialized = 2;
    p_state = (AXI4_struct *)(gm_mpu6050_interface_DW.obj.DeviceState);
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

  /* Start for MATLABSystem: '<S10>/AXI4-Interface Read' incorporates:
   *  Terminate for MATLABSystem: '<S10>/AXI4-Interface Read'
   */
  if (gm_mpu6050_interface_DW.obj_f.isInitialized == 1) {
    gm_mpu6050_interface_DW.obj_f.isInitialized = 2;
    p_state = (AXI4_struct *)(gm_mpu6050_interface_DW.obj_f.DeviceState);
    AXI4LITE_TERMINATE(p_state);
  }

  /* End of Start for MATLABSystem: '<S10>/AXI4-Interface Read' */

  /* Start for MATLABSystem: '<S7>/AXI4-Interface Read' incorporates:
   *  Terminate for MATLABSystem: '<S7>/AXI4-Interface Read'
   */
  if (gm_mpu6050_interface_DW.obj_b.isInitialized == 1) {
    gm_mpu6050_interface_DW.obj_b.isInitialized = 2;
    p_state = (AXI4_struct *)(gm_mpu6050_interface_DW.obj_b.DeviceState);
    AXI4LITE_TERMINATE(p_state);
  }

  /* End of Start for MATLABSystem: '<S7>/AXI4-Interface Read' */

  /* Start for MATLABSystem: '<S8>/AXI4-Interface Read' incorporates:
   *  Terminate for MATLABSystem: '<S8>/AXI4-Interface Read'
   */
  if (gm_mpu6050_interface_DW.obj_d.isInitialized == 1) {
    gm_mpu6050_interface_DW.obj_d.isInitialized = 2;
    p_state = (AXI4_struct *)(gm_mpu6050_interface_DW.obj_d.DeviceState);
    AXI4LITE_TERMINATE(p_state);
  }

  /* End of Start for MATLABSystem: '<S8>/AXI4-Interface Read' */

  /* Start for MATLABSystem: '<S9>/AXI4-Interface Read' incorporates:
   *  Terminate for MATLABSystem: '<S9>/AXI4-Interface Read'
   */
  if (gm_mpu6050_interface_DW.obj_c.isInitialized == 1) {
    gm_mpu6050_interface_DW.obj_c.isInitialized = 2;
    p_state = (AXI4_struct *)(gm_mpu6050_interface_DW.obj_c.DeviceState);
    AXI4LITE_TERMINATE(p_state);
  }

  /* End of Start for MATLABSystem: '<S9>/AXI4-Interface Read' */

  /* End of Terminate for SubSystem: '<Root>/I2C_MPU6050_IP' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
