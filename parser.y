%{
#include <stdio.h>

int yylex();
int yyerror(char *s);

%}

%token VOID INT DOUBLE BOOL STRING CLASS INTERFACE _NULL THIS EXTENDS IMPLEMENTS FOR WHILE IF ELSE RETURN BREAK NEW NEWARRAY PRINT READINTEGER READLINE _TRUE _FALSE 
%token <ival> INT_VALUE 
%token <dval> DOUBLE_VALUE
%token <cval> CHAR_VALUE 
%token <sval> STRING_VALUE 
%token <sval> IDENTIFIER 
%token PLUS MINUS MUL DIV MOD LESS LESSEQUAL GREATER GREATEREQUAL EQUALEQUAL EQUAL NOTEQUAL AND OR NOT 
%token SEMICOLON COMMA DOT SBO SBC BO BC CBO CBC

%union {
    int ival;
    double dval;
    char cval;
    char* sval;
}


%%

program :   stmts {
                printf("Program\n");
            };

stmts   :   PLUS {
                printf("Program\n");
            }
            | PLUS stmts;


%%

int yyerror(char *s)
{
	printf("Syntax Error on line %s\n", s);
	return 0;
}