/* Include files */

#include "mpu6050_working_sfun.h"
#include "c1_mpu6050_working.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "mpu6050_working_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c_with_debugger(S, sfGlobalDebugInstanceStruct);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c1_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c1_IN_cfgDone                  ((uint8_T)1U)
#define c1_IN_readPwrManagement1       ((uint8_T)2U)
#define c1_IN_readWhoAmI1              ((uint8_T)3U)
#define c1_IN_setupFS_SEL              ((uint8_T)4U)
#define c1_IN_setupReadPwrMgmt1        ((uint8_T)5U)
#define c1_IN_setupReadWhoAmI          ((uint8_T)6U)
#define c1_IN_setupWritePwrMgmt1       ((uint8_T)7U)
#define c1_IN_waitforNotBusy0          ((uint8_T)8U)
#define c1_IN_waitforNotBusy1          ((uint8_T)9U)
#define c1_IN_waitforNotBusy2          ((uint8_T)10U)
#define c1_IN_waitforNotBusy3          ((uint8_T)11U)
#define c1_IN_readAccelXoutH           ((uint8_T)12U)
#define c1_IN_readAccelXoutL           ((uint8_T)13U)
#define c1_IN_readAccelYoutH           ((uint8_T)14U)
#define c1_IN_readAccelZoutH           ((uint8_T)15U)
#define c1_IN_readAccelZoutL           ((uint8_T)16U)
#define c1_IN_readGyroYoutL            ((uint8_T)17U)
#define c1_IN_setupReadAccelXoutH      ((uint8_T)18U)
#define c1_IN_setupReadAccelXoutL      ((uint8_T)19U)
#define c1_IN_setupReadAccelYoutH      ((uint8_T)20U)
#define c1_IN_setupReadAccelYoutL      ((uint8_T)21U)
#define c1_IN_setupReadAccelZoutH      ((uint8_T)22U)
#define c1_IN_setupReadAccelZoutL      ((uint8_T)23U)
#define c1_IN_waitforNotBusya1         ((uint8_T)24U)
#define c1_IN_waitforNotBusya3         ((uint8_T)25U)
#define c1_IN_waitforNotBusya4         ((uint8_T)26U)
#define c1_IN_waitforNotBusya5         ((uint8_T)27U)
#define c1_IN_waitforNotBusya6         ((uint8_T)28U)
#define c1_IN_waitforNotBusya7         ((uint8_T)29U)
#define c1_IN_debuggingState           ((uint8_T)30U)
#define c1_IN_getDEVID                 ((uint8_T)31U)
#define c1_IN_getRegData               ((uint8_T)32U)
#define c1_IN_readDEVID                ((uint8_T)33U)
#define c1_IN_readUserRegData          ((uint8_T)34U)
#define c1_b_IN_waitforNotBusy1        ((uint8_T)35U)
#define c1_IN_waitforNotBusy5          ((uint8_T)36U)
#define c1_IN_readGyroXoutH            ((uint8_T)37U)
#define c1_IN_readGyroXoutL            ((uint8_T)38U)
#define c1_IN_readGyroYoutH            ((uint8_T)39U)
#define c1_b_IN_readGyroYoutL          ((uint8_T)40U)
#define c1_IN_readGyroZoutH            ((uint8_T)41U)
#define c1_IN_readGyroZoutL            ((uint8_T)42U)
#define c1_IN_setupReadGyroXoutH       ((uint8_T)43U)
#define c1_IN_setupReadGyroXoutL       ((uint8_T)44U)
#define c1_IN_setupReadGyroYoutH       ((uint8_T)45U)
#define c1_IN_setupReadGyroYoutL       ((uint8_T)46U)
#define c1_IN_setupReadGyroZoutH       ((uint8_T)47U)
#define c1_IN_setupReadGyroZoutL       ((uint8_T)48U)
#define c1_IN_waitforNotBusy01         ((uint8_T)49U)
#define c1_IN_waitforNotBusy03         ((uint8_T)50U)
#define c1_IN_waitforNotBusy04         ((uint8_T)51U)
#define c1_IN_waitforNotBusy05         ((uint8_T)52U)
#define c1_IN_waitforNotBusy06         ((uint8_T)53U)
#define c1_IN_waitforNotBusy07         ((uint8_T)54U)
#define c1_IN_Valid                    ((uint8_T)55U)
#define c1_IN_check_cfg                ((uint8_T)56U)
#define c1_IN_idle                     ((uint8_T)57U)
#define c1_IN_init                     ((uint8_T)58U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c1_debug_family_names[5] = { "nargin", "nargout", "msb",
  "lsb", "val" };

/* Function Declarations */
static void initialize_c1_mpu6050_working(SFc1_mpu6050_workingInstanceStruct
  *chartInstance);
static void initialize_params_c1_mpu6050_working
  (SFc1_mpu6050_workingInstanceStruct *chartInstance);
static void enable_c1_mpu6050_working(SFc1_mpu6050_workingInstanceStruct
  *chartInstance);
static void disable_c1_mpu6050_working(SFc1_mpu6050_workingInstanceStruct
  *chartInstance);
static void c1_update_debugger_state_c1_mpu6050_working
  (SFc1_mpu6050_workingInstanceStruct *chartInstance);
static void ext_mode_exec_c1_mpu6050_working(SFc1_mpu6050_workingInstanceStruct *
  chartInstance);
static const mxArray *get_sim_state_c1_mpu6050_working
  (SFc1_mpu6050_workingInstanceStruct *chartInstance);
static void set_sim_state_c1_mpu6050_working(SFc1_mpu6050_workingInstanceStruct *
  chartInstance, const mxArray *c1_st);
static void c1_set_sim_state_side_effects_c1_mpu6050_working
  (SFc1_mpu6050_workingInstanceStruct *chartInstance);
static void finalize_c1_mpu6050_working(SFc1_mpu6050_workingInstanceStruct
  *chartInstance);
static void sf_gateway_c1_mpu6050_working(SFc1_mpu6050_workingInstanceStruct
  *chartInstance);
static void mdl_start_c1_mpu6050_working(SFc1_mpu6050_workingInstanceStruct
  *chartInstance);
static void c1_chartstep_c1_mpu6050_working(SFc1_mpu6050_workingInstanceStruct
  *chartInstance);
static void initSimStructsc1_mpu6050_working(SFc1_mpu6050_workingInstanceStruct *
  chartInstance);
static void c1_setupReadWhoAmI(SFc1_mpu6050_workingInstanceStruct *chartInstance);
static void c1_waitforNotBusy0(SFc1_mpu6050_workingInstanceStruct *chartInstance);
static void c1_readWhoAmI1(SFc1_mpu6050_workingInstanceStruct *chartInstance);
static void c1_setupReadPwrMgmt1(SFc1_mpu6050_workingInstanceStruct
  *chartInstance);
static void c1_waitforNotBusy1(SFc1_mpu6050_workingInstanceStruct *chartInstance);
static void c1_readPwrManagement1(SFc1_mpu6050_workingInstanceStruct
  *chartInstance);
static void c1_setupWritePwrMgmt1(SFc1_mpu6050_workingInstanceStruct
  *chartInstance);
static void c1_waitforNotBusy2(SFc1_mpu6050_workingInstanceStruct *chartInstance);
static void c1_cfgDone(SFc1_mpu6050_workingInstanceStruct *chartInstance);
static void c1_getDEVID(SFc1_mpu6050_workingInstanceStruct *chartInstance);
static void c1_b_waitforNotBusy1(SFc1_mpu6050_workingInstanceStruct
  *chartInstance);
static void c1_readDEVID(SFc1_mpu6050_workingInstanceStruct *chartInstance);
static void c1_debuggingState(SFc1_mpu6050_workingInstanceStruct *chartInstance);
static void c1_getRegData(SFc1_mpu6050_workingInstanceStruct *chartInstance);
static void c1_waitforNotBusy5(SFc1_mpu6050_workingInstanceStruct *chartInstance);
static void c1_readUserRegData(SFc1_mpu6050_workingInstanceStruct *chartInstance);
static void c1_Valid(SFc1_mpu6050_workingInstanceStruct *chartInstance);
static void c1_setupReadGyroZoutH(SFc1_mpu6050_workingInstanceStruct
  *chartInstance);
static void c1_readGyroXoutL(SFc1_mpu6050_workingInstanceStruct *chartInstance);
static void c1_waitforNotBusy01(SFc1_mpu6050_workingInstanceStruct
  *chartInstance);
static void c1_readGyroYoutH(SFc1_mpu6050_workingInstanceStruct *chartInstance);
static void c1_waitforNotBusy06(SFc1_mpu6050_workingInstanceStruct
  *chartInstance);
static void c1_readGyroYoutL(SFc1_mpu6050_workingInstanceStruct *chartInstance);
static void c1_waitforNotBusy04(SFc1_mpu6050_workingInstanceStruct
  *chartInstance);
static void c1_readGyroZoutL(SFc1_mpu6050_workingInstanceStruct *chartInstance);
static void c1_waitforNotBusy03(SFc1_mpu6050_workingInstanceStruct
  *chartInstance);
static void c1_waitforNotBusy05(SFc1_mpu6050_workingInstanceStruct
  *chartInstance);
static void c1_setupReadGyroXoutL(SFc1_mpu6050_workingInstanceStruct
  *chartInstance);
static void c1_readGyroZoutH(SFc1_mpu6050_workingInstanceStruct *chartInstance);
static void c1_setupReadGyroYoutH(SFc1_mpu6050_workingInstanceStruct
  *chartInstance);
static void c1_setupReadGyroXoutH(SFc1_mpu6050_workingInstanceStruct
  *chartInstance);
static void c1_waitforNotBusya6(SFc1_mpu6050_workingInstanceStruct
  *chartInstance);
static void c1_readAccelZoutH(SFc1_mpu6050_workingInstanceStruct *chartInstance);
static void c1_setupReadAccelXoutH(SFc1_mpu6050_workingInstanceStruct
  *chartInstance);
static void c1_waitforNotBusya7(SFc1_mpu6050_workingInstanceStruct
  *chartInstance);
static void c1_readAccelXoutH(SFc1_mpu6050_workingInstanceStruct *chartInstance);
static void c1_waitforNotBusya3(SFc1_mpu6050_workingInstanceStruct
  *chartInstance);
static void c1_readAccelYoutH(SFc1_mpu6050_workingInstanceStruct *chartInstance);
static void c1_readAccelXoutL(SFc1_mpu6050_workingInstanceStruct *chartInstance);
static void c1_setupReadAccelYoutH(SFc1_mpu6050_workingInstanceStruct
  *chartInstance);
static void c1_setupReadAccelZoutL(SFc1_mpu6050_workingInstanceStruct
  *chartInstance);
static void c1_setupReadAccelZoutH(SFc1_mpu6050_workingInstanceStruct
  *chartInstance);
static void c1_waitforNotBusya5(SFc1_mpu6050_workingInstanceStruct
  *chartInstance);
static void c1_waitforNotBusya1(SFc1_mpu6050_workingInstanceStruct
  *chartInstance);
static void c1_waitforNotBusya4(SFc1_mpu6050_workingInstanceStruct
  *chartInstance);
static void c1_setupReadAccelYoutL(SFc1_mpu6050_workingInstanceStruct
  *chartInstance);
static void c1_readAccelZoutL(SFc1_mpu6050_workingInstanceStruct *chartInstance);
static void c1_setupReadAccelXoutL(SFc1_mpu6050_workingInstanceStruct
  *chartInstance);
static void c1_b_readGyroYoutL(SFc1_mpu6050_workingInstanceStruct *chartInstance);
static void c1_waitforNotBusy07(SFc1_mpu6050_workingInstanceStruct
  *chartInstance);
static void c1_readGyroXoutH(SFc1_mpu6050_workingInstanceStruct *chartInstance);
static void c1_setupReadGyroYoutL(SFc1_mpu6050_workingInstanceStruct
  *chartInstance);
static void c1_waitforNotBusy3(SFc1_mpu6050_workingInstanceStruct *chartInstance);
static void c1_setupFS_SEL(SFc1_mpu6050_workingInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static int16_T c1_emlrt_marshallIn(SFc1_mpu6050_workingInstanceStruct
  *chartInstance, const mxArray *c1_val, const char_T *c1_identifier);
static int16_T c1_b_emlrt_marshallIn(SFc1_mpu6050_workingInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static uint8_T c1_c_emlrt_marshallIn(SFc1_mpu6050_workingInstanceStruct
  *chartInstance, const mxArray *c1_lsb, const char_T *c1_identifier);
static uint8_T c1_d_emlrt_marshallIn(SFc1_mpu6050_workingInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_e_emlrt_marshallIn(SFc1_mpu6050_workingInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static int16_T c1_convert_int16(SFc1_mpu6050_workingInstanceStruct
  *chartInstance, uint8_T c1_msb, uint8_T c1_lsb);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_f_emlrt_marshallIn(SFc1_mpu6050_workingInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static boolean_T c1_g_emlrt_marshallIn(SFc1_mpu6050_workingInstanceStruct
  *chartInstance, const mxArray *c1_b_enb, const char_T *c1_identifier);
static boolean_T c1_h_emlrt_marshallIn(SFc1_mpu6050_workingInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static uint32_T c1_i_emlrt_marshallIn(SFc1_mpu6050_workingInstanceStruct
  *chartInstance, const mxArray *c1_b_cnt, const char_T *c1_identifier);
static uint32_T c1_j_emlrt_marshallIn(SFc1_mpu6050_workingInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_k_emlrt_marshallIn(SFc1_mpu6050_workingInstanceStruct
  *chartInstance, const mxArray *c1_b_setSimStateSideEffectsInfo, const char_T
  *c1_identifier);
static const mxArray *c1_l_emlrt_marshallIn(SFc1_mpu6050_workingInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static const mxArray *sf_get_hover_data_for_msg
  (SFc1_mpu6050_workingInstanceStruct *chartInstance, int32_T c1_ssid);
static void c1_init_sf_message_store_memory(SFc1_mpu6050_workingInstanceStruct
  *chartInstance);
static void init_dsm_address_info(SFc1_mpu6050_workingInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc1_mpu6050_workingInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_mpu6050_working(SFc1_mpu6050_workingInstanceStruct
  *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc1_mpu6050_working(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  *chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_doSetSimStateSideEffects = 0U;
  chartInstance->c1_setSimStateSideEffectsInfo = NULL;
  *chartInstance->c1_is_active_c1_mpu6050_working = 0U;
  *chartInstance->c1_is_c1_mpu6050_working = c1_IN_NO_ACTIVE_CHILD;
  *chartInstance->c1_cnt = 0U;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_cnt, 0U, 1U, 0U,
                        *chartInstance->c1_sfEvent, false);
  *chartInstance->c1_tempVal = 0U;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_tempVal, 1U, 1U, 0U,
                        *chartInstance->c1_sfEvent, false);
  if (!(sf_get_output_port_reusable(chartInstance->S, 1) != 0)) {
    *chartInstance->c1_enb = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 1U, 0U,
                          *chartInstance->c1_sfEvent, false);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 2) != 0)) {
    *chartInstance->c1_rw = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_rw, 11U, 1U, 0U,
                          *chartInstance->c1_sfEvent, false);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 3) != 0)) {
    *chartInstance->c1_mode = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_mode, 12U, 1U, 0U,
                          *chartInstance->c1_sfEvent, false);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 4) != 0)) {
    *chartInstance->c1_slv_addr = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_slv_addr, 13U, 1U, 0U,
                          *chartInstance->c1_sfEvent, false);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 5) != 0)) {
    *chartInstance->c1_reg_addr = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_reg_addr, 14U, 1U, 0U,
                          *chartInstance->c1_sfEvent, false);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 6) != 0)) {
    *chartInstance->c1_reg_byte_mode = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_reg_byte_mode, 15U, 1U, 0U,
                          *chartInstance->c1_sfEvent, false);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 7) != 0)) {
    *chartInstance->c1_data_out = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_data_out, 16U, 1U, 0U,
                          *chartInstance->c1_sfEvent, false);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 8) != 0)) {
    *chartInstance->c1_AccelX = 0;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_AccelX, 17U, 1U, 0U,
                          *chartInstance->c1_sfEvent, false);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 9) != 0)) {
    *chartInstance->c1_AccelY = 0;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_AccelY, 18U, 1U, 0U,
                          *chartInstance->c1_sfEvent, false);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 10) != 0)) {
    *chartInstance->c1_AccelZ = 0;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_AccelZ, 19U, 1U, 0U,
                          *chartInstance->c1_sfEvent, false);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 11) != 0)) {
    *chartInstance->c1_Valid_Out = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_Valid_Out, 20U, 1U, 0U,
                          *chartInstance->c1_sfEvent, false);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 12) != 0)) {
    *chartInstance->c1_deviceId = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_deviceId, 21U, 1U, 0U,
                          *chartInstance->c1_sfEvent, false);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 13) != 0)) {
    *chartInstance->c1_regdata = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_regdata, 22U, 1U, 0U,
                          *chartInstance->c1_sfEvent, false);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 14) != 0)) {
    *chartInstance->c1_GyroX = 0;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_GyroX, 23U, 1U, 0U,
                          *chartInstance->c1_sfEvent, false);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 15) != 0)) {
    *chartInstance->c1_GyroY = 0;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_GyroY, 24U, 1U, 0U,
                          *chartInstance->c1_sfEvent, false);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 16) != 0)) {
    *chartInstance->c1_GyroZ = 0;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_GyroZ, 25U, 1U, 0U,
                          *chartInstance->c1_sfEvent, false);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 17) != 0)) {
    *chartInstance->c1_isDeviceSetup = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_isDeviceSetup, 26U, 1U, 0U,
                          *chartInstance->c1_sfEvent, false);
  }

  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, *chartInstance->c1_sfEvent);
  *chartInstance->c1_is_active_c1_mpu6050_working = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, *chartInstance->c1_sfEvent);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, *chartInstance->c1_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, *chartInstance->c1_sfEvent);
  *chartInstance->c1_is_c1_mpu6050_working = c1_IN_init;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 62U, *chartInstance->c1_sfEvent);
  *chartInstance->c1_Valid_Out = false;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_Valid_Out, 20U, 4U, 62U,
                        *chartInstance->c1_sfEvent, false);
  *chartInstance->c1_isDeviceSetup = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_isDeviceSetup, 26U, 4U, 62U, *
                        chartInstance->c1_sfEvent, false);
  *chartInstance->c1_slv_addr = chartInstance->c1_SlvAddr;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_slv_addr, 13U, 4U, 62U,
                        *chartInstance->c1_sfEvent, false);
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, *chartInstance->c1_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_mpu6050_workingMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initialize_params_c1_mpu6050_working
  (SFc1_mpu6050_workingInstanceStruct *chartInstance)
{
  real_T c1_d0;
  real_T c1_d1;
  real_T c1_d2;
  real_T c1_d3;
  real_T c1_d4;
  real_T c1_d5;
  real_T c1_d6;
  sf_mex_import_named("SlvAddr", sf_mex_get_sfun_param(chartInstance->S, 4, 0),
                      &c1_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c1_SlvAddr = (uint8_T)c1_d0;
  sf_mex_import_named("AccelXRegAddr", sf_mex_get_sfun_param(chartInstance->S, 0,
    0), &c1_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c1_AccelXRegAddr = (uint8_T)c1_d1;
  sf_mex_import_named("AccelYRegAddr", sf_mex_get_sfun_param(chartInstance->S, 1,
    0), &c1_d2, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c1_AccelYRegAddr = (uint8_T)c1_d2;
  sf_mex_import_named("AccelZRegAddr", sf_mex_get_sfun_param(chartInstance->S, 2,
    0), &c1_d3, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c1_AccelZRegAddr = (uint8_T)c1_d3;
  sf_mex_import_named("powerRegData", sf_mex_get_sfun_param(chartInstance->S, 6,
    0), &c1_d4, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c1_powerRegData = (uint8_T)c1_d4;
  sf_mex_import_named("powerRegAddr", sf_mex_get_sfun_param(chartInstance->S, 5,
    0), &c1_d5, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c1_powerRegAddr = (uint8_T)c1_d5;
  sf_mex_import_named("GyroXRegAddr", sf_mex_get_sfun_param(chartInstance->S, 3,
    0), &c1_d6, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c1_GyroXRegAddr = (uint8_T)c1_d6;
}

static void enable_c1_mpu6050_working(SFc1_mpu6050_workingInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c1_mpu6050_working(SFc1_mpu6050_workingInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c1_update_debugger_state_c1_mpu6050_working
  (SFc1_mpu6050_workingInstanceStruct *chartInstance)
{
  uint32_T c1_prevAniVal;
  c1_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (*chartInstance->c1_is_active_c1_mpu6050_working == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_init) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 62U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 62U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_idle) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 61U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 61U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_setupReadWhoAmI) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_waitforNotBusy0) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_readWhoAmI1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_setupReadPwrMgmt1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_waitforNotBusy1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_readPwrManagement1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_setupWritePwrMgmt1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_waitforNotBusy2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_cfgDone) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_getDEVID) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 33U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 33U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_b_IN_waitforNotBusy1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 37U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 37U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_readDEVID) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 35U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 35U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_debuggingState) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 32U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 32U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_getRegData) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 34U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 34U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_waitforNotBusy5) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 38U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 38U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_readUserRegData) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 36U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 36U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_Valid) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 58U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 58U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_setupReadGyroZoutH) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 50U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 50U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_readGyroXoutL) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 41U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 41U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_waitforNotBusy01) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 52U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 52U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_readGyroYoutH) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 42U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 42U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_waitforNotBusy06) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 56U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 56U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_b_IN_readGyroYoutL) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 43U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 43U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_waitforNotBusy04) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 54U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 54U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_readGyroZoutL) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 45U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 45U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_waitforNotBusy03) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 53U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 53U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_waitforNotBusy05) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 55U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 55U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_setupReadGyroXoutL) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 47U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 47U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_readGyroZoutH) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 44U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 44U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_setupReadGyroYoutH) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 48U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 48U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_setupReadGyroZoutL) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 51U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 51U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_setupReadGyroXoutH) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 46U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 46U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_check_cfg) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 59U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 59U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_waitforNotBusya6) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 29U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 29U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_readAccelZoutH) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_setupReadAccelXoutH) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_waitforNotBusya7) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 30U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 30U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_readAccelXoutH) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_waitforNotBusya3) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 26U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 26U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_readAccelYoutH) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_readAccelXoutL) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_setupReadAccelYoutH) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 21U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_setupReadAccelZoutL) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 24U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 24U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_setupReadAccelZoutH) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 23U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 23U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_waitforNotBusya5) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 28U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 28U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_waitforNotBusya1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 25U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 25U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_waitforNotBusya4) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 27U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 27U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_setupReadAccelYoutL) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 22U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_readAccelZoutL) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_setupReadAccelXoutL) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_readGyroYoutL) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_waitforNotBusy07) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 57U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 57U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_readGyroXoutH) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 40U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 40U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_setupReadGyroYoutL) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 49U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 49U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_waitforNotBusy3) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, *chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_is_c1_mpu6050_working == c1_IN_setupFS_SEL) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, *chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, *chartInstance->c1_sfEvent);
  }

  _SFD_SET_ANIMATION(c1_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static void ext_mode_exec_c1_mpu6050_working(SFc1_mpu6050_workingInstanceStruct *
  chartInstance)
{
  c1_update_debugger_state_c1_mpu6050_working(chartInstance);
}

static const mxArray *get_sim_state_c1_mpu6050_working
  (SFc1_mpu6050_workingInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  int16_T c1_hoistedGlobal;
  const mxArray *c1_b_y = NULL;
  int16_T c1_b_hoistedGlobal;
  const mxArray *c1_c_y = NULL;
  int16_T c1_c_hoistedGlobal;
  const mxArray *c1_d_y = NULL;
  int16_T c1_d_hoistedGlobal;
  const mxArray *c1_e_y = NULL;
  int16_T c1_e_hoistedGlobal;
  const mxArray *c1_f_y = NULL;
  int16_T c1_f_hoistedGlobal;
  const mxArray *c1_g_y = NULL;
  boolean_T c1_g_hoistedGlobal;
  const mxArray *c1_h_y = NULL;
  uint8_T c1_h_hoistedGlobal;
  const mxArray *c1_i_y = NULL;
  uint8_T c1_i_hoistedGlobal;
  const mxArray *c1_j_y = NULL;
  boolean_T c1_j_hoistedGlobal;
  const mxArray *c1_k_y = NULL;
  boolean_T c1_k_hoistedGlobal;
  const mxArray *c1_l_y = NULL;
  boolean_T c1_l_hoistedGlobal;
  const mxArray *c1_m_y = NULL;
  uint8_T c1_m_hoistedGlobal;
  const mxArray *c1_n_y = NULL;
  boolean_T c1_n_hoistedGlobal;
  const mxArray *c1_o_y = NULL;
  uint8_T c1_o_hoistedGlobal;
  const mxArray *c1_p_y = NULL;
  boolean_T c1_p_hoistedGlobal;
  const mxArray *c1_q_y = NULL;
  uint8_T c1_q_hoistedGlobal;
  const mxArray *c1_r_y = NULL;
  uint32_T c1_r_hoistedGlobal;
  const mxArray *c1_s_y = NULL;
  uint8_T c1_s_hoistedGlobal;
  const mxArray *c1_t_y = NULL;
  uint8_T c1_t_hoistedGlobal;
  const mxArray *c1_u_y = NULL;
  uint8_T c1_u_hoistedGlobal;
  const mxArray *c1_v_y = NULL;
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellmatrix(21, 1), false);
  c1_hoistedGlobal = *chartInstance->c1_AccelX;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_hoistedGlobal, 4, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_b_hoistedGlobal = *chartInstance->c1_AccelY;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_hoistedGlobal, 4, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_c_hoistedGlobal = *chartInstance->c1_AccelZ;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_hoistedGlobal, 4, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  c1_d_hoistedGlobal = *chartInstance->c1_GyroX;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_d_hoistedGlobal, 4, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 3, c1_e_y);
  c1_e_hoistedGlobal = *chartInstance->c1_GyroY;
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_e_hoistedGlobal, 4, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 4, c1_f_y);
  c1_f_hoistedGlobal = *chartInstance->c1_GyroZ;
  c1_g_y = NULL;
  sf_mex_assign(&c1_g_y, sf_mex_create("y", &c1_f_hoistedGlobal, 4, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 5, c1_g_y);
  c1_g_hoistedGlobal = *chartInstance->c1_Valid_Out;
  c1_h_y = NULL;
  sf_mex_assign(&c1_h_y, sf_mex_create("y", &c1_g_hoistedGlobal, 11, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 6, c1_h_y);
  c1_h_hoistedGlobal = *chartInstance->c1_data_out;
  c1_i_y = NULL;
  sf_mex_assign(&c1_i_y, sf_mex_create("y", &c1_h_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 7, c1_i_y);
  c1_i_hoistedGlobal = *chartInstance->c1_deviceId;
  c1_j_y = NULL;
  sf_mex_assign(&c1_j_y, sf_mex_create("y", &c1_i_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 8, c1_j_y);
  c1_j_hoistedGlobal = *chartInstance->c1_enb;
  c1_k_y = NULL;
  sf_mex_assign(&c1_k_y, sf_mex_create("y", &c1_j_hoistedGlobal, 11, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 9, c1_k_y);
  c1_k_hoistedGlobal = *chartInstance->c1_isDeviceSetup;
  c1_l_y = NULL;
  sf_mex_assign(&c1_l_y, sf_mex_create("y", &c1_k_hoistedGlobal, 11, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 10, c1_l_y);
  c1_l_hoistedGlobal = *chartInstance->c1_mode;
  c1_m_y = NULL;
  sf_mex_assign(&c1_m_y, sf_mex_create("y", &c1_l_hoistedGlobal, 11, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 11, c1_m_y);
  c1_m_hoistedGlobal = *chartInstance->c1_reg_addr;
  c1_n_y = NULL;
  sf_mex_assign(&c1_n_y, sf_mex_create("y", &c1_m_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 12, c1_n_y);
  c1_n_hoistedGlobal = *chartInstance->c1_reg_byte_mode;
  c1_o_y = NULL;
  sf_mex_assign(&c1_o_y, sf_mex_create("y", &c1_n_hoistedGlobal, 11, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 13, c1_o_y);
  c1_o_hoistedGlobal = *chartInstance->c1_regdata;
  c1_p_y = NULL;
  sf_mex_assign(&c1_p_y, sf_mex_create("y", &c1_o_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 14, c1_p_y);
  c1_p_hoistedGlobal = *chartInstance->c1_rw;
  c1_q_y = NULL;
  sf_mex_assign(&c1_q_y, sf_mex_create("y", &c1_p_hoistedGlobal, 11, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 15, c1_q_y);
  c1_q_hoistedGlobal = *chartInstance->c1_slv_addr;
  c1_r_y = NULL;
  sf_mex_assign(&c1_r_y, sf_mex_create("y", &c1_q_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 16, c1_r_y);
  c1_r_hoistedGlobal = *chartInstance->c1_cnt;
  c1_s_y = NULL;
  sf_mex_assign(&c1_s_y, sf_mex_create("y", &c1_r_hoistedGlobal, 7, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 17, c1_s_y);
  c1_s_hoistedGlobal = *chartInstance->c1_tempVal;
  c1_t_y = NULL;
  sf_mex_assign(&c1_t_y, sf_mex_create("y", &c1_s_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 18, c1_t_y);
  c1_t_hoistedGlobal = *chartInstance->c1_is_active_c1_mpu6050_working;
  c1_u_y = NULL;
  sf_mex_assign(&c1_u_y, sf_mex_create("y", &c1_t_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 19, c1_u_y);
  c1_u_hoistedGlobal = *chartInstance->c1_is_c1_mpu6050_working;
  c1_v_y = NULL;
  sf_mex_assign(&c1_v_y, sf_mex_create("y", &c1_u_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 20, c1_v_y);
  sf_mex_assign(&c1_st, c1_y, false);
  return c1_st;
}

static void set_sim_state_c1_mpu6050_working(SFc1_mpu6050_workingInstanceStruct *
  chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  *chartInstance->c1_doneDoubleBufferReInit = true;
  c1_u = sf_mex_dup(c1_st);
  *chartInstance->c1_AccelX = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("AccelX", c1_u, 0)), "AccelX");
  *chartInstance->c1_AccelY = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("AccelY", c1_u, 1)), "AccelY");
  *chartInstance->c1_AccelZ = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("AccelZ", c1_u, 2)), "AccelZ");
  *chartInstance->c1_GyroX = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("GyroX", c1_u, 3)), "GyroX");
  *chartInstance->c1_GyroY = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("GyroY", c1_u, 4)), "GyroY");
  *chartInstance->c1_GyroZ = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("GyroZ", c1_u, 5)), "GyroZ");
  *chartInstance->c1_Valid_Out = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("Valid_Out", c1_u, 6)), "Valid_Out");
  *chartInstance->c1_data_out = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("data_out", c1_u, 7)), "data_out");
  *chartInstance->c1_deviceId = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("deviceId", c1_u, 8)), "deviceId");
  *chartInstance->c1_enb = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("enb", c1_u, 9)), "enb");
  *chartInstance->c1_isDeviceSetup = c1_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("isDeviceSetup", c1_u, 10)), "isDeviceSetup");
  *chartInstance->c1_mode = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("mode", c1_u, 11)), "mode");
  *chartInstance->c1_reg_addr = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("reg_addr", c1_u, 12)), "reg_addr");
  *chartInstance->c1_reg_byte_mode = c1_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("reg_byte_mode", c1_u, 13)), "reg_byte_mode");
  *chartInstance->c1_regdata = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("regdata", c1_u, 14)), "regdata");
  *chartInstance->c1_rw = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("rw", c1_u, 15)), "rw");
  *chartInstance->c1_slv_addr = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("slv_addr", c1_u, 16)), "slv_addr");
  *chartInstance->c1_cnt = c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("cnt", c1_u, 17)), "cnt");
  *chartInstance->c1_tempVal = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("tempVal", c1_u, 18)), "tempVal");
  *chartInstance->c1_is_active_c1_mpu6050_working = c1_c_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell("is_active_c1_mpu6050_working",
       c1_u, 19)), "is_active_c1_mpu6050_working");
  *chartInstance->c1_is_c1_mpu6050_working = c1_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_c1_mpu6050_working", c1_u, 20)),
    "is_c1_mpu6050_working");
  sf_mex_assign(&chartInstance->c1_setSimStateSideEffectsInfo,
                c1_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "setSimStateSideEffectsInfo", c1_u, 21)), "setSimStateSideEffectsInfo"),
                true);
  sf_mex_destroy(&c1_u);
  chartInstance->c1_doSetSimStateSideEffects = 1U;
  c1_update_debugger_state_c1_mpu6050_working(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void c1_set_sim_state_side_effects_c1_mpu6050_working
  (SFc1_mpu6050_workingInstanceStruct *chartInstance)
{
  if (chartInstance->c1_doSetSimStateSideEffects != 0) {
    chartInstance->c1_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c1_mpu6050_working(SFc1_mpu6050_workingInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c1_setSimStateSideEffectsInfo);
}

static void sf_gateway_c1_mpu6050_working(SFc1_mpu6050_workingInstanceStruct
  *chartInstance)
{
  c1_set_sim_state_side_effects_c1_mpu6050_working(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, *chartInstance->c1_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_configDevice, 9U, 1U, 0U,
                        *chartInstance->c1_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_userRegAddr, 8U, 1U, 0U,
                        *chartInstance->c1_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_mstr_ack, 7U, 1U, 0U,
                        *chartInstance->c1_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_data_in, 6U, 1U, 0U,
                        *chartInstance->c1_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_reg_mode, 5U, 1U, 0U,
                        *chartInstance->c1_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_byte_mode, 4U, 1U, 0U,
                        *chartInstance->c1_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_n_ack, 3U, 1U, 0U,
                        *chartInstance->c1_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_busy, 2U, 1U, 0U,
                        *chartInstance->c1_sfEvent, false);
  *chartInstance->c1_sfEvent = CALL_EVENT;
  c1_chartstep_c1_mpu6050_working(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_mpu6050_workingMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c1_mpu6050_working(SFc1_mpu6050_workingInstanceStruct
  *chartInstance)
{
  c1_init_sf_message_store_memory(chartInstance);
}

static void c1_chartstep_c1_mpu6050_working(SFc1_mpu6050_workingInstanceStruct
  *chartInstance)
{
  boolean_T c1_out;
  boolean_T c1_b_out;
  boolean_T c1_c_out;
  uint32_T c1_q0;
  int8_T c1_i0;
  boolean_T c1_d_out;
  uint32_T c1_qY;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, *chartInstance->c1_sfEvent);
  switch (*chartInstance->c1_is_c1_mpu6050_working) {
   case c1_IN_cfgDone:
    CV_CHART_EVAL(0, 0, 1);
    c1_cfgDone(chartInstance);
    break;

   case c1_IN_readPwrManagement1:
    CV_CHART_EVAL(0, 0, 2);
    c1_readPwrManagement1(chartInstance);
    break;

   case c1_IN_readWhoAmI1:
    CV_CHART_EVAL(0, 0, 3);
    c1_readWhoAmI1(chartInstance);
    break;

   case c1_IN_setupFS_SEL:
    CV_CHART_EVAL(0, 0, 4);
    c1_setupFS_SEL(chartInstance);
    break;

   case c1_IN_setupReadPwrMgmt1:
    CV_CHART_EVAL(0, 0, 5);
    c1_setupReadPwrMgmt1(chartInstance);
    break;

   case c1_IN_setupReadWhoAmI:
    CV_CHART_EVAL(0, 0, 6);
    c1_setupReadWhoAmI(chartInstance);
    break;

   case c1_IN_setupWritePwrMgmt1:
    CV_CHART_EVAL(0, 0, 7);
    c1_setupWritePwrMgmt1(chartInstance);
    break;

   case c1_IN_waitforNotBusy0:
    CV_CHART_EVAL(0, 0, 8);
    c1_waitforNotBusy0(chartInstance);
    break;

   case c1_IN_waitforNotBusy1:
    CV_CHART_EVAL(0, 0, 9);
    c1_waitforNotBusy1(chartInstance);
    break;

   case c1_IN_waitforNotBusy2:
    CV_CHART_EVAL(0, 0, 10);
    c1_waitforNotBusy2(chartInstance);
    break;

   case c1_IN_waitforNotBusy3:
    CV_CHART_EVAL(0, 0, 11);
    c1_waitforNotBusy3(chartInstance);
    break;

   case c1_IN_readAccelXoutH:
    CV_CHART_EVAL(0, 0, 12);
    c1_readAccelXoutH(chartInstance);
    break;

   case c1_IN_readAccelXoutL:
    CV_CHART_EVAL(0, 0, 13);
    c1_readAccelXoutL(chartInstance);
    break;

   case c1_IN_readAccelYoutH:
    CV_CHART_EVAL(0, 0, 14);
    c1_readAccelYoutH(chartInstance);
    break;

   case c1_IN_readAccelZoutH:
    CV_CHART_EVAL(0, 0, 15);
    c1_readAccelZoutH(chartInstance);
    break;

   case c1_IN_readAccelZoutL:
    CV_CHART_EVAL(0, 0, 16);
    c1_readAccelZoutL(chartInstance);
    break;

   case c1_IN_readGyroYoutL:
    CV_CHART_EVAL(0, 0, 17);
    c1_b_readGyroYoutL(chartInstance);
    break;

   case c1_IN_setupReadAccelXoutH:
    CV_CHART_EVAL(0, 0, 18);
    c1_setupReadAccelXoutH(chartInstance);
    break;

   case c1_IN_setupReadAccelXoutL:
    CV_CHART_EVAL(0, 0, 19);
    c1_setupReadAccelXoutL(chartInstance);
    break;

   case c1_IN_setupReadAccelYoutH:
    CV_CHART_EVAL(0, 0, 20);
    c1_setupReadAccelYoutH(chartInstance);
    break;

   case c1_IN_setupReadAccelYoutL:
    CV_CHART_EVAL(0, 0, 21);
    c1_setupReadAccelYoutL(chartInstance);
    break;

   case c1_IN_setupReadAccelZoutH:
    CV_CHART_EVAL(0, 0, 22);
    c1_setupReadAccelZoutH(chartInstance);
    break;

   case c1_IN_setupReadAccelZoutL:
    CV_CHART_EVAL(0, 0, 23);
    c1_setupReadAccelZoutL(chartInstance);
    break;

   case c1_IN_waitforNotBusya1:
    CV_CHART_EVAL(0, 0, 24);
    c1_waitforNotBusya1(chartInstance);
    break;

   case c1_IN_waitforNotBusya3:
    CV_CHART_EVAL(0, 0, 25);
    c1_waitforNotBusya3(chartInstance);
    break;

   case c1_IN_waitforNotBusya4:
    CV_CHART_EVAL(0, 0, 26);
    c1_waitforNotBusya4(chartInstance);
    break;

   case c1_IN_waitforNotBusya5:
    CV_CHART_EVAL(0, 0, 27);
    c1_waitforNotBusya5(chartInstance);
    break;

   case c1_IN_waitforNotBusya6:
    CV_CHART_EVAL(0, 0, 28);
    c1_waitforNotBusya6(chartInstance);
    break;

   case c1_IN_waitforNotBusya7:
    CV_CHART_EVAL(0, 0, 29);
    c1_waitforNotBusya7(chartInstance);
    break;

   case c1_IN_debuggingState:
    CV_CHART_EVAL(0, 0, 30);
    c1_debuggingState(chartInstance);
    break;

   case c1_IN_getDEVID:
    CV_CHART_EVAL(0, 0, 31);
    c1_getDEVID(chartInstance);
    break;

   case c1_IN_getRegData:
    CV_CHART_EVAL(0, 0, 32);
    c1_getRegData(chartInstance);
    break;

   case c1_IN_readDEVID:
    CV_CHART_EVAL(0, 0, 33);
    c1_readDEVID(chartInstance);
    break;

   case c1_IN_readUserRegData:
    CV_CHART_EVAL(0, 0, 34);
    c1_readUserRegData(chartInstance);
    break;

   case c1_b_IN_waitforNotBusy1:
    CV_CHART_EVAL(0, 0, 35);
    c1_b_waitforNotBusy1(chartInstance);
    break;

   case c1_IN_waitforNotBusy5:
    CV_CHART_EVAL(0, 0, 36);
    c1_waitforNotBusy5(chartInstance);
    break;

   case c1_IN_readGyroXoutH:
    CV_CHART_EVAL(0, 0, 37);
    c1_readGyroXoutH(chartInstance);
    break;

   case c1_IN_readGyroXoutL:
    CV_CHART_EVAL(0, 0, 38);
    c1_readGyroXoutL(chartInstance);
    break;

   case c1_IN_readGyroYoutH:
    CV_CHART_EVAL(0, 0, 39);
    c1_readGyroYoutH(chartInstance);
    break;

   case c1_b_IN_readGyroYoutL:
    CV_CHART_EVAL(0, 0, 40);
    c1_readGyroYoutL(chartInstance);
    break;

   case c1_IN_readGyroZoutH:
    CV_CHART_EVAL(0, 0, 41);
    c1_readGyroZoutH(chartInstance);
    break;

   case c1_IN_readGyroZoutL:
    CV_CHART_EVAL(0, 0, 42);
    c1_readGyroZoutL(chartInstance);
    break;

   case c1_IN_setupReadGyroXoutH:
    CV_CHART_EVAL(0, 0, 43);
    c1_setupReadGyroXoutH(chartInstance);
    break;

   case c1_IN_setupReadGyroXoutL:
    CV_CHART_EVAL(0, 0, 44);
    c1_setupReadGyroXoutL(chartInstance);
    break;

   case c1_IN_setupReadGyroYoutH:
    CV_CHART_EVAL(0, 0, 45);
    c1_setupReadGyroYoutH(chartInstance);
    break;

   case c1_IN_setupReadGyroYoutL:
    CV_CHART_EVAL(0, 0, 46);
    c1_setupReadGyroYoutL(chartInstance);
    break;

   case c1_IN_setupReadGyroZoutH:
    CV_CHART_EVAL(0, 0, 47);
    c1_setupReadGyroZoutH(chartInstance);
    break;

   case c1_IN_setupReadGyroZoutL:
    CV_CHART_EVAL(0, 0, 48);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 58U,
                 *chartInstance->c1_sfEvent);
    c1_out = (CV_TRANSITION_EVAL(58U, (int32_T)_SFD_CCP_CALL(58U, 0,
                CV_RELATIONAL_EVAL(5U, 58U, 0, (real_T)*chartInstance->c1_busy,
      1.0, 0, 0U, (int32_T)*chartInstance->c1_busy) != 0U,
                *chartInstance->c1_sfEvent)) != 0);
    if (c1_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 58U, *chartInstance->c1_sfEvent);
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 51U, *chartInstance->c1_sfEvent);
      *chartInstance->c1_is_c1_mpu6050_working = c1_IN_waitforNotBusy03;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 53U, *chartInstance->c1_sfEvent);
      *chartInstance->c1_enb = false;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 53U,
                            *chartInstance->c1_sfEvent, false);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 51U,
                   *chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 51U, *chartInstance->c1_sfEvent);
    break;

   case c1_IN_waitforNotBusy01:
    CV_CHART_EVAL(0, 0, 49);
    c1_waitforNotBusy01(chartInstance);
    break;

   case c1_IN_waitforNotBusy03:
    CV_CHART_EVAL(0, 0, 50);
    c1_waitforNotBusy03(chartInstance);
    break;

   case c1_IN_waitforNotBusy04:
    CV_CHART_EVAL(0, 0, 51);
    c1_waitforNotBusy04(chartInstance);
    break;

   case c1_IN_waitforNotBusy05:
    CV_CHART_EVAL(0, 0, 52);
    c1_waitforNotBusy05(chartInstance);
    break;

   case c1_IN_waitforNotBusy06:
    CV_CHART_EVAL(0, 0, 53);
    c1_waitforNotBusy06(chartInstance);
    break;

   case c1_IN_waitforNotBusy07:
    CV_CHART_EVAL(0, 0, 54);
    c1_waitforNotBusy07(chartInstance);
    break;

   case c1_IN_Valid:
    CV_CHART_EVAL(0, 0, 55);
    c1_Valid(chartInstance);
    break;

   case c1_IN_check_cfg:
    CV_CHART_EVAL(0, 0, 56);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                 *chartInstance->c1_sfEvent);
    c1_b_out = (CV_TRANSITION_EVAL(3U, (int32_T)_SFD_CCP_CALL(3U, 0,
      CV_RELATIONAL_EVAL(5U, 3U, 0, (real_T)*chartInstance->c1_cnt, 5.0, 0, 5U, *
                         chartInstance->c1_cnt >= 5U) != 0U,
      *chartInstance->c1_sfEvent)) != 0);
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, *chartInstance->c1_sfEvent);
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 59U, *chartInstance->c1_sfEvent);
      *chartInstance->c1_is_c1_mpu6050_working = c1_IN_idle;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 61U, *chartInstance->c1_sfEvent);
      *chartInstance->c1_enb = false;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 61U,
                            *chartInstance->c1_sfEvent, false);
      *chartInstance->c1_rw = false;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_rw, 11U, 4U, 61U,
                            *chartInstance->c1_sfEvent, false);
      *chartInstance->c1_mode = false;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_mode, 12U, 4U, 61U,
                            *chartInstance->c1_sfEvent, false);
      *chartInstance->c1_cnt = 0U;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_cnt, 0U, 4U, 61U,
                            *chartInstance->c1_sfEvent, false);
      *chartInstance->c1_reg_byte_mode = false;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_reg_byte_mode, 15U, 4U,
                            61U, *chartInstance->c1_sfEvent, false);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 59U,
                   *chartInstance->c1_sfEvent);
      c1_q0 = *chartInstance->c1_cnt;
      c1_i0 = 1;
      if (CV_SATURATION_EVAL(4, 59, 0, 0, c1_i0 < 0)) {
        c1_i0 = 0;
      }

      c1_qY = c1_q0 + (uint32_T)c1_i0;
      if (CV_SATURATION_EVAL(4, 59, 0, 0, c1_qY < c1_q0)) {
        c1_qY = MAX_uint32_T;
      }

      *chartInstance->c1_cnt = c1_qY;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_cnt, 0U, 4U, 59U,
                            *chartInstance->c1_sfEvent, false);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 59U, *chartInstance->c1_sfEvent);
    break;

   case c1_IN_idle:
    CV_CHART_EVAL(0, 0, 57);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 12U,
                 *chartInstance->c1_sfEvent);
    c1_c_out = (CV_TRANSITION_EVAL(12U, (int32_T)_SFD_CCP_CALL(12U, 0,
      CV_RELATIONAL_EVAL(5U, 12U, 0, (real_T)*chartInstance->c1_busy, 0.0, 0, 0U,
                         !*chartInstance->c1_busy) != 0U,
      *chartInstance->c1_sfEvent)) != 0);
    if (c1_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, *chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   *chartInstance->c1_sfEvent);
      c1_d_out = (CV_TRANSITION_EVAL(1U, (int32_T)_SFD_CCP_CALL(1U, 0,
        CV_RELATIONAL_EVAL(5U, 1U, 0, (real_T)((int32_T)
        *chartInstance->c1_configDevice | !*chartInstance->c1_isDeviceSetup),
                           0.0, 0, 1U, ((int32_T)*chartInstance->c1_configDevice
        | !*chartInstance->c1_isDeviceSetup) != 0) != 0U,
        *chartInstance->c1_sfEvent)) != 0);
      if (c1_d_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, *chartInstance->c1_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 61U, *chartInstance->c1_sfEvent);
        *chartInstance->c1_is_c1_mpu6050_working = c1_IN_setupReadWhoAmI;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, *chartInstance->c1_sfEvent);
        *chartInstance->c1_enb = true;
        _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 6U,
                              *chartInstance->c1_sfEvent, false);
        *chartInstance->c1_rw = true;
        _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_rw, 11U, 4U, 6U,
                              *chartInstance->c1_sfEvent, false);
        *chartInstance->c1_mode = false;
        _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_mode, 12U, 4U, 6U,
                              *chartInstance->c1_sfEvent, false);
        *chartInstance->c1_reg_addr = 117U;
        _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_reg_addr, 14U, 4U, 6U, *
                              chartInstance->c1_sfEvent, false);
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 18U, *chartInstance->c1_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 61U, *chartInstance->c1_sfEvent);
        *chartInstance->c1_is_c1_mpu6050_working = c1_IN_getDEVID;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 33U, *chartInstance->c1_sfEvent);
        *chartInstance->c1_enb = true;
        _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 33U,
                              *chartInstance->c1_sfEvent, false);
        *chartInstance->c1_rw = true;
        _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_rw, 11U, 4U, 33U,
                              *chartInstance->c1_sfEvent, false);
        *chartInstance->c1_mode = false;
        _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_mode, 12U, 4U, 33U,
                              *chartInstance->c1_sfEvent, false);
        *chartInstance->c1_reg_addr = 117U;
        _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_reg_addr, 14U, 4U, 33U,
                              *chartInstance->c1_sfEvent, false);
      }
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 61U,
                   *chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 61U, *chartInstance->c1_sfEvent);
    break;

   case c1_IN_init:
    CV_CHART_EVAL(0, 0, 58);
    *chartInstance->c1_slv_addr = chartInstance->c1_SlvAddr;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, *chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 62U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_is_c1_mpu6050_working = c1_IN_idle;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 61U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_enb = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 61U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_rw = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_rw, 11U, 4U, 61U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_mode = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_mode, 12U, 4U, 61U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_cnt = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_cnt, 0U, 4U, 61U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_reg_byte_mode = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_reg_byte_mode, 15U, 4U, 61U,
                          *chartInstance->c1_sfEvent, false);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 62U, *chartInstance->c1_sfEvent);
    break;

   default:
    CV_CHART_EVAL(0, 0, 0);

    /* Unreachable state, for coverage only */
    *chartInstance->c1_is_c1_mpu6050_working = c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, *chartInstance->c1_sfEvent);
    break;
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, *chartInstance->c1_sfEvent);
}

static void initSimStructsc1_mpu6050_working(SFc1_mpu6050_workingInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void c1_setupReadWhoAmI(SFc1_mpu6050_workingInstanceStruct *chartInstance)
{
  boolean_T c1_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 20U, *chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(20U, (int32_T)_SFD_CCP_CALL(20U, 0,
              CV_RELATIONAL_EVAL(5U, 20U, 0, (real_T)*chartInstance->c1_busy,
    1.0, 0, 0U, (int32_T)*chartInstance->c1_busy) != 0U,
              *chartInstance->c1_sfEvent)) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 20U, *chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_is_c1_mpu6050_working = c1_IN_waitforNotBusy0;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_enb = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 8U,
                          *chartInstance->c1_sfEvent, false);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U, *chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, *chartInstance->c1_sfEvent);
}

static void c1_waitforNotBusy0(SFc1_mpu6050_workingInstanceStruct *chartInstance)
{
  boolean_T c1_out;
  boolean_T c1_b_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 22U, *chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(22U, (int32_T)_SFD_CCP_CALL(22U, 0,
              CV_RELATIONAL_EVAL(5U, 22U, 0, (real_T)*chartInstance->c1_n_ack,
    1.0, 0, 0U, (int32_T)*chartInstance->c1_n_ack) != 0U,
              *chartInstance->c1_sfEvent)) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 22U, *chartInstance->c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, *chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_is_c1_mpu6050_working = c1_IN_check_cfg;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 59U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_enb = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 59U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_cnt = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_cnt, 0U, 4U, 59U,
                          *chartInstance->c1_sfEvent, false);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 23U,
                 *chartInstance->c1_sfEvent);
    c1_b_out = (CV_TRANSITION_EVAL(23U, (int32_T)_SFD_CCP_CALL(23U, 0,
      CV_RELATIONAL_EVAL(5U, 23U, 0, (real_T)*chartInstance->c1_mstr_ack, 1.0, 0,
                         0U, (int32_T)*chartInstance->c1_mstr_ack) != 0U,
      *chartInstance->c1_sfEvent)) != 0);
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 23U, *chartInstance->c1_sfEvent);
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, *chartInstance->c1_sfEvent);
      *chartInstance->c1_is_c1_mpu6050_working = c1_IN_readWhoAmI1;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, *chartInstance->c1_sfEvent);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U,
                   *chartInstance->c1_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, *chartInstance->c1_sfEvent);
}

static void c1_readWhoAmI1(SFc1_mpu6050_workingInstanceStruct *chartInstance)
{
  boolean_T c1_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 21U, *chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(21U, (int32_T)_SFD_CCP_CALL(21U, 0,
              CV_RELATIONAL_EVAL(5U, 21U, 0, (real_T)*chartInstance->c1_busy,
    0.0, 0, 0U, !*chartInstance->c1_busy) != 0U, *chartInstance->c1_sfEvent)) !=
            0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 21U, *chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_is_c1_mpu6050_working = c1_IN_setupReadPwrMgmt1;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_enb = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 5U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_rw = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_rw, 11U, 4U, 5U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_mode = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_mode, 12U, 4U, 5U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_reg_addr = 107U;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_reg_addr, 14U, 4U, 5U,
                          *chartInstance->c1_sfEvent, false);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U, *chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, *chartInstance->c1_sfEvent);
}

static void c1_setupReadPwrMgmt1(SFc1_mpu6050_workingInstanceStruct
  *chartInstance)
{
  boolean_T c1_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 24U, *chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(24U, (int32_T)_SFD_CCP_CALL(24U, 0,
              CV_RELATIONAL_EVAL(5U, 24U, 0, (real_T)*chartInstance->c1_busy,
    1.0, 0, 0U, (int32_T)*chartInstance->c1_busy) != 0U,
              *chartInstance->c1_sfEvent)) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 24U, *chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_is_c1_mpu6050_working = c1_IN_waitforNotBusy1;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_enb = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 9U,
                          *chartInstance->c1_sfEvent, false);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U, *chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, *chartInstance->c1_sfEvent);
}

static void c1_waitforNotBusy1(SFc1_mpu6050_workingInstanceStruct *chartInstance)
{
  boolean_T c1_out;
  boolean_T c1_b_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 27U, *chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(27U, (int32_T)_SFD_CCP_CALL(27U, 0,
              CV_RELATIONAL_EVAL(5U, 27U, 0, (real_T)*chartInstance->c1_n_ack,
    1.0, 0, 0U, (int32_T)*chartInstance->c1_n_ack) != 0U,
              *chartInstance->c1_sfEvent)) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 27U, *chartInstance->c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, *chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_is_c1_mpu6050_working = c1_IN_check_cfg;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 59U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_enb = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 59U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_cnt = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_cnt, 0U, 4U, 59U,
                          *chartInstance->c1_sfEvent, false);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 25U,
                 *chartInstance->c1_sfEvent);
    c1_b_out = (CV_TRANSITION_EVAL(25U, (int32_T)_SFD_CCP_CALL(25U, 0,
      CV_RELATIONAL_EVAL(5U, 25U, 0, (real_T)*chartInstance->c1_mstr_ack, 1.0, 0,
                         0U, (int32_T)*chartInstance->c1_mstr_ack) != 0U,
      *chartInstance->c1_sfEvent)) != 0);
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 25U, *chartInstance->c1_sfEvent);
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, *chartInstance->c1_sfEvent);
      *chartInstance->c1_is_c1_mpu6050_working = c1_IN_readPwrManagement1;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, *chartInstance->c1_sfEvent);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U,
                   *chartInstance->c1_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, *chartInstance->c1_sfEvent);
}

static void c1_readPwrManagement1(SFc1_mpu6050_workingInstanceStruct
  *chartInstance)
{
  boolean_T c1_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 82U, *chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(82U, (int32_T)_SFD_CCP_CALL(82U, 0,
              CV_RELATIONAL_EVAL(5U, 82U, 0, (real_T)*chartInstance->c1_busy,
    0.0, 0, 0U, !*chartInstance->c1_busy) != 0U, *chartInstance->c1_sfEvent)) !=
            0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 82U, *chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_is_c1_mpu6050_working = c1_IN_setupFS_SEL;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_enb = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 4U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_rw = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_rw, 11U, 4U, 4U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_mode = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_mode, 12U, 4U, 4U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_reg_addr = 27U;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_reg_addr, 14U, 4U, 4U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_data_out = 16U;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_data_out, 16U, 4U, 4U,
                          *chartInstance->c1_sfEvent, false);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U, *chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, *chartInstance->c1_sfEvent);
}

static void c1_setupWritePwrMgmt1(SFc1_mpu6050_workingInstanceStruct
  *chartInstance)
{
  boolean_T c1_out;
  *chartInstance->c1_data_out = 0U;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 15U, *chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(15U, (int32_T)_SFD_CCP_CALL(15U, 0,
              CV_RELATIONAL_EVAL(5U, 15U, 0, (real_T)*chartInstance->c1_busy,
    1.0, 0, 0U, (int32_T)*chartInstance->c1_busy) != 0U,
              *chartInstance->c1_sfEvent)) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, *chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_is_c1_mpu6050_working = c1_IN_waitforNotBusy2;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_enb = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 10U,
                          *chartInstance->c1_sfEvent, false);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U, *chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, *chartInstance->c1_sfEvent);
}

static void c1_waitforNotBusy2(SFc1_mpu6050_workingInstanceStruct *chartInstance)
{
  boolean_T c1_out;
  boolean_T c1_b_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 16U, *chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(16U, (int32_T)_SFD_CCP_CALL(16U, 0,
              CV_RELATIONAL_EVAL(5U, 16U, 0, (real_T)*chartInstance->c1_busy,
    0.0, 0, 0U, !*chartInstance->c1_busy) != 0U, *chartInstance->c1_sfEvent)) !=
            0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, *chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_is_c1_mpu6050_working = c1_IN_cfgDone;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_isDeviceSetup = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_isDeviceSetup, 26U, 4U, 1U,
                          *chartInstance->c1_sfEvent, false);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 17U,
                 *chartInstance->c1_sfEvent);
    c1_b_out = (CV_TRANSITION_EVAL(17U, (int32_T)_SFD_CCP_CALL(17U, 0,
      CV_RELATIONAL_EVAL(5U, 17U, 0, (real_T)*chartInstance->c1_n_ack, 1.0, 0,
                         0U, (int32_T)*chartInstance->c1_n_ack) != 0U,
      *chartInstance->c1_sfEvent)) != 0);
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 17U, *chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, *chartInstance->c1_sfEvent);
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, *chartInstance->c1_sfEvent);
      *chartInstance->c1_is_c1_mpu6050_working = c1_IN_check_cfg;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 59U, *chartInstance->c1_sfEvent);
      *chartInstance->c1_enb = false;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 59U,
                            *chartInstance->c1_sfEvent, false);
      *chartInstance->c1_cnt = 0U;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_cnt, 0U, 4U, 59U,
                            *chartInstance->c1_sfEvent, false);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 10U,
                   *chartInstance->c1_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, *chartInstance->c1_sfEvent);
}

static void c1_cfgDone(SFc1_mpu6050_workingInstanceStruct *chartInstance)
{
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 79U, *chartInstance->c1_sfEvent);
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, *chartInstance->c1_sfEvent);
  *chartInstance->c1_is_c1_mpu6050_working = c1_IN_setupReadAccelXoutH;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, *chartInstance->c1_sfEvent);
  *chartInstance->c1_enb = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 19U,
                        *chartInstance->c1_sfEvent, false);
  *chartInstance->c1_rw = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_rw, 11U, 4U, 19U,
                        *chartInstance->c1_sfEvent, false);
  *chartInstance->c1_mode = false;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_mode, 12U, 4U, 19U,
                        *chartInstance->c1_sfEvent, false);
  *chartInstance->c1_reg_addr = 59U;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_reg_addr, 14U, 4U, 19U,
                        *chartInstance->c1_sfEvent, false);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, *chartInstance->c1_sfEvent);
}

static void c1_getDEVID(SFc1_mpu6050_workingInstanceStruct *chartInstance)
{
  boolean_T c1_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U, *chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(6U, (int32_T)_SFD_CCP_CALL(6U, 0,
              CV_RELATIONAL_EVAL(5U, 6U, 0, (real_T)*chartInstance->c1_busy, 1.0,
    0, 0U, (int32_T)*chartInstance->c1_busy) != 0U, *chartInstance->c1_sfEvent))
            != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, *chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 33U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_is_c1_mpu6050_working = c1_b_IN_waitforNotBusy1;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 37U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_enb = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 37U,
                          *chartInstance->c1_sfEvent, false);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 33U,
                 *chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 33U, *chartInstance->c1_sfEvent);
}

static void c1_b_waitforNotBusy1(SFc1_mpu6050_workingInstanceStruct
  *chartInstance)
{
  boolean_T c1_out;
  boolean_T c1_b_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U, *chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(5U, (int32_T)_SFD_CCP_CALL(5U, 0,
              CV_RELATIONAL_EVAL(5U, 5U, 0, (real_T)*chartInstance->c1_mstr_ack,
    1.0, 0, 0U, (int32_T)*chartInstance->c1_mstr_ack) != 0U,
              *chartInstance->c1_sfEvent)) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, *chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 37U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_is_c1_mpu6050_working = c1_IN_readDEVID;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 35U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_deviceId = *chartInstance->c1_data_in;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_deviceId, 21U, 4U, 35U,
                          *chartInstance->c1_sfEvent, false);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U,
                 *chartInstance->c1_sfEvent);
    c1_b_out = (CV_TRANSITION_EVAL(7U, (int32_T)_SFD_CCP_CALL(7U, 0,
      CV_RELATIONAL_EVAL(5U, 7U, 0, (real_T)*chartInstance->c1_n_ack, 1.0, 0, 0U,
                         (int32_T)*chartInstance->c1_n_ack) != 0U,
      *chartInstance->c1_sfEvent)) != 0);
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, *chartInstance->c1_sfEvent);
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 37U, *chartInstance->c1_sfEvent);
      *chartInstance->c1_is_c1_mpu6050_working = c1_IN_debuggingState;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 32U, *chartInstance->c1_sfEvent);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 37U,
                   *chartInstance->c1_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 37U, *chartInstance->c1_sfEvent);
}

static void c1_readDEVID(SFc1_mpu6050_workingInstanceStruct *chartInstance)
{
  boolean_T c1_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 10U, *chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(10U, (int32_T)_SFD_CCP_CALL(10U, 0,
              CV_RELATIONAL_EVAL(5U, 10U, 0, (real_T)*chartInstance->c1_busy,
    0.0, 0, 0U, !*chartInstance->c1_busy) != 0U, *chartInstance->c1_sfEvent)) !=
            0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, *chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 35U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_is_c1_mpu6050_working = c1_IN_getRegData;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 34U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_enb = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 34U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_rw = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_rw, 11U, 4U, 34U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_mode = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_mode, 12U, 4U, 34U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_reg_addr = *chartInstance->c1_userRegAddr;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_reg_addr, 14U, 4U, 34U,
                          *chartInstance->c1_sfEvent, false);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 35U,
                 *chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 35U, *chartInstance->c1_sfEvent);
}

static void c1_debuggingState(SFc1_mpu6050_workingInstanceStruct *chartInstance)
{
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 19U, *chartInstance->c1_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, *chartInstance->c1_sfEvent);
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 32U, *chartInstance->c1_sfEvent);
  *chartInstance->c1_is_c1_mpu6050_working = c1_IN_check_cfg;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 59U, *chartInstance->c1_sfEvent);
  *chartInstance->c1_enb = false;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 59U,
                        *chartInstance->c1_sfEvent, false);
  *chartInstance->c1_cnt = 0U;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_cnt, 0U, 4U, 59U,
                        *chartInstance->c1_sfEvent, false);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 32U, *chartInstance->c1_sfEvent);
}

static void c1_getRegData(SFc1_mpu6050_workingInstanceStruct *chartInstance)
{
  boolean_T c1_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U, *chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(8U, (int32_T)_SFD_CCP_CALL(8U, 0,
              CV_RELATIONAL_EVAL(5U, 8U, 0, (real_T)*chartInstance->c1_busy, 1.0,
    0, 0U, (int32_T)*chartInstance->c1_busy) != 0U, *chartInstance->c1_sfEvent))
            != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, *chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 34U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_is_c1_mpu6050_working = c1_IN_waitforNotBusy5;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 38U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_enb = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 38U,
                          *chartInstance->c1_sfEvent, false);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 34U,
                 *chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 34U, *chartInstance->c1_sfEvent);
}

static void c1_waitforNotBusy5(SFc1_mpu6050_workingInstanceStruct *chartInstance)
{
  boolean_T c1_out;
  boolean_T c1_b_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 9U, *chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(9U, (int32_T)_SFD_CCP_CALL(9U, 0,
              CV_RELATIONAL_EVAL(5U, 9U, 0, (real_T)*chartInstance->c1_mstr_ack,
    1.0, 0, 0U, (int32_T)*chartInstance->c1_mstr_ack) != 0U,
              *chartInstance->c1_sfEvent)) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, *chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 38U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_is_c1_mpu6050_working = c1_IN_readUserRegData;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 36U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_regdata = *chartInstance->c1_data_in;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_regdata, 22U, 4U, 36U,
                          *chartInstance->c1_sfEvent, false);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 11U,
                 *chartInstance->c1_sfEvent);
    c1_b_out = (CV_TRANSITION_EVAL(11U, (int32_T)_SFD_CCP_CALL(11U, 0,
      CV_RELATIONAL_EVAL(5U, 11U, 0, (real_T)*chartInstance->c1_n_ack, 1.0, 0,
                         0U, (int32_T)*chartInstance->c1_n_ack) != 0U,
      *chartInstance->c1_sfEvent)) != 0);
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, *chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, *chartInstance->c1_sfEvent);
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 38U, *chartInstance->c1_sfEvent);
      *chartInstance->c1_is_c1_mpu6050_working = c1_IN_check_cfg;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 59U, *chartInstance->c1_sfEvent);
      *chartInstance->c1_enb = false;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 59U,
                            *chartInstance->c1_sfEvent, false);
      *chartInstance->c1_cnt = 0U;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_cnt, 0U, 4U, 59U,
                            *chartInstance->c1_sfEvent, false);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 38U,
                   *chartInstance->c1_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 38U, *chartInstance->c1_sfEvent);
}

static void c1_readUserRegData(SFc1_mpu6050_workingInstanceStruct *chartInstance)
{
  boolean_T c1_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 78U, *chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(78U, (int32_T)_SFD_CCP_CALL(78U, 0,
              CV_RELATIONAL_EVAL(5U, 78U, 0, (real_T)*chartInstance->c1_busy,
    0.0, 0, 0U, !*chartInstance->c1_busy) != 0U, *chartInstance->c1_sfEvent)) !=
            0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 78U, *chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 36U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_is_c1_mpu6050_working = c1_IN_setupReadAccelXoutH;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_enb = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 19U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_rw = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_rw, 11U, 4U, 19U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_mode = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_mode, 12U, 4U, 19U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_reg_addr = 59U;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_reg_addr, 14U, 4U, 19U,
                          *chartInstance->c1_sfEvent, false);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 36U,
                 *chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 36U, *chartInstance->c1_sfEvent);
}

static void c1_Valid(SFc1_mpu6050_workingInstanceStruct *chartInstance)
{
  boolean_T c1_out;
  uint32_T c1_q0;
  int8_T c1_i1;
  uint32_T c1_qY;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U, *chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(2U, (int32_T)_SFD_CCP_CALL(2U, 0,
              CV_RELATIONAL_EVAL(5U, 2U, 0, (real_T)*chartInstance->c1_cnt, 5.0,
    0, 5U, *chartInstance->c1_cnt >= 5U) != 0U, *chartInstance->c1_sfEvent)) !=
            0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, *chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 58U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_is_c1_mpu6050_working = c1_IN_check_cfg;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 59U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_enb = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 59U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_cnt = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_cnt, 0U, 4U, 59U,
                          *chartInstance->c1_sfEvent, false);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 58U,
                 *chartInstance->c1_sfEvent);
    c1_q0 = *chartInstance->c1_cnt;
    c1_i1 = 1;
    if (CV_SATURATION_EVAL(4, 58, 0, 0, c1_i1 < 0)) {
      c1_i1 = 0;
    }

    c1_qY = c1_q0 + (uint32_T)c1_i1;
    if (CV_SATURATION_EVAL(4, 58, 0, 0, c1_qY < c1_q0)) {
      c1_qY = MAX_uint32_T;
    }

    *chartInstance->c1_cnt = c1_qY;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_cnt, 0U, 4U, 58U,
                          *chartInstance->c1_sfEvent, false);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 58U, *chartInstance->c1_sfEvent);
}

static void c1_setupReadGyroZoutH(SFc1_mpu6050_workingInstanceStruct
  *chartInstance)
{
  boolean_T c1_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 52U, *chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(52U, (int32_T)_SFD_CCP_CALL(52U, 0,
              CV_RELATIONAL_EVAL(5U, 52U, 0, (real_T)*chartInstance->c1_busy,
    1.0, 0, 0U, (int32_T)*chartInstance->c1_busy) != 0U,
              *chartInstance->c1_sfEvent)) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 52U, *chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 50U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_is_c1_mpu6050_working = c1_IN_waitforNotBusy01;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 52U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_enb = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 52U,
                          *chartInstance->c1_sfEvent, false);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 50U,
                 *chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 50U, *chartInstance->c1_sfEvent);
}

static void c1_readGyroXoutL(SFc1_mpu6050_workingInstanceStruct *chartInstance)
{
  boolean_T c1_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 48U, *chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(48U, (int32_T)_SFD_CCP_CALL(48U, 0,
              CV_RELATIONAL_EVAL(5U, 48U, 0, (real_T)*chartInstance->c1_busy,
    0.0, 0, 0U, !*chartInstance->c1_busy) != 0U, *chartInstance->c1_sfEvent)) !=
            0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 48U, *chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 41U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_is_c1_mpu6050_working = c1_IN_setupReadGyroYoutH;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 48U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_enb = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 48U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_rw = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_rw, 11U, 4U, 48U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_mode = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_mode, 12U, 4U, 48U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_reg_addr = 69U;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_reg_addr, 14U, 4U, 48U,
                          *chartInstance->c1_sfEvent, false);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 41U,
                 *chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 41U, *chartInstance->c1_sfEvent);
}

static void c1_waitforNotBusy01(SFc1_mpu6050_workingInstanceStruct
  *chartInstance)
{
  boolean_T c1_out;
  boolean_T c1_b_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 53U, *chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(53U, (int32_T)_SFD_CCP_CALL(53U, 0,
              CV_RELATIONAL_EVAL(5U, 53U, 0, (real_T)*chartInstance->c1_mstr_ack,
    1.0, 0, 0U, (int32_T)*chartInstance->c1_mstr_ack) != 0U,
              *chartInstance->c1_sfEvent)) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 53U, *chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 52U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_is_c1_mpu6050_working = c1_IN_readGyroZoutH;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 44U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_tempVal = *chartInstance->c1_data_in;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_tempVal, 1U, 4U, 44U,
                          *chartInstance->c1_sfEvent, false);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 65U,
                 *chartInstance->c1_sfEvent);
    c1_b_out = (CV_TRANSITION_EVAL(65U, (int32_T)_SFD_CCP_CALL(65U, 0,
      CV_RELATIONAL_EVAL(5U, 65U, 0, (real_T)*chartInstance->c1_n_ack, 1.0, 0,
                         0U, (int32_T)*chartInstance->c1_n_ack) != 0U,
      *chartInstance->c1_sfEvent)) != 0);
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 65U, *chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 77U, *chartInstance->c1_sfEvent);
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 52U, *chartInstance->c1_sfEvent);
      *chartInstance->c1_is_c1_mpu6050_working = c1_IN_check_cfg;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 59U, *chartInstance->c1_sfEvent);
      *chartInstance->c1_enb = false;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 59U,
                            *chartInstance->c1_sfEvent, false);
      *chartInstance->c1_cnt = 0U;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_cnt, 0U, 4U, 59U,
                            *chartInstance->c1_sfEvent, false);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 52U,
                   *chartInstance->c1_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 52U, *chartInstance->c1_sfEvent);
}

static void c1_readGyroYoutH(SFc1_mpu6050_workingInstanceStruct *chartInstance)
{
  boolean_T c1_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 69U, *chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(69U, (int32_T)_SFD_CCP_CALL(69U, 0,
              CV_RELATIONAL_EVAL(5U, 69U, 0, (real_T)*chartInstance->c1_busy,
    0.0, 0, 0U, !*chartInstance->c1_busy) != 0U, *chartInstance->c1_sfEvent)) !=
            0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 69U, *chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 42U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_is_c1_mpu6050_working = c1_IN_setupReadGyroYoutL;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 49U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_enb = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 49U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_rw = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_rw, 11U, 4U, 49U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_mode = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_mode, 12U, 4U, 49U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_reg_addr = 70U;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_reg_addr, 14U, 4U, 49U,
                          *chartInstance->c1_sfEvent, false);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 42U,
                 *chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 42U, *chartInstance->c1_sfEvent);
}

static void c1_waitforNotBusy06(SFc1_mpu6050_workingInstanceStruct
  *chartInstance)
{
  boolean_T c1_out;
  boolean_T c1_b_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 63U, *chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(63U, (int32_T)_SFD_CCP_CALL(63U, 0,
              CV_RELATIONAL_EVAL(5U, 63U, 0, (real_T)*chartInstance->c1_mstr_ack,
    1.0, 0, 0U, (int32_T)*chartInstance->c1_mstr_ack) != 0U,
              *chartInstance->c1_sfEvent)) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 63U, *chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 56U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_is_c1_mpu6050_working = c1_IN_readGyroXoutH;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 40U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_tempVal = *chartInstance->c1_data_in;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_tempVal, 1U, 4U, 40U,
                          *chartInstance->c1_sfEvent, false);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 46U,
                 *chartInstance->c1_sfEvent);
    c1_b_out = (CV_TRANSITION_EVAL(46U, (int32_T)_SFD_CCP_CALL(46U, 0,
      CV_RELATIONAL_EVAL(5U, 46U, 0, (real_T)*chartInstance->c1_n_ack, 1.0, 0,
                         0U, (int32_T)*chartInstance->c1_n_ack) != 0U,
      *chartInstance->c1_sfEvent)) != 0);
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 46U, *chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 77U, *chartInstance->c1_sfEvent);
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 56U, *chartInstance->c1_sfEvent);
      *chartInstance->c1_is_c1_mpu6050_working = c1_IN_check_cfg;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 59U, *chartInstance->c1_sfEvent);
      *chartInstance->c1_enb = false;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 59U,
                            *chartInstance->c1_sfEvent, false);
      *chartInstance->c1_cnt = 0U;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_cnt, 0U, 4U, 59U,
                            *chartInstance->c1_sfEvent, false);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 56U,
                   *chartInstance->c1_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 56U, *chartInstance->c1_sfEvent);
}

static void c1_readGyroYoutL(SFc1_mpu6050_workingInstanceStruct *chartInstance)
{
  boolean_T c1_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 56U, *chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(56U, (int32_T)_SFD_CCP_CALL(56U, 0,
              CV_RELATIONAL_EVAL(5U, 56U, 0, (real_T)*chartInstance->c1_busy,
    0.0, 0, 0U, !*chartInstance->c1_busy) != 0U, *chartInstance->c1_sfEvent)) !=
            0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 56U, *chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 43U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_is_c1_mpu6050_working = c1_IN_setupReadGyroZoutH;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 50U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_enb = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 50U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_rw = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_rw, 11U, 4U, 50U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_mode = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_mode, 12U, 4U, 50U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_reg_addr = 71U;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_reg_addr, 14U, 4U, 50U,
                          *chartInstance->c1_sfEvent, false);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 43U,
                 *chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 43U, *chartInstance->c1_sfEvent);
}

static void c1_waitforNotBusy04(SFc1_mpu6050_workingInstanceStruct
  *chartInstance)
{
  boolean_T c1_out;
  boolean_T c1_b_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 50U, *chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(50U, (int32_T)_SFD_CCP_CALL(50U, 0,
              CV_RELATIONAL_EVAL(5U, 50U, 0, (real_T)*chartInstance->c1_mstr_ack,
    1.0, 0, 0U, (int32_T)*chartInstance->c1_mstr_ack) != 0U,
              *chartInstance->c1_sfEvent)) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 50U, *chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 54U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_is_c1_mpu6050_working = c1_IN_readGyroYoutH;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 42U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_tempVal = *chartInstance->c1_data_in;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_tempVal, 1U, 4U, 42U,
                          *chartInstance->c1_sfEvent, false);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 72U,
                 *chartInstance->c1_sfEvent);
    c1_b_out = (CV_TRANSITION_EVAL(72U, (int32_T)_SFD_CCP_CALL(72U, 0,
      CV_RELATIONAL_EVAL(5U, 72U, 0, (real_T)*chartInstance->c1_n_ack, 1.0, 0,
                         0U, (int32_T)*chartInstance->c1_n_ack) != 0U,
      *chartInstance->c1_sfEvent)) != 0);
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 72U, *chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 77U, *chartInstance->c1_sfEvent);
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 54U, *chartInstance->c1_sfEvent);
      *chartInstance->c1_is_c1_mpu6050_working = c1_IN_check_cfg;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 59U, *chartInstance->c1_sfEvent);
      *chartInstance->c1_enb = false;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 59U,
                            *chartInstance->c1_sfEvent, false);
      *chartInstance->c1_cnt = 0U;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_cnt, 0U, 4U, 59U,
                            *chartInstance->c1_sfEvent, false);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 54U,
                   *chartInstance->c1_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 54U, *chartInstance->c1_sfEvent);
}

static void c1_readGyroZoutL(SFc1_mpu6050_workingInstanceStruct *chartInstance)
{
  boolean_T c1_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 67U, *chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(67U, (int32_T)_SFD_CCP_CALL(67U, 0,
              CV_RELATIONAL_EVAL(5U, 67U, 0, (real_T)*chartInstance->c1_busy,
    0.0, 0, 0U, !*chartInstance->c1_busy) != 0U, *chartInstance->c1_sfEvent)) !=
            0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 67U, *chartInstance->c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 75U, *chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 45U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_is_c1_mpu6050_working = c1_IN_Valid;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 58U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_enb = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 58U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_cnt = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_cnt, 0U, 4U, 58U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_Valid_Out = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_Valid_Out, 20U, 4U, 58U,
                          *chartInstance->c1_sfEvent, false);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 45U,
                 *chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 45U, *chartInstance->c1_sfEvent);
}

static void c1_waitforNotBusy03(SFc1_mpu6050_workingInstanceStruct
  *chartInstance)
{
  boolean_T c1_out;
  boolean_T c1_b_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 60U, *chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(60U, (int32_T)_SFD_CCP_CALL(60U, 0,
              CV_RELATIONAL_EVAL(5U, 60U, 0, (real_T)*chartInstance->c1_mstr_ack,
    1.0, 0, 0U, (int32_T)*chartInstance->c1_mstr_ack) != 0U,
              *chartInstance->c1_sfEvent)) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 60U, *chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 53U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_is_c1_mpu6050_working = c1_IN_readGyroZoutL;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 45U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_GyroZ = c1_convert_int16(chartInstance,
      *chartInstance->c1_tempVal, *chartInstance->c1_data_in);
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_GyroZ, 25U, 4U, 45U,
                          *chartInstance->c1_sfEvent, false);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 45U,
                 *chartInstance->c1_sfEvent);
    c1_b_out = (CV_TRANSITION_EVAL(45U, (int32_T)_SFD_CCP_CALL(45U, 0,
      CV_RELATIONAL_EVAL(5U, 45U, 0, (real_T)*chartInstance->c1_n_ack, 1.0, 0,
                         0U, (int32_T)*chartInstance->c1_n_ack) != 0U,
      *chartInstance->c1_sfEvent)) != 0);
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 45U, *chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 77U, *chartInstance->c1_sfEvent);
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 53U, *chartInstance->c1_sfEvent);
      *chartInstance->c1_is_c1_mpu6050_working = c1_IN_check_cfg;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 59U, *chartInstance->c1_sfEvent);
      *chartInstance->c1_enb = false;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 59U,
                            *chartInstance->c1_sfEvent, false);
      *chartInstance->c1_cnt = 0U;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_cnt, 0U, 4U, 59U,
                            *chartInstance->c1_sfEvent, false);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 53U,
                   *chartInstance->c1_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 53U, *chartInstance->c1_sfEvent);
}

static void c1_waitforNotBusy05(SFc1_mpu6050_workingInstanceStruct
  *chartInstance)
{
  boolean_T c1_out;
  boolean_T c1_b_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 55U, *chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(55U, (int32_T)_SFD_CCP_CALL(55U, 0,
              CV_RELATIONAL_EVAL(5U, 55U, 0, (real_T)*chartInstance->c1_mstr_ack,
    1.0, 0, 0U, (int32_T)*chartInstance->c1_mstr_ack) != 0U,
              *chartInstance->c1_sfEvent)) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 55U, *chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 55U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_is_c1_mpu6050_working = c1_b_IN_readGyroYoutL;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 43U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_GyroY = c1_convert_int16(chartInstance,
      *chartInstance->c1_tempVal, *chartInstance->c1_data_in);
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_GyroY, 24U, 4U, 43U,
                          *chartInstance->c1_sfEvent, false);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 64U,
                 *chartInstance->c1_sfEvent);
    c1_b_out = (CV_TRANSITION_EVAL(64U, (int32_T)_SFD_CCP_CALL(64U, 0,
      CV_RELATIONAL_EVAL(5U, 64U, 0, (real_T)*chartInstance->c1_n_ack, 1.0, 0,
                         0U, (int32_T)*chartInstance->c1_n_ack) != 0U,
      *chartInstance->c1_sfEvent)) != 0);
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 64U, *chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 77U, *chartInstance->c1_sfEvent);
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 55U, *chartInstance->c1_sfEvent);
      *chartInstance->c1_is_c1_mpu6050_working = c1_IN_check_cfg;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 59U, *chartInstance->c1_sfEvent);
      *chartInstance->c1_enb = false;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 59U,
                            *chartInstance->c1_sfEvent, false);
      *chartInstance->c1_cnt = 0U;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_cnt, 0U, 4U, 59U,
                            *chartInstance->c1_sfEvent, false);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 55U,
                   *chartInstance->c1_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 55U, *chartInstance->c1_sfEvent);
}

static void c1_setupReadGyroXoutL(SFc1_mpu6050_workingInstanceStruct
  *chartInstance)
{
  boolean_T c1_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 59U, *chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(59U, (int32_T)_SFD_CCP_CALL(59U, 0,
              CV_RELATIONAL_EVAL(5U, 59U, 0, (real_T)*chartInstance->c1_busy,
    1.0, 0, 0U, (int32_T)*chartInstance->c1_busy) != 0U,
              *chartInstance->c1_sfEvent)) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 59U, *chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 47U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_is_c1_mpu6050_working = c1_IN_waitforNotBusy07;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 57U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_enb = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 57U,
                          *chartInstance->c1_sfEvent, false);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 47U,
                 *chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 47U, *chartInstance->c1_sfEvent);
}

static void c1_readGyroZoutH(SFc1_mpu6050_workingInstanceStruct *chartInstance)
{
  boolean_T c1_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 57U, *chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(57U, (int32_T)_SFD_CCP_CALL(57U, 0,
              CV_RELATIONAL_EVAL(5U, 57U, 0, (real_T)*chartInstance->c1_busy,
    0.0, 0, 0U, !*chartInstance->c1_busy) != 0U, *chartInstance->c1_sfEvent)) !=
            0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 57U, *chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 44U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_is_c1_mpu6050_working = c1_IN_setupReadGyroZoutL;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 51U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_enb = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 51U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_rw = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_rw, 11U, 4U, 51U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_mode = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_mode, 12U, 4U, 51U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_reg_addr = 72U;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_reg_addr, 14U, 4U, 51U,
                          *chartInstance->c1_sfEvent, false);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 44U,
                 *chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 44U, *chartInstance->c1_sfEvent);
}

static void c1_setupReadGyroYoutH(SFc1_mpu6050_workingInstanceStruct
  *chartInstance)
{
  boolean_T c1_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 49U, *chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(49U, (int32_T)_SFD_CCP_CALL(49U, 0,
              CV_RELATIONAL_EVAL(5U, 49U, 0, (real_T)*chartInstance->c1_busy,
    1.0, 0, 0U, (int32_T)*chartInstance->c1_busy) != 0U,
              *chartInstance->c1_sfEvent)) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 49U, *chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 48U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_is_c1_mpu6050_working = c1_IN_waitforNotBusy04;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 54U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_enb = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 54U,
                          *chartInstance->c1_sfEvent, false);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 48U,
                 *chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 48U, *chartInstance->c1_sfEvent);
}

static void c1_setupReadGyroXoutH(SFc1_mpu6050_workingInstanceStruct
  *chartInstance)
{
  boolean_T c1_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 51U, *chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(51U, (int32_T)_SFD_CCP_CALL(51U, 0,
              CV_RELATIONAL_EVAL(5U, 51U, 0, (real_T)*chartInstance->c1_busy,
    1.0, 0, 0U, (int32_T)*chartInstance->c1_busy) != 0U,
              *chartInstance->c1_sfEvent)) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 51U, *chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 46U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_is_c1_mpu6050_working = c1_IN_waitforNotBusy06;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 56U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_enb = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 56U,
                          *chartInstance->c1_sfEvent, false);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 46U,
                 *chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 46U, *chartInstance->c1_sfEvent);
}

static void c1_waitforNotBusya6(SFc1_mpu6050_workingInstanceStruct
  *chartInstance)
{
  boolean_T c1_out;
  boolean_T c1_b_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 62U, *chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(62U, (int32_T)_SFD_CCP_CALL(62U, 0,
              CV_RELATIONAL_EVAL(5U, 62U, 0, (real_T)*chartInstance->c1_mstr_ack,
    1.0, 0, 0U, (int32_T)*chartInstance->c1_mstr_ack) != 0U,
              *chartInstance->c1_sfEvent)) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 62U, *chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 29U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_is_c1_mpu6050_working = c1_IN_readAccelZoutH;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_tempVal = *chartInstance->c1_data_in;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_tempVal, 1U, 4U, 16U,
                          *chartInstance->c1_sfEvent, false);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 33U,
                 *chartInstance->c1_sfEvent);
    c1_b_out = (CV_TRANSITION_EVAL(33U, (int32_T)_SFD_CCP_CALL(33U, 0,
      CV_RELATIONAL_EVAL(5U, 33U, 0, (real_T)*chartInstance->c1_n_ack, 1.0, 0,
                         0U, (int32_T)*chartInstance->c1_n_ack) != 0U,
      *chartInstance->c1_sfEvent)) != 0);
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 33U, *chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 80U, *chartInstance->c1_sfEvent);
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 29U, *chartInstance->c1_sfEvent);
      *chartInstance->c1_is_c1_mpu6050_working = c1_IN_check_cfg;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 59U, *chartInstance->c1_sfEvent);
      *chartInstance->c1_enb = false;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 59U,
                            *chartInstance->c1_sfEvent, false);
      *chartInstance->c1_cnt = 0U;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_cnt, 0U, 4U, 59U,
                            *chartInstance->c1_sfEvent, false);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 29U,
                   *chartInstance->c1_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 29U, *chartInstance->c1_sfEvent);
}

static void c1_readAccelZoutH(SFc1_mpu6050_workingInstanceStruct *chartInstance)
{
  boolean_T c1_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 73U, *chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(73U, (int32_T)_SFD_CCP_CALL(73U, 0,
              CV_RELATIONAL_EVAL(5U, 73U, 0, (real_T)*chartInstance->c1_busy,
    0.0, 0, 0U, !*chartInstance->c1_busy) != 0U, *chartInstance->c1_sfEvent)) !=
            0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 73U, *chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_is_c1_mpu6050_working = c1_IN_setupReadAccelZoutL;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 24U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_enb = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 24U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_rw = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_rw, 11U, 4U, 24U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_mode = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_mode, 12U, 4U, 24U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_reg_addr = 64U;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_reg_addr, 14U, 4U, 24U,
                          *chartInstance->c1_sfEvent, false);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 16U,
                 *chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, *chartInstance->c1_sfEvent);
}

static void c1_setupReadAccelXoutH(SFc1_mpu6050_workingInstanceStruct
  *chartInstance)
{
  boolean_T c1_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 39U, *chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(39U, (int32_T)_SFD_CCP_CALL(39U, 0,
              CV_RELATIONAL_EVAL(5U, 39U, 0, (real_T)*chartInstance->c1_busy,
    1.0, 0, 0U, (int32_T)*chartInstance->c1_busy) != 0U,
              *chartInstance->c1_sfEvent)) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 39U, *chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_is_c1_mpu6050_working = c1_IN_waitforNotBusya1;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 25U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_enb = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 25U,
                          *chartInstance->c1_sfEvent, false);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 19U,
                 *chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19U, *chartInstance->c1_sfEvent);
}

static void c1_waitforNotBusya7(SFc1_mpu6050_workingInstanceStruct
  *chartInstance)
{
  boolean_T c1_out;
  boolean_T c1_b_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 47U, *chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(47U, (int32_T)_SFD_CCP_CALL(47U, 0,
              CV_RELATIONAL_EVAL(5U, 47U, 0, (real_T)*chartInstance->c1_mstr_ack,
    1.0, 0, 0U, (int32_T)*chartInstance->c1_mstr_ack) != 0U,
              *chartInstance->c1_sfEvent)) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 47U, *chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 30U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_is_c1_mpu6050_working = c1_IN_readAccelZoutL;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_AccelZ = c1_convert_int16(chartInstance,
      *chartInstance->c1_tempVal, *chartInstance->c1_data_in);
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_AccelZ, 19U, 4U, 17U,
                          *chartInstance->c1_sfEvent, false);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 44U,
                 *chartInstance->c1_sfEvent);
    c1_b_out = (CV_TRANSITION_EVAL(44U, (int32_T)_SFD_CCP_CALL(44U, 0,
      CV_RELATIONAL_EVAL(5U, 44U, 0, (real_T)*chartInstance->c1_n_ack, 1.0, 0,
                         0U, (int32_T)*chartInstance->c1_n_ack) != 0U,
      *chartInstance->c1_sfEvent)) != 0);
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 44U, *chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 80U, *chartInstance->c1_sfEvent);
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 30U, *chartInstance->c1_sfEvent);
      *chartInstance->c1_is_c1_mpu6050_working = c1_IN_check_cfg;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 59U, *chartInstance->c1_sfEvent);
      *chartInstance->c1_enb = false;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 59U,
                            *chartInstance->c1_sfEvent, false);
      *chartInstance->c1_cnt = 0U;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_cnt, 0U, 4U, 59U,
                            *chartInstance->c1_sfEvent, false);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 30U,
                   *chartInstance->c1_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 30U, *chartInstance->c1_sfEvent);
}

static void c1_readAccelXoutH(SFc1_mpu6050_workingInstanceStruct *chartInstance)
{
  boolean_T c1_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 34U, *chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(34U, (int32_T)_SFD_CCP_CALL(34U, 0,
              CV_RELATIONAL_EVAL(5U, 34U, 0, (real_T)*chartInstance->c1_busy,
    0.0, 0, 0U, !*chartInstance->c1_busy) != 0U, *chartInstance->c1_sfEvent)) !=
            0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 34U, *chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_is_c1_mpu6050_working = c1_IN_setupReadAccelXoutL;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_enb = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 20U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_rw = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_rw, 11U, 4U, 20U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_mode = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_mode, 12U, 4U, 20U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_reg_addr = 60U;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_reg_addr, 14U, 4U, 20U,
                          *chartInstance->c1_sfEvent, false);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 13U,
                 *chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, *chartInstance->c1_sfEvent);
}

static void c1_waitforNotBusya3(SFc1_mpu6050_workingInstanceStruct
  *chartInstance)
{
  boolean_T c1_out;
  boolean_T c1_b_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 40U, *chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(40U, (int32_T)_SFD_CCP_CALL(40U, 0,
              CV_RELATIONAL_EVAL(5U, 40U, 0, (real_T)*chartInstance->c1_mstr_ack,
    1.0, 0, 0U, (int32_T)*chartInstance->c1_mstr_ack) != 0U,
              *chartInstance->c1_sfEvent)) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 40U, *chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 26U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_is_c1_mpu6050_working = c1_IN_readAccelXoutL;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_AccelX = c1_convert_int16(chartInstance,
      *chartInstance->c1_tempVal, *chartInstance->c1_data_in);
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_AccelX, 17U, 4U, 14U,
                          *chartInstance->c1_sfEvent, false);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 32U,
                 *chartInstance->c1_sfEvent);
    c1_b_out = (CV_TRANSITION_EVAL(32U, (int32_T)_SFD_CCP_CALL(32U, 0,
      CV_RELATIONAL_EVAL(5U, 32U, 0, (real_T)*chartInstance->c1_n_ack, 1.0, 0,
                         0U, (int32_T)*chartInstance->c1_n_ack) != 0U,
      *chartInstance->c1_sfEvent)) != 0);
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 32U, *chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 80U, *chartInstance->c1_sfEvent);
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 26U, *chartInstance->c1_sfEvent);
      *chartInstance->c1_is_c1_mpu6050_working = c1_IN_check_cfg;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 59U, *chartInstance->c1_sfEvent);
      *chartInstance->c1_enb = false;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 59U,
                            *chartInstance->c1_sfEvent, false);
      *chartInstance->c1_cnt = 0U;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_cnt, 0U, 4U, 59U,
                            *chartInstance->c1_sfEvent, false);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 26U,
                   *chartInstance->c1_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 26U, *chartInstance->c1_sfEvent);
}

static void c1_readAccelYoutH(SFc1_mpu6050_workingInstanceStruct *chartInstance)
{
  boolean_T c1_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 36U, *chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(36U, (int32_T)_SFD_CCP_CALL(36U, 0,
              CV_RELATIONAL_EVAL(5U, 36U, 0, (real_T)*chartInstance->c1_busy,
    0.0, 0, 0U, !*chartInstance->c1_busy) != 0U, *chartInstance->c1_sfEvent)) !=
            0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 36U, *chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_is_c1_mpu6050_working = c1_IN_setupReadAccelYoutL;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 22U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_enb = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 22U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_rw = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_rw, 11U, 4U, 22U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_mode = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_mode, 12U, 4U, 22U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_reg_addr = 62U;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_reg_addr, 14U, 4U, 22U,
                          *chartInstance->c1_sfEvent, false);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 15U,
                 *chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 15U, *chartInstance->c1_sfEvent);
}

static void c1_readAccelXoutL(SFc1_mpu6050_workingInstanceStruct *chartInstance)
{
  boolean_T c1_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 41U, *chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(41U, (int32_T)_SFD_CCP_CALL(41U, 0,
              CV_RELATIONAL_EVAL(5U, 41U, 0, (real_T)*chartInstance->c1_busy,
    0.0, 0, 0U, !*chartInstance->c1_busy) != 0U, *chartInstance->c1_sfEvent)) !=
            0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 41U, *chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_is_c1_mpu6050_working = c1_IN_setupReadAccelYoutH;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 21U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_enb = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 21U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_rw = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_rw, 11U, 4U, 21U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_mode = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_mode, 12U, 4U, 21U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_reg_addr = 61U;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_reg_addr, 14U, 4U, 21U,
                          *chartInstance->c1_sfEvent, false);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 14U,
                 *chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, *chartInstance->c1_sfEvent);
}

static void c1_setupReadAccelYoutH(SFc1_mpu6050_workingInstanceStruct
  *chartInstance)
{
  boolean_T c1_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 28U, *chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(28U, (int32_T)_SFD_CCP_CALL(28U, 0,
              CV_RELATIONAL_EVAL(5U, 28U, 0, (real_T)*chartInstance->c1_busy,
    1.0, 0, 0U, (int32_T)*chartInstance->c1_busy) != 0U,
              *chartInstance->c1_sfEvent)) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 28U, *chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_is_c1_mpu6050_working = c1_IN_waitforNotBusya4;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 27U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_enb = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 27U,
                          *chartInstance->c1_sfEvent, false);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 21U,
                 *chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 21U, *chartInstance->c1_sfEvent);
}

static void c1_setupReadAccelZoutL(SFc1_mpu6050_workingInstanceStruct
  *chartInstance)
{
  boolean_T c1_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 74U, *chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(74U, (int32_T)_SFD_CCP_CALL(74U, 0,
              CV_RELATIONAL_EVAL(5U, 74U, 0, (real_T)*chartInstance->c1_busy,
    1.0, 0, 0U, (int32_T)*chartInstance->c1_busy) != 0U,
              *chartInstance->c1_sfEvent)) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 74U, *chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 24U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_is_c1_mpu6050_working = c1_IN_waitforNotBusya7;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 30U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_enb = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 30U,
                          *chartInstance->c1_sfEvent, false);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 24U,
                 *chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 24U, *chartInstance->c1_sfEvent);
}

static void c1_setupReadAccelZoutH(SFc1_mpu6050_workingInstanceStruct
  *chartInstance)
{
  boolean_T c1_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 61U, *chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(61U, (int32_T)_SFD_CCP_CALL(61U, 0,
              CV_RELATIONAL_EVAL(5U, 61U, 0, (real_T)*chartInstance->c1_busy,
    1.0, 0, 0U, (int32_T)*chartInstance->c1_busy) != 0U,
              *chartInstance->c1_sfEvent)) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 61U, *chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 23U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_is_c1_mpu6050_working = c1_IN_waitforNotBusya6;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 29U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_enb = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 29U,
                          *chartInstance->c1_sfEvent, false);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 23U,
                 *chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 23U, *chartInstance->c1_sfEvent);
}

static void c1_waitforNotBusya5(SFc1_mpu6050_workingInstanceStruct
  *chartInstance)
{
  boolean_T c1_out;
  boolean_T c1_b_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 38U, *chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(38U, (int32_T)_SFD_CCP_CALL(38U, 0,
              CV_RELATIONAL_EVAL(5U, 38U, 0, (real_T)*chartInstance->c1_mstr_ack,
    1.0, 0, 0U, (int32_T)*chartInstance->c1_mstr_ack) != 0U,
              *chartInstance->c1_sfEvent)) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 38U, *chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 28U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_is_c1_mpu6050_working = c1_IN_readGyroYoutL;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_AccelY = c1_convert_int16(chartInstance,
      *chartInstance->c1_tempVal, *chartInstance->c1_data_in);
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_AccelY, 18U, 4U, 18U,
                          *chartInstance->c1_sfEvent, false);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 42U,
                 *chartInstance->c1_sfEvent);
    c1_b_out = (CV_TRANSITION_EVAL(42U, (int32_T)_SFD_CCP_CALL(42U, 0,
      CV_RELATIONAL_EVAL(5U, 42U, 0, (real_T)*chartInstance->c1_n_ack, 1.0, 0,
                         0U, (int32_T)*chartInstance->c1_n_ack) != 0U,
      *chartInstance->c1_sfEvent)) != 0);
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 42U, *chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 80U, *chartInstance->c1_sfEvent);
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 28U, *chartInstance->c1_sfEvent);
      *chartInstance->c1_is_c1_mpu6050_working = c1_IN_check_cfg;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 59U, *chartInstance->c1_sfEvent);
      *chartInstance->c1_enb = false;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 59U,
                            *chartInstance->c1_sfEvent, false);
      *chartInstance->c1_cnt = 0U;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_cnt, 0U, 4U, 59U,
                            *chartInstance->c1_sfEvent, false);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 28U,
                   *chartInstance->c1_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 28U, *chartInstance->c1_sfEvent);
}

static void c1_waitforNotBusya1(SFc1_mpu6050_workingInstanceStruct
  *chartInstance)
{
  boolean_T c1_out;
  boolean_T c1_b_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 35U, *chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(35U, (int32_T)_SFD_CCP_CALL(35U, 0,
              CV_RELATIONAL_EVAL(5U, 35U, 0, (real_T)*chartInstance->c1_mstr_ack,
    1.0, 0, 0U, (int32_T)*chartInstance->c1_mstr_ack) != 0U,
              *chartInstance->c1_sfEvent)) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 35U, *chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 25U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_is_c1_mpu6050_working = c1_IN_readAccelXoutH;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_tempVal = *chartInstance->c1_data_in;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_tempVal, 1U, 4U, 13U,
                          *chartInstance->c1_sfEvent, false);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 43U,
                 *chartInstance->c1_sfEvent);
    c1_b_out = (CV_TRANSITION_EVAL(43U, (int32_T)_SFD_CCP_CALL(43U, 0,
      CV_RELATIONAL_EVAL(5U, 43U, 0, (real_T)*chartInstance->c1_n_ack, 1.0, 0,
                         0U, (int32_T)*chartInstance->c1_n_ack) != 0U,
      *chartInstance->c1_sfEvent)) != 0);
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 43U, *chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 80U, *chartInstance->c1_sfEvent);
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 25U, *chartInstance->c1_sfEvent);
      *chartInstance->c1_is_c1_mpu6050_working = c1_IN_check_cfg;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 59U, *chartInstance->c1_sfEvent);
      *chartInstance->c1_enb = false;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 59U,
                            *chartInstance->c1_sfEvent, false);
      *chartInstance->c1_cnt = 0U;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_cnt, 0U, 4U, 59U,
                            *chartInstance->c1_sfEvent, false);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 25U,
                   *chartInstance->c1_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 25U, *chartInstance->c1_sfEvent);
}

static void c1_waitforNotBusya4(SFc1_mpu6050_workingInstanceStruct
  *chartInstance)
{
  boolean_T c1_out;
  boolean_T c1_b_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 29U, *chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(29U, (int32_T)_SFD_CCP_CALL(29U, 0,
              CV_RELATIONAL_EVAL(5U, 29U, 0, (real_T)*chartInstance->c1_mstr_ack,
    1.0, 0, 0U, (int32_T)*chartInstance->c1_mstr_ack) != 0U,
              *chartInstance->c1_sfEvent)) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 29U, *chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 27U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_is_c1_mpu6050_working = c1_IN_readAccelYoutH;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_tempVal = *chartInstance->c1_data_in;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_tempVal, 1U, 4U, 15U,
                          *chartInstance->c1_sfEvent, false);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 31U,
                 *chartInstance->c1_sfEvent);
    c1_b_out = (CV_TRANSITION_EVAL(31U, (int32_T)_SFD_CCP_CALL(31U, 0,
      CV_RELATIONAL_EVAL(5U, 31U, 0, (real_T)*chartInstance->c1_n_ack, 1.0, 0,
                         0U, (int32_T)*chartInstance->c1_n_ack) != 0U,
      *chartInstance->c1_sfEvent)) != 0);
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 31U, *chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 80U, *chartInstance->c1_sfEvent);
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 27U, *chartInstance->c1_sfEvent);
      *chartInstance->c1_is_c1_mpu6050_working = c1_IN_check_cfg;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 59U, *chartInstance->c1_sfEvent);
      *chartInstance->c1_enb = false;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 59U,
                            *chartInstance->c1_sfEvent, false);
      *chartInstance->c1_cnt = 0U;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_cnt, 0U, 4U, 59U,
                            *chartInstance->c1_sfEvent, false);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 27U,
                   *chartInstance->c1_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 27U, *chartInstance->c1_sfEvent);
}

static void c1_setupReadAccelYoutL(SFc1_mpu6050_workingInstanceStruct
  *chartInstance)
{
  boolean_T c1_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 37U, *chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(37U, (int32_T)_SFD_CCP_CALL(37U, 0,
              CV_RELATIONAL_EVAL(5U, 37U, 0, (real_T)*chartInstance->c1_busy,
    1.0, 0, 0U, (int32_T)*chartInstance->c1_busy) != 0U,
              *chartInstance->c1_sfEvent)) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 37U, *chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_is_c1_mpu6050_working = c1_IN_waitforNotBusya5;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 28U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_enb = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 28U,
                          *chartInstance->c1_sfEvent, false);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 22U,
                 *chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 22U, *chartInstance->c1_sfEvent);
}

static void c1_readAccelZoutL(SFc1_mpu6050_workingInstanceStruct *chartInstance)
{
  boolean_T c1_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 76U, *chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(76U, (int32_T)_SFD_CCP_CALL(76U, 0,
              CV_RELATIONAL_EVAL(5U, 76U, 0, (real_T)*chartInstance->c1_busy,
    0.0, 0, 0U, !*chartInstance->c1_busy) != 0U, *chartInstance->c1_sfEvent)) !=
            0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 76U, *chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_is_c1_mpu6050_working = c1_IN_setupReadGyroXoutH;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 46U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_enb = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 46U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_rw = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_rw, 11U, 4U, 46U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_mode = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_mode, 12U, 4U, 46U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_reg_addr = 67U;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_reg_addr, 14U, 4U, 46U,
                          *chartInstance->c1_sfEvent, false);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 17U,
                 *chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 17U, *chartInstance->c1_sfEvent);
}

static void c1_setupReadAccelXoutL(SFc1_mpu6050_workingInstanceStruct
  *chartInstance)
{
  boolean_T c1_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 30U, *chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(30U, (int32_T)_SFD_CCP_CALL(30U, 0,
              CV_RELATIONAL_EVAL(5U, 30U, 0, (real_T)*chartInstance->c1_busy,
    1.0, 0, 0U, (int32_T)*chartInstance->c1_busy) != 0U,
              *chartInstance->c1_sfEvent)) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 30U, *chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_is_c1_mpu6050_working = c1_IN_waitforNotBusya3;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 26U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_enb = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 26U,
                          *chartInstance->c1_sfEvent, false);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 20U,
                 *chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 20U, *chartInstance->c1_sfEvent);
}

static void c1_b_readGyroYoutL(SFc1_mpu6050_workingInstanceStruct *chartInstance)
{
  boolean_T c1_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 70U, *chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(70U, (int32_T)_SFD_CCP_CALL(70U, 0,
              CV_RELATIONAL_EVAL(5U, 70U, 0, (real_T)*chartInstance->c1_busy,
    0.0, 0, 0U, !*chartInstance->c1_busy) != 0U, *chartInstance->c1_sfEvent)) !=
            0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 70U, *chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_is_c1_mpu6050_working = c1_IN_setupReadAccelZoutH;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 23U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_enb = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 23U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_rw = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_rw, 11U, 4U, 23U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_mode = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_mode, 12U, 4U, 23U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_reg_addr = 63U;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_reg_addr, 14U, 4U, 23U,
                          *chartInstance->c1_sfEvent, false);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 18U,
                 *chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 18U, *chartInstance->c1_sfEvent);
}

static void c1_waitforNotBusy07(SFc1_mpu6050_workingInstanceStruct
  *chartInstance)
{
  boolean_T c1_out;
  boolean_T c1_b_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 54U, *chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(54U, (int32_T)_SFD_CCP_CALL(54U, 0,
              CV_RELATIONAL_EVAL(5U, 54U, 0, (real_T)*chartInstance->c1_mstr_ack,
    1.0, 0, 0U, (int32_T)*chartInstance->c1_mstr_ack) != 0U,
              *chartInstance->c1_sfEvent)) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 54U, *chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 57U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_is_c1_mpu6050_working = c1_IN_readGyroXoutL;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 41U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_GyroX = c1_convert_int16(chartInstance,
      *chartInstance->c1_tempVal, *chartInstance->c1_data_in);
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_GyroX, 23U, 4U, 41U,
                          *chartInstance->c1_sfEvent, false);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 68U,
                 *chartInstance->c1_sfEvent);
    c1_b_out = (CV_TRANSITION_EVAL(68U, (int32_T)_SFD_CCP_CALL(68U, 0,
      CV_RELATIONAL_EVAL(5U, 68U, 0, (real_T)*chartInstance->c1_n_ack, 1.0, 0,
                         0U, (int32_T)*chartInstance->c1_n_ack) != 0U,
      *chartInstance->c1_sfEvent)) != 0);
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 68U, *chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 77U, *chartInstance->c1_sfEvent);
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 57U, *chartInstance->c1_sfEvent);
      *chartInstance->c1_is_c1_mpu6050_working = c1_IN_check_cfg;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 59U, *chartInstance->c1_sfEvent);
      *chartInstance->c1_enb = false;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 59U,
                            *chartInstance->c1_sfEvent, false);
      *chartInstance->c1_cnt = 0U;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_cnt, 0U, 4U, 59U,
                            *chartInstance->c1_sfEvent, false);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 57U,
                   *chartInstance->c1_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 57U, *chartInstance->c1_sfEvent);
}

static void c1_readGyroXoutH(SFc1_mpu6050_workingInstanceStruct *chartInstance)
{
  boolean_T c1_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 71U, *chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(71U, (int32_T)_SFD_CCP_CALL(71U, 0,
              CV_RELATIONAL_EVAL(5U, 71U, 0, (real_T)*chartInstance->c1_busy,
    0.0, 0, 0U, !*chartInstance->c1_busy) != 0U, *chartInstance->c1_sfEvent)) !=
            0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 71U, *chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 40U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_is_c1_mpu6050_working = c1_IN_setupReadGyroXoutL;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 47U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_enb = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 47U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_rw = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_rw, 11U, 4U, 47U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_mode = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_mode, 12U, 4U, 47U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_reg_addr = 68U;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_reg_addr, 14U, 4U, 47U,
                          *chartInstance->c1_sfEvent, false);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 40U,
                 *chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 40U, *chartInstance->c1_sfEvent);
}

static void c1_setupReadGyroYoutL(SFc1_mpu6050_workingInstanceStruct
  *chartInstance)
{
  boolean_T c1_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 66U, *chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(66U, (int32_T)_SFD_CCP_CALL(66U, 0,
              CV_RELATIONAL_EVAL(5U, 66U, 0, (real_T)*chartInstance->c1_busy,
    1.0, 0, 0U, (int32_T)*chartInstance->c1_busy) != 0U,
              *chartInstance->c1_sfEvent)) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 66U, *chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 49U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_is_c1_mpu6050_working = c1_IN_waitforNotBusy05;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 55U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_enb = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 55U,
                          *chartInstance->c1_sfEvent, false);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 49U,
                 *chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 49U, *chartInstance->c1_sfEvent);
}

static void c1_waitforNotBusy3(SFc1_mpu6050_workingInstanceStruct *chartInstance)
{
  boolean_T c1_out;
  boolean_T c1_b_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 26U, *chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(26U, (int32_T)_SFD_CCP_CALL(26U, 0,
              CV_RELATIONAL_EVAL(5U, 26U, 0, (real_T)*chartInstance->c1_busy,
    0.0, 0, 0U, !*chartInstance->c1_busy) != 0U, *chartInstance->c1_sfEvent)) !=
            0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 26U, *chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_is_c1_mpu6050_working = c1_IN_setupWritePwrMgmt1;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_enb = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 7U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_rw = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_rw, 11U, 4U, 7U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_mode = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_mode, 12U, 4U, 7U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_reg_addr = 107U;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_reg_addr, 14U, 4U, 7U,
                          *chartInstance->c1_sfEvent, false);
    *chartInstance->c1_data_out = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_data_out, 16U, 4U, 7U,
                          *chartInstance->c1_sfEvent, false);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 83U,
                 *chartInstance->c1_sfEvent);
    c1_b_out = (CV_TRANSITION_EVAL(83U, (int32_T)_SFD_CCP_CALL(83U, 0,
      CV_RELATIONAL_EVAL(5U, 83U, 0, (real_T)*chartInstance->c1_n_ack, 1.0, 0,
                         0U, (int32_T)*chartInstance->c1_n_ack) != 0U,
      *chartInstance->c1_sfEvent)) != 0);
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 83U, *chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, *chartInstance->c1_sfEvent);
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, *chartInstance->c1_sfEvent);
      *chartInstance->c1_is_c1_mpu6050_working = c1_IN_check_cfg;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 59U, *chartInstance->c1_sfEvent);
      *chartInstance->c1_enb = false;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 59U,
                            *chartInstance->c1_sfEvent, false);
      *chartInstance->c1_cnt = 0U;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_cnt, 0U, 4U, 59U,
                            *chartInstance->c1_sfEvent, false);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 11U,
                   *chartInstance->c1_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, *chartInstance->c1_sfEvent);
}

static void c1_setupFS_SEL(SFc1_mpu6050_workingInstanceStruct *chartInstance)
{
  boolean_T c1_out;
  *chartInstance->c1_data_out = 16U;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 81U, *chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(81U, (int32_T)_SFD_CCP_CALL(81U, 0,
              CV_RELATIONAL_EVAL(5U, 81U, 0, (real_T)*chartInstance->c1_busy,
    1.0, 0, 0U, (int32_T)*chartInstance->c1_busy) != 0U,
              *chartInstance->c1_sfEvent)) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 81U, *chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_is_c1_mpu6050_working = c1_IN_waitforNotBusy3;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, *chartInstance->c1_sfEvent);
    *chartInstance->c1_enb = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_enb, 10U, 4U, 11U,
                          *chartInstance->c1_sfEvent, false);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U, *chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, *chartInstance->c1_sfEvent);
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber)
{
  (void)(c1_machineNumber);
  (void)(c1_chartNumber);
  (void)(c1_instanceNumber);
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  int16_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_mpu6050_workingInstanceStruct *chartInstance;
  chartInstance = (SFc1_mpu6050_workingInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_u = *(int16_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 4, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static int16_T c1_emlrt_marshallIn(SFc1_mpu6050_workingInstanceStruct
  *chartInstance, const mxArray *c1_val, const char_T *c1_identifier)
{
  int16_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_val), &c1_thisId);
  sf_mex_destroy(&c1_val);
  return c1_y;
}

static int16_T c1_b_emlrt_marshallIn(SFc1_mpu6050_workingInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int16_T c1_y;
  int16_T c1_i2;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i2, 1, 4, 0U, 0, 0U, 0);
  c1_y = c1_i2;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_val;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int16_T c1_y;
  SFc1_mpu6050_workingInstanceStruct *chartInstance;
  chartInstance = (SFc1_mpu6050_workingInstanceStruct *)chartInstanceVoid;
  c1_val = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_val), &c1_thisId);
  sf_mex_destroy(&c1_val);
  *(int16_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  uint8_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_mpu6050_workingInstanceStruct *chartInstance;
  chartInstance = (SFc1_mpu6050_workingInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_u = *(uint8_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static uint8_T c1_c_emlrt_marshallIn(SFc1_mpu6050_workingInstanceStruct
  *chartInstance, const mxArray *c1_lsb, const char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_lsb), &c1_thisId);
  sf_mex_destroy(&c1_lsb);
  return c1_y;
}

static uint8_T c1_d_emlrt_marshallIn(SFc1_mpu6050_workingInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_lsb;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  uint8_T c1_y;
  SFc1_mpu6050_workingInstanceStruct *chartInstance;
  chartInstance = (SFc1_mpu6050_workingInstanceStruct *)chartInstanceVoid;
  c1_lsb = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_lsb), &c1_thisId);
  sf_mex_destroy(&c1_lsb);
  *(uint8_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_mpu6050_workingInstanceStruct *chartInstance;
  chartInstance = (SFc1_mpu6050_workingInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static real_T c1_e_emlrt_marshallIn(SFc1_mpu6050_workingInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d7;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d7, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d7;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_nargout;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_mpu6050_workingInstanceStruct *chartInstance;
  chartInstance = (SFc1_mpu6050_workingInstanceStruct *)chartInstanceVoid;
  c1_nargout = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_mpu6050_working_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c1_nameCaptureInfo;
}

static int16_T c1_convert_int16(SFc1_mpu6050_workingInstanceStruct
  *chartInstance, uint8_T c1_msb, uint8_T c1_lsb)
{
  int16_T c1_val;
  uint32_T c1_debug_family_var_map[5];
  real_T c1_nargin = 2.0;
  real_T c1_nargout = 1.0;
  int16_T c1_a;
  int16_T c1_b_a;
  int16_T c1_c;
  int16_T c1_varargin_1;
  int16_T c1_varargin_2;
  int16_T c1_c_a;
  int16_T c1_b;
  _SFD_DATA_RANGE_CHECK((real_T)c1_lsb, 28U, 4U, 60U, *chartInstance->c1_sfEvent,
                        false);
  _SFD_DATA_RANGE_CHECK((real_T)c1_msb, 27U, 4U, 60U, *chartInstance->c1_sfEvent,
                        false);
  _SFD_SET_DATA_VALUE_PTR(29U, &c1_val);
  _SFD_SET_DATA_VALUE_PTR(28U, &c1_lsb);
  _SFD_SET_DATA_VALUE_PTR(27U, &c1_msb);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_msb, 2U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_lsb, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_val, 4U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(60, 0);
  _SFD_EML_CALL(60U, *chartInstance->c1_sfEvent, 3);
  c1_a = c1_msb;
  c1_b_a = c1_a;
  c1_c = (int16_T)(c1_b_a << 8);
  c1_varargin_1 = c1_c;
  c1_varargin_2 = c1_lsb;
  c1_c_a = c1_varargin_1;
  c1_b = c1_varargin_2;
  c1_val = (int16_T)(c1_c_a | c1_b);
  _SFD_DATA_RANGE_CHECK((real_T)c1_val, 29U, 4U, 60U, *chartInstance->c1_sfEvent,
                        false);
  _SFD_EML_CALL(60U, *chartInstance->c1_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_UNSET_DATA_VALUE_PTR(29U);
  _SFD_UNSET_DATA_VALUE_PTR(28U);
  _SFD_UNSET_DATA_VALUE_PTR(27U);
  return c1_val;
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_mpu6050_workingInstanceStruct *chartInstance;
  chartInstance = (SFc1_mpu6050_workingInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static int32_T c1_f_emlrt_marshallIn(SFc1_mpu6050_workingInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i3;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i3, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i3;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_mpu6050_workingInstanceStruct *chartInstance;
  chartInstance = (SFc1_mpu6050_workingInstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  boolean_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_mpu6050_workingInstanceStruct *chartInstance;
  chartInstance = (SFc1_mpu6050_workingInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_u = *(boolean_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static boolean_T c1_g_emlrt_marshallIn(SFc1_mpu6050_workingInstanceStruct
  *chartInstance, const mxArray *c1_b_enb, const char_T *c1_identifier)
{
  boolean_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_enb), &c1_thisId);
  sf_mex_destroy(&c1_b_enb);
  return c1_y;
}

static boolean_T c1_h_emlrt_marshallIn(SFc1_mpu6050_workingInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  boolean_T c1_y;
  boolean_T c1_b0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_b0, 1, 11, 0U, 0, 0U, 0);
  c1_y = c1_b0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_enb;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  boolean_T c1_y;
  SFc1_mpu6050_workingInstanceStruct *chartInstance;
  chartInstance = (SFc1_mpu6050_workingInstanceStruct *)chartInstanceVoid;
  c1_b_enb = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_enb), &c1_thisId);
  sf_mex_destroy(&c1_b_enb);
  *(boolean_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  uint32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_mpu6050_workingInstanceStruct *chartInstance;
  chartInstance = (SFc1_mpu6050_workingInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_u = *(uint32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static uint32_T c1_i_emlrt_marshallIn(SFc1_mpu6050_workingInstanceStruct
  *chartInstance, const mxArray *c1_b_cnt, const char_T *c1_identifier)
{
  uint32_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_cnt), &c1_thisId);
  sf_mex_destroy(&c1_b_cnt);
  return c1_y;
}

static uint32_T c1_j_emlrt_marshallIn(SFc1_mpu6050_workingInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint32_T c1_y;
  uint32_T c1_u1;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u1, 1, 7, 0U, 0, 0U, 0);
  c1_y = c1_u1;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_cnt;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  uint32_T c1_y;
  SFc1_mpu6050_workingInstanceStruct *chartInstance;
  chartInstance = (SFc1_mpu6050_workingInstanceStruct *)chartInstanceVoid;
  c1_b_cnt = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_cnt), &c1_thisId);
  sf_mex_destroy(&c1_b_cnt);
  *(uint32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_k_emlrt_marshallIn(SFc1_mpu6050_workingInstanceStruct
  *chartInstance, const mxArray *c1_b_setSimStateSideEffectsInfo, const char_T
  *c1_identifier)
{
  const mxArray *c1_y = NULL;
  emlrtMsgIdentifier c1_thisId;
  c1_y = NULL;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  sf_mex_assign(&c1_y, c1_l_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_setSimStateSideEffectsInfo), &c1_thisId), false);
  sf_mex_destroy(&c1_b_setSimStateSideEffectsInfo);
  return c1_y;
}

static const mxArray *c1_l_emlrt_marshallIn(SFc1_mpu6050_workingInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  const mxArray *c1_y = NULL;
  (void)chartInstance;
  (void)c1_parentId;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_duplicatearraysafe(&c1_u), false);
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static const mxArray *sf_get_hover_data_for_msg
  (SFc1_mpu6050_workingInstanceStruct *chartInstance, int32_T c1_ssid)
{
  const mxArray *c1_msgInfo;
  (void)chartInstance;
  (void)c1_ssid;
  c1_msgInfo = NULL;
  return NULL;
}

static void c1_init_sf_message_store_memory(SFc1_mpu6050_workingInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_dsm_address_info(SFc1_mpu6050_workingInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc1_mpu6050_workingInstanceStruct
  *chartInstance)
{
  chartInstance->c1_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c1_sfEvent = (int32_T *)ssGetDWork_wrapper(chartInstance->S, 0);
  chartInstance->c1_doneDoubleBufferReInit = (boolean_T *)ssGetDWork_wrapper
    (chartInstance->S, 1);
  chartInstance->c1_is_active_c1_mpu6050_working = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 2);
  chartInstance->c1_is_c1_mpu6050_working = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 3);
  chartInstance->c1_enb = (boolean_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c1_rw = (boolean_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c1_mode = (boolean_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c1_slv_addr = (uint8_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c1_reg_addr = (uint8_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c1_reg_byte_mode = (boolean_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c1_data_out = (uint8_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 7);
  chartInstance->c1_busy = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c1_n_ack = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c1_byte_mode = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c1_reg_mode = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c1_cnt = (uint32_T *)ssGetDWork_wrapper(chartInstance->S, 4);
  chartInstance->c1_data_in = (uint8_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c1_mstr_ack = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c1_AccelX = (int16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 8);
  chartInstance->c1_AccelY = (int16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 9);
  chartInstance->c1_AccelZ = (int16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 10);
  chartInstance->c1_Valid_Out = (boolean_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 11);
  chartInstance->c1_tempVal = (uint8_T *)ssGetDWork_wrapper(chartInstance->S, 5);
  chartInstance->c1_deviceId = (uint8_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 12);
  chartInstance->c1_regdata = (uint8_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 13);
  chartInstance->c1_userRegAddr = (uint8_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c1_configDevice = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 7);
  chartInstance->c1_GyroX = (int16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 14);
  chartInstance->c1_GyroY = (int16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 15);
  chartInstance->c1_GyroZ = (int16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 16);
  chartInstance->c1_isDeviceSetup = (boolean_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 17);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

static uint32_T* sf_get_sfun_dwork_checksum(void);
void sf_c1_mpu6050_working_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2768908990U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1740376699U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3087875051U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2116105072U);
}

mxArray* sf_c1_mpu6050_working_get_post_codegen_info(void);
mxArray *sf_c1_mpu6050_working_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("dAdxTL31PQVQ8SczbKMuRD");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,8,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,7,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,17,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(6));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(6));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(6));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,10,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,10,"type",mxType);
    }

    mxSetField(mxData,10,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,11,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,11,"type",mxType);
    }

    mxSetField(mxData,11,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,12,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,12,"type",mxType);
    }

    mxSetField(mxData,12,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,13,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(6));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,13,"type",mxType);
    }

    mxSetField(mxData,13,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,14,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(6));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,14,"type",mxType);
    }

    mxSetField(mxData,14,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,15,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(6));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,15,"type",mxType);
    }

    mxSetField(mxData,15,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,16,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,16,"type",mxType);
    }

    mxSetField(mxData,16,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c1_mpu6050_working_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_mpu6050_working_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c1_mpu6050_working_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("early");
  mxArray *fallbackReason = mxCreateString("ext_mode");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c1_mpu6050_working_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c1_mpu6050_working_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c1_mpu6050_working(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[2123],T\"AccelX\",},{M[1],M[2124],T\"AccelY\",},{M[1],M[2125],T\"AccelZ\",},{M[1],M[2326],T\"GyroX\",},{M[1],M[2327],T\"GyroY\",},{M[1],M[2328],T\"GyroZ\",},{M[1],M[2149],T\"Valid_Out\",},{M[1],M[2156],T\"data_out\",},{M[1],M[2208],T\"deviceId\",},{M[1],M[157],T\"enb\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[2269],T\"isDeviceSetup\",},{M[1],M[99],T\"mode\",},{M[1],M[1094],T\"reg_addr\",},{M[1],M[777],T\"reg_byte_mode\",},{M[1],M[2245],T\"regdata\",},{M[1],M[371],T\"rw\",},{M[1],M[158],T\"slv_addr\",},{M[3],M[1089],T\"cnt\",},{M[3],M[2207],T\"tempVal\",},{M[8],M[0],T\"is_active_c1_mpu6050_working\",}}",
    "100 S'type','srcId','name','auxInfo'{{M[9],M[0],T\"is_c1_mpu6050_working\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 21, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_mpu6050_working_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const mxArray* sf_opaque_get_hover_data_for_msg(void* chartInstance,
  int32_T msgSSID)
{
  return sf_get_hover_data_for_msg( (SFc1_mpu6050_workingInstanceStruct *)
    chartInstance, msgSSID);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_mpu6050_workingInstanceStruct *chartInstance =
      (SFc1_mpu6050_workingInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _mpu6050_workingMachineNumber_,
           1,
           63,
           84,
           0,
           37,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_mpu6050_workingMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_mpu6050_workingMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _mpu6050_workingMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,0,0,0,"cnt");
          _SFD_SET_DATA_PROPS(1,0,0,0,"tempVal");
          _SFD_SET_DATA_PROPS(2,1,1,0,"busy");
          _SFD_SET_DATA_PROPS(3,1,1,0,"n_ack");
          _SFD_SET_DATA_PROPS(4,1,1,0,"byte_mode");
          _SFD_SET_DATA_PROPS(5,1,1,0,"reg_mode");
          _SFD_SET_DATA_PROPS(6,1,1,0,"data_in");
          _SFD_SET_DATA_PROPS(7,1,1,0,"mstr_ack");
          _SFD_SET_DATA_PROPS(8,1,1,0,"userRegAddr");
          _SFD_SET_DATA_PROPS(9,1,1,0,"configDevice");
          _SFD_SET_DATA_PROPS(10,2,0,1,"enb");
          _SFD_SET_DATA_PROPS(11,2,0,1,"rw");
          _SFD_SET_DATA_PROPS(12,2,0,1,"mode");
          _SFD_SET_DATA_PROPS(13,2,0,1,"slv_addr");
          _SFD_SET_DATA_PROPS(14,2,0,1,"reg_addr");
          _SFD_SET_DATA_PROPS(15,2,0,1,"reg_byte_mode");
          _SFD_SET_DATA_PROPS(16,2,0,1,"data_out");
          _SFD_SET_DATA_PROPS(17,2,0,1,"AccelX");
          _SFD_SET_DATA_PROPS(18,2,0,1,"AccelY");
          _SFD_SET_DATA_PROPS(19,2,0,1,"AccelZ");
          _SFD_SET_DATA_PROPS(20,2,0,1,"Valid_Out");
          _SFD_SET_DATA_PROPS(21,2,0,1,"deviceId");
          _SFD_SET_DATA_PROPS(22,2,0,1,"regdata");
          _SFD_SET_DATA_PROPS(23,2,0,1,"GyroX");
          _SFD_SET_DATA_PROPS(24,2,0,1,"GyroY");
          _SFD_SET_DATA_PROPS(25,2,0,1,"GyroZ");
          _SFD_SET_DATA_PROPS(26,2,0,1,"isDeviceSetup");
          _SFD_SET_DATA_PROPS(27,8,0,0,"");
          _SFD_SET_DATA_PROPS(28,8,0,0,"");
          _SFD_SET_DATA_PROPS(29,9,0,0,"");
          _SFD_SET_DATA_PROPS(30,10,0,0,"AccelXRegAddr");
          _SFD_SET_DATA_PROPS(31,10,0,0,"AccelYRegAddr");
          _SFD_SET_DATA_PROPS(32,10,0,0,"AccelZRegAddr");
          _SFD_SET_DATA_PROPS(33,10,0,0,"GyroXRegAddr");
          _SFD_SET_DATA_PROPS(34,10,0,0,"SlvAddr");
          _SFD_SET_DATA_PROPS(35,10,0,0,"powerRegAddr");
          _SFD_SET_DATA_PROPS(36,10,0,0,"powerRegData");
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(6,0,0);
          _SFD_STATE_INFO(7,0,0);
          _SFD_STATE_INFO(8,0,0);
          _SFD_STATE_INFO(9,0,0);
          _SFD_STATE_INFO(10,0,0);
          _SFD_STATE_INFO(11,0,0);
          _SFD_STATE_INFO(13,0,0);
          _SFD_STATE_INFO(14,0,0);
          _SFD_STATE_INFO(15,0,0);
          _SFD_STATE_INFO(16,0,0);
          _SFD_STATE_INFO(17,0,0);
          _SFD_STATE_INFO(18,0,0);
          _SFD_STATE_INFO(19,0,0);
          _SFD_STATE_INFO(20,0,0);
          _SFD_STATE_INFO(21,0,0);
          _SFD_STATE_INFO(22,0,0);
          _SFD_STATE_INFO(23,0,0);
          _SFD_STATE_INFO(24,0,0);
          _SFD_STATE_INFO(25,0,0);
          _SFD_STATE_INFO(26,0,0);
          _SFD_STATE_INFO(27,0,0);
          _SFD_STATE_INFO(28,0,0);
          _SFD_STATE_INFO(29,0,0);
          _SFD_STATE_INFO(30,0,0);
          _SFD_STATE_INFO(32,0,0);
          _SFD_STATE_INFO(33,0,0);
          _SFD_STATE_INFO(34,0,0);
          _SFD_STATE_INFO(35,0,0);
          _SFD_STATE_INFO(36,0,0);
          _SFD_STATE_INFO(37,0,0);
          _SFD_STATE_INFO(38,0,0);
          _SFD_STATE_INFO(40,0,0);
          _SFD_STATE_INFO(41,0,0);
          _SFD_STATE_INFO(42,0,0);
          _SFD_STATE_INFO(43,0,0);
          _SFD_STATE_INFO(44,0,0);
          _SFD_STATE_INFO(45,0,0);
          _SFD_STATE_INFO(46,0,0);
          _SFD_STATE_INFO(47,0,0);
          _SFD_STATE_INFO(48,0,0);
          _SFD_STATE_INFO(49,0,0);
          _SFD_STATE_INFO(50,0,0);
          _SFD_STATE_INFO(51,0,0);
          _SFD_STATE_INFO(52,0,0);
          _SFD_STATE_INFO(53,0,0);
          _SFD_STATE_INFO(54,0,0);
          _SFD_STATE_INFO(55,0,0);
          _SFD_STATE_INFO(56,0,0);
          _SFD_STATE_INFO(57,0,0);
          _SFD_STATE_INFO(58,0,0);
          _SFD_STATE_INFO(59,0,0);
          _SFD_STATE_INFO(61,0,0);
          _SFD_STATE_INFO(62,0,0);
          _SFD_STATE_INFO(60,0,2);
          _SFD_CH_SUBSTATE_COUNT(58);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,1);
          _SFD_CH_SUBSTATE_INDEX(1,2);
          _SFD_CH_SUBSTATE_INDEX(2,3);
          _SFD_CH_SUBSTATE_INDEX(3,4);
          _SFD_CH_SUBSTATE_INDEX(4,5);
          _SFD_CH_SUBSTATE_INDEX(5,6);
          _SFD_CH_SUBSTATE_INDEX(6,7);
          _SFD_CH_SUBSTATE_INDEX(7,8);
          _SFD_CH_SUBSTATE_INDEX(8,9);
          _SFD_CH_SUBSTATE_INDEX(9,10);
          _SFD_CH_SUBSTATE_INDEX(10,11);
          _SFD_CH_SUBSTATE_INDEX(11,13);
          _SFD_CH_SUBSTATE_INDEX(12,14);
          _SFD_CH_SUBSTATE_INDEX(13,15);
          _SFD_CH_SUBSTATE_INDEX(14,16);
          _SFD_CH_SUBSTATE_INDEX(15,17);
          _SFD_CH_SUBSTATE_INDEX(16,18);
          _SFD_CH_SUBSTATE_INDEX(17,19);
          _SFD_CH_SUBSTATE_INDEX(18,20);
          _SFD_CH_SUBSTATE_INDEX(19,21);
          _SFD_CH_SUBSTATE_INDEX(20,22);
          _SFD_CH_SUBSTATE_INDEX(21,23);
          _SFD_CH_SUBSTATE_INDEX(22,24);
          _SFD_CH_SUBSTATE_INDEX(23,25);
          _SFD_CH_SUBSTATE_INDEX(24,26);
          _SFD_CH_SUBSTATE_INDEX(25,27);
          _SFD_CH_SUBSTATE_INDEX(26,28);
          _SFD_CH_SUBSTATE_INDEX(27,29);
          _SFD_CH_SUBSTATE_INDEX(28,30);
          _SFD_CH_SUBSTATE_INDEX(29,32);
          _SFD_CH_SUBSTATE_INDEX(30,33);
          _SFD_CH_SUBSTATE_INDEX(31,34);
          _SFD_CH_SUBSTATE_INDEX(32,35);
          _SFD_CH_SUBSTATE_INDEX(33,36);
          _SFD_CH_SUBSTATE_INDEX(34,37);
          _SFD_CH_SUBSTATE_INDEX(35,38);
          _SFD_CH_SUBSTATE_INDEX(36,40);
          _SFD_CH_SUBSTATE_INDEX(37,41);
          _SFD_CH_SUBSTATE_INDEX(38,42);
          _SFD_CH_SUBSTATE_INDEX(39,43);
          _SFD_CH_SUBSTATE_INDEX(40,44);
          _SFD_CH_SUBSTATE_INDEX(41,45);
          _SFD_CH_SUBSTATE_INDEX(42,46);
          _SFD_CH_SUBSTATE_INDEX(43,47);
          _SFD_CH_SUBSTATE_INDEX(44,48);
          _SFD_CH_SUBSTATE_INDEX(45,49);
          _SFD_CH_SUBSTATE_INDEX(46,50);
          _SFD_CH_SUBSTATE_INDEX(47,51);
          _SFD_CH_SUBSTATE_INDEX(48,52);
          _SFD_CH_SUBSTATE_INDEX(49,53);
          _SFD_CH_SUBSTATE_INDEX(50,54);
          _SFD_CH_SUBSTATE_INDEX(51,55);
          _SFD_CH_SUBSTATE_INDEX(52,56);
          _SFD_CH_SUBSTATE_INDEX(53,57);
          _SFD_CH_SUBSTATE_INDEX(54,58);
          _SFD_CH_SUBSTATE_INDEX(55,59);
          _SFD_CH_SUBSTATE_INDEX(56,61);
          _SFD_CH_SUBSTATE_INDEX(57,62);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(5,0);
          _SFD_ST_SUBSTATE_COUNT(6,0);
          _SFD_ST_SUBSTATE_COUNT(7,0);
          _SFD_ST_SUBSTATE_COUNT(8,0);
          _SFD_ST_SUBSTATE_COUNT(9,0);
          _SFD_ST_SUBSTATE_COUNT(10,0);
          _SFD_ST_SUBSTATE_COUNT(11,0);
          _SFD_ST_SUBSTATE_COUNT(13,0);
          _SFD_ST_SUBSTATE_COUNT(14,0);
          _SFD_ST_SUBSTATE_COUNT(15,0);
          _SFD_ST_SUBSTATE_COUNT(16,0);
          _SFD_ST_SUBSTATE_COUNT(17,0);
          _SFD_ST_SUBSTATE_COUNT(18,0);
          _SFD_ST_SUBSTATE_COUNT(19,0);
          _SFD_ST_SUBSTATE_COUNT(20,0);
          _SFD_ST_SUBSTATE_COUNT(21,0);
          _SFD_ST_SUBSTATE_COUNT(22,0);
          _SFD_ST_SUBSTATE_COUNT(23,0);
          _SFD_ST_SUBSTATE_COUNT(24,0);
          _SFD_ST_SUBSTATE_COUNT(25,0);
          _SFD_ST_SUBSTATE_COUNT(26,0);
          _SFD_ST_SUBSTATE_COUNT(27,0);
          _SFD_ST_SUBSTATE_COUNT(28,0);
          _SFD_ST_SUBSTATE_COUNT(29,0);
          _SFD_ST_SUBSTATE_COUNT(30,0);
          _SFD_ST_SUBSTATE_COUNT(32,0);
          _SFD_ST_SUBSTATE_COUNT(33,0);
          _SFD_ST_SUBSTATE_COUNT(34,0);
          _SFD_ST_SUBSTATE_COUNT(35,0);
          _SFD_ST_SUBSTATE_COUNT(36,0);
          _SFD_ST_SUBSTATE_COUNT(37,0);
          _SFD_ST_SUBSTATE_COUNT(38,0);
          _SFD_ST_SUBSTATE_COUNT(40,0);
          _SFD_ST_SUBSTATE_COUNT(41,0);
          _SFD_ST_SUBSTATE_COUNT(42,0);
          _SFD_ST_SUBSTATE_COUNT(43,0);
          _SFD_ST_SUBSTATE_COUNT(44,0);
          _SFD_ST_SUBSTATE_COUNT(45,0);
          _SFD_ST_SUBSTATE_COUNT(46,0);
          _SFD_ST_SUBSTATE_COUNT(47,0);
          _SFD_ST_SUBSTATE_COUNT(48,0);
          _SFD_ST_SUBSTATE_COUNT(49,0);
          _SFD_ST_SUBSTATE_COUNT(50,0);
          _SFD_ST_SUBSTATE_COUNT(51,0);
          _SFD_ST_SUBSTATE_COUNT(52,0);
          _SFD_ST_SUBSTATE_COUNT(53,0);
          _SFD_ST_SUBSTATE_COUNT(54,0);
          _SFD_ST_SUBSTATE_COUNT(55,0);
          _SFD_ST_SUBSTATE_COUNT(56,0);
          _SFD_ST_SUBSTATE_COUNT(57,0);
          _SFD_ST_SUBSTATE_COUNT(58,0);
          _SFD_ST_SUBSTATE_COUNT(59,0);
          _SFD_ST_SUBSTATE_COUNT(61,0);
          _SFD_ST_SUBSTATE_COUNT(62,0);
        }

        _SFD_CV_INIT_CHART(58,1,0,0);

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(3,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(4,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(5,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(6,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(7,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(8,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(9,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(10,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(11,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(13,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(14,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(15,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(16,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(17,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(18,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(19,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(20,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(21,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(22,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(23,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(24,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(25,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(26,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(27,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(28,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(29,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(30,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(32,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(33,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(34,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(35,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(36,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(37,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(38,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(40,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(41,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(42,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(43,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(44,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(45,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(46,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(47,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(48,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(49,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(50,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(51,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(52,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(53,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(54,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(55,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(56,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(57,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(58,0,0,0,0,0,NULL,NULL);
        }

        {
          static unsigned int sStartSaturateMap[] = { 69 };

          static unsigned int sEndSaturateMap[] = { 70 };

          _SFD_CV_INIT_STATE_SATURATION(58,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          _SFD_CV_INIT_STATE(59,0,0,0,0,0,NULL,NULL);
        }

        {
          static unsigned int sStartSaturateMap[] = { 46 };

          static unsigned int sEndSaturateMap[] = { 47 };

          _SFD_CV_INIT_STATE_SATURATION(59,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          _SFD_CV_INIT_STATE(61,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(62,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(60,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(3,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 8 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 5, 5, 5, 5 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(3,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(12,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 8 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(12,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 37 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(1,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 37 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 1, 1, 1, 1 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(1,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(18,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(78,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 8 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(78,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(75,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(14,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 9 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(2,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 9 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 5, 5, 5, 5 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(2,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(77,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(80,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(79,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(76,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 8 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(76,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(20,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 8 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(20,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 9 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(22,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 9 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(22,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 12 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(23,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 12 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(23,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(21,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 8 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(21,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(24,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 8 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(24,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 9 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(27,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 9 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(27,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 12 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(25,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 12 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(25,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(82,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 8 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(82,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(81,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 8 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(81,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(26,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 8 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(26,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 9 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(83,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 9 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(83,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 9 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(17,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 9 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(17,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(15,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 8 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(15,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(16,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 8 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(16,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(6,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 8 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(6,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 9 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(7,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 9 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(7,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 12 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(5,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 12 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(5,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(10,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 8 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(10,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(19,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(8,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 8 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(8,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 12 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(9,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 12 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(9,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 9 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(11,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 9 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(11,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(51,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 8 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(51,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 9 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(46,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 9 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(46,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 12 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(63,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 12 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(63,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(71,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 8 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(71,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(59,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 8 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(59,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 9 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(68,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 9 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(68,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 12 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(54,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 12 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(54,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(48,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 8 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(48,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 9 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(72,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 9 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(72,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 9 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(64,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 9 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(64,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 9 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(65,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 9 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(65,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 9 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(45,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 9 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(45,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(49,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 8 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(49,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 12 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(50,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 12 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(50,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(69,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 8 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(69,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(66,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 8 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(66,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 12 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(55,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 12 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(55,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(56,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 8 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(56,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(52,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 8 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(52,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 12 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(53,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 12 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(53,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(57,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 8 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(57,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(58,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 8 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(58,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 12 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(60,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 12 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(60,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(67,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 8 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(67,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(39,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 8 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(39,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 9 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(43,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 9 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(43,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 12 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(35,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 12 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(35,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(34,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 8 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(34,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(30,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 8 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(30,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 9 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(32,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 9 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(32,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 12 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(40,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 12 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(40,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(41,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 8 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(41,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 9 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(31,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 9 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(31,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 9 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(42,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 9 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(42,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 9 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(33,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 9 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(33,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 9 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(44,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 9 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(44,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(28,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 8 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(28,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 12 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(29,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 12 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(29,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(36,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 8 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(36,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(37,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 8 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(37,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 12 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(38,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 12 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(38,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(70,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 8 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(70,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(61,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 8 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(61,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 12 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(62,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 12 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(62,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(73,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 8 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(73,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(74,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 8 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(74,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 12 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(47,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 12 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(47,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(60,1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(60,0,"convert_int16",0,-1,98);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_f_sf_marshallOut,(MexInFcnForType)c1_f_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_e_sf_marshallOut,(MexInFcnForType)c1_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_e_sf_marshallOut,(MexInFcnForType)c1_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_e_sf_marshallOut,(MexInFcnForType)c1_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_e_sf_marshallOut,(MexInFcnForType)c1_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_INT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_INT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_INT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(20,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_e_sf_marshallOut,(MexInFcnForType)c1_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(21,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(22,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(23,SF_INT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(24,SF_INT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(25,SF_INT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(26,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_e_sf_marshallOut,(MexInFcnForType)c1_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(27,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(28,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(29,SF_INT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(30,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(31,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(32,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(33,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(34,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(35,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(36,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(27,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(28,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(29,(void *)(NULL));
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _mpu6050_workingMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_mpu6050_workingInstanceStruct *chartInstance =
      (SFc1_mpu6050_workingInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(10U, (void *)chartInstance->c1_enb);
        _SFD_SET_DATA_VALUE_PTR(11U, (void *)chartInstance->c1_rw);
        _SFD_SET_DATA_VALUE_PTR(12U, (void *)chartInstance->c1_mode);
        _SFD_SET_DATA_VALUE_PTR(13U, (void *)chartInstance->c1_slv_addr);
        _SFD_SET_DATA_VALUE_PTR(14U, (void *)chartInstance->c1_reg_addr);
        _SFD_SET_DATA_VALUE_PTR(15U, (void *)chartInstance->c1_reg_byte_mode);
        _SFD_SET_DATA_VALUE_PTR(16U, (void *)chartInstance->c1_data_out);
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)chartInstance->c1_busy);
        _SFD_SET_DATA_VALUE_PTR(3U, (void *)chartInstance->c1_n_ack);
        _SFD_SET_DATA_VALUE_PTR(4U, (void *)chartInstance->c1_byte_mode);
        _SFD_SET_DATA_VALUE_PTR(5U, (void *)chartInstance->c1_reg_mode);
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)chartInstance->c1_cnt);
        _SFD_SET_DATA_VALUE_PTR(6U, (void *)chartInstance->c1_data_in);
        _SFD_SET_DATA_VALUE_PTR(7U, (void *)chartInstance->c1_mstr_ack);
        _SFD_SET_DATA_VALUE_PTR(17U, (void *)chartInstance->c1_AccelX);
        _SFD_SET_DATA_VALUE_PTR(18U, (void *)chartInstance->c1_AccelY);
        _SFD_SET_DATA_VALUE_PTR(19U, (void *)chartInstance->c1_AccelZ);
        _SFD_SET_DATA_VALUE_PTR(34U, (void *)&chartInstance->c1_SlvAddr);
        _SFD_SET_DATA_VALUE_PTR(30U, (void *)&chartInstance->c1_AccelXRegAddr);
        _SFD_SET_DATA_VALUE_PTR(31U, (void *)&chartInstance->c1_AccelYRegAddr);
        _SFD_SET_DATA_VALUE_PTR(32U, (void *)&chartInstance->c1_AccelZRegAddr);
        _SFD_SET_DATA_VALUE_PTR(20U, (void *)chartInstance->c1_Valid_Out);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)chartInstance->c1_tempVal);
        _SFD_SET_DATA_VALUE_PTR(21U, (void *)chartInstance->c1_deviceId);
        _SFD_SET_DATA_VALUE_PTR(36U, (void *)&chartInstance->c1_powerRegData);
        _SFD_SET_DATA_VALUE_PTR(22U, (void *)chartInstance->c1_regdata);
        _SFD_SET_DATA_VALUE_PTR(8U, (void *)chartInstance->c1_userRegAddr);
        _SFD_SET_DATA_VALUE_PTR(35U, (void *)&chartInstance->c1_powerRegAddr);
        _SFD_SET_DATA_VALUE_PTR(9U, (void *)chartInstance->c1_configDevice);
        _SFD_SET_DATA_VALUE_PTR(33U, (void *)&chartInstance->c1_GyroXRegAddr);
        _SFD_SET_DATA_VALUE_PTR(23U, (void *)chartInstance->c1_GyroX);
        _SFD_SET_DATA_VALUE_PTR(24U, (void *)chartInstance->c1_GyroY);
        _SFD_SET_DATA_VALUE_PTR(25U, (void *)chartInstance->c1_GyroZ);
        _SFD_SET_DATA_VALUE_PTR(26U, (void *)chartInstance->c1_isDeviceSetup);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sL7Kzb2O2xbfDBFrf91LzmG";
}

static void sf_check_dwork_consistency(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    const uint32_T *sfunDWorkChecksum = sf_get_sfun_dwork_checksum();
    mxArray *infoStruct = load_mpu6050_working_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    mxArray* mxRTWDWorkChecksum = sf_get_dwork_info_from_mat_file(S,
      sf_get_instance_specialization(), infoStruct, 1, "dworkChecksum");
    if (mxRTWDWorkChecksum != NULL) {
      double *pr = mxGetPr(mxRTWDWorkChecksum);
      if ((uint32_T)pr[0] != sfunDWorkChecksum[0] ||
          (uint32_T)pr[1] != sfunDWorkChecksum[1] ||
          (uint32_T)pr[2] != sfunDWorkChecksum[2] ||
          (uint32_T)pr[3] != sfunDWorkChecksum[3]) {
        sf_mex_error_message("Code generation and simulation targets registered different sets of persistent variables for the block. "
                             "External or Rapid Accelerator mode simulation requires code generation and simulation targets to "
                             "register the same set of persistent variables for this block. "
                             "This discrepancy is typically caused by MATLAB functions that have different code paths for "
                             "simulation and code generation targets where these code paths define different sets of persistent variables. "
                             "Please identify these code paths in the offending block and rewrite the MATLAB code so that "
                             "the set of persistent variables is the same between simulation and code generation.");
      }
    }
  }
}

static void sf_opaque_initialize_c1_mpu6050_working(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc1_mpu6050_workingInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc1_mpu6050_workingInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_mpu6050_working((SFc1_mpu6050_workingInstanceStruct*)
    chartInstanceVar);
  initialize_c1_mpu6050_working((SFc1_mpu6050_workingInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_mpu6050_working(void *chartInstanceVar)
{
  enable_c1_mpu6050_working((SFc1_mpu6050_workingInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_mpu6050_working(void *chartInstanceVar)
{
  disable_c1_mpu6050_working((SFc1_mpu6050_workingInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_mpu6050_working(void *chartInstanceVar)
{
  sf_gateway_c1_mpu6050_working((SFc1_mpu6050_workingInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c1_mpu6050_working(void *chartInstanceVar)
{
  ext_mode_exec_c1_mpu6050_working((SFc1_mpu6050_workingInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c1_mpu6050_working(SimStruct* S)
{
  return get_sim_state_c1_mpu6050_working((SFc1_mpu6050_workingInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c1_mpu6050_working(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c1_mpu6050_working((SFc1_mpu6050_workingInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c1_mpu6050_working(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_mpu6050_workingInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_mpu6050_working_optimization_info();
    }

    finalize_c1_mpu6050_working((SFc1_mpu6050_workingInstanceStruct*)
      chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_mpu6050_working((SFc1_mpu6050_workingInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_mpu6050_working(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_mpu6050_working((SFc1_mpu6050_workingInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

mxArray *sf_c1_mpu6050_working_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S1x2'varName','path'{{T\"is_active_c1_mpu6050_working\",T\"is_active_c1_mpu6050_working\"},{T\"is_c1_mpu6050_working\",T\"is_c1_mpu6050_working\"}}"
  };

  mxArray *mxTpInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  return mxTpInfo;
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  const char *dworkEncStr[] = {
    "100 S1x6'type','isSigned','wordLength','bias','slope','exponent','isScaledDouble','isComplex','size','local_queue_dwork_idx','local_queue_id'{{T\"int32\",,,,,,,M[0],M[],M[-1],M[-1]},{T\"boolean\",,,,,,,M[0],M[],M[-1],M[-1]},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1]},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1]},{T\"uint32\",,,,,,,M[0],M[],M[-1],M[-1]},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 6, 10);
}

static uint32_T* sf_get_sfun_dwork_checksum()
{
  static uint32_T checksum[4] = { 2598896996U, 4117322300U, 2603995857U,
    1649122424U };

  return checksum;
}

static void mdlSetWorkWidths_c1_mpu6050_working(SimStruct *S)
{
  /* Actual parameters from chart:
     AccelXRegAddr AccelYRegAddr AccelZRegAddr GyroXRegAddr SlvAddr powerRegAddr powerRegData
   */
  const char_T *rtParamNames[] = { "AccelXRegAddr", "AccelYRegAddr",
    "AccelZRegAddr", "GyroXRegAddr", "SlvAddr", "powerRegAddr", "powerRegData" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for AccelXRegAddr*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_UINT8);

  /* registration for AccelYRegAddr*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_UINT8);

  /* registration for AccelZRegAddr*/
  ssRegDlgParamAsRunTimeParam(S, 2, 2, rtParamNames[2], SS_UINT8);

  /* registration for GyroXRegAddr*/
  ssRegDlgParamAsRunTimeParam(S, 3, 3, rtParamNames[3], SS_UINT8);

  /* registration for SlvAddr*/
  ssRegDlgParamAsRunTimeParam(S, 4, 4, rtParamNames[4], SS_UINT8);

  /* registration for powerRegAddr*/
  ssRegDlgParamAsRunTimeParam(S, 5, 5, rtParamNames[5], SS_UINT8);

  /* registration for powerRegData*/
  ssRegDlgParamAsRunTimeParam(S, 6, 6, rtParamNames[6], SS_UINT8);
  ssSetStatesModifiedOnlyInUpdate(S, 0);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_mpu6050_working_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,1,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 1);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,8);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,17);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=17; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 8; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetCallsOutputInInitFcn(S,1);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1230251123U));
  ssSetChecksum1(S,(361244473U));
  ssSetChecksum2(S,(3037847760U));
  ssSetChecksum3(S,(1179797624U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_mpu6050_working(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c1_mpu6050_working(SimStruct *S)
{
  SFc1_mpu6050_workingInstanceStruct *chartInstance;
  chartInstance = (SFc1_mpu6050_workingInstanceStruct *)utMalloc(sizeof
    (SFc1_mpu6050_workingInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc1_mpu6050_workingInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_mpu6050_working;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_mpu6050_working;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_mpu6050_working;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_mpu6050_working;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_mpu6050_working;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_mpu6050_working;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_mpu6050_working;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_mpu6050_working;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_mpu6050_working;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_mpu6050_working;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_mpu6050_working;
  chartInstance->chartInfo.callGetHoverDataForMsg =
    sf_opaque_get_hover_data_for_msg;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c1_mpu6050_working;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
  mdl_start_c1_mpu6050_working(chartInstance);
}

void c1_mpu6050_working_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_mpu6050_working(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_mpu6050_working(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_mpu6050_working(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_mpu6050_working_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
