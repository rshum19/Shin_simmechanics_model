/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Assembly_Quadrotor_sfun.h"
#include "c53_Assembly_Quadrotor.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Assembly_Quadrotor_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c53_debug_family_names[4] = { "nargin", "nargout",
  "AngleDeg", "AngleFix" };

/* Function Declarations */
static void initialize_c53_Assembly_Quadrotor
  (SFc53_Assembly_QuadrotorInstanceStruct *chartInstance);
static void initialize_params_c53_Assembly_Quadrotor
  (SFc53_Assembly_QuadrotorInstanceStruct *chartInstance);
static void enable_c53_Assembly_Quadrotor(SFc53_Assembly_QuadrotorInstanceStruct
  *chartInstance);
static void disable_c53_Assembly_Quadrotor
  (SFc53_Assembly_QuadrotorInstanceStruct *chartInstance);
static void c53_update_debugger_state_c53_Assembly_Quadrotor
  (SFc53_Assembly_QuadrotorInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c53_Assembly_Quadrotor
  (SFc53_Assembly_QuadrotorInstanceStruct *chartInstance);
static void set_sim_state_c53_Assembly_Quadrotor
  (SFc53_Assembly_QuadrotorInstanceStruct *chartInstance, const mxArray *c53_st);
static void finalize_c53_Assembly_Quadrotor
  (SFc53_Assembly_QuadrotorInstanceStruct *chartInstance);
static void sf_gateway_c53_Assembly_Quadrotor
  (SFc53_Assembly_QuadrotorInstanceStruct *chartInstance);
static void initSimStructsc53_Assembly_Quadrotor
  (SFc53_Assembly_QuadrotorInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c53_machineNumber, uint32_T
  c53_chartNumber, uint32_T c53_instanceNumber);
static const mxArray *c53_sf_marshallOut(void *chartInstanceVoid, void
  *c53_inData);
static real_T c53_emlrt_marshallIn(SFc53_Assembly_QuadrotorInstanceStruct
  *chartInstance, const mxArray *c53_AngleFix, const char_T *c53_identifier);
static real_T c53_b_emlrt_marshallIn(SFc53_Assembly_QuadrotorInstanceStruct
  *chartInstance, const mxArray *c53_u, const emlrtMsgIdentifier *c53_parentId);
static void c53_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c53_mxArrayInData, const char_T *c53_varName, void *c53_outData);
static void c53_info_helper(const mxArray **c53_info);
static const mxArray *c53_emlrt_marshallOut(const char * c53_u);
static const mxArray *c53_b_emlrt_marshallOut(const uint32_T c53_u);
static real_T c53_mod(SFc53_Assembly_QuadrotorInstanceStruct *chartInstance,
                      real_T c53_x, real_T c53_y);
static void c53_eml_scalar_eg(SFc53_Assembly_QuadrotorInstanceStruct
  *chartInstance);
static const mxArray *c53_b_sf_marshallOut(void *chartInstanceVoid, void
  *c53_inData);
static int32_T c53_c_emlrt_marshallIn(SFc53_Assembly_QuadrotorInstanceStruct
  *chartInstance, const mxArray *c53_u, const emlrtMsgIdentifier *c53_parentId);
static void c53_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c53_mxArrayInData, const char_T *c53_varName, void *c53_outData);
static uint8_T c53_d_emlrt_marshallIn(SFc53_Assembly_QuadrotorInstanceStruct
  *chartInstance, const mxArray *c53_b_is_active_c53_Assembly_Quadrotor, const
  char_T *c53_identifier);
static uint8_T c53_e_emlrt_marshallIn(SFc53_Assembly_QuadrotorInstanceStruct
  *chartInstance, const mxArray *c53_u, const emlrtMsgIdentifier *c53_parentId);
static void init_dsm_address_info(SFc53_Assembly_QuadrotorInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c53_Assembly_Quadrotor
  (SFc53_Assembly_QuadrotorInstanceStruct *chartInstance)
{
  chartInstance->c53_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c53_is_active_c53_Assembly_Quadrotor = 0U;
}

static void initialize_params_c53_Assembly_Quadrotor
  (SFc53_Assembly_QuadrotorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c53_Assembly_Quadrotor(SFc53_Assembly_QuadrotorInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c53_Assembly_Quadrotor
  (SFc53_Assembly_QuadrotorInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c53_update_debugger_state_c53_Assembly_Quadrotor
  (SFc53_Assembly_QuadrotorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c53_Assembly_Quadrotor
  (SFc53_Assembly_QuadrotorInstanceStruct *chartInstance)
{
  const mxArray *c53_st;
  const mxArray *c53_y = NULL;
  real_T c53_hoistedGlobal;
  real_T c53_u;
  const mxArray *c53_b_y = NULL;
  uint8_T c53_b_hoistedGlobal;
  uint8_T c53_b_u;
  const mxArray *c53_c_y = NULL;
  real_T *c53_AngleFix;
  c53_AngleFix = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c53_st = NULL;
  c53_st = NULL;
  c53_y = NULL;
  sf_mex_assign(&c53_y, sf_mex_createcellmatrix(2, 1), false);
  c53_hoistedGlobal = *c53_AngleFix;
  c53_u = c53_hoistedGlobal;
  c53_b_y = NULL;
  sf_mex_assign(&c53_b_y, sf_mex_create("y", &c53_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c53_y, 0, c53_b_y);
  c53_b_hoistedGlobal = chartInstance->c53_is_active_c53_Assembly_Quadrotor;
  c53_b_u = c53_b_hoistedGlobal;
  c53_c_y = NULL;
  sf_mex_assign(&c53_c_y, sf_mex_create("y", &c53_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c53_y, 1, c53_c_y);
  sf_mex_assign(&c53_st, c53_y, false);
  return c53_st;
}

static void set_sim_state_c53_Assembly_Quadrotor
  (SFc53_Assembly_QuadrotorInstanceStruct *chartInstance, const mxArray *c53_st)
{
  const mxArray *c53_u;
  real_T *c53_AngleFix;
  c53_AngleFix = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c53_doneDoubleBufferReInit = true;
  c53_u = sf_mex_dup(c53_st);
  *c53_AngleFix = c53_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c53_u, 0)), "AngleFix");
  chartInstance->c53_is_active_c53_Assembly_Quadrotor = c53_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c53_u, 1)),
     "is_active_c53_Assembly_Quadrotor");
  sf_mex_destroy(&c53_u);
  c53_update_debugger_state_c53_Assembly_Quadrotor(chartInstance);
  sf_mex_destroy(&c53_st);
}

static void finalize_c53_Assembly_Quadrotor
  (SFc53_Assembly_QuadrotorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c53_Assembly_Quadrotor
  (SFc53_Assembly_QuadrotorInstanceStruct *chartInstance)
{
  real_T c53_hoistedGlobal;
  real_T c53_AngleDeg;
  uint32_T c53_debug_family_var_map[4];
  real_T c53_nargin = 1.0;
  real_T c53_nargout = 1.0;
  real_T c53_AngleFix;
  real_T c53_x;
  real_T c53_b_x;
  real_T c53_y;
  real_T *c53_b_AngleDeg;
  real_T *c53_b_AngleFix;
  c53_b_AngleFix = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c53_b_AngleDeg = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 6U, chartInstance->c53_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c53_b_AngleDeg, 0U);
  chartInstance->c53_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c53_sfEvent);
  c53_hoistedGlobal = *c53_b_AngleDeg;
  c53_AngleDeg = c53_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c53_debug_family_names,
    c53_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c53_nargin, 0U, c53_sf_marshallOut,
    c53_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c53_nargout, 1U, c53_sf_marshallOut,
    c53_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c53_AngleDeg, 2U, c53_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c53_AngleFix, 3U, c53_sf_marshallOut,
    c53_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c53_sfEvent, 3);
  if (CV_EML_IF(0, 1, 0, c53_AngleDeg > 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c53_sfEvent, 4);
    c53_AngleFix = c53_mod(chartInstance, c53_AngleDeg, 360.0);
  } else {
    _SFD_EML_CALL(0U, chartInstance->c53_sfEvent, 6);
    c53_x = c53_AngleDeg;
    c53_b_x = c53_x;
    c53_y = muDoubleScalarAbs(c53_b_x);
    c53_AngleFix = -c53_mod(chartInstance, c53_y, 360.0);
  }

  _SFD_EML_CALL(0U, chartInstance->c53_sfEvent, -6);
  _SFD_SYMBOL_SCOPE_POP();
  *c53_b_AngleFix = c53_AngleFix;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c53_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Assembly_QuadrotorMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c53_b_AngleFix, 1U);
}

static void initSimStructsc53_Assembly_Quadrotor
  (SFc53_Assembly_QuadrotorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c53_machineNumber, uint32_T
  c53_chartNumber, uint32_T c53_instanceNumber)
{
  (void)c53_machineNumber;
  (void)c53_chartNumber;
  (void)c53_instanceNumber;
}

static const mxArray *c53_sf_marshallOut(void *chartInstanceVoid, void
  *c53_inData)
{
  const mxArray *c53_mxArrayOutData = NULL;
  real_T c53_u;
  const mxArray *c53_y = NULL;
  SFc53_Assembly_QuadrotorInstanceStruct *chartInstance;
  chartInstance = (SFc53_Assembly_QuadrotorInstanceStruct *)chartInstanceVoid;
  c53_mxArrayOutData = NULL;
  c53_u = *(real_T *)c53_inData;
  c53_y = NULL;
  sf_mex_assign(&c53_y, sf_mex_create("y", &c53_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c53_mxArrayOutData, c53_y, false);
  return c53_mxArrayOutData;
}

static real_T c53_emlrt_marshallIn(SFc53_Assembly_QuadrotorInstanceStruct
  *chartInstance, const mxArray *c53_AngleFix, const char_T *c53_identifier)
{
  real_T c53_y;
  emlrtMsgIdentifier c53_thisId;
  c53_thisId.fIdentifier = c53_identifier;
  c53_thisId.fParent = NULL;
  c53_y = c53_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c53_AngleFix),
    &c53_thisId);
  sf_mex_destroy(&c53_AngleFix);
  return c53_y;
}

static real_T c53_b_emlrt_marshallIn(SFc53_Assembly_QuadrotorInstanceStruct
  *chartInstance, const mxArray *c53_u, const emlrtMsgIdentifier *c53_parentId)
{
  real_T c53_y;
  real_T c53_d0;
  (void)chartInstance;
  sf_mex_import(c53_parentId, sf_mex_dup(c53_u), &c53_d0, 1, 0, 0U, 0, 0U, 0);
  c53_y = c53_d0;
  sf_mex_destroy(&c53_u);
  return c53_y;
}

static void c53_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c53_mxArrayInData, const char_T *c53_varName, void *c53_outData)
{
  const mxArray *c53_AngleFix;
  const char_T *c53_identifier;
  emlrtMsgIdentifier c53_thisId;
  real_T c53_y;
  SFc53_Assembly_QuadrotorInstanceStruct *chartInstance;
  chartInstance = (SFc53_Assembly_QuadrotorInstanceStruct *)chartInstanceVoid;
  c53_AngleFix = sf_mex_dup(c53_mxArrayInData);
  c53_identifier = c53_varName;
  c53_thisId.fIdentifier = c53_identifier;
  c53_thisId.fParent = NULL;
  c53_y = c53_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c53_AngleFix),
    &c53_thisId);
  sf_mex_destroy(&c53_AngleFix);
  *(real_T *)c53_outData = c53_y;
  sf_mex_destroy(&c53_mxArrayInData);
}

const mxArray *sf_c53_Assembly_Quadrotor_get_eml_resolved_functions_info(void)
{
  const mxArray *c53_nameCaptureInfo = NULL;
  c53_nameCaptureInfo = NULL;
  sf_mex_assign(&c53_nameCaptureInfo, sf_mex_createstruct("structure", 2, 17, 1),
                false);
  c53_info_helper(&c53_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c53_nameCaptureInfo);
  return c53_nameCaptureInfo;
}

static void c53_info_helper(const mxArray **c53_info)
{
  const mxArray *c53_rhs0 = NULL;
  const mxArray *c53_lhs0 = NULL;
  const mxArray *c53_rhs1 = NULL;
  const mxArray *c53_lhs1 = NULL;
  const mxArray *c53_rhs2 = NULL;
  const mxArray *c53_lhs2 = NULL;
  const mxArray *c53_rhs3 = NULL;
  const mxArray *c53_lhs3 = NULL;
  const mxArray *c53_rhs4 = NULL;
  const mxArray *c53_lhs4 = NULL;
  const mxArray *c53_rhs5 = NULL;
  const mxArray *c53_lhs5 = NULL;
  const mxArray *c53_rhs6 = NULL;
  const mxArray *c53_lhs6 = NULL;
  const mxArray *c53_rhs7 = NULL;
  const mxArray *c53_lhs7 = NULL;
  const mxArray *c53_rhs8 = NULL;
  const mxArray *c53_lhs8 = NULL;
  const mxArray *c53_rhs9 = NULL;
  const mxArray *c53_lhs9 = NULL;
  const mxArray *c53_rhs10 = NULL;
  const mxArray *c53_lhs10 = NULL;
  const mxArray *c53_rhs11 = NULL;
  const mxArray *c53_lhs11 = NULL;
  const mxArray *c53_rhs12 = NULL;
  const mxArray *c53_lhs12 = NULL;
  const mxArray *c53_rhs13 = NULL;
  const mxArray *c53_lhs13 = NULL;
  const mxArray *c53_rhs14 = NULL;
  const mxArray *c53_lhs14 = NULL;
  const mxArray *c53_rhs15 = NULL;
  const mxArray *c53_lhs15 = NULL;
  const mxArray *c53_rhs16 = NULL;
  const mxArray *c53_lhs16 = NULL;
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut("mod"), "name", "name", 0);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(1363731854U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c53_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c53_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c53_info, sf_mex_duplicatearraysafe(&c53_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c53_info, sf_mex_duplicatearraysafe(&c53_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(1363732556U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c53_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c53_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c53_info, sf_mex_duplicatearraysafe(&c53_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c53_info, sf_mex_duplicatearraysafe(&c53_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 2);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c53_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c53_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c53_info, sf_mex_duplicatearraysafe(&c53_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c53_info, sf_mex_duplicatearraysafe(&c53_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 3);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(1389329520U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c53_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c53_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c53_info, sf_mex_duplicatearraysafe(&c53_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c53_info, sf_mex_duplicatearraysafe(&c53_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 4);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c53_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c53_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c53_info, sf_mex_duplicatearraysafe(&c53_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c53_info, sf_mex_duplicatearraysafe(&c53_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 5);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 5);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(1389329520U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c53_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c53_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c53_info, sf_mex_duplicatearraysafe(&c53_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c53_info, sf_mex_duplicatearraysafe(&c53_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod"), "context",
                  "context", 6);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 6);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c53_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c53_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c53_info, sf_mex_duplicatearraysafe(&c53_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c53_info, sf_mex_duplicatearraysafe(&c53_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod"), "context",
                  "context", 7);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 7);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(1286840326U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c53_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c53_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c53_info, sf_mex_duplicatearraysafe(&c53_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c53_info, sf_mex_duplicatearraysafe(&c53_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod"), "context",
                  "context", 8);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut("eml_scalar_round"), "name",
                  "name", 8);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(1307672838U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c53_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c53_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c53_info, sf_mex_duplicatearraysafe(&c53_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c53_info, sf_mex_duplicatearraysafe(&c53_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod"), "context",
                  "context", 9);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 9);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(1286840312U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c53_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c53_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c53_info, sf_mex_duplicatearraysafe(&c53_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c53_info, sf_mex_duplicatearraysafe(&c53_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod"), "context",
                  "context", 10);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut("eps"), "name", "name", 10);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c53_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c53_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c53_info, sf_mex_duplicatearraysafe(&c53_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c53_info, sf_mex_duplicatearraysafe(&c53_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut("eml_is_float_class"), "name",
                  "name", 11);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(1286840382U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c53_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c53_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c53_info, sf_mex_duplicatearraysafe(&c53_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c53_info, sf_mex_duplicatearraysafe(&c53_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut("eml_eps"), "name", "name",
                  12);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c53_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c53_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c53_info, sf_mex_duplicatearraysafe(&c53_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c53_info, sf_mex_duplicatearraysafe(&c53_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 13);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c53_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c53_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c53_info, sf_mex_duplicatearraysafe(&c53_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c53_info, sf_mex_duplicatearraysafe(&c53_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut(""), "context", "context", 14);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut("abs"), "name", "name", 14);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 14);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c53_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c53_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c53_info, sf_mex_duplicatearraysafe(&c53_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c53_info, sf_mex_duplicatearraysafe(&c53_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 15);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(1363732556U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c53_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c53_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c53_info, sf_mex_duplicatearraysafe(&c53_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c53_info, sf_mex_duplicatearraysafe(&c53_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 16);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c53_info, c53_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(1286840312U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c53_info, c53_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c53_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c53_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c53_info, sf_mex_duplicatearraysafe(&c53_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c53_info, sf_mex_duplicatearraysafe(&c53_lhs16), "lhs", "lhs",
                  16);
  sf_mex_destroy(&c53_rhs0);
  sf_mex_destroy(&c53_lhs0);
  sf_mex_destroy(&c53_rhs1);
  sf_mex_destroy(&c53_lhs1);
  sf_mex_destroy(&c53_rhs2);
  sf_mex_destroy(&c53_lhs2);
  sf_mex_destroy(&c53_rhs3);
  sf_mex_destroy(&c53_lhs3);
  sf_mex_destroy(&c53_rhs4);
  sf_mex_destroy(&c53_lhs4);
  sf_mex_destroy(&c53_rhs5);
  sf_mex_destroy(&c53_lhs5);
  sf_mex_destroy(&c53_rhs6);
  sf_mex_destroy(&c53_lhs6);
  sf_mex_destroy(&c53_rhs7);
  sf_mex_destroy(&c53_lhs7);
  sf_mex_destroy(&c53_rhs8);
  sf_mex_destroy(&c53_lhs8);
  sf_mex_destroy(&c53_rhs9);
  sf_mex_destroy(&c53_lhs9);
  sf_mex_destroy(&c53_rhs10);
  sf_mex_destroy(&c53_lhs10);
  sf_mex_destroy(&c53_rhs11);
  sf_mex_destroy(&c53_lhs11);
  sf_mex_destroy(&c53_rhs12);
  sf_mex_destroy(&c53_lhs12);
  sf_mex_destroy(&c53_rhs13);
  sf_mex_destroy(&c53_lhs13);
  sf_mex_destroy(&c53_rhs14);
  sf_mex_destroy(&c53_lhs14);
  sf_mex_destroy(&c53_rhs15);
  sf_mex_destroy(&c53_lhs15);
  sf_mex_destroy(&c53_rhs16);
  sf_mex_destroy(&c53_lhs16);
}

static const mxArray *c53_emlrt_marshallOut(const char * c53_u)
{
  const mxArray *c53_y = NULL;
  c53_y = NULL;
  sf_mex_assign(&c53_y, sf_mex_create("y", c53_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c53_u)), false);
  return c53_y;
}

static const mxArray *c53_b_emlrt_marshallOut(const uint32_T c53_u)
{
  const mxArray *c53_y = NULL;
  c53_y = NULL;
  sf_mex_assign(&c53_y, sf_mex_create("y", &c53_u, 7, 0U, 0U, 0U, 0), false);
  return c53_y;
}

static real_T c53_mod(SFc53_Assembly_QuadrotorInstanceStruct *chartInstance,
                      real_T c53_x, real_T c53_y)
{
  real_T c53_r;
  real_T c53_xk;
  real_T c53_yk;
  real_T c53_b_x;
  real_T c53_b_y;
  real_T c53_c_x;
  real_T c53_d_x;
  real_T c53_e_x;
  real_T c53_f_x;
  real_T c53_g_x;
  real_T c53_h_x;
  real_T c53_i_x;
  real_T c53_c_y;
  real_T c53_j_x;
  real_T c53_d_y;
  real_T c53_k_x;
  real_T c53_l_x;
  c53_eml_scalar_eg(chartInstance);
  c53_xk = c53_x;
  c53_yk = c53_y;
  c53_b_x = c53_xk;
  c53_b_y = c53_yk;
  c53_eml_scalar_eg(chartInstance);
  if (c53_b_y == 0.0) {
    c53_r = c53_b_x;
  } else {
    c53_c_x = c53_b_y;
    c53_d_x = c53_c_x;
    c53_d_x = muDoubleScalarFloor(c53_d_x);
    if (c53_b_y == c53_d_x) {
      c53_e_x = c53_b_x / c53_b_y;
      c53_f_x = c53_e_x;
      c53_f_x = muDoubleScalarFloor(c53_f_x);
      c53_r = c53_b_x - c53_f_x * c53_b_y;
    } else {
      c53_r = c53_b_x / c53_b_y;
      c53_g_x = c53_r;
      c53_h_x = c53_g_x;
      c53_h_x = muDoubleScalarRound(c53_h_x);
      c53_i_x = c53_r - c53_h_x;
      c53_c_y = muDoubleScalarAbs(c53_i_x);
      c53_j_x = c53_r;
      c53_d_y = muDoubleScalarAbs(c53_j_x);
      if (c53_c_y <= 2.2204460492503131E-16 * c53_d_y) {
        c53_r = 0.0;
      } else {
        c53_k_x = c53_r;
        c53_l_x = c53_k_x;
        c53_l_x = muDoubleScalarFloor(c53_l_x);
        c53_r = (c53_r - c53_l_x) * c53_b_y;
      }
    }
  }

  return c53_r;
}

static void c53_eml_scalar_eg(SFc53_Assembly_QuadrotorInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *c53_b_sf_marshallOut(void *chartInstanceVoid, void
  *c53_inData)
{
  const mxArray *c53_mxArrayOutData = NULL;
  int32_T c53_u;
  const mxArray *c53_y = NULL;
  SFc53_Assembly_QuadrotorInstanceStruct *chartInstance;
  chartInstance = (SFc53_Assembly_QuadrotorInstanceStruct *)chartInstanceVoid;
  c53_mxArrayOutData = NULL;
  c53_u = *(int32_T *)c53_inData;
  c53_y = NULL;
  sf_mex_assign(&c53_y, sf_mex_create("y", &c53_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c53_mxArrayOutData, c53_y, false);
  return c53_mxArrayOutData;
}

static int32_T c53_c_emlrt_marshallIn(SFc53_Assembly_QuadrotorInstanceStruct
  *chartInstance, const mxArray *c53_u, const emlrtMsgIdentifier *c53_parentId)
{
  int32_T c53_y;
  int32_T c53_i0;
  (void)chartInstance;
  sf_mex_import(c53_parentId, sf_mex_dup(c53_u), &c53_i0, 1, 6, 0U, 0, 0U, 0);
  c53_y = c53_i0;
  sf_mex_destroy(&c53_u);
  return c53_y;
}

static void c53_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c53_mxArrayInData, const char_T *c53_varName, void *c53_outData)
{
  const mxArray *c53_b_sfEvent;
  const char_T *c53_identifier;
  emlrtMsgIdentifier c53_thisId;
  int32_T c53_y;
  SFc53_Assembly_QuadrotorInstanceStruct *chartInstance;
  chartInstance = (SFc53_Assembly_QuadrotorInstanceStruct *)chartInstanceVoid;
  c53_b_sfEvent = sf_mex_dup(c53_mxArrayInData);
  c53_identifier = c53_varName;
  c53_thisId.fIdentifier = c53_identifier;
  c53_thisId.fParent = NULL;
  c53_y = c53_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c53_b_sfEvent),
    &c53_thisId);
  sf_mex_destroy(&c53_b_sfEvent);
  *(int32_T *)c53_outData = c53_y;
  sf_mex_destroy(&c53_mxArrayInData);
}

static uint8_T c53_d_emlrt_marshallIn(SFc53_Assembly_QuadrotorInstanceStruct
  *chartInstance, const mxArray *c53_b_is_active_c53_Assembly_Quadrotor, const
  char_T *c53_identifier)
{
  uint8_T c53_y;
  emlrtMsgIdentifier c53_thisId;
  c53_thisId.fIdentifier = c53_identifier;
  c53_thisId.fParent = NULL;
  c53_y = c53_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c53_b_is_active_c53_Assembly_Quadrotor), &c53_thisId);
  sf_mex_destroy(&c53_b_is_active_c53_Assembly_Quadrotor);
  return c53_y;
}

static uint8_T c53_e_emlrt_marshallIn(SFc53_Assembly_QuadrotorInstanceStruct
  *chartInstance, const mxArray *c53_u, const emlrtMsgIdentifier *c53_parentId)
{
  uint8_T c53_y;
  uint8_T c53_u0;
  (void)chartInstance;
  sf_mex_import(c53_parentId, sf_mex_dup(c53_u), &c53_u0, 1, 3, 0U, 0, 0U, 0);
  c53_y = c53_u0;
  sf_mex_destroy(&c53_u);
  return c53_y;
}

static void init_dsm_address_info(SFc53_Assembly_QuadrotorInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
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

void sf_c53_Assembly_Quadrotor_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3709772258U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1254931316U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1362683153U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3144525742U);
}

mxArray *sf_c53_Assembly_Quadrotor_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("0kcfGSqDG0e4PvXhH39srF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c53_Assembly_Quadrotor_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c53_Assembly_Quadrotor_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c53_Assembly_Quadrotor(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[6],T\"AngleFix\",},{M[8],M[0],T\"is_active_c53_Assembly_Quadrotor\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c53_Assembly_Quadrotor_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc53_Assembly_QuadrotorInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc53_Assembly_QuadrotorInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Assembly_QuadrotorMachineNumber_,
           53,
           1,
           1,
           0,
           2,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_Assembly_QuadrotorMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Assembly_QuadrotorMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Assembly_QuadrotorMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"AngleDeg");
          _SFD_SET_DATA_PROPS(1,2,0,1,"AngleFix");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,150);
        _SFD_CV_INIT_EML_IF(0,1,0,52,67,102,150);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c53_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c53_sf_marshallOut,(MexInFcnForType)c53_sf_marshallIn);

        {
          real_T *c53_AngleDeg;
          real_T *c53_AngleFix;
          c53_AngleFix = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c53_AngleDeg = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c53_AngleDeg);
          _SFD_SET_DATA_VALUE_PTR(1U, c53_AngleFix);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Assembly_QuadrotorMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "zr2VeMEavtjy6AdGWeSmmD";
}

static void sf_opaque_initialize_c53_Assembly_Quadrotor(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc53_Assembly_QuadrotorInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c53_Assembly_Quadrotor
    ((SFc53_Assembly_QuadrotorInstanceStruct*) chartInstanceVar);
  initialize_c53_Assembly_Quadrotor((SFc53_Assembly_QuadrotorInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c53_Assembly_Quadrotor(void *chartInstanceVar)
{
  enable_c53_Assembly_Quadrotor((SFc53_Assembly_QuadrotorInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c53_Assembly_Quadrotor(void *chartInstanceVar)
{
  disable_c53_Assembly_Quadrotor((SFc53_Assembly_QuadrotorInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c53_Assembly_Quadrotor(void *chartInstanceVar)
{
  sf_gateway_c53_Assembly_Quadrotor((SFc53_Assembly_QuadrotorInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c53_Assembly_Quadrotor(SimStruct*
  S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c53_Assembly_Quadrotor
    ((SFc53_Assembly_QuadrotorInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c53_Assembly_Quadrotor();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c53_Assembly_Quadrotor(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c53_Assembly_Quadrotor();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c53_Assembly_Quadrotor((SFc53_Assembly_QuadrotorInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c53_Assembly_Quadrotor(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c53_Assembly_Quadrotor(S);
}

static void sf_opaque_set_sim_state_c53_Assembly_Quadrotor(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c53_Assembly_Quadrotor(S, st);
}

static void sf_opaque_terminate_c53_Assembly_Quadrotor(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc53_Assembly_QuadrotorInstanceStruct*) chartInstanceVar
      )->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Assembly_Quadrotor_optimization_info();
    }

    finalize_c53_Assembly_Quadrotor((SFc53_Assembly_QuadrotorInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc53_Assembly_Quadrotor((SFc53_Assembly_QuadrotorInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c53_Assembly_Quadrotor(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    initialize_params_c53_Assembly_Quadrotor
      ((SFc53_Assembly_QuadrotorInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c53_Assembly_Quadrotor(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Assembly_Quadrotor_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      53);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,53,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,53,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,53);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,53,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,53,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,53);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4048153443U));
  ssSetChecksum1(S,(38617625U));
  ssSetChecksum2(S,(2765847627U));
  ssSetChecksum3(S,(2709379406U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c53_Assembly_Quadrotor(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c53_Assembly_Quadrotor(SimStruct *S)
{
  SFc53_Assembly_QuadrotorInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc53_Assembly_QuadrotorInstanceStruct *)utMalloc(sizeof
    (SFc53_Assembly_QuadrotorInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc53_Assembly_QuadrotorInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c53_Assembly_Quadrotor;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c53_Assembly_Quadrotor;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c53_Assembly_Quadrotor;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c53_Assembly_Quadrotor;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c53_Assembly_Quadrotor;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c53_Assembly_Quadrotor;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c53_Assembly_Quadrotor;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c53_Assembly_Quadrotor;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c53_Assembly_Quadrotor;
  chartInstance->chartInfo.mdlStart = mdlStart_c53_Assembly_Quadrotor;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c53_Assembly_Quadrotor;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  crtInfo->instanceInfo = (&(chartInstance->chartInfo));
  crtInfo->isJITEnabled = false;
  ssSetUserData(S,(void *)(crtInfo));  /* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c53_Assembly_Quadrotor_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c53_Assembly_Quadrotor(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c53_Assembly_Quadrotor(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c53_Assembly_Quadrotor(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c53_Assembly_Quadrotor_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
