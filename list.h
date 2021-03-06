#ifndef LIST_H
#define LIST_H

#include "term.h"

#include <iostream>
#include <vector>

using std::vector;
class List : public Term {
public:
  string symbol() const;
  string value() ;
  bool match(Term & term);

public:
  List ();
  List (vector<Term *> const & elements);
  Term * head() const;
  List * tail() const;
  vector<Term *> elements();
  Term * args(int index);
  int arity() const;
  Iterator<Term*> * createIterator();
  Iterator<Term*> * createDFSIterator();
  Iterator<Term*> * createBFSIterator();
private:
  vector<Term *> _elements;

};

#endif
