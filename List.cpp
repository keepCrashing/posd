#include "list.h"
#include "variable.h"
#include "iterator.h"
List::List (): _elements() {}
List::List (vector<Term *> const & elements):_elements(elements){}
//
string List::symbol() const{
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
}
string List::value() const{
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
}
bool List::match(Term & term){
    //List *pl = term.getList();
    List * pl = dynamic_cast<List *>(&term);
    Variable *pv = dynamic_cast<Variable *>(&term);
    //Variable *pv  = term.getVariable();
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
    else if(pv){
        ret = pv->match(*this);
    }
    else{
        ret = false;
    }
    return ret;
}
//
Term * List::head() const{
    if(_elements.size()==0){
        throw string("Accessing head in an empty list");
    }
    return _elements[0];
}
List * List::tail() const{
    if(_elements.size()==0){
        throw string("Accessing tail in an empty list");
    }
    vector<Term *> v;
    v.assign(_elements.begin()+1, _elements.end());
    List* ret = new List(v);
    return ret;
}
vector<Term *> List::elements(){
    return _elements;
}
Term * List::args(int index) {
  return _elements[index];
}
int List::arity() const {return _elements.size();}
Iterator * List::createIterator(){
    return new ListIterator(this);
}
Iterator * List::createDFSIterator(){
    return new DFSIterator(this);
}
Iterator * List::createBFSIterator(){
    return new BFSIterator(this);
}
