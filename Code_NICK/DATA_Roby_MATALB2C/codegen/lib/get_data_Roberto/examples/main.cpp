//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: main.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:23:51
//

/*************************************************************************/
/* This automatically generated example C++ main file shows how to call  */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

// Include Files
#include "main.h"
#include "get_data_Roberto.h"
#include "get_data_Roberto_terminate.h"
#include "get_data_Roberto_types.h"

// Function Definitions
//
// Arguments    : int argc
//                char **argv
// Return Type  : int
//
int main(int, char **)
{
  // The initialize function is being called automatically from your entry-point
  // function. So, a call to initialize is not included here. Invoke the
  // entry-point functions.
  // You can call entry-point functions multiple times.
  main_get_data_Roberto();
  // Terminate the application.
  // You do not need to do this more than one time.
  get_data_Roberto_terminate();
  return 0;
}

//
// Arguments    : void
// Return Type  : void
//
void main_get_data_Roberto()
{
  static struct0_T DATA_Neutral_Raw;
  static struct10_T DATA_MVCFlex_Proc;
  static struct11_T DATA_MVCExt_Proc;
  static struct2_T DATA_Extension_Raw;
  static struct3_T DATA_Dynamic_Raw;
  static struct4_T DATA_MVCFlex_Raw;
  static struct5_T DATA_MVCExt_Raw;
  static struct6_T DATA_Neutral_Proc;
  static struct8_T DATA_Extension_Proc;
  static struct9_T DATA_Dynamic_Proc;
  struct1_T DATA_Flexion_Raw;
  struct7_T DATA_Flexion_Proc;
  // Call the entry-point 'get_data_Roberto'.
  get_data_Roberto(&DATA_Neutral_Raw, &DATA_Flexion_Raw, &DATA_Extension_Raw,
                   &DATA_Dynamic_Raw, &DATA_MVCFlex_Raw, &DATA_MVCExt_Raw,
                   &DATA_Neutral_Proc, &DATA_Flexion_Proc, &DATA_Extension_Proc,
                   &DATA_Dynamic_Proc, &DATA_MVCFlex_Proc, &DATA_MVCExt_Proc);
}

//
// File trailer for main.cpp
//
// [EOF]
//
