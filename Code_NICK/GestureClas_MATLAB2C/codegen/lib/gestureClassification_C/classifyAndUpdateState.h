//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: classifyAndUpdateState.h
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 23-Nov-2022 17:22:04
//

#ifndef CLASSIFYANDUPDATESTATE_H
#define CLASSIFYANDUPDATESTATE_H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace coder {
namespace internal {
namespace ctarget {
struct DeepLearningNetwork;

}
} // namespace internal
} // namespace coder

// Function Declarations
namespace coder {
namespace internal {
namespace ctarget {
void DeepLearningNetwork_classifyAndUpdateState(DeepLearningNetwork *obj,
                                                const double indata[8],
                                                float scores[3]);

}
} // namespace internal
} // namespace coder

#endif
//
// File trailer for classifyAndUpdateState.h
//
// [EOF]
//
