#include <cstdio>
#include <iostream>

#include "ast.h"


extern "C" int yylex();
extern "C" FILE *yyin;
extern "C" int yyparse();

AST_Program * start;

int main (const int argc, const char ** argv) {
    if (argc < 2) {
        yyin = NULL;
        std::cerr <<"fatal error: no input files" << std::endl;
        return -1;
    } else {
        FILE * infile = fopen(argv[1], "r");
        if (!infile) {
            std::cerr <<"Error reading file " << argv[1] << std::endl;
            return -1;
        }
        yyin = infile;
    }
    std::cout << "        -------------------------------------------------------------------------\n";
    std::cout << "\t| Line\t\t| Column\t| Token\t\t\t| Value\t\t|\n";
    std::cout << "        -------------------------------------------------------------------------\n";
    
    int type;
    do {
        type = yylex();
    } while (type != 0);
    return 0;
}
