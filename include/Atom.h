#ifndef ATOM_H
#define ATOM_H
#include <string>
using std::string;
class Number;
class Var;
class Atom {
public:
    Atom (string s);
    bool operator ==(Atom a);
    bool match(Number num);
    bool match(Variable &vari);
    string _symbol;
};

#endif
