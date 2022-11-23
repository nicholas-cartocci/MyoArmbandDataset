//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: forwardExplicitLoops.h
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 23-Nov-2022 17:22:04
//

#ifndef FORWARDEXPLICITLOOPS_H
#define FORWARDEXPLICITLOOPS_H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
namespace layer {
namespace rnnUtils {
namespace lstmUtils {
void forwardExplicitLoops(const float X[64],
                          const float inputGateWeights[24576],
                          const float inputStateWeights[8192],
                          const float recurrentGateWeights[49152],
                          const float recurrentStateWeights[16384],
                          const float gateBias[384], const float stateBias[128],
                          const float c0[128], const float b_y0[128],
                          float CSout[128], float YTout[128]);

}
} // namespace rnnUtils
} // namespace layer
} // namespace internal
} // namespace coder

#endif
//
// File trailer for forwardExplicitLoops.h
//
// [EOF]
//
