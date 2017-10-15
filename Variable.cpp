#include "atom.h"
#include "number.h"
#include "variable.h"

#include <string>
#include <iostream>
using namespace::std;
using std::string;

Variable::Variable(string s):_symbol(s),_value(s){_variable.clear();}
vector<Variable*> Variable::_variable;
//Variable::Variable(double d):_symbol(s){}
void Variable::setVariable(Variable *vari){
    _variable.push_back(vari);
}
string Variable::value(){ return _value; }
string Variable::symbol()const{return _symbol;}
// bool Variable::match( Atom atom ){
//     bool ret = _assignable;
//     if(_assignable == true || _value == atom._symbol){
//         _value = atom._symbol ;
//         _assignable = false;
//         ret = true;
//     }else{
//         ret = false;
//     }
//     return ret;
// }
//
// bool Variable::match(Number num){
//   bool ret = _assignable;
//   if(_assignable || _value == num.value()){
//     _value = num.value();
//     _assignable = false;
//     ret = true;
//   }
//   else{
//     ret = false;
//   }
//   return ret;
// }
bool Variable::match(Term &term){
    Variable *var = dynamic_cast<Variable *>(&term);
    bool ret = _assignable;
    if(var){
        _value = term.value();
        _variable.push_back(this);
        _variable.push_back(var);
    }
    else{
        for(int i=0; i<_variable.size(); i++){
            _variable[i]->setValue(term.value());
            cout << _variable[i]->symbol() << " ";
        }
        if(_assignable || _value == term.value()){
            _value = term.value();
            _assignable = false;
            ret = true;
        }
        else{
            ret = false;
        }
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
