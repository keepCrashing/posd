#include "atom.h"
#include "number.h"
#include "variable.h"
#include <string>
#include <sstream>
using namespace std;
string numberToString(double d){
	std::stringstream ss;
	string ret;
	ss << d;
	ss >> ret;
	return ret;
}
Number::Number(double d):_symbol(numberToString(d)),_value(numberToString(d)){}
string Number::symbol()const{return _symbol;}
// bool Number::match(Term &trem){
//     bool ret = trem.getAssignable();
//     if(trem.getAssignable()==true || trem.value() == _value){
//         trem.setValue(_value);
//         ret = true;
//     }else{
//         ret = false;
//     }
//     return ret;
// }
//string Number::value(){return _value;}
// bool Number::match(Number num){
//     return _value == num._value;
// }
// bool Number::match(Atom atom){
//     return false;
// }
// bool Number::match(Variable &vari){
//     bool ret = vari.getAssignable();
//     if(vari.getAssignable()==true || vari.value() == _value){
//         vari.setValue(_value);
//         ret = true;
//     }else{
//         ret = false;
//     }
//     return ret;
// }
