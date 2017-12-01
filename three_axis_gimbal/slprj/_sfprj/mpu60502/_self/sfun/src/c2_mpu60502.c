/* Include files */

#include "simstruc.h"
#include "fixedpoint.h"
#include "simtarget/slSimTgtLogLoadBlocksSfcnBridge.h"
#include "mpu60502_sfun.h"
#include "c2_mpu60502.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "mpu60502_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c_with_debugger(S, sfGlobalDebugInstanceStruct);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c2_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c2_IN_Increment_Byte_count1    ((uint8_T)1U)
#define c2_IN_ack_addr_m               ((uint8_T)2U)
#define c2_IN_ack_addr_m_cnf           ((uint8_T)3U)
#define c2_IN_ack_addrm1               ((uint8_T)4U)
#define c2_IN_ack_data                 ((uint8_T)5U)
#define c2_IN_ack_end                  ((uint8_T)6U)
#define c2_IN_ack_end1                 ((uint8_T)7U)
#define c2_IN_ack_recv_wr              ((uint8_T)8U)
#define c2_IN_ack_recv_wr1             ((uint8_T)9U)
#define c2_IN_ack_recv_wr2             ((uint8_T)10U)
#define c2_IN_ack_recv_wr3             ((uint8_T)11U)
#define c2_IN_ack_slv                  ((uint8_T)12U)
#define c2_IN_ack_slv1                 ((uint8_T)13U)
#define c2_IN_ack_slv_cnf1             ((uint8_T)14U)
#define c2_IN_ack_wr_p                 ((uint8_T)15U)
#define c2_IN_ack_wr_p2                ((uint8_T)16U)
#define c2_IN_cmd_reg_addr_n           ((uint8_T)17U)
#define c2_IN_cmd_reg_addr_p           ((uint8_T)18U)
#define c2_IN_cmd_reg_data_n           ((uint8_T)19U)
#define c2_IN_cmd_reg_data_p           ((uint8_T)20U)
#define c2_IN_cmd_reg_read_data_n      ((uint8_T)21U)
#define c2_IN_cmd_reg_read_data_p      ((uint8_T)22U)
#define c2_IN_cmd_slave_addr_n         ((uint8_T)23U)
#define c2_IN_cmd_slave_addr_n1        ((uint8_T)24U)
#define c2_IN_cmd_slave_addr_p         ((uint8_T)25U)
#define c2_IN_cmd_slave_addr_p1        ((uint8_T)26U)
#define c2_IN_delay                    ((uint8_T)27U)
#define c2_IN_error_ack                ((uint8_T)28U)
#define c2_IN_idle                     ((uint8_T)29U)
#define c2_IN_mastr_ack_data           ((uint8_T)30U)
#define c2_IN_mastr_ack_data_cnf       ((uint8_T)31U)
#define c2_IN_mastr_ack_data_cnf1      ((uint8_T)32U)
#define c2_IN_read_n                   ((uint8_T)33U)
#define c2_IN_read_p                   ((uint8_T)34U)
#define c2_IN_ready                    ((uint8_T)35U)
#define c2_IN_ready_repeated           ((uint8_T)36U)
#define c2_IN_ready_repeated_dummy     ((uint8_T)37U)
#define c2_IN_repeat_strt_n            ((uint8_T)38U)
#define c2_IN_repeat_strt_p            ((uint8_T)39U)
#define c2_IN_scl_ext_n                ((uint8_T)40U)
#define c2_IN_scl_ext_p                ((uint8_T)41U)
#define c2_IN_start_n                  ((uint8_T)42U)
#define c2_IN_start_p                  ((uint8_T)43U)
#define c2_IN_stop                     ((uint8_T)44U)
#define c2_IN_stop_ext                 ((uint8_T)45U)
#define c2_IN_write_n                  ((uint8_T)46U)
#define c2_IN_write_p                  ((uint8_T)47U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c2_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_c_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_d_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_e_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_f_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_g_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_h_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_i_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_j_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_k_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_l_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_m_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_n_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_o_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_p_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_q_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_r_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_s_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_t_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_u_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_v_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_w_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_x_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_y_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_ab_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_bb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_cb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_db_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_eb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_fb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_gb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_hb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_ib_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_jb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_kb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_lb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_mb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_nb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_ob_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_pb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_qb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_rb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_sb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_tb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_ub_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_vb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_wb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_xb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_yb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_ac_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_bc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_cc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_dc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_ec_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_fc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_gc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_hc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_ic_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_jc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_kc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_lc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_mc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const mxArray *c2_eml_mx;
static const mxArray *c2_b_eml_mx;

/* Function Declarations */
static void initialize_c2_mpu60502(SFc2_mpu60502InstanceStruct *chartInstance);
static void initialize_params_c2_mpu60502(SFc2_mpu60502InstanceStruct
  *chartInstance);
static void enable_c2_mpu60502(SFc2_mpu60502InstanceStruct *chartInstance);
static void disable_c2_mpu60502(SFc2_mpu60502InstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_mpu60502(SFc2_mpu60502InstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c2_mpu60502(SFc2_mpu60502InstanceStruct
  *chartInstance);
static void set_sim_state_c2_mpu60502(SFc2_mpu60502InstanceStruct *chartInstance,
  const mxArray *c2_st);
static void c2_set_sim_state_side_effects_c2_mpu60502
  (SFc2_mpu60502InstanceStruct *chartInstance);
static void finalize_c2_mpu60502(SFc2_mpu60502InstanceStruct *chartInstance);
static void sf_gateway_c2_mpu60502(SFc2_mpu60502InstanceStruct *chartInstance);
static void mdl_start_c2_mpu60502(SFc2_mpu60502InstanceStruct *chartInstance);
static void c2_chartstep_c2_mpu60502(SFc2_mpu60502InstanceStruct *chartInstance);
static void initSimStructsc2_mpu60502(SFc2_mpu60502InstanceStruct *chartInstance);
static void c2_enter_atomic_idle(SFc2_mpu60502InstanceStruct *chartInstance);
static void c2_idle(SFc2_mpu60502InstanceStruct *chartInstance);
static void c2_ready(SFc2_mpu60502InstanceStruct *chartInstance);
static void c2_mastr_ack_data_cnf1(SFc2_mpu60502InstanceStruct *chartInstance);
static void c2_mastr_ack_data_cnf(SFc2_mpu60502InstanceStruct *chartInstance);
static void c2_mastr_ack_data(SFc2_mpu60502InstanceStruct *chartInstance);
static void c2_enter_atomic_cmd_slave_addr_n(SFc2_mpu60502InstanceStruct
  *chartInstance);
static void c2_cmd_slave_addr_n(SFc2_mpu60502InstanceStruct *chartInstance);
static void c2_Increment_Byte_count1(SFc2_mpu60502InstanceStruct *chartInstance);
static void c2_cmd_slave_addr_p(SFc2_mpu60502InstanceStruct *chartInstance);
static void c2_ack_end1(SFc2_mpu60502InstanceStruct *chartInstance);
static void c2_cmd_reg_read_data_p(SFc2_mpu60502InstanceStruct *chartInstance);
static void c2_ack_end(SFc2_mpu60502InstanceStruct *chartInstance);
static void c2_ack_recv_wr3(SFc2_mpu60502InstanceStruct *chartInstance);
static void c2_ack_data(SFc2_mpu60502InstanceStruct *chartInstance);
static void c2_ack_slv(SFc2_mpu60502InstanceStruct *chartInstance);
static void c2_cmd_reg_read_data_n(SFc2_mpu60502InstanceStruct *chartInstance);
static void c2_ack_recv_wr(SFc2_mpu60502InstanceStruct *chartInstance);
static void c2_cmd_reg_data_p(SFc2_mpu60502InstanceStruct *chartInstance);
static void c2_ack_addr_m_cnf(SFc2_mpu60502InstanceStruct *chartInstance);
static void c2_ack_wr_p(SFc2_mpu60502InstanceStruct *chartInstance);
static void c2_error_ack(SFc2_mpu60502InstanceStruct *chartInstance);
static void c2_enter_atomic_cmd_reg_data_n(SFc2_mpu60502InstanceStruct
  *chartInstance);
static void c2_cmd_reg_data_n(SFc2_mpu60502InstanceStruct *chartInstance);
static void c2_delay(SFc2_mpu60502InstanceStruct *chartInstance);
static void c2_enter_atomic_cmd_reg_addr_n(SFc2_mpu60502InstanceStruct
  *chartInstance);
static void c2_cmd_reg_addr_n(SFc2_mpu60502InstanceStruct *chartInstance);
static void c2_repeat_strt_n(SFc2_mpu60502InstanceStruct *chartInstance);
static void c2_ready_repeated(SFc2_mpu60502InstanceStruct *chartInstance);
static void c2_cmd_reg_addr_p(SFc2_mpu60502InstanceStruct *chartInstance);
static void c2_repeat_strt_p(SFc2_mpu60502InstanceStruct *chartInstance);
static void c2_ready_repeated_dummy(SFc2_mpu60502InstanceStruct *chartInstance);
static void c2_ack_addr_m(SFc2_mpu60502InstanceStruct *chartInstance);
static void c2_ack_recv_wr1(SFc2_mpu60502InstanceStruct *chartInstance);
static void c2_ack_recv_wr2(SFc2_mpu60502InstanceStruct *chartInstance);
static void c2_enter_atomic_cmd_slave_addr_n1(SFc2_mpu60502InstanceStruct
  *chartInstance);
static void c2_cmd_slave_addr_n1(SFc2_mpu60502InstanceStruct *chartInstance);
static void c2_cmd_slave_addr_p1(SFc2_mpu60502InstanceStruct *chartInstance);
static void c2_ack_addrm1(SFc2_mpu60502InstanceStruct *chartInstance);
static void c2_read_n(SFc2_mpu60502InstanceStruct *chartInstance);
static void c2_ack_wr_p2(SFc2_mpu60502InstanceStruct *chartInstance);
static void c2_read_p(SFc2_mpu60502InstanceStruct *chartInstance);
static void c2_ack_slv1(SFc2_mpu60502InstanceStruct *chartInstance);
static void c2_ack_slv_cnf1(SFc2_mpu60502InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static real_T c2_emlrt_marshallIn(SFc2_mpu60502InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static boolean_T c2_b_emlrt_marshallIn(SFc2_mpu60502InstanceStruct
  *chartInstance, const mxArray *c2_sf_internal_predicateOutput, const char_T
  *c2_identifier);
static boolean_T c2_c_emlrt_marshallIn(SFc2_mpu60502InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_d_emlrt_marshallIn(SFc2_mpu60502InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static uint8_T c2_e_emlrt_marshallIn(SFc2_mpu60502InstanceStruct *chartInstance,
  const mxArray *c2_b_tp_idle, const char_T *c2_identifier);
static uint8_T c2_f_emlrt_marshallIn(SFc2_mpu60502InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static uint8_T c2_g_emlrt_marshallIn(SFc2_mpu60502InstanceStruct *chartInstance,
  const mxArray *c2_b_data_out, const char_T *c2_identifier);
static uint8_T c2_h_emlrt_marshallIn(SFc2_mpu60502InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_i_emlrt_marshallIn(SFc2_mpu60502InstanceStruct *chartInstance,
  const mxArray *c2_b_dataWrittenToVector, const char_T *c2_identifier,
  boolean_T c2_y[12]);
static void c2_j_emlrt_marshallIn(SFc2_mpu60502InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, boolean_T c2_y[12]);
static const mxArray *c2_k_emlrt_marshallIn(SFc2_mpu60502InstanceStruct
  *chartInstance, const mxArray *c2_b_setSimStateSideEffectsInfo, const char_T
  *c2_identifier);
static const mxArray *c2_l_emlrt_marshallIn(SFc2_mpu60502InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static const mxArray *sf_get_hover_data_for_msg(SFc2_mpu60502InstanceStruct
  *chartInstance, int32_T c2_ssid);
static void c2_init_sf_message_store_memory(SFc2_mpu60502InstanceStruct
  *chartInstance);
static void init_test_point_addr_map(SFc2_mpu60502InstanceStruct *chartInstance);
static void **get_test_point_address_map(SFc2_mpu60502InstanceStruct
  *chartInstance);
static rtwCAPI_ModelMappingInfo *get_test_point_mapping_info
  (SFc2_mpu60502InstanceStruct *chartInstance);
static void **get_dataset_logging_obj_vector(SFc2_mpu60502InstanceStruct
  *chartInstance);
static void init_dsm_address_info(SFc2_mpu60502InstanceStruct *chartInstance);
static void init_simulink_io_address(SFc2_mpu60502InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_mpu60502(SFc2_mpu60502InstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc2_mpu60502(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_doSetSimStateSideEffects = 0U;
  chartInstance->c2_setSimStateSideEffectsInfo = NULL;
  chartInstance->c2_tp_Increment_Byte_count1 = 0U;
  chartInstance->c2_tp_ack_addr_m = 0U;
  chartInstance->c2_tp_ack_addr_m_cnf = 0U;
  chartInstance->c2_tp_ack_addrm1 = 0U;
  chartInstance->c2_tp_ack_data = 0U;
  chartInstance->c2_tp_ack_end = 0U;
  chartInstance->c2_tp_ack_end1 = 0U;
  chartInstance->c2_tp_ack_recv_wr = 0U;
  chartInstance->c2_tp_ack_recv_wr1 = 0U;
  chartInstance->c2_tp_ack_recv_wr2 = 0U;
  chartInstance->c2_tp_ack_recv_wr3 = 0U;
  chartInstance->c2_tp_ack_slv = 0U;
  chartInstance->c2_tp_ack_slv1 = 0U;
  chartInstance->c2_tp_ack_slv_cnf1 = 0U;
  chartInstance->c2_tp_ack_wr_p = 0U;
  chartInstance->c2_tp_ack_wr_p2 = 0U;
  chartInstance->c2_tp_cmd_reg_addr_n = 0U;
  chartInstance->c2_tp_cmd_reg_addr_p = 0U;
  chartInstance->c2_tp_cmd_reg_data_n = 0U;
  chartInstance->c2_tp_cmd_reg_data_p = 0U;
  chartInstance->c2_tp_cmd_reg_read_data_n = 0U;
  chartInstance->c2_tp_cmd_reg_read_data_p = 0U;
  chartInstance->c2_tp_cmd_slave_addr_n = 0U;
  chartInstance->c2_tp_cmd_slave_addr_n1 = 0U;
  chartInstance->c2_tp_cmd_slave_addr_p = 0U;
  chartInstance->c2_tp_cmd_slave_addr_p1 = 0U;
  chartInstance->c2_tp_delay = 0U;
  chartInstance->c2_tp_error_ack = 0U;
  chartInstance->c2_tp_idle = 0U;
  chartInstance->c2_tp_mastr_ack_data = 0U;
  chartInstance->c2_tp_mastr_ack_data_cnf = 0U;
  chartInstance->c2_tp_mastr_ack_data_cnf1 = 0U;
  chartInstance->c2_tp_read_n = 0U;
  chartInstance->c2_tp_read_p = 0U;
  chartInstance->c2_tp_ready = 0U;
  chartInstance->c2_tp_ready_repeated = 0U;
  chartInstance->c2_tp_ready_repeated_dummy = 0U;
  chartInstance->c2_tp_repeat_strt_n = 0U;
  chartInstance->c2_tp_repeat_strt_p = 0U;
  chartInstance->c2_tp_scl_ext_n = 0U;
  chartInstance->c2_tp_scl_ext_p = 0U;
  chartInstance->c2_tp_start_n = 0U;
  chartInstance->c2_tp_start_p = 0U;
  chartInstance->c2_tp_stop = 0U;
  chartInstance->c2_tp_stop_ext = 0U;
  chartInstance->c2_tp_write_n = 0U;
  chartInstance->c2_tp_write_p = 0U;
  chartInstance->c2_is_active_c2_mpu60502 = 0U;
  chartInstance->c2_is_c2_mpu60502 = c2_IN_NO_ACTIVE_CHILD;
  sf_mex_assign(&c2_b_eml_mx, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "numerictype", 1U, 14U, 15, "SignednessBool", 3, false, 15, "Signedness", 15,
    "Unsigned", 15, "WordLength", 6, 8.0, 15, "FractionLength", 6, 0.0, 15,
    "BinaryPoint", 6, 0.0, 15, "Slope", 6, 1.0, 15, "FixedExponent", 6, 0.0),
                true);
  sf_mex_assign(&c2_eml_mx, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
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
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  chartInstance->c2_is_active_c2_mpu60502 = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c2_sfEvent);
  chartInstance->c2_is_c2_mpu60502 = c2_IN_idle;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 28U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_idle = 1U;
  c2_enter_atomic_idle(chartInstance);
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_mpu60502MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initialize_params_c2_mpu60502(SFc2_mpu60502InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c2_mpu60502(SFc2_mpu60502InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c2_mpu60502(SFc2_mpu60502InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c2_update_debugger_state_c2_mpu60502(SFc2_mpu60502InstanceStruct
  *chartInstance)
{
  uint32_T c2_prevAniVal;
  c2_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c2_is_active_c2_mpu60502 == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_mpu60502 == c2_IN_idle) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 28U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 28U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_mpu60502 == c2_IN_stop_ext) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 44U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 44U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_mpu60502 == c2_IN_ready) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 34U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 34U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_mpu60502 == c2_IN_stop) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 43U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 43U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_mpu60502 == c2_IN_start_n) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 41U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 41U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_mpu60502 == c2_IN_mastr_ack_data_cnf1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 31U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 31U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_mpu60502 == c2_IN_mastr_ack_data_cnf) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 30U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 30U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_mpu60502 == c2_IN_scl_ext_p) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 40U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 40U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_mpu60502 == c2_IN_start_p) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 42U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 42U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_mpu60502 == c2_IN_scl_ext_n) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 39U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 39U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_mpu60502 == c2_IN_mastr_ack_data) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 29U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 29U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_mpu60502 == c2_IN_cmd_slave_addr_n) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 22U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_mpu60502 == c2_IN_Increment_Byte_count1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_mpu60502 == c2_IN_cmd_slave_addr_p) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 24U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 24U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_mpu60502 == c2_IN_write_n) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 45U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 45U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_mpu60502 == c2_IN_ack_end1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_mpu60502 == c2_IN_cmd_reg_read_data_p) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 21U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_mpu60502 == c2_IN_ack_end) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_mpu60502 == c2_IN_write_p) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 46U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 46U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_mpu60502 == c2_IN_ack_recv_wr3) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_mpu60502 == c2_IN_ack_data) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_mpu60502 == c2_IN_ack_slv) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_mpu60502 == c2_IN_cmd_reg_read_data_n) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_mpu60502 == c2_IN_ack_recv_wr) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_mpu60502 == c2_IN_cmd_reg_data_p) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_mpu60502 == c2_IN_ack_addr_m_cnf) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_mpu60502 == c2_IN_ack_wr_p) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_mpu60502 == c2_IN_error_ack) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 27U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 27U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_mpu60502 == c2_IN_cmd_reg_data_n) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_mpu60502 == c2_IN_delay) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 26U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 26U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_mpu60502 == c2_IN_cmd_reg_addr_n) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_mpu60502 == c2_IN_repeat_strt_n) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 37U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 37U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_mpu60502 == c2_IN_ready_repeated) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 35U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 35U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_mpu60502 == c2_IN_cmd_reg_addr_p) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_mpu60502 == c2_IN_repeat_strt_p) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 38U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 38U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_mpu60502 == c2_IN_ready_repeated_dummy) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 36U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 36U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_mpu60502 == c2_IN_ack_addr_m) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_mpu60502 == c2_IN_ack_recv_wr1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_mpu60502 == c2_IN_ack_recv_wr2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_mpu60502 == c2_IN_cmd_slave_addr_n1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 23U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 23U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_mpu60502 == c2_IN_cmd_slave_addr_p1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 25U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 25U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_mpu60502 == c2_IN_ack_addrm1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_mpu60502 == c2_IN_read_n) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 32U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 32U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_mpu60502 == c2_IN_ack_wr_p2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_mpu60502 == c2_IN_read_p) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 33U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 33U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_mpu60502 == c2_IN_ack_slv1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_mpu60502 == c2_IN_ack_slv_cnf1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c2_sfEvent);
  }

  _SFD_SET_ANIMATION(c2_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c2_mpu60502(SFc2_mpu60502InstanceStruct
  *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  boolean_T c2_hoistedGlobal;
  const mxArray *c2_b_y = NULL;
  boolean_T c2_b_hoistedGlobal;
  const mxArray *c2_c_y = NULL;
  uint8_T c2_c_hoistedGlobal;
  const mxArray *c2_d_y = NULL;
  uint8_T c2_u;
  const mxArray *c2_e_y = NULL;
  boolean_T c2_d_hoistedGlobal;
  const mxArray *c2_f_y = NULL;
  boolean_T c2_e_hoistedGlobal;
  const mxArray *c2_g_y = NULL;
  boolean_T c2_f_hoistedGlobal;
  const mxArray *c2_h_y = NULL;
  boolean_T c2_g_hoistedGlobal;
  const mxArray *c2_i_y = NULL;
  boolean_T c2_h_hoistedGlobal;
  const mxArray *c2_j_y = NULL;
  boolean_T c2_i_hoistedGlobal;
  const mxArray *c2_k_y = NULL;
  uint8_T c2_j_hoistedGlobal;
  const mxArray *c2_l_y = NULL;
  uint8_T c2_k_hoistedGlobal;
  const mxArray *c2_m_y = NULL;
  uint8_T c2_l_hoistedGlobal;
  const mxArray *c2_n_y = NULL;
  uint8_T c2_m_hoistedGlobal;
  const mxArray *c2_o_y = NULL;
  uint8_T c2_n_hoistedGlobal;
  const mxArray *c2_p_y = NULL;
  const mxArray *c2_q_y = NULL;
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellmatrix(15, 1), false);
  c2_hoistedGlobal = *chartInstance->c2_ack;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_hoistedGlobal, 11, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = *chartInstance->c2_busy;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_hoistedGlobal, 11, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_c_hoistedGlobal = *chartInstance->c2_data_out;
  c2_d_y = NULL;
  c2_u = c2_c_hoistedGlobal;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_d_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
    (c2_eml_mx), 15, "numerictype", 14, sf_mex_dup(c2_b_eml_mx), 15,
    "simulinkarray", 14, c2_e_y, 15, "fimathislocal", 3, false), false);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  c2_d_hoistedGlobal = *chartInstance->c2_mstr_ack;
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_d_hoistedGlobal, 11, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c2_y, 3, c2_f_y);
  c2_e_hoistedGlobal = *chartInstance->c2_n_ack;
  c2_g_y = NULL;
  sf_mex_assign(&c2_g_y, sf_mex_create("y", &c2_e_hoistedGlobal, 11, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c2_y, 4, c2_g_y);
  c2_f_hoistedGlobal = *chartInstance->c2_reg_addr_burst;
  c2_h_y = NULL;
  sf_mex_assign(&c2_h_y, sf_mex_create("y", &c2_f_hoistedGlobal, 11, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c2_y, 5, c2_h_y);
  c2_g_hoistedGlobal = *chartInstance->c2_reg_data_burst;
  c2_i_y = NULL;
  sf_mex_assign(&c2_i_y, sf_mex_create("y", &c2_g_hoistedGlobal, 11, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c2_y, 6, c2_i_y);
  c2_h_hoistedGlobal = *chartInstance->c2_scl;
  c2_j_y = NULL;
  sf_mex_assign(&c2_j_y, sf_mex_create("y", &c2_h_hoistedGlobal, 11, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c2_y, 7, c2_j_y);
  c2_i_hoistedGlobal = *chartInstance->c2_sda;
  c2_k_y = NULL;
  sf_mex_assign(&c2_k_y, sf_mex_create("y", &c2_i_hoistedGlobal, 11, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c2_y, 8, c2_k_y);
  c2_j_hoistedGlobal = chartInstance->c2_bit_cnt;
  c2_l_y = NULL;
  sf_mex_assign(&c2_l_y, sf_mex_create("y", &c2_j_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c2_y, 9, c2_l_y);
  c2_k_hoistedGlobal = chartInstance->c2_reg_byte_cnt;
  c2_m_y = NULL;
  sf_mex_assign(&c2_m_y, sf_mex_create("y", &c2_k_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c2_y, 10, c2_m_y);
  c2_l_hoistedGlobal = chartInstance->c2_temp_data;
  c2_n_y = NULL;
  sf_mex_assign(&c2_n_y, sf_mex_create("y", &c2_l_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c2_y, 11, c2_n_y);
  c2_m_hoistedGlobal = chartInstance->c2_is_active_c2_mpu60502;
  c2_o_y = NULL;
  sf_mex_assign(&c2_o_y, sf_mex_create("y", &c2_m_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c2_y, 12, c2_o_y);
  c2_n_hoistedGlobal = chartInstance->c2_is_c2_mpu60502;
  c2_p_y = NULL;
  sf_mex_assign(&c2_p_y, sf_mex_create("y", &c2_n_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c2_y, 13, c2_p_y);
  c2_q_y = NULL;
  sf_mex_assign(&c2_q_y, sf_mex_create("y",
    chartInstance->c2_dataWrittenToVector, 11, 0U, 1U, 0U, 1, 12), false);
  sf_mex_setcell(c2_y, 14, c2_q_y);
  sf_mex_assign(&c2_st, c2_y, false);
  return c2_st;
}

static void set_sim_state_c2_mpu60502(SFc2_mpu60502InstanceStruct *chartInstance,
  const mxArray *c2_st)
{
  const mxArray *c2_u;
  boolean_T c2_bv0[12];
  int32_T c2_i0;
  chartInstance->c2_doneDoubleBufferReInit = true;
  c2_u = sf_mex_dup(c2_st);
  *chartInstance->c2_ack = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("ack", c2_u, 0)), "ack");
  *chartInstance->c2_busy = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("busy", c2_u, 1)), "busy");
  *chartInstance->c2_data_out = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("data_out", c2_u, 2)), "data_out");
  *chartInstance->c2_mstr_ack = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("mstr_ack", c2_u, 3)), "mstr_ack");
  *chartInstance->c2_n_ack = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("n_ack", c2_u, 4)), "n_ack");
  *chartInstance->c2_reg_addr_burst = c2_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("reg_addr_burst", c2_u, 5)), "reg_addr_burst");
  *chartInstance->c2_reg_data_burst = c2_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("reg_data_burst", c2_u, 6)), "reg_data_burst");
  *chartInstance->c2_scl = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("scl", c2_u, 7)), "scl");
  *chartInstance->c2_sda = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("sda", c2_u, 8)), "sda");
  chartInstance->c2_bit_cnt = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("bit_cnt", c2_u, 9)), "bit_cnt");
  chartInstance->c2_reg_byte_cnt = c2_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("reg_byte_cnt", c2_u, 10)), "reg_byte_cnt");
  chartInstance->c2_temp_data = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("temp_data", c2_u, 11)), "temp_data");
  chartInstance->c2_is_active_c2_mpu60502 = c2_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_active_c2_mpu60502", c2_u, 12)),
    "is_active_c2_mpu60502");
  chartInstance->c2_is_c2_mpu60502 = c2_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_c2_mpu60502", c2_u, 13)), "is_c2_mpu60502");
  c2_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "dataWrittenToVector", c2_u, 14)), "dataWrittenToVector", c2_bv0);
  for (c2_i0 = 0; c2_i0 < 12; c2_i0++) {
    chartInstance->c2_dataWrittenToVector[c2_i0] = c2_bv0[c2_i0];
  }

  sf_mex_assign(&chartInstance->c2_setSimStateSideEffectsInfo,
                c2_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "setSimStateSideEffectsInfo", c2_u, 15)), "setSimStateSideEffectsInfo"),
                true);
  sf_mex_destroy(&c2_u);
  chartInstance->c2_doSetSimStateSideEffects = 1U;
  c2_update_debugger_state_c2_mpu60502(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void c2_set_sim_state_side_effects_c2_mpu60502
  (SFc2_mpu60502InstanceStruct *chartInstance)
{
  if (chartInstance->c2_doSetSimStateSideEffects != 0) {
    chartInstance->c2_tp_Increment_Byte_count1 = (uint8_T)
      (chartInstance->c2_is_c2_mpu60502 == c2_IN_Increment_Byte_count1);
    chartInstance->c2_tp_ack_addr_m = (uint8_T)(chartInstance->c2_is_c2_mpu60502
      == c2_IN_ack_addr_m);
    chartInstance->c2_tp_ack_addr_m_cnf = (uint8_T)
      (chartInstance->c2_is_c2_mpu60502 == c2_IN_ack_addr_m_cnf);
    chartInstance->c2_tp_ack_addrm1 = (uint8_T)(chartInstance->c2_is_c2_mpu60502
      == c2_IN_ack_addrm1);
    chartInstance->c2_tp_ack_data = (uint8_T)(chartInstance->c2_is_c2_mpu60502 ==
      c2_IN_ack_data);
    chartInstance->c2_tp_ack_end = (uint8_T)(chartInstance->c2_is_c2_mpu60502 ==
      c2_IN_ack_end);
    chartInstance->c2_tp_ack_end1 = (uint8_T)(chartInstance->c2_is_c2_mpu60502 ==
      c2_IN_ack_end1);
    chartInstance->c2_tp_ack_recv_wr = (uint8_T)
      (chartInstance->c2_is_c2_mpu60502 == c2_IN_ack_recv_wr);
    chartInstance->c2_tp_ack_recv_wr1 = (uint8_T)
      (chartInstance->c2_is_c2_mpu60502 == c2_IN_ack_recv_wr1);
    chartInstance->c2_tp_ack_recv_wr2 = (uint8_T)
      (chartInstance->c2_is_c2_mpu60502 == c2_IN_ack_recv_wr2);
    chartInstance->c2_tp_ack_recv_wr3 = (uint8_T)
      (chartInstance->c2_is_c2_mpu60502 == c2_IN_ack_recv_wr3);
    chartInstance->c2_tp_ack_slv = (uint8_T)(chartInstance->c2_is_c2_mpu60502 ==
      c2_IN_ack_slv);
    chartInstance->c2_tp_ack_slv1 = (uint8_T)(chartInstance->c2_is_c2_mpu60502 ==
      c2_IN_ack_slv1);
    chartInstance->c2_tp_ack_slv_cnf1 = (uint8_T)
      (chartInstance->c2_is_c2_mpu60502 == c2_IN_ack_slv_cnf1);
    chartInstance->c2_tp_ack_wr_p = (uint8_T)(chartInstance->c2_is_c2_mpu60502 ==
      c2_IN_ack_wr_p);
    chartInstance->c2_tp_ack_wr_p2 = (uint8_T)(chartInstance->c2_is_c2_mpu60502 ==
      c2_IN_ack_wr_p2);
    chartInstance->c2_tp_cmd_reg_addr_n = (uint8_T)
      (chartInstance->c2_is_c2_mpu60502 == c2_IN_cmd_reg_addr_n);
    chartInstance->c2_tp_cmd_reg_addr_p = (uint8_T)
      (chartInstance->c2_is_c2_mpu60502 == c2_IN_cmd_reg_addr_p);
    chartInstance->c2_tp_cmd_reg_data_n = (uint8_T)
      (chartInstance->c2_is_c2_mpu60502 == c2_IN_cmd_reg_data_n);
    chartInstance->c2_tp_cmd_reg_data_p = (uint8_T)
      (chartInstance->c2_is_c2_mpu60502 == c2_IN_cmd_reg_data_p);
    chartInstance->c2_tp_cmd_reg_read_data_n = (uint8_T)
      (chartInstance->c2_is_c2_mpu60502 == c2_IN_cmd_reg_read_data_n);
    chartInstance->c2_tp_cmd_reg_read_data_p = (uint8_T)
      (chartInstance->c2_is_c2_mpu60502 == c2_IN_cmd_reg_read_data_p);
    chartInstance->c2_tp_cmd_slave_addr_n = (uint8_T)
      (chartInstance->c2_is_c2_mpu60502 == c2_IN_cmd_slave_addr_n);
    chartInstance->c2_tp_cmd_slave_addr_n1 = (uint8_T)
      (chartInstance->c2_is_c2_mpu60502 == c2_IN_cmd_slave_addr_n1);
    chartInstance->c2_tp_cmd_slave_addr_p = (uint8_T)
      (chartInstance->c2_is_c2_mpu60502 == c2_IN_cmd_slave_addr_p);
    chartInstance->c2_tp_cmd_slave_addr_p1 = (uint8_T)
      (chartInstance->c2_is_c2_mpu60502 == c2_IN_cmd_slave_addr_p1);
    chartInstance->c2_tp_delay = (uint8_T)(chartInstance->c2_is_c2_mpu60502 ==
      c2_IN_delay);
    chartInstance->c2_tp_error_ack = (uint8_T)(chartInstance->c2_is_c2_mpu60502 ==
      c2_IN_error_ack);
    chartInstance->c2_tp_idle = (uint8_T)(chartInstance->c2_is_c2_mpu60502 ==
      c2_IN_idle);
    chartInstance->c2_tp_mastr_ack_data = (uint8_T)
      (chartInstance->c2_is_c2_mpu60502 == c2_IN_mastr_ack_data);
    chartInstance->c2_tp_mastr_ack_data_cnf = (uint8_T)
      (chartInstance->c2_is_c2_mpu60502 == c2_IN_mastr_ack_data_cnf);
    chartInstance->c2_tp_mastr_ack_data_cnf1 = (uint8_T)
      (chartInstance->c2_is_c2_mpu60502 == c2_IN_mastr_ack_data_cnf1);
    chartInstance->c2_tp_read_n = (uint8_T)(chartInstance->c2_is_c2_mpu60502 ==
      c2_IN_read_n);
    chartInstance->c2_tp_read_p = (uint8_T)(chartInstance->c2_is_c2_mpu60502 ==
      c2_IN_read_p);
    chartInstance->c2_tp_ready = (uint8_T)(chartInstance->c2_is_c2_mpu60502 ==
      c2_IN_ready);
    chartInstance->c2_tp_ready_repeated = (uint8_T)
      (chartInstance->c2_is_c2_mpu60502 == c2_IN_ready_repeated);
    chartInstance->c2_tp_ready_repeated_dummy = (uint8_T)
      (chartInstance->c2_is_c2_mpu60502 == c2_IN_ready_repeated_dummy);
    chartInstance->c2_tp_repeat_strt_n = (uint8_T)
      (chartInstance->c2_is_c2_mpu60502 == c2_IN_repeat_strt_n);
    chartInstance->c2_tp_repeat_strt_p = (uint8_T)
      (chartInstance->c2_is_c2_mpu60502 == c2_IN_repeat_strt_p);
    chartInstance->c2_tp_scl_ext_n = (uint8_T)(chartInstance->c2_is_c2_mpu60502 ==
      c2_IN_scl_ext_n);
    chartInstance->c2_tp_scl_ext_p = (uint8_T)(chartInstance->c2_is_c2_mpu60502 ==
      c2_IN_scl_ext_p);
    chartInstance->c2_tp_start_n = (uint8_T)(chartInstance->c2_is_c2_mpu60502 ==
      c2_IN_start_n);
    chartInstance->c2_tp_start_p = (uint8_T)(chartInstance->c2_is_c2_mpu60502 ==
      c2_IN_start_p);
    chartInstance->c2_tp_stop = (uint8_T)(chartInstance->c2_is_c2_mpu60502 ==
      c2_IN_stop);
    chartInstance->c2_tp_stop_ext = (uint8_T)(chartInstance->c2_is_c2_mpu60502 ==
      c2_IN_stop_ext);
    chartInstance->c2_tp_write_n = (uint8_T)(chartInstance->c2_is_c2_mpu60502 ==
      c2_IN_write_n);
    chartInstance->c2_tp_write_p = (uint8_T)(chartInstance->c2_is_c2_mpu60502 ==
      c2_IN_write_p);
    chartInstance->c2_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c2_mpu60502(SFc2_mpu60502InstanceStruct *chartInstance)
{
  sf_mex_destroy(&c2_eml_mx);
  sf_mex_destroy(&c2_b_eml_mx);
  sf_mex_destroy(&chartInstance->c2_setSimStateSideEffectsInfo);
}

static void sf_gateway_c2_mpu60502(SFc2_mpu60502InstanceStruct *chartInstance)
{
  c2_set_sim_state_side_effects_c2_mpu60502(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sda_in, 10U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_reg_data, 9U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_reg_addr_burstIn, 8U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_reg_addr, 7U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_slv_addr, 6U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_mode, 5U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_rd_wr, 4U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_enb, 3U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_mpu60502(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_mpu60502MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c2_mpu60502(SFc2_mpu60502InstanceStruct *chartInstance)
{
  c2_init_sf_message_store_memory(chartInstance);
}

static void c2_chartstep_c2_mpu60502(SFc2_mpu60502InstanceStruct *chartInstance)
{
  uint32_T c2_debug_family_var_map[2];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 0.0;
  real_T c2_b_nargin = 0.0;
  real_T c2_c_nargin = 0.0;
  real_T c2_d_nargin = 0.0;
  real_T c2_b_nargout = 0.0;
  real_T c2_c_nargout = 0.0;
  real_T c2_d_nargout = 0.0;
  real_T c2_e_nargin = 0.0;
  real_T c2_f_nargin = 0.0;
  real_T c2_e_nargout = 0.0;
  real_T c2_f_nargout = 0.0;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  switch (chartInstance->c2_is_c2_mpu60502) {
   case c2_IN_Increment_Byte_count1:
    CV_CHART_EVAL(1, 0, 1);
    c2_Increment_Byte_count1(chartInstance);
    break;

   case c2_IN_ack_addr_m:
    CV_CHART_EVAL(1, 0, 2);
    c2_ack_addr_m(chartInstance);
    break;

   case c2_IN_ack_addr_m_cnf:
    CV_CHART_EVAL(1, 0, 3);
    c2_ack_addr_m_cnf(chartInstance);
    break;

   case c2_IN_ack_addrm1:
    CV_CHART_EVAL(1, 0, 4);
    c2_ack_addrm1(chartInstance);
    break;

   case c2_IN_ack_data:
    CV_CHART_EVAL(1, 0, 5);
    c2_ack_data(chartInstance);
    break;

   case c2_IN_ack_end:
    CV_CHART_EVAL(1, 0, 6);
    c2_ack_end(chartInstance);
    break;

   case c2_IN_ack_end1:
    CV_CHART_EVAL(1, 0, 7);
    c2_ack_end1(chartInstance);
    break;

   case c2_IN_ack_recv_wr:
    CV_CHART_EVAL(1, 0, 8);
    c2_ack_recv_wr(chartInstance);
    break;

   case c2_IN_ack_recv_wr1:
    CV_CHART_EVAL(1, 0, 9);
    c2_ack_recv_wr1(chartInstance);
    break;

   case c2_IN_ack_recv_wr2:
    CV_CHART_EVAL(1, 0, 10);
    c2_ack_recv_wr2(chartInstance);
    break;

   case c2_IN_ack_recv_wr3:
    CV_CHART_EVAL(1, 0, 11);
    c2_ack_recv_wr3(chartInstance);
    break;

   case c2_IN_ack_slv:
    CV_CHART_EVAL(1, 0, 12);
    c2_ack_slv(chartInstance);
    break;

   case c2_IN_ack_slv1:
    CV_CHART_EVAL(1, 0, 13);
    c2_ack_slv1(chartInstance);
    break;

   case c2_IN_ack_slv_cnf1:
    CV_CHART_EVAL(1, 0, 14);
    c2_ack_slv_cnf1(chartInstance);
    break;

   case c2_IN_ack_wr_p:
    CV_CHART_EVAL(1, 0, 15);
    c2_ack_wr_p(chartInstance);
    break;

   case c2_IN_ack_wr_p2:
    CV_CHART_EVAL(1, 0, 16);
    c2_ack_wr_p2(chartInstance);
    break;

   case c2_IN_cmd_reg_addr_n:
    CV_CHART_EVAL(1, 0, 17);
    c2_cmd_reg_addr_n(chartInstance);
    break;

   case c2_IN_cmd_reg_addr_p:
    CV_CHART_EVAL(1, 0, 18);
    c2_cmd_reg_addr_p(chartInstance);
    break;

   case c2_IN_cmd_reg_data_n:
    CV_CHART_EVAL(1, 0, 19);
    c2_cmd_reg_data_n(chartInstance);
    break;

   case c2_IN_cmd_reg_data_p:
    CV_CHART_EVAL(1, 0, 20);
    c2_cmd_reg_data_p(chartInstance);
    break;

   case c2_IN_cmd_reg_read_data_n:
    CV_CHART_EVAL(1, 0, 21);
    c2_cmd_reg_read_data_n(chartInstance);
    break;

   case c2_IN_cmd_reg_read_data_p:
    CV_CHART_EVAL(1, 0, 22);
    c2_cmd_reg_read_data_p(chartInstance);
    break;

   case c2_IN_cmd_slave_addr_n:
    CV_CHART_EVAL(1, 0, 23);
    c2_cmd_slave_addr_n(chartInstance);
    break;

   case c2_IN_cmd_slave_addr_n1:
    CV_CHART_EVAL(1, 0, 24);
    c2_cmd_slave_addr_n1(chartInstance);
    break;

   case c2_IN_cmd_slave_addr_p:
    CV_CHART_EVAL(1, 0, 25);
    c2_cmd_slave_addr_p(chartInstance);
    break;

   case c2_IN_cmd_slave_addr_p1:
    CV_CHART_EVAL(1, 0, 26);
    c2_cmd_slave_addr_p1(chartInstance);
    break;

   case c2_IN_delay:
    CV_CHART_EVAL(1, 0, 27);
    c2_delay(chartInstance);
    break;

   case c2_IN_error_ack:
    CV_CHART_EVAL(1, 0, 28);
    c2_error_ack(chartInstance);
    break;

   case c2_IN_idle:
    CV_CHART_EVAL(1, 0, 29);
    c2_idle(chartInstance);
    break;

   case c2_IN_mastr_ack_data:
    CV_CHART_EVAL(1, 0, 30);
    c2_mastr_ack_data(chartInstance);
    break;

   case c2_IN_mastr_ack_data_cnf:
    CV_CHART_EVAL(1, 0, 31);
    c2_mastr_ack_data_cnf(chartInstance);
    break;

   case c2_IN_mastr_ack_data_cnf1:
    CV_CHART_EVAL(1, 0, 32);
    c2_mastr_ack_data_cnf1(chartInstance);
    break;

   case c2_IN_read_n:
    CV_CHART_EVAL(1, 0, 33);
    c2_read_n(chartInstance);
    break;

   case c2_IN_read_p:
    CV_CHART_EVAL(1, 0, 34);
    c2_read_p(chartInstance);
    break;

   case c2_IN_ready:
    CV_CHART_EVAL(1, 0, 35);
    c2_ready(chartInstance);
    break;

   case c2_IN_ready_repeated:
    CV_CHART_EVAL(1, 0, 36);
    c2_ready_repeated(chartInstance);
    break;

   case c2_IN_ready_repeated_dummy:
    CV_CHART_EVAL(1, 0, 37);
    c2_ready_repeated_dummy(chartInstance);
    break;

   case c2_IN_repeat_strt_n:
    CV_CHART_EVAL(1, 0, 38);
    c2_repeat_strt_n(chartInstance);
    break;

   case c2_IN_repeat_strt_p:
    CV_CHART_EVAL(1, 0, 39);
    c2_repeat_strt_p(chartInstance);
    break;

   case c2_IN_scl_ext_n:
    CV_CHART_EVAL(1, 0, 40);
    *chartInstance->c2_mstr_ack = false;
    chartInstance->c2_dataWrittenToVector[9U] = true;
    *chartInstance->c2_scl = false;
    chartInstance->c2_dataWrittenToVector[2U] = true;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 26U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_scl_ext_n = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 39U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_c2_mpu60502 = c2_IN_scl_ext_p;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 40U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_scl_ext_p = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_h_debug_family_names,
      c2_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_e_nargin, 0U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_e_nargout, 1U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    *chartInstance->c2_scl = true;
    chartInstance->c2_dataWrittenToVector[2U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_scl, 12U, 4U, 40U,
                          chartInstance->c2_sfEvent, false);
    *chartInstance->c2_sda = false;
    chartInstance->c2_dataWrittenToVector[3U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sda, 13U, 4U, 40U,
                          chartInstance->c2_sfEvent, false);
    *chartInstance->c2_ack = false;
    chartInstance->c2_dataWrittenToVector[4U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_ack, 14U, 4U, 40U,
                          chartInstance->c2_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 39U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_scl_ext_p:
    CV_CHART_EVAL(1, 0, 41);
    *chartInstance->c2_scl = true;
    chartInstance->c2_dataWrittenToVector[2U] = true;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_scl_ext_p = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 40U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_c2_mpu60502 = c2_IN_stop;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 43U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_stop = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_d_debug_family_names,
      c2_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargin, 0U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargout, 1U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    *chartInstance->c2_sda = false;
    chartInstance->c2_dataWrittenToVector[3U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sda, 13U, 4U, 43U,
                          chartInstance->c2_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 40U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_start_n:
    CV_CHART_EVAL(1, 0, 42);
    *chartInstance->c2_scl = true;
    chartInstance->c2_dataWrittenToVector[2U] = true;
    *chartInstance->c2_busy = true;
    chartInstance->c2_dataWrittenToVector[0U] = true;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_start_n = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 41U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_c2_mpu60502 = c2_IN_start_p;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 42U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_start_p = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_i_debug_family_names,
      c2_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_f_nargin, 0U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_f_nargout, 1U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    *chartInstance->c2_sda = false;
    chartInstance->c2_dataWrittenToVector[3U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sda, 13U, 4U, 42U,
                          chartInstance->c2_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 41U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_start_p:
    CV_CHART_EVAL(1, 0, 43);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 55U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_start_p = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 42U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_c2_mpu60502 = c2_IN_cmd_slave_addr_n;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 22U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_cmd_slave_addr_n = 1U;
    c2_enter_atomic_cmd_slave_addr_n(chartInstance);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 42U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_stop:
    CV_CHART_EVAL(1, 0, 44);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 53U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_stop = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 43U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_c2_mpu60502 = c2_IN_stop_ext;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 44U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_stop_ext = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_b_debug_family_names,
      c2_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    *chartInstance->c2_scl = true;
    chartInstance->c2_dataWrittenToVector[2U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_scl, 12U, 4U, 44U,
                          chartInstance->c2_sfEvent, false);
    *chartInstance->c2_sda = true;
    chartInstance->c2_dataWrittenToVector[3U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sda, 13U, 4U, 44U,
                          chartInstance->c2_sfEvent, false);
    *chartInstance->c2_ack = false;
    chartInstance->c2_dataWrittenToVector[4U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_ack, 14U, 4U, 44U,
                          chartInstance->c2_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 43U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_stop_ext:
    CV_CHART_EVAL(1, 0, 45);
    *chartInstance->c2_scl = true;
    chartInstance->c2_dataWrittenToVector[2U] = true;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_stop_ext = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 44U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_c2_mpu60502 = c2_IN_idle;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 28U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_idle = 1U;
    c2_enter_atomic_idle(chartInstance);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 44U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_write_n:
    CV_CHART_EVAL(1, 0, 46);
    *chartInstance->c2_scl = false;
    chartInstance->c2_dataWrittenToVector[2U] = true;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 23U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_write_n = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 45U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_c2_mpu60502 = c2_IN_write_p;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 46U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_write_p = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_s_debug_family_names,
      c2_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_c_nargin, 0U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_c_nargout, 1U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    *chartInstance->c2_scl = true;
    chartInstance->c2_dataWrittenToVector[2U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_scl, 12U, 4U, 46U,
                          chartInstance->c2_sfEvent, false);
    *chartInstance->c2_sda = false;
    chartInstance->c2_dataWrittenToVector[3U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sda, 13U, 4U, 46U,
                          chartInstance->c2_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 45U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_write_p:
    CV_CHART_EVAL(1, 0, 47);
    *chartInstance->c2_scl = true;
    chartInstance->c2_dataWrittenToVector[2U] = true;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 18U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_write_p = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 46U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_c2_mpu60502 = c2_IN_ack_slv;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_ack_slv = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_v_debug_family_names,
      c2_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_d_nargin, 0U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_d_nargout, 1U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    *chartInstance->c2_scl = false;
    chartInstance->c2_dataWrittenToVector[2U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_scl, 12U, 4U, 11U,
                          chartInstance->c2_sfEvent, false);
    *chartInstance->c2_ack = true;
    chartInstance->c2_dataWrittenToVector[4U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_ack, 14U, 4U, 11U,
                          chartInstance->c2_sfEvent, false);
    *chartInstance->c2_sda = true;
    chartInstance->c2_dataWrittenToVector[3U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sda, 13U, 4U, 11U,
                          chartInstance->c2_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 46U, chartInstance->c2_sfEvent);
    break;

   default:
    CV_CHART_EVAL(1, 0, 0);

    /* Unreachable state, for coverage only */
    chartInstance->c2_is_c2_mpu60502 = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
    break;
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_mpu60502(SFc2_mpu60502InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c2_enter_atomic_idle(SFc2_mpu60502InstanceStruct *chartInstance)
{
  uint32_T c2_debug_family_var_map[2];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 0.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  *chartInstance->c2_scl = true;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_scl, 12U, 4U, 28U,
                        chartInstance->c2_sfEvent, false);
  *chartInstance->c2_sda = true;
  chartInstance->c2_dataWrittenToVector[3U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sda, 13U, 4U, 28U,
                        chartInstance->c2_sfEvent, false);
  *chartInstance->c2_busy = false;
  chartInstance->c2_dataWrittenToVector[0U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_busy, 11U, 4U, 28U,
                        chartInstance->c2_sfEvent, false);
  *chartInstance->c2_reg_data_burst = false;
  chartInstance->c2_dataWrittenToVector[7U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_reg_data_burst, 16U, 4U, 28U,
                        chartInstance->c2_sfEvent, false);
  chartInstance->c2_temp_data = 0U;
  chartInstance->c2_dataWrittenToVector[11U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_temp_data, 2U, 4U, 28U,
                        chartInstance->c2_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c2_idle(SFc2_mpu60502InstanceStruct *chartInstance)
{
  uint32_T c2_debug_family_var_map[3];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 1.0;
  boolean_T c2_out;
  uint32_T c2_b_debug_family_var_map[2];
  real_T c2_b_nargin = 0.0;
  real_T c2_b_nargout = 0.0;
  *chartInstance->c2_scl = true;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  *chartInstance->c2_busy = false;
  chartInstance->c2_dataWrittenToVector[0U] = true;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 30U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c2_wb_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_out, 2U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  c2_out = CV_EML_IF(30, 0, 0, CV_RELATIONAL_EVAL(5U, 30U, 0, (real_T)
    *chartInstance->c2_enb, 1.0, -1, 0U, (int32_T)*chartInstance->c2_enb));
  _SFD_SYMBOL_SCOPE_POP();
  if (c2_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 30U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_idle = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 28U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_c2_mpu60502 = c2_IN_ready;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 34U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_ready = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_c_debug_family_names,
      c2_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargin, 0U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargout, 1U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    *chartInstance->c2_scl = true;
    chartInstance->c2_dataWrittenToVector[2U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_scl, 12U, 4U, 34U,
                          chartInstance->c2_sfEvent, false);
    *chartInstance->c2_sda = true;
    chartInstance->c2_dataWrittenToVector[3U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sda, 13U, 4U, 34U,
                          chartInstance->c2_sfEvent, false);
    *chartInstance->c2_data_out = 0U;
    chartInstance->c2_dataWrittenToVector[10U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_data_out, 19U, 4U, 34U,
                          chartInstance->c2_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 28U, chartInstance->c2_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 28U, chartInstance->c2_sfEvent);
}

static void c2_ready(SFc2_mpu60502InstanceStruct *chartInstance)
{
  uint32_T c2_debug_family_var_map[2];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 0.0;
  *chartInstance->c2_scl = true;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 54U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_ready = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 34U, chartInstance->c2_sfEvent);
  chartInstance->c2_is_c2_mpu60502 = c2_IN_start_n;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 41U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_start_n = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_e_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  *chartInstance->c2_scl = true;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_scl, 12U, 4U, 41U,
                        chartInstance->c2_sfEvent, false);
  *chartInstance->c2_sda = false;
  chartInstance->c2_dataWrittenToVector[3U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sda, 13U, 4U, 41U,
                        chartInstance->c2_sfEvent, false);
  chartInstance->c2_bit_cnt = 7U;
  chartInstance->c2_dataWrittenToVector[1U] = true;
  ssLoggerUpdateTimeseries(chartInstance->S,
    chartInstance->c2_dataSetLogObjVector[0], 0, _sfTime_, (char_T *)
    &chartInstance->c2_bit_cnt);
  chartInstance->c2_dataWrittenToVector[1U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_bit_cnt, 0U, 4U, 41U,
                        chartInstance->c2_sfEvent, false);
  *chartInstance->c2_busy = true;
  chartInstance->c2_dataWrittenToVector[0U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_busy, 11U, 4U, 41U,
                        chartInstance->c2_sfEvent, false);
  chartInstance->c2_reg_byte_cnt = 1U;
  chartInstance->c2_dataWrittenToVector[6U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_reg_byte_cnt, 1U, 4U, 41U,
                        chartInstance->c2_sfEvent, false);
  *chartInstance->c2_data_out = 0U;
  chartInstance->c2_dataWrittenToVector[10U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_data_out, 19U, 4U, 41U,
                        chartInstance->c2_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 34U, chartInstance->c2_sfEvent);
}

static void c2_mastr_ack_data_cnf1(SFc2_mpu60502InstanceStruct *chartInstance)
{
  uint32_T c2_debug_family_var_map[2];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 0.0;
  *chartInstance->c2_mstr_ack = true;
  chartInstance->c2_dataWrittenToVector[9U] = true;
  *chartInstance->c2_scl = true;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 50U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_mastr_ack_data_cnf1 = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 31U, chartInstance->c2_sfEvent);
  chartInstance->c2_is_c2_mpu60502 = c2_IN_scl_ext_n;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 39U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_scl_ext_n = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_j_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  *chartInstance->c2_scl = false;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_scl, 12U, 4U, 39U,
                        chartInstance->c2_sfEvent, false);
  *chartInstance->c2_sda = false;
  chartInstance->c2_dataWrittenToVector[3U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sda, 13U, 4U, 39U,
                        chartInstance->c2_sfEvent, false);
  *chartInstance->c2_ack = false;
  chartInstance->c2_dataWrittenToVector[4U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_ack, 14U, 4U, 39U,
                        chartInstance->c2_sfEvent, false);
  *chartInstance->c2_mstr_ack = false;
  chartInstance->c2_dataWrittenToVector[9U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_mstr_ack, 18U, 4U, 39U,
                        chartInstance->c2_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 31U, chartInstance->c2_sfEvent);
}

static void c2_mastr_ack_data_cnf(SFc2_mpu60502InstanceStruct *chartInstance)
{
  uint32_T c2_debug_family_var_map[2];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 0.0;
  *chartInstance->c2_mstr_ack = true;
  chartInstance->c2_dataWrittenToVector[9U] = true;
  *chartInstance->c2_scl = true;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_mastr_ack_data_cnf = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 30U, chartInstance->c2_sfEvent);
  chartInstance->c2_is_c2_mpu60502 = c2_IN_Increment_Byte_count1;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_Increment_Byte_count1 = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_m_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  *chartInstance->c2_scl = false;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_scl, 12U, 4U, 0U,
                        chartInstance->c2_sfEvent, false);
  chartInstance->c2_bit_cnt = 8U;
  chartInstance->c2_dataWrittenToVector[1U] = true;
  ssLoggerUpdateTimeseries(chartInstance->S,
    chartInstance->c2_dataSetLogObjVector[0], 0, _sfTime_, (char_T *)
    &chartInstance->c2_bit_cnt);
  chartInstance->c2_dataWrittenToVector[1U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_bit_cnt, 0U, 4U, 0U,
                        chartInstance->c2_sfEvent, false);
  *chartInstance->c2_mstr_ack = false;
  chartInstance->c2_dataWrittenToVector[9U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_mstr_ack, 18U, 4U, 0U,
                        chartInstance->c2_sfEvent, false);
  *chartInstance->c2_reg_data_burst = true;
  chartInstance->c2_dataWrittenToVector[7U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_reg_data_burst, 16U, 4U, 0U,
                        chartInstance->c2_sfEvent, false);
  *chartInstance->c2_sda = true;
  chartInstance->c2_dataWrittenToVector[3U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sda, 13U, 4U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 30U, chartInstance->c2_sfEvent);
}

static void c2_mastr_ack_data(SFc2_mpu60502InstanceStruct *chartInstance)
{
  uint32_T c2_debug_family_var_map[3];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 1.0;
  boolean_T c2_out;
  uint32_T c2_b_debug_family_var_map[2];
  real_T c2_b_nargin = 0.0;
  real_T c2_c_nargin = 0.0;
  real_T c2_b_nargout = 0.0;
  real_T c2_c_nargout = 0.0;
  *chartInstance->c2_mstr_ack = true;
  chartInstance->c2_dataWrittenToVector[9U] = true;
  *chartInstance->c2_scl = false;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 22U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c2_xb_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_out, 2U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  c2_out = CV_EML_IF(22, 0, 0, CV_RELATIONAL_EVAL(5U, 22U, 0, (real_T)
    *chartInstance->c2_mode, 1.0, -1, 0U, (int32_T)*chartInstance->c2_mode));
  _SFD_SYMBOL_SCOPE_POP();
  if (c2_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 22U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_mastr_ack_data = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 29U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_c2_mpu60502 = c2_IN_mastr_ack_data_cnf;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 30U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_mastr_ack_data_cnf = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_g_debug_family_names,
      c2_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_c_nargin, 0U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_c_nargout, 1U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    *chartInstance->c2_scl = true;
    chartInstance->c2_dataWrittenToVector[2U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_scl, 12U, 4U, 30U,
                          chartInstance->c2_sfEvent, false);
    *chartInstance->c2_sda = false;
    chartInstance->c2_dataWrittenToVector[3U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sda, 13U, 4U, 30U,
                          chartInstance->c2_sfEvent, false);
    *chartInstance->c2_mstr_ack = true;
    chartInstance->c2_dataWrittenToVector[9U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_mstr_ack, 18U, 4U, 30U,
                          chartInstance->c2_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 52U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_mastr_ack_data = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 29U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_c2_mpu60502 = c2_IN_mastr_ack_data_cnf1;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 31U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_mastr_ack_data_cnf1 = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_f_debug_family_names,
      c2_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargin, 0U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargout, 1U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    *chartInstance->c2_scl = true;
    chartInstance->c2_dataWrittenToVector[2U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_scl, 12U, 4U, 31U,
                          chartInstance->c2_sfEvent, false);
    *chartInstance->c2_sda = true;
    chartInstance->c2_dataWrittenToVector[3U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sda, 13U, 4U, 31U,
                          chartInstance->c2_sfEvent, false);
    *chartInstance->c2_mstr_ack = true;
    chartInstance->c2_dataWrittenToVector[9U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_mstr_ack, 18U, 4U, 31U,
                          chartInstance->c2_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 29U, chartInstance->c2_sfEvent);
}

static void c2_enter_atomic_cmd_slave_addr_n(SFc2_mpu60502InstanceStruct
  *chartInstance)
{
  uint32_T c2_debug_family_var_map[2];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 0.0;
  uint8_T c2_hoistedGlobal;
  uint8_T c2_b_hoistedGlobal;
  uint8_T c2_a;
  uint8_T c2_bit;
  uint8_T c2_x;
  boolean_T c2_p;
  uint8_T c2_b_a;
  uint8_T c2_a1;
  int32_T c2_c_a;
  boolean_T c2_b_p;
  uint8_T c2_b_x;
  boolean_T c2_b0;
  uint8_T c2_c_x;
  const mxArray *c2_y = NULL;
  static char_T c2_cv0[30] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'b', 'i', 't',
    'S', 'e', 't', 'G', 'e', 't', ':', 'B', 'I', 'T', 'O', 'u', 't', 'O', 'f',
    'R', 'a', 'n', 'g', 'e' };

  uint32_T c2_q0;
  uint32_T c2_qY;
  uint32_T c2_u0;
  uint8_T c2_bitkm1;
  uint8_T c2_c;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_l_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  *chartInstance->c2_scl = false;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_scl, 12U, 4U, 22U,
                        chartInstance->c2_sfEvent, false);
  if (!chartInstance->c2_dataWrittenToVector[1U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 22U, chartInstance->c2_sfEvent,
      false);
  }

  c2_hoistedGlobal = *chartInstance->c2_slv_addr;
  c2_b_hoistedGlobal = chartInstance->c2_bit_cnt;
  c2_a = c2_hoistedGlobal;
  c2_bit = c2_b_hoistedGlobal;
  c2_x = c2_bit;
  c2_p = true;
  c2_b_a = c2_x;
  c2_a1 = c2_b_a;
  c2_c_a = c2_a1;
  c2_b_p = (c2_c_a >= 1);
  if (c2_b_p && (c2_x <= 8)) {
    c2_b_x = c2_x;
    c2_c_x = c2_b_x;
    if (c2_x == c2_c_x) {
      c2_b0 = true;
    } else {
      c2_b0 = false;
    }
  } else {
    c2_b0 = false;
  }

  if (!c2_b0) {
    c2_p = false;
  }

  if (c2_p) {
  } else {
    c2_y = NULL;
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_cv0, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_y));
  }

  c2_q0 = c2_bit;
  c2_qY = c2_q0 - 1U;
  if (CV_SATURATION_EVAL(4, 22, 0, 0, c2_qY > c2_q0)) {
    c2_qY = 0U;
  }

  c2_u0 = c2_qY;
  if (CV_SATURATION_EVAL(4, 22, 0, 0, c2_u0 > 255U)) {
    c2_u0 = 255U;
  }

  c2_bitkm1 = (uint8_T)c2_u0;
  c2_c = (uint8_T)((uint8_T)(c2_a & (uint8_T)(1 << (uint8_T)
    sf_eml_shift_index_bounds_check(sfGlobalDebugInstanceStruct,
    chartInstance->S, 2166U, 47, 27, "", (int32_T)c2_bitkm1, 0, 7))) != 0);
  *chartInstance->c2_sda = (c2_c != 0);
  chartInstance->c2_dataWrittenToVector[3U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sda, 13U, 4U, 22U,
                        chartInstance->c2_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c2_cmd_slave_addr_n(SFc2_mpu60502InstanceStruct *chartInstance)
{
  uint32_T c2_debug_family_var_map[2];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 0.0;
  uint32_T c2_q0;
  uint32_T c2_qY;
  uint32_T c2_u1;
  *chartInstance->c2_scl = false;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 44U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_cmd_slave_addr_n = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, chartInstance->c2_sfEvent);
  chartInstance->c2_is_c2_mpu60502 = c2_IN_cmd_slave_addr_p;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 24U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_cmd_slave_addr_p = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_n_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  *chartInstance->c2_scl = true;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_scl, 12U, 4U, 24U,
                        chartInstance->c2_sfEvent, false);
  if (!chartInstance->c2_dataWrittenToVector[1U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 24U, chartInstance->c2_sfEvent,
      false);
  }

  c2_q0 = chartInstance->c2_bit_cnt;
  c2_qY = c2_q0 - 1U;
  if (CV_SATURATION_EVAL(4, 24, 0, 0, c2_qY > c2_q0)) {
    c2_qY = 0U;
  }

  c2_u1 = c2_qY;
  if (CV_SATURATION_EVAL(4, 24, 0, 0, c2_u1 > 255U)) {
    c2_u1 = 255U;
  }

  chartInstance->c2_bit_cnt = (uint8_T)c2_u1;
  chartInstance->c2_dataWrittenToVector[1U] = true;
  ssLoggerUpdateTimeseries(chartInstance->S,
    chartInstance->c2_dataSetLogObjVector[0], 0, _sfTime_, (char_T *)
    &chartInstance->c2_bit_cnt);
  chartInstance->c2_dataWrittenToVector[1U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_bit_cnt, 0U, 4U, 24U,
                        chartInstance->c2_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 22U, chartInstance->c2_sfEvent);
}

static void c2_Increment_Byte_count1(SFc2_mpu60502InstanceStruct *chartInstance)
{
  uint32_T c2_debug_family_var_map[2];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 0.0;
  *chartInstance->c2_mstr_ack = false;
  chartInstance->c2_dataWrittenToVector[9U] = true;
  *chartInstance->c2_scl = false;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 48U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_Increment_Byte_count1 = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
  chartInstance->c2_is_c2_mpu60502 = c2_IN_cmd_reg_read_data_n;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_cmd_reg_read_data_n = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_w_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  *chartInstance->c2_scl = false;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_scl, 12U, 4U, 20U,
                        chartInstance->c2_sfEvent, false);
  *chartInstance->c2_ack = true;
  chartInstance->c2_dataWrittenToVector[4U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_ack, 14U, 4U, 20U,
                        chartInstance->c2_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
}

static void c2_cmd_slave_addr_p(SFc2_mpu60502InstanceStruct *chartInstance)
{
  uint32_T c2_debug_family_var_map[3];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 1.0;
  boolean_T c2_out;
  uint32_T c2_b_debug_family_var_map[2];
  real_T c2_b_nargin = 0.0;
  real_T c2_b_nargout = 0.0;
  *chartInstance->c2_scl = true;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 19U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c2_yb_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_out, 2U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  if (!chartInstance->c2_dataWrittenToVector[1U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 5U, 19U, chartInstance->c2_sfEvent,
      false);
  }

  c2_out = CV_EML_IF(19, 0, 0, CV_RELATIONAL_EVAL(5U, 19U, 0, (real_T)
    chartInstance->c2_bit_cnt, 0.0, -1, 4U, (real_T)chartInstance->c2_bit_cnt >
    0.0));
  _SFD_SYMBOL_SCOPE_POP();
  if (c2_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 19U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_cmd_slave_addr_p = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 24U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_c2_mpu60502 = c2_IN_cmd_slave_addr_n;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 22U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_cmd_slave_addr_n = 1U;
    c2_enter_atomic_cmd_slave_addr_n(chartInstance);
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_cmd_slave_addr_p = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 24U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_c2_mpu60502 = c2_IN_write_n;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 45U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_write_n = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_o_debug_family_names,
      c2_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargin, 0U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargout, 1U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    *chartInstance->c2_scl = false;
    chartInstance->c2_dataWrittenToVector[2U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_scl, 12U, 4U, 45U,
                          chartInstance->c2_sfEvent, false);
    *chartInstance->c2_sda = false;
    chartInstance->c2_dataWrittenToVector[3U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sda, 13U, 4U, 45U,
                          chartInstance->c2_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 24U, chartInstance->c2_sfEvent);
}

static void c2_ack_end1(SFc2_mpu60502InstanceStruct *chartInstance)
{
  uint32_T c2_debug_family_var_map[2];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 0.0;
  *chartInstance->c2_scl = true;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 60U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_ack_end1 = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c2_sfEvent);
  chartInstance->c2_is_c2_mpu60502 = c2_IN_ack_end;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_ack_end = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_r_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  *chartInstance->c2_scl = true;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_scl, 12U, 4U, 5U,
                        chartInstance->c2_sfEvent, false);
  *chartInstance->c2_sda = true;
  chartInstance->c2_dataWrittenToVector[3U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sda, 13U, 4U, 5U,
                        chartInstance->c2_sfEvent, false);
  *chartInstance->c2_ack = true;
  chartInstance->c2_dataWrittenToVector[4U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_ack, 14U, 4U, 5U,
                        chartInstance->c2_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c2_sfEvent);
}

static void c2_cmd_reg_read_data_p(SFc2_mpu60502InstanceStruct *chartInstance)
{
  uint32_T c2_debug_family_var_map[3];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 1.0;
  boolean_T c2_out;
  uint32_T c2_b_debug_family_var_map[2];
  real_T c2_b_nargin = 0.0;
  real_T c2_c_nargin = 0.0;
  real_T c2_b_nargout = 0.0;
  real_T c2_c_nargout = 0.0;
  *chartInstance->c2_scl = true;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 31U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c2_dc_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_out, 2U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  if (!chartInstance->c2_dataWrittenToVector[1U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 5U, 31U, chartInstance->c2_sfEvent,
      false);
  }

  c2_out = CV_EML_IF(31, 0, 0, CV_RELATIONAL_EVAL(5U, 31U, 0, (real_T)
    chartInstance->c2_bit_cnt, 0.0, -1, 4U, (real_T)chartInstance->c2_bit_cnt >
    0.0));
  _SFD_SYMBOL_SCOPE_POP();
  if (c2_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 31U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_cmd_reg_read_data_p = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_c2_mpu60502 = c2_IN_cmd_reg_read_data_n;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_cmd_reg_read_data_n = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_w_debug_family_names,
      c2_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_c_nargin, 0U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_c_nargout, 1U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    *chartInstance->c2_scl = false;
    chartInstance->c2_dataWrittenToVector[2U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_scl, 12U, 4U, 20U,
                          chartInstance->c2_sfEvent, false);
    *chartInstance->c2_ack = true;
    chartInstance->c2_dataWrittenToVector[4U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_ack, 14U, 4U, 20U,
                          chartInstance->c2_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 32U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_cmd_reg_read_data_p = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_c2_mpu60502 = c2_IN_mastr_ack_data;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 29U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_mastr_ack_data = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_k_debug_family_names,
      c2_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargin, 0U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargout, 1U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    *chartInstance->c2_scl = false;
    chartInstance->c2_dataWrittenToVector[2U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_scl, 12U, 4U, 29U,
                          chartInstance->c2_sfEvent, false);
    if (CV_EML_IF(29, 1, 0, CV_RELATIONAL_EVAL(4U, 29U, 0, (real_T)
          *chartInstance->c2_mode, 1.0, -1, 0U, (int32_T)*chartInstance->c2_mode)))
    {
      *chartInstance->c2_sda = false;
      chartInstance->c2_dataWrittenToVector[3U] = true;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sda, 13U, 4U, 29U,
                            chartInstance->c2_sfEvent, false);
    } else {
      *chartInstance->c2_sda = true;
      chartInstance->c2_dataWrittenToVector[3U] = true;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sda, 13U, 4U, 29U,
                            chartInstance->c2_sfEvent, false);
    }

    *chartInstance->c2_mstr_ack = true;
    chartInstance->c2_dataWrittenToVector[9U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_mstr_ack, 18U, 4U, 29U,
                          chartInstance->c2_sfEvent, false);
    *chartInstance->c2_ack = false;
    chartInstance->c2_dataWrittenToVector[4U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_ack, 14U, 4U, 29U,
                          chartInstance->c2_sfEvent, false);
    if (!chartInstance->c2_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 29U, chartInstance->c2_sfEvent,
        false);
    }

    *chartInstance->c2_data_out = chartInstance->c2_temp_data;
    chartInstance->c2_dataWrittenToVector[10U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_data_out, 19U, 4U, 29U,
                          chartInstance->c2_sfEvent, false);
    chartInstance->c2_temp_data = 0U;
    chartInstance->c2_dataWrittenToVector[11U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_temp_data, 2U, 4U, 29U,
                          chartInstance->c2_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 21U, chartInstance->c2_sfEvent);
}

static void c2_ack_end(SFc2_mpu60502InstanceStruct *chartInstance)
{
  uint32_T c2_debug_family_var_map[3];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 1.0;
  boolean_T c2_out;
  real_T c2_b_nargin = 0.0;
  real_T c2_b_nargout = 1.0;
  boolean_T c2_b_out;
  uint32_T c2_b_debug_family_var_map[2];
  real_T c2_c_nargin = 0.0;
  real_T c2_c_nargout = 0.0;
  real_T c2_d_nargin = 0.0;
  real_T c2_d_nargout = 0.0;
  real_T c2_e_nargin = 0.0;
  real_T c2_e_nargout = 0.0;
  *chartInstance->c2_scl = true;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 36U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c2_ac_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_out, 2U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  c2_out = CV_EML_IF(36, 0, 0, CV_RELATIONAL_EVAL(5U, 36U, 0, (real_T)
    *chartInstance->c2_sda_in, 0.0, -1, 0U, !*chartInstance->c2_sda_in));
  _SFD_SYMBOL_SCOPE_POP();
  if (c2_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 36U, chartInstance->c2_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 38U,
                 chartInstance->c2_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c2_bc_debug_family_names,
      c2_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargin, 0U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargout, 1U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_out, 2U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    c2_b_out = CV_EML_IF(38, 0, 0, *chartInstance->c2_mode);
    _SFD_SYMBOL_SCOPE_POP();
    if (c2_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 38U, chartInstance->c2_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_cc_debug_family_names,
        c2_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_d_nargin, 0U, c2_sf_marshallOut,
        c2_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_d_nargout, 1U, c2_sf_marshallOut,
        c2_sf_marshallIn);
      chartInstance->c2_bit_cnt = 8U;
      chartInstance->c2_dataWrittenToVector[1U] = true;
      ssLoggerUpdateTimeseries(chartInstance->S,
        chartInstance->c2_dataSetLogObjVector[0], 0, _sfTime_, (char_T *)
        &chartInstance->c2_bit_cnt);
      chartInstance->c2_dataWrittenToVector[1U] = true;
      _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_bit_cnt, 0U, 5U, 38U,
                            chartInstance->c2_sfEvent, false);
      *chartInstance->c2_reg_data_burst = true;
      chartInstance->c2_dataWrittenToVector[7U] = true;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_reg_data_burst, 16U, 5U,
                            38U, chartInstance->c2_sfEvent, false);
      *chartInstance->c2_ack = false;
      chartInstance->c2_dataWrittenToVector[4U] = true;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_ack, 14U, 5U, 38U,
                            chartInstance->c2_sfEvent, false);
      _SFD_SYMBOL_SCOPE_POP();
      chartInstance->c2_tp_ack_end = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c2_sfEvent);
      chartInstance->c2_is_c2_mpu60502 = c2_IN_cmd_reg_data_n;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c2_sfEvent);
      chartInstance->c2_tp_cmd_reg_data_n = 1U;
      c2_enter_atomic_cmd_reg_data_n(chartInstance);
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 58U, chartInstance->c2_sfEvent);
      chartInstance->c2_tp_ack_end = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c2_sfEvent);
      chartInstance->c2_is_c2_mpu60502 = c2_IN_scl_ext_n;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 39U, chartInstance->c2_sfEvent);
      chartInstance->c2_tp_scl_ext_n = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_j_debug_family_names,
        c2_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_e_nargin, 0U, c2_sf_marshallOut,
        c2_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_e_nargout, 1U, c2_sf_marshallOut,
        c2_sf_marshallIn);
      *chartInstance->c2_scl = false;
      chartInstance->c2_dataWrittenToVector[2U] = true;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_scl, 12U, 4U, 39U,
                            chartInstance->c2_sfEvent, false);
      *chartInstance->c2_sda = false;
      chartInstance->c2_dataWrittenToVector[3U] = true;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sda, 13U, 4U, 39U,
                            chartInstance->c2_sfEvent, false);
      *chartInstance->c2_ack = false;
      chartInstance->c2_dataWrittenToVector[4U] = true;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_ack, 14U, 4U, 39U,
                            chartInstance->c2_sfEvent, false);
      *chartInstance->c2_mstr_ack = false;
      chartInstance->c2_dataWrittenToVector[9U] = true;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_mstr_ack, 18U, 4U, 39U,
                            chartInstance->c2_sfEvent, false);
      _SFD_SYMBOL_SCOPE_POP();
    }
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 20U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_ack_end = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_c2_mpu60502 = c2_IN_error_ack;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 27U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_error_ack = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_cb_debug_family_names,
      c2_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_c_nargin, 0U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_c_nargout, 1U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    *chartInstance->c2_scl = false;
    chartInstance->c2_dataWrittenToVector[2U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_scl, 12U, 4U, 27U,
                          chartInstance->c2_sfEvent, false);
    *chartInstance->c2_sda = true;
    chartInstance->c2_dataWrittenToVector[3U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sda, 13U, 4U, 27U,
                          chartInstance->c2_sfEvent, false);
    *chartInstance->c2_n_ack = true;
    chartInstance->c2_dataWrittenToVector[5U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_n_ack, 15U, 4U, 27U,
                          chartInstance->c2_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c2_sfEvent);
}

static void c2_ack_recv_wr3(SFc2_mpu60502InstanceStruct *chartInstance)
{
  uint32_T c2_debug_family_var_map[2];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 0.0;
  *chartInstance->c2_scl = true;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 61U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_ack_recv_wr3 = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c2_sfEvent);
  chartInstance->c2_is_c2_mpu60502 = c2_IN_ack_recv_wr;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_ack_recv_wr = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_x_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  *chartInstance->c2_scl = true;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_scl, 12U, 4U, 7U,
                        chartInstance->c2_sfEvent, false);
  *chartInstance->c2_sda = true;
  chartInstance->c2_dataWrittenToVector[3U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sda, 13U, 4U, 7U,
                        chartInstance->c2_sfEvent, false);
  *chartInstance->c2_ack = true;
  chartInstance->c2_dataWrittenToVector[4U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_ack, 14U, 4U, 7U,
                        chartInstance->c2_sfEvent, false);
  chartInstance->c2_bit_cnt = 8U;
  chartInstance->c2_dataWrittenToVector[1U] = true;
  ssLoggerUpdateTimeseries(chartInstance->S,
    chartInstance->c2_dataSetLogObjVector[0], 0, _sfTime_, (char_T *)
    &chartInstance->c2_bit_cnt);
  chartInstance->c2_dataWrittenToVector[1U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_bit_cnt, 0U, 4U, 7U,
                        chartInstance->c2_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c2_sfEvent);
}

static void c2_ack_data(SFc2_mpu60502InstanceStruct *chartInstance)
{
  uint32_T c2_debug_family_var_map[2];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 0.0;
  *chartInstance->c2_scl = false;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 47U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_ack_data = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c2_sfEvent);
  chartInstance->c2_is_c2_mpu60502 = c2_IN_ack_end1;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_ack_end1 = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_p_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  *chartInstance->c2_scl = true;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_scl, 12U, 4U, 6U,
                        chartInstance->c2_sfEvent, false);
  *chartInstance->c2_sda = true;
  chartInstance->c2_dataWrittenToVector[3U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sda, 13U, 4U, 6U,
                        chartInstance->c2_sfEvent, false);
  *chartInstance->c2_ack = true;
  chartInstance->c2_dataWrittenToVector[4U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_ack, 14U, 4U, 6U,
                        chartInstance->c2_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c2_sfEvent);
}

static void c2_ack_slv(SFc2_mpu60502InstanceStruct *chartInstance)
{
  uint32_T c2_debug_family_var_map[2];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 0.0;
  *chartInstance->c2_scl = false;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 46U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_ack_slv = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c2_sfEvent);
  chartInstance->c2_is_c2_mpu60502 = c2_IN_ack_recv_wr3;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_ack_recv_wr3 = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_t_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  *chartInstance->c2_scl = true;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_scl, 12U, 4U, 10U,
                        chartInstance->c2_sfEvent, false);
  *chartInstance->c2_sda = true;
  chartInstance->c2_dataWrittenToVector[3U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sda, 13U, 4U, 10U,
                        chartInstance->c2_sfEvent, false);
  *chartInstance->c2_ack = true;
  chartInstance->c2_dataWrittenToVector[4U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_ack, 14U, 4U, 10U,
                        chartInstance->c2_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c2_sfEvent);
}

static void c2_cmd_reg_read_data_n(SFc2_mpu60502InstanceStruct *chartInstance)
{
  uint32_T c2_debug_family_var_map[2];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 0.0;
  uint8_T c2_hoistedGlobal;
  uint8_T c2_b_hoistedGlobal;
  uint8_T c2_a;
  uint8_T c2_bit;
  uint8_T c2_x;
  boolean_T c2_p;
  uint8_T c2_b_a;
  uint32_T c2_q0;
  uint8_T c2_a1;
  uint32_T c2_qY;
  int32_T c2_c_a;
  boolean_T c2_b_p;
  uint32_T c2_u2;
  uint8_T c2_b_x;
  boolean_T c2_b1;
  uint8_T c2_c_x;
  const mxArray *c2_y = NULL;
  static char_T c2_cv1[30] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'b', 'i', 't',
    'S', 'e', 't', 'G', 'e', 't', ':', 'B', 'I', 'T', 'O', 'u', 't', 'O', 'f',
    'R', 'a', 'n', 'g', 'e' };

  uint32_T c2_b_q0;
  uint32_T c2_b_qY;
  uint32_T c2_u3;
  uint8_T c2_mask;
  uint8_T c2_c;
  *chartInstance->c2_scl = false;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 33U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_cmd_reg_read_data_n = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c2_sfEvent);
  chartInstance->c2_is_c2_mpu60502 = c2_IN_cmd_reg_read_data_p;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 21U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_cmd_reg_read_data_p = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_q_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  *chartInstance->c2_scl = true;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_scl, 12U, 4U, 21U,
                        chartInstance->c2_sfEvent, false);
  if (CV_EML_IF(21, 1, 0, CV_RELATIONAL_EVAL(4U, 21U, 0, (real_T)
        *chartInstance->c2_sda_in, 1.0, -1, 0U, (int32_T)
        *chartInstance->c2_sda_in))) {
    c2_hoistedGlobal = chartInstance->c2_temp_data;
    c2_b_hoistedGlobal = chartInstance->c2_bit_cnt;
    c2_a = c2_hoistedGlobal;
    c2_bit = c2_b_hoistedGlobal;
    c2_x = c2_bit;
    c2_p = true;
    c2_b_a = c2_x;
    c2_a1 = c2_b_a;
    c2_c_a = c2_a1;
    c2_b_p = (c2_c_a >= 1);
    if (c2_b_p && (c2_x <= 8)) {
      c2_b_x = c2_x;
      c2_c_x = c2_b_x;
      if (c2_x == c2_c_x) {
        c2_b1 = true;
      } else {
        c2_b1 = false;
      }
    } else {
      c2_b1 = false;
    }

    if (!c2_b1) {
      c2_p = false;
    }

    if (c2_p) {
    } else {
      c2_y = NULL;
      sf_mex_assign(&c2_y, sf_mex_create("y", c2_cv1, 10, 0U, 1U, 0U, 2, 1, 30),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
        1U, 1U, 14, c2_y));
    }

    c2_b_q0 = c2_bit;
    c2_b_qY = c2_b_q0 - 1U;
    if (CV_SATURATION_EVAL(4, 21, 1, 0, c2_b_qY > c2_b_q0)) {
      c2_b_qY = 0U;
    }

    c2_u3 = c2_b_qY;
    if (CV_SATURATION_EVAL(4, 21, 1, 0, c2_u3 > 255U)) {
      c2_u3 = 255U;
    }

    c2_mask = (uint8_T)(1 << (uint8_T)sf_eml_shift_index_bounds_check
                        (sfGlobalDebugInstanceStruct, chartInstance->S, 2179U,
                         71, 25, "", (int32_T)(uint8_T)c2_u3, 0, 7));
    c2_c = (uint8_T)(c2_a | c2_mask);
    chartInstance->c2_temp_data = c2_c;
    chartInstance->c2_dataWrittenToVector[11U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_temp_data, 2U, 4U, 21U,
                          chartInstance->c2_sfEvent, false);
  } else {
    if (!chartInstance->c2_dataWrittenToVector[1U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 21U, chartInstance->c2_sfEvent,
        false);
    }

    if (!chartInstance->c2_dataWrittenToVector[11U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 21U, chartInstance->c2_sfEvent,
        false);
    }
  }

  if (!chartInstance->c2_dataWrittenToVector[1U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 21U, chartInstance->c2_sfEvent,
      false);
  }

  c2_q0 = chartInstance->c2_bit_cnt;
  c2_qY = c2_q0 - 1U;
  if (CV_SATURATION_EVAL(4, 21, 0, 0, c2_qY > c2_q0)) {
    c2_qY = 0U;
  }

  c2_u2 = c2_qY;
  if (CV_SATURATION_EVAL(4, 21, 0, 0, c2_u2 > 255U)) {
    c2_u2 = 255U;
  }

  chartInstance->c2_bit_cnt = (uint8_T)c2_u2;
  chartInstance->c2_dataWrittenToVector[1U] = true;
  ssLoggerUpdateTimeseries(chartInstance->S,
    chartInstance->c2_dataSetLogObjVector[0], 0, _sfTime_, (char_T *)
    &chartInstance->c2_bit_cnt);
  chartInstance->c2_dataWrittenToVector[1U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_bit_cnt, 0U, 4U, 21U,
                        chartInstance->c2_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 20U, chartInstance->c2_sfEvent);
}

static void c2_ack_recv_wr(SFc2_mpu60502InstanceStruct *chartInstance)
{
  uint32_T c2_debug_family_var_map[3];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 1.0;
  boolean_T c2_out;
  uint32_T c2_b_debug_family_var_map[2];
  real_T c2_b_nargin = 0.0;
  real_T c2_c_nargin = 0.0;
  real_T c2_b_nargout = 0.0;
  real_T c2_c_nargout = 0.0;
  *chartInstance->c2_scl = true;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 21U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c2_fc_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_out, 2U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  c2_out = CV_EML_IF(21, 0, 0, CV_RELATIONAL_EVAL(5U, 21U, 0, (real_T)
    *chartInstance->c2_sda_in, 0.0, -1, 0U, !*chartInstance->c2_sda_in));
  _SFD_SYMBOL_SCOPE_POP();
  if (c2_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 21U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_ack_recv_wr = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_c2_mpu60502 = c2_IN_ack_wr_p;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_ack_wr_p = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_bb_debug_family_names,
      c2_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_c_nargin, 0U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_c_nargout, 1U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    *chartInstance->c2_scl = false;
    chartInstance->c2_dataWrittenToVector[2U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_scl, 12U, 4U, 14U,
                          chartInstance->c2_sfEvent, false);
    *chartInstance->c2_ack = false;
    chartInstance->c2_dataWrittenToVector[4U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_ack, 14U, 4U, 14U,
                          chartInstance->c2_sfEvent, false);
    *chartInstance->c2_sda = false;
    chartInstance->c2_dataWrittenToVector[3U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sda, 13U, 4U, 14U,
                          chartInstance->c2_sfEvent, false);
    chartInstance->c2_bit_cnt = 8U;
    chartInstance->c2_dataWrittenToVector[1U] = true;
    ssLoggerUpdateTimeseries(chartInstance->S,
      chartInstance->c2_dataSetLogObjVector[0], 0, _sfTime_, (char_T *)
      &chartInstance->c2_bit_cnt);
    chartInstance->c2_dataWrittenToVector[1U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_bit_cnt, 0U, 4U, 14U,
                          chartInstance->c2_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 17U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_ack_recv_wr = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_c2_mpu60502 = c2_IN_error_ack;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 27U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_error_ack = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_cb_debug_family_names,
      c2_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargin, 0U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargout, 1U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    *chartInstance->c2_scl = false;
    chartInstance->c2_dataWrittenToVector[2U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_scl, 12U, 4U, 27U,
                          chartInstance->c2_sfEvent, false);
    *chartInstance->c2_sda = true;
    chartInstance->c2_dataWrittenToVector[3U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sda, 13U, 4U, 27U,
                          chartInstance->c2_sfEvent, false);
    *chartInstance->c2_n_ack = true;
    chartInstance->c2_dataWrittenToVector[5U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_n_ack, 15U, 4U, 27U,
                          chartInstance->c2_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c2_sfEvent);
}

static void c2_cmd_reg_data_p(SFc2_mpu60502InstanceStruct *chartInstance)
{
  uint32_T c2_debug_family_var_map[3];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 1.0;
  boolean_T c2_out;
  uint32_T c2_b_debug_family_var_map[2];
  real_T c2_b_nargin = 0.0;
  real_T c2_b_nargout = 0.0;
  *chartInstance->c2_scl = true;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c2_ec_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_out, 2U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  if (!chartInstance->c2_dataWrittenToVector[1U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 5U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  c2_out = CV_EML_IF(0, 0, 0, CV_RELATIONAL_EVAL(5U, 0U, 0, (real_T)
    chartInstance->c2_bit_cnt, 0.0, -1, 4U, (real_T)chartInstance->c2_bit_cnt >
    0.0));
  _SFD_SYMBOL_SCOPE_POP();
  if (c2_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_cmd_reg_data_p = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_c2_mpu60502 = c2_IN_cmd_reg_data_n;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_cmd_reg_data_n = 1U;
    c2_enter_atomic_cmd_reg_data_n(chartInstance);
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 28U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_cmd_reg_data_p = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_c2_mpu60502 = c2_IN_ack_data;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_ack_data = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_u_debug_family_names,
      c2_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargin, 0U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargout, 1U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    *chartInstance->c2_scl = false;
    chartInstance->c2_dataWrittenToVector[2U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_scl, 12U, 4U, 4U,
                          chartInstance->c2_sfEvent, false);
    *chartInstance->c2_sda = true;
    chartInstance->c2_dataWrittenToVector[3U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sda, 13U, 4U, 4U,
                          chartInstance->c2_sfEvent, false);
    *chartInstance->c2_ack = true;
    chartInstance->c2_dataWrittenToVector[4U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_ack, 14U, 4U, 4U,
                          chartInstance->c2_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19U, chartInstance->c2_sfEvent);
}

static void c2_ack_addr_m_cnf(SFc2_mpu60502InstanceStruct *chartInstance)
{
  uint32_T c2_debug_family_var_map[3];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 1.0;
  boolean_T c2_out;
  real_T c2_b_nargin = 0.0;
  real_T c2_b_nargout = 1.0;
  boolean_T c2_b_out;
  uint32_T c2_b_debug_family_var_map[2];
  real_T c2_c_nargin = 0.0;
  real_T c2_c_nargout = 0.0;
  *chartInstance->c2_scl = false;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c2_gc_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_out, 2U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  c2_out = CV_EML_IF(4, 0, 0, CV_RELATIONAL_EVAL(5U, 4U, 0, (real_T)
    *chartInstance->c2_rd_wr, 0.0, -1, 0U, !*chartInstance->c2_rd_wr));
  _SFD_SYMBOL_SCOPE_POP();
  if (c2_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_ack_addr_m_cnf = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_c2_mpu60502 = c2_IN_cmd_reg_data_n;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_cmd_reg_data_n = 1U;
    c2_enter_atomic_cmd_reg_data_n(chartInstance);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 11U,
                 chartInstance->c2_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c2_ic_debug_family_names,
      c2_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargin, 0U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargout, 1U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_out, 2U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    c2_b_out = CV_EML_IF(11, 0, 0, CV_RELATIONAL_EVAL(5U, 11U, 0, (real_T)
      *chartInstance->c2_rd_wr, 1.0, -1, 0U, (int32_T)*chartInstance->c2_rd_wr));
    _SFD_SYMBOL_SCOPE_POP();
    if (c2_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c2_sfEvent);
      chartInstance->c2_tp_ack_addr_m_cnf = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
      chartInstance->c2_is_c2_mpu60502 = c2_IN_delay;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 26U, chartInstance->c2_sfEvent);
      chartInstance->c2_tp_delay = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_eb_debug_family_names,
        c2_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_c_nargin, 0U, c2_sf_marshallOut,
        c2_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_c_nargout, 1U, c2_sf_marshallOut,
        c2_sf_marshallIn);
      *chartInstance->c2_scl = false;
      chartInstance->c2_dataWrittenToVector[2U] = true;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_scl, 12U, 4U, 26U,
                            chartInstance->c2_sfEvent, false);
      *chartInstance->c2_sda = true;
      chartInstance->c2_dataWrittenToVector[3U] = true;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sda, 13U, 4U, 26U,
                            chartInstance->c2_sfEvent, false);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                   chartInstance->c2_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c2_sfEvent);
}

static void c2_ack_wr_p(SFc2_mpu60502InstanceStruct *chartInstance)
{
  *chartInstance->c2_scl = false;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 56U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_ack_wr_p = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c2_sfEvent);
  chartInstance->c2_is_c2_mpu60502 = c2_IN_cmd_reg_addr_n;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_cmd_reg_addr_n = 1U;
  c2_enter_atomic_cmd_reg_addr_n(chartInstance);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, chartInstance->c2_sfEvent);
}

static void c2_error_ack(SFc2_mpu60502InstanceStruct *chartInstance)
{
  uint32_T c2_debug_family_var_map[2];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 0.0;
  *chartInstance->c2_n_ack = true;
  chartInstance->c2_dataWrittenToVector[5U] = true;
  *chartInstance->c2_scl = false;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_error_ack = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 27U, chartInstance->c2_sfEvent);
  chartInstance->c2_is_c2_mpu60502 = c2_IN_scl_ext_n;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 39U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_scl_ext_n = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_j_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  *chartInstance->c2_scl = false;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_scl, 12U, 4U, 39U,
                        chartInstance->c2_sfEvent, false);
  *chartInstance->c2_sda = false;
  chartInstance->c2_dataWrittenToVector[3U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sda, 13U, 4U, 39U,
                        chartInstance->c2_sfEvent, false);
  *chartInstance->c2_ack = false;
  chartInstance->c2_dataWrittenToVector[4U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_ack, 14U, 4U, 39U,
                        chartInstance->c2_sfEvent, false);
  *chartInstance->c2_mstr_ack = false;
  chartInstance->c2_dataWrittenToVector[9U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_mstr_ack, 18U, 4U, 39U,
                        chartInstance->c2_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 27U, chartInstance->c2_sfEvent);
}

static void c2_enter_atomic_cmd_reg_data_n(SFc2_mpu60502InstanceStruct
  *chartInstance)
{
  uint32_T c2_debug_family_var_map[2];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 0.0;
  uint8_T c2_hoistedGlobal;
  uint8_T c2_b_hoistedGlobal;
  uint8_T c2_a;
  uint8_T c2_bit;
  uint8_T c2_x;
  boolean_T c2_p;
  uint8_T c2_b_a;
  uint8_T c2_a1;
  int32_T c2_c_a;
  boolean_T c2_b_p;
  uint8_T c2_b_x;
  boolean_T c2_b2;
  uint8_T c2_c_x;
  const mxArray *c2_y = NULL;
  static char_T c2_cv2[30] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'b', 'i', 't',
    'S', 'e', 't', 'G', 'e', 't', ':', 'B', 'I', 'T', 'O', 'u', 't', 'O', 'f',
    'R', 'a', 'n', 'g', 'e' };

  uint32_T c2_q0;
  uint32_T c2_qY;
  uint32_T c2_u4;
  uint8_T c2_bitkm1;
  uint8_T c2_c;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_db_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  *chartInstance->c2_scl = false;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_scl, 12U, 4U, 18U,
                        chartInstance->c2_sfEvent, false);
  *chartInstance->c2_ack = false;
  chartInstance->c2_dataWrittenToVector[4U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_ack, 14U, 4U, 18U,
                        chartInstance->c2_sfEvent, false);
  *chartInstance->c2_reg_data_burst = false;
  chartInstance->c2_dataWrittenToVector[7U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_reg_data_burst, 16U, 4U, 18U,
                        chartInstance->c2_sfEvent, false);
  if (!chartInstance->c2_dataWrittenToVector[1U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 18U, chartInstance->c2_sfEvent,
      false);
  }

  c2_hoistedGlobal = *chartInstance->c2_reg_data;
  c2_b_hoistedGlobal = chartInstance->c2_bit_cnt;
  c2_a = c2_hoistedGlobal;
  c2_bit = c2_b_hoistedGlobal;
  c2_x = c2_bit;
  c2_p = true;
  c2_b_a = c2_x;
  c2_a1 = c2_b_a;
  c2_c_a = c2_a1;
  c2_b_p = (c2_c_a >= 1);
  if (c2_b_p && (c2_x <= 8)) {
    c2_b_x = c2_x;
    c2_c_x = c2_b_x;
    if (c2_x == c2_c_x) {
      c2_b2 = true;
    } else {
      c2_b2 = false;
    }
  } else {
    c2_b2 = false;
  }

  if (!c2_b2) {
    c2_p = false;
  }

  if (c2_p) {
  } else {
    c2_y = NULL;
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_cv2, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_y));
  }

  c2_q0 = c2_bit;
  c2_qY = c2_q0 - 1U;
  if (CV_SATURATION_EVAL(4, 18, 0, 0, c2_qY > c2_q0)) {
    c2_qY = 0U;
  }

  c2_u4 = c2_qY;
  if (CV_SATURATION_EVAL(4, 18, 0, 0, c2_u4 > 255U)) {
    c2_u4 = 255U;
  }

  c2_bitkm1 = (uint8_T)c2_u4;
  c2_c = (uint8_T)((uint8_T)(c2_a & (uint8_T)(1 << (uint8_T)
    sf_eml_shift_index_bounds_check(sfGlobalDebugInstanceStruct,
    chartInstance->S, 2188U, 78, 24, "", (int32_T)c2_bitkm1, 0, 7))) != 0);
  *chartInstance->c2_sda = (c2_c != 0);
  chartInstance->c2_dataWrittenToVector[3U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sda, 13U, 4U, 18U,
                        chartInstance->c2_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c2_cmd_reg_data_n(SFc2_mpu60502InstanceStruct *chartInstance)
{
  uint32_T c2_debug_family_var_map[2];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 0.0;
  uint32_T c2_q0;
  uint32_T c2_qY;
  uint32_T c2_u5;
  *chartInstance->c2_scl = false;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_cmd_reg_data_n = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c2_sfEvent);
  chartInstance->c2_is_c2_mpu60502 = c2_IN_cmd_reg_data_p;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_cmd_reg_data_p = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_y_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  *chartInstance->c2_scl = true;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_scl, 12U, 4U, 19U,
                        chartInstance->c2_sfEvent, false);
  if (!chartInstance->c2_dataWrittenToVector[1U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 19U, chartInstance->c2_sfEvent,
      false);
  }

  c2_q0 = chartInstance->c2_bit_cnt;
  c2_qY = c2_q0 - 1U;
  if (CV_SATURATION_EVAL(4, 19, 0, 0, c2_qY > c2_q0)) {
    c2_qY = 0U;
  }

  c2_u5 = c2_qY;
  if (CV_SATURATION_EVAL(4, 19, 0, 0, c2_u5 > 255U)) {
    c2_u5 = 255U;
  }

  chartInstance->c2_bit_cnt = (uint8_T)c2_u5;
  chartInstance->c2_dataWrittenToVector[1U] = true;
  ssLoggerUpdateTimeseries(chartInstance->S,
    chartInstance->c2_dataSetLogObjVector[0], 0, _sfTime_, (char_T *)
    &chartInstance->c2_bit_cnt);
  chartInstance->c2_dataWrittenToVector[1U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_bit_cnt, 0U, 4U, 19U,
                        chartInstance->c2_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 18U, chartInstance->c2_sfEvent);
}

static void c2_delay(SFc2_mpu60502InstanceStruct *chartInstance)
{
  uint32_T c2_debug_family_var_map[2];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 0.0;
  *chartInstance->c2_scl = false;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 57U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_delay = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 26U, chartInstance->c2_sfEvent);
  chartInstance->c2_is_c2_mpu60502 = c2_IN_ready_repeated;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 35U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_ready_repeated = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_hb_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  *chartInstance->c2_scl = true;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_scl, 12U, 4U, 35U,
                        chartInstance->c2_sfEvent, false);
  *chartInstance->c2_sda = true;
  chartInstance->c2_dataWrittenToVector[3U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sda, 13U, 4U, 35U,
                        chartInstance->c2_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 26U, chartInstance->c2_sfEvent);
}

static void c2_enter_atomic_cmd_reg_addr_n(SFc2_mpu60502InstanceStruct
  *chartInstance)
{
  uint32_T c2_debug_family_var_map[2];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 0.0;
  uint8_T c2_hoistedGlobal;
  uint8_T c2_b_hoistedGlobal;
  uint8_T c2_a;
  uint8_T c2_bit;
  uint8_T c2_x;
  boolean_T c2_p;
  uint8_T c2_b_a;
  uint8_T c2_a1;
  int32_T c2_c_a;
  boolean_T c2_b_p;
  uint8_T c2_b_x;
  boolean_T c2_b3;
  uint8_T c2_c_x;
  const mxArray *c2_y = NULL;
  static char_T c2_cv3[30] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'b', 'i', 't',
    'S', 'e', 't', 'G', 'e', 't', ':', 'B', 'I', 'T', 'O', 'u', 't', 'O', 'f',
    'R', 'a', 'n', 'g', 'e' };

  uint32_T c2_q0;
  uint32_T c2_qY;
  uint32_T c2_u6;
  uint8_T c2_bitkm1;
  uint8_T c2_c;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_fb_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  *chartInstance->c2_scl = false;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_scl, 12U, 4U, 16U,
                        chartInstance->c2_sfEvent, false);
  *chartInstance->c2_ack = false;
  chartInstance->c2_dataWrittenToVector[4U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_ack, 14U, 4U, 16U,
                        chartInstance->c2_sfEvent, false);
  if (!chartInstance->c2_dataWrittenToVector[1U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 16U, chartInstance->c2_sfEvent,
      false);
  }

  c2_hoistedGlobal = *chartInstance->c2_reg_addr;
  c2_b_hoistedGlobal = chartInstance->c2_bit_cnt;
  c2_a = c2_hoistedGlobal;
  c2_bit = c2_b_hoistedGlobal;
  c2_x = c2_bit;
  c2_p = true;
  c2_b_a = c2_x;
  c2_a1 = c2_b_a;
  c2_c_a = c2_a1;
  c2_b_p = (c2_c_a >= 1);
  if (c2_b_p && (c2_x <= 8)) {
    c2_b_x = c2_x;
    c2_c_x = c2_b_x;
    if (c2_x == c2_c_x) {
      c2_b3 = true;
    } else {
      c2_b3 = false;
    }
  } else {
    c2_b3 = false;
  }

  if (!c2_b3) {
    c2_p = false;
  }

  if (c2_p) {
  } else {
    c2_y = NULL;
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_cv3, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_y));
  }

  c2_q0 = c2_bit;
  c2_qY = c2_q0 - 1U;
  if (CV_SATURATION_EVAL(4, 16, 0, 0, c2_qY > c2_q0)) {
    c2_qY = 0U;
  }

  c2_u6 = c2_qY;
  if (CV_SATURATION_EVAL(4, 16, 0, 0, c2_u6 > 255U)) {
    c2_u6 = 255U;
  }

  c2_bitkm1 = (uint8_T)c2_u6;
  c2_c = (uint8_T)((uint8_T)(c2_a & (uint8_T)(1 << (uint8_T)
    sf_eml_shift_index_bounds_check(sfGlobalDebugInstanceStruct,
    chartInstance->S, 2172U, 58, 24, "", (int32_T)c2_bitkm1, 0, 7))) != 0);
  *chartInstance->c2_sda = (c2_c != 0);
  chartInstance->c2_dataWrittenToVector[3U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sda, 13U, 4U, 16U,
                        chartInstance->c2_sfEvent, false);
  *chartInstance->c2_reg_addr_burst = false;
  chartInstance->c2_dataWrittenToVector[8U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_reg_addr_burst, 17U, 4U, 16U,
                        chartInstance->c2_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c2_cmd_reg_addr_n(SFc2_mpu60502InstanceStruct *chartInstance)
{
  uint32_T c2_debug_family_var_map[2];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 0.0;
  uint32_T c2_q0;
  uint32_T c2_qY;
  uint32_T c2_u7;
  *chartInstance->c2_scl = false;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  *chartInstance->c2_reg_addr_burst = false;
  chartInstance->c2_dataWrittenToVector[8U] = true;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 25U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_cmd_reg_addr_n = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c2_sfEvent);
  chartInstance->c2_is_c2_mpu60502 = c2_IN_cmd_reg_addr_p;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_cmd_reg_addr_p = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_ib_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  *chartInstance->c2_scl = true;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_scl, 12U, 4U, 17U,
                        chartInstance->c2_sfEvent, false);
  if (!chartInstance->c2_dataWrittenToVector[1U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 17U, chartInstance->c2_sfEvent,
      false);
  }

  c2_q0 = chartInstance->c2_bit_cnt;
  c2_qY = c2_q0 - 1U;
  if (CV_SATURATION_EVAL(4, 17, 0, 0, c2_qY > c2_q0)) {
    c2_qY = 0U;
  }

  c2_u7 = c2_qY;
  if (CV_SATURATION_EVAL(4, 17, 0, 0, c2_u7 > 255U)) {
    c2_u7 = 255U;
  }

  chartInstance->c2_bit_cnt = (uint8_T)c2_u7;
  chartInstance->c2_dataWrittenToVector[1U] = true;
  ssLoggerUpdateTimeseries(chartInstance->S,
    chartInstance->c2_dataSetLogObjVector[0], 0, _sfTime_, (char_T *)
    &chartInstance->c2_bit_cnt);
  chartInstance->c2_dataWrittenToVector[1U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_bit_cnt, 0U, 4U, 17U,
                        chartInstance->c2_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, chartInstance->c2_sfEvent);
}

static void c2_repeat_strt_n(SFc2_mpu60502InstanceStruct *chartInstance)
{
  uint32_T c2_debug_family_var_map[2];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 0.0;
  *chartInstance->c2_scl = true;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  *chartInstance->c2_busy = true;
  chartInstance->c2_dataWrittenToVector[0U] = true;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 41U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_repeat_strt_n = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 37U, chartInstance->c2_sfEvent);
  chartInstance->c2_is_c2_mpu60502 = c2_IN_repeat_strt_p;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 38U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_repeat_strt_p = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_jb_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  *chartInstance->c2_sda = false;
  chartInstance->c2_dataWrittenToVector[3U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sda, 13U, 4U, 38U,
                        chartInstance->c2_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 37U, chartInstance->c2_sfEvent);
}

static void c2_ready_repeated(SFc2_mpu60502InstanceStruct *chartInstance)
{
  uint32_T c2_debug_family_var_map[2];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 0.0;
  *chartInstance->c2_scl = true;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 37U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_ready_repeated = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 35U, chartInstance->c2_sfEvent);
  chartInstance->c2_is_c2_mpu60502 = c2_IN_ready_repeated_dummy;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 36U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_ready_repeated_dummy = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_kb_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  *chartInstance->c2_scl = true;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_scl, 12U, 4U, 36U,
                        chartInstance->c2_sfEvent, false);
  *chartInstance->c2_sda = true;
  chartInstance->c2_dataWrittenToVector[3U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sda, 13U, 4U, 36U,
                        chartInstance->c2_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 35U, chartInstance->c2_sfEvent);
}

static void c2_cmd_reg_addr_p(SFc2_mpu60502InstanceStruct *chartInstance)
{
  uint32_T c2_debug_family_var_map[3];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 1.0;
  boolean_T c2_out;
  uint32_T c2_b_debug_family_var_map[2];
  real_T c2_b_nargin = 0.0;
  real_T c2_b_nargout = 0.0;
  *chartInstance->c2_scl = true;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 24U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c2_jc_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_out, 2U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  if (!chartInstance->c2_dataWrittenToVector[1U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 5U, 24U, chartInstance->c2_sfEvent,
      false);
  }

  c2_out = CV_EML_IF(24, 0, 0, CV_RELATIONAL_EVAL(5U, 24U, 0, (real_T)
    chartInstance->c2_bit_cnt, 0.0, -1, 4U, (real_T)chartInstance->c2_bit_cnt >
    0.0));
  _SFD_SYMBOL_SCOPE_POP();
  if (c2_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 24U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_cmd_reg_addr_p = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_c2_mpu60502 = c2_IN_cmd_reg_addr_n;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_cmd_reg_addr_n = 1U;
    c2_enter_atomic_cmd_reg_addr_n(chartInstance);
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 29U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_cmd_reg_addr_p = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_c2_mpu60502 = c2_IN_ack_addr_m;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_ack_addr_m = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_lb_debug_family_names,
      c2_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargin, 0U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargout, 1U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    *chartInstance->c2_scl = false;
    chartInstance->c2_dataWrittenToVector[2U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_scl, 12U, 4U, 1U,
                          chartInstance->c2_sfEvent, false);
    *chartInstance->c2_ack = true;
    chartInstance->c2_dataWrittenToVector[4U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_ack, 14U, 4U, 1U,
                          chartInstance->c2_sfEvent, false);
    *chartInstance->c2_sda = true;
    chartInstance->c2_dataWrittenToVector[3U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sda, 13U, 4U, 1U,
                          chartInstance->c2_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 17U, chartInstance->c2_sfEvent);
}

static void c2_repeat_strt_p(SFc2_mpu60502InstanceStruct *chartInstance)
{
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 40U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_repeat_strt_p = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 38U, chartInstance->c2_sfEvent);
  chartInstance->c2_is_c2_mpu60502 = c2_IN_cmd_slave_addr_n1;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 23U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_cmd_slave_addr_n1 = 1U;
  c2_enter_atomic_cmd_slave_addr_n1(chartInstance);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 38U, chartInstance->c2_sfEvent);
}

static void c2_ready_repeated_dummy(SFc2_mpu60502InstanceStruct *chartInstance)
{
  uint32_T c2_debug_family_var_map[2];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 0.0;
  *chartInstance->c2_scl = true;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_ready_repeated_dummy = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 36U, chartInstance->c2_sfEvent);
  chartInstance->c2_is_c2_mpu60502 = c2_IN_repeat_strt_n;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 37U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_repeat_strt_n = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_gb_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  *chartInstance->c2_scl = true;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_scl, 12U, 4U, 37U,
                        chartInstance->c2_sfEvent, false);
  *chartInstance->c2_sda = false;
  chartInstance->c2_dataWrittenToVector[3U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sda, 13U, 4U, 37U,
                        chartInstance->c2_sfEvent, false);
  chartInstance->c2_bit_cnt = 7U;
  chartInstance->c2_dataWrittenToVector[1U] = true;
  ssLoggerUpdateTimeseries(chartInstance->S,
    chartInstance->c2_dataSetLogObjVector[0], 0, _sfTime_, (char_T *)
    &chartInstance->c2_bit_cnt);
  chartInstance->c2_dataWrittenToVector[1U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_bit_cnt, 0U, 4U, 37U,
                        chartInstance->c2_sfEvent, false);
  *chartInstance->c2_busy = true;
  chartInstance->c2_dataWrittenToVector[0U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_busy, 11U, 4U, 37U,
                        chartInstance->c2_sfEvent, false);
  chartInstance->c2_reg_byte_cnt = 1U;
  chartInstance->c2_dataWrittenToVector[6U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_reg_byte_cnt, 1U, 4U, 37U,
                        chartInstance->c2_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 36U, chartInstance->c2_sfEvent);
}

static void c2_ack_addr_m(SFc2_mpu60502InstanceStruct *chartInstance)
{
  uint32_T c2_debug_family_var_map[3];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 1.0;
  boolean_T c2_out;
  uint32_T c2_b_debug_family_var_map[2];
  real_T c2_b_nargin = 0.0;
  real_T c2_c_nargin = 0.0;
  real_T c2_b_nargout = 0.0;
  real_T c2_c_nargout = 0.0;
  *chartInstance->c2_scl = false;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 39U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c2_kc_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_out, 2U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  c2_out = CV_EML_IF(39, 0, 0, CV_RELATIONAL_EVAL(5U, 39U, 0, (real_T)
    *chartInstance->c2_reg_addr_burstIn, 1.0, -1, 0U, (int32_T)
    *chartInstance->c2_reg_addr_burstIn));
  _SFD_SYMBOL_SCOPE_POP();
  if (c2_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 39U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_ack_addr_m = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_c2_mpu60502 = c2_IN_ack_addrm1;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_ack_addrm1 = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_qb_debug_family_names,
      c2_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_c_nargin, 0U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_c_nargout, 1U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    *chartInstance->c2_scl = true;
    chartInstance->c2_dataWrittenToVector[2U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_scl, 12U, 4U, 3U,
                          chartInstance->c2_sfEvent, false);
    *chartInstance->c2_ack = false;
    chartInstance->c2_dataWrittenToVector[4U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_ack, 14U, 4U, 3U,
                          chartInstance->c2_sfEvent, false);
    chartInstance->c2_bit_cnt = 8U;
    chartInstance->c2_dataWrittenToVector[1U] = true;
    ssLoggerUpdateTimeseries(chartInstance->S,
      chartInstance->c2_dataSetLogObjVector[0], 0, _sfTime_, (char_T *)
      &chartInstance->c2_bit_cnt);
    chartInstance->c2_dataWrittenToVector[1U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_bit_cnt, 0U, 4U, 3U,
                          chartInstance->c2_sfEvent, false);
    *chartInstance->c2_reg_addr_burst = true;
    chartInstance->c2_dataWrittenToVector[8U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_reg_addr_burst, 17U, 4U, 3U,
                          chartInstance->c2_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 51U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_ack_addr_m = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_c2_mpu60502 = c2_IN_ack_recv_wr1;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_ack_recv_wr1 = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_mb_debug_family_names,
      c2_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargin, 0U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargout, 1U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    *chartInstance->c2_scl = true;
    chartInstance->c2_dataWrittenToVector[2U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_scl, 12U, 4U, 8U,
                          chartInstance->c2_sfEvent, false);
    *chartInstance->c2_sda = true;
    chartInstance->c2_dataWrittenToVector[3U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sda, 13U, 4U, 8U,
                          chartInstance->c2_sfEvent, false);
    *chartInstance->c2_ack = true;
    chartInstance->c2_dataWrittenToVector[4U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_ack, 14U, 4U, 8U,
                          chartInstance->c2_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
}

static void c2_ack_recv_wr1(SFc2_mpu60502InstanceStruct *chartInstance)
{
  uint32_T c2_debug_family_var_map[2];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 0.0;
  *chartInstance->c2_scl = true;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 59U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_ack_recv_wr1 = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c2_sfEvent);
  chartInstance->c2_is_c2_mpu60502 = c2_IN_ack_recv_wr2;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_ack_recv_wr2 = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_nb_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  *chartInstance->c2_scl = true;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_scl, 12U, 4U, 9U,
                        chartInstance->c2_sfEvent, false);
  *chartInstance->c2_sda = true;
  chartInstance->c2_dataWrittenToVector[3U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sda, 13U, 4U, 9U,
                        chartInstance->c2_sfEvent, false);
  *chartInstance->c2_ack = true;
  chartInstance->c2_dataWrittenToVector[4U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_ack, 14U, 4U, 9U,
                        chartInstance->c2_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c2_sfEvent);
}

static void c2_ack_recv_wr2(SFc2_mpu60502InstanceStruct *chartInstance)
{
  uint32_T c2_debug_family_var_map[3];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 1.0;
  boolean_T c2_out;
  uint32_T c2_b_debug_family_var_map[2];
  real_T c2_b_nargin = 0.0;
  real_T c2_c_nargin = 0.0;
  real_T c2_b_nargout = 0.0;
  real_T c2_c_nargout = 0.0;
  *chartInstance->c2_scl = true;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 10U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c2_hc_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_out, 2U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  c2_out = CV_EML_IF(10, 0, 0, CV_RELATIONAL_EVAL(5U, 10U, 0, (real_T)
    *chartInstance->c2_sda_in, 0.0, -1, 0U, !*chartInstance->c2_sda_in));
  _SFD_SYMBOL_SCOPE_POP();
  if (c2_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_ack_recv_wr2 = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_c2_mpu60502 = c2_IN_ack_addr_m_cnf;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_ack_addr_m_cnf = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_ab_debug_family_names,
      c2_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_c_nargin, 0U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_c_nargout, 1U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    *chartInstance->c2_scl = false;
    chartInstance->c2_dataWrittenToVector[2U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_scl, 12U, 4U, 2U,
                          chartInstance->c2_sfEvent, false);
    if (CV_EML_IF(2, 1, 0, CV_RELATIONAL_EVAL(4U, 2U, 0, (real_T)
          *chartInstance->c2_rd_wr, 1.0, -1, 0U, (int32_T)
          *chartInstance->c2_rd_wr))) {
      *chartInstance->c2_sda = true;
      chartInstance->c2_dataWrittenToVector[3U] = true;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sda, 13U, 4U, 2U,
                            chartInstance->c2_sfEvent, false);
    } else {
      *chartInstance->c2_sda = false;
      chartInstance->c2_dataWrittenToVector[3U] = true;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sda, 13U, 4U, 2U,
                            chartInstance->c2_sfEvent, false);
    }

    chartInstance->c2_bit_cnt = 8U;
    chartInstance->c2_dataWrittenToVector[1U] = true;
    ssLoggerUpdateTimeseries(chartInstance->S,
      chartInstance->c2_dataSetLogObjVector[0], 0, _sfTime_, (char_T *)
      &chartInstance->c2_bit_cnt);
    chartInstance->c2_dataWrittenToVector[1U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_bit_cnt, 0U, 4U, 2U,
                          chartInstance->c2_sfEvent, false);
    *chartInstance->c2_ack = false;
    chartInstance->c2_dataWrittenToVector[4U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_ack, 14U, 4U, 2U,
                          chartInstance->c2_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 27U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_ack_recv_wr2 = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_c2_mpu60502 = c2_IN_error_ack;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 27U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_error_ack = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_cb_debug_family_names,
      c2_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargin, 0U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargout, 1U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    *chartInstance->c2_scl = false;
    chartInstance->c2_dataWrittenToVector[2U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_scl, 12U, 4U, 27U,
                          chartInstance->c2_sfEvent, false);
    *chartInstance->c2_sda = true;
    chartInstance->c2_dataWrittenToVector[3U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sda, 13U, 4U, 27U,
                          chartInstance->c2_sfEvent, false);
    *chartInstance->c2_n_ack = true;
    chartInstance->c2_dataWrittenToVector[5U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_n_ack, 15U, 4U, 27U,
                          chartInstance->c2_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c2_sfEvent);
}

static void c2_enter_atomic_cmd_slave_addr_n1(SFc2_mpu60502InstanceStruct
  *chartInstance)
{
  uint32_T c2_debug_family_var_map[2];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 0.0;
  uint8_T c2_hoistedGlobal;
  uint8_T c2_b_hoistedGlobal;
  uint8_T c2_a;
  uint8_T c2_bit;
  uint8_T c2_x;
  boolean_T c2_p;
  uint8_T c2_b_a;
  uint8_T c2_a1;
  int32_T c2_c_a;
  boolean_T c2_b_p;
  uint8_T c2_b_x;
  boolean_T c2_b4;
  uint8_T c2_c_x;
  const mxArray *c2_y = NULL;
  static char_T c2_cv4[30] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'b', 'i', 't',
    'S', 'e', 't', 'G', 'e', 't', ':', 'B', 'I', 'T', 'O', 'u', 't', 'O', 'f',
    'R', 'a', 'n', 'g', 'e' };

  uint32_T c2_q0;
  uint32_T c2_qY;
  uint32_T c2_u8;
  uint8_T c2_bitkm1;
  uint8_T c2_c;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_ob_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  *chartInstance->c2_scl = false;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_scl, 12U, 4U, 23U,
                        chartInstance->c2_sfEvent, false);
  if (!chartInstance->c2_dataWrittenToVector[1U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 23U, chartInstance->c2_sfEvent,
      false);
  }

  c2_hoistedGlobal = *chartInstance->c2_slv_addr;
  c2_b_hoistedGlobal = chartInstance->c2_bit_cnt;
  c2_a = c2_hoistedGlobal;
  c2_bit = c2_b_hoistedGlobal;
  c2_x = c2_bit;
  c2_p = true;
  c2_b_a = c2_x;
  c2_a1 = c2_b_a;
  c2_c_a = c2_a1;
  c2_b_p = (c2_c_a >= 1);
  if (c2_b_p && (c2_x <= 8)) {
    c2_b_x = c2_x;
    c2_c_x = c2_b_x;
    if (c2_x == c2_c_x) {
      c2_b4 = true;
    } else {
      c2_b4 = false;
    }
  } else {
    c2_b4 = false;
  }

  if (!c2_b4) {
    c2_p = false;
  }

  if (c2_p) {
  } else {
    c2_y = NULL;
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_cv4, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_y));
  }

  c2_q0 = c2_bit;
  c2_qY = c2_q0 - 1U;
  if (CV_SATURATION_EVAL(4, 23, 0, 0, c2_qY > c2_q0)) {
    c2_qY = 0U;
  }

  c2_u8 = c2_qY;
  if (CV_SATURATION_EVAL(4, 23, 0, 0, c2_u8 > 255U)) {
    c2_u8 = 255U;
  }

  c2_bitkm1 = (uint8_T)c2_u8;
  c2_c = (uint8_T)((uint8_T)(c2_a & (uint8_T)(1 << (uint8_T)
    sf_eml_shift_index_bounds_check(sfGlobalDebugInstanceStruct,
    chartInstance->S, 2214U, 48, 27, "", (int32_T)c2_bitkm1, 0, 7))) != 0);
  *chartInstance->c2_sda = (c2_c != 0);
  chartInstance->c2_dataWrittenToVector[3U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sda, 13U, 4U, 23U,
                        chartInstance->c2_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c2_cmd_slave_addr_n1(SFc2_mpu60502InstanceStruct *chartInstance)
{
  uint32_T c2_debug_family_var_map[2];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 0.0;
  uint32_T c2_q0;
  uint32_T c2_qY;
  uint32_T c2_u9;
  *chartInstance->c2_scl = false;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 42U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_cmd_slave_addr_n1 = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 23U, chartInstance->c2_sfEvent);
  chartInstance->c2_is_c2_mpu60502 = c2_IN_cmd_slave_addr_p1;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 25U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_cmd_slave_addr_p1 = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_pb_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  *chartInstance->c2_scl = true;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_scl, 12U, 4U, 25U,
                        chartInstance->c2_sfEvent, false);
  if (!chartInstance->c2_dataWrittenToVector[1U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 25U, chartInstance->c2_sfEvent,
      false);
  }

  c2_q0 = chartInstance->c2_bit_cnt;
  c2_qY = c2_q0 - 1U;
  if (CV_SATURATION_EVAL(4, 25, 0, 0, c2_qY > c2_q0)) {
    c2_qY = 0U;
  }

  c2_u9 = c2_qY;
  if (CV_SATURATION_EVAL(4, 25, 0, 0, c2_u9 > 255U)) {
    c2_u9 = 255U;
  }

  chartInstance->c2_bit_cnt = (uint8_T)c2_u9;
  chartInstance->c2_dataWrittenToVector[1U] = true;
  ssLoggerUpdateTimeseries(chartInstance->S,
    chartInstance->c2_dataSetLogObjVector[0], 0, _sfTime_, (char_T *)
    &chartInstance->c2_bit_cnt);
  chartInstance->c2_dataWrittenToVector[1U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_bit_cnt, 0U, 4U, 25U,
                        chartInstance->c2_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 23U, chartInstance->c2_sfEvent);
}

static void c2_cmd_slave_addr_p1(SFc2_mpu60502InstanceStruct *chartInstance)
{
  uint32_T c2_debug_family_var_map[3];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 1.0;
  boolean_T c2_out;
  uint32_T c2_b_debug_family_var_map[2];
  real_T c2_b_nargin = 0.0;
  real_T c2_b_nargout = 0.0;
  *chartInstance->c2_scl = true;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c2_lc_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_out, 2U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  if (!chartInstance->c2_dataWrittenToVector[1U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 5U, 6U, chartInstance->c2_sfEvent,
      false);
  }

  c2_out = CV_EML_IF(6, 0, 0, CV_RELATIONAL_EVAL(5U, 6U, 0, (real_T)
    chartInstance->c2_bit_cnt, 0.0, -1, 4U, (real_T)chartInstance->c2_bit_cnt >
    0.0));
  _SFD_SYMBOL_SCOPE_POP();
  if (c2_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_cmd_slave_addr_p1 = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 25U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_c2_mpu60502 = c2_IN_cmd_slave_addr_n1;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 23U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_cmd_slave_addr_n1 = 1U;
    c2_enter_atomic_cmd_slave_addr_n1(chartInstance);
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 43U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_cmd_slave_addr_p1 = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 25U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_c2_mpu60502 = c2_IN_read_n;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 32U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_read_n = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_rb_debug_family_names,
      c2_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargin, 0U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargout, 1U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    *chartInstance->c2_scl = false;
    chartInstance->c2_dataWrittenToVector[2U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_scl, 12U, 4U, 32U,
                          chartInstance->c2_sfEvent, false);
    *chartInstance->c2_sda = true;
    chartInstance->c2_dataWrittenToVector[3U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sda, 13U, 4U, 32U,
                          chartInstance->c2_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 25U, chartInstance->c2_sfEvent);
}

static void c2_ack_addrm1(SFc2_mpu60502InstanceStruct *chartInstance)
{
  *chartInstance->c2_scl = true;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  *chartInstance->c2_reg_addr_burst = true;
  chartInstance->c2_dataWrittenToVector[8U] = true;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_ack_addrm1 = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
  chartInstance->c2_is_c2_mpu60502 = c2_IN_cmd_reg_addr_n;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_cmd_reg_addr_n = 1U;
  c2_enter_atomic_cmd_reg_addr_n(chartInstance);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c2_sfEvent);
}

static void c2_read_n(SFc2_mpu60502InstanceStruct *chartInstance)
{
  uint32_T c2_debug_family_var_map[2];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 0.0;
  *chartInstance->c2_scl = false;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_read_n = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 32U, chartInstance->c2_sfEvent);
  chartInstance->c2_is_c2_mpu60502 = c2_IN_read_p;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 33U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_read_p = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_tb_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  *chartInstance->c2_scl = true;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_scl, 12U, 4U, 33U,
                        chartInstance->c2_sfEvent, false);
  *chartInstance->c2_sda = true;
  chartInstance->c2_dataWrittenToVector[3U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sda, 13U, 4U, 33U,
                        chartInstance->c2_sfEvent, false);
  chartInstance->c2_bit_cnt = 8U;
  chartInstance->c2_dataWrittenToVector[1U] = true;
  ssLoggerUpdateTimeseries(chartInstance->S,
    chartInstance->c2_dataSetLogObjVector[0], 0, _sfTime_, (char_T *)
    &chartInstance->c2_bit_cnt);
  chartInstance->c2_dataWrittenToVector[1U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_bit_cnt, 0U, 4U, 33U,
                        chartInstance->c2_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 32U, chartInstance->c2_sfEvent);
}

static void c2_ack_wr_p2(SFc2_mpu60502InstanceStruct *chartInstance)
{
  uint32_T c2_debug_family_var_map[2];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 0.0;
  *chartInstance->c2_scl = false;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 49U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_ack_wr_p2 = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c2_sfEvent);
  chartInstance->c2_is_c2_mpu60502 = c2_IN_cmd_reg_read_data_n;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_cmd_reg_read_data_n = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_w_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  *chartInstance->c2_scl = false;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_scl, 12U, 4U, 20U,
                        chartInstance->c2_sfEvent, false);
  *chartInstance->c2_ack = true;
  chartInstance->c2_dataWrittenToVector[4U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_ack, 14U, 4U, 20U,
                        chartInstance->c2_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 15U, chartInstance->c2_sfEvent);
}

static void c2_read_p(SFc2_mpu60502InstanceStruct *chartInstance)
{
  uint32_T c2_debug_family_var_map[2];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 0.0;
  *chartInstance->c2_scl = true;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_read_p = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 33U, chartInstance->c2_sfEvent);
  chartInstance->c2_is_c2_mpu60502 = c2_IN_ack_slv1;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_ack_slv1 = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_ub_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  *chartInstance->c2_scl = false;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_scl, 12U, 4U, 12U,
                        chartInstance->c2_sfEvent, false);
  *chartInstance->c2_ack = true;
  chartInstance->c2_dataWrittenToVector[4U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_ack, 14U, 4U, 12U,
                        chartInstance->c2_sfEvent, false);
  *chartInstance->c2_sda = true;
  chartInstance->c2_dataWrittenToVector[3U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sda, 13U, 4U, 12U,
                        chartInstance->c2_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 33U, chartInstance->c2_sfEvent);
}

static void c2_ack_slv1(SFc2_mpu60502InstanceStruct *chartInstance)
{
  uint32_T c2_debug_family_var_map[2];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 0.0;
  *chartInstance->c2_scl = false;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 45U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_ack_slv1 = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c2_sfEvent);
  chartInstance->c2_is_c2_mpu60502 = c2_IN_ack_slv_cnf1;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_ack_slv_cnf1 = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_vb_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  *chartInstance->c2_scl = true;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_scl, 12U, 4U, 13U,
                        chartInstance->c2_sfEvent, false);
  *chartInstance->c2_ack = true;
  chartInstance->c2_dataWrittenToVector[4U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_ack, 14U, 4U, 13U,
                        chartInstance->c2_sfEvent, false);
  chartInstance->c2_bit_cnt = 8U;
  chartInstance->c2_dataWrittenToVector[1U] = true;
  ssLoggerUpdateTimeseries(chartInstance->S,
    chartInstance->c2_dataSetLogObjVector[0], 0, _sfTime_, (char_T *)
    &chartInstance->c2_bit_cnt);
  chartInstance->c2_dataWrittenToVector[1U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_bit_cnt, 0U, 4U, 13U,
                        chartInstance->c2_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c2_sfEvent);
}

static void c2_ack_slv_cnf1(SFc2_mpu60502InstanceStruct *chartInstance)
{
  uint32_T c2_debug_family_var_map[3];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 1.0;
  boolean_T c2_out;
  uint32_T c2_b_debug_family_var_map[2];
  real_T c2_b_nargin = 0.0;
  real_T c2_c_nargin = 0.0;
  real_T c2_b_nargout = 0.0;
  real_T c2_c_nargout = 0.0;
  *chartInstance->c2_scl = true;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 35U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c2_mc_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_out, 2U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  c2_out = CV_EML_IF(35, 0, 0, CV_RELATIONAL_EVAL(5U, 35U, 0, (real_T)
    *chartInstance->c2_sda_in, 0.0, -1, 0U, !*chartInstance->c2_sda_in));
  _SFD_SYMBOL_SCOPE_POP();
  if (c2_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 35U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_ack_slv_cnf1 = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_c2_mpu60502 = c2_IN_ack_wr_p2;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_ack_wr_p2 = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_sb_debug_family_names,
      c2_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_c_nargin, 0U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_c_nargout, 1U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    *chartInstance->c2_scl = false;
    chartInstance->c2_dataWrittenToVector[2U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_scl, 12U, 4U, 15U,
                          chartInstance->c2_sfEvent, false);
    *chartInstance->c2_ack = true;
    chartInstance->c2_dataWrittenToVector[4U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_ack, 14U, 4U, 15U,
                          chartInstance->c2_sfEvent, false);
    *chartInstance->c2_sda = true;
    chartInstance->c2_dataWrittenToVector[3U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sda, 13U, 4U, 15U,
                          chartInstance->c2_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 34U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_ack_slv_cnf1 = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_c2_mpu60502 = c2_IN_error_ack;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 27U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_error_ack = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_cb_debug_family_names,
      c2_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargin, 0U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargout, 1U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    *chartInstance->c2_scl = false;
    chartInstance->c2_dataWrittenToVector[2U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_scl, 12U, 4U, 27U,
                          chartInstance->c2_sfEvent, false);
    *chartInstance->c2_sda = true;
    chartInstance->c2_dataWrittenToVector[3U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_sda, 13U, 4U, 27U,
                          chartInstance->c2_sfEvent, false);
    *chartInstance->c2_n_ack = true;
    chartInstance->c2_dataWrittenToVector[5U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_n_ack, 15U, 4U, 27U,
                          chartInstance->c2_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, chartInstance->c2_sfEvent);
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber)
{
  (void)(c2_machineNumber);
  (void)(c2_chartNumber);
  (void)(c2_instanceNumber);
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_mpu60502InstanceStruct *chartInstance;
  chartInstance = (SFc2_mpu60502InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static real_T c2_emlrt_marshallIn(SFc2_mpu60502InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargout;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_mpu60502InstanceStruct *chartInstance;
  chartInstance = (SFc2_mpu60502InstanceStruct *)chartInstanceVoid;
  c2_nargout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout), &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  boolean_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_mpu60502InstanceStruct *chartInstance;
  chartInstance = (SFc2_mpu60502InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_u = *(boolean_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static boolean_T c2_b_emlrt_marshallIn(SFc2_mpu60502InstanceStruct
  *chartInstance, const mxArray *c2_sf_internal_predicateOutput, const char_T
  *c2_identifier)
{
  boolean_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_sf_internal_predicateOutput), &c2_thisId);
  sf_mex_destroy(&c2_sf_internal_predicateOutput);
  return c2_y;
}

static boolean_T c2_c_emlrt_marshallIn(SFc2_mpu60502InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  boolean_T c2_y;
  boolean_T c2_b5;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_b5, 1, 11, 0U, 0, 0U, 0);
  c2_y = c2_b5;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_sf_internal_predicateOutput;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  boolean_T c2_y;
  SFc2_mpu60502InstanceStruct *chartInstance;
  chartInstance = (SFc2_mpu60502InstanceStruct *)chartInstanceVoid;
  c2_sf_internal_predicateOutput = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_sf_internal_predicateOutput), &c2_thisId);
  sf_mex_destroy(&c2_sf_internal_predicateOutput);
  *(boolean_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_mpu60502_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c2_nameCaptureInfo;
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_mpu60502InstanceStruct *chartInstance;
  chartInstance = (SFc2_mpu60502InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static int32_T c2_d_emlrt_marshallIn(SFc2_mpu60502InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i1;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i1, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i1;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_mpu60502InstanceStruct *chartInstance;
  chartInstance = (SFc2_mpu60502InstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  uint8_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_mpu60502InstanceStruct *chartInstance;
  chartInstance = (SFc2_mpu60502InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_u = *(uint8_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static uint8_T c2_e_emlrt_marshallIn(SFc2_mpu60502InstanceStruct *chartInstance,
  const mxArray *c2_b_tp_idle, const char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_tp_idle),
    &c2_thisId);
  sf_mex_destroy(&c2_b_tp_idle);
  return c2_y;
}

static uint8_T c2_f_emlrt_marshallIn(SFc2_mpu60502InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u10;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u10, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u10;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_tp_idle;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  uint8_T c2_y;
  SFc2_mpu60502InstanceStruct *chartInstance;
  chartInstance = (SFc2_mpu60502InstanceStruct *)chartInstanceVoid;
  c2_b_tp_idle = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_tp_idle),
    &c2_thisId);
  sf_mex_destroy(&c2_b_tp_idle);
  *(uint8_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  uint8_T c2_u;
  const mxArray *c2_y = NULL;
  uint8_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  SFc2_mpu60502InstanceStruct *chartInstance;
  chartInstance = (SFc2_mpu60502InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  if (sf_debug_check_fi_license()) {
    c2_u = *(uint8_T *)c2_inData;
    c2_y = NULL;
    c2_b_u = c2_u;
    c2_b_y = NULL;
    sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0), false);
    sf_mex_assign(&c2_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
      (c2_eml_mx), 15, "numerictype", 14, sf_mex_dup(c2_b_eml_mx), 15,
      "simulinkarray", 14, c2_b_y, 15, "fimathislocal", 3, false), false);
    sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  } else {
    sf_mex_assign(&c2_mxArrayOutData, sf_mex_create("mxArrayOutData",
      "Cannot display value.", 15, 0U, 0U, 0U, 2, 1, strlen(
      "Cannot display value.")), false);
  }

  return c2_mxArrayOutData;
}

static uint8_T c2_g_emlrt_marshallIn(SFc2_mpu60502InstanceStruct *chartInstance,
  const mxArray *c2_b_data_out, const char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_data_out),
    &c2_thisId);
  sf_mex_destroy(&c2_b_data_out);
  return c2_y;
}

static uint8_T c2_h_emlrt_marshallIn(SFc2_mpu60502InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  const mxArray *c2_mxFi = NULL;
  const mxArray *c2_mxInt = NULL;
  uint8_T c2_u11;
  (void)chartInstance;
  sf_mex_check_fi(c2_parentId, c2_u, false, 0U, NULL, c2_eml_mx, c2_b_eml_mx);
  sf_mex_assign(&c2_mxFi, sf_mex_dup(c2_u), false);
  sf_mex_assign(&c2_mxInt, sf_mex_call("simulinkarray", 1U, 1U, 14, sf_mex_dup
    (c2_mxFi)), false);
  sf_mex_import(c2_parentId, sf_mex_dup(c2_mxInt), &c2_u11, 1, 3, 0U, 0, 0U, 0);
  sf_mex_destroy(&c2_mxFi);
  sf_mex_destroy(&c2_mxInt);
  c2_y = c2_u11;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_data_out;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  uint8_T c2_y;
  SFc2_mpu60502InstanceStruct *chartInstance;
  chartInstance = (SFc2_mpu60502InstanceStruct *)chartInstanceVoid;
  c2_b_data_out = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_data_out),
    &c2_thisId);
  sf_mex_destroy(&c2_b_data_out);
  *(uint8_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static void c2_i_emlrt_marshallIn(SFc2_mpu60502InstanceStruct *chartInstance,
  const mxArray *c2_b_dataWrittenToVector, const char_T *c2_identifier,
  boolean_T c2_y[12])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_dataWrittenToVector),
                        &c2_thisId, c2_y);
  sf_mex_destroy(&c2_b_dataWrittenToVector);
}

static void c2_j_emlrt_marshallIn(SFc2_mpu60502InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, boolean_T c2_y[12])
{
  boolean_T c2_bv1[12];
  int32_T c2_i2;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_bv1, 1, 11, 0U, 1, 0U, 1, 12);
  for (c2_i2 = 0; c2_i2 < 12; c2_i2++) {
    c2_y[c2_i2] = c2_bv1[c2_i2];
  }

  sf_mex_destroy(&c2_u);
}

static const mxArray *c2_k_emlrt_marshallIn(SFc2_mpu60502InstanceStruct
  *chartInstance, const mxArray *c2_b_setSimStateSideEffectsInfo, const char_T
  *c2_identifier)
{
  const mxArray *c2_y = NULL;
  emlrtMsgIdentifier c2_thisId;
  c2_y = NULL;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  sf_mex_assign(&c2_y, c2_l_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_setSimStateSideEffectsInfo), &c2_thisId), false);
  sf_mex_destroy(&c2_b_setSimStateSideEffectsInfo);
  return c2_y;
}

static const mxArray *c2_l_emlrt_marshallIn(SFc2_mpu60502InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  const mxArray *c2_y = NULL;
  (void)chartInstance;
  (void)c2_parentId;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_duplicatearraysafe(&c2_u), false);
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static const mxArray *sf_get_hover_data_for_msg(SFc2_mpu60502InstanceStruct
  *chartInstance, int32_T c2_ssid)
{
  const mxArray *c2_msgInfo;
  (void)chartInstance;
  (void)c2_ssid;
  c2_msgInfo = NULL;
  return NULL;
}

static void c2_init_sf_message_store_memory(SFc2_mpu60502InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_test_point_addr_map(SFc2_mpu60502InstanceStruct *chartInstance)
{
  chartInstance->c2_testPointAddrMap[0] = &chartInstance->c2_bit_cnt;
}

static void **get_test_point_address_map(SFc2_mpu60502InstanceStruct
  *chartInstance)
{
  return &chartInstance->c2_testPointAddrMap[0];
}

static rtwCAPI_ModelMappingInfo *get_test_point_mapping_info
  (SFc2_mpu60502InstanceStruct *chartInstance)
{
  return &chartInstance->c2_testPointMappingInfo;
}

static void **get_dataset_logging_obj_vector(SFc2_mpu60502InstanceStruct
  *chartInstance)
{
  return &chartInstance->c2_dataSetLogObjVector[0];
}

static void init_dsm_address_info(SFc2_mpu60502InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc2_mpu60502InstanceStruct *chartInstance)
{
  chartInstance->c2_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c2_enb = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c2_rd_wr = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c2_mode = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c2_busy = (boolean_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c2_scl = (boolean_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c2_sda = (boolean_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c2_slv_addr = (uint8_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c2_reg_addr = (uint8_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c2_reg_addr_burstIn = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c2_reg_data = (uint8_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c2_sda_in = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 7);
  chartInstance->c2_ack = (boolean_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c2_n_ack = (boolean_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c2_reg_data_burst = (boolean_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c2_reg_addr_burst = (boolean_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 7);
  chartInstance->c2_mstr_ack = (boolean_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 8);
  chartInstance->c2_data_out = (uint8_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 9);
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

static void init_test_point_mapping_info(SimStruct *S);
void sf_c2_mpu60502_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(938800247U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(430903150U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4217801661U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(268263998U);
}

mxArray* sf_c2_mpu60502_get_post_codegen_info(void);
mxArray *sf_c2_mpu60502_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("2TP1HyoU37MbJN8wzR0rCF");
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,9,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,8,"size",mxSize);
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
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  {
    mxArray* mxPostCodegenInfo = sf_c2_mpu60502_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c2_mpu60502_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c2_mpu60502_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("early");
  mxArray *fallbackReason = mxCreateString("logging");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("bit_cnt");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c2_mpu60502_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c2_mpu60502_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c2_mpu60502(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[464],T\"ack\",},{M[1],M[83],T\"busy\",},{M[1],M[1970],T\"data_out\",},{M[1],M[2253],T\"mstr_ack\",},{M[1],M[742],T\"n_ack\",},{M[1],M[1887],T\"reg_addr_burst\",},{M[1],M[1881],T\"reg_data_burst\",},{M[1],M[32],T\"scl\",},{M[1],M[425],T\"sda\",},{M[3],M[30],T\"bit_cnt\",}}",
    "100 S1x5'type','srcId','name','auxInfo'{{M[3],M[1870],T\"reg_byte_cnt\",},{M[3],M[2305],T\"temp_data\",},{M[8],M[0],T\"is_active_c2_mpu60502\",},{M[9],M[0],T\"is_c2_mpu60502\",},{M[15],M[0],T\"dataWrittenToVector\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 15, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_mpu60502_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const mxArray* sf_opaque_get_hover_data_for_msg(void* chartInstance,
  int32_T msgSSID)
{
  return sf_get_hover_data_for_msg( (SFc2_mpu60502InstanceStruct *)
    chartInstance, msgSSID);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_mpu60502InstanceStruct *chartInstance = (SFc2_mpu60502InstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _mpu60502MachineNumber_,
           2,
           47,
           62,
           0,
           20,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_mpu60502MachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_mpu60502MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _mpu60502MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,0,0,0,"bit_cnt");
          _SFD_SET_DATA_PROPS(1,0,0,0,"reg_byte_cnt");
          _SFD_SET_DATA_PROPS(2,0,0,0,"temp_data");
          _SFD_SET_DATA_PROPS(3,1,1,0,"enb");
          _SFD_SET_DATA_PROPS(4,1,1,0,"rd_wr");
          _SFD_SET_DATA_PROPS(5,1,1,0,"mode");
          _SFD_SET_DATA_PROPS(6,1,1,0,"slv_addr");
          _SFD_SET_DATA_PROPS(7,1,1,0,"reg_addr");
          _SFD_SET_DATA_PROPS(8,1,1,0,"reg_addr_burstIn");
          _SFD_SET_DATA_PROPS(9,1,1,0,"reg_data");
          _SFD_SET_DATA_PROPS(10,1,1,0,"sda_in");
          _SFD_SET_DATA_PROPS(11,2,0,1,"busy");
          _SFD_SET_DATA_PROPS(12,2,0,1,"scl");
          _SFD_SET_DATA_PROPS(13,2,0,1,"sda");
          _SFD_SET_DATA_PROPS(14,2,0,1,"ack");
          _SFD_SET_DATA_PROPS(15,2,0,1,"n_ack");
          _SFD_SET_DATA_PROPS(16,2,0,1,"reg_data_burst");
          _SFD_SET_DATA_PROPS(17,2,0,1,"reg_addr_burst");
          _SFD_SET_DATA_PROPS(18,2,0,1,"mstr_ack");
          _SFD_SET_DATA_PROPS(19,2,0,1,"data_out");
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
          _SFD_STATE_INFO(31,0,0);
          _SFD_STATE_INFO(32,0,0);
          _SFD_STATE_INFO(33,0,0);
          _SFD_STATE_INFO(34,0,0);
          _SFD_STATE_INFO(35,0,0);
          _SFD_STATE_INFO(36,0,0);
          _SFD_STATE_INFO(37,0,0);
          _SFD_STATE_INFO(38,0,0);
          _SFD_STATE_INFO(39,0,0);
          _SFD_STATE_INFO(40,0,0);
          _SFD_STATE_INFO(41,0,0);
          _SFD_STATE_INFO(42,0,0);
          _SFD_STATE_INFO(43,0,0);
          _SFD_STATE_INFO(44,0,0);
          _SFD_STATE_INFO(45,0,0);
          _SFD_STATE_INFO(46,0,0);
          _SFD_CH_SUBSTATE_COUNT(47);
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
          _SFD_CH_SUBSTATE_INDEX(16,16);
          _SFD_CH_SUBSTATE_INDEX(17,17);
          _SFD_CH_SUBSTATE_INDEX(18,18);
          _SFD_CH_SUBSTATE_INDEX(19,19);
          _SFD_CH_SUBSTATE_INDEX(20,20);
          _SFD_CH_SUBSTATE_INDEX(21,21);
          _SFD_CH_SUBSTATE_INDEX(22,22);
          _SFD_CH_SUBSTATE_INDEX(23,23);
          _SFD_CH_SUBSTATE_INDEX(24,24);
          _SFD_CH_SUBSTATE_INDEX(25,25);
          _SFD_CH_SUBSTATE_INDEX(26,26);
          _SFD_CH_SUBSTATE_INDEX(27,27);
          _SFD_CH_SUBSTATE_INDEX(28,28);
          _SFD_CH_SUBSTATE_INDEX(29,29);
          _SFD_CH_SUBSTATE_INDEX(30,30);
          _SFD_CH_SUBSTATE_INDEX(31,31);
          _SFD_CH_SUBSTATE_INDEX(32,32);
          _SFD_CH_SUBSTATE_INDEX(33,33);
          _SFD_CH_SUBSTATE_INDEX(34,34);
          _SFD_CH_SUBSTATE_INDEX(35,35);
          _SFD_CH_SUBSTATE_INDEX(36,36);
          _SFD_CH_SUBSTATE_INDEX(37,37);
          _SFD_CH_SUBSTATE_INDEX(38,38);
          _SFD_CH_SUBSTATE_INDEX(39,39);
          _SFD_CH_SUBSTATE_INDEX(40,40);
          _SFD_CH_SUBSTATE_INDEX(41,41);
          _SFD_CH_SUBSTATE_INDEX(42,42);
          _SFD_CH_SUBSTATE_INDEX(43,43);
          _SFD_CH_SUBSTATE_INDEX(44,44);
          _SFD_CH_SUBSTATE_INDEX(45,45);
          _SFD_CH_SUBSTATE_INDEX(46,46);
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
          _SFD_ST_SUBSTATE_COUNT(31,0);
          _SFD_ST_SUBSTATE_COUNT(32,0);
          _SFD_ST_SUBSTATE_COUNT(33,0);
          _SFD_ST_SUBSTATE_COUNT(34,0);
          _SFD_ST_SUBSTATE_COUNT(35,0);
          _SFD_ST_SUBSTATE_COUNT(36,0);
          _SFD_ST_SUBSTATE_COUNT(37,0);
          _SFD_ST_SUBSTATE_COUNT(38,0);
          _SFD_ST_SUBSTATE_COUNT(39,0);
          _SFD_ST_SUBSTATE_COUNT(40,0);
          _SFD_ST_SUBSTATE_COUNT(41,0);
          _SFD_ST_SUBSTATE_COUNT(42,0);
          _SFD_ST_SUBSTATE_COUNT(43,0);
          _SFD_ST_SUBSTATE_COUNT(44,0);
          _SFD_ST_SUBSTATE_COUNT(45,0);
          _SFD_ST_SUBSTATE_COUNT(46,0);
        }

        _SFD_CV_INIT_CHART(47,1,0,0);

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
          _SFD_CV_INIT_STATE(31,0,0,0,0,0,NULL,NULL);
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
          _SFD_CV_INIT_STATE(39,0,0,0,0,0,NULL,NULL);
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

        _SFD_CV_INIT_TRANS(15,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(16,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(30,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(53,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(54,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(50,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(14,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(22,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(52,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(26,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(55,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(19,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(58,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(44,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(48,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(36,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(38,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(32,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(23,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(47,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(60,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(31,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(46,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(18,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(20,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(33,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(61,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(28,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(49,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(17,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(21,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(27,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(34,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(56,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(57,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(24,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(25,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(41,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(37,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(29,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(40,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(59,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(51,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(39,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(42,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(43,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(35,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(45,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(28,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(44,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(34,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(43,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(41,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(31,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(30,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(40,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(42,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(39,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(29,1,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(29,1,0,36,48,72,104);
        _SFD_CV_INIT_EML_RELATIONAL(29,1,0,39,48,-1,0);
        _SFD_CV_INIT_EML(22,1,0,0,0,0,1,0,0,0,0,0);
        _SFD_CV_INIT_EML_SATURATION(22,1,0,47,-1,74);
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(24,1,0,0,0,0,1,0,0,0,0,0);
        _SFD_CV_INIT_EML_SATURATION(24,1,0,48,-1,57);
        _SFD_CV_INIT_EML(45,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(6,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(21,1,0,0,1,0,2,0,0,0,0,0);
        _SFD_CV_INIT_EML_SATURATION(21,1,0,112,-1,121);
        _SFD_CV_INIT_EML_SATURATION(21,1,1,71,-1,96);
        _SFD_CV_INIT_EML_IF(21,1,0,39,53,-1,101);
        _SFD_CV_INIT_EML_RELATIONAL(21,1,0,42,53,-1,0);
        _SFD_CV_INIT_EML(5,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(46,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(10,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(4,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(11,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(20,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(7,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(19,1,0,0,0,0,1,0,0,0,0,0);
        _SFD_CV_INIT_EML_SATURATION(19,1,0,46,-1,55);
        _SFD_CV_INIT_EML(2,1,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,1,0,36,49,68,94);
        _SFD_CV_INIT_EML_RELATIONAL(2,1,0,39,49,-1,0);
        _SFD_CV_INIT_EML(14,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(27,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(18,1,0,0,0,0,1,0,0,0,0,0);
        _SFD_CV_INIT_EML_SATURATION(18,1,0,78,-1,102);
        _SFD_CV_INIT_EML(26,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(16,1,0,0,0,0,1,0,0,0,0,0);
        _SFD_CV_INIT_EML_SATURATION(16,1,0,58,-1,82);
        _SFD_CV_INIT_EML(37,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(35,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(17,1,0,0,0,0,1,0,0,0,0,0);
        _SFD_CV_INIT_EML_SATURATION(17,1,0,45,-1,54);
        _SFD_CV_INIT_EML(38,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(36,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(8,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(9,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(23,1,0,0,0,0,1,0,0,0,0,0);
        _SFD_CV_INIT_EML_SATURATION(23,1,0,48,-1,75);
        _SFD_CV_INIT_EML(25,1,0,0,0,0,1,0,0,0,0,0);
        _SFD_CV_INIT_EML_SATURATION(25,1,0,49,-1,58);
        _SFD_CV_INIT_EML(3,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(32,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(15,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(33,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(12,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(13,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(30,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(30,0,0,1,7,1,7);
        _SFD_CV_INIT_EML_RELATIONAL(30,0,0,1,7,-1,0);
        _SFD_CV_INIT_EML(22,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(22,0,0,1,8,1,8);
        _SFD_CV_INIT_EML_RELATIONAL(22,0,0,1,8,-1,0);
        _SFD_CV_INIT_EML(19,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(19,0,0,1,12,1,12);
        _SFD_CV_INIT_EML_RELATIONAL(19,0,0,1,12,-1,4);
        _SFD_CV_INIT_EML(36,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(36,0,0,1,12,1,12);
        _SFD_CV_INIT_EML_RELATIONAL(36,0,0,1,12,-1,0);
        _SFD_CV_INIT_EML(38,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(38,0,0,1,10,1,10);
        _SFD_CV_INIT_EML(31,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(31,0,0,1,12,1,12);
        _SFD_CV_INIT_EML_RELATIONAL(31,0,0,1,12,-1,4);
        _SFD_CV_INIT_EML(0,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(0,0,0,1,12,1,12);
        _SFD_CV_INIT_EML_RELATIONAL(0,0,0,1,12,-1,4);
        _SFD_CV_INIT_EML(21,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(21,0,0,1,12,1,12);
        _SFD_CV_INIT_EML_RELATIONAL(21,0,0,1,12,-1,0);
        _SFD_CV_INIT_EML(4,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(4,0,0,1,9,1,9);
        _SFD_CV_INIT_EML_RELATIONAL(4,0,0,1,9,-1,0);
        _SFD_CV_INIT_EML(10,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(10,0,0,1,12,1,12);
        _SFD_CV_INIT_EML_RELATIONAL(10,0,0,1,12,-1,0);
        _SFD_CV_INIT_EML(11,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(11,0,0,1,9,1,9);
        _SFD_CV_INIT_EML_RELATIONAL(11,0,0,1,9,-1,0);
        _SFD_CV_INIT_EML(24,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(24,0,0,1,12,1,12);
        _SFD_CV_INIT_EML_RELATIONAL(24,0,0,1,12,-1,4);
        _SFD_CV_INIT_EML(39,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(39,0,0,1,21,1,21);
        _SFD_CV_INIT_EML_RELATIONAL(39,0,0,1,21,-1,0);
        _SFD_CV_INIT_EML(6,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(6,0,0,1,12,1,12);
        _SFD_CV_INIT_EML_RELATIONAL(6,0,0,1,12,-1,4);
        _SFD_CV_INIT_EML(35,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(35,0,0,1,12,1,12);
        _SFD_CV_INIT_EML_RELATIONAL(35,0,0,1,12,-1,0);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)c2_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)c2_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)c2_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_UINT8,0,NULL,1,0,8,0,1,0,0,
          (MexFcnForType)c2_e_sf_marshallOut,(MexInFcnForType)c2_e_sf_marshallIn);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _mpu60502MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_mpu60502InstanceStruct *chartInstance = (SFc2_mpu60502InstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(3U, (void *)chartInstance->c2_enb);
        _SFD_SET_DATA_VALUE_PTR(4U, (void *)chartInstance->c2_rd_wr);
        _SFD_SET_DATA_VALUE_PTR(5U, (void *)chartInstance->c2_mode);
        _SFD_SET_DATA_VALUE_PTR(11U, (void *)chartInstance->c2_busy);
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)&chartInstance->c2_bit_cnt);
        _SFD_SET_DATA_VALUE_PTR(12U, (void *)chartInstance->c2_scl);
        _SFD_SET_DATA_VALUE_PTR(13U, (void *)chartInstance->c2_sda);
        _SFD_SET_DATA_VALUE_PTR(6U, (void *)chartInstance->c2_slv_addr);
        _SFD_SET_DATA_VALUE_PTR(7U, (void *)chartInstance->c2_reg_addr);
        _SFD_SET_DATA_VALUE_PTR(8U, (void *)chartInstance->c2_reg_addr_burstIn);
        _SFD_SET_DATA_VALUE_PTR(9U, (void *)chartInstance->c2_reg_data);
        _SFD_SET_DATA_VALUE_PTR(10U, (void *)chartInstance->c2_sda_in);
        _SFD_SET_DATA_VALUE_PTR(14U, (void *)chartInstance->c2_ack);
        _SFD_SET_DATA_VALUE_PTR(15U, (void *)chartInstance->c2_n_ack);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)&chartInstance->c2_reg_byte_cnt);
        _SFD_SET_DATA_VALUE_PTR(16U, (void *)chartInstance->c2_reg_data_burst);
        _SFD_SET_DATA_VALUE_PTR(17U, (void *)chartInstance->c2_reg_addr_burst);
        _SFD_SET_DATA_VALUE_PTR(18U, (void *)chartInstance->c2_mstr_ack);
        _SFD_SET_DATA_VALUE_PTR(19U, (void *)chartInstance->c2_data_out);
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)&chartInstance->c2_temp_data);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "stLslrfyS7Gie0lijZL8HcD";
}

static void sf_opaque_initialize_c2_mpu60502(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_mpu60502InstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c2_mpu60502((SFc2_mpu60502InstanceStruct*) chartInstanceVar);
  initialize_c2_mpu60502((SFc2_mpu60502InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_mpu60502(void *chartInstanceVar)
{
  enable_c2_mpu60502((SFc2_mpu60502InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_mpu60502(void *chartInstanceVar)
{
  disable_c2_mpu60502((SFc2_mpu60502InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_mpu60502(void *chartInstanceVar)
{
  sf_gateway_c2_mpu60502((SFc2_mpu60502InstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c2_mpu60502(SimStruct* S)
{
  return get_sim_state_c2_mpu60502((SFc2_mpu60502InstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c2_mpu60502(SimStruct* S, const mxArray *st)
{
  set_sim_state_c2_mpu60502((SFc2_mpu60502InstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c2_mpu60502(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_mpu60502InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_mpu60502_optimization_info();
    }

    finalize_c2_mpu60502((SFc2_mpu60502InstanceStruct*) chartInstanceVar);
    if (!sim_mode_is_rtw_gen(S)) {
      ssSetModelMappingInfoPtr(S, NULL);
    }

    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_mpu60502((SFc2_mpu60502InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_mpu60502(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_mpu60502((SFc2_mpu60502InstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c2_mpu60502(SimStruct *S)
{
  ssSetStatesModifiedOnlyInUpdate(S, 0);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_mpu60502_optimization_info(sim_mode_is_rtw_gen(S),
      sim_mode_is_modelref_sim(S), sim_mode_is_external(S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,2,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 2);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,2);
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
        infoStruct,2,8);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,9);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=9; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 8; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetCallsOutputInInitFcn(S,1);
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  if (sim_mode_is_modelref_sim(S)) {
    mxArray *prhs[4];
    mxArray *plhs[1];
    uint32_T newChkSum[4];
    double *inPr, *outPr;
    int i;
    int firstSlashIdx = 0;
    for (i = 0; i < 999 && S->path[i] != '\0' ; ++i) {
      if (S->path[i] == '/') {
        firstSlashIdx = i;
        break;
      }
    }

    prhs[0] = mxCreateString("Private");
    prhs[1] = mxCreateString("md5");
    prhs[2] = mxCreateDoubleMatrix(1, 4, mxREAL);
    prhs[3] = mxCreateString(S->path + firstSlashIdx + 1);
    inPr = mxGetPr(prhs[2]);
    inPr[0] = 982846907U;
    inPr[1] = 2348823113U;
    inPr[2] = 3554300143U;
    inPr[3] = 3931218785U;
    mexCallMATLAB(1, plhs, 4, prhs, "sf");
    outPr = mxGetPr(plhs[0]);
    for (i = 0; i < 4; ++i) {
      newChkSum[i] = (uint32_T) outPr[i];
    }

    ssSetChecksum0(S, newChkSum[0]);
    ssSetChecksum1(S, newChkSum[1]);
    ssSetChecksum2(S, newChkSum[2]);
    ssSetChecksum3(S, newChkSum[3]);
    mxDestroyArray(plhs[0]);
    mxDestroyArray(prhs[0]);
    mxDestroyArray(prhs[1]);
    mxDestroyArray(prhs[2]);
    mxDestroyArray(prhs[3]);
  } else {
    ssSetChecksum0(S,(982846907U));
    ssSetChecksum1(S,(2348823113U));
    ssSetChecksum2(S,(3554300143U));
    ssSetChecksum3(S,(3931218785U));
  }

  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_mpu60502(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c2_mpu60502(SimStruct *S)
{
  SFc2_mpu60502InstanceStruct *chartInstance;
  chartInstance = (SFc2_mpu60502InstanceStruct *)utMalloc(sizeof
    (SFc2_mpu60502InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc2_mpu60502InstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_mpu60502;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c2_mpu60502;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_mpu60502;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_mpu60502;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_mpu60502;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_mpu60502;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_mpu60502;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c2_mpu60502;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_mpu60502;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_mpu60502;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_mpu60502;
  chartInstance->chartInfo.callGetHoverDataForMsg =
    sf_opaque_get_hover_data_for_msg;
  chartInstance->chartInfo.extModeExec = NULL;
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
    init_test_point_mapping_info(S);
  }

  chart_debug_initialization(S,1);
  mdl_start_c2_mpu60502(chartInstance);
}

void c2_mpu60502_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_mpu60502(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_mpu60502(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_mpu60502(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_mpu60502_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

static const rtwCAPI_DataTypeMap dataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, isComplex, isPointer */
  { "uint8_T", "uint8_T", 0, 0, sizeof(uint8_T), SS_UINT8, 0, 0 } };

static real_T sfCAPIsampleTimeZero = 0.0;
static const rtwCAPI_SampleTimeMap sampleTimeMap[] = {
  /* *period, *offset, taskId, mode */
  { &sfCAPIsampleTimeZero, &sfCAPIsampleTimeZero, 0, 0 }
};

static const rtwCAPI_DimensionMap dimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims*/
  { rtwCAPI_SCALAR, 0, 2 } };

static const rtwCAPI_Signals testPointSignals[] = {
  /* addrMapIndex, sysNum, SFRelativePath, dataName, portNumber, dataTypeIndex, dimIndex, fixPtIdx, sTimeIndex */
  { 0, 0, "StateflowChart/bit_cnt", "bit_cnt", 0, 0, 0, 0, 0 } };

static const rtwCAPI_FixPtMap fixedPointMap[] = {
  /* *fracSlope, *bias, scaleType, wordLength, exponent, isSigned */
  { NULL, NULL, rtwCAPI_FIX_RESERVED, 64, 0, 0 } };

static const uint_T dimensionArray[] = {
  1, 1 };

static rtwCAPI_ModelMappingStaticInfo testPointMappingStaticInfo = {
  /* block signal monitoring */
  {
    testPointSignals,                  /* Block signals Array  */
    1,                                 /* Num Block IO signals */
    NULL,                              /* Root Inputs Array    */
    0,                                 /* Num root inputs      */
    NULL,                              /* Root Outputs Array */
    0                                  /* Num root outputs   */
  },

  /* parameter tuning */
  {
    NULL,                              /* Block parameters Array    */
    0,                                 /* Num block parameters      */
    NULL,                              /* Variable parameters Array */
    0                                  /* Num variable parameters   */
  },

  /* block states */
  {
    NULL,                              /* Block States array        */
    0                                  /* Num Block States          */
  },

  /* Static maps */
  {
    dataTypeMap,                       /* Data Type Map            */
    dimensionMap,                      /* Data Dimension Map       */
    fixedPointMap,                     /* Fixed Point Map          */
    NULL,                              /* Structure Element map    */
    sampleTimeMap,                     /* Sample Times Map         */
    dimensionArray                     /* Dimension Array          */
  },

  /* Target type */
  "float",

  {
    982846907U,
    2348823113U,
    3554300143U,
    3931218785U
  }
};

static void init_signal_logging_objects(SimStruct *S, rtwCAPI_ModelMappingInfo
  *testPointMappingInfo)
{
  void ** chartDatasetLoggingObjs;
  void *pSetDescr;
  int i;
  size_t lastSlashIdx = 0;
  chartDatasetLoggingObjs = get_dataset_logging_obj_vector
    ((SFc2_mpu60502InstanceStruct *)sf_get_chart_instance_ptr(S));

  /* Initialize signal log vector */
  for (i = 0; i < 1; ++i) {
    chartDatasetLoggingObjs[i] = NULL;
  }

  _ssLoggerCreateDatasetDescriptWithMMI(S, testPointMappingInfo, 0, NULL,
    NULL, &pSetDescr);
  if (pSetDescr) {
    {
      void *pElementDescr;
      int_T dimArray[] = { 1 };

      ssLoggerAddStateflowElementDescription(S, &pSetDescr,
        "Stateflow.SimulationData.Data",
        "bit_cnt",
        NULL,
        "StateflowChart/bit_cnt",
        NULL,
        &pElementDescr);
      ssLoggerAddTimeseriesDescriptionWithInterpolation(S, &pSetDescr,
        &pElementDescr,
        "bit_cnt",
        1,
        dimArray,
        SS_UINT8,
        0,
        SS_ZOH_INTERPOLATION);
    }

    ssLoggerCreateElementFromDescription(S, &pSetDescr,
      chartDatasetLoggingObjs);
    if (chartDatasetLoggingObjs[0] != NULL) {
      mxArray *pVal = mxCreateDoubleScalar(30);
      ssLoggerAddElementProperty(S,
        chartDatasetLoggingObjs[0],
        "SSIdNumber",
        pVal);
    }
  }
}

static void init_test_point_mapping_info(SimStruct *S)
{
  rtwCAPI_ModelMappingInfo *testPointMappingInfo;
  void **testPointAddrMap;
  SFc2_mpu60502InstanceStruct *chartInstance = (SFc2_mpu60502InstanceStruct *)
    sf_get_chart_instance_ptr(S);
  init_test_point_addr_map(chartInstance);
  testPointMappingInfo = get_test_point_mapping_info(chartInstance);
  testPointAddrMap = get_test_point_address_map(chartInstance);
  rtwCAPI_SetStaticMap(*testPointMappingInfo, &testPointMappingStaticInfo);
  rtwCAPI_SetLoggingStaticMap(*testPointMappingInfo, NULL);
  rtwCAPI_SetInstanceLoggingInfo(*testPointMappingInfo, NULL);
  rtwCAPI_SetPath(*testPointMappingInfo, "");
  rtwCAPI_SetFullPath(*testPointMappingInfo, NULL);
  rtwCAPI_SetDataAddressMap(*testPointMappingInfo, testPointAddrMap);
  rtwCAPI_SetChildMMIArray(*testPointMappingInfo, NULL);
  rtwCAPI_SetChildMMIArrayLen(*testPointMappingInfo, 0);
  ssSetModelMappingInfoPtr(S, testPointMappingInfo);
  init_signal_logging_objects(S, testPointMappingInfo);
}
