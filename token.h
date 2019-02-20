
#include "string.h"
#include <string>
#include <vector>
using namespace std;
#ifndef TOKEN_H
#define TOKEN_H


class token
{
public:
    token();


private:
    int type;
    string content;

};

#endif // TOKEN_H
