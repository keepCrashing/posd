#ifndef STRUCT_H
#define STRUCT_H

#include "atom.h"
#include "variable.h"
#include <vector>
#include <string>

using std::string;

class Struct:public Term
{
public:
  Struct(Atom const & name, std::vector<Term *>  args={}):_name(name), _args(args) {
  }
  Struct * getStruct() { return this; }
  int arity(){
      return _args.size();
  }
  Term * args(int index) {
    return _args[index];
  }
  std::vector<Term *> args() {
    return _args;
  }
  Atom const & name() {
    return _name;
  }
  string symbol() const{
      if(_args.size() == 0)return _name.symbol() + "()";
    string ret =_name.symbol() + "(";
    for(int i = 0; i < _args.size() - 1 ; i++){
      ret += _args[i]-> symbol() + ", ";
    }
    ret += _args[_args.size()-1]-> symbol() + ")";
    return  ret;
  }
  string value(){
    string ret =_name.value() + "(";
    for(int i = 0; i < _args.size() - 1 ; i++){
      ret += _args[i]-> value() + ", ";
    }
    ret += _args[_args.size()-1]-> value() + ")";
    return  ret;
  }
  bool match(Term &term){
    Struct * ps = dynamic_cast<Struct *>(&term);
    if (ps){
      if (!_name.match(ps->_name))
        return false;
      if(_args.size()!= ps->_args.size())
        return false;
      for(int i=0;i<_args.size();i++){
        if(_args[i]->symbol() != ps->_args[i]->symbol())
            return false;
      }
      return true;
    }
    return false;
  }
  Iterator<Term*> * createIterator();
  Iterator<Term*> * createDFSIterator();
  Iterator<Term*> * createBFSIterator();
private:
  Atom _name;
  std::vector<Term *> _args;
};

#endif
