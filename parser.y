%{
#include <stdio.h>
#include <vector>

#include "Nodo.h"

int yylex();
int yyerror(char *s);
static void insertNodo(Nodo *pNodo);
static void readVector();

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

program                 :   decls {insertNodo(new Nodo("program"," ")); printf("OK\n"); readVector();}
                        ;

decls                   :   decl {insertNodo(new Nodo("declas","  "));}
                        |   decls decl {insertNodo(new Nodo("declas","  "));}
                        ;

decl                    :   variableDecl {insertNodo(new Nodo("decla","  "));}
                        |   functionDecl {insertNodo(new Nodo("decla","  "));}
                        |   classDecl {insertNodo(new Nodo("decla","  "));}
                        |   interfaceDecl {insertNodo(new Nodo("decla","  "));}
                        ;

identifiers             :   IDENTIFIER {insertNodo(new Nodo("identifiers","  "));}
                        |   identifiers IDENTIFIER {insertNodo(new Nodo("identifiers","  "));}
                        ;

functionDecl            :   type IDENTIFIER BO formals BC stmtBlock {insertNodo(new Nodo("functionDecl","  "));}
                        |   VOID IDENTIFIER BO formals BC stmtBlock {insertNodo(new Nodo("functionDecl","  "));}
                        ;

formals                 :
                        |   COMMA variable {insertNodo(new Nodo("formals","  "));}
                        |   variable formals {insertNodo(new Nodo("formals","  "));}
                        ;

classDecl               :   CLASS IDENTIFIER optExtends optImplements CBO fields CBC {insertNodo(new Nodo("classDecl","  "));}
                        ;

optExtends              :   EXTENDS IDENTIFIER {insertNodo(new Nodo("optExtends","  "));}
                        |
                        ;

optImplements           :   IMPLEMENTS identifiers {insertNodo(new Nodo("optImplements","  "));}
                        |
                        ;

fields                  :
                        |   fields field {insertNodo(new Nodo("fields","  "));}
                        ;

field                   :   variableDecl {insertNodo(new Nodo("field","  "));}
                        |   functionDecl {insertNodo(new Nodo("field","  "));}
                        ;

interfaceDecl           :   INTERFACE IDENTIFIER CBO prototype CBC {insertNodo(new Nodo("interfaceDecl","  "));}
                        ;

prototype               :
                        |   type IDENTIFIER BO formals BC SEMICOLON {insertNodo(new Nodo("prototype","  "));}
                        |   VOID IDENTIFIER BO formals BC SEMICOLON {insertNodo(new Nodo("prototype","  "));}
                        ;

stmts                   :
                        |   stmt stmts {insertNodo(new Nodo("stmts","  "));}
                        |   variableDecl stmts {insertNodo(new Nodo("stmts","  "));}
                        ;

stmtBlock               :   CBO stmts CBC {insertNodo(new Nodo("stmtBlock","  "));}
                        ;

variableDecl            :   variable SEMICOLON {insertNodo(new Nodo("variableDecl","  "));}
                        ;

variable                :   type IDENTIFIER {insertNodo(new Nodo("variable","  "));}
                        ;

type                    :   INT {insertNodo(new Nodo("type","  "));}
                        |   DOUBLE {insertNodo(new Nodo("type","  "));}
                        |   BOOL {insertNodo(new Nodo("type","  "));}
                        |   STRING {insertNodo(new Nodo("type","  "));}
                        |   IDENTIFIER {insertNodo(new Nodo("type","  "));}
                        |   type SBO SBC {insertNodo(new Nodo("type","  "));}
                        ;

stmt                    :   ifStmt {insertNodo(new Nodo("stmt","  "));}
                        |   expression SEMICOLON {insertNodo(new Nodo("stmt","  "));}
                        |   whileStmt {insertNodo(new Nodo("stmt","  "));}
                        |   forStmt {insertNodo(new Nodo("stmt","  "));}
                        |   breakStmt {insertNodo(new Nodo("stmt","  "));}
                        |   returnStmt {insertNodo(new Nodo("stmt","  "));}
                        |   printStmt {insertNodo(new Nodo("stmt","  "));}
                        |   stmtBlock {insertNodo(new Nodo("stmt","  "));}
                        ;

ifStmt                  :   IF BO expression BC stmtBlock optElse {insertNodo(new Nodo("Program","  "));}
                        ;

optElse                 :
                        |   ELSE stmtBlock {insertNodo(new Nodo("optElse","  "));}
                        ;

whileStmt               :   WHILE BO expression BC stmtBlock {insertNodo(new Nodo("whileStmt","  "));}
                        ;

forStmt                 :   FOR BO expression SEMICOLON expression SEMICOLON expression BC stmtBlock {insertNodo(new Nodo("forStmt","  "));}
                        ;
                        
returnStmt              :   RETURN expression SEMICOLON {insertNodo(new Nodo("returnStmt","  "));}
                        ;

breakStmt               :   BREAK SEMICOLON {insertNodo(new Nodo("breakStmt","  "));}
                        ;
                        
printStmt               :   PRINT BO expressionList BC SEMICOLON {insertNodo(new Nodo("printStmt","  "));}
                        ;

expressionList          :   expression {insertNodo(new Nodo("expressionList","  "));}
                        |   expressionList COMMA expression {insertNodo(new Nodo("expressionList","  "));}
                        ;


expression              :   expression OR expression {insertNodo(new Nodo("expression","  "));}
                        |   expression AND expression {insertNodo(new Nodo("expression","  "));}
                        |   expression EQUALEQUAL expression {insertNodo(new Nodo("expression","  "));}
                        |   expression NOTEQUAL expression {insertNodo(new Nodo("expression","  "));}
                        |   expression LESS expression {insertNodo(new Nodo("expression","  "));}
                        |   expression LESSEQUAL expression {insertNodo(new Nodo("expression","  "));}
                        |   expression GREATER expression {insertNodo(new Nodo("expression","  "));}
                        |   expression GREATEREQUAL expression {insertNodo(new Nodo("expression","  "));}
                        |   expression PLUS expression {insertNodo(new Nodo("expression","  "));}
                        |   expression MINUS expression {insertNodo(new Nodo("expression","  "));}
                        |   expression MUL expression {insertNodo(new Nodo("expression","  "));}
                        |   expression DIV expression {insertNodo(new Nodo("expression","  "));}
                        |   expression MOD expression {insertNodo(new Nodo("expression","  "));}
                        |   expression EQUAL expression {insertNodo(new Nodo("expression","  "));} 
                        |   NOT expression {insertNodo(new Nodo("expression","  "));}
                        |   MINUS expression {insertNodo(new Nodo("expression","  "));}
                        |   expression SBO expression SBC {insertNodo(new Nodo("expression","  "));}
                        |   expression DOT IDENTIFIER optActualList {insertNodo(new Nodo("expression","  "));}
                        |   IDENTIFIER {insertNodo(new Nodo("expression","  "));}
                        |   constant {insertNodo(new Nodo("expression","  "));}
                        |   READINTEGER BO BC {insertNodo(new Nodo("expression","  "));}
                        |   READLINE BO BC {insertNodo(new Nodo("expression","  "));}
                        |   NEW BO IDENTIFIER BC {insertNodo(new Nodo("expression","  "));}
                        |   NEWARRAY BO expression COMMA type BC {insertNodo(new Nodo("expression","  "));}
                        |   THIS {insertNodo(new Nodo("expression","  "));} 
                        |   BO expression BC {insertNodo(new Nodo("expression","  "));}
                        ;

optActualList           :
                        |   BO actualList BC {insertNodo(new Nodo("optActualList","  "));}
                        ;

actualList              :   actuals {insertNodo(new Nodo("actualList","  "));}
                        |
                        ;

actuals                 :   expression {insertNodo(new Nodo("actuals","  "));}
                        |   actuals COMMA expression {insertNodo(new Nodo("actuals","  "));}
                        ;

constant                :   INT_VALUE {insertNodo(new Nodo("constant","  "));}
                        |   DOUBLE_VALUE {insertNodo(new Nodo("constant","  "));}
                        |   _TRUE {insertNodo(new Nodo("constant","  "));}
                        |   _FALSE {insertNodo(new Nodo("constant","  "));}
                        |   STRING_VALUE {insertNodo(new Nodo("constant","  "));}
                        |   _NULL {insertNodo(new Nodo("constant","  "));}
                        ;

%%

int yyerror(char *s)
{
	printf("Syntax Error on line %s\n", s);
	return 0;
}

static vector<Nodo*> stack;

static void insertNodo(Nodo *pNodo){
    stack.push_back(pNodo);
}

static void readVector(){
      for(int i =stack.size()-1; i>=0; i--){       
            printf("%s","  ombre: ");
            printf("%s\n",stack[i]->name.c_str());
      }
}

