//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: gestureClassification_C_internal_types.h
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 23-Nov-2022 17:22:04
//

#ifndef GESTURECLASSIFICATION_C_INTERNAL_TYPES_H
#define GESTURECLASSIFICATION_C_INTERNAL_TYPES_H

// Include Files
#include "gestureClassification_C_types.h"
#include "rtwtypes.h"
#include "coder_bounded_array.h"

// Type Definitions
struct cell_wrap_3 {
  float f1[256];
};

struct cell_wrap_21 {
  float f1[3];
};

struct cell_wrap_27 {
  float f1[128];
};

struct cell_wrap_4 {
  cell_wrap_3 f1[2];
};

namespace coder {
namespace internal {
namespace ctarget {
struct DeepLearningNetwork {
  bool matlabCodegenIsDeleted;
  cell_wrap_4 NetworkState[1];
  bool IsNetworkInitialized;
};

} // namespace ctarget
} // namespace internal
} // namespace coder
struct cell_wrap_6 {
  coder::bounded_array<char, 15U, 2U> f1;
};

struct struct_T {
  coder::bounded_array<cell_wrap_6, 3U, 1U> c;
};

#endif
//
// File trailer for gestureClassification_C_internal_types.h
//
// [EOF]
//
