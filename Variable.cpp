#include "atom.h"
#include "number.h"
#include "variable.h"
#include <string>
#include <iostream>
using namespace::std;
using std::string;

Variable::Variable(string s):_symbol(s){}

string Variable::value(){ return _value; }

bool Variable::match( Atom atom ){
    bool ret = _assignable;
    if(_assignable == true || _value == atom._symbol){
        _value = atom._symbol ;
        _assignable = false;
        ret = true;
    }else{
        ret = false;
    }
    return ret;
}

bool Variable::match(Number num){
  bool ret = _assignable;
  if(_assignable || _value == num.value()){
    _value = num.value();
    _assignable = false;
    ret = true;
  }
  else{
    ret = false;
  }
  return ret;
}

bool Variable::getAssignable(){
    return _assignable;
}
void Variable::setAssignable(bool assignable){
    _assignable = assignable;
}
void Variable::setValue(string str){
    _value = str;
}
