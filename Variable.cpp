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
string Variable::value(){
    if(_isStruct){
        return _struct->value();
    }
    else if(_isList){
        //cout << _list->value();
        return _list->value();
    }
    return _value;
}
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
    List *list = dynamic_cast<List *>(&term);
    bool ret = _assignable;
    if(list){
        for(int i = 0; i < list->elements().size();i++){
            if(this == list->elements()[i]){
                return false;
            }
        }
    }
    if(var){

        for(int i=0; i<_variable.size(); i++){
            if(_variable[i] == var){
                return true;
            }
        }
        if(_assignable)//20171128
        _value = term.value();
        //_variable.push_back(this);
        _variable.push_back(var);
        var->match(*this);
        for(int i=0; i<_variable.size(); i++){
            //_variable[i]->setValue(term.value());
            _variable[i]->match(term);
            //cout <<i<<" "<< _variable[i]->symbol() << " " <<endl;
        }
        return true;
    }
    else{
        if(_assignable || _value == term.value()){
            _value = term.value();
            for(int i=0; i<_variable.size(); i++){
                _variable[i]->setValue(term.value());
                _variable[i]->setAssignable(false);
                //cout << _variable[i]->value() << " ";
            }
            _assignable = false;
            ret = true;
        }
        else{
            ret = false;
        }
    }
    if(stru){
        setAssignable(true);//
        _struct = stru;
        _isStruct = true;
    }
    if(list){
        setAssignable(true);//
        _list = list;
        _isList = true;
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
