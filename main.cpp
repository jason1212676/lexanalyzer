#include <iostream>
#include "token.h"
#include <iomanip>
#include "lexfunctions.h"
#include <iomanip>

//comment
using namespace std;
void initArray();
void markEntry(int x, int y, int mark);
void printTable();
void stateMachine(string str);

int const ROWLENGTH = 10;
int const COLUMNLENGTH = 10;
int stateFunctionTable [ROWLENGTH][COLUMNLENGTH];

bool debug = false;

int main()
{
    initArray();
    printTable();

    //    string str = "! Find largest value between two numbers! int num1, num2, large$ if(num1 > num2) { large = num1$; } else { large = num2$; }";
    string str = "int ab231 cd$ a";
    stateMachine(str);

    return 0;
}

void markEntry(int x, int y, int mark){
    stateFunctionTable[x][y] = mark;
}

int getType (char c);

void initArray(){


    for (int i=0; i< ROWLENGTH; i++){
        for (int j=0; j< COLUMNLENGTH; j++){
            markEntry(i,j,FAILED);
        }
    }

    markEntry(0,ALPHA, ALPHA);
    markEntry(ALPHA,NUM,NUM);
    markEntry(0,NUM, NUM);
    markEntry(0,OPERATOR, OPERATOR);
    markEntry(0, SPACE, SPACE);
    markEntry(0,COMMENT, COMMENT);
    markEntry(0,REG, REG);
    markEntry(ALPHA,REG,REG);
    markEntry(NUM,REG,REG);


    markEntry(ALPHA,ALPHA,ALPHA);
    markEntry(NUM, NUM, NUM);
    markEntry(OPERATOR, OPERATOR, OPERATOR);
    markEntry(SPACE, SPACE, SPACE);
    markEntry(REG,REG, REG);


    initKeywords();
    initSeparator();
    initOperators();

}

void printTable(){
    for (int i=0; i< ROWLENGTH; i++){
        for (int j=0; j< COLUMNLENGTH; j++){
            cout << setw(5) << stateFunctionTable[i][j];
        }
        cout << endl;
    }
}

int getType (char c){
    if (c=='!'){
        return COMMENT;
    }

    if (c >= 'a' && c <=  'z'){
        return ALPHA;
    }

    if (c >= 'A' && c <=  'Z'){
        return ALPHA;
    }

    if (c >= '0' && c <=  '9'){
        return NUM;
    }

    if (c >= '%' && c <=  '/'){
        return OPERATOR;
    }

    if (c >= '<' && c <=  '>'){
        return OPERATOR;
    }

    if (c == ' '){
        return SPACE;
    }

    if (c =='$'){
        return REG;
    }

    else{
        return 0;
    }

}

void stateMachine(string str){
    int size = str.size();
    int state = 0;

    string result = "";

    for (int i=0; i< size; i++){
        char c = str.at(i);
//        bool seperator = isSeparator(string(1,c));

        if (c=='!'){
            c = str.at(++i);

            while(c !='!'){
                result+=c;
                c = str.at(++i);
            }
        }

        else if (c ==' ' || c== '\n'){

            if (state!= FAILED){

                cout  <<"STATE: " << convertToString(state, result) << "\t" << result << endl;
            }

            else {
                cout << "failed state\n";
            }
            state = 0;
            result.clear();
        }

        else {
            int conversion = getType(c);

            state = stateFunctionTable[state][conversion];
            if (debug)
                cout << "type\t" << conversion << "\t" << c << "\t" << "state: " << state << endl;
            result+=c;
        }
    }


    //to check last token
    if (state!= FAILED){
        cout << "STATE: " << convertToString(state, result) << "\t" << result << endl;
    }
    else {
        cout << "failed state\n";
    }

}

