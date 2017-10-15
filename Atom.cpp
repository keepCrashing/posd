#include "atom.h"
#include "number.h"
#include "variable.h"
#include "term.h"
#include <iostream>
using namespace::std;
Atom::Atom (string s):_symbol(s) {}
bool Atom::match(Term &term){
    Variable *var = dynamic_cast<Variable *>(&term);
    if(var){
        bool ret = var->getAssignable();
        if(var->getAssignable()==true || var->value() == _symbol){
            var->setValue(_symbol);
            var->setAssignable(false);
            ret = true;
        }else{
            ret = false;
        }
        return ret;
    }else{
        return term.symbol() == symbol();
    }
}
string Atom::symbol() const{
  return _symbol;
}
//bool Atom::operator ==(Atom a) {return _symbol == a._symbol;}
// bool Atom::match(Number num){return false;}
// bool Atom::match(Variable &vari){
//     bool ret = vari.getAssignable();
//     if(vari.getAssignable()==true || vari.value() == _symbol){
//         vari.setValue(_symbol);
//         vari.setAssignable(false);
//         ret = true;
//     }else{
//         ret = false;
//     }
//     return ret;
// }
