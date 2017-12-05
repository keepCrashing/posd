#ifndef ITERATOR_H
#define ITERATOR_H
#include <iostream>
#include "struct.h"
#include "list.h"
#include "iterator.h"
using namespace::std;

template <class T>
class Iterator {
public:
  virtual void first() = 0;
  virtual void next() = 0;
  virtual Term* currentItem() const = 0;
  virtual bool isDone() const = 0;
};
template <class T>
class NullIterator :public Iterator<T>{
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
template <class T>
class StructIterator :public Iterator<T> {
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
template <class T>
class ListIterator :public Iterator<T> {
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
template <class T>
class DFSIterator : public Iterator<T>{
public:
    DFSIterator(Term *term): _index(0), _term(term){}
    void first(){
        _index = 0;
        std::vector<Term*> temp;
        //_terms.push_back(_term);
        Iterator<Term*> * it = _term->createIterator();
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
        Iterator<Term*> * it = term->createIterator();
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
template <class T>
class BFSIterator : public Iterator<T>{
public:
    BFSIterator(Term *term): _index(0), _term(term){}
    void first(){
        _index = 0;
        std::vector<Term*> temp;
        //_terms.push_back(_term);
        Iterator<Term*> * it = _term->createIterator();
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
        Iterator<Term*> * it = term->createIterator();
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
