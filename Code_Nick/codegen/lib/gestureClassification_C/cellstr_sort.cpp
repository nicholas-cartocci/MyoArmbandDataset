//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: cellstr_sort.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 23-Nov-2022 17:22:04
//

// Include Files
#include "cellstr_sort.h"
#include "anonymous_function.h"
#include "gestureClassification_C_internal_types.h"
#include "introsort.h"
#include "coder_bounded_array.h"

// Function Definitions
//
// Arguments    : const cell_wrap_6 c_data[]
//                int c_size
//                cell_wrap_6 sorted_data[]
//                int *sorted_size
//                int idx_data[]
//                int *idx_size
// Return Type  : void
//
namespace coder {
namespace matlab {
namespace internal {
namespace coder {
namespace datatypes {
void cellstr_sort(const cell_wrap_6 c_data[], int c_size,
                  cell_wrap_6 sorted_data[], int *sorted_size, int idx_data[],
                  int *idx_size)
{
  anonymous_function b_this;
  int n_tmp;
  int yk;
  short y_data[3];
  n_tmp = static_cast<unsigned char>(c_size - 1) + 1;
  y_data[0] = 1;
  yk = 1;
  for (int k{2}; k <= n_tmp; k++) {
    yk++;
    y_data[k - 1] = static_cast<short>(yk);
  }
  b_this.workspace.c.size[0] = c_size;
  for (int k{0}; k < c_size; k++) {
    b_this.workspace.c.data[k] = c_data[k];
  }
  *idx_size = static_cast<unsigned char>(c_size - 1) + 1;
  for (int k{0}; k < n_tmp; k++) {
    idx_data[k] = y_data[k];
  }
  ::coder::internal::introsort(idx_data, c_size, &b_this);
  *sorted_size = c_size;
  for (n_tmp = 0; n_tmp < c_size; n_tmp++) {
    sorted_data[n_tmp].f1.size[0] = 1;
    sorted_data[n_tmp].f1.size[1] = c_data[idx_data[n_tmp] - 1].f1.size[1];
    yk = c_data[idx_data[n_tmp] - 1].f1.size[1];
    for (int k{0}; k < yk; k++) {
      sorted_data[n_tmp].f1.data[k] = c_data[idx_data[n_tmp] - 1].f1.data[k];
    }
  }
}

} // namespace datatypes
} // namespace coder
} // namespace internal
} // namespace matlab
} // namespace coder

//
// File trailer for cellstr_sort.cpp
//
// [EOF]
//
