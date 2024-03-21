#include "tmHeader.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <cmath>

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
void tmOnAssert(bool cond, const char* file, int line, const char* cond_str, const char* msg)
{
    if (cond) return;
    DumpTreeState();

    // Report the assertion failure
    string message;
    if (msg)
        message = string("Failed assertion in file ") + file + " at line " + to_string(line) + ". Failed condition was:\n  " + cond_str + ": " + msg;
    else
        message = string("Failed assertion in file ") + file + " at line " + to_string(line) + ". Failed condition was:\n  " + cond_str;

    cerr << message << endl;
    abort();
}
#endif // TMDEBUG

/**********
NAN DETECTION FUNCTIONS
**********/

/**********
Check for NaN in debug builds
**********/
#ifdef TMDEBUG
void tmCheckNaN(double x) {
    if (std::isnan(x)) {
        TMLOG("NaN encountered!");
    }
}
#endif // TMDEBUG
