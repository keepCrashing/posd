#include "exp.h"
class Shell {
public:
    Shell(Exp* exp) : _exp(exp) {}
    string exec(){
        string ret = _exp->getResult();
        if(ret == ""){
            ret = "false.";
        }else{
            ret = ret+".";
        }
        return ret;
    }
private:
    Exp* _exp;
};
