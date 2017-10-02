#ifndef VARIABLE_H
#define VARIABLE_H
class Atom;
class Number;
class Variable{
public:
    Variable(string s);
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