#include <cstdio>
#include <iostream>

#include "ast.h"
#include "Declaration.h"

extern "C" int yylex();
extern "C" FILE *yyin;
extern "C" int yyparse();

AST_Program *start;
ScopeStack<Declaration> scopes;

bool printTokenTable = true;

int main(const int argc, const char **argv)
{
    if (argc >= 2)
    {
        FILE *infile = fopen(argv[1], "r");
        if (!infile)
        {
            std::cerr << "        Error reading file:" << argv[1] << std::endl;
            return -1;
        }
        yyin = infile;
    }
    
    if (printTokenTable){
        std::cout << " ╔═══════════════════════════════════════════════════════════════════════════════╗\n";
        std::cout << " ║                                  TOKEN TABLE                                  ║\n";
        std::cout << " ╠═══════════════╦═══════════════╦═══════════════════════╦═══════════════════════╣\n";
        std::cout << " ║ Line          ║ Column        ║ Token                 ║ Value                 ║\n";
    }
    yyparse();
    if (start && 1) {
        //start->print(0);
        start->checkSemantic();
        //scopes.printScopes();
    }
    return 0;
}
