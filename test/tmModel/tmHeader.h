/*******************************************************************************
File:         tmHeader.h
Project:      TreeMaker 5.x
Purpose:      Common header file for all TreeMaker source code
Author:       Robert J. Lang
Modified by:  
Created:      2003-11-15
Copyright:    �2003 Robert J. Lang. All Rights Reserved.
*******************************************************************************/

#ifndef _TMHEADER_H_
#define _TMHEADER_H_

/*
Every TreeMaker source file includes this in its header tree. This file can be
precompiled. (Since it can be included from both C and C++ files, it is
standard C.) Note the symbols below that may be predefined in compilation:
TMDEBUG
TMPROFILE

You may also use the following macros:
TMASSERT(cond) -- to perform assertion tests.
TMLOG(text) -- to send information to a log window or standard output.

See discussion below for more details.
*/

/**********
Assertions, debugging, and profiling

We define several macros that are used in debugging and/or profiling that
behave differently under various compile conditions. The macros are:

TMASSERT(cond) where cond is a condition that must always be true
TMLOG(text) where text is a string containing information to go to the
  debugging window or stdout.

The behavior of these macros is different depending on the compiler symbols
TMDEBUG and TMPROFILE.

You should #define no more than one of TMDEBUG or TMPROFILE.

TMDEBUG     -- define this for debug builds that don't include wxWidgets and
              for Development builds given to clients for user testing. This
              enables all assertions within TreeMaker code. Assertion failure
              gets reported to stdout.
              
TMPROFILE   -- define this for profiling builds, which will typically have all
              compiler optimizations, but which may still throw timing info
              to stdout.
              
            -- Don't define any of these for release builds. No
              assertions will be enabled and all log messages will be ignored.
**********/

/*****
TM_LOG_ENABLED is defined if we accept log messages. If it doesn't exist, then
TMLOG() macro evaluates to nothing. Everything but release builds accept log
messages.
*****/
#ifdef TMDEBUG
  #define TM_LOG_ENABLED
#endif
#ifdef TMPROFILE
  #define TM_LOG_ENABLED
#endif

/*****
TM_UI_CHAR is the character type used for the user interface. Use ordinary C char.
*****/
#define TM_UI_CHAR char
#define TM_UI_T(cstr) cstr
#define __TM_FILE__ __FILE__

/*****
TMASSERT() macro - used to test conditions that should be true (and about which
subsequent code will make assumptions).
TMFAIL() macro - used when program execution reaches a place that it shouldn't:
For example, a switch() statement that reaches the default state when it
shouldn't. The argument is a string giving the reason for failure. TMFAIL(msg)
is equivalent to TMASSERT(false) but lets us give a reason for the failure.
*****/
#ifdef __cplusplus
  #if defined (TMDEBUG)
    /* Debug and Development builds test & respond to assertions */
    void tmOnAssert(int cond, const TM_UI_CHAR* szFile, int nLine, 
      const TM_UI_CHAR* szCond, const TM_UI_CHAR* szMsg = 0);
    #define TMASSERT(cond) \
      tmOnAssert(!!(cond), __TM_FILE__, __LINE__, TM_UI_T(#cond))
    #define TMFAIL(msg) \
      tmOnAssert(0, __TM_FILE__, __LINE__, TM_UI_T("fail"), TM_UI_T(msg))
  #else
    /* Profile and Release builds compile out assertions */
    #define TMASSERT(cond)
    #define TMFAIL(msg)
  #endif /* defined (TMDEBUG) */
#endif /* __cplusplus */

/*****
TMLOG(str) macro - used to dump textual information to the console.
Only in Debug, Development, and profile builds.
*****/
#ifdef TM_LOG_ENABLED
  #define TMLOG(text) tmOnLog(text)
  void tmOnLog(const char* c);
  #ifdef __cplusplus
    #include <string>
    void tmOnLog(const std::string& s);
  #endif /* __cplusplus */
#else
  #define TMLOG(text)
#endif /* TM_LOG_ENABLED */

/**********
typedef tmFloat
Set the floating-point precision used throughout the TreeMaker model.
**********/
#ifdef __DMC__
  /* STL of DMC has math functions for 'float' or 'long double', so we need one
  of them to avoid "ambiguous reference to symbol" errors in math functions */
  typedef float tmFloat;
#else
  typedef double tmFloat;
#endif

/**********
TM_CHECK_NAN(x)
Checks for NaN in debugging builds in numbers and (in C++) std::vector<T>
**********/
#ifdef TMDEBUG
  void tmCheckNaN(double x);
  #ifdef __cplusplus
    #include <vector>
    template <class T>
      void tmCheckNaN(const std::vector<T>& v) {
        for (size_t i = 0; i < v.size(); ++i)
          tmCheckNaN(v[i]);
      };
  #endif /* __cplusplus */
  #define TM_CHECK_NAN(x) tmCheckNaN(x)
#else
  #define TM_CHECK_NAN(x)
#endif /* TMDEBUG */

#endif /* _TMHEADER_H_ */