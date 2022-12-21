//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: postProcessOutputToReturnCategorical.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 23-Nov-2022 17:22:04
//

// Include Files
#include "postProcessOutputToReturnCategorical.h"
#include "categorical.h"
#include "cellstr_sort.h"
#include "gestureClassification_C_internal_types.h"
#include "strtrim.h"
#include "coder_bounded_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const cell_wrap_21 scores
// Return Type  : void
//
namespace coder {
namespace internal {
namespace ctarget {
void DeepLearningNetwork_postProcessOutputToReturnCategorical(
    const cell_wrap_21 scores)
{
  static const char classNames[45]{
      'N',    'W', 'W', 'e',    'r', 'r',    'u',    'i', 'i',
      't',    's', 's', 'r',    't', 't',    'a',    ' ', ' ',
      'l',    'E', 'F', '\x00', 'x', 'l',    '\x00', 't', 'e',
      '\x00', 'e', 'x', '\x00', 'n', 'i',    '\x00', 's', 'o',
      '\x00', 'i', 'n', '\x00', 'o', '\x00', '\x00', 'n', '\x00'};
  bounded_array<cell_wrap_6, 3U, 2U> labelsCells;
  bounded_array<cell_wrap_6, 3U, 2U> r;
  bounded_array<cell_wrap_6, 3U, 1U> b_c;
  int idx_data[3];
  int i;
  int idx;
  int k;
  if (!std::isnan(scores.f1[0])) {
    idx = 1;
  } else {
    bool exitg1;
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (!std::isnan(scores.f1[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if (idx == 0) {
    idx = 1;
  } else {
    float ex;
    ex = scores.f1[idx - 1];
    i = idx + 1;
    for (k = i; k < 4; k++) {
      float f;
      f = scores.f1[k - 1];
      if (ex < f) {
        ex = f;
        idx = k;
      }
    }
  }
  labelsCells.size[0] = 1;
  labelsCells.size[1] = 0;
  for (int b_i{0}; b_i < 3; b_i++) {
    int n;
    char v_data[15];
    n = 0;
    i = -1;
    for (k = 0; k < 15; k++) {
      char c;
      c = classNames[b_i + 3 * k];
      if (c != 0) {
        n++;
        i++;
        v_data[i] = c;
      }
    }
    i = labelsCells.size[1] + 1;
    labelsCells.size[0] = 1;
    labelsCells.size[1]++;
    labelsCells.data[i - 1].f1.size[0] = 1;
    labelsCells.data[labelsCells.size[1] - 1].f1.size[1] = n;
    for (i = 0; i < n; i++) {
      labelsCells.data[labelsCells.size[1] - 1].f1.data[i] = v_data[i];
    }
  }
  cell_wrap_6 inData;
  strtrim(labelsCells.data[idx - 1].f1.data, labelsCells.data[idx - 1].f1.size,
          inData.f1.data, inData.f1.size);
  r.size[0] = 1;
  r.size[1] = labelsCells.size[1];
  i = labelsCells.size[1];
  for (int b_i{0}; b_i < i; b_i++) {
    strtrim(labelsCells.data[b_i].f1.data, labelsCells.data[b_i].f1.size,
            r.data[b_i].f1.data, r.data[b_i].f1.size);
  }
  if (r.size[1] != 0) {
    matlab::internal::coder::datatypes::cellstr_sort(
        r.data, r.size[1], b_c.data, &b_c.size[0], idx_data, &i);
  }
  categorical::initDataValueSet(r.data, r.size[1]);
}

} // namespace ctarget
} // namespace internal
} // namespace coder

//
// File trailer for postProcessOutputToReturnCategorical.cpp
//
// [EOF]
//
