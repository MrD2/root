// lib/dll_stl/eh.h

#include <exception>
#ifndef __hpux
using namespace std;
#endif
#ifdef __SUNPRO_CC
#define exception std::exception
#endif

#include <string>
class G__exception : public exception {
  string msg;
  string cname;
 public:
  G__exception() { }
  G__exception(const G__exception& x) { msg=x.msg; cname=x.cname; }
  G__exception(const char* x,const char* cnm="") : msg(x),cname(cnm) { }
  G__exception(const string& x,const string& cnm="") : msg(x),cname(cnm) { }
  G__exception& operator=(const G__exception& x) 
    {msg=x.msg;cname=x.cname;return(*this);}
  virtual const char* what() const throw() { return(msg.c_str()); }
  virtual const char* classname() const throw() { return(cname.c_str()); }
  virtual ~G__exception() throw() { }
};

#ifdef __MAKECINT__
#ifndef G__EXCEPTION_DLL
#define G__EXCEPTION_DLL
#endif

#pragma link C++ global G__EXCEPTION_DLL;
#pragma link C++ class exception;
#pragma link C++ class bad_exception;
#pragma link C++ class G__exception;
#pragma link C++ function set_unexpected;
#pragma link C++ function unexpected;
#pragma link C++ function set_terminate;
#pragma link C++ function terminate;
#pragma link C++ function uncaught_exception;
#pragma link C++ typedef unexpected_handler;
#pragma link C++ typedef terminate_handler;

#endif

