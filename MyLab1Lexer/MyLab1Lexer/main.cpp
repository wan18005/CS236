#include <iostream>
#include "lexer.h"

using namespace std;


int main(int argc, char* argv[])
{
    string fileName = argv[1];
    lexer fileCheck;
    fileCheck.check(argv[1]);


    return 0;
}