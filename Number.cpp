#include "Atom.h"
#include "Number.h"
#include "Variable.h"
#include <string>
#include <sstream>
//#include "Atom.h"
using namespace std;
// string numberToString(int d){
// 	std::stringstream ss;
// 	string ret;
// 	ss << d;
// 	ss >> ret;
// 	return ret;
// }
Number::Number(int d):_symbol(to_string(d)),_value(to_string(d)){}
string Number::symbol(){return _symbol;}
string Number::value(){return _value;}
bool Number::match(Number num){
    return _value == num._value;
}
bool Number::match(Atom atom){
    return false;
}
bool Number::match(Var &vari){
    bool ret = vari.getAssignable();
    if(vari.getAssignable()==true || vari.value() == _value){
        ret = true;
    }else{
        ret = false;
    }
    return ret;
}
