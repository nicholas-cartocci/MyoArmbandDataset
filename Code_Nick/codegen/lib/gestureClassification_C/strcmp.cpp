//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: strcmp.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 23-Nov-2022 17:22:04
//

// Include Files
#include "strcmp.h"

// Function Definitions
//
// Arguments    : const char a_data[]
//                const int a_size[2]
//                const char b_data[]
//                const int b_size[2]
// Return Type  : bool
//
namespace coder {
namespace internal {
bool b_strcmp(const char a_data[], const int a_size[2], const char b_data[],
              const int b_size[2])
{
  bool b;
  bool b_bool;
  b_bool = false;
  b = (a_size[1] == 0);
  if (b && (b_size[1] == 0)) {
    b_bool = true;
  } else if (a_size[1] == b_size[1]) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr <= b_size[1] - 1) {
        if (a_data[kstr] != b_data[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return b_bool;
}

} // namespace internal
} // namespace coder

//
// File trailer for strcmp.cpp
//
// [EOF]
//
