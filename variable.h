#ifndef VARIABLE_H
#define VARIABLE_H
#include <string>
#include <vector>
using std::vector;
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
    void setVariable(Variable *vari);
    string _symbol;
private:
    static vector<Variable*> _variable;
    string _value;
    bool _assignable = true;
    static string temp;
};
#endif
