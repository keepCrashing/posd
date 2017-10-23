#ifndef LIST_H
#define LIST_H

#include "term.h"
#include <iostream>
#include <vector>
using std::vector;

class List : public Term {
public:
  string symbol() const{
      string ret = "";
      if(_elements.size() == 0){
          ret = "[]";
      }else{
          ret = "[";
          for(int i = 0; i < _elements.size(); i++){
              ret=ret+_elements[i]->symbol()+", ";
          }
          ret = ret.substr(0,ret.length()-2);
          ret = ret + "]";
      }
      return ret;
  };
  string value() const{
      string ret = "";
      if(_elements.size() == 0){
          ret = "[]";
      }else{
          ret = "[";
          for(int i = 0; i < _elements.size(); i++){
              ret=ret+_elements[i]->value()+", ";
          }
          ret = ret.substr(0,ret.length()-2);
          ret = ret + "]";
      }
      return ret;
  };
  bool match(Term & term){
      //List *pl = term.getList();
      List * pl = dynamic_cast<List *>(&term);
      bool ret = true;
      if(pl){
          if(_elements.size() != pl->elements().size()){
              ret = false;
          }else{
              for(int i = 0; i < _elements.size(); i++){
                  if(_elements[i]->match( *(pl->elements()[i]) )!=true){
                      ret = false;
                  }
              }
          }
      }
      return ret;
  }

public:
  List (): _elements() {}
  List (vector<Term *> const & elements):_elements(elements){}
  Term * head() const{
      if(_elements.size()==0){
          throw string("Accessing head in an empty list");
      }
      return _elements[0];
  };
  List * tail() const{
      if(_elements.size()==0){
          throw string("Accessing head in an empty list");
      }
      vector<Term *> v;
      v.assign(_elements.begin()+1, _elements.end());
      List* ret = new List(v);
      return ret;
  };
  vector<Term *> elements(){
      return _elements;
  }

private:
  vector<Term *> _elements;

};

#endif
