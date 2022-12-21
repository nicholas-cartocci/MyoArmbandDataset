//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: _coder_get_data_Roberto_mex.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:23:51
//

// Include Files
#include "_coder_get_data_Roberto_mex.h"
#include "_coder_get_data_Roberto_api.h"

// Function Definitions
//
// Arguments    : int32_T nlhs
//                mxArray *plhs[]
//                int32_T nrhs
//                const mxArray *prhs[]
// Return Type  : void
//
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray *[])
{
  mexAtExit(&get_data_Roberto_atexit);
  // Module initialization.
  get_data_Roberto_initialize();
  // Dispatch the entry-point.
  unsafe_get_data_Roberto_mexFunction(nlhs, plhs, nrhs);
  // Module termination.
  get_data_Roberto_terminate();
}

//
// Arguments    : void
// Return Type  : emlrtCTX
//
emlrtCTX mexFunctionCreateRootTLS()
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, nullptr, 1,
                           nullptr, "windows-1252", true);
  return emlrtRootTLSGlobal;
}

//
// Arguments    : int32_T nlhs
//                mxArray *plhs[12]
//                int32_T nrhs
// Return Type  : void
//
void unsafe_get_data_Roberto_mexFunction(int32_T nlhs, mxArray *plhs[12],
                                         int32_T nrhs)
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  const mxArray *outputs[12];
  int32_T i;
  st.tls = emlrtRootTLSGlobal;
  // Check for proper number of arguments.
  if (nrhs != 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 0, 4,
                        16, "get_data_Roberto");
  }
  if (nlhs > 12) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 16,
                        "get_data_Roberto");
  }
  // Call the function.
  get_data_Roberto_api(nlhs, outputs);
  // Copy over outputs to the caller.
  if (nlhs < 1) {
    i = 1;
  } else {
    i = nlhs;
  }
  emlrtReturnArrays(i, &plhs[0], &outputs[0]);
}

//
// File trailer for _coder_get_data_Roberto_mex.cpp
//
// [EOF]
//
