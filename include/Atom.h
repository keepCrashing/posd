#ifndef ATOM_H
#define ATOM_H
#include <string>
using std::string;
class Number;
class Variable;
class Atom {
public:
    Atom (string s);
    bool operator ==(Atom a);
    string _symbol;
};

#endif
