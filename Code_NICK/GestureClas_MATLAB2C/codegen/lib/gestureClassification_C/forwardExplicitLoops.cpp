//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: forwardExplicitLoops.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 23-Nov-2022 17:22:04
//

// Include Files
#include "forwardExplicitLoops.h"
#include "omp.h"
#include <algorithm>
#include <cmath>
#include <cstring>

// Function Definitions
//
// Arguments    : const float X[64]
//                const float inputGateWeights[24576]
//                const float inputStateWeights[8192]
//                const float recurrentGateWeights[49152]
//                const float recurrentStateWeights[16384]
//                const float gateBias[384]
//                const float stateBias[128]
//                const float c0[128]
//                const float b_y0[128]
//                float CSout[128]
//                float YTout[128]
// Return Type  : void
//
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
                          float CSout[128], float YTout[128])
{
  float G[512];
  float cellGateOp[128];
  float forgetGateOp[128];
  float ipGateOp[128];
  float outputGateOp[128];
  float f;
  float f1;
  float f2;
  float f3;
  float f4;
  int b_i;
  int p;
  std::memset(&G[0], 0, 512U * sizeof(float));
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    p, f, f1, f2, f3, b_i, f4)

  for (int i = 0; i < 128; i++) {
    f = G[i];
    f1 = G[i + 128];
    f2 = G[i + 256];
    f3 = G[i + 384];
    for (p = 0; p < 64; p++) {
      b_i = i + 384 * p;
      f4 = X[p];
      f += inputGateWeights[b_i] * f4;
      f1 += inputGateWeights[b_i + 128] * f4;
      f2 += inputStateWeights[i + (p << 7)] * f4;
      f3 += inputGateWeights[b_i + 256] * f4;
    }
    for (p = 0; p < 128; p++) {
      b_i = i + 384 * p;
      f4 = b_y0[p];
      f += recurrentGateWeights[b_i] * f4;
      f1 += recurrentGateWeights[b_i + 128] * f4;
      f2 += recurrentStateWeights[i + (p << 7)] * f4;
      f3 += recurrentGateWeights[b_i + 256] * f4;
    }
    G[i] = 1.0F / (std::exp(-(f + gateBias[i])) + 1.0F);
    G[i + 128] = 1.0F / (std::exp(-(f1 + gateBias[i + 128])) + 1.0F);
    G[i + 256] = std::tanh(f2 + stateBias[i]);
    G[i + 384] = 1.0F / (std::exp(-(f3 + gateBias[i + 256])) + 1.0F);
  }
  std::copy(&G[0], &G[128], &ipGateOp[0]);
  std::copy(&G[128], &G[256], &forgetGateOp[0]);
  std::copy(&G[256], &G[384], &cellGateOp[0]);
  std::copy(&G[384], &G[512], &outputGateOp[0]);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(f)

  for (int i = 0; i < 128; i++) {
    f = cellGateOp[i] * ipGateOp[i] + forgetGateOp[i] * c0[i];
    CSout[i] = f;
    YTout[i] = std::tanh(f) * outputGateOp[i];
  }
}

} // namespace lstmUtils
} // namespace rnnUtils
} // namespace layer
} // namespace internal
} // namespace coder

//
// File trailer for forwardExplicitLoops.cpp
//
// [EOF]
//
