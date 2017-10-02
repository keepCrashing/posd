#ifndef NUMBER_H
#define NUMBER_H
#include <string>
#include <sstream>
#include "Atom.h"
using namespace std;
string numberToString(int d);
class Number{
public:
	Number(int d):_symbol(numberToString(d)),_value(numberToString(d)){}
	string symbol(){return _symbol;}
	string value(){return _value;}
	bool match(Number num){
		return _value == num._value;
	}
	bool match(Atom atom){
		return false;
	}
private:
	string _value;
	string _symbol;
	bool _assignable = true;
};
string numberToString(int d){
	std::stringstream ss;
	string ret;
	ss << d;
	ss >> ret;
	return ret;
}
#endif
