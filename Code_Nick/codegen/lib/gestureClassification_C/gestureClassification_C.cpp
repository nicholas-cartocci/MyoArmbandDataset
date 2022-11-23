//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: gestureClassification_C.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 23-Nov-2022 17:22:04
//

// Include Files
#include "gestureClassification_C.h"
#include "classifyAndUpdateState.h"
#include "gestureClassification_C_data.h"
#include "gestureClassification_C_initialize.h"
#include "gestureClassification_C_internal_types.h"
#include "postProcessOutputToReturnCategorical.h"
#include "predict.h"
#include <cmath>
#include <cstring>

// Variable Definitions
static coder::internal::ctarget::DeepLearningNetwork net;

static bool net_not_empty;

static double BUFFER[320];

static double iBUFFER;

// Function Definitions
//
// Arguments    : const double DATA[8]
//                float Perc[3]
// Return Type  : void
//
void gestureClassification_C(const double DATA[8], float Perc[3])
{
  static const double dv[8]{
      62.5341966817099, 115.454332583449, 114.153665342948, 65.7814640082061,
      40.252540377884,  100.421821047113, 79.0393829388866, 71.4412803477133};
  static const double dv1[5]{0.00041659920440659639, 0.0016663968176263855,
                             0.0024995952264395783, 0.0016663968176263855,
                             0.00041659920440659639};
  static const double dv2[5]{1.0, -3.18063854887472, 3.8611943489942155,
                             -2.1121553551109704, 0.43826514226198021};
  if (!isInitialized_gestureClassification_C) {
    gestureClassification_C_initialize();
  }
  if (!net_not_empty) {
    net.IsNetworkInitialized = false;
    net.matlabCodegenIsDeleted = false;
    net_not_empty = true;
  }
  if (iBUFFER < 41.0) {
    for (int i{0}; i < 8; i++) {
      BUFFER[i + ((static_cast<int>(iBUFFER) - 1) << 3)] = DATA[i];
    }
    cell_wrap_21 r;
    iBUFFER++;
    coder::internal::ctarget::DeepLearningNetwork_predict(&net, Perc);
    r.f1[0] = Perc[0];
    r.f1[1] = Perc[1];
    r.f1[2] = Perc[2];
    coder::internal::ctarget::
        DeepLearningNetwork_postProcessOutputToReturnCategorical(r);
  } else {
    double signals[320];
    double signals_Rect[320];
    double b_signals[8];
    int i;
    for (i = 0; i < 312; i++) {
      BUFFER[i] = BUFFER[i + 8];
    }
    //  Treatment
    //  Hz
    for (i = 0; i < 8; i++) {
      BUFFER[i + 312] = DATA[i];
      for (int k{0}; k < 40; k++) {
        signals[k + 40 * i] = BUFFER[i + (k << 3)];
      }
    }
    for (int k{0}; k < 320; k++) {
      signals_Rect[k] = std::abs(signals[k]);
      signals[k] = 0.0;
    }
    for (int c{0}; c < 8; c++) {
      int offset;
      offset = c * 40 - 1;
      for (int k{0}; k < 40; k++) {
        double as;
        int jp;
        int signals_tmp;
        jp = (offset + k) + 1;
        if (40 - k < 5) {
          i = 39 - k;
        } else {
          i = 4;
        }
        for (int j{0}; j <= i; j++) {
          signals_tmp = jp + j;
          signals[signals_tmp] += signals_Rect[jp] * dv1[j];
        }
        if (39 - k < 4) {
          i = 38 - k;
        } else {
          i = 3;
        }
        as = -signals[jp];
        for (int j{0}; j <= i; j++) {
          signals_tmp = (jp + j) + 1;
          signals[signals_tmp] += as * dv2[j + 1];
        }
      }
    }
    //  Normalization
    //  Classification
    for (i = 0; i < 8; i++) {
      b_signals[i] = signals[40 * i + 39] / dv[i];
    }
    coder::internal::ctarget::DeepLearningNetwork_classifyAndUpdateState(
        &net, b_signals, Perc);
  }
}

//
// Arguments    : void
// Return Type  : void
//
void gestureClassification_C_free()
{
  if (!net.matlabCodegenIsDeleted) {
    net.matlabCodegenIsDeleted = true;
  }
}

//
// Arguments    : void
// Return Type  : void
//
void gestureClassification_C_init()
{
  net_not_empty = false;
  net.matlabCodegenIsDeleted = true;
  std::memset(&BUFFER[0], 0, 320U * sizeof(double));
  iBUFFER = 1.0;
}

//
// File trailer for gestureClassification_C.cpp
//
// [EOF]
//
