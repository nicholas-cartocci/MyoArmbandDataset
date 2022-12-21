//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: categorical.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 23-Nov-2022 17:22:04
//

// Include Files
#include "categorical.h"
#include "cellstr_sort.h"
#include "find.h"
#include "gestureClassification_C_internal_types.h"
#include "strcmp.h"
#include "coder_bounded_array.h"
#include <algorithm>
#include <cstring>

// Function Definitions
//
// Arguments    : const cell_wrap_6 valueSet_data[]
//                int valueSet_size
// Return Type  : void
//
namespace coder {
void categorical::initDataValueSet(const cell_wrap_6 valueSet_data[],
                                   int valueSet_size)
{
  bounded_array<cell_wrap_6, 3U, 1U> c;
  int dIdx_data[3];
  int idx_data[3];
  int idx_size;
  int minSize;
  bool b_d_data[3];
  bool d_data[2];
  if (valueSet_size == 0) {
  } else {
    int i;
    int j;
    int nz;
    matlab::internal::coder::datatypes::cellstr_sort(
        valueSet_data, valueSet_size, c.data, &c.size[0], idx_data, &idx_size);
    nz = c.size[0] - 1;
    j = c.size[0];
    if (j - 2 >= 0) {
      std::memset(&d_data[0], 0,
                  static_cast<unsigned int>(j - 1) * sizeof(bool));
    }
    i = c.size[0];
    for (int b_i{0}; b_i <= i - 2; b_i++) {
      d_data[b_i] =
          !internal::b_strcmp(c.data[b_i].f1.data, c.data[b_i].f1.size,
                              c.data[b_i + 1].f1.data, c.data[b_i + 1].f1.size);
    }
    b_d_data[0] = true;
    if (nz - 1 >= 0) {
      std::copy(&d_data[0], &d_data[nz], &b_d_data[1]);
    }
    eml_find(b_d_data, c.size[0], dIdx_data, &minSize);
  }
}

} // namespace coder

//
// File trailer for categorical.cpp
//
// [EOF]
//
