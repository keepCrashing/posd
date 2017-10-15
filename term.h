#ifndef TERM_H
#define TERM_H
#include <vector>
#include <string>
using std::string;
using std::vector;

class Term{
public:
    virtual string symbol()const = 0;
    virtual string value(){
        return symbol();
    }
    // virtual bool match(Term &term){
    //     return term.symbol() == symbol();
    // }
    virtual bool match(Term &term){
        return term.symbol() == symbol();
    }
    //vector<*Term> t;
};

#endif
