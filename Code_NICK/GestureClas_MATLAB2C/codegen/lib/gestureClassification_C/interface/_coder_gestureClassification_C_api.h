//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: _coder_gestureClassification_C_api.h
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 23-Nov-2022 17:22:04
//

#ifndef _CODER_GESTURECLASSIFICATION_C_API_H
#define _CODER_GESTURECLASSIFICATION_C_API_H

// Include Files
#include "emlrt.h"
#include "tmwtypes.h"
#include <algorithm>
#include <cstring>

// Variable Declarations
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

// Function Declarations
void gestureClassification_C(real_T DATA[8], real32_T Perc[3]);

void gestureClassification_C_api(const mxArray *prhs, const mxArray **plhs);

void gestureClassification_C_atexit();

void gestureClassification_C_initialize();

void gestureClassification_C_terminate();

void gestureClassification_C_xil_shutdown();

void gestureClassification_C_xil_terminate();

#endif
//
// File trailer for _coder_gestureClassification_C_api.h
//
// [EOF]
//
