%{
#include <stdio.h>

int yylex();
int yyerror(char *s);

%}

%token VOID INT DOUBLE BOOL STRING CLASS INTERFACE _NULL THIS EXTENDS IMPLEMENTS FOR WHILE IF ELSE RETURN BREAK NEW NEWARRAY PRINT READINTEGER READLINE _TRUE _FALSE 
%token PLUS MINUS MUL DIV MOD LESS LESSEQUAL GREATER GREATEREQUAL EQUALEQUAL EQUAL NOTEQUAL AND OR NOT 
%token SEMICOLON COMMA DOT SBO SBC BO BC CBO CBC
%token <ival> INT_VALUE 
%token <dval> DOUBLE_VALUE
%token <cval> CHAR_VALUE 
%token <sval> STRING_VALUE 
%token <sval> IDENTIFIER 

%union {
    int ival;
    double dval;
    char cval;
    char* sval;
}


%%  //TERMINALES MAYUS - NO TERMINALES MINUS

program                 :   decls 
    {
        printf("OK\n");
    }
                        ;

decls                   :   decl
                        |   decl decls
                        ;

decl                    :   variableDecl 
                        |   functionDecl 
                        |   classDecl 
                        |   interfaceDecl
                        ;

variableDecl            :   variable SEMICOLON
                        ;

variable                :   type IDENTIFIER
                        ;

type                    :   INT 
                        |   DOUBLE 
                        |   BOOL 
                        |   STRING 
                        |   IDENTIFIER
                        |   type SBO SBC //CHECK
                        ;

identifiers             :   IDENTIFIER IDENTIFIER
                        |   IDENTIFIER identifiers
                        ;

functionDecl            :   type IDENTIFIER BO formals BC stmtBlock
                        |   VOID IDENTIFIER BO formals BC stmtBlock
                        ;

formals                 :   variable
                        |   variable COMMA formals
                        ;

classDecl               :   CLASS IDENTIFIER EXTENDS IDENTIFIER IMPLEMENTS identifiers CBO fields CBC
                        |   CLASS IDENTIFIER IMPLEMENTS identifiers CBO fields CBC
                        |   CLASS IDENTIFIER EXTENDS IDENTIFIER CBO fields CBC
                        |   CLASS IDENTIFIER CBO fields CBC
                        ;

fields                  :   //NON
                        |   field fields
                        ;

field                   :   variableDecl 
                        |   functionDecl
                        ;

interfaceDecl           :   INTERFACE IDENTIFIER CBO prototype CBC
                        ;

prototype               :   //NON
                        |   type IDENTIFIER BO formals BC SEMICOLON
                        |   VOID IDENTIFIER BO formals BC SEMICOLON
                        ;

stmtBlock               :   CBO variableDecl stmts CBC
                        ;

stmts                   :  
                        |   stmt stmts
                        ;

stmt                    :   expression SEMICOLON
                        |   ifStmt
                        |   whileStmt
                        |   forStmt
                        |   breakStmt 
                        |   returnStmt 
                        |   printStmt 
                        |   stmtBlock
                        ;

ifStmt                  :   IF BO expression BC stmtBlock
                        |   IF BO expression BC stmtBlock ELSE stmtBlock
                        ;

whileStmt               :   WHILE BO expression BC stmtBlock
                        ;

forStmt                 :   FOR BO expression SEMICOLON expression SEMICOLON expression BC stmtBlock
                        ;
                        
returnStmt              :   RETURN expression SEMICOLON
                        ;

breakStmt               :   BREAK
                        ;
                        
printStmt               :   PRINT BO expressionList BC SEMICOLON
                        ;

expressionList          :   expression
                        |   expressionList COMMA expression
                        ;   

expression              :   lValue EQUAL expression 
                        |   constant 
                        |   lValue 
                        |   THIS 
                        |   call 
                        |   BO expression BC
                        |   expression PLUS expression
                        |   expression MINUS expression
                        |   expression MUL expression
                        |   expression DIV expression
                        |   expression MOD expression
                        |   MINUS expression
                        |   expression LESS expression
                        |   expression LESSEQUAL expression
                        |   expression GREATER expression
                        |   expression GREATEREQUAL expression
                        |   expression EQUALEQUAL expression
                        |   expression NOTEQUAL expression
                        |   expression AND expression
                        |   expression OR expression
                        |   NOT expression
                        |   READINTEGER BO BC
                        |   READLINE BO BC
                        |   NEW BO IDENTIFIER BC
                        |   NEWARRAY BO expression COMMA expression BC
                        ;

lValue                  :   IDENTIFIER 
                        |   expression DOT IDENTIFIER
                        |   expression SBO expression SBC
                        ;

call                    :   IDENTIFIER BO actuals BC
                        |   expression DOT IDENTIFIER BO actualList BC
                        ;

actualList              :   actuals
                        |
                        ;

actuals                 :   expression
                        |   actuals COMMA expression
                        ;

constant                :   INT_VALUE
                        |   DOUBLE_VALUE
                        |   _TRUE
                        |   _FALSE
                        |   STRING_VALUE
                        |   _NULL
                        ;

%%

int yyerror(char *s)
{
	printf("Syntax Error on line %s\n", s);
	return 0;
}