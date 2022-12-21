//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: strtrim.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 23-Nov-2022 17:22:04
//

// Include Files
#include "strtrim.h"

// Function Definitions
//
// Arguments    : const char x_data[]
//                const int x_size[2]
//                char y_data[]
//                int y_size[2]
// Return Type  : void
//
namespace coder {
void strtrim(const char x_data[], const int x_size[2], char y_data[],
             int y_size[2])
{
  static const bool bv[128]{
      false, false, false, false, false, false, false, false, false, true,
      true,  true,  true,  true,  false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, true,  true,
      true,  true,  true,  false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false};
  int b_j1;
  int j2;
  b_j1 = 0;
  while ((b_j1 + 1 <= x_size[1]) &&
         bv[static_cast<unsigned char>(x_data[b_j1]) & 127] &&
         (x_data[b_j1] != '\x00')) {
    b_j1++;
  }
  j2 = x_size[1] - 1;
  while ((j2 + 1 > 0) && bv[static_cast<unsigned char>(x_data[j2]) & 127] &&
         (x_data[j2] != '\x00')) {
    j2--;
  }
  if (b_j1 + 1 > j2 + 1) {
    b_j1 = 0;
    j2 = -1;
  }
  y_size[0] = 1;
  j2 -= b_j1;
  y_size[1] = j2 + 1;
  for (int i{0}; i <= j2; i++) {
    y_data[i] = x_data[b_j1 + i];
  }
}

} // namespace coder

//
// File trailer for strtrim.cpp
//
// [EOF]
//
