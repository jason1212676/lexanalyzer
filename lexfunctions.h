#ifndef LEXFUNCTIONS_H
#define LEXFUNCTIONS_H
#include "string.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int const ALPHA = 1;
int const NUM = 2;
int const OPERATOR = 3;
int const SPACE = 4;
int const DOT = 5;
int const REG = 6;
int const COMMA = 7;
int const FAILED = 9;
int const COMMENT = 0;


vector<string> keywords;
vector<string> separator;
vector<string> operators;

void initKeywords(){

    keywords.push_back("int");
    keywords.push_back("float");
    keywords.push_back("if");
    keywords.push_back("else");
    keywords.push_back("then");
    keywords.push_back("do");
    keywords.push_back("while");
    keywords.push_back("whileend");
    keywords.push_back("do");
    keywords.push_back("doend");
    keywords.push_back("for");
    keywords.push_back("and");
    keywords.push_back("or");
    keywords.push_back("function");
}

void initOperators(){


    operators.push_back("*");
    operators.push_back("+");
    operators.push_back("-");
    operators.push_back("=");
    operators.push_back("/");
    operators.push_back(">");
    operators.push_back("<");
    operators.push_back("%");
}

void initSeparator(){
    separator.push_back("'");
    separator.push_back("(");
    separator.push_back(")");
    separator.push_back("{");
    separator.push_back("}");
    separator.push_back("[");
    separator.push_back("]");
    separator.push_back(",");
    separator.push_back(".");
    separator.push_back(":");
    separator.push_back(";");
    separator.push_back("!");
//    separator.push_back(" ");
//    separator.push_back("sp");
//    separator.push_back("(space)");

}

bool isKeyword(string str){
    bool result = false;
    int size = keywords.size();

    for (int i=0; i< size; i++){
        if (str==keywords.at(i)){
            result = true;
            return result;
        }
    }

    return result;
}

bool isSeparator(string str){
    int size = separator.size();
    bool result = false;

    for (int i=0; i< size; i++){
        if (str==separator.at(i)){
            result = true;
            return result;
        }
    }

    return result;

}

string convertToString(int state, string str){

    if (state==COMMENT){
        return "COMMENT";
    }

    else if (state==NUM || state==ALPHA || state==REG){
        if (isKeyword(str)){
            return "KEYWORD";
        }

        else {
        return "IDENTIFIER";
        }
    }

    else if (state==OPERATOR){
        return "OPEARATOR";
    }

    else if(state==COMMENT){
        return "COMMENT";
    }

    else {
        return "UNKNWON";
    }

}


#endif // LEXFUNCTIONS_H
