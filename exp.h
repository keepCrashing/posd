#ifndef EXP_H
#define EXP_H

#include "term.h"
#include "global.h"
class Exp {
public:
  virtual bool evaluate() = 0;
  virtual string getResult() = 0;

};


class MatchExp : public Exp {//=
public:
  MatchExp(Term* left, Term* right): _left(left), _right(right){

  }

  bool evaluate(){
      //
      for(int i = 0; i < globalTerms.size(); i++){
          if(_left->symbol() == globalTerms[i]->symbol()){
              _left->match(*globalTerms[i]);
              //_left = globalTerms[i];
              //std::cout << globalTerms[i]->symbol() << " " << globalTerms[i]->value() << std::endl;

          }
      }

      for(int i = 0; i < globalTerms.size(); i++){
          List* pl = dynamic_cast<List*>(globalTerms[i]);
          if(pl){
              for(int j = 0; j < pl->elements().size(); j++){

                 if(_left -> symbol() == pl->args(j)->symbol()){
                     _left->match(*(pl->args(j)));
                     //pl->args(j)->match(*_left);
                     //std::cout << _left->symbol()<<" "<<_left->value()<<" "<< _right->symbol()<<" "<< _right->value() << std::endl;
                 }
              }
          }
          Struct* ps = dynamic_cast<Struct*>(globalTerms[i]);
          if(ps){

              for(int j = 0; j < ps->args().size(); j++){

                 if(_left -> symbol() == ps->args(j)->symbol()){
                     //std::cout << _left->value()<<" "<< ps->args(j)->value() << std::endl;
                     _left->match(*(ps->args(j)));
                     //ps->args(j)->match(_left);
                     //std::cout << _left->value()<<" "<< ps->args(j)->value() << std::endl;
                     //std::cout << _left->symbol()<<" "<<_left->value()<<" "<< _right->symbol()<<" "<< _right->value() << std::endl;
                 }
              }
          }

      }

      globalTerms.push_back(_left);
      globalTerms.push_back(_right);
      Variable* pv = dynamic_cast<Variable*>(_left);
      // if(pv){
      //     if(pv->getAssignable() == false)
      //       return true;
      // }
      //std::cout << _left->symbol()<<" "<<_left->value()<<" "<< _right->symbol()<<" "<< _right->value() << std::endl;
      //bool ret = _left->match(*_right);
      return _left->match(*_right);
  }
  string getResult()
  {
      if(evaluate() == true){
          if(_left->symbol() == _right->symbol()){
              return "true";
          }else{
              return _left->symbol() + " = " + _right->value();
          }
      }else{
          return "";
      }
      // evaluate();
      // string ret = "";
      // if(_left->symbol() == _right->symbol()){
      //     ret = "true";
      // }
      // else if(_left->match(*_right) == false || _left->symbol() == ""){
      //     ret = "";
      // }
      // else{
      //     _left->match(*_right);
      //   ret = _left->symbol() + " = " + _right->value();
      // }
      //
      // return ret;
  }
private:
  Term* _left;
  Term* _right;
};

class ConjExp : public Exp {//,
public:
  ConjExp(Exp *left, Exp *right) : _left(left), _right(right) {

  }

  bool evaluate() {
    return (_left->evaluate() && _right->evaluate());
  }
  string getResult()
  {

      if(evaluate() == true){
          string tmpL =  _left->getResult(), tmpR = _right->getResult();
          if (tmpL == "true" && tmpR == "true"){
              return "true";
          }
          else if(tmpL == tmpR){
              return tmpL;
          }else if(tmpL == "" ){
              //std::cout<<"QQQQQQQQQQQQQQQ"<<std::endl;
              return "";
          }else if(tmpR == ""){
              return "";
          }
          else if(tmpL == "true"){
              return tmpR;
          }
          else if(tmpR == "true"){
              return tmpL;
          }
          return tmpL+", "+ tmpR;
      }else{
          return "";
      }
      // if(evaluate() == true){
      //     if (_left->getResult() == "true" && _right->getResult() == "true"){
      //         return "true";
      //     }
      //     else if(_left->getResult() == _right->getResult()){
      //         return _left->getResult();
      //     }else if(_left->getResult() == "" ){
      //         //std::cout<<"QQQQQQQQQQQQQQQ"<<std::endl;
      //         return "";
      //     }else if(_right->getResult() == ""){
      //         return "";
      //     }
      //     else if(_left->getResult() == "true"){
      //         return _right->getResult();
      //     }
      //     else if(_right->getResult() == "true"){
      //         return _left->getResult();
      //     }
      //     return _left->getResult()+", "+ _right->getResult();
      // }else{
      //     return "";
      // }
  }
private:
  Exp * _left;
  Exp * _right;
};

class DisjExp : public Exp {//;
public:
  DisjExp(Exp *left, Exp *right) : _left(left), _right(right) {

  }

  bool evaluate() {
    return (_left->evaluate() || _right->evaluate());
  }
  std::string getResult()
  {
      // if (evaluate()){
      //     if (_left->getResult() == "false"){
      //         return _right->getResult();
      //     }
      //     else if (_right->getResult() == "false"){
      //         return _left->getResult();
      //     }else{
      //         return _left->getResult() + "; "+  _right->getResult();
      //     }
      // }else{
      //     return "false";
      // }
      string tmpL =  _left->getResult(), tmpR = _right->getResult();
      string semicolon = "; ";
      if( tmpL == ""){
          semicolon ="";
          tmpL == "";
      }
      if( tmpR == ""){
          semicolon ="";
          tmpR == "";
      }
      return tmpL +semicolon+ tmpR;
  }
private:
  Exp * _left;
  Exp * _right;
};
#endif
