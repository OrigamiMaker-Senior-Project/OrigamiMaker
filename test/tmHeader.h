#ifndef _TMHEADER_H_
#define _TMHEADER_H_

#include <QDebug>

/**********
Assertions, debugging, and profiling

We define several macros that are used in debugging and/or profiling that
behave differently under various compile conditions. The macros are:

TMASSERT(cond) where cond is a condition that must always be true
TMLOG(text) where text is a string containing information to go to the
  debugging window or stdout.

The behavior of these macros is different depending on the compiler symbols
TMDEBUG, and TMPROFILE.

You should define no more than one of TMDEBUG, or TMPROFILE.

TMDEBUG     -- define this for debug builds. This enables all assertions within
              TreeMaker code. Assertion failure gets reported to the console.

TMPROFILE   -- define this for profiling builds, which will typically have all
              compiler optimizations, but which may still throw timing info
              to the console.

            -- Don't define any of the two for release builds. No assertions
              will be enabled, and all log messages will be ignored.
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
TMASSERT() macro - used to test conditions that should be true (and about which
subsequent code will make assumptions).
TMFAIL() macro - used when program execution reaches a place that it shouldn't:
For example, a switch() statement that reaches the default state when it
shouldn't. The argument is a string giving the reason for failure. TMFAIL(msg)
is equivalent to TMASSERT(false) but lets us give a reason for the failure.
*****/
#if defined(TMDEBUG)
/* Debug and Development builds test & respond to assertions */
void tmOnAssert(bool cond, const char* file, int line, const char* cond_str, const char* msg = nullptr);
#define TMASSERT(cond) tmOnAssert((cond), __FILE__, __LINE__, #cond)
#define TMFAIL(msg) tmOnAssert(false, __FILE__, __LINE__, "fail", msg)
#else
/* Profile and Release builds compile out assertions */
#define TMASSERT(cond)
#define TMFAIL(msg)
#endif

/*****
TMLOG(str) macro - used to dump textual information to the console.
Only in Debug, Development, and profile builds.
*****/
#ifdef TM_LOG_ENABLED
#define TMLOG(text) qDebug() << text
#else
#define TMLOG(text)
#endif

/**********
typedef tmFloat
Set the floating-point precision used throughout the TreeMaker model.
**********/
typedef double tmFloat;

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
}
#endif
#define TM_CHECK_NAN(x) tmCheckNaN(x)
#else
#define TM_CHECK_NAN(x)
#endif

#endif // _TMHEADER_H_
