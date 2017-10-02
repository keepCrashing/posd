#include "include/Atom.h"
#include "include/Number.h"
#include "include/Variable.h"
#include <string>
using std::string;
Variable::Variable(string s):_symbol(s){}

string Variable::value(){ return _value; }

bool Variable::match( Atom atom ){
  bool ret = _assignable;
  if(_assignable){
    _value = atom._symbol ;
    _assignable = false;
  }
  return ret;
}

bool Variable::match(Number num){
  bool ret = _assignable;
  if(_assignable){
    _value = num.symbol();
    _assignable = false;
  }
  return ret;
}
