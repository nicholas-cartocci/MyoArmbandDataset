//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: classifyAndUpdateState.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 23-Nov-2022 17:22:04
//

// Include Files
#include "classifyAndUpdateState.h"
#include "elementwiseOperationInPlace.h"
#include "forwardExplicitLoops.h"
#include "gestureClassification_C_data.h"
#include "gestureClassification_C_internal_types.h"
#include "gestureClassification_C_rtwutil.h"
#include "postProcessOutputToReturnCategorical.h"
#include <algorithm>
#include <cmath>
#include <cstring>

// Type Definitions
struct cell_wrap_23 {
  float f1[64];
};

// Function Definitions
//
// Arguments    : DeepLearningNetwork *obj
//                const double indata[8]
//                float scores[3]
// Return Type  : void
//
namespace coder {
namespace internal {
namespace ctarget {
void DeepLearningNetwork_classifyAndUpdateState(DeepLearningNetwork *obj,
                                                const double indata[8],
                                                float scores[3])
{
  cell_wrap_23 inT;
  cell_wrap_27 r;
  cell_wrap_27 r1;
  cell_wrap_3 outT_f4[3];
  float CS[128];
  float Y[8];
  float layerOutput[3];
  if (!obj->IsNetworkInitialized) {
    std::memset(&obj->NetworkState[0].f1[0].f1[0], 0, 256U * sizeof(float));
    std::memset(&obj->NetworkState[0].f1[1].f1[0], 0, 256U * sizeof(float));
    obj->IsNetworkInitialized = true;
  }
  for (int i{0}; i < 8; i++) {
    Y[i] = static_cast<float>(indata[i]);
  }
  float b_CS[128];
  std::copy(&fv[0], &fv[64], &inT.f1[0]);
  matrixMultiply(64, 8, 64, &fv1[0], &Y[0], &inT.f1[0]);
  layer::elementwiseOperationInPlace(inT.f1);
  layer::rnnUtils::lstmUtils::forwardExplicitLoops(
      inT.f1, fv2, fv3, fv4, fv5, fv6, fv7, &obj->NetworkState[0].f1[0].f1[0],
      &obj->NetworkState[0].f1[1].f1[0], CS, r.f1);
  layer::rnnUtils::lstmUtils::forwardExplicitLoops(
      inT.f1, fv8, fv9, fv10, fv11, fv12, fv13,
      &obj->NetworkState[0].f1[0].f1[128], &obj->NetworkState[0].f1[1].f1[128],
      b_CS, r1.f1);
  std::copy(&r.f1[0], &r.f1[128], &outT_f4[0].f1[0]);
  std::copy(&r1.f1[0], &r1.f1[128], &outT_f4[0].f1[128]);
  for (int i{0}; i < 128; i++) {
    obj->NetworkState[0].f1[0].f1[i] = CS[i];
    obj->NetworkState[0].f1[0].f1[i + 128] = 0.0F;
    obj->NetworkState[0].f1[1].f1[i] = r.f1[i];
    obj->NetworkState[0].f1[1].f1[i + 128] = 0.0F;
  }
  cell_wrap_21 outT_f7;
  float f;
  float maxVal;
  layerOutput[0] = -0.0331666321F;
  layerOutput[1] = -0.312335134F;
  layerOutput[2] = 0.225089759F;
  matrixMultiply(3, 256, 64, &fv14[0], &outT_f4[0].f1[0], &layerOutput[0]);
  maxVal = std::fmax(std::fmax(layerOutput[0], layerOutput[1]), layerOutput[2]);
  layerOutput[0] = std::exp(layerOutput[0] - maxVal);
  layerOutput[1] = std::exp(layerOutput[1] - maxVal);
  layerOutput[2] = std::exp(layerOutput[2] - maxVal);
  maxVal = (layerOutput[0] + layerOutput[1]) + layerOutput[2];
  f = layerOutput[0] / maxVal;
  outT_f7.f1[0] = f;
  scores[0] = f;
  f = layerOutput[1] / maxVal;
  outT_f7.f1[1] = f;
  scores[1] = f;
  f = layerOutput[2] / maxVal;
  outT_f7.f1[2] = f;
  scores[2] = f;
  DeepLearningNetwork_postProcessOutputToReturnCategorical(outT_f7);
}

} // namespace ctarget
} // namespace internal
} // namespace coder

//
// File trailer for classifyAndUpdateState.cpp
//
// [EOF]
//
