//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: _coder_get_data_Roberto_api.h
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:23:51
//

#ifndef _CODER_GET_DATA_ROBERTO_API_H
#define _CODER_GET_DATA_ROBERTO_API_H

// Include Files
#include "emlrt.h"
#include "tmwtypes.h"
#include <algorithm>
#include <cstring>

// Type Definitions
struct struct0_T {
  real_T DATA_Neutral_Raw[9456];
};

struct struct1_T {
  real_T DATA_Flexion_Raw[8400];
};

struct struct2_T {
  real_T DATA_Extension_Raw[8744];
};

struct struct3_T {
  real_T DATA_Dynamic_Raw[19808];
};

struct struct4_T {
  real_T DATA_MVCFlex_Raw[12432];
};

struct struct5_T {
  real_T DATA_MVCExt_Raw[12320];
};

struct struct6_T {
  real_T DATA_Neutral_Proc[9456];
};

struct struct7_T {
  real_T DATA_Flexion_Proc[8400];
};

struct struct8_T {
  real_T DATA_Extension_Proc[8744];
};

struct struct9_T {
  real_T DATA_Dynamic_Proc[19808];
};

struct struct10_T {
  real_T DATA_MVCFlex_Proc[12432];
};

struct struct11_T {
  real_T DATA_MVCExt_Proc[12320];
};

// Variable Declarations
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

// Function Declarations
void get_data_Roberto(struct0_T *DATA_Neutral_Raw, struct1_T *DATA_Flexion_Raw,
                      struct2_T *DATA_Extension_Raw,
                      struct3_T *DATA_Dynamic_Raw, struct4_T *DATA_MVCFlex_Raw,
                      struct5_T *DATA_MVCExt_Raw, struct6_T *DATA_Neutral_Proc,
                      struct7_T *DATA_Flexion_Proc,
                      struct8_T *DATA_Extension_Proc,
                      struct9_T *DATA_Dynamic_Proc,
                      struct10_T *DATA_MVCFlex_Proc,
                      struct11_T *DATA_MVCExt_Proc);

void get_data_Roberto_api(int32_T nlhs, const mxArray *plhs[12]);

void get_data_Roberto_atexit();

void get_data_Roberto_initialize();

void get_data_Roberto_terminate();

void get_data_Roberto_xil_shutdown();

void get_data_Roberto_xil_terminate();

#endif
//
// File trailer for _coder_get_data_Roberto_api.h
//
// [EOF]
//
