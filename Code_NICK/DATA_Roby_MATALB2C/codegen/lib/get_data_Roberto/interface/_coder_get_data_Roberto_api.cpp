//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: _coder_get_data_Roberto_api.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:23:51
//

// Include Files
#include "_coder_get_data_Roberto_api.h"
#include "_coder_get_data_Roberto_mex.h"

// Variable Definitions
emlrtCTX emlrtRootTLSGlobal{nullptr};

emlrtContext emlrtContextGlobal{
    true,                                                 // bFirstTime
    false,                                                // bInitialized
    131627U,                                              // fVersionInfo
    nullptr,                                              // fErrorFunction
    "get_data_Roberto",                                   // fFunctionName
    nullptr,                                              // fRTCallStack
    false,                                                // bDebugMode
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, // fSigWrd
    nullptr                                               // fSigMem
};

// Function Declarations
static const mxArray *b_emlrt_marshallOut(const real_T u[8400]);

static const mxArray *c_emlrt_marshallOut(const real_T u[8744]);

static const mxArray *d_emlrt_marshallOut(const real_T u[19808]);

static const mxArray *e_emlrt_marshallOut(const real_T u[12432]);

static const mxArray *emlrt_marshallOut(const struct0_T *u);

static const mxArray *emlrt_marshallOut(const struct1_T *u);

static const mxArray *emlrt_marshallOut(const struct2_T *u);

static const mxArray *emlrt_marshallOut(const struct3_T *u);

static const mxArray *emlrt_marshallOut(const struct4_T *u);

static const mxArray *emlrt_marshallOut(const struct5_T *u);

static const mxArray *emlrt_marshallOut(const struct6_T *u);

static const mxArray *emlrt_marshallOut(const real_T u[9456]);

static const mxArray *emlrt_marshallOut(const struct7_T *u);

static const mxArray *emlrt_marshallOut(const struct8_T *u);

static const mxArray *emlrt_marshallOut(const struct9_T *u);

static const mxArray *emlrt_marshallOut(const struct10_T *u);

static const mxArray *emlrt_marshallOut(const struct11_T *u);

static const mxArray *f_emlrt_marshallOut(const real_T u[12320]);

// Function Definitions
//
// Arguments    : const real_T u[8400]
// Return Type  : const mxArray *
//
static const mxArray *b_emlrt_marshallOut(const real_T u[8400])
{
  static const int32_T iv[2]{8, 1050};
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T i;
  y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (int32_T b_i{0}; b_i < 1050; b_i++) {
    for (int32_T c_i{0}; c_i < 8; c_i++) {
      pData[i + c_i] = u[c_i + (b_i << 3)];
    }
    i += 8;
  }
  emlrtAssign(&y, m);
  return y;
}

//
// Arguments    : const real_T u[8744]
// Return Type  : const mxArray *
//
static const mxArray *c_emlrt_marshallOut(const real_T u[8744])
{
  static const int32_T iv[2]{8, 1093};
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T i;
  y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (int32_T b_i{0}; b_i < 1093; b_i++) {
    for (int32_T c_i{0}; c_i < 8; c_i++) {
      pData[i + c_i] = u[c_i + (b_i << 3)];
    }
    i += 8;
  }
  emlrtAssign(&y, m);
  return y;
}

//
// Arguments    : const real_T u[19808]
// Return Type  : const mxArray *
//
static const mxArray *d_emlrt_marshallOut(const real_T u[19808])
{
  static const int32_T iv[2]{8, 2476};
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T i;
  y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (int32_T b_i{0}; b_i < 2476; b_i++) {
    for (int32_T c_i{0}; c_i < 8; c_i++) {
      pData[i + c_i] = u[c_i + (b_i << 3)];
    }
    i += 8;
  }
  emlrtAssign(&y, m);
  return y;
}

//
// Arguments    : const real_T u[12432]
// Return Type  : const mxArray *
//
static const mxArray *e_emlrt_marshallOut(const real_T u[12432])
{
  static const int32_T iv[2]{8, 1554};
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T i;
  y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (int32_T b_i{0}; b_i < 1554; b_i++) {
    for (int32_T c_i{0}; c_i < 8; c_i++) {
      pData[i + c_i] = u[c_i + (b_i << 3)];
    }
    i += 8;
  }
  emlrtAssign(&y, m);
  return y;
}

//
// Arguments    : const struct0_T *u
// Return Type  : const mxArray *
//
static const mxArray *emlrt_marshallOut(const struct0_T *u)
{
  static const char_T *s{"DATA_Neutral_Raw"};
  const mxArray *y;
  y = nullptr;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 1, (const char_T **)&s));
  emlrtSetFieldR2017b(y, 0, "DATA_Neutral_Raw",
                      emlrt_marshallOut(u->DATA_Neutral_Raw), 0);
  return y;
}

//
// Arguments    : const struct1_T *u
// Return Type  : const mxArray *
//
static const mxArray *emlrt_marshallOut(const struct1_T *u)
{
  static const char_T *s{"DATA_Flexion_Raw"};
  const mxArray *y;
  y = nullptr;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 1, (const char_T **)&s));
  emlrtSetFieldR2017b(y, 0, "DATA_Flexion_Raw",
                      b_emlrt_marshallOut(u->DATA_Flexion_Raw), 0);
  return y;
}

//
// Arguments    : const struct2_T *u
// Return Type  : const mxArray *
//
static const mxArray *emlrt_marshallOut(const struct2_T *u)
{
  static const char_T *s{"DATA_Extension_Raw"};
  const mxArray *y;
  y = nullptr;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 1, (const char_T **)&s));
  emlrtSetFieldR2017b(y, 0, "DATA_Extension_Raw",
                      c_emlrt_marshallOut(u->DATA_Extension_Raw), 0);
  return y;
}

//
// Arguments    : const struct3_T *u
// Return Type  : const mxArray *
//
static const mxArray *emlrt_marshallOut(const struct3_T *u)
{
  static const char_T *s{"DATA_Dynamic_Raw"};
  const mxArray *y;
  y = nullptr;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 1, (const char_T **)&s));
  emlrtSetFieldR2017b(y, 0, "DATA_Dynamic_Raw",
                      d_emlrt_marshallOut(u->DATA_Dynamic_Raw), 0);
  return y;
}

//
// Arguments    : const struct4_T *u
// Return Type  : const mxArray *
//
static const mxArray *emlrt_marshallOut(const struct4_T *u)
{
  static const char_T *s{"DATA_MVCFlex_Raw"};
  const mxArray *y;
  y = nullptr;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 1, (const char_T **)&s));
  emlrtSetFieldR2017b(y, 0, "DATA_MVCFlex_Raw",
                      e_emlrt_marshallOut(u->DATA_MVCFlex_Raw), 0);
  return y;
}

//
// Arguments    : const struct5_T *u
// Return Type  : const mxArray *
//
static const mxArray *emlrt_marshallOut(const struct5_T *u)
{
  static const char_T *s{"DATA_MVCExt_Raw"};
  const mxArray *y;
  y = nullptr;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 1, (const char_T **)&s));
  emlrtSetFieldR2017b(y, 0, "DATA_MVCExt_Raw",
                      f_emlrt_marshallOut(u->DATA_MVCExt_Raw), 0);
  return y;
}

//
// Arguments    : const struct6_T *u
// Return Type  : const mxArray *
//
static const mxArray *emlrt_marshallOut(const struct6_T *u)
{
  static const char_T *s{"DATA_Neutral_Proc"};
  const mxArray *y;
  y = nullptr;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 1, (const char_T **)&s));
  emlrtSetFieldR2017b(y, 0, "DATA_Neutral_Proc",
                      emlrt_marshallOut(u->DATA_Neutral_Proc), 0);
  return y;
}

//
// Arguments    : const real_T u[9456]
// Return Type  : const mxArray *
//
static const mxArray *emlrt_marshallOut(const real_T u[9456])
{
  static const int32_T iv[2]{8, 1182};
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T i;
  y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (int32_T b_i{0}; b_i < 1182; b_i++) {
    for (int32_T c_i{0}; c_i < 8; c_i++) {
      pData[i + c_i] = u[c_i + (b_i << 3)];
    }
    i += 8;
  }
  emlrtAssign(&y, m);
  return y;
}

//
// Arguments    : const struct7_T *u
// Return Type  : const mxArray *
//
static const mxArray *emlrt_marshallOut(const struct7_T *u)
{
  static const char_T *s{"DATA_Flexion_Proc"};
  const mxArray *y;
  y = nullptr;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 1, (const char_T **)&s));
  emlrtSetFieldR2017b(y, 0, "DATA_Flexion_Proc",
                      b_emlrt_marshallOut(u->DATA_Flexion_Proc), 0);
  return y;
}

//
// Arguments    : const struct8_T *u
// Return Type  : const mxArray *
//
static const mxArray *emlrt_marshallOut(const struct8_T *u)
{
  static const char_T *s{"DATA_Extension_Proc"};
  const mxArray *y;
  y = nullptr;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 1, (const char_T **)&s));
  emlrtSetFieldR2017b(y, 0, "DATA_Extension_Proc",
                      c_emlrt_marshallOut(u->DATA_Extension_Proc), 0);
  return y;
}

//
// Arguments    : const struct9_T *u
// Return Type  : const mxArray *
//
static const mxArray *emlrt_marshallOut(const struct9_T *u)
{
  static const char_T *s{"DATA_Dynamic_Proc"};
  const mxArray *y;
  y = nullptr;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 1, (const char_T **)&s));
  emlrtSetFieldR2017b(y, 0, "DATA_Dynamic_Proc",
                      d_emlrt_marshallOut(u->DATA_Dynamic_Proc), 0);
  return y;
}

//
// Arguments    : const struct10_T *u
// Return Type  : const mxArray *
//
static const mxArray *emlrt_marshallOut(const struct10_T *u)
{
  static const char_T *s{"DATA_MVCFlex_Proc"};
  const mxArray *y;
  y = nullptr;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 1, (const char_T **)&s));
  emlrtSetFieldR2017b(y, 0, "DATA_MVCFlex_Proc",
                      e_emlrt_marshallOut(u->DATA_MVCFlex_Proc), 0);
  return y;
}

//
// Arguments    : const struct11_T *u
// Return Type  : const mxArray *
//
static const mxArray *emlrt_marshallOut(const struct11_T *u)
{
  static const char_T *s{"DATA_MVCExt_Proc"};
  const mxArray *y;
  y = nullptr;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 1, (const char_T **)&s));
  emlrtSetFieldR2017b(y, 0, "DATA_MVCExt_Proc",
                      f_emlrt_marshallOut(u->DATA_MVCExt_Proc), 0);
  return y;
}

//
// Arguments    : const real_T u[12320]
// Return Type  : const mxArray *
//
static const mxArray *f_emlrt_marshallOut(const real_T u[12320])
{
  static const int32_T iv[2]{8, 1540};
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T i;
  y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (int32_T b_i{0}; b_i < 1540; b_i++) {
    for (int32_T c_i{0}; c_i < 8; c_i++) {
      pData[i + c_i] = u[c_i + (b_i << 3)];
    }
    i += 8;
  }
  emlrtAssign(&y, m);
  return y;
}

//
// Arguments    : int32_T nlhs
//                const mxArray *plhs[12]
// Return Type  : void
//
void get_data_Roberto_api(int32_T nlhs, const mxArray *plhs[12])
{
  static struct0_T DATA_Neutral_Raw;
  static struct10_T DATA_MVCFlex_Proc;
  static struct11_T DATA_MVCExt_Proc;
  static struct2_T DATA_Extension_Raw;
  static struct3_T DATA_Dynamic_Raw;
  static struct4_T DATA_MVCFlex_Raw;
  static struct5_T DATA_MVCExt_Raw;
  static struct6_T DATA_Neutral_Proc;
  static struct8_T DATA_Extension_Proc;
  static struct9_T DATA_Dynamic_Proc;
  struct1_T DATA_Flexion_Raw;
  struct7_T DATA_Flexion_Proc;
  // Invoke the target function
  get_data_Roberto(&DATA_Neutral_Raw, &DATA_Flexion_Raw, &DATA_Extension_Raw,
                   &DATA_Dynamic_Raw, &DATA_MVCFlex_Raw, &DATA_MVCExt_Raw,
                   &DATA_Neutral_Proc, &DATA_Flexion_Proc, &DATA_Extension_Proc,
                   &DATA_Dynamic_Proc, &DATA_MVCFlex_Proc, &DATA_MVCExt_Proc);
  // Marshall function outputs
  plhs[0] = emlrt_marshallOut(&DATA_Neutral_Raw);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(&DATA_Flexion_Raw);
  }
  if (nlhs > 2) {
    plhs[2] = emlrt_marshallOut(&DATA_Extension_Raw);
  }
  if (nlhs > 3) {
    plhs[3] = emlrt_marshallOut(&DATA_Dynamic_Raw);
  }
  if (nlhs > 4) {
    plhs[4] = emlrt_marshallOut(&DATA_MVCFlex_Raw);
  }
  if (nlhs > 5) {
    plhs[5] = emlrt_marshallOut(&DATA_MVCExt_Raw);
  }
  if (nlhs > 6) {
    plhs[6] = emlrt_marshallOut(&DATA_Neutral_Proc);
  }
  if (nlhs > 7) {
    plhs[7] = emlrt_marshallOut(&DATA_Flexion_Proc);
  }
  if (nlhs > 8) {
    plhs[8] = emlrt_marshallOut(&DATA_Extension_Proc);
  }
  if (nlhs > 9) {
    plhs[9] = emlrt_marshallOut(&DATA_Dynamic_Proc);
  }
  if (nlhs > 10) {
    plhs[10] = emlrt_marshallOut(&DATA_MVCFlex_Proc);
  }
  if (nlhs > 11) {
    plhs[11] = emlrt_marshallOut(&DATA_MVCExt_Proc);
  }
}

//
// Arguments    : void
// Return Type  : void
//
void get_data_Roberto_atexit()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  get_data_Roberto_xil_terminate();
  get_data_Roberto_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

//
// Arguments    : void
// Return Type  : void
//
void get_data_Roberto_initialize()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, nullptr);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

//
// Arguments    : void
// Return Type  : void
//
void get_data_Roberto_terminate()
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

//
// File trailer for _coder_get_data_Roberto_api.cpp
//
// [EOF]
//
