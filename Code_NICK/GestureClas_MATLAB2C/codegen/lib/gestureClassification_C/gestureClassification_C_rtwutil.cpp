//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: gestureClassification_C_rtwutil.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 23-Nov-2022 17:22:04
//

// Include Files
#include "gestureClassification_C_rtwutil.h"
#include "omp.h"

// Function Definitions
//
// Arguments    : int K
//                const float *A
//                int LDA
//                const float *B
//                float *C
// Return Type  : void
//
void b_microKernel(int K, const float *A, int LDA, const float *B, float *C)
{
  float c;
  int A_idx;
  int B_idx;
  A_idx = 0;
  B_idx = 0;
  c = C[0];
  for (int k{0}; k < K; k++) {
    float a;
    float b;
    a = A[A_idx];
    b = B[B_idx];
    c += a * b;
    A_idx += LDA;
    B_idx++;
  }
  C[0] = c;
}

//
// Arguments    : int numerator
//                int denominator
// Return Type  : int
//
int div_s32_floor(int numerator, int denominator)
{
  int quotient;
  if (denominator == 0) {
    if (numerator >= 0) {
      quotient = MAX_int32_T;
    } else {
      quotient = MIN_int32_T;
    }
  } else {
    unsigned int absDenominator;
    unsigned int absNumerator;
    unsigned int tempAbsQuotient;
    bool quotientNeedsNegation;
    if (numerator < 0) {
      absNumerator = ~static_cast<unsigned int>(numerator) + 1U;
    } else {
      absNumerator = static_cast<unsigned int>(numerator);
    }
    if (denominator < 0) {
      absDenominator = ~static_cast<unsigned int>(denominator) + 1U;
    } else {
      absDenominator = static_cast<unsigned int>(denominator);
    }
    quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
    tempAbsQuotient = absNumerator / absDenominator;
    if (quotientNeedsNegation) {
      absNumerator %= absDenominator;
      if (absNumerator > 0U) {
        tempAbsQuotient++;
      }
      quotient = -static_cast<int>(tempAbsQuotient);
    } else {
      quotient = static_cast<int>(tempAbsQuotient);
    }
  }
  return quotient;
}

//
// Arguments    : int M
//                int K
//                const float *A
//                int LDA
//                const float *B
//                int LDB
//                float *C
// Return Type  : void
//
void macroKernel(int M, int K, const float *A, int LDA, const float *B, int LDB,
                 float *C)
{
  int B_idx;
  int j;
  j = 0;
  B_idx = 0;
  while (j <= 0) {
    int A_idx;
    int i;
    j = 0;
    i = 0;
    A_idx = 0;
    while (i <= M - 2) {
      microKernel(K, &A[A_idx], LDA, &B[B_idx], &C[j]);
      A_idx += 2;
      j += 2;
      i += 2;
    }
    while (i <= M - 1) {
      b_microKernel(K, &A[A_idx], LDA, &B[B_idx], &C[j]);
      A_idx++;
      j++;
      i++;
    }
    B_idx += LDB;
    j = 1;
  }
}

//
// Arguments    : int M
//                int K
//                int blockSizeM
//                const float *A
//                const float *B
//                float *C
// Return Type  : void
//
void matrixMultiply(int M, int K, int blockSizeM, const float *A,
                    const float *B, float *C)
{
  const float *B_ptr;
  int b_i;
  int i;
  int i0_ub;
  int k0_ub;
  if (blockSizeM >= M) {
    blockSizeM = M;
  } else {
    blockSizeM = (blockSizeM >> 1) << 1;
    if (blockSizeM <= 0) {
      blockSizeM = 1;
    }
  }
  i0_ub = div_s32_floor(M - 1, blockSizeM) + 1;
  k0_ub = ((K - 1) >> 6) + 1;
  for (int k0{1}; k0 <= k0_ub; k0++) {
    int K2;
    int k;
    k = (k0 - 1) << 6;
    if (k > K - 64) {
      K2 = K - k;
    } else {
      K2 = 64;
    }
    B_ptr = &B[k];
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i, b_i)

    for (int i0 = 1; i0 <= i0_ub; i0++) {
      i = (i0 - 1) * blockSizeM;
      if (i > M - blockSizeM) {
        b_i = M - i;
      } else {
        b_i = blockSizeM;
      }
      macroKernel(b_i, K2, &A[i + M * k], M, B_ptr, K, &C[i]);
    }
  }
}

//
// Arguments    : int K
//                const float *A
//                int LDA
//                const float *B
//                float *C
// Return Type  : void
//
void microKernel(int K, const float *A, int LDA, const float *B, float *C)
{
  float b_c;
  float c;
  int A_idx;
  int B_idx;
  A_idx = 0;
  B_idx = 0;
  c = C[0];
  b_c = C[1];
  for (int k{0}; k < K; k++) {
    float a;
    float b;
    float b_a;
    a = A[A_idx];
    b_a = A[A_idx + 1];
    b = B[B_idx];
    c += a * b;
    b_c += b_a * b;
    A_idx += LDA;
    B_idx++;
  }
  C[0] = c;
  C[1] = b_c;
}

//
// File trailer for gestureClassification_C_rtwutil.cpp
//
// [EOF]
//
