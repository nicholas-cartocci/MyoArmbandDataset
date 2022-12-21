//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: cellstr_sort.h
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 23-Nov-2022 17:22:04
//

#ifndef CELLSTR_SORT_H
#define CELLSTR_SORT_H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
struct cell_wrap_6;

// Function Declarations
namespace coder {
namespace matlab {
namespace internal {
namespace coder {
namespace datatypes {
void cellstr_sort(const cell_wrap_6 c_data[], int c_size,
                  cell_wrap_6 sorted_data[], int *sorted_size, int idx_data[],
                  int *idx_size);

}
} // namespace coder
} // namespace internal
} // namespace matlab
} // namespace coder

#endif
//
// File trailer for cellstr_sort.h
//
// [EOF]
//
