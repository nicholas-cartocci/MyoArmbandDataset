//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: gestureClassification_C_rtwutil.h
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 23-Nov-2022 17:22:04
//

#ifndef GESTURECLASSIFICATION_C_RTWUTIL_H
#define GESTURECLASSIFICATION_C_RTWUTIL_H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
extern void b_microKernel(int K, const float *A, int LDA, const float *B,
                          float *C);

extern int div_s32_floor(int numerator, int denominator);

extern void macroKernel(int M, int K, const float *A, int LDA, const float *B,
                        int LDB, float *C);

extern void matrixMultiply(int M, int K, int blockSizeM, const float *A,
                           const float *B, float *C);

extern void microKernel(int K, const float *A, int LDA, const float *B,
                        float *C);

#endif
//
// File trailer for gestureClassification_C_rtwutil.h
//
// [EOF]
//
