//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: elementwiseOperationInPlace.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 23-Nov-2022 17:22:04
//

// Include Files
#include "elementwiseOperationInPlace.h"
#include "omp.h"
#include <cmath>

// Function Definitions
//
// Arguments    : float X[64]
// Return Type  : void
//
namespace coder {
namespace internal {
namespace layer {
void elementwiseOperationInPlace(float X[64])
{
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int iElem = 0; iElem < 64; iElem++) {
    X[iElem] = std::fmax(0.0F, X[iElem]);
  }
}

} // namespace layer
} // namespace internal
} // namespace coder

//
// File trailer for elementwiseOperationInPlace.cpp
//
// [EOF]
//
