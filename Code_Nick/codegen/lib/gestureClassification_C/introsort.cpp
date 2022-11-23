//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: introsort.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 23-Nov-2022 17:22:04
//

// Include Files
#include "introsort.h"
#include "anonymous_function.h"
#include "insertionsort.h"

// Function Definitions
//
// Arguments    : int x_data[]
//                int xend
//                const anonymous_function *cmp
// Return Type  : void
//
namespace coder {
namespace internal {
void introsort(int x_data[], int xend, const anonymous_function *cmp)
{
  if (xend > 1) {
    insertionsort(x_data, xend, cmp);
  }
}

} // namespace internal
} // namespace coder

//
// File trailer for introsort.cpp
//
// [EOF]
//
