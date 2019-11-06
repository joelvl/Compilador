%{
#include "ast.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

extern "C" int yylex();
extern "C" int yyparse();
extern "C" void yyerror(char *s);
extern "C" int yywrap(void){return 1;}

extern union node yylval;
extern class AST_Node * start;
%}

%token VOID INT DOUBLE BOOL STRING CLASS INTERFACE _NULL THIS EXTENDS IMPLEMENTS FOR WHILE IF ELSE RETURN BREAK NEW NEWARRAY PRINT READINTEGER READLINE _TRUE _FALSE 
%token PLUS MINUS MUL DIV MOD LESS LESSEQUAL GREATER GREATEREQUAL EQUALEQUAL EQUAL NOTEQUAL AND OR NOT 
%token SEMICOLON COMMA DOT SBO SBC BO BC CBO CBC
%token <ival> INT_VALUE 
%token <dval> DOUBLE_VALUE
%token <cval> CHAR_VALUE 
%token <cval> INVALID_CHAR 
%token <sval> STRING_VALUE
%token <sval> INVALID_STRING 
%token <sval> IDENTIFIER 

%union {
    int ival;
    double dval;
    char cval;
    char* sval;
}

%left AND OR NOT
%left PLUS MINUS
%left MUL DIV MOD
%nonassoc GREATER GREATEREQUAL LESS LESSEQUAL NOTEQUAL EQUALEQUAL EQUAL DOT SBO SBC

%%  //TERMINALES MAYUS - NO TERMINALES MINUS

program                 :   decls {}
                        ;

decls                   :   decl {}
                        |   decls decl 
                        ;

decl                    :   variableDecl 
                        |   functionDecl { }
                        |   classDecl { }
                        |   interfaceDecl { }
                        ;

identifiers             :   IDENTIFIER { }
                        |   identifiers IDENTIFIER { }
                        ;

functionDecl            :   type IDENTIFIER BO formals BC stmtBlock { }
                        |   VOID IDENTIFIER BO formals BC stmtBlock { }
                        ;

formals                 :
                        |   COMMA variable { }
                        |   variable formals { }
                        ;

classDecl               :   CLASS IDENTIFIER optExtends optImplements CBO fields CBC { }
                        ;

optExtends              :   EXTENDS IDENTIFIER { }
                        |
                        ;

optImplements           :   IMPLEMENTS identifiers { }
                        |
                        ;

fields                  :
                        |   fields field { }
                        ;

field                   :   variableDecl { }
                        |   functionDecl { }
                        ;

interfaceDecl           :   INTERFACE IDENTIFIER CBO prototype CBC { }
                        ;

prototype               :
                        |   type IDENTIFIER BO formals BC SEMICOLON { }
                        |   VOID IDENTIFIER BO formals BC SEMICOLON { }
                        ;

stmts                   :
                        |   stmt stmts { }
                        |   variableDecl stmts { }
                        ;

stmtBlock               :   CBO stmts CBC { }
                        ;

variableDecl            :   variable SEMICOLON { }
                        ;

variable                :   type IDENTIFIER { }
                        ;

type                    :   INT { }
                        |   DOUBLE { }
                        |   BOOL { }
                        |   STRING { }
                        |   IDENTIFIER { }
                        |   type SBO SBC { }
                        ;

stmt                    :   ifStmt { }
                        |   expression SEMICOLON { }
                        |   whileStmt { }
                        |   forStmt { }
                        |   breakStmt { }
                        |   returnStmt { }
                        |   printStmt { }
                        |   stmtBlock { }
                        ;

ifStmt                  :   IF BO expression BC stmtBlock optElse { }
                        ;

optElse                 :
                        |   ELSE stmtBlock { }
                        ;

whileStmt               :   WHILE BO expression BC stmtBlock { }
                        ;

forStmt                 :   FOR BO expression SEMICOLON expression SEMICOLON expression BC stmtBlock { }
                        ;
                        
returnStmt              :   RETURN expression SEMICOLON { }
                        ;

breakStmt               :   BREAK SEMICOLON { }
                        ;
                        
printStmt               :   PRINT BO expressionList BC SEMICOLON { }
                        ;

expressionList          :   expression { }
                        |   expressionList COMMA expression { }
                        ;


expression              :   expression OR expression { }
                        |   expression AND expression { }
                        |   expression EQUALEQUAL expression { }
                        |   expression NOTEQUAL expression { }
                        |   expression LESS expression { }
                        |   expression LESSEQUAL expression { }
                        |   expression GREATER expression { }
                        |   expression GREATEREQUAL expression { }
                        |   expression PLUS expression { }
                        |   expression MINUS expression { }
                        |   expression MUL expression { }
                        |   expression DIV expression { }
                        |   expression MOD expression { }
                        |   expression EQUAL expression { } 
                        |   NOT expression { }
                        |   MINUS expression { }
                        |   expression SBO expression SBC { }
                        |   expression DOT IDENTIFIER optActualList { }
                        |   IDENTIFIER { }
                        |   constant { }
                        |   READINTEGER BO BC { }
                        |   READLINE BO BC { }
                        |   NEW BO IDENTIFIER BC { }
                        |   NEWARRAY BO expression COMMA type BC { }
                        |   THIS { } 
                        |   BO expression BC { }
                        ;

optActualList           :
                        |   BO actualList BC { }
                        ;

actualList              :   actuals { }
                        |
                        ;

actuals                 :   expression { }
                        |   actuals COMMA expression { }
                        ;

constant                :   INT_VALUE { }
                        |   DOUBLE_VALUE { }
                        |   _TRUE { }
                        |   _FALSE { }
                        |   STRING_VALUE { }
                        |   _NULL { }
                        ;

%%