#ifndef ITERATOR_H
#define ITERATOR_H
#include <iostream>
#include "struct.h"
#include "list.h"
#include "iterator.h"
using namespace::std;
class Iterator {
public:
  virtual void first() = 0;
  virtual void next() = 0;
  virtual Term* currentItem() const = 0;
  virtual bool isDone() const = 0;
};

class NullIterator :public Iterator{
public:
  NullIterator(Term *n){}
  void first(){}
  void next(){}
  Term * currentItem() const{
      return nullptr;
  }
  bool isDone() const{
    return true;
  }

};

class StructIterator :public Iterator {
public:
  friend class Struct;
  void first() {
    _index = 0;
  }

  Term* currentItem() const {
    return _s->args(_index);
  }

  bool isDone() const {
    return _index >= _s->arity();
  }

  void next() {
    _index++;
  }
private:
  StructIterator(Struct *s): _index(0), _s(s) {}
  int _index;
  Struct* _s;
};

class ListIterator :public Iterator {
public:
  ListIterator(List *list): _index(0), _list(list) {}

  void first() {
    _index = 0;
  }

  Term* currentItem() const {
    return _list->args(_index);
  }

  bool isDone() const {
    return _index >= _list->arity();
  }

  void next() {
    _index++;
  }
private:
  int _index;
  List* _list;
};
class DFSIterator : public Iterator{
public:
    DFSIterator(Term *term): _index(0), _term(term){}
    void first(){
        _index = 0;
        std::vector<Term*> temp;
        //_terms.push_back(_term);
        Iterator * it = _term->createIterator();
        for(it->first(); it->isDone() == false; it -> next()){
            //cout << it -> currentItem() -> symbol() << endl;
            temp.push_back(it -> currentItem());
        }
        for(int i = 0; i < temp.size(); i++){
            // Iterator * it = temp[i]->createIterator();
            // _terms.push_back(temp[i]);
            // for(it->first(); it->isDone() == false; it -> next()){
            //     //cout << it -> currentItem() -> symbol() << endl;
            //     _terms.push_back(it -> currentItem());
            // }
            DFS(temp[i]);
        }
    }
    void DFS(Term * term){
        Iterator * it = term->createIterator();
        _terms.push_back(term);
        for(it->first(); it->isDone() == false; it -> next()){
            //cout << it -> currentItem() -> symbol() << endl;
            DFS(it -> currentItem());
        }
    }
    Term* currentItem() const {
        return _terms[_index];
    }
    bool isDone()const{
        return _index >= _terms.size();
    }
    void next(){
        _index++;
    }
private:
    int _index;
    Term * _term;
    std::vector<Term*> _terms;
};
class BFSIterator : public Iterator{
public:
    BFSIterator(Term *term): _index(0), _term(term){}
    void first(){
        _index = 0;
        std::vector<Term*> temp;
        //_terms.push_back(_term);
        Iterator * it = _term->createIterator();
        for(it->first(); it->isDone() == false; it -> next()){
            //cout << it -> currentItem() -> symbol() << endl;
            temp.push_back(it -> currentItem());
        }
        for(int i = 0; i < temp.size(); i++){
            _terms.push_back(temp[i]);
        }
        for(int i = 0; i < temp.size(); i++){
            // Iterator * it = temp[i]->createIterator();
            // for(it->first(); it->isDone() == false; it -> next()){
            //     //cout << it -> currentItem() -> symbol() << endl;
            //     _terms.push_back(it -> currentItem());
            // }
            BFS(temp[i]);
        }
    }
    void BFS(Term * term){
        Iterator * it = term->createIterator();
        std::vector<Term*> tmp;
        for(it->first(); it->isDone() == false; it -> next()){
            _terms.push_back(it -> currentItem());
            tmp.push_back(it -> currentItem());
        }
        for(int i = 0; i < tmp.size(); i++){
            BFS(tmp[i]);
        }
    }
    Term* currentItem() const {
        return _terms[_index];
    }
    bool isDone()const{
        return _index >= _terms.size();
    }
    void next(){
        _index++;
    }
private:
    int _index;
    Term * _term;
    std::vector<Term*> _terms;
};
#endif
