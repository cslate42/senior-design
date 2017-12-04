/* Include files */

#include "mpu6050_working_sfun.h"
#include "c4_mpu6050_working.h"
#include "mwmathutil.h"
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
#define c4_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c4_IN_NACK                     ((uint8_T)1U)
#define c4_IN_endgetaddr               ((uint8_T)2U)
#define c4_IN_endgetdata               ((uint8_T)3U)
#define c4_IN_getaddr                  ((uint8_T)4U)
#define c4_IN_getcfgdata               ((uint8_T)5U)
#define c4_IN_getcfgregstart           ((uint8_T)6U)
#define c4_IN_getdata                  ((uint8_T)7U)
#define c4_IN_getdatastart             ((uint8_T)8U)
#define c4_IN_idle                     ((uint8_T)9U)
#define c4_IN_init                     ((uint8_T)10U)
#define c4_IN_lookRestart              ((uint8_T)11U)
#define c4_IN_sendAck                  ((uint8_T)12U)
#define c4_IN_sendack                  ((uint8_T)13U)
#define c4_IN_sendbit                  ((uint8_T)14U)
#define c4_IN_sendbyte                 ((uint8_T)15U)
#define c4_IN_senddatastart            ((uint8_T)16U)
#define c4_IN_start                    ((uint8_T)17U)
#define c4_IN_startgetaddr             ((uint8_T)18U)
#define c4_IN_waitEndOfAck             ((uint8_T)19U)
#define c4_IN_waitForStop              ((uint8_T)20U)
#define c4_IN_waitforPos               ((uint8_T)21U)
#define c4_IN_waitstop1                ((uint8_T)22U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const mxArray *c4_eml_mx;
static const mxArray *c4_b_eml_mx;
static const char * c4_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_c_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_d_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_e_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_f_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_g_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_h_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_i_debug_family_names[4] = { "nargin", "nargout", "reg",
  "regdata" };

static const char * c4_j_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_k_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_l_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_m_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_n_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_o_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_p_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_q_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_r_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_s_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_t_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_u_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_v_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_w_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_x_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_y_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_ab_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_bb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_cb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_db_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_eb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_fb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_gb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_hb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_ib_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_jb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_kb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_lb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_mb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_nb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_ob_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_pb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_qb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_rb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_sb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_tb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_ub_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_vb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const mxArray *c4_c_eml_mx;

/* Function Declarations */
static void initialize_c4_mpu6050_working(SFc4_mpu6050_workingInstanceStruct
  *chartInstance);
static void initialize_params_c4_mpu6050_working
  (SFc4_mpu6050_workingInstanceStruct *chartInstance);
static void enable_c4_mpu6050_working(SFc4_mpu6050_workingInstanceStruct
  *chartInstance);
static void disable_c4_mpu6050_working(SFc4_mpu6050_workingInstanceStruct
  *chartInstance);
static void c4_update_debugger_state_c4_mpu6050_working
  (SFc4_mpu6050_workingInstanceStruct *chartInstance);
static void ext_mode_exec_c4_mpu6050_working(SFc4_mpu6050_workingInstanceStruct *
  chartInstance);
static const mxArray *get_sim_state_c4_mpu6050_working
  (SFc4_mpu6050_workingInstanceStruct *chartInstance);
static void set_sim_state_c4_mpu6050_working(SFc4_mpu6050_workingInstanceStruct *
  chartInstance, const mxArray *c4_st);
static void c4_set_sim_state_side_effects_c4_mpu6050_working
  (SFc4_mpu6050_workingInstanceStruct *chartInstance);
static void finalize_c4_mpu6050_working(SFc4_mpu6050_workingInstanceStruct
  *chartInstance);
static void sf_gateway_c4_mpu6050_working(SFc4_mpu6050_workingInstanceStruct
  *chartInstance);
static void mdl_start_c4_mpu6050_working(SFc4_mpu6050_workingInstanceStruct
  *chartInstance);
static void c4_chartstep_c4_mpu6050_working(SFc4_mpu6050_workingInstanceStruct
  *chartInstance);
static void initSimStructsc4_mpu6050_working(SFc4_mpu6050_workingInstanceStruct *
  chartInstance);
static void c4_init(SFc4_mpu6050_workingInstanceStruct *chartInstance);
static void c4_idle(SFc4_mpu6050_workingInstanceStruct *chartInstance);
static void c4_start(SFc4_mpu6050_workingInstanceStruct *chartInstance);
static void c4_NACK(SFc4_mpu6050_workingInstanceStruct *chartInstance);
static void c4_getaddr(SFc4_mpu6050_workingInstanceStruct *chartInstance);
static void c4_endgetaddr(SFc4_mpu6050_workingInstanceStruct *chartInstance);
static void c4_sendack(SFc4_mpu6050_workingInstanceStruct *chartInstance);
static void c4_enter_atomic_senddatastart(SFc4_mpu6050_workingInstanceStruct
  *chartInstance);
static void c4_senddatastart(SFc4_mpu6050_workingInstanceStruct *chartInstance);
static void c4_getdatastart(SFc4_mpu6050_workingInstanceStruct *chartInstance);
static void c4_sendbyte(SFc4_mpu6050_workingInstanceStruct *chartInstance);
static void c4_getdata(SFc4_mpu6050_workingInstanceStruct *chartInstance);
static void c4_sendbit(SFc4_mpu6050_workingInstanceStruct *chartInstance);
static void c4_endgetdata(SFc4_mpu6050_workingInstanceStruct *chartInstance);
static void c4_lookRestart(SFc4_mpu6050_workingInstanceStruct *chartInstance);
static void c4_getcfgregstart(SFc4_mpu6050_workingInstanceStruct *chartInstance);
static void c4_sendAck(SFc4_mpu6050_workingInstanceStruct *chartInstance);
static void c4_enter_atomic_getcfgdata(SFc4_mpu6050_workingInstanceStruct
  *chartInstance);
static void c4_getcfgdata(SFc4_mpu6050_workingInstanceStruct *chartInstance);
static void c4_error(SFc4_mpu6050_workingInstanceStruct *chartInstance, int32_T
                     c4_varargin_1);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static real_T c4_emlrt_marshallIn(SFc4_mpu6050_workingInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static uint8_T c4_b_emlrt_marshallIn(SFc4_mpu6050_workingInstanceStruct
  *chartInstance, const mxArray *c4_reg, const char_T *c4_identifier);
static uint8_T c4_c_emlrt_marshallIn(SFc4_mpu6050_workingInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static boolean_T c4_d_emlrt_marshallIn(SFc4_mpu6050_workingInstanceStruct
  *chartInstance, const mxArray *c4_sf_internal_predicateOutput, const char_T
  *c4_identifier);
static boolean_T c4_e_emlrt_marshallIn(SFc4_mpu6050_workingInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_f_emlrt_marshallIn(SFc4_mpu6050_workingInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_e_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static uint8_T c4_g_emlrt_marshallIn(SFc4_mpu6050_workingInstanceStruct
  *chartInstance, const mxArray *c4_b_addr, const char_T *c4_identifier);
static uint8_T c4_h_emlrt_marshallIn(SFc4_mpu6050_workingInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_f_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static uint8_T c4_i_emlrt_marshallIn(SFc4_mpu6050_workingInstanceStruct
  *chartInstance, const mxArray *c4_b_data, const char_T *c4_identifier);
static uint8_T c4_j_emlrt_marshallIn(SFc4_mpu6050_workingInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static void c4_k_emlrt_marshallIn(SFc4_mpu6050_workingInstanceStruct
  *chartInstance, const mxArray *c4_b_dataWrittenToVector, const char_T
  *c4_identifier, boolean_T c4_y[8]);
static void c4_l_emlrt_marshallIn(SFc4_mpu6050_workingInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  boolean_T c4_y[8]);
static const mxArray *c4_m_emlrt_marshallIn(SFc4_mpu6050_workingInstanceStruct
  *chartInstance, const mxArray *c4_b_setSimStateSideEffectsInfo, const char_T
  *c4_identifier);
static const mxArray *c4_n_emlrt_marshallIn(SFc4_mpu6050_workingInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static const mxArray *sf_get_hover_data_for_msg
  (SFc4_mpu6050_workingInstanceStruct *chartInstance, int32_T c4_ssid);
static void c4_init_sf_message_store_memory(SFc4_mpu6050_workingInstanceStruct
  *chartInstance);
static void init_dsm_address_info(SFc4_mpu6050_workingInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc4_mpu6050_workingInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c4_mpu6050_working(SFc4_mpu6050_workingInstanceStruct
  *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc4_mpu6050_working(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  *chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c4_doSetSimStateSideEffects = 0U;
  chartInstance->c4_setSimStateSideEffectsInfo = NULL;
  *chartInstance->c4_is_active_c4_mpu6050_working = 0U;
  *chartInstance->c4_is_c4_mpu6050_working = c4_IN_NO_ACTIVE_CHILD;
  sf_mex_assign(&c4_c_eml_mx, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "numerictype", 1U, 14U, 15, "SignednessBool", 3, false, 15, "Signedness", 15,
    "Unsigned", 15, "WordLength", 6, 7.0, 15, "FractionLength", 6, 0.0, 15,
    "BinaryPoint", 6, 0.0, 15, "Slope", 6, 1.0, 15, "FixedExponent", 6, 0.0),
                true);
  sf_mex_assign(&c4_b_eml_mx, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "numerictype", 1U, 14U, 15, "SignednessBool", 3, false, 15, "Signedness", 15,
    "Unsigned", 15, "WordLength", 6, 8.0, 15, "FractionLength", 6, 0.0, 15,
    "BinaryPoint", 6, 0.0, 15, "Slope", 6, 1.0, 15, "FixedExponent", 6, 0.0),
                true);
  sf_mex_assign(&c4_eml_mx, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "fimath", 1U, 42U, 15, "RoundMode", 15, "nearest", 15, "RoundingMethod", 15,
    "Nearest", 15, "OverflowMode", 15, "saturate", 15, "OverflowAction", 15,
    "Saturate", 15, "ProductMode", 15, "FullPrecision", 15, "SumMode", 15,
    "FullPrecision", 15, "ProductWordLength", 6, 32.0, 15, "SumWordLength", 6,
    32.0, 15, "MaxProductWordLength", 6, 65535.0, 15, "MaxSumWordLength", 6,
    65535.0, 15, "ProductFractionLength", 6, 30.0, 15, "ProductFixedExponent", 6,
    -30.0, 15, "SumFractionLength", 6, 30.0, 15, "SumFixedExponent", 6, -30.0,
    15, "SumSlopeAdjustmentFactor", 6, 1.0, 15, "SumBias", 6, 0.0, 15,
    "ProductSlopeAdjustmentFactor", 6, 1.0, 15, "ProductBias", 6, 0.0, 15,
    "CastBeforeSum", 3, true, 15, "SumSlope", 6, 9.3132257461547852E-10, 15,
    "ProductSlope", 6, 9.3132257461547852E-10), true);
}

static void initialize_params_c4_mpu6050_working
  (SFc4_mpu6050_workingInstanceStruct *chartInstance)
{
  real_T c4_d0;
  real_T c4_d1;
  uint8_T c4_u0;
  real_T c4_d2;
  real_T c4_d3;
  real_T c4_d4;
  real_T c4_d5;
  sf_mex_import_named("deviceAddr", sf_mex_get_sfun_param(chartInstance->S, 3, 0),
                      &c4_d0, 0, 0, 0U, 0, 0U, 0);
  c4_d1 = c4_d0;
  if (c4_d1 < 128.0) {
    if (c4_d1 >= 0.0) {
      c4_u0 = (uint8_T)c4_d1;
    } else {
      c4_u0 = 0U;
    }
  } else if (c4_d1 >= 128.0) {
    c4_u0 = 127U;
  } else {
    c4_u0 = 0U;
  }

  chartInstance->c4_deviceAddr = c4_u0;
  sf_mex_import_named("powerRegAddr", sf_mex_get_sfun_param(chartInstance->S, 4,
    0), &c4_d2, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c4_powerRegAddr = (uint8_T)c4_d2;
  sf_mex_import_named("AccelXRegAddr", sf_mex_get_sfun_param(chartInstance->S, 0,
    0), &c4_d3, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c4_AccelXRegAddr = (uint8_T)c4_d3;
  sf_mex_import_named("AccelYRegAddr", sf_mex_get_sfun_param(chartInstance->S, 1,
    0), &c4_d4, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c4_AccelYRegAddr = (uint8_T)c4_d4;
  sf_mex_import_named("AccelZRegAddr", sf_mex_get_sfun_param(chartInstance->S, 2,
    0), &c4_d5, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c4_AccelZRegAddr = (uint8_T)c4_d5;
}

static void enable_c4_mpu6050_working(SFc4_mpu6050_workingInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c4_mpu6050_working(SFc4_mpu6050_workingInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c4_update_debugger_state_c4_mpu6050_working
  (SFc4_mpu6050_workingInstanceStruct *chartInstance)
{
  uint32_T c4_prevAniVal;
  c4_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (*chartInstance->c4_is_active_c4_mpu6050_working == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 3U, *chartInstance->c4_sfEvent);
  }

  if (*chartInstance->c4_is_c4_mpu6050_working == c4_IN_init) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, *chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, *chartInstance->c4_sfEvent);
  }

  if (*chartInstance->c4_is_c4_mpu6050_working == c4_IN_idle) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, *chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, *chartInstance->c4_sfEvent);
  }

  if (*chartInstance->c4_is_c4_mpu6050_working == c4_IN_start) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, *chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, *chartInstance->c4_sfEvent);
  }

  if (*chartInstance->c4_is_c4_mpu6050_working == c4_IN_startgetaddr) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, *chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, *chartInstance->c4_sfEvent);
  }

  if (*chartInstance->c4_is_c4_mpu6050_working == c4_IN_NACK) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, *chartInstance->c4_sfEvent);
  }

  if (*chartInstance->c4_is_c4_mpu6050_working == c4_IN_getaddr) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, *chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *chartInstance->c4_sfEvent);
  }

  if (*chartInstance->c4_is_c4_mpu6050_working == c4_IN_endgetaddr) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, *chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, *chartInstance->c4_sfEvent);
  }

  if (*chartInstance->c4_is_c4_mpu6050_working == c4_IN_sendack) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, *chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, *chartInstance->c4_sfEvent);
  }

  if (*chartInstance->c4_is_c4_mpu6050_working == c4_IN_senddatastart) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, *chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, *chartInstance->c4_sfEvent);
  }

  if (*chartInstance->c4_is_c4_mpu6050_working == c4_IN_waitForStop) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, *chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, *chartInstance->c4_sfEvent);
  }

  if (*chartInstance->c4_is_c4_mpu6050_working == c4_IN_getdatastart) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, *chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, *chartInstance->c4_sfEvent);
  }

  if (*chartInstance->c4_is_c4_mpu6050_working == c4_IN_sendbyte) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, *chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, *chartInstance->c4_sfEvent);
  }

  if (*chartInstance->c4_is_c4_mpu6050_working == c4_IN_getdata) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, *chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, *chartInstance->c4_sfEvent);
  }

  if (*chartInstance->c4_is_c4_mpu6050_working == c4_IN_sendbit) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, *chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, *chartInstance->c4_sfEvent);
  }

  if (*chartInstance->c4_is_c4_mpu6050_working == c4_IN_waitforPos) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 21U, *chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, *chartInstance->c4_sfEvent);
  }

  if (*chartInstance->c4_is_c4_mpu6050_working == c4_IN_endgetdata) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, *chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c4_sfEvent);
  }

  if (*chartInstance->c4_is_c4_mpu6050_working == c4_IN_lookRestart) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, *chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, *chartInstance->c4_sfEvent);
  }

  if (*chartInstance->c4_is_c4_mpu6050_working == c4_IN_waitstop1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 22U, *chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, *chartInstance->c4_sfEvent);
  }

  if (*chartInstance->c4_is_c4_mpu6050_working == c4_IN_waitEndOfAck) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, *chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, *chartInstance->c4_sfEvent);
  }

  if (*chartInstance->c4_is_c4_mpu6050_working == c4_IN_getcfgregstart) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, *chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, *chartInstance->c4_sfEvent);
  }

  if (*chartInstance->c4_is_c4_mpu6050_working == c4_IN_sendAck) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, *chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, *chartInstance->c4_sfEvent);
  }

  if (*chartInstance->c4_is_c4_mpu6050_working == c4_IN_getcfgdata) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, *chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, *chartInstance->c4_sfEvent);
  }

  _SFD_SET_ANIMATION(c4_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static void ext_mode_exec_c4_mpu6050_working(SFc4_mpu6050_workingInstanceStruct *
  chartInstance)
{
  c4_update_debugger_state_c4_mpu6050_working(chartInstance);
}

static const mxArray *get_sim_state_c4_mpu6050_working
  (SFc4_mpu6050_workingInstanceStruct *chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  boolean_T c4_hoistedGlobal;
  const mxArray *c4_b_y = NULL;
  uint8_T c4_b_hoistedGlobal;
  const mxArray *c4_c_y = NULL;
  uint8_T c4_u;
  const mxArray *c4_d_y = NULL;
  uint8_T c4_c_hoistedGlobal;
  const mxArray *c4_e_y = NULL;
  uint8_T c4_d_hoistedGlobal;
  const mxArray *c4_f_y = NULL;
  uint8_T c4_b_u;
  const mxArray *c4_g_y = NULL;
  uint8_T c4_e_hoistedGlobal;
  const mxArray *c4_h_y = NULL;
  uint8_T c4_f_hoistedGlobal;
  const mxArray *c4_i_y = NULL;
  boolean_T c4_g_hoistedGlobal;
  const mxArray *c4_j_y = NULL;
  uint8_T c4_h_hoistedGlobal;
  const mxArray *c4_k_y = NULL;
  uint8_T c4_i_hoistedGlobal;
  const mxArray *c4_l_y = NULL;
  const mxArray *c4_m_y = NULL;
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellmatrix(10, 1), false);
  c4_hoistedGlobal = *chartInstance->c4_sda_out;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_hoistedGlobal, 11, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_b_hoistedGlobal = *chartInstance->c4_addr;
  c4_c_y = NULL;
  c4_u = c4_b_hoistedGlobal;
  c4_d_y = NULL;
  sf_mex_assign(&c4_d_y, sf_mex_create("y", &c4_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_c_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
    (c4_eml_mx), 15, "numerictype", 14, sf_mex_dup(c4_c_eml_mx), 15,
    "simulinkarray", 14, c4_d_y, 15, "fimathislocal", 3, false), false);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  c4_c_hoistedGlobal = *chartInstance->c4_bit_idx;
  c4_e_y = NULL;
  sf_mex_assign(&c4_e_y, sf_mex_create("y", &c4_c_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c4_y, 2, c4_e_y);
  c4_d_hoistedGlobal = *chartInstance->c4_data;
  c4_f_y = NULL;
  c4_b_u = c4_d_hoistedGlobal;
  c4_g_y = NULL;
  sf_mex_assign(&c4_g_y, sf_mex_create("y", &c4_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_f_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
    (c4_eml_mx), 15, "numerictype", 14, sf_mex_dup(c4_b_eml_mx), 15,
    "simulinkarray", 14, c4_g_y, 15, "fimathislocal", 3, false), false);
  sf_mex_setcell(c4_y, 3, c4_f_y);
  c4_e_hoistedGlobal = *chartInstance->c4_rd_cnt;
  c4_h_y = NULL;
  sf_mex_assign(&c4_h_y, sf_mex_create("y", &c4_e_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c4_y, 4, c4_h_y);
  c4_f_hoistedGlobal = *chartInstance->c4_reg_idx;
  c4_i_y = NULL;
  sf_mex_assign(&c4_i_y, sf_mex_create("y", &c4_f_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c4_y, 5, c4_i_y);
  c4_g_hoistedGlobal = *chartInstance->c4_rw;
  c4_j_y = NULL;
  sf_mex_assign(&c4_j_y, sf_mex_create("y", &c4_g_hoistedGlobal, 11, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c4_y, 6, c4_j_y);
  c4_h_hoistedGlobal = *chartInstance->c4_is_active_c4_mpu6050_working;
  c4_k_y = NULL;
  sf_mex_assign(&c4_k_y, sf_mex_create("y", &c4_h_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c4_y, 7, c4_k_y);
  c4_i_hoistedGlobal = *chartInstance->c4_is_c4_mpu6050_working;
  c4_l_y = NULL;
  sf_mex_assign(&c4_l_y, sf_mex_create("y", &c4_i_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c4_y, 8, c4_l_y);
  c4_m_y = NULL;
  sf_mex_assign(&c4_m_y, sf_mex_create("y",
    chartInstance->c4_dataWrittenToVector, 11, 0U, 1U, 0U, 1, 8), false);
  sf_mex_setcell(c4_y, 9, c4_m_y);
  sf_mex_assign(&c4_st, c4_y, false);
  return c4_st;
}

static void set_sim_state_c4_mpu6050_working(SFc4_mpu6050_workingInstanceStruct *
  chartInstance, const mxArray *c4_st)
{
  const mxArray *c4_u;
  boolean_T c4_bv0[8];
  int32_T c4_i0;
  c4_u = sf_mex_dup(c4_st);
  *chartInstance->c4_sda_out = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("sda_out", c4_u, 0)), "sda_out");
  *chartInstance->c4_addr = c4_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("addr", c4_u, 1)), "addr");
  *chartInstance->c4_bit_idx = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("bit_idx", c4_u, 2)), "bit_idx");
  *chartInstance->c4_data = c4_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("data", c4_u, 3)), "data");
  *chartInstance->c4_rd_cnt = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("rd_cnt", c4_u, 4)), "rd_cnt");
  *chartInstance->c4_reg_idx = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("reg_idx", c4_u, 5)), "reg_idx");
  *chartInstance->c4_rw = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("rw", c4_u, 6)), "rw");
  *chartInstance->c4_is_active_c4_mpu6050_working = c4_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell("is_active_c4_mpu6050_working",
       c4_u, 7)), "is_active_c4_mpu6050_working");
  *chartInstance->c4_is_c4_mpu6050_working = c4_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_c4_mpu6050_working", c4_u, 8)),
    "is_c4_mpu6050_working");
  c4_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "dataWrittenToVector", c4_u, 9)), "dataWrittenToVector", c4_bv0);
  for (c4_i0 = 0; c4_i0 < 8; c4_i0++) {
    chartInstance->c4_dataWrittenToVector[c4_i0] = c4_bv0[c4_i0];
  }

  sf_mex_assign(&chartInstance->c4_setSimStateSideEffectsInfo,
                c4_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "setSimStateSideEffectsInfo", c4_u, 10)), "setSimStateSideEffectsInfo"),
                true);
  sf_mex_destroy(&c4_u);
  chartInstance->c4_doSetSimStateSideEffects = 1U;
  c4_update_debugger_state_c4_mpu6050_working(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void c4_set_sim_state_side_effects_c4_mpu6050_working
  (SFc4_mpu6050_workingInstanceStruct *chartInstance)
{
  if (chartInstance->c4_doSetSimStateSideEffects != 0) {
    chartInstance->c4_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c4_mpu6050_working(SFc4_mpu6050_workingInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&c4_eml_mx);
  sf_mex_destroy(&c4_b_eml_mx);
  sf_mex_destroy(&c4_c_eml_mx);
  sf_mex_destroy(&chartInstance->c4_setSimStateSideEffectsInfo);
}

static void sf_gateway_c4_mpu6050_working(SFc4_mpu6050_workingInstanceStruct
  *chartInstance)
{
  c4_set_sim_state_side_effects_c4_mpu6050_working(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, *chartInstance->c4_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_scl, 7U, 1U, 0U,
                        *chartInstance->c4_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_sda, 6U, 1U, 0U,
                        *chartInstance->c4_sfEvent, false);
  *chartInstance->c4_sfEvent = CALL_EVENT;
  c4_chartstep_c4_mpu6050_working(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_mpu6050_workingMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c4_mpu6050_working(SFc4_mpu6050_workingInstanceStruct
  *chartInstance)
{
  c4_init_sf_message_store_memory(chartInstance);
}

static void c4_chartstep_c4_mpu6050_working(SFc4_mpu6050_workingInstanceStruct
  *chartInstance)
{
  uint32_T c4_debug_family_var_map[3];
  real_T c4_nargin = 0.0;
  real_T c4_b_nargin = 0.0;
  real_T c4_c_nargin = 0.0;
  real_T c4_d_nargin = 0.0;
  real_T c4_e_nargin = 0.0;
  real_T c4_nargout = 1.0;
  real_T c4_b_nargout = 1.0;
  real_T c4_c_nargout = 1.0;
  real_T c4_d_nargout = 1.0;
  real_T c4_e_nargout = 1.0;
  boolean_T c4_out;
  boolean_T c4_b_out;
  boolean_T c4_c_out;
  boolean_T c4_d_out;
  boolean_T c4_e_out;
  uint32_T c4_b_debug_family_var_map[2];
  real_T c4_f_nargin = 0.0;
  real_T c4_f_nargout = 0.0;
  real_T c4_g_nargin = 0.0;
  real_T c4_g_nargout = 0.0;
  real_T c4_h_nargin = 0.0;
  real_T c4_i_nargin = 0.0;
  real_T c4_j_nargin = 0.0;
  uint8_T c4_hoistedGlobal;
  real_T c4_h_nargout = 1.0;
  real_T c4_i_nargout = 0.0;
  real_T c4_j_nargout = 1.0;
  uint8_T c4_b_hoistedGlobal;
  boolean_T c4_f_out;
  boolean_T c4_g_out;
  uint8_T c4_a;
  real_T c4_k_nargin = 0.0;
  uint8_T c4_bit;
  real_T c4_k_nargout = 0.0;
  uint8_T c4_bit1;
  uint32_T c4_q0;
  uint32_T c4_b_q0;
  uint32_T c4_qY;
  uint8_T c4_c;
  uint32_T c4_b_qY;
  uint32_T c4_u1;
  uint32_T c4_u2;
  real_T c4_l_nargin = 0.0;
  real_T c4_l_nargout = 0.0;
  uint8_T c4_b_bit_idx;
  uint8_T c4_mask;
  uint32_T c4_u3;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, *chartInstance->c4_sfEvent);
  if (*chartInstance->c4_is_active_c4_mpu6050_working == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 3U, *chartInstance->c4_sfEvent);
    *chartInstance->c4_is_active_c4_mpu6050_working = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, *chartInstance->c4_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, *chartInstance->c4_sfEvent);
    *chartInstance->c4_is_c4_mpu6050_working = c4_IN_init;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, *chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_debug_family_names,
      c4_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_f_nargin, 0U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_f_nargout, 1U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    *chartInstance->c4_rd_cnt = 0U;
    chartInstance->c4_dataWrittenToVector[6U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_rd_cnt, 3U, 4U, 9U,
                          *chartInstance->c4_sfEvent, false);
    *chartInstance->c4_reg_idx = 0U;
    chartInstance->c4_dataWrittenToVector[5U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_reg_idx, 4U, 4U, 9U,
                          *chartInstance->c4_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    switch (*chartInstance->c4_is_c4_mpu6050_working) {
     case c4_IN_NACK:
      CV_CHART_EVAL(3, 0, 1);
      c4_NACK(chartInstance);
      break;

     case c4_IN_endgetaddr:
      CV_CHART_EVAL(3, 0, 2);
      c4_endgetaddr(chartInstance);
      break;

     case c4_IN_endgetdata:
      CV_CHART_EVAL(3, 0, 3);
      c4_endgetdata(chartInstance);
      break;

     case c4_IN_getaddr:
      CV_CHART_EVAL(3, 0, 4);
      c4_getaddr(chartInstance);
      break;

     case c4_IN_getcfgdata:
      CV_CHART_EVAL(3, 0, 5);
      c4_getcfgdata(chartInstance);
      break;

     case c4_IN_getcfgregstart:
      CV_CHART_EVAL(3, 0, 6);
      c4_getcfgregstart(chartInstance);
      break;

     case c4_IN_getdata:
      CV_CHART_EVAL(3, 0, 7);
      c4_getdata(chartInstance);
      break;

     case c4_IN_getdatastart:
      CV_CHART_EVAL(3, 0, 8);
      c4_getdatastart(chartInstance);
      break;

     case c4_IN_idle:
      CV_CHART_EVAL(3, 0, 9);
      c4_idle(chartInstance);
      break;

     case c4_IN_init:
      CV_CHART_EVAL(3, 0, 10);
      c4_init(chartInstance);
      break;

     case c4_IN_lookRestart:
      CV_CHART_EVAL(3, 0, 11);
      c4_lookRestart(chartInstance);
      break;

     case c4_IN_sendAck:
      CV_CHART_EVAL(3, 0, 12);
      c4_sendAck(chartInstance);
      break;

     case c4_IN_sendack:
      CV_CHART_EVAL(3, 0, 13);
      c4_sendack(chartInstance);
      break;

     case c4_IN_sendbit:
      CV_CHART_EVAL(3, 0, 14);
      c4_sendbit(chartInstance);
      break;

     case c4_IN_sendbyte:
      CV_CHART_EVAL(3, 0, 15);
      c4_sendbyte(chartInstance);
      break;

     case c4_IN_senddatastart:
      CV_CHART_EVAL(3, 0, 16);
      c4_senddatastart(chartInstance);
      break;

     case c4_IN_start:
      CV_CHART_EVAL(3, 0, 17);
      c4_start(chartInstance);
      break;

     case c4_IN_startgetaddr:
      CV_CHART_EVAL(3, 0, 18);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                   *chartInstance->c4_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_u_debug_family_names,
        c4_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_c_sf_marshallOut,
        c4_c_sf_marshallIn);
      c4_out = CV_EML_IF(2, 0, 0, CV_RELATIONAL_EVAL(5U, 2U, 0, (real_T)
        *chartInstance->c4_scl, 1.0, -1, 0U, (int32_T)*chartInstance->c4_scl));
      _SFD_SYMBOL_SCOPE_POP();
      if (c4_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, *chartInstance->c4_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, *chartInstance->c4_sfEvent);
        *chartInstance->c4_is_c4_mpu6050_working = c4_IN_getaddr;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, *chartInstance->c4_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_e_debug_family_names,
          c4_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_g_nargin, 0U, c4_sf_marshallOut,
          c4_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_g_nargout, 1U,
          c4_sf_marshallOut, c4_sf_marshallIn);
        if (CV_EML_IF(3, 1, 0, CV_RELATIONAL_EVAL(4U, 3U, 0, (real_T)
              *chartInstance->c4_sda, 1.0, -1, 0U, (int32_T)
              *chartInstance->c4_sda))) {
          c4_hoistedGlobal = *chartInstance->c4_addr;
          c4_b_hoistedGlobal = *chartInstance->c4_bit_idx;
          c4_a = c4_hoistedGlobal;
          c4_bit = c4_b_hoistedGlobal;
          if (((real_T)c4_bit >= 1.0) && ((real_T)c4_bit <= 7.0)) {
            c4_bit1 = c4_bit;
            c4_b_q0 = c4_bit1;
            c4_b_qY = c4_b_q0 - 1U;
            if (CV_SATURATION_EVAL(4, 3, 0, 0, c4_b_qY > c4_b_q0)) {
              c4_b_qY = 0U;
            }

            c4_u2 = c4_b_qY;
            if (CV_SATURATION_EVAL(4, 3, 0, 0, c4_u2 > 255U)) {
              c4_u2 = 255U;
            }

            c4_b_bit_idx = (uint8_T)c4_u2;
            c4_mask = (uint8_T)((uint8_T)(1 << (uint8_T)
              sf_eml_shift_index_bounds_check(sfGlobalDebugInstanceStruct,
              chartInstance->S, 20U, 38, 20, "", (int32_T)c4_b_bit_idx, 0, 6)) &
                                127U);
            c4_c = (uint8_T)((c4_a | c4_mask) & 127U);
          } else {
            c4_error(chartInstance, 7);
          }

          *chartInstance->c4_addr = c4_c;
          chartInstance->c4_dataWrittenToVector[1U] = true;
          _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_addr, 0U, 4U, 3U,
                                *chartInstance->c4_sfEvent, false);
        } else {
          if (!chartInstance->c4_dataWrittenToVector[2U]) {
            _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 3U,
              *chartInstance->c4_sfEvent, false);
          }

          if (!chartInstance->c4_dataWrittenToVector[1U]) {
            _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 3U,
              *chartInstance->c4_sfEvent, false);
          }
        }

        if (!chartInstance->c4_dataWrittenToVector[2U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 3U,
            *chartInstance->c4_sfEvent, false);
        }

        c4_q0 = *chartInstance->c4_bit_idx;
        c4_qY = c4_q0 - 1U;
        if (CV_SATURATION_EVAL(4, 3, 1, 0, c4_qY > c4_q0)) {
          c4_qY = 0U;
        }

        c4_u1 = c4_qY;
        if (CV_SATURATION_EVAL(4, 3, 1, 0, c4_u1 > 255U)) {
          c4_u1 = 255U;
        }

        *chartInstance->c4_bit_idx = (uint8_T)c4_u1;
        chartInstance->c4_dataWrittenToVector[2U] = true;
        _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_bit_idx, 1U, 4U, 3U,
                              *chartInstance->c4_sfEvent, false);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 18U,
                     *chartInstance->c4_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 18U, *chartInstance->c4_sfEvent);
      break;

     case c4_IN_waitEndOfAck:
      CV_CHART_EVAL(3, 0, 19);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 62U,
                   *chartInstance->c4_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_fb_debug_family_names,
        c4_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 0U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 1U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_out, 2U, c4_c_sf_marshallOut,
        c4_c_sf_marshallIn);
      if (CV_EML_COND(62, 0, 0, CV_RELATIONAL_EVAL(5U, 62U, 0, (real_T)
            *chartInstance->c4_scl, 1.0, -1, 0U, (int32_T)*chartInstance->c4_scl))
          && CV_EML_COND(62, 0, 1, CV_RELATIONAL_EVAL(5U, 62U, 1, (real_T)
            *chartInstance->c4_sda, 0.0, -1, 0U, !*chartInstance->c4_sda))) {
        CV_EML_MCDC(62, 0, 0, true);
        CV_EML_IF(62, 0, 0, true);
        c4_b_out = true;
      } else {
        CV_EML_MCDC(62, 0, 0, false);
        CV_EML_IF(62, 0, 0, false);
        c4_b_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c4_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 62U, *chartInstance->c4_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, *chartInstance->c4_sfEvent);
        *chartInstance->c4_is_c4_mpu6050_working = c4_IN_waitForStop;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, *chartInstance->c4_sfEvent);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 19U,
                     *chartInstance->c4_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19U, *chartInstance->c4_sfEvent);
      break;

     case c4_IN_waitForStop:
      CV_CHART_EVAL(3, 0, 20);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 32U,
                   *chartInstance->c4_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_p_debug_family_names,
        c4_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargin, 0U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargout, 1U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_out, 2U, c4_c_sf_marshallOut,
        c4_c_sf_marshallIn);
      if (CV_EML_COND(32, 0, 0, CV_RELATIONAL_EVAL(5U, 32U, 0, (real_T)
            *chartInstance->c4_scl, 1.0, -1, 0U, (int32_T)*chartInstance->c4_scl))
          && CV_EML_COND(32, 0, 1, CV_RELATIONAL_EVAL(5U, 32U, 1, (real_T)
            *chartInstance->c4_sda, 1.0, -1, 0U, (int32_T)*chartInstance->c4_sda)))
      {
        CV_EML_MCDC(32, 0, 0, true);
        CV_EML_IF(32, 0, 0, true);
        c4_c_out = true;
      } else {
        CV_EML_MCDC(32, 0, 0, false);
        CV_EML_IF(32, 0, 0, false);
        c4_c_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c4_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 32U, *chartInstance->c4_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, *chartInstance->c4_sfEvent);
        *chartInstance->c4_is_c4_mpu6050_working = c4_IN_idle;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, *chartInstance->c4_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_b_debug_family_names,
          c4_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_k_nargin, 0U, c4_sf_marshallOut,
          c4_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_k_nargout, 1U,
          c4_sf_marshallOut, c4_sf_marshallIn);
        *chartInstance->c4_sda_out = false;
        chartInstance->c4_dataWrittenToVector[0U] = true;
        _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_sda_out, 8U, 4U, 8U,
                              *chartInstance->c4_sfEvent, false);
        *chartInstance->c4_addr = 0U;
        chartInstance->c4_dataWrittenToVector[1U] = true;
        _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_addr, 0U, 4U, 8U,
                              *chartInstance->c4_sfEvent, false);
        *chartInstance->c4_data = 0U;
        chartInstance->c4_dataWrittenToVector[3U] = true;
        _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_data, 2U, 4U, 8U,
                              *chartInstance->c4_sfEvent, false);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 20U,
                     *chartInstance->c4_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 20U, *chartInstance->c4_sfEvent);
      break;

     case c4_IN_waitforPos:
      CV_CHART_EVAL(3, 0, 21);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 54U,
                   *chartInstance->c4_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_rb_debug_family_names,
        c4_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_nargin, 0U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_nargout, 1U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_out, 2U, c4_c_sf_marshallOut,
        c4_c_sf_marshallIn);
      if (CV_EML_COND(54, 0, 0, *chartInstance->c4_scl) && CV_EML_COND(54, 0, 1,
           !*chartInstance->c4_sda)) {
        CV_EML_MCDC(54, 0, 0, true);
        CV_EML_IF(54, 0, 0, true);
        c4_d_out = true;
      } else {
        CV_EML_MCDC(54, 0, 0, false);
        CV_EML_IF(54, 0, 0, false);
        c4_d_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c4_d_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 54U, *chartInstance->c4_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_sb_debug_family_names,
          c4_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_i_nargin, 0U, c4_sf_marshallOut,
          c4_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_i_nargout, 1U,
          c4_sf_marshallOut, c4_sf_marshallIn);
        *chartInstance->c4_bit_idx = 8U;
        chartInstance->c4_dataWrittenToVector[2U] = true;
        _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_bit_idx, 1U, 5U, 54U,
                              *chartInstance->c4_sfEvent, false);
        *chartInstance->c4_data = 0U;
        chartInstance->c4_dataWrittenToVector[3U] = true;
        _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_data, 2U, 5U, 54U,
                              *chartInstance->c4_sfEvent, false);
        _SFD_SYMBOL_SCOPE_POP();
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, *chartInstance->c4_sfEvent);
        *chartInstance->c4_is_c4_mpu6050_working = c4_IN_getcfgdata;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, *chartInstance->c4_sfEvent);
        c4_enter_atomic_getcfgdata(chartInstance);
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 63U,
                     *chartInstance->c4_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_qb_debug_family_names,
          c4_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_h_nargin, 0U, c4_sf_marshallOut,
          c4_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_h_nargout, 1U,
          c4_sf_marshallOut, c4_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_f_out, 2U, c4_c_sf_marshallOut,
          c4_c_sf_marshallIn);
        if (CV_EML_COND(63, 0, 0, CV_RELATIONAL_EVAL(5U, 63U, 0, (real_T)
              *chartInstance->c4_scl, 1.0, -1, 0U, (int32_T)
              *chartInstance->c4_scl)) && CV_EML_COND(63, 0, 1,
             CV_RELATIONAL_EVAL(5U, 63U, 1, (real_T)*chartInstance->c4_sda, 1.0,
              -1, 0U, (int32_T)*chartInstance->c4_sda))) {
          CV_EML_MCDC(63, 0, 0, true);
          CV_EML_IF(63, 0, 0, true);
          c4_f_out = true;
        } else {
          CV_EML_MCDC(63, 0, 0, false);
          CV_EML_IF(63, 0, 0, false);
          c4_f_out = false;
        }

        _SFD_SYMBOL_SCOPE_POP();
        if (c4_f_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 63U, *chartInstance->c4_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, *chartInstance->c4_sfEvent);
          *chartInstance->c4_is_c4_mpu6050_working = c4_IN_lookRestart;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, *chartInstance->c4_sfEvent);
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 21U,
                       *chartInstance->c4_sfEvent);
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 21U, *chartInstance->c4_sfEvent);
      break;

     case c4_IN_waitstop1:
      CV_CHART_EVAL(3, 0, 22);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 50U,
                   *chartInstance->c4_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_eb_debug_family_names,
        c4_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_e_nargin, 0U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_e_nargout, 1U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_e_out, 2U, c4_c_sf_marshallOut,
        c4_c_sf_marshallIn);
      if (CV_EML_COND(50, 0, 0, CV_RELATIONAL_EVAL(5U, 50U, 0, (real_T)
            *chartInstance->c4_scl, 1.0, -1, 0U, (int32_T)*chartInstance->c4_scl))
          && CV_EML_COND(50, 0, 1, CV_RELATIONAL_EVAL(5U, 50U, 1, (real_T)
            *chartInstance->c4_sda, 1.0, -1, 0U, (int32_T)*chartInstance->c4_sda)))
      {
        CV_EML_MCDC(50, 0, 0, true);
        CV_EML_IF(50, 0, 0, true);
        c4_e_out = true;
      } else {
        CV_EML_MCDC(50, 0, 0, false);
        CV_EML_IF(50, 0, 0, false);
        c4_e_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c4_e_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 50U, *chartInstance->c4_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, *chartInstance->c4_sfEvent);
        *chartInstance->c4_is_c4_mpu6050_working = c4_IN_waitForStop;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, *chartInstance->c4_sfEvent);
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 51U,
                     *chartInstance->c4_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_cb_debug_family_names,
          c4_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_j_nargin, 0U, c4_sf_marshallOut,
          c4_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_j_nargout, 1U,
          c4_sf_marshallOut, c4_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_g_out, 2U, c4_c_sf_marshallOut,
          c4_c_sf_marshallIn);
        if (CV_EML_COND(51, 0, 0, *chartInstance->c4_scl) && CV_EML_COND(51, 0,
             1, !*chartInstance->c4_sda)) {
          CV_EML_MCDC(51, 0, 0, true);
          CV_EML_IF(51, 0, 0, true);
          c4_g_out = true;
        } else {
          CV_EML_MCDC(51, 0, 0, false);
          CV_EML_IF(51, 0, 0, false);
          c4_g_out = false;
        }

        _SFD_SYMBOL_SCOPE_POP();
        if (c4_g_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 51U, *chartInstance->c4_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_db_debug_family_names,
            c4_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_l_nargin, 0U,
            c4_sf_marshallOut, c4_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_l_nargout, 1U,
            c4_sf_marshallOut, c4_sf_marshallIn);
          if (!chartInstance->c4_dataWrittenToVector[6U]) {
            _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 5U, 51U,
              *chartInstance->c4_sfEvent, false);
          }

          c4_u3 = (uint32_T)*chartInstance->c4_rd_cnt + 1U;
          if (CV_SATURATION_EVAL(5, 51, 0, 0, c4_u3 > 255U)) {
            c4_u3 = 255U;
          }

          *chartInstance->c4_rd_cnt = (uint8_T)c4_u3;
          chartInstance->c4_dataWrittenToVector[6U] = true;
          _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_rd_cnt, 3U, 5U, 51U, *
                                chartInstance->c4_sfEvent, false);
          _SFD_SYMBOL_SCOPE_POP();
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, *chartInstance->c4_sfEvent);
          *chartInstance->c4_is_c4_mpu6050_working = c4_IN_senddatastart;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, *chartInstance->c4_sfEvent);
          c4_enter_atomic_senddatastart(chartInstance);
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 22U,
                       *chartInstance->c4_sfEvent);
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 22U, *chartInstance->c4_sfEvent);
      break;

     default:
      CV_CHART_EVAL(3, 0, 0);

      /* Unreachable state, for coverage only */
      *chartInstance->c4_is_c4_mpu6050_working = c4_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, *chartInstance->c4_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, *chartInstance->c4_sfEvent);
}

static void initSimStructsc4_mpu6050_working(SFc4_mpu6050_workingInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void c4_init(SFc4_mpu6050_workingInstanceStruct *chartInstance)
{
  uint32_T c4_debug_family_var_map[2];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 0.0;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 33U, *chartInstance->c4_sfEvent);
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, *chartInstance->c4_sfEvent);
  *chartInstance->c4_is_c4_mpu6050_working = c4_IN_idle;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, *chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_b_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  *chartInstance->c4_sda_out = false;
  chartInstance->c4_dataWrittenToVector[0U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_sda_out, 8U, 4U, 8U,
                        *chartInstance->c4_sfEvent, false);
  *chartInstance->c4_addr = 0U;
  chartInstance->c4_dataWrittenToVector[1U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_addr, 0U, 4U, 8U,
                        *chartInstance->c4_sfEvent, false);
  *chartInstance->c4_data = 0U;
  chartInstance->c4_dataWrittenToVector[3U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_data, 2U, 4U, 8U,
                        *chartInstance->c4_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, *chartInstance->c4_sfEvent);
}

static void c4_idle(SFc4_mpu6050_workingInstanceStruct *chartInstance)
{
  uint32_T c4_debug_family_var_map[3];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 1.0;
  boolean_T c4_out;
  uint32_T c4_b_debug_family_var_map[2];
  real_T c4_b_nargin = 0.0;
  real_T c4_b_nargout = 0.0;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 66U, *chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_q_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  if (CV_EML_COND(66, 0, 0, CV_RELATIONAL_EVAL(5U, 66U, 0, (real_T)
        *chartInstance->c4_scl, 1.0, -1, 0U, (int32_T)*chartInstance->c4_scl)) &&
      CV_EML_COND(66, 0, 1, CV_RELATIONAL_EVAL(5U, 66U, 1, (real_T)
        *chartInstance->c4_sda, 0.0, -1, 0U, !*chartInstance->c4_sda))) {
    CV_EML_MCDC(66, 0, 0, true);
    CV_EML_IF(66, 0, 0, true);
    c4_out = true;
  } else {
    CV_EML_MCDC(66, 0, 0, false);
    CV_EML_IF(66, 0, 0, false);
    c4_out = false;
  }

  _SFD_SYMBOL_SCOPE_POP();
  if (c4_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 66U, *chartInstance->c4_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, *chartInstance->c4_sfEvent);
    *chartInstance->c4_is_c4_mpu6050_working = c4_IN_start;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, *chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_c_debug_family_names,
      c4_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 0U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 1U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    *chartInstance->c4_bit_idx = 7U;
    chartInstance->c4_dataWrittenToVector[2U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_bit_idx, 1U, 4U, 17U,
                          *chartInstance->c4_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U, *chartInstance->c4_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, *chartInstance->c4_sfEvent);
}

static void c4_start(SFc4_mpu6050_workingInstanceStruct *chartInstance)
{
  uint32_T c4_debug_family_var_map[3];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 1.0;
  boolean_T c4_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U, *chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_s_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  c4_out = CV_EML_IF(1, 0, 0, CV_RELATIONAL_EVAL(5U, 1U, 0, (real_T)
    *chartInstance->c4_scl, 1.0, -1, 0U, (int32_T)*chartInstance->c4_scl));
  _SFD_SYMBOL_SCOPE_POP();
  if (c4_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, *chartInstance->c4_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, *chartInstance->c4_sfEvent);
    *chartInstance->c4_is_c4_mpu6050_working = c4_IN_startgetaddr;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, *chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 17U,
                 *chartInstance->c4_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 17U, *chartInstance->c4_sfEvent);
}

static void c4_NACK(SFc4_mpu6050_workingInstanceStruct *chartInstance)
{
  uint32_T c4_debug_family_var_map[2];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 0.0;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 61U, *chartInstance->c4_sfEvent);
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, *chartInstance->c4_sfEvent);
  *chartInstance->c4_is_c4_mpu6050_working = c4_IN_idle;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, *chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_b_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  *chartInstance->c4_sda_out = false;
  chartInstance->c4_dataWrittenToVector[0U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_sda_out, 8U, 4U, 8U,
                        *chartInstance->c4_sfEvent, false);
  *chartInstance->c4_addr = 0U;
  chartInstance->c4_dataWrittenToVector[1U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_addr, 0U, 4U, 8U,
                        *chartInstance->c4_sfEvent, false);
  *chartInstance->c4_data = 0U;
  chartInstance->c4_dataWrittenToVector[3U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_data, 2U, 4U, 8U,
                        *chartInstance->c4_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, *chartInstance->c4_sfEvent);
}

static void c4_getaddr(SFc4_mpu6050_workingInstanceStruct *chartInstance)
{
  uint32_T c4_debug_family_var_map[3];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 1.0;
  boolean_T c4_out;
  real_T c4_b_nargin = 0.0;
  real_T c4_b_nargout = 1.0;
  boolean_T c4_b_out;
  uint32_T c4_b_debug_family_var_map[2];
  real_T c4_c_nargin = 0.0;
  real_T c4_c_nargout = 0.0;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U, *chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_t_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  if (!chartInstance->c4_dataWrittenToVector[2U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 5U, 3U, *chartInstance->c4_sfEvent,
      false);
  }

  c4_out = CV_EML_IF(3, 0, 0, CV_RELATIONAL_EVAL(5U, 3U, 0, (real_T)
    *chartInstance->c4_bit_idx, 0.0, -1, 4U, (real_T)*chartInstance->c4_bit_idx >
    0.0));
  _SFD_SYMBOL_SCOPE_POP();
  if (c4_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, *chartInstance->c4_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *chartInstance->c4_sfEvent);
    *chartInstance->c4_is_c4_mpu6050_working = c4_IN_startgetaddr;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, *chartInstance->c4_sfEvent);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U,
                 *chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_w_debug_family_names,
      c4_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 0U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 1U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_out, 2U, c4_c_sf_marshallOut,
      c4_c_sf_marshallIn);
    c4_b_out = CV_EML_IF(4, 0, 0, CV_RELATIONAL_EVAL(5U, 4U, 0, (real_T)
      *chartInstance->c4_scl, 1.0, -1, 0U, (int32_T)*chartInstance->c4_scl));
    _SFD_SYMBOL_SCOPE_POP();
    if (c4_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, *chartInstance->c4_sfEvent);
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *chartInstance->c4_sfEvent);
      *chartInstance->c4_is_c4_mpu6050_working = c4_IN_endgetaddr;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, *chartInstance->c4_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_f_debug_family_names,
        c4_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargin, 0U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargout, 1U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      *chartInstance->c4_rw = *chartInstance->c4_sda;
      chartInstance->c4_dataWrittenToVector[4U] = true;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_rw, 5U, 4U, 1U,
                            *chartInstance->c4_sfEvent, false);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                   *chartInstance->c4_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, *chartInstance->c4_sfEvent);
}

static void c4_endgetaddr(SFc4_mpu6050_workingInstanceStruct *chartInstance)
{
  uint32_T c4_debug_family_var_map[3];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 1.0;
  boolean_T c4_out;
  uint8_T c4_hoistedGlobal;
  uint8_T c4_b_hoistedGlobal;
  uint8_T c4_c_hoistedGlobal;
  uint8_T c4_d_hoistedGlobal;
  uint8_T c4_e_hoistedGlobal;
  uint8_T c4_f_hoistedGlobal;
  uint8_T c4_g_hoistedGlobal;
  uint8_T c4_h_hoistedGlobal;
  uint8_T c4_i_hoistedGlobal;
  uint8_T c4_j_hoistedGlobal;
  uint8_T c4_a0;
  uint8_T c4_b0;
  uint8_T c4_a;
  uint8_T c4_b;
  uint8_T c4_b_a0;
  uint8_T c4_b_b0;
  uint8_T c4_a1;
  uint8_T c4_b1;
  uint8_T c4_b_a1;
  uint8_T c4_b_b1;
  boolean_T c4_c;
  int32_T c4_i1;
  int32_T c4_i2;
  real_T c4_k_hoistedGlobal;
  real_T c4_b_nargin = 0.0;
  real_T c4_b_nargout = 1.0;
  boolean_T c4_b_out;
  uint32_T c4_b_debug_family_var_map[2];
  real_T c4_c_nargin = 0.0;
  real_T c4_c_nargout = 0.0;
  real_T c4_d_nargin = 0.0;
  real_T c4_d_nargout = 0.0;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U, *chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_v_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  if (!chartInstance->c4_dataWrittenToVector[1U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 5U, 5U, *chartInstance->c4_sfEvent,
      false);
  }

  c4_hoistedGlobal = *chartInstance->c4_addr;
  c4_b_hoistedGlobal = chartInstance->c4_deviceAddr;
  c4_c_hoistedGlobal = chartInstance->c4_deviceAddr;
  c4_d_hoistedGlobal = *chartInstance->c4_addr;
  c4_e_hoistedGlobal = *chartInstance->c4_addr;
  c4_f_hoistedGlobal = chartInstance->c4_deviceAddr;
  c4_g_hoistedGlobal = *chartInstance->c4_addr;
  c4_h_hoistedGlobal = chartInstance->c4_deviceAddr;
  c4_i_hoistedGlobal = *chartInstance->c4_addr;
  c4_j_hoistedGlobal = chartInstance->c4_deviceAddr;
  c4_a0 = c4_i_hoistedGlobal;
  c4_b0 = c4_j_hoistedGlobal;
  c4_a = c4_a0;
  c4_b = c4_b0;
  c4_b_a0 = c4_a;
  c4_b_b0 = c4_b;
  c4_a1 = c4_b_a0;
  c4_b1 = c4_b_b0;
  c4_b_a1 = c4_a1;
  c4_b_b1 = c4_b1;
  c4_c = (c4_b_a1 != c4_b_b1);
  c4_i1 = (int8_T)c4_c_hoistedGlobal - (int8_T)c4_d_hoistedGlobal;
  if (c4_i1 > 127) {
    c4_i1 = 127;
  } else {
    if (c4_i1 < -128) {
      c4_i1 = -128;
    }
  }

  c4_i2 = (int8_T)c4_g_hoistedGlobal - (int8_T)c4_h_hoistedGlobal;
  if (c4_i2 > 127) {
    c4_i2 = 127;
  } else {
    if (c4_i2 < -128) {
      c4_i2 = -128;
    }
  }

  if ((int8_T)c4_hoistedGlobal < (int8_T)c4_b_hoistedGlobal) {
    c4_k_hoistedGlobal = (real_T)((int8_T)c4_i1 <= 1);
  } else if ((int8_T)c4_e_hoistedGlobal > (int8_T)c4_f_hoistedGlobal) {
    if ((int8_T)c4_i2 <= 1) {
      c4_k_hoistedGlobal = 3.0;
    } else {
      c4_k_hoistedGlobal = 0.0;
    }
  } else {
    c4_k_hoistedGlobal = 2.0;
  }

  c4_out = CV_EML_IF(5, 0, 0, CV_RELATIONAL_EVAL(5U, 5U, 0, c4_k_hoistedGlobal,
    0.0, -2, 1U, (int32_T)c4_c));
  _SFD_SYMBOL_SCOPE_POP();
  if (c4_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, *chartInstance->c4_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, *chartInstance->c4_sfEvent);
    *chartInstance->c4_is_c4_mpu6050_working = c4_IN_NACK;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_d_debug_family_names,
      c4_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargin, 0U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargout, 1U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    *chartInstance->c4_sda_out = true;
    chartInstance->c4_dataWrittenToVector[0U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_sda_out, 8U, 4U, 0U,
                          *chartInstance->c4_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U,
                 *chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_x_debug_family_names,
      c4_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 0U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 1U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_out, 2U, c4_c_sf_marshallOut,
      c4_c_sf_marshallIn);
    c4_b_out = CV_EML_IF(6, 0, 0, CV_RELATIONAL_EVAL(5U, 6U, 0, (real_T)
      *chartInstance->c4_scl, 1.0, -1, 0U, (int32_T)*chartInstance->c4_scl));
    _SFD_SYMBOL_SCOPE_POP();
    if (c4_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, *chartInstance->c4_sfEvent);
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, *chartInstance->c4_sfEvent);
      *chartInstance->c4_is_c4_mpu6050_working = c4_IN_sendack;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, *chartInstance->c4_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_g_debug_family_names,
        c4_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_nargin, 0U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_nargout, 1U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      *chartInstance->c4_sda_out = false;
      chartInstance->c4_dataWrittenToVector[0U] = true;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_sda_out, 8U, 4U, 12U,
                            *chartInstance->c4_sfEvent, false);
      *chartInstance->c4_bit_idx = 8U;
      chartInstance->c4_dataWrittenToVector[2U] = true;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_bit_idx, 1U, 4U, 12U,
                            *chartInstance->c4_sfEvent, false);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                   *chartInstance->c4_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, *chartInstance->c4_sfEvent);
}

static void c4_sendack(SFc4_mpu6050_workingInstanceStruct *chartInstance)
{
  uint32_T c4_debug_family_var_map[3];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 1.0;
  boolean_T c4_out;
  real_T c4_b_nargin = 0.0;
  real_T c4_b_nargout = 1.0;
  boolean_T c4_b_out;
  uint32_T c4_b_debug_family_var_map[2];
  real_T c4_c_nargin = 0.0;
  real_T c4_c_nargout = 0.0;
  boolean_T guard1 = false;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 11U, *chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_y_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  guard1 = false;
  if (CV_EML_COND(11, 0, 0, CV_RELATIONAL_EVAL(5U, 11U, 0, (real_T)
        *chartInstance->c4_scl, 0.0, -1, 0U, !*chartInstance->c4_scl))) {
    if (CV_EML_COND(11, 0, 1, CV_RELATIONAL_EVAL(5U, 11U, 1, (real_T)
          *chartInstance->c4_rw, 1.0, -1, 0U, (int32_T)*chartInstance->c4_rw)))
    {
      CV_EML_MCDC(11, 0, 0, true);
      CV_EML_IF(11, 0, 0, true);
      c4_out = true;
    } else {
      guard1 = true;
    }
  } else {
    if (!chartInstance->c4_dataWrittenToVector[4U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(5U, 5U, 11U, *chartInstance->c4_sfEvent,
        false);
    }

    guard1 = true;
  }

  if (guard1) {
    CV_EML_MCDC(11, 0, 0, false);
    CV_EML_IF(11, 0, 0, false);
    c4_out = false;
  }

  _SFD_SYMBOL_SCOPE_POP();
  if (c4_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, *chartInstance->c4_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, *chartInstance->c4_sfEvent);
    *chartInstance->c4_is_c4_mpu6050_working = c4_IN_senddatastart;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, *chartInstance->c4_sfEvent);
    c4_enter_atomic_senddatastart(chartInstance);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U,
                 *chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_ab_debug_family_names,
      c4_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 0U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 1U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_out, 2U, c4_c_sf_marshallOut,
      c4_c_sf_marshallIn);
    guard1 = false;
    if (CV_EML_COND(7, 0, 0, *chartInstance->c4_scl)) {
      if (CV_EML_COND(7, 0, 1, !*chartInstance->c4_rw)) {
        CV_EML_MCDC(7, 0, 0, true);
        CV_EML_IF(7, 0, 0, true);
        c4_b_out = true;
      } else {
        guard1 = true;
      }
    } else {
      if (!chartInstance->c4_dataWrittenToVector[4U]) {
        _SFD_DATA_READ_BEFORE_WRITE_ERROR(5U, 5U, 7U, *chartInstance->c4_sfEvent,
          false);
      }

      guard1 = true;
    }

    if (guard1) {
      CV_EML_MCDC(7, 0, 0, false);
      CV_EML_IF(7, 0, 0, false);
      c4_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c4_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, *chartInstance->c4_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_bb_debug_family_names,
        c4_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargin, 0U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargout, 1U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      *chartInstance->c4_rd_cnt = 0U;
      chartInstance->c4_dataWrittenToVector[6U] = true;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_rd_cnt, 3U, 5U, 7U,
                            *chartInstance->c4_sfEvent, false);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, *chartInstance->c4_sfEvent);
      *chartInstance->c4_is_c4_mpu6050_working = c4_IN_getdatastart;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, *chartInstance->c4_sfEvent);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 12U,
                   *chartInstance->c4_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, *chartInstance->c4_sfEvent);
}

static void c4_enter_atomic_senddatastart(SFc4_mpu6050_workingInstanceStruct
  *chartInstance)
{
  uint32_T c4_debug_family_var_map[2];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 0.0;
  uint8_T c4_hoistedGlobal;
  uint8_T c4_b_hoistedGlobal;
  uint32_T c4_u4;
  uint8_T c4_reg;
  uint32_T c4_b_debug_family_var_map[4];
  real_T c4_b_nargin = 1.0;
  real_T c4_b_nargout = 1.0;
  real_T c4_regdata;
  boolean_T c4_sf_internal_predicateOutput;
  uint32_T c4_u5;
  uint32_T c4_u6;
  real_T c4_u;
  real_T c4_v;
  uint32_T c4_u7;
  real_T c4_d6;
  uint8_T c4_u8;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  boolean_T guard5 = false;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_h_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  if (!chartInstance->c4_dataWrittenToVector[5U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 15U, *chartInstance->c4_sfEvent,
      false);
  }

  if (!chartInstance->c4_dataWrittenToVector[6U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 15U, *chartInstance->c4_sfEvent,
      false);
  }

  c4_hoistedGlobal = *chartInstance->c4_reg_idx;
  c4_b_hoistedGlobal = *chartInstance->c4_rd_cnt;
  c4_u4 = (uint32_T)c4_hoistedGlobal + (uint32_T)c4_b_hoistedGlobal;
  if (CV_SATURATION_EVAL(4, 15, 1, 0, c4_u4 > 255U)) {
    c4_u4 = 255U;
  }

  c4_reg = (uint8_T)c4_u4;
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 16U, *chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c4_i_debug_family_names,
    c4_b_debug_family_var_map);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 16U, *chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_reg, 2U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_regdata, 3U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, *chartInstance->c4_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 15U, *chartInstance->c4_sfEvent);
  c4_sf_internal_predicateOutput = CV_EML_IF(15, 0, 0, c4_reg ==
    chartInstance->c4_AccelXRegAddr);
  guard1 = false;
  guard2 = false;
  guard3 = false;
  guard4 = false;
  guard5 = false;
  if (c4_sf_internal_predicateOutput) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, *chartInstance->c4_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, *chartInstance->c4_sfEvent);
    c4_regdata = 210.0;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 20U, *chartInstance->c4_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 22U, *chartInstance->c4_sfEvent);
    guard5 = true;
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 18U, *chartInstance->c4_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 19U,
                 *chartInstance->c4_sfEvent);
    c4_sf_internal_predicateOutput = CV_EML_IF(19, 0, 0, c4_reg ==
      chartInstance->c4_AccelYRegAddr);
    if (c4_sf_internal_predicateOutput) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 19U, *chartInstance->c4_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 17U, *chartInstance->c4_sfEvent);
      c4_regdata = 225.0;
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 21U, *chartInstance->c4_sfEvent);
      guard5 = true;
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, *chartInstance->c4_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 25U,
                   *chartInstance->c4_sfEvent);
      c4_sf_internal_predicateOutput = CV_EML_IF(25, 0, 0, c4_reg ==
        chartInstance->c4_AccelZRegAddr);
      if (c4_sf_internal_predicateOutput) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 25U, *chartInstance->c4_sfEvent);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 23U, *chartInstance->c4_sfEvent);
        c4_regdata = 46.0;
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 26U, *chartInstance->c4_sfEvent);
        guard4 = true;
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 27U, *chartInstance->c4_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 34U,
                     *chartInstance->c4_sfEvent);
        c4_u5 = (uint32_T)chartInstance->c4_AccelXRegAddr + 1U;
        if (CV_SATURATION_EVAL(5, 34, 0, 0, c4_u5 > 255U)) {
          c4_u5 = 255U;
        }

        c4_sf_internal_predicateOutput = CV_EML_IF(34, 0, 0, c4_reg == (uint8_T)
          c4_u5);
        if (c4_sf_internal_predicateOutput) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 34U, *chartInstance->c4_sfEvent);
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 38U, *chartInstance->c4_sfEvent);
          c4_regdata = 4.0;
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 40U, *chartInstance->c4_sfEvent);
          guard3 = true;
        } else {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 42U, *chartInstance->c4_sfEvent);
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 43U,
                       *chartInstance->c4_sfEvent);
          c4_u6 = (uint32_T)chartInstance->c4_AccelYRegAddr + 1U;
          if (CV_SATURATION_EVAL(5, 43, 0, 0, c4_u6 > 255U)) {
            c4_u6 = 255U;
          }

          c4_sf_internal_predicateOutput = CV_EML_IF(43, 0, 0, c4_reg ==
            (uint8_T)c4_u6);
          if (c4_sf_internal_predicateOutput) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 43U, *chartInstance->c4_sfEvent);
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 35U, *chartInstance->c4_sfEvent);
            c4_regdata = 255.0;
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 46U, *chartInstance->c4_sfEvent);
            guard2 = true;
          } else {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 39U, *chartInstance->c4_sfEvent);
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 44U,
                         *chartInstance->c4_sfEvent);
            c4_u7 = (uint32_T)chartInstance->c4_AccelZRegAddr + 1U;
            if (CV_SATURATION_EVAL(5, 44, 0, 0, c4_u7 > 255U)) {
              c4_u7 = 255U;
            }

            c4_sf_internal_predicateOutput = CV_EML_IF(44, 0, 0, c4_reg ==
              (uint8_T)c4_u7);
            if (c4_sf_internal_predicateOutput) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 44U,
                           *chartInstance->c4_sfEvent);
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 41U,
                           *chartInstance->c4_sfEvent);
              c4_regdata = 22.0;
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 36U,
                           *chartInstance->c4_sfEvent);
              guard1 = true;
            } else {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 60U,
                           *chartInstance->c4_sfEvent);
              _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 57U,
                           *chartInstance->c4_sfEvent);
              c4_sf_internal_predicateOutput = CV_EML_IF(57, 0, 0, c4_reg ==
                chartInstance->c4_powerRegAddr);
              if (c4_sf_internal_predicateOutput) {
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 57U,
                             *chartInstance->c4_sfEvent);
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 59U,
                             *chartInstance->c4_sfEvent);
                c4_regdata = 254.0;
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 56U,
                             *chartInstance->c4_sfEvent);
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 37U,
                             *chartInstance->c4_sfEvent);
              } else {
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 45U,
                             *chartInstance->c4_sfEvent);
                c4_regdata = 229.0;
              }
            }
          }
        }
      }
    }
  }

  if (guard5) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 24U, *chartInstance->c4_sfEvent);
    guard4 = true;
  }

  if (guard4) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 49U, *chartInstance->c4_sfEvent);
    guard3 = true;
  }

  if (guard3) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 48U, *chartInstance->c4_sfEvent);
    guard2 = true;
  }

  if (guard2) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 47U, *chartInstance->c4_sfEvent);
    guard1 = true;
  }

  if (guard1) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 58U, *chartInstance->c4_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 37U, *chartInstance->c4_sfEvent);
  }

  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 16U, *chartInstance->c4_sfEvent);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, *chartInstance->c4_sfEvent);
  c4_u = c4_regdata;
  c4_v = muDoubleScalarAbs(c4_u);
  if (c4_v < 4.503599627370496E+15) {
    if (c4_v >= 0.5) {
      c4_d6 = muDoubleScalarFloor(c4_u + 0.5);
    } else {
      c4_d6 = c4_u * 0.0;
    }
  } else {
    c4_d6 = c4_u;
  }

  if (c4_d6 < 256.0) {
    if (CV_SATURATION_EVAL(4, 15, 0, 1, c4_d6 >= 0.0)) {
      c4_u8 = (uint8_T)c4_d6;
    } else {
      c4_u8 = 0U;
    }
  } else if (CV_SATURATION_EVAL(4, 15, 0, 0, c4_d6 >= 256.0)) {
    c4_u8 = MAX_uint8_T;
  } else {
    c4_u8 = 0U;
  }

  *chartInstance->c4_data = c4_u8;
  chartInstance->c4_dataWrittenToVector[3U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_data, 2U, 4U, 15U,
                        *chartInstance->c4_sfEvent, false);
  *chartInstance->c4_bit_idx = 8U;
  chartInstance->c4_dataWrittenToVector[2U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_bit_idx, 1U, 4U, 15U,
                        *chartInstance->c4_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_senddatastart(SFc4_mpu6050_workingInstanceStruct *chartInstance)
{
  uint32_T c4_debug_family_var_map[2];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 0.0;
  uint8_T c4_hoistedGlobal;
  uint8_T c4_b_hoistedGlobal;
  uint8_T c4_a;
  uint8_T c4_bit;
  uint8_T c4_bit1;
  uint32_T c4_q0;
  uint8_T c4_c;
  uint32_T c4_qY;
  uint32_T c4_u9;
  uint8_T c4_b_bit_idx;
  uint8_T c4_slice_temp;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 28U, *chartInstance->c4_sfEvent);
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, *chartInstance->c4_sfEvent);
  *chartInstance->c4_is_c4_mpu6050_working = c4_IN_sendbyte;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, *chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_j_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  if (!chartInstance->c4_dataWrittenToVector[3U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 14U, *chartInstance->c4_sfEvent,
      false);
  }

  if (!chartInstance->c4_dataWrittenToVector[2U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 14U, *chartInstance->c4_sfEvent,
      false);
  }

  c4_hoistedGlobal = *chartInstance->c4_data;
  c4_b_hoistedGlobal = *chartInstance->c4_bit_idx;
  c4_a = c4_hoistedGlobal;
  c4_bit = c4_b_hoistedGlobal;
  if (((real_T)c4_bit >= 1.0) && ((real_T)c4_bit <= 8.0)) {
    c4_bit1 = c4_bit;
    c4_q0 = c4_bit1;
    c4_qY = c4_q0 - 1U;
    if (CV_SATURATION_EVAL(4, 14, 0, 0, c4_qY > c4_q0)) {
      c4_qY = 0U;
    }

    c4_u9 = c4_qY;
    if (CV_SATURATION_EVAL(4, 14, 0, 0, c4_u9 > 255U)) {
      c4_u9 = 255U;
    }

    c4_b_bit_idx = (uint8_T)c4_u9;
    c4_slice_temp = (uint8_T)((uint8_T)((uint32_T)c4_a >> c4_b_bit_idx) & 1U);
    c4_c = c4_slice_temp;
  } else {
    c4_error(chartInstance, 8);
  }

  *chartInstance->c4_sda_out = (c4_c != 0);
  chartInstance->c4_dataWrittenToVector[0U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_sda_out, 8U, 4U, 14U,
                        *chartInstance->c4_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 15U, *chartInstance->c4_sfEvent);
}

static void c4_getdatastart(SFc4_mpu6050_workingInstanceStruct *chartInstance)
{
  uint32_T c4_debug_family_var_map[3];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 1.0;
  boolean_T c4_out;
  uint32_T c4_b_debug_family_var_map[2];
  real_T c4_b_nargin = 0.0;
  real_T c4_b_nargout = 0.0;
  uint8_T c4_hoistedGlobal;
  uint8_T c4_b_hoistedGlobal;
  uint8_T c4_a;
  uint8_T c4_bit;
  uint8_T c4_bit1;
  uint32_T c4_q0;
  uint32_T c4_b_q0;
  uint32_T c4_qY;
  uint8_T c4_c;
  uint32_T c4_b_qY;
  uint32_T c4_u10;
  uint32_T c4_u11;
  uint8_T c4_b_bit_idx;
  uint8_T c4_mask;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U, *chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_hb_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  c4_out = CV_EML_IF(8, 0, 0, CV_RELATIONAL_EVAL(5U, 8U, 0, (real_T)
    *chartInstance->c4_scl, 1.0, -1, 0U, (int32_T)*chartInstance->c4_scl));
  _SFD_SYMBOL_SCOPE_POP();
  if (c4_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, *chartInstance->c4_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, *chartInstance->c4_sfEvent);
    *chartInstance->c4_is_c4_mpu6050_working = c4_IN_getdata;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, *chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_k_debug_family_names,
      c4_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 0U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 1U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    if (CV_EML_IF(6, 1, 0, CV_RELATIONAL_EVAL(4U, 6U, 0, (real_T)
          *chartInstance->c4_sda, 1.0, -1, 0U, (int32_T)*chartInstance->c4_sda)))
    {
      c4_hoistedGlobal = *chartInstance->c4_data;
      c4_b_hoistedGlobal = *chartInstance->c4_bit_idx;
      c4_a = c4_hoistedGlobal;
      c4_bit = c4_b_hoistedGlobal;
      if (((real_T)c4_bit >= 1.0) && ((real_T)c4_bit <= 8.0)) {
        c4_bit1 = c4_bit;
        c4_b_q0 = c4_bit1;
        c4_b_qY = c4_b_q0 - 1U;
        if (CV_SATURATION_EVAL(4, 6, 0, 0, c4_b_qY > c4_b_q0)) {
          c4_b_qY = 0U;
        }

        c4_u11 = c4_b_qY;
        if (CV_SATURATION_EVAL(4, 6, 0, 0, c4_u11 > 255U)) {
          c4_u11 = 255U;
        }

        c4_b_bit_idx = (uint8_T)c4_u11;
        c4_mask = (uint8_T)(1 << (uint8_T)sf_eml_shift_index_bounds_check
                            (sfGlobalDebugInstanceStruct, chartInstance->S, 32U,
                             38, 20, "", (int32_T)c4_b_bit_idx, 0, 7));
        c4_c = (uint8_T)(c4_a | c4_mask);
      } else {
        c4_error(chartInstance, 8);
      }

      *chartInstance->c4_data = c4_c;
      chartInstance->c4_dataWrittenToVector[3U] = true;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_data, 2U, 4U, 6U,
                            *chartInstance->c4_sfEvent, false);
    } else {
      if (!chartInstance->c4_dataWrittenToVector[2U]) {
        _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 6U, *chartInstance->c4_sfEvent,
          false);
      }

      if (!chartInstance->c4_dataWrittenToVector[3U]) {
        _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 6U, *chartInstance->c4_sfEvent,
          false);
      }
    }

    if (!chartInstance->c4_dataWrittenToVector[2U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 6U, *chartInstance->c4_sfEvent,
        false);
    }

    c4_q0 = *chartInstance->c4_bit_idx;
    c4_qY = c4_q0 - 1U;
    if (CV_SATURATION_EVAL(4, 6, 1, 0, c4_qY > c4_q0)) {
      c4_qY = 0U;
    }

    c4_u10 = c4_qY;
    if (CV_SATURATION_EVAL(4, 6, 1, 0, c4_u10 > 255U)) {
      c4_u10 = 255U;
    }

    *chartInstance->c4_bit_idx = (uint8_T)c4_u10;
    chartInstance->c4_dataWrittenToVector[2U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_bit_idx, 1U, 4U, 6U,
                          *chartInstance->c4_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U, *chartInstance->c4_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, *chartInstance->c4_sfEvent);
}

static void c4_sendbyte(SFc4_mpu6050_workingInstanceStruct *chartInstance)
{
  uint32_T c4_debug_family_var_map[3];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 1.0;
  boolean_T c4_out;
  uint32_T c4_b_debug_family_var_map[2];
  real_T c4_b_nargin = 0.0;
  real_T c4_b_nargout = 0.0;
  uint32_T c4_q0;
  uint32_T c4_qY;
  uint32_T c4_u12;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 29U, *chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_jb_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  c4_out = CV_EML_IF(29, 0, 0, CV_RELATIONAL_EVAL(5U, 29U, 0, (real_T)
    *chartInstance->c4_scl, 1.0, -1, 0U, (int32_T)*chartInstance->c4_scl));
  _SFD_SYMBOL_SCOPE_POP();
  if (c4_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 29U, *chartInstance->c4_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, *chartInstance->c4_sfEvent);
    *chartInstance->c4_is_c4_mpu6050_working = c4_IN_sendbit;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, *chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_l_debug_family_names,
      c4_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 0U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 1U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    if (!chartInstance->c4_dataWrittenToVector[2U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 13U, *chartInstance->c4_sfEvent,
        false);
    }

    c4_q0 = *chartInstance->c4_bit_idx;
    c4_qY = c4_q0 - 1U;
    if (CV_SATURATION_EVAL(4, 13, 0, 0, c4_qY > c4_q0)) {
      c4_qY = 0U;
    }

    c4_u12 = c4_qY;
    if (CV_SATURATION_EVAL(4, 13, 0, 0, c4_u12 > 255U)) {
      c4_u12 = 255U;
    }

    *chartInstance->c4_bit_idx = (uint8_T)c4_u12;
    chartInstance->c4_dataWrittenToVector[2U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_bit_idx, 1U, 4U, 13U,
                          *chartInstance->c4_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 14U,
                 *chartInstance->c4_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, *chartInstance->c4_sfEvent);
}

static void c4_getdata(SFc4_mpu6050_workingInstanceStruct *chartInstance)
{
  uint32_T c4_debug_family_var_map[3];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 1.0;
  boolean_T c4_out;
  real_T c4_b_nargin = 0.0;
  real_T c4_b_nargout = 1.0;
  boolean_T c4_b_out;
  uint32_T c4_b_debug_family_var_map[2];
  real_T c4_c_nargin = 0.0;
  real_T c4_c_nargout = 0.0;
  uint8_T c4_hoistedGlobal;
  uint8_T c4_A;
  uint8_T c4_xfi;
  uint8_T c4_b_hoistedGlobal;
  const mxArray *c4_y = NULL;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 9U, *chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_gb_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  if (!chartInstance->c4_dataWrittenToVector[2U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 5U, 9U, *chartInstance->c4_sfEvent,
      false);
  }

  c4_out = CV_EML_IF(9, 0, 0, CV_RELATIONAL_EVAL(5U, 9U, 0, (real_T)
    *chartInstance->c4_bit_idx, 0.0, -1, 4U, (real_T)*chartInstance->c4_bit_idx >
    0.0));
  _SFD_SYMBOL_SCOPE_POP();
  if (c4_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, *chartInstance->c4_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, *chartInstance->c4_sfEvent);
    *chartInstance->c4_is_c4_mpu6050_working = c4_IN_getdatastart;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, *chartInstance->c4_sfEvent);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 10U,
                 *chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_nb_debug_family_names,
      c4_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 0U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 1U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_out, 2U, c4_c_sf_marshallOut,
      c4_c_sf_marshallIn);
    c4_b_out = CV_EML_IF(10, 0, 0, CV_RELATIONAL_EVAL(5U, 10U, 0, (real_T)
      *chartInstance->c4_scl, 1.0, -1, 0U, (int32_T)*chartInstance->c4_scl));
    _SFD_SYMBOL_SCOPE_POP();
    if (c4_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, *chartInstance->c4_sfEvent);
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, *chartInstance->c4_sfEvent);
      *chartInstance->c4_is_c4_mpu6050_working = c4_IN_endgetdata;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, *chartInstance->c4_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_m_debug_family_names,
        c4_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargin, 0U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargout, 1U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      if (!chartInstance->c4_dataWrittenToVector[3U]) {
        _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 2U, *chartInstance->c4_sfEvent,
          false);
      }

      c4_hoistedGlobal = *chartInstance->c4_data;
      c4_A = c4_hoistedGlobal;
      c4_xfi = c4_A;
      *chartInstance->c4_reg_idx = c4_xfi;
      chartInstance->c4_dataWrittenToVector[5U] = true;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_reg_idx, 4U, 4U, 2U,
                            *chartInstance->c4_sfEvent, false);
      if (!chartInstance->c4_dataWrittenToVector[5U]) {
        _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 2U, *chartInstance->c4_sfEvent,
          false);
      }

      sf_mex_printf("%s =\\n", "reg_idx");
      c4_b_hoistedGlobal = *chartInstance->c4_reg_idx;
      c4_y = NULL;
      sf_mex_assign(&c4_y, sf_mex_create("y", &c4_b_hoistedGlobal, 3, 0U, 0U, 0U,
        0), false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c4_y);
      *chartInstance->c4_sda_out = false;
      chartInstance->c4_dataWrittenToVector[0U] = true;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_sda_out, 8U, 4U, 2U,
                            *chartInstance->c4_sfEvent, false);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U,
                   *chartInstance->c4_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, *chartInstance->c4_sfEvent);
}

static void c4_sendbit(SFc4_mpu6050_workingInstanceStruct *chartInstance)
{
  uint32_T c4_debug_family_var_map[3];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 1.0;
  boolean_T c4_out;
  real_T c4_b_nargin = 0.0;
  real_T c4_b_nargout = 1.0;
  boolean_T c4_b_out;
  uint32_T c4_b_debug_family_var_map[2];
  real_T c4_c_nargin = 0.0;
  real_T c4_c_nargout = 0.0;
  uint8_T c4_hoistedGlobal;
  uint8_T c4_b_hoistedGlobal;
  uint8_T c4_a;
  uint8_T c4_bit;
  uint8_T c4_bit1;
  uint32_T c4_q0;
  uint8_T c4_c;
  uint32_T c4_qY;
  uint32_T c4_u13;
  uint8_T c4_b_bit_idx;
  uint8_T c4_slice_temp;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 30U, *chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_ib_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  if (!chartInstance->c4_dataWrittenToVector[2U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 5U, 30U, *chartInstance->c4_sfEvent,
      false);
  }

  c4_out = CV_EML_IF(30, 0, 0, CV_RELATIONAL_EVAL(5U, 30U, 0, (real_T)
    *chartInstance->c4_bit_idx, 0.0, -1, 4U, (real_T)*chartInstance->c4_bit_idx >
    0.0));
  _SFD_SYMBOL_SCOPE_POP();
  if (c4_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 30U, *chartInstance->c4_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, *chartInstance->c4_sfEvent);
    *chartInstance->c4_is_c4_mpu6050_working = c4_IN_sendbyte;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, *chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_j_debug_family_names,
      c4_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargin, 0U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargout, 1U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    if (!chartInstance->c4_dataWrittenToVector[3U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 14U, *chartInstance->c4_sfEvent,
        false);
    }

    if (!chartInstance->c4_dataWrittenToVector[2U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 14U, *chartInstance->c4_sfEvent,
        false);
    }

    c4_hoistedGlobal = *chartInstance->c4_data;
    c4_b_hoistedGlobal = *chartInstance->c4_bit_idx;
    c4_a = c4_hoistedGlobal;
    c4_bit = c4_b_hoistedGlobal;
    if (((real_T)c4_bit >= 1.0) && ((real_T)c4_bit <= 8.0)) {
      c4_bit1 = c4_bit;
      c4_q0 = c4_bit1;
      c4_qY = c4_q0 - 1U;
      if (CV_SATURATION_EVAL(4, 14, 0, 0, c4_qY > c4_q0)) {
        c4_qY = 0U;
      }

      c4_u13 = c4_qY;
      if (CV_SATURATION_EVAL(4, 14, 0, 0, c4_u13 > 255U)) {
        c4_u13 = 255U;
      }

      c4_b_bit_idx = (uint8_T)c4_u13;
      c4_slice_temp = (uint8_T)((uint8_T)((uint32_T)c4_a >> c4_b_bit_idx) & 1U);
      c4_c = c4_slice_temp;
    } else {
      c4_error(chartInstance, 8);
    }

    *chartInstance->c4_sda_out = (c4_c != 0);
    chartInstance->c4_dataWrittenToVector[0U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_sda_out, 8U, 4U, 14U,
                          *chartInstance->c4_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 31U,
                 *chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_ob_debug_family_names,
      c4_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 0U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 1U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_out, 2U, c4_c_sf_marshallOut,
      c4_c_sf_marshallIn);
    c4_b_out = CV_EML_IF(31, 0, 0, CV_RELATIONAL_EVAL(5U, 31U, 0, (real_T)
      *chartInstance->c4_scl, 0.0, -1, 0U, !*chartInstance->c4_scl));
    _SFD_SYMBOL_SCOPE_POP();
    if (c4_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 31U, *chartInstance->c4_sfEvent);
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, *chartInstance->c4_sfEvent);
      *chartInstance->c4_is_c4_mpu6050_working = c4_IN_waitstop1;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 22U, *chartInstance->c4_sfEvent);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 13U,
                   *chartInstance->c4_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, *chartInstance->c4_sfEvent);
}

static void c4_endgetdata(SFc4_mpu6050_workingInstanceStruct *chartInstance)
{
  uint32_T c4_debug_family_var_map[3];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 1.0;
  boolean_T c4_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 68U, *chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_pb_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  c4_out = CV_EML_IF(68, 0, 0, CV_RELATIONAL_EVAL(5U, 68U, 0, (real_T)
    *chartInstance->c4_scl, 1.0, -1, 0U, (int32_T)*chartInstance->c4_scl));
  _SFD_SYMBOL_SCOPE_POP();
  if (c4_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 68U, *chartInstance->c4_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c4_sfEvent);
    *chartInstance->c4_is_c4_mpu6050_working = c4_IN_waitforPos;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 21U, *chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U, *chartInstance->c4_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, *chartInstance->c4_sfEvent);
}

static void c4_lookRestart(SFc4_mpu6050_workingInstanceStruct *chartInstance)
{
  uint32_T c4_debug_family_var_map[3];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 1.0;
  boolean_T c4_out;
  real_T c4_b_nargin = 0.0;
  real_T c4_b_nargout = 1.0;
  boolean_T c4_b_out;
  real_T c4_c_nargin = 0.0;
  real_T c4_c_nargout = 1.0;
  boolean_T c4_c_out;
  uint32_T c4_b_debug_family_var_map[2];
  real_T c4_d_nargin = 0.0;
  real_T c4_d_nargout = 0.0;
  real_T c4_e_nargin = 0.0;
  real_T c4_e_nargout = 0.0;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 12U, *chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_mb_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  c4_out = CV_EML_IF(12, 0, 0, CV_RELATIONAL_EVAL(5U, 12U, 0, (real_T)
    *chartInstance->c4_sda, 0.0, -1, 0U, !*chartInstance->c4_sda));
  _SFD_SYMBOL_SCOPE_POP();
  if (c4_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, *chartInstance->c4_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 64U,
                 *chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_r_debug_family_names,
      c4_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 0U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 1U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_out, 2U, c4_c_sf_marshallOut,
      c4_c_sf_marshallIn);
    c4_b_out = CV_EML_IF(64, 0, 0, CV_RELATIONAL_EVAL(5U, 64U, 0, (real_T)
      *chartInstance->c4_scl, 1.0, -1, 0U, (int32_T)*chartInstance->c4_scl));
    _SFD_SYMBOL_SCOPE_POP();
    if (c4_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 64U, *chartInstance->c4_sfEvent);
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, *chartInstance->c4_sfEvent);
      *chartInstance->c4_is_c4_mpu6050_working = c4_IN_start;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, *chartInstance->c4_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_c_debug_family_names,
        c4_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_nargin, 0U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_nargout, 1U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      *chartInstance->c4_bit_idx = 7U;
      chartInstance->c4_dataWrittenToVector[2U] = true;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_bit_idx, 1U, 4U, 17U,
                            *chartInstance->c4_sfEvent, false);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 65U,
                   *chartInstance->c4_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_kb_debug_family_names,
        c4_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargin, 0U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargout, 1U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_out, 2U, c4_c_sf_marshallOut,
        c4_c_sf_marshallIn);
      c4_c_out = CV_EML_IF(65, 0, 0, !*chartInstance->c4_scl);
      _SFD_SYMBOL_SCOPE_POP();
      if (c4_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 65U, *chartInstance->c4_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_lb_debug_family_names,
          c4_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_e_nargin, 0U, c4_sf_marshallOut,
          c4_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_e_nargout, 1U,
          c4_sf_marshallOut, c4_sf_marshallIn);
        *chartInstance->c4_bit_idx = 8U;
        chartInstance->c4_dataWrittenToVector[2U] = true;
        _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_bit_idx, 1U, 5U, 65U,
                              *chartInstance->c4_sfEvent, false);
        *chartInstance->c4_data = 0U;
        chartInstance->c4_dataWrittenToVector[3U] = true;
        _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_data, 2U, 5U, 65U,
                              *chartInstance->c4_sfEvent, false);
        _SFD_SYMBOL_SCOPE_POP();
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, *chartInstance->c4_sfEvent);
        *chartInstance->c4_is_c4_mpu6050_working = c4_IN_getcfgdata;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, *chartInstance->c4_sfEvent);
        c4_enter_atomic_getcfgdata(chartInstance);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 10U,
                     *chartInstance->c4_sfEvent);
      }
    }
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 10U,
                 *chartInstance->c4_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, *chartInstance->c4_sfEvent);
}

static void c4_getcfgregstart(SFc4_mpu6050_workingInstanceStruct *chartInstance)
{
  uint32_T c4_debug_family_var_map[3];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 1.0;
  boolean_T c4_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 53U, *chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_vb_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  c4_out = CV_EML_IF(53, 0, 0, CV_RELATIONAL_EVAL(5U, 53U, 0, (real_T)
    *chartInstance->c4_scl, 1.0, -1, 0U, (int32_T)*chartInstance->c4_scl));
  _SFD_SYMBOL_SCOPE_POP();
  if (c4_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 53U, *chartInstance->c4_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, *chartInstance->c4_sfEvent);
    *chartInstance->c4_is_c4_mpu6050_working = c4_IN_getcfgdata;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, *chartInstance->c4_sfEvent);
    c4_enter_atomic_getcfgdata(chartInstance);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U, *chartInstance->c4_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, *chartInstance->c4_sfEvent);
}

static void c4_sendAck(SFc4_mpu6050_workingInstanceStruct *chartInstance)
{
  uint32_T c4_debug_family_var_map[3];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 1.0;
  boolean_T c4_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 67U, *chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_tb_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  c4_out = CV_EML_IF(67, 0, 0, CV_RELATIONAL_EVAL(5U, 67U, 0, (real_T)
    *chartInstance->c4_scl, 1.0, -1, 0U, (int32_T)*chartInstance->c4_scl));
  _SFD_SYMBOL_SCOPE_POP();
  if (c4_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 67U, *chartInstance->c4_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, *chartInstance->c4_sfEvent);
    *chartInstance->c4_is_c4_mpu6050_working = c4_IN_waitEndOfAck;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, *chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 11U,
                 *chartInstance->c4_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, *chartInstance->c4_sfEvent);
}

static void c4_enter_atomic_getcfgdata(SFc4_mpu6050_workingInstanceStruct
  *chartInstance)
{
  uint32_T c4_debug_family_var_map[2];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 0.0;
  uint8_T c4_hoistedGlobal;
  uint8_T c4_b_hoistedGlobal;
  uint8_T c4_a;
  uint8_T c4_bit;
  uint8_T c4_bit1;
  uint32_T c4_q0;
  uint32_T c4_b_q0;
  uint32_T c4_qY;
  uint8_T c4_c;
  uint32_T c4_b_qY;
  uint32_T c4_u14;
  uint32_T c4_u15;
  uint8_T c4_b_bit_idx;
  uint8_T c4_mask;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_o_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  if (CV_EML_IF(4, 1, 0, CV_RELATIONAL_EVAL(4U, 4U, 0, (real_T)
        *chartInstance->c4_sda, 1.0, -1, 0U, (int32_T)*chartInstance->c4_sda)))
  {
    c4_hoistedGlobal = *chartInstance->c4_data;
    c4_b_hoistedGlobal = *chartInstance->c4_bit_idx;
    c4_a = c4_hoistedGlobal;
    c4_bit = c4_b_hoistedGlobal;
    if (((real_T)c4_bit >= 1.0) && ((real_T)c4_bit <= 8.0)) {
      c4_bit1 = c4_bit;
      c4_b_q0 = c4_bit1;
      c4_b_qY = c4_b_q0 - 1U;
      if (CV_SATURATION_EVAL(4, 4, 0, 0, c4_b_qY > c4_b_q0)) {
        c4_b_qY = 0U;
      }

      c4_u15 = c4_b_qY;
      if (CV_SATURATION_EVAL(4, 4, 0, 0, c4_u15 > 255U)) {
        c4_u15 = 255U;
      }

      c4_b_bit_idx = (uint8_T)c4_u15;
      c4_mask = (uint8_T)(1 << (uint8_T)sf_eml_shift_index_bounds_check
                          (sfGlobalDebugInstanceStruct, chartInstance->S, 180U,
                           41, 20, "", (int32_T)c4_b_bit_idx, 0, 7));
      c4_c = (uint8_T)(c4_a | c4_mask);
    } else {
      c4_error(chartInstance, 8);
    }

    *chartInstance->c4_data = c4_c;
    chartInstance->c4_dataWrittenToVector[3U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_data, 2U, 4U, 4U,
                          *chartInstance->c4_sfEvent, false);
  } else {
    if (!chartInstance->c4_dataWrittenToVector[2U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 4U, *chartInstance->c4_sfEvent,
        false);
    }

    if (!chartInstance->c4_dataWrittenToVector[3U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 4U, *chartInstance->c4_sfEvent,
        false);
    }
  }

  if (!chartInstance->c4_dataWrittenToVector[2U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 4U, *chartInstance->c4_sfEvent,
      false);
  }

  c4_q0 = *chartInstance->c4_bit_idx;
  c4_qY = c4_q0 - 1U;
  if (CV_SATURATION_EVAL(4, 4, 1, 0, c4_qY > c4_q0)) {
    c4_qY = 0U;
  }

  c4_u14 = c4_qY;
  if (CV_SATURATION_EVAL(4, 4, 1, 0, c4_u14 > 255U)) {
    c4_u14 = 255U;
  }

  *chartInstance->c4_bit_idx = (uint8_T)c4_u14;
  chartInstance->c4_dataWrittenToVector[2U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_bit_idx, 1U, 4U, 4U,
                        *chartInstance->c4_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_getcfgdata(SFc4_mpu6050_workingInstanceStruct *chartInstance)
{
  uint32_T c4_debug_family_var_map[3];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 1.0;
  boolean_T c4_out;
  uint32_T c4_b_debug_family_var_map[2];
  real_T c4_b_nargin = 0.0;
  real_T c4_b_nargout = 0.0;
  uint8_T c4_hoistedGlobal;
  const mxArray *c4_y = NULL;
  uint8_T c4_u;
  const mxArray *c4_b_y = NULL;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 52U, *chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_ub_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  if (!chartInstance->c4_dataWrittenToVector[2U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 5U, 52U, *chartInstance->c4_sfEvent,
      false);
  }

  c4_out = CV_EML_IF(52, 0, 0, CV_RELATIONAL_EVAL(5U, 52U, 0, (real_T)
    *chartInstance->c4_bit_idx, 0.0, -1, 4U, (real_T)*chartInstance->c4_bit_idx >
    0.0));
  _SFD_SYMBOL_SCOPE_POP();
  if (c4_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 52U, *chartInstance->c4_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, *chartInstance->c4_sfEvent);
    *chartInstance->c4_is_c4_mpu6050_working = c4_IN_getcfgregstart;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, *chartInstance->c4_sfEvent);
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 55U, *chartInstance->c4_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, *chartInstance->c4_sfEvent);
    *chartInstance->c4_is_c4_mpu6050_working = c4_IN_sendAck;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, *chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_n_debug_family_names,
      c4_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 0U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 1U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    *chartInstance->c4_sda_out = false;
    chartInstance->c4_dataWrittenToVector[0U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_sda_out, 8U, 4U, 11U,
                          *chartInstance->c4_sfEvent, false);
    if (!chartInstance->c4_dataWrittenToVector[3U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 11U, *chartInstance->c4_sfEvent,
        false);
    }

    sf_mex_printf("%s =\\n", "data");
    c4_hoistedGlobal = *chartInstance->c4_data;
    c4_y = NULL;
    c4_u = c4_hoistedGlobal;
    c4_b_y = NULL;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_u, 3, 0U, 0U, 0U, 0), false);
    sf_mex_assign(&c4_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
      (c4_eml_mx), 15, "numerictype", 14, sf_mex_dup(c4_b_eml_mx), 15,
      "simulinkarray", 14, c4_b_y, 15, "fimathislocal", 3, false), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c4_y);
    _SFD_SYMBOL_SCOPE_POP();
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, *chartInstance->c4_sfEvent);
}

static void c4_error(SFc4_mpu6050_workingInstanceStruct *chartInstance, int32_T
                     c4_varargin_1)
{
  const mxArray *c4_y = NULL;
  static char_T c4_cv0[36] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'b', 'i', 't', 'S', 'e', 't', 'G', 'e', 't', '_', 'B', 'I',
    'T', 'O', 'u', 't', 'O', 'f', 'R', 'a', 'n', 'g', 'e' };

  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  static char_T c4_cv1[11] = { 'e', 'm', 'b', 'e', 'd', 'd', 'e', 'd', '.', 'f',
    'i' };

  (void)chartInstance;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_cv0, 10, 0U, 1U, 0U, 2, 1, 36),
                false);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_varargin_1, 6, 0U, 0U, 0U, 0),
                false);
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_cv1, 10, 0U, 1U, 0U, 2, 1, 11),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    3U, 14, c4_y, 14, c4_b_y, 14, c4_c_y));
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber)
{
  (void)(c4_machineNumber);
  (void)(c4_chartNumber);
  (void)(c4_instanceNumber);
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_mpu6050_workingInstanceStruct *chartInstance;
  chartInstance = (SFc4_mpu6050_workingInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static real_T c4_emlrt_marshallIn(SFc4_mpu6050_workingInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d7;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d7, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d7;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_nargout;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_mpu6050_workingInstanceStruct *chartInstance;
  chartInstance = (SFc4_mpu6050_workingInstanceStruct *)chartInstanceVoid;
  c4_nargout = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_nargout), &c4_thisId);
  sf_mex_destroy(&c4_nargout);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  uint8_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_mpu6050_workingInstanceStruct *chartInstance;
  chartInstance = (SFc4_mpu6050_workingInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  c4_u = *(uint8_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static uint8_T c4_b_emlrt_marshallIn(SFc4_mpu6050_workingInstanceStruct
  *chartInstance, const mxArray *c4_reg, const char_T *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_reg), &c4_thisId);
  sf_mex_destroy(&c4_reg);
  return c4_y;
}

static uint8_T c4_c_emlrt_marshallIn(SFc4_mpu6050_workingInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  uint8_T c4_u16;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u16, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_u16;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_reg;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  uint8_T c4_y;
  SFc4_mpu6050_workingInstanceStruct *chartInstance;
  chartInstance = (SFc4_mpu6050_workingInstanceStruct *)chartInstanceVoid;
  c4_reg = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_reg), &c4_thisId);
  sf_mex_destroy(&c4_reg);
  *(uint8_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  boolean_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_mpu6050_workingInstanceStruct *chartInstance;
  chartInstance = (SFc4_mpu6050_workingInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  c4_u = *(boolean_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static boolean_T c4_d_emlrt_marshallIn(SFc4_mpu6050_workingInstanceStruct
  *chartInstance, const mxArray *c4_sf_internal_predicateOutput, const char_T
  *c4_identifier)
{
  boolean_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_sf_internal_predicateOutput), &c4_thisId);
  sf_mex_destroy(&c4_sf_internal_predicateOutput);
  return c4_y;
}

static boolean_T c4_e_emlrt_marshallIn(SFc4_mpu6050_workingInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  boolean_T c4_y;
  boolean_T c4_b0;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_b0, 1, 11, 0U, 0, 0U, 0);
  c4_y = c4_b0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_sf_internal_predicateOutput;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  boolean_T c4_y;
  SFc4_mpu6050_workingInstanceStruct *chartInstance;
  chartInstance = (SFc4_mpu6050_workingInstanceStruct *)chartInstanceVoid;
  c4_sf_internal_predicateOutput = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_sf_internal_predicateOutput), &c4_thisId);
  sf_mex_destroy(&c4_sf_internal_predicateOutput);
  *(boolean_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

const mxArray *sf_c4_mpu6050_working_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  sf_mex_assign(&c4_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c4_nameCaptureInfo;
}

static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  int32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_mpu6050_workingInstanceStruct *chartInstance;
  chartInstance = (SFc4_mpu6050_workingInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static int32_T c4_f_emlrt_marshallIn(SFc4_mpu6050_workingInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i3;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i3, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i3;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_sfEvent;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y;
  SFc4_mpu6050_workingInstanceStruct *chartInstance;
  chartInstance = (SFc4_mpu6050_workingInstanceStruct *)chartInstanceVoid;
  c4_b_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent),
    &c4_thisId);
  sf_mex_destroy(&c4_b_sfEvent);
  *(int32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_e_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  uint8_T c4_u;
  const mxArray *c4_y = NULL;
  uint8_T c4_b_u;
  const mxArray *c4_b_y = NULL;
  SFc4_mpu6050_workingInstanceStruct *chartInstance;
  chartInstance = (SFc4_mpu6050_workingInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  if (sf_debug_check_fi_license()) {
    c4_u = *(uint8_T *)c4_inData;
    c4_y = NULL;
    c4_b_u = c4_u;
    c4_b_y = NULL;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_b_u, 3, 0U, 0U, 0U, 0), false);
    sf_mex_assign(&c4_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
      (c4_eml_mx), 15, "numerictype", 14, sf_mex_dup(c4_c_eml_mx), 15,
      "simulinkarray", 14, c4_b_y, 15, "fimathislocal", 3, false), false);
    sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  } else {
    sf_mex_assign(&c4_mxArrayOutData, sf_mex_create("mxArrayOutData",
      "Cannot display value.", 15, 0U, 0U, 0U, 2, 1, strlen(
      "Cannot display value.")), false);
  }

  return c4_mxArrayOutData;
}

static uint8_T c4_g_emlrt_marshallIn(SFc4_mpu6050_workingInstanceStruct
  *chartInstance, const mxArray *c4_b_addr, const char_T *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_addr), &c4_thisId);
  sf_mex_destroy(&c4_b_addr);
  return c4_y;
}

static uint8_T c4_h_emlrt_marshallIn(SFc4_mpu6050_workingInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  const mxArray *c4_mxFi = NULL;
  const mxArray *c4_mxInt = NULL;
  uint8_T c4_u17;
  (void)chartInstance;
  sf_mex_check_fi(c4_parentId, c4_u, false, 0U, NULL, c4_eml_mx, c4_c_eml_mx);
  sf_mex_assign(&c4_mxFi, sf_mex_dup(c4_u), false);
  sf_mex_assign(&c4_mxInt, sf_mex_call("simulinkarray", 1U, 1U, 14, sf_mex_dup
    (c4_mxFi)), false);
  sf_mex_import(c4_parentId, sf_mex_dup(c4_mxInt), &c4_u17, 1, 3, 0U, 0, 0U, 0);
  sf_mex_destroy(&c4_mxFi);
  sf_mex_destroy(&c4_mxInt);
  c4_y = c4_u17;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_addr;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  uint8_T c4_y;
  SFc4_mpu6050_workingInstanceStruct *chartInstance;
  chartInstance = (SFc4_mpu6050_workingInstanceStruct *)chartInstanceVoid;
  if (sf_debug_check_fi_license()) {
    c4_b_addr = sf_mex_dup(c4_mxArrayInData);
    c4_identifier = c4_varName;
    c4_thisId.fIdentifier = (const char *)c4_identifier;
    c4_thisId.fParent = NULL;
    c4_thisId.bParentIsCell = false;
    c4_y = c4_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_addr),
      &c4_thisId);
    sf_mex_destroy(&c4_b_addr);
    *(uint8_T *)c4_outData = c4_y;
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_f_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  uint8_T c4_u;
  const mxArray *c4_y = NULL;
  uint8_T c4_b_u;
  const mxArray *c4_b_y = NULL;
  SFc4_mpu6050_workingInstanceStruct *chartInstance;
  chartInstance = (SFc4_mpu6050_workingInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  if (sf_debug_check_fi_license()) {
    c4_u = *(uint8_T *)c4_inData;
    c4_y = NULL;
    c4_b_u = c4_u;
    c4_b_y = NULL;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_b_u, 3, 0U, 0U, 0U, 0), false);
    sf_mex_assign(&c4_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
      (c4_eml_mx), 15, "numerictype", 14, sf_mex_dup(c4_b_eml_mx), 15,
      "simulinkarray", 14, c4_b_y, 15, "fimathislocal", 3, false), false);
    sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  } else {
    sf_mex_assign(&c4_mxArrayOutData, sf_mex_create("mxArrayOutData",
      "Cannot display value.", 15, 0U, 0U, 0U, 2, 1, strlen(
      "Cannot display value.")), false);
  }

  return c4_mxArrayOutData;
}

static uint8_T c4_i_emlrt_marshallIn(SFc4_mpu6050_workingInstanceStruct
  *chartInstance, const mxArray *c4_b_data, const char_T *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_data), &c4_thisId);
  sf_mex_destroy(&c4_b_data);
  return c4_y;
}

static uint8_T c4_j_emlrt_marshallIn(SFc4_mpu6050_workingInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  const mxArray *c4_mxFi = NULL;
  const mxArray *c4_mxInt = NULL;
  uint8_T c4_u18;
  (void)chartInstance;
  sf_mex_check_fi(c4_parentId, c4_u, false, 0U, NULL, c4_eml_mx, c4_b_eml_mx);
  sf_mex_assign(&c4_mxFi, sf_mex_dup(c4_u), false);
  sf_mex_assign(&c4_mxInt, sf_mex_call("simulinkarray", 1U, 1U, 14, sf_mex_dup
    (c4_mxFi)), false);
  sf_mex_import(c4_parentId, sf_mex_dup(c4_mxInt), &c4_u18, 1, 3, 0U, 0, 0U, 0);
  sf_mex_destroy(&c4_mxFi);
  sf_mex_destroy(&c4_mxInt);
  c4_y = c4_u18;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_data;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  uint8_T c4_y;
  SFc4_mpu6050_workingInstanceStruct *chartInstance;
  chartInstance = (SFc4_mpu6050_workingInstanceStruct *)chartInstanceVoid;
  c4_b_data = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_data), &c4_thisId);
  sf_mex_destroy(&c4_b_data);
  *(uint8_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static void c4_k_emlrt_marshallIn(SFc4_mpu6050_workingInstanceStruct
  *chartInstance, const mxArray *c4_b_dataWrittenToVector, const char_T
  *c4_identifier, boolean_T c4_y[8])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_dataWrittenToVector),
                        &c4_thisId, c4_y);
  sf_mex_destroy(&c4_b_dataWrittenToVector);
}

static void c4_l_emlrt_marshallIn(SFc4_mpu6050_workingInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  boolean_T c4_y[8])
{
  boolean_T c4_bv1[8];
  int32_T c4_i4;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_bv1, 1, 11, 0U, 1, 0U, 1, 8);
  for (c4_i4 = 0; c4_i4 < 8; c4_i4++) {
    c4_y[c4_i4] = c4_bv1[c4_i4];
  }

  sf_mex_destroy(&c4_u);
}

static const mxArray *c4_m_emlrt_marshallIn(SFc4_mpu6050_workingInstanceStruct
  *chartInstance, const mxArray *c4_b_setSimStateSideEffectsInfo, const char_T
  *c4_identifier)
{
  const mxArray *c4_y = NULL;
  emlrtMsgIdentifier c4_thisId;
  c4_y = NULL;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  sf_mex_assign(&c4_y, c4_n_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_setSimStateSideEffectsInfo), &c4_thisId), false);
  sf_mex_destroy(&c4_b_setSimStateSideEffectsInfo);
  return c4_y;
}

static const mxArray *c4_n_emlrt_marshallIn(SFc4_mpu6050_workingInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  const mxArray *c4_y = NULL;
  (void)chartInstance;
  (void)c4_parentId;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_duplicatearraysafe(&c4_u), false);
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static const mxArray *sf_get_hover_data_for_msg
  (SFc4_mpu6050_workingInstanceStruct *chartInstance, int32_T c4_ssid)
{
  const mxArray *c4_msgInfo;
  (void)chartInstance;
  (void)c4_ssid;
  c4_msgInfo = NULL;
  return NULL;
}

static void c4_init_sf_message_store_memory(SFc4_mpu6050_workingInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_dsm_address_info(SFc4_mpu6050_workingInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc4_mpu6050_workingInstanceStruct
  *chartInstance)
{
  chartInstance->c4_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c4_sfEvent = (int32_T *)ssGetDWork_wrapper(chartInstance->S, 0);
  chartInstance->c4_is_active_c4_mpu6050_working = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 1);
  chartInstance->c4_is_c4_mpu6050_working = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 2);
  chartInstance->c4_sda = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c4_scl = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c4_sda_out = (boolean_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c4_addr = (uint8_T *)ssGetDWork_wrapper(chartInstance->S, 3);
  chartInstance->c4_bit_idx = (uint8_T *)ssGetDWork_wrapper(chartInstance->S, 4);
  chartInstance->c4_data = (uint8_T *)ssGetDWork_wrapper(chartInstance->S, 5);
  chartInstance->c4_rw = (boolean_T *)ssGetDWork_wrapper(chartInstance->S, 6);
  chartInstance->c4_reg_idx = (uint8_T *)ssGetDWork_wrapper(chartInstance->S, 7);
  chartInstance->c4_rd_cnt = (uint8_T *)ssGetDWork_wrapper(chartInstance->S, 8);
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
void sf_c4_mpu6050_working_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(177380402U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2817055523U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2333668986U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1941665044U);
}

mxArray* sf_c4_mpu6050_working_get_post_codegen_info(void);
mxArray *sf_c4_mpu6050_working_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("ajrkRtU7nUMEe2oUO8MAjG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(11));

      {
        const char *fixptFields[] = { "isSigned", "wordLength", "bias", "slope",
          "exponent", "isScaledDouble" };

        mxArray *mxFixpt = mxCreateStructMatrix(1,1,6,fixptFields);
        mxSetField(mxFixpt,0,"isSigned",mxCreateDoubleScalar(0));
        mxSetField(mxFixpt,0,"wordLength",mxCreateDoubleScalar(7));
        mxSetField(mxFixpt,0,"bias",mxCreateDoubleScalar(0));
        mxSetField(mxFixpt,0,"slope",mxCreateDoubleScalar(1));
        mxSetField(mxFixpt,0,"exponent",mxCreateDoubleScalar(0));
        mxSetField(mxFixpt,0,"isScaledDouble",mxCreateDoubleScalar(0));
        mxSetField(mxType,0,"fixpt",mxFixpt);
      }

      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(1));
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
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(11));

      {
        const char *fixptFields[] = { "isSigned", "wordLength", "bias", "slope",
          "exponent", "isScaledDouble" };

        mxArray *mxFixpt = mxCreateStructMatrix(1,1,6,fixptFields);
        mxSetField(mxFixpt,0,"isSigned",mxCreateDoubleScalar(0));
        mxSetField(mxFixpt,0,"wordLength",mxCreateDoubleScalar(7));
        mxSetField(mxFixpt,0,"bias",mxCreateDoubleScalar(0));
        mxSetField(mxFixpt,0,"slope",mxCreateDoubleScalar(1));
        mxSetField(mxFixpt,0,"exponent",mxCreateDoubleScalar(0));
        mxSetField(mxFixpt,0,"isScaledDouble",mxCreateDoubleScalar(0));
        mxSetField(mxType,0,"fixpt",mxFixpt);
      }

      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(1));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(11));

      {
        const char *fixptFields[] = { "isSigned", "wordLength", "bias", "slope",
          "exponent", "isScaledDouble" };

        mxArray *mxFixpt = mxCreateStructMatrix(1,1,6,fixptFields);
        mxSetField(mxFixpt,0,"isSigned",mxCreateDoubleScalar(0));
        mxSetField(mxFixpt,0,"wordLength",mxCreateDoubleScalar(8));
        mxSetField(mxFixpt,0,"bias",mxCreateDoubleScalar(0));
        mxSetField(mxFixpt,0,"slope",mxCreateDoubleScalar(1));
        mxSetField(mxFixpt,0,"exponent",mxCreateDoubleScalar(0));
        mxSetField(mxFixpt,0,"isScaledDouble",mxCreateDoubleScalar(0));
        mxSetField(mxType,0,"fixpt",mxFixpt);
      }

      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(1));
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
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  {
    mxArray* mxPostCodegenInfo = sf_c4_mpu6050_working_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c4_mpu6050_working_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c4_mpu6050_working_jit_fallback_info(void)
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

mxArray *sf_c4_mpu6050_working_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c4_mpu6050_working_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c4_mpu6050_working(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[3],T\"sda_out\",},{M[3],M[15],T\"addr\",},{M[3],M[16],T\"bit_idx\",},{M[3],M[31],T\"data\",},{M[3],M[123],T\"rd_cnt\",},{M[3],M[78],T\"reg_idx\",},{M[3],M[37],T\"rw\",},{M[8],M[0],T\"is_active_c4_mpu6050_working\",},{M[9],M[0],T\"is_c4_mpu6050_working\",},{M[15],M[0],T\"dataWrittenToVector\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 10, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_mpu6050_working_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const mxArray* sf_opaque_get_hover_data_for_msg(void* chartInstance,
  int32_T msgSSID)
{
  return sf_get_hover_data_for_msg( (SFc4_mpu6050_workingInstanceStruct *)
    chartInstance, msgSSID);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_mpu6050_workingInstanceStruct *chartInstance =
      (SFc4_mpu6050_workingInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _mpu6050_workingMachineNumber_,
           4,
           23,
           69,
           0,
           16,
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
          _SFD_SET_DATA_PROPS(0,0,0,0,"addr");
          _SFD_SET_DATA_PROPS(1,0,0,0,"bit_idx");
          _SFD_SET_DATA_PROPS(2,0,0,0,"data");
          _SFD_SET_DATA_PROPS(3,0,0,0,"rd_cnt");
          _SFD_SET_DATA_PROPS(4,0,0,0,"reg_idx");
          _SFD_SET_DATA_PROPS(5,0,0,0,"rw");
          _SFD_SET_DATA_PROPS(6,1,1,0,"sda");
          _SFD_SET_DATA_PROPS(7,1,1,0,"scl");
          _SFD_SET_DATA_PROPS(8,2,0,1,"sda_out");
          _SFD_SET_DATA_PROPS(9,8,0,0,"");
          _SFD_SET_DATA_PROPS(10,9,0,0,"");
          _SFD_SET_DATA_PROPS(11,10,0,0,"AccelXRegAddr");
          _SFD_SET_DATA_PROPS(12,10,0,0,"AccelYRegAddr");
          _SFD_SET_DATA_PROPS(13,10,0,0,"AccelZRegAddr");
          _SFD_SET_DATA_PROPS(14,10,0,0,"deviceAddr");
          _SFD_SET_DATA_PROPS(15,10,0,0,"powerRegAddr");
          _SFD_STATE_INFO(0,0,0);
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
          _SFD_STATE_INFO(12,0,0);
          _SFD_STATE_INFO(13,0,0);
          _SFD_STATE_INFO(14,0,0);
          _SFD_STATE_INFO(15,0,0);
          _SFD_STATE_INFO(17,0,0);
          _SFD_STATE_INFO(18,0,0);
          _SFD_STATE_INFO(19,0,0);
          _SFD_STATE_INFO(20,0,0);
          _SFD_STATE_INFO(21,0,0);
          _SFD_STATE_INFO(22,0,0);
          _SFD_STATE_INFO(16,0,2);
          _SFD_CH_SUBSTATE_COUNT(22);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_CH_SUBSTATE_INDEX(2,2);
          _SFD_CH_SUBSTATE_INDEX(3,3);
          _SFD_CH_SUBSTATE_INDEX(4,4);
          _SFD_CH_SUBSTATE_INDEX(5,5);
          _SFD_CH_SUBSTATE_INDEX(6,6);
          _SFD_CH_SUBSTATE_INDEX(7,7);
          _SFD_CH_SUBSTATE_INDEX(8,8);
          _SFD_CH_SUBSTATE_INDEX(9,9);
          _SFD_CH_SUBSTATE_INDEX(10,10);
          _SFD_CH_SUBSTATE_INDEX(11,11);
          _SFD_CH_SUBSTATE_INDEX(12,12);
          _SFD_CH_SUBSTATE_INDEX(13,13);
          _SFD_CH_SUBSTATE_INDEX(14,14);
          _SFD_CH_SUBSTATE_INDEX(15,15);
          _SFD_CH_SUBSTATE_INDEX(16,17);
          _SFD_CH_SUBSTATE_INDEX(17,18);
          _SFD_CH_SUBSTATE_INDEX(18,19);
          _SFD_CH_SUBSTATE_INDEX(19,20);
          _SFD_CH_SUBSTATE_INDEX(20,21);
          _SFD_CH_SUBSTATE_INDEX(21,22);
          _SFD_ST_SUBSTATE_COUNT(0,0);
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
          _SFD_ST_SUBSTATE_COUNT(12,0);
          _SFD_ST_SUBSTATE_COUNT(13,0);
          _SFD_ST_SUBSTATE_COUNT(14,0);
          _SFD_ST_SUBSTATE_COUNT(15,0);
          _SFD_ST_SUBSTATE_COUNT(17,0);
          _SFD_ST_SUBSTATE_COUNT(18,0);
          _SFD_ST_SUBSTATE_COUNT(19,0);
          _SFD_ST_SUBSTATE_COUNT(20,0);
          _SFD_ST_SUBSTATE_COUNT(21,0);
          _SFD_ST_SUBSTATE_COUNT(22,0);
        }

        _SFD_CV_INIT_CHART(22,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

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
          _SFD_CV_INIT_STATE(12,0,0,0,0,0,NULL,NULL);
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
          _SFD_CV_INIT_STATE(16,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(33,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(32,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(61,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(66,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(64,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(51,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(28,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(50,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(62,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(30,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(29,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(65,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(31,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(68,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(63,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(54,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(67,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(52,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(53,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(55,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(15,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(18,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(16,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(20,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(22,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(19,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(17,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(14,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(21,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(24,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(25,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(23,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(27,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(26,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(49,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(34,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(42,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(38,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(40,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(48,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(43,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(35,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(39,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(46,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(47,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(44,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(41,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(60,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(36,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(58,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(57,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(59,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(45,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(56,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(37,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(9,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(8,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(17,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(3,1,0,0,1,0,2,0,0,0,0,0);
        _SFD_CV_INIT_EML_SATURATION(3,1,0,38,-1,58);
        _SFD_CV_INIT_EML_SATURATION(3,1,1,74,-1,85);
        _SFD_CV_INIT_EML_IF(3,1,0,15,26,-1,63);
        _SFD_CV_INIT_EML_RELATIONAL(3,1,0,18,26,-1,0);
        _SFD_CV_INIT_EML(1,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(12,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(15,1,0,0,0,0,2,0,0,0,0,0);
        _SFD_CV_INIT_EML_SATURATION(15,1,0,21,-1,58);
        _SFD_CV_INIT_EML_SATURATION(15,1,1,43,-1,57);
        _SFD_CV_INIT_EML(14,1,0,0,0,0,1,0,0,0,0,0);
        _SFD_CV_INIT_EML_SATURATION(14,1,0,30,-1,50);
        _SFD_CV_INIT_EML(6,1,0,0,1,0,2,0,0,0,0,0);
        _SFD_CV_INIT_EML_SATURATION(6,1,0,38,-1,58);
        _SFD_CV_INIT_EML_SATURATION(6,1,1,74,-1,85);
        _SFD_CV_INIT_EML_IF(6,1,0,15,26,-1,63);
        _SFD_CV_INIT_EML_RELATIONAL(6,1,0,18,26,-1,0);
        _SFD_CV_INIT_EML(13,1,0,0,0,0,1,0,0,0,0,0);
        _SFD_CV_INIT_EML_SATURATION(13,1,0,26,-1,37);
        _SFD_CV_INIT_EML(2,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(10,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(11,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(4,1,0,0,1,0,2,0,0,0,0,0);
        _SFD_CV_INIT_EML_SATURATION(4,1,0,41,-1,61);
        _SFD_CV_INIT_EML_SATURATION(4,1,1,77,-1,88);
        _SFD_CV_INIT_EML_IF(4,1,0,18,29,-1,66);
        _SFD_CV_INIT_EML_RELATIONAL(4,1,0,21,29,-1,0);
        _SFD_CV_INIT_EML(13,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(15,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(15,0,0,1,20,1,20);
        _SFD_CV_INIT_EML(18,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(16,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(20,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(22,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(19,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(19,0,0,1,19,1,19);
        _SFD_CV_INIT_EML(17,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(14,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(21,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(24,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(25,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(25,0,0,1,19,1,19);
        _SFD_CV_INIT_EML(23,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(27,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(26,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(49,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(34,0,0,0,1,0,1,0,0,0,0,0);
        _SFD_CV_INIT_EML_SATURATION(34,0,0,7,-1,22);
        _SFD_CV_INIT_EML_IF(34,0,0,1,22,1,22);
        _SFD_CV_INIT_EML(42,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(38,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(40,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(48,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(43,0,0,0,1,0,1,0,0,0,0,0);
        _SFD_CV_INIT_EML_SATURATION(43,0,0,6,-1,21);
        _SFD_CV_INIT_EML_IF(43,0,0,1,21,1,21);
        _SFD_CV_INIT_EML(35,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(39,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(46,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(47,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(44,0,0,0,1,0,1,0,0,0,0,0);
        _SFD_CV_INIT_EML_SATURATION(44,0,0,6,-1,21);
        _SFD_CV_INIT_EML_IF(44,0,0,1,21,1,21);
        _SFD_CV_INIT_EML(41,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(60,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(36,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(58,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(57,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(57,0,0,1,18,1,18);
        _SFD_CV_INIT_EML(59,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(45,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(56,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(37,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(32,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(32,0,0,1,16,1,16);

        {
          static int condStart[] = { 1, 10 };

          static int condEnd[] = { 7, 16 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(32,0,0,1,16,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(32,0,0,1,7,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(32,0,1,10,16,-1,0);
        _SFD_CV_INIT_EML(66,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(66,0,0,1,18,1,18);

        {
          static int condStart[] = { 1, 10 };

          static int condEnd[] = { 7, 18 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(66,0,0,1,18,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(66,0,0,1,7,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(66,0,1,10,18,-1,0);
        _SFD_CV_INIT_EML(64,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(64,0,0,1,7,1,7);
        _SFD_CV_INIT_EML_RELATIONAL(64,0,0,1,7,-1,0);
        _SFD_CV_INIT_EML(1,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,1,9,1,9);
        _SFD_CV_INIT_EML_RELATIONAL(1,0,0,1,9,-1,0);
        _SFD_CV_INIT_EML(3,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(3,0,0,1,12,1,12);
        _SFD_CV_INIT_EML_RELATIONAL(3,0,0,1,12,-1,4);
        _SFD_CV_INIT_EML(2,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,0,0,1,7,1,7);
        _SFD_CV_INIT_EML_RELATIONAL(2,0,0,1,7,-1,0);
        _SFD_CV_INIT_EML(5,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(5,0,0,1,19,1,19);
        _SFD_CV_INIT_EML_RELATIONAL(5,0,0,1,19,-2,1);
        _SFD_CV_INIT_EML(4,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(4,0,0,1,7,1,7);
        _SFD_CV_INIT_EML_RELATIONAL(4,0,0,1,7,-1,0);
        _SFD_CV_INIT_EML(6,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(6,0,0,1,7,1,7);
        _SFD_CV_INIT_EML_RELATIONAL(6,0,0,1,7,-1,0);
        _SFD_CV_INIT_EML(11,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(11,0,0,1,15,1,15);

        {
          static int condStart[] = { 1, 10 };

          static int condEnd[] = { 7, 15 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(11,0,0,1,15,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(11,0,0,1,7,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(11,0,1,10,15,-1,0);
        _SFD_CV_INIT_EML(7,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(7,0,0,1,15,1,15);

        {
          static int condStart[] = { 1, 10 };

          static int condEnd[] = { 7, 15 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(7,0,0,1,15,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(51,0,0,0,1,0,1,0,0,0,2,1);
        _SFD_CV_INIT_EML_SATURATION(51,0,0,26,-1,36);
        _SFD_CV_INIT_EML_IF(51,0,0,1,14,1,14);

        {
          static int condStart[] = { 1, 8 };

          static int condEnd[] = { 7, 14 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(51,0,0,1,14,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(50,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(50,0,0,1,14,1,14);

        {
          static int condStart[] = { 1, 8 };

          static int condEnd[] = { 7, 14 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(50,0,0,1,14,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(50,0,0,1,7,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(50,0,1,8,14,-1,0);
        _SFD_CV_INIT_EML(62,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(62,0,0,1,14,1,14);

        {
          static int condStart[] = { 1, 8 };

          static int condEnd[] = { 7, 14 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(62,0,0,1,14,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(62,0,0,1,7,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(62,0,1,8,14,-1,0);
        _SFD_CV_INIT_EML(9,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(9,0,0,1,12,1,12);
        _SFD_CV_INIT_EML_RELATIONAL(9,0,0,1,12,-1,4);
        _SFD_CV_INIT_EML(8,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(8,0,0,1,9,1,9);
        _SFD_CV_INIT_EML_RELATIONAL(8,0,0,1,9,-1,0);
        _SFD_CV_INIT_EML(30,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(30,0,0,1,12,1,12);
        _SFD_CV_INIT_EML_RELATIONAL(30,0,0,1,12,-1,4);
        _SFD_CV_INIT_EML(29,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(29,0,0,1,7,1,7);
        _SFD_CV_INIT_EML_RELATIONAL(29,0,0,1,7,-1,0);
        _SFD_CV_INIT_EML(65,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(65,0,0,1,7,1,7);
        _SFD_CV_INIT_EML(12,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(12,0,0,1,7,1,7);
        _SFD_CV_INIT_EML_RELATIONAL(12,0,0,1,7,-1,0);
        _SFD_CV_INIT_EML(10,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(10,0,0,1,7,1,7);
        _SFD_CV_INIT_EML_RELATIONAL(10,0,0,1,7,-1,0);
        _SFD_CV_INIT_EML(31,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(31,0,0,1,7,1,7);
        _SFD_CV_INIT_EML_RELATIONAL(31,0,0,1,7,-1,0);
        _SFD_CV_INIT_EML(68,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(68,0,0,1,7,1,7);
        _SFD_CV_INIT_EML_RELATIONAL(68,0,0,1,7,-1,0);
        _SFD_CV_INIT_EML(63,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(63,0,0,1,14,1,14);

        {
          static int condStart[] = { 1, 8 };

          static int condEnd[] = { 7, 14 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(63,0,0,1,14,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(63,0,0,1,7,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(63,0,1,8,14,-1,0);
        _SFD_CV_INIT_EML(54,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(54,0,0,1,14,1,14);

        {
          static int condStart[] = { 1, 8 };

          static int condEnd[] = { 7, 14 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(54,0,0,1,14,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(67,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(67,0,0,1,7,1,7);
        _SFD_CV_INIT_EML_RELATIONAL(67,0,0,1,7,-1,0);
        _SFD_CV_INIT_EML(52,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(52,0,0,1,12,1,12);
        _SFD_CV_INIT_EML_RELATIONAL(52,0,0,1,12,-1,4);
        _SFD_CV_INIT_EML(53,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(53,0,0,1,9,1,9);
        _SFD_CV_INIT_EML_RELATIONAL(53,0,0,1,9,-1,0);
        _SFD_CV_INIT_EML(16,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,0,NULL,1,0,7,0,1,0,0,
          (MexFcnForType)c4_e_sf_marshallOut,(MexInFcnForType)c4_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT8,0,NULL,1,0,8,0,1,0,0,
          (MexFcnForType)c4_f_sf_marshallOut,(MexInFcnForType)c4_f_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)c4_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)c4_c_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295U;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295U;
          _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(11,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_UINT8,0,NULL,1,0,7,0,1,0,0,
          (MexFcnForType)c4_e_sf_marshallOut,(MexInFcnForType)c4_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(9,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(10,(void *)(NULL));
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
    SFc4_mpu6050_workingInstanceStruct *chartInstance =
      (SFc4_mpu6050_workingInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(6U, (void *)chartInstance->c4_sda);
        _SFD_SET_DATA_VALUE_PTR(7U, (void *)chartInstance->c4_scl);
        _SFD_SET_DATA_VALUE_PTR(8U, (void *)chartInstance->c4_sda_out);
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)chartInstance->c4_addr);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)chartInstance->c4_bit_idx);
        _SFD_SET_DATA_VALUE_PTR(14U, (void *)&chartInstance->c4_deviceAddr);
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)chartInstance->c4_data);
        _SFD_SET_DATA_VALUE_PTR(5U, (void *)chartInstance->c4_rw);
        _SFD_SET_DATA_VALUE_PTR(4U, (void *)chartInstance->c4_reg_idx);
        _SFD_SET_DATA_VALUE_PTR(3U, (void *)chartInstance->c4_rd_cnt);
        _SFD_SET_DATA_VALUE_PTR(15U, (void *)&chartInstance->c4_powerRegAddr);
        _SFD_SET_DATA_VALUE_PTR(11U, (void *)&chartInstance->c4_AccelXRegAddr);
        _SFD_SET_DATA_VALUE_PTR(12U, (void *)&chartInstance->c4_AccelYRegAddr);
        _SFD_SET_DATA_VALUE_PTR(13U, (void *)&chartInstance->c4_AccelZRegAddr);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "saF3GFwSNSFegVrf4WyxUhH";
}

static void sf_check_dwork_consistency(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    const uint32_T *sfunDWorkChecksum = sf_get_sfun_dwork_checksum();
    mxArray *infoStruct = load_mpu6050_working_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    mxArray* mxRTWDWorkChecksum = sf_get_dwork_info_from_mat_file(S,
      sf_get_instance_specialization(), infoStruct, 4, "dworkChecksum");
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

static void sf_opaque_initialize_c4_mpu6050_working(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc4_mpu6050_workingInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc4_mpu6050_workingInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c4_mpu6050_working((SFc4_mpu6050_workingInstanceStruct*)
    chartInstanceVar);
  initialize_c4_mpu6050_working((SFc4_mpu6050_workingInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c4_mpu6050_working(void *chartInstanceVar)
{
  enable_c4_mpu6050_working((SFc4_mpu6050_workingInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c4_mpu6050_working(void *chartInstanceVar)
{
  disable_c4_mpu6050_working((SFc4_mpu6050_workingInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c4_mpu6050_working(void *chartInstanceVar)
{
  sf_gateway_c4_mpu6050_working((SFc4_mpu6050_workingInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c4_mpu6050_working(void *chartInstanceVar)
{
  ext_mode_exec_c4_mpu6050_working((SFc4_mpu6050_workingInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c4_mpu6050_working(SimStruct* S)
{
  return get_sim_state_c4_mpu6050_working((SFc4_mpu6050_workingInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c4_mpu6050_working(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c4_mpu6050_working((SFc4_mpu6050_workingInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c4_mpu6050_working(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_mpu6050_workingInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_mpu6050_working_optimization_info();
    }

    finalize_c4_mpu6050_working((SFc4_mpu6050_workingInstanceStruct*)
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
  initSimStructsc4_mpu6050_working((SFc4_mpu6050_workingInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_mpu6050_working(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_mpu6050_working((SFc4_mpu6050_workingInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

mxArray *sf_c4_mpu6050_working_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S1x2'varName','path'{{T\"is_active_c4_mpu6050_working\",T\"is_active_c4_mpu6050_working\"},{T\"is_c4_mpu6050_working\",T\"is_c4_mpu6050_working\"}}"
  };

  mxArray *mxTpInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  return mxTpInfo;
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  const char *dworkEncStr[] = {
    "100 S1x9'type','isSigned','wordLength','bias','slope','exponent','isScaledDouble','isComplex','size','local_queue_dwork_idx','local_queue_id'{{T\"int32\",,,,,,,M[0],M[],M[-1],M[-1]},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1]},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1]},{T\"fixpt\",M[0],M[7],M[0],M[1],M[0],M[0],M[0],M[],M[-1],M[-1]},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1]},{T\"fixpt\",M[0],M[8],M[0],M[1],M[0],M[0],M[0],M[],M[-1],M[-1]},{T\"boolean\",,,,,,,M[0],M[],M[-1],M[-1]},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1]},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 9, 10);
}

static uint32_T* sf_get_sfun_dwork_checksum()
{
  static uint32_T checksum[4] = { 4043088047U, 3170159088U, 3140814435U,
    225705984U };

  return checksum;
}

static void mdlSetWorkWidths_c4_mpu6050_working(SimStruct *S)
{
  /* Actual parameters from chart:
     AccelXRegAddr AccelYRegAddr AccelZRegAddr deviceAddr powerRegAddr
   */
  const char_T *rtParamNames[] = { "AccelXRegAddr", "AccelYRegAddr",
    "AccelZRegAddr", "deviceAddr", "powerRegAddr" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for AccelXRegAddr*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_UINT8);

  /* registration for AccelYRegAddr*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_UINT8);

  /* registration for AccelZRegAddr*/
  ssRegDlgParamAsRunTimeParam(S, 2, 2, rtParamNames[2], SS_UINT8);

  /* registration for deviceAddr*/
  {
    DTypeId dataTypeId = sf_get_fixpt_data_type_id(S,
      (unsigned int)7,
      (bool)0,
      (int)0,
      (double)1,
      (double)0);
    ssRegDlgParamAsRunTimeParam(S, 3, 3, rtParamNames[3], dataTypeId);
  }

  /* registration for powerRegAddr*/
  ssRegDlgParamAsRunTimeParam(S, 4, 4, rtParamNames[4], SS_UINT8);
  ssSetStatesModifiedOnlyInUpdate(S, 0);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_mpu6050_working_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,4,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 4);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,4);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,4,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,4,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,4);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(807280710U));
  ssSetChecksum1(S,(3896088873U));
  ssSetChecksum2(S,(2164837328U));
  ssSetChecksum3(S,(2521896154U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c4_mpu6050_working(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c4_mpu6050_working(SimStruct *S)
{
  SFc4_mpu6050_workingInstanceStruct *chartInstance;
  chartInstance = (SFc4_mpu6050_workingInstanceStruct *)utMalloc(sizeof
    (SFc4_mpu6050_workingInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc4_mpu6050_workingInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c4_mpu6050_working;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c4_mpu6050_working;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c4_mpu6050_working;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_mpu6050_working;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c4_mpu6050_working;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c4_mpu6050_working;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c4_mpu6050_working;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_mpu6050_working;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_mpu6050_working;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_mpu6050_working;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c4_mpu6050_working;
  chartInstance->chartInfo.callGetHoverDataForMsg =
    sf_opaque_get_hover_data_for_msg;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c4_mpu6050_working;
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
  mdl_start_c4_mpu6050_working(chartInstance);
}

void c4_mpu6050_working_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_mpu6050_working(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_mpu6050_working(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_mpu6050_working(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_mpu6050_working_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
