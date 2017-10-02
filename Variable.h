#ifndef VARIABLE_H
#define VARIABLE_H
#include <string>
using std::string;
class Atom;
class Number;
class Var{
public:
    Var(string s);
    string value();
    bool match( Atom atom );
    bool match(Number num);
    bool getAssignable();
private:
    string _symbol;
    string _value;
    bool _assignable = true;
};

#endif
