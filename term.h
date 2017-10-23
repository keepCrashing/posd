#ifndef TERM_H
#define TERM_H
#include <vector>
#include <string>
using std::string;
using std::vector;
class List;
class Term{
public:
    virtual string symbol()const = 0;
    virtual string value(){
        return symbol();
    }
    virtual bool match(Term &term){
        return term.symbol() == symbol();
    }
    virtual List * getList() { return 0; }
};

#endif
