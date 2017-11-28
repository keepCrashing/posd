#ifndef NODE_H
#define NODE_H

enum Operators {SEMICOLON, COMMA, EQUALITY, TERM};

class Node {
public:
  Node(Operators op):payload(op), term(0), left(0), right(0) {}
  Node(Operators op, Term *t, Node *l, Node *r):payload(op), term(t), left(l), right(r) {}

  bool evaluate(){
      bool ret = false;
      if(payload == SEMICOLON){
          bool isR = right -> evaluate();
          bool isL = left->evaluate();
          ret = isL || isR;
      }else if(payload == COMMA){
          ret = left->evaluate() && right -> evaluate();
      }else if(payload = EQUALITY){
          ret = left->term->match(*(right->term));
      }
      return ret;
  }

  Operators payload;
  Term *term;
  Node *left;
  Node *right;
};

#endif
