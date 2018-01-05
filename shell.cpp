#include <gtest/gtest.h>
#include <iostream>
//#include "scanner.h"
#include "parser.h"
#include "shell.h"
using std::cout;
using std::endl;
using std::cin;
int main(int argc, char **argv)
{
  string input, context = "", result = "";
  while(true){
    do{
        if(context == ""){
            cout << "?- ";
        }else{
            cout << "|  ";
        }
        getline(cin, input);
        if(input != ""){
        while(input[0] == ' '){
            input = input.substr(1, input.size() - 1);
        }
        context += input;
        }
    }while(input == "" || context.back() != '.');
    if(context == "halt.") break;
    try{
        Scanner s(context);
        Parser p(s);
        p.buildExpression();
        Shell shell(p.getExpressionTree());
        result = shell.exec();
    } catch (std::string & msg) {
        std::cout << msg << std::endl;
    }
    cout << result << endl;
    context = "";
  };
}
