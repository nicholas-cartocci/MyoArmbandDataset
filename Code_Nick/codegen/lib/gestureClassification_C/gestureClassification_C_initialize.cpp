//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: gestureClassification_C_initialize.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 23-Nov-2022 17:22:04
//

// Include Files
#include "gestureClassification_C_initialize.h"
#include "gestureClassification_C.h"
#include "gestureClassification_C_data.h"
#include "omp.h"

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
void gestureClassification_C_initialize()
{
  omp_init_nest_lock(&gestureClassification_C_nestLockGlobal);
  gestureClassification_C_init();
  isInitialized_gestureClassification_C = true;
}

//
// File trailer for gestureClassification_C_initialize.cpp
//
// [EOF]
//
