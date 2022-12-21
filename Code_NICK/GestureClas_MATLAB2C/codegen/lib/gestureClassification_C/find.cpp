//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: find.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 23-Nov-2022 17:22:04
//

// Include Files
#include "find.h"

// Function Definitions
//
// Arguments    : const bool x_data[]
//                int x_size
//                int i_data[]
//                int *i_size
// Return Type  : void
//
namespace coder {
void eml_find(const bool x_data[], int x_size, int i_data[], int *i_size)
{
  int idx;
  int ii;
  bool exitg1;
  idx = 0;
  *i_size = x_size;
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= x_size - 1)) {
    if (x_data[ii]) {
      idx++;
      i_data[idx - 1] = ii + 1;
      if (idx >= x_size) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }
  if (x_size == 1) {
    if (idx == 0) {
      *i_size = 0;
    }
  } else if (idx < 1) {
    *i_size = 0;
  } else {
    *i_size = idx;
  }
}

} // namespace coder

//
// File trailer for find.cpp
//
// [EOF]
//
