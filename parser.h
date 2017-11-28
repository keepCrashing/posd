#ifndef PARSER_H
#define PARSER_H
#include <string>
using std::string;

#include "atom.h"
#include "variable.h"
#include "global.h"
#include "scanner.h"
#include "struct.h"
#include "list.h"
#include "number.h"
#include "node.h"
#include "iostream"
using namespace::std;

#include "utParser.h"

class Parser{
public:
  Parser(Scanner scanner) : _scanner(scanner), _terms(){}

  Term* createTerm(){
    int token = _scanner.nextToken();
    _currentToken = token;
    if(token == VAR){
      return new Variable(symtable[_scanner.tokenValue()].first);
    }else if(token == NUMBER){
      return new Number(_scanner.tokenValue());
    }else if(token == ATOM || token == ATOMSC){
      Atom* atom = new Atom(symtable[_scanner.tokenValue()].first);
      if(_scanner.currentChar() == '(' ) {
        return structure();
      }
      else
        return atom;
    }
    else if(token == '['){
      return list();
    }

    return nullptr;
  }



  Term * structure() {
    Atom structName = Atom(symtable[_scanner.tokenValue()].first);
    int startIndexOfStructArgs = _terms.size();
    _scanner.nextToken();
    createTerms();
    if(_currentToken == ')')
    {
      vector<Term *> args(_terms.begin() + startIndexOfStructArgs, _terms.end());
      _terms.erase(_terms.begin() + startIndexOfStructArgs, _terms.end());
      return new Struct(structName, args);
    } else {
      throw string("unexpected token");
    }
  }

  Term * list() {
    int startIndexOfListArgs = _terms.size();
    createTerms();
    if(_currentToken == ']')
    {
      vector<Term *> args(_terms.begin() + startIndexOfListArgs, _terms.end());
      _terms.erase(_terms.begin() + startIndexOfListArgs, _terms.end());
      return new List(args);
    } else {
      throw string("unexpected token");
    }
  }

  vector<Term *> & getTerms() {
    return _terms;
  }
  Node* expressionTree(){
      return _expressionTree;
  }
  void getVarInStruct(Struct* s){

      for(int i = 0; i < s->arity(); i++){
          Variable* pv = dynamic_cast<Variable *>(s->args(i));
          Struct* ps = dynamic_cast<Struct *>(s->args(i));
          if(pv){
              _vars.push_back(pv);
          }else if(ps){
              getVarInStruct(ps);
          }
      }
  }
  void matchings(){
      //_expressionTree = createTree();
      Node *top, *right, *left;
      Term* term = createTerm();
      Variable* pv = dynamic_cast<Variable *>(term);
      if(pv){
          for(int i = _terms.size()-1; i >= 0; i--){
              if(_operators[i] == ';')break;
              if(term->symbol() == _terms[i]->symbol()){
                  term->match(*_terms[i]);
              }
              Struct* ps = dynamic_cast<Struct*>(_terms[i]);
              if(ps){
                  for(int j = 0; j < ps->args().size(); j++){
                     if(term -> symbol() == ps->args(j)->symbol()){
                         term->match(*(ps->args(j)));
                     }
                  }
              }
          }
      }
      while((_currentToken = _scanner.nextToken()) == '=' ||
      _currentToken == ',' ||
      _currentToken == ';'){
          if(_currentToken == '='){
              _operators.push_back('=');
              left = new Node(TERM, term, nullptr, nullptr);
              _terms.push_back(term);
              top = new Node(EQUALITY, nullptr, left, nullptr);
              term = createTerm();
              top->right = new Node(TERM, term, nullptr, nullptr);


              _terms.push_back(term);

              _expressionTree = top;

          }else if(_currentToken == ','){
              _operators.push_back(',');
              top = new Node(COMMA, nullptr, nullptr, nullptr);
              top->left = expressionTree();
              matchings();
              top->right = expressionTree();
              _expressionTree = top;

          }else if(_currentToken == ';'){
               _operators.push_back(';');
              top = new Node(SEMICOLON, nullptr, nullptr, nullptr);
              top->left = expressionTree();
              matchings();
              top->right = expressionTree();
              _expressionTree = top;

          }
      }
  }
private:
  FRIEND_TEST(ParserTest, createArgs);
  FRIEND_TEST(ParserTest,ListOfTermsEmpty);
  FRIEND_TEST(ParserTest,listofTermsTwoNumber);
  FRIEND_TEST(ParserTest, createTerm_nestedStruct3);

  void createTerms() {
    Term* term = createTerm();
    if(term!=nullptr)
    {
      _terms.push_back(term);
      while((_currentToken = _scanner.nextToken()) == ',') {
        _terms.push_back(createTerm());
      }
    }
  }
  vector<char> _operators;
  vector<Term *> _terms;
  vector<Term *> _vars;
  Scanner _scanner;
  int _currentToken;
  Node *_expressionTree;
  std::vector<Node *> _nodes;
};
#endif
