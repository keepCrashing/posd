#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include "Atom.h"
#include "Number.h"
using std::string;

class Variable{
public:
  Variable(string s):_symbol(s){}
  string const _symbol;
  string value(){ return _value; }
  bool match( Atom atom ){
    bool ret = _assignable;
    if(_assignable){
      _value = atom._symbol ;
      _assignable = false;
    }
    return ret;
  }
  bool match(Number num){
    bool ret = _assignable;
    if(_assignable){
      _value = num.symbol();
      _assignable = false;
    }
    return ret;
  }

private:
  string _value;
  bool _assignable = true;
};

#endif
