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
%nonassoc GREATER GREATEREQUAL LESS LESSEQUAL NOTEQUAL EQUALEQUAL

%%  //TERMINALES MAYUS - NO TERMINALES MINUS

program                 :   decls 
    {
        printf("OK\n");
    }
                        ;

decls                   :   decl
                        |   decls decl
                        ;

decl                    :   variableDecl 
                        |   functionDecl 
                        |   classDecl 
                        |   interfaceDecl
                        ;

optArray                :
                        |   SBO SBC
                        ;

identifiers             :   IDENTIFIER
                        |   identifiers IDENTIFIER
                        ;

functionDecl            :   type IDENTIFIER BO formals BC stmtBlock
                        |   VOID IDENTIFIER BO formals BC stmtBlock
                        ;

formals                 :   variable
                        |   formals COMMA variable //FIX
                        ;

classDecl               :   CLASS IDENTIFIER optExtends optImplements CBO fields CBC
                        ;

optExtends              :   EXTENDS IDENTIFIER
                        |
                        ;

optImplements           :   IMPLEMENTS identifiers
                        |
                        ;

fields                  :
                        |   fields field
                        ;

field                   :   variableDecl 
                        |   functionDecl
                        ;

interfaceDecl           :   INTERFACE IDENTIFIER CBO prototype CBC
                        ;

prototype               :
                        |   type IDENTIFIER BO formals BC SEMICOLON
                        |   VOID IDENTIFIER BO formals BC SEMICOLON
                        ;

variableDecls           :
                        |   variableDecls variableDecl
                        ;

stmts                   :
                        |   stmts stmt
                        ;

stmtBlock               :   CBO variableDecls stmts CBC
                        ;

variableDecl            :   variable SEMICOLON
                        ;

variable                :   type IDENTIFIER
                        ;

type                    :   INT optArray
                        |   DOUBLE optArray
                        |   BOOL optArray
                        |   STRING optArray
                        |   IDENTIFIER optArray
                        ;



stmt                    :   ifStmt
                        |   expression SEMICOLON
                        |   whileStmt
                        |   forStmt
                        |   breakStmt 
                        |   returnStmt 
                        |   printStmt 
                        |   stmtBlock
                        ;

ifStmt                  :   IF BO expression BC stmtBlock optElse
                        ;

optElse                 :
                        |   ELSE stmtBlock
                        ;

whileStmt               :   WHILE BO expression BC stmtBlock
                        ;

forStmt                 :   FOR BO expression SEMICOLON expression SEMICOLON expression BC stmtBlock
                        ;
                        
returnStmt              :   RETURN expression SEMICOLON
                        ;

breakStmt               :   BREAK SEMICOLON
                        ;
                        
printStmt               :   PRINT BO expressionList BC SEMICOLON
                        ;

expressionList          :   expression
                        |   expressionList COMMA expression
                        ;   


expression              :   expressionA
                        ;

expressionA             :   expressionA EQUAL expressionA
                        |   expressionB
                        ;

expressionB             :   expressionB OR expressionC
                        |   expressionC
                        ;

expressionC             :   expressionC AND expressionD
                        |   expressionD
                        ;

expressionD             :   expressionD EQUALEQUAL expressionE
                        |   expressionD NOTEQUAL expressionE
                        |   expressionE
                        ;

expressionE             :   expressionE LESS expressionF
                        |   expressionE LESSEQUAL expressionF
                        |   expressionE GREATER expressionF
                        |   expressionE GREATEREQUAL expressionF
                        |   expressionF
                        ;

expressionF             :   expressionF PLUS expressionG
                        |   expressionF MINUS expressionG
                        |   expressionG
                        ;

expressionG             :   expressionG MUL expressionH
                        |   expressionG DIV expressionH
                        |   expressionG MOD expressionH
                        |   expressionH
                        ;

expressionH             :   NOT expressionH
                        |   MINUS expressionH
                        |   expressionI
                        ;

expressionI             :   lValue EQUAL expressionA
                        |   lValue
                        |   constant
                        |   call
                        |   READINTEGER BO BC
                        |   READLINE BO BC
                        |   NEW BO IDENTIFIER BC
                        |   NEWARRAY BO expressionA COMMA type BC
                        |   THIS
                        |   BO expressionA BC
                        ;
lValue                  :   IDENTIFIER 
                        |   expression DOT IDENTIFIER
                        |   expression SBO expression SBC
                        ;

call                    :   IDENTIFIER BO actualList BC
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