#ifndef VARIABLE_H
#define VARIABLE_H
#include <string>
using std::string;
class Atom;
class Number;
class Variable:public Term{
public:
    Variable(string s);
    //Variable(double d);
    string value();
    string symbol()const;
    // bool match( Atom atom );
    // bool match(Number num);
    bool match(Term &term);
    bool getAssignable();
    void setAssignable(bool assignable);
    void setValue(string str);
    string _symbol;
private:
    string _value;
    bool _assignable = true;
};
#endif
