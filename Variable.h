#ifndef VARIABLE_H
#define VARIABLE_H
#include <string>
using std::string;
class Atom;
class Number;
class Variable{
public:
    Variable(string s);
    string value();
    bool match( Atom atom );
    bool match(Number num);
    bool getAssignable();
    void setAssignable(bool assignable);
    void setValue(string str);
private:
    string _symbol;
    string _value;
    bool _assignable = true;
};

#endif
