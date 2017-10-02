#include "include/Atom.h"
#include "include/Number.h"
#include "include/Variable.h"

Atom::Atom (string s):_symbol(s) {}
bool Atom::operator ==(Atom a) {return _symbol == a._symbol;}
