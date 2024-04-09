/*******************************************************************************
File:         tmHeader.cpp
Project:      TreeMaker 5.x
Purpose:      Defines failed assertion behavior for Development builds
Author:       Robert J. Lang
Modified by:  
Created:      2005-08-24
Copyright:    �2003 Robert J. Lang. All Rights Reserved.
*******************************************************************************/
#include "tmHeader.h"

#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <limits>

using namespace std;

/**********
ASSERTIONS
**********/

#ifdef TMDEBUG
/*****
Global stream that records state for dumping
*****/
stringstream& DbgPreBuildCreasesStringStream()
{
  static stringstream sDbgPreBuildCreasesStringStream;
  return sDbgPreBuildCreasesStringStream;
}

/*****
Global stream that records state for dumping
*****/
stringstream& DbgPreCleanupStringStream()
{
  static stringstream sDbgPreCleanupStringStream;
  return sDbgPreCleanupStringStream;
}

/*****
Dump two tree state stringstreams to crash files.
*****/
void DumpTreeState()
{
  ofstream fout1("pre_build_creases.tmd5");
  fout1 << DbgPreBuildCreasesStringStream().str();
  fout1.close();
  ofstream fout2("pre_cleanup.tmd5");
  fout2 << DbgPreCleanupStringStream().str();
  fout2.close();
}

/*****
Test the assertion condition; if false, report the reason for failure and exit
the program.
*****/
void tmOnAssert(int cond, const TM_UI_CHAR* szFile, int nLine, 
  const TM_UI_CHAR* szCond, const TM_UI_CHAR* szMsg)
{
  if (cond) return;
  DumpTreeState();

  char msg[1024];
  if (szMsg)
    sprintf(msg, "Failed assertion in file %s "
      "at line %d. Failed condition was:\n"
      "  %s: %s", szFile, nLine, szCond, szMsg);
  else
    sprintf(msg, "Failed assertion in file %s "
      "at line %d. Failed condition was:\n"
      "  %s", szFile, nLine, szCond);
  cout << msg << endl;
  abort();
}

#endif // TMDEBUG

#ifdef __MWERKS__
  #pragma mark -
#endif

/**********
LOGGING FUNCTIONS
**********/

/*****
Report a C string to stdout
*****/
#ifdef TM_LOG_ENABLED
  void tmOnLog(const char* c) {
    cout << c << endl;
  };
#endif // TM_LOG_ENABLED

/*****
Report a C++ string to stdout
*****/
#ifdef TM_LOG_ENABLED
  void tmOnLog(const string& s) {
    cout << s << endl;
  };
#endif // TM_LOG_ENABLED

/**********
NAN DETECTION FUNCTIONS
**********/

/**********
Check for NaN in debug builds
**********/
#ifdef TMDEBUG
  void tmCheckNaN(double x) {
    if (isnan(x)) {
//     if (!(x == x)) { // use this if your compiler doesn't have isnan()
      // TBD, generate exception, or break here
      TMLOG("NaN encountered!");
    }
  }
#endif // TMDEBUG