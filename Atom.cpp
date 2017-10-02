#include "Atom.h"
#include "Number.h"
#include "Variable.h"
#include <iostream>
using namespace::std;
Atom::Atom (string s):_symbol(s) {}
bool Atom::operator ==(Atom a) {return _symbol == a._symbol;}
bool Atom::match(Number num){return false;}
bool Atom::match(Var &vari){
    bool ret = vari.getAssignable();
    if(vari.getAssignable()==true || vari.value() == _symbol){
        ret = true;
    }else{
        ret = false;
    }
    return ret;
}
