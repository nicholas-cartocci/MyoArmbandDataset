//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: insertionsort.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 23-Nov-2022 17:22:04
//

// Include Files
#include "insertionsort.h"
#include "anonymous_function.h"
#include "gestureClassification_C_internal_types.h"
#include "coder_bounded_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : int x_data[]
//                int xend
//                const anonymous_function *cmp
// Return Type  : void
//
namespace coder {
namespace internal {
void insertionsort(int x_data[], int xend, const anonymous_function *cmp)
{
  for (int k{2}; k <= xend; k++) {
    int idx;
    int xc;
    bool exitg1;
    xc = x_data[k - 1] - 1;
    idx = k - 2;
    exitg1 = false;
    while ((!exitg1) && (idx + 1 >= 1)) {
      int b_k;
      int j;
      int n;
      bool varargout_1;
      j = x_data[idx];
      n = static_cast<int>(
          std::fmin(static_cast<double>(cmp->workspace.c.data[xc].f1.size[1]),
                    static_cast<double>(
                        cmp->workspace.c.data[x_data[idx] - 1].f1.size[1])));
      varargout_1 = (cmp->workspace.c.data[xc].f1.size[1] <
                     cmp->workspace.c.data[x_data[idx] - 1].f1.size[1]);
      b_k = 0;
      int exitg2;
      do {
        exitg2 = 0;
        if (b_k <= n - 1) {
          if (cmp->workspace.c.data[xc].f1.data[b_k] !=
              cmp->workspace.c.data[x_data[idx] - 1].f1.data[b_k]) {
            varargout_1 = (cmp->workspace.c.data[xc].f1.data[b_k] <
                           cmp->workspace.c.data[x_data[idx] - 1].f1.data[b_k]);
            exitg2 = 1;
          } else {
            b_k++;
          }
        } else {
          if (cmp->workspace.c.data[xc].f1.size[1] ==
              cmp->workspace.c.data[j - 1].f1.size[1]) {
            varargout_1 = (xc + 1 < j);
          }
          exitg2 = 1;
        }
      } while (exitg2 == 0);
      if (varargout_1) {
        x_data[idx + 1] = x_data[idx];
        idx--;
      } else {
        exitg1 = true;
      }
    }
    x_data[idx + 1] = xc + 1;
  }
}

} // namespace internal
} // namespace coder

//
// File trailer for insertionsort.cpp
//
// [EOF]
//
