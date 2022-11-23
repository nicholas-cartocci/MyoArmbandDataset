//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: predict.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 23-Nov-2022 17:22:04
//

// Include Files
#include "predict.h"
#include "elementwiseOperationInPlace.h"
#include "forwardExplicitLoops.h"
#include "gestureClassification_C_data.h"
#include "gestureClassification_C_internal_types.h"
#include "gestureClassification_C_rtwutil.h"
#include <algorithm>
#include <cmath>
#include <cstring>

// Function Definitions
//
// Arguments    : DeepLearningNetwork *obj
//                float varargout_1[3]
// Return Type  : void
//
namespace coder {
namespace internal {
namespace ctarget {
void DeepLearningNetwork_predict(DeepLearningNetwork *obj, float varargout_1[3])
{
  cell_wrap_27 r;
  cell_wrap_27 r1;
  float Y[256];
  float layerOutput[64];
  float b_Y[8];
  float b_layerOutput[3];
  if (!obj->IsNetworkInitialized) {
    std::memset(&Y[0], 0, 256U * sizeof(float));
    std::copy(&Y[0], &Y[256], &obj->NetworkState[0].f1[0].f1[0]);
    std::copy(&Y[0], &Y[256], &obj->NetworkState[0].f1[1].f1[0]);
    obj->IsNetworkInitialized = true;
  }
  for (int i{0}; i < 8; i++) {
    b_Y[i] = 0.0F;
  }
  float CS[128];
  float maxVal;
  std::copy(&fv[0], &fv[64], &layerOutput[0]);
  matrixMultiply(64, 8, 64, &fv1[0], &b_Y[0], &layerOutput[0]);
  layer::elementwiseOperationInPlace(layerOutput);
  layer::rnnUtils::lstmUtils::forwardExplicitLoops(
      layerOutput, fv2, fv3, fv4, fv5, fv6, fv7,
      &obj->NetworkState[0].f1[0].f1[0], &obj->NetworkState[0].f1[1].f1[0], CS,
      r.f1);
  layer::rnnUtils::lstmUtils::forwardExplicitLoops(
      layerOutput, fv8, fv9, fv10, fv11, fv12, fv13,
      &obj->NetworkState[0].f1[0].f1[128], &obj->NetworkState[0].f1[1].f1[128],
      CS, r1.f1);
  std::copy(&r.f1[0], &r.f1[128], &Y[0]);
  std::copy(&r1.f1[0], &r1.f1[128], &Y[128]);
  b_layerOutput[0] = -0.0331666321F;
  b_layerOutput[1] = -0.312335134F;
  b_layerOutput[2] = 0.225089759F;
  matrixMultiply(3, 256, 64, &fv14[0], &Y[0], &b_layerOutput[0]);
  maxVal = std::fmax(std::fmax(b_layerOutput[0], b_layerOutput[1]),
                     b_layerOutput[2]);
  b_layerOutput[0] = std::exp(b_layerOutput[0] - maxVal);
  b_layerOutput[1] = std::exp(b_layerOutput[1] - maxVal);
  b_layerOutput[2] = std::exp(b_layerOutput[2] - maxVal);
  maxVal = (b_layerOutput[0] + b_layerOutput[1]) + b_layerOutput[2];
  varargout_1[0] = b_layerOutput[0] / maxVal;
  varargout_1[1] = b_layerOutput[1] / maxVal;
  varargout_1[2] = b_layerOutput[2] / maxVal;
}

} // namespace ctarget
} // namespace internal
} // namespace coder

//
// File trailer for predict.cpp
//
// [EOF]
//
