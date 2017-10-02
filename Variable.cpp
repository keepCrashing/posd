#include "Atom.h"
#include "Number.h"
#include "Variable.h"
#include <string>
#include <iostream>
using namespace::std;
using std::string;

Var::Var(string s):_symbol(s){}

string Var::value(){ return _value; }

bool Var::match( Atom atom ){
  bool ret = _assignable;
  if(_assignable){
    _value = atom._symbol ;
    _assignable = false;
  }
  return ret;
}

bool Var::match(Number num){
  bool ret = _assignable;
  if(_assignable){
    _value = num.value();
    _assignable = false;
  }
  return ret;
}

bool Var::getAssignable(){
    return _assignable;
}
