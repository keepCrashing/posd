#include "atom.h"
#include "number.h"
#include "variable.h"
#include "struct.h"
#include <string>
#include <iostream>
using namespace::std;
using std::string;

Variable::Variable(string s):_symbol(s),_value(s){}
//vector<Variable*> Variable::_variable;
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
    Struct *stru = dynamic_cast<Struct *>(&term);
    bool ret = _assignable;
    if(var){

        for(int i=0; i<_variable.size(); i++){
            if(_variable[i] == var){
                return true;
            }
        }
        _value = term.value();
        //_variable.push_back(this);
        _variable.push_back(var);
        var->match(*this);
        for(int i=0; i<_variable.size(); i++){
            //_variable[i]->setValue(term.value());
            _variable[i]->match(term);
            //cout <<i<<" "<< _variable[i]->symbol() << " " <<endl;
        }
    }
    else{
        // if(stru){
        //     for(int i=0;i<stru->args().size();i++){
        //         Variable *struVar = dynamic_cast<Variable *>(stru->args(i));
        //         if(struVar){
        //             _variable.push_back(struVar);
        //         }
        //     }
        // }
        for(int i=0; i<_variable.size(); i++){
            _variable[i]->setValue(term.value());
            //cout << _variable[i]->value() << " ";
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
