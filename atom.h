#ifndef ATOM_H
#define ATOM_H
#include "term.h"
#include <string>

using std::string;
class Number;
class Variable;
class Atom:public Term{
public:
    Atom (string s);
    //bool operator ==(Atom a);
    //bool match(Number num);
    //bool match(Variable &vari);
    bool match(Term &term);
    string symbol()const;
    string _symbol;
};

#endif
