%{
#include "ast.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

extern "C" int yylex();
extern "C" int yyparse();
extern "C" void yyerror(char *s);
extern "C" int yywrap(void) {return 1;}

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
%type <program> program
%type <decls> decls
%type <decl> decl
%type <variableDecl> variableDecl
%type <functionDecl> functionDecl
%type <classDecl> classDecl
%type <identifiers> identifiers
%type <optFormals> optFormals
%type <formals> formals
%type <optExtends> optExtends
%type <optImplements> optImplements
%type <fields> fields
%type <field> field
%type <interfaceDecl> interfaceDecl
%type <prototype> prototype
%type <prototypes> prototypes
%type <stmts> stmts
%type <stmtBlock> stmtBlock
%type <variable> variable
%type <type> type
%type <stmt> stmt
%type <ifStmt> ifStmt
%type <optElse> optElse
%type <whileStmt> whileStmt
%type <forStmt> forStmt
%type <returnStmt> returnStmt
%type <breakStmt> breakStmt
%type <printStmt> printStmt
%type <expressionList> expressionList
%type <expression> expression
%type <optActualList> optActualList
%type <actualList> actualList
%type <actuals> actuals
%type <constant> constant

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

program                 :   decls { $$ = new AST_Program($1); std::cout << "Vaya duerma.\n"; }
                        ;

decls                   :   decl { 
                                $$ = new std::vector<Declaration_Node*>(); 
                                $$->push_back($1); 
                            }
                        |   decls decl {
                                $1->push_back($2);
                                $$ = $1;
                            }
                        ;

decl                    :   variableDecl {
                                $$ = $1;
                            }
                        |   functionDecl {
                                $$ = $1;
                            }
                        |   classDecl {
                                $$ = $1;
                            }
                        |   interfaceDecl {
                                $$ = $1;
                            }
                        ;

identifiers             :   IDENTIFIER { $$ = new std::vector<Identifier_Node*> (); $$->push_back(new Identifier_Node(std::string($1))); }
                        |   identifiers IDENTIFIER { $1->push_back(new Identifier_Node(std::string($2))); $$ = $1; }
                        ;

functionDecl            :   type IDENTIFIER BO optFormals BC stmtBlock { 
                                $$ = new Function_Declaration_Node($1, new Identifier_Node(std::string($2)), $4, $6); 
                            }
                        |   VOID IDENTIFIER BO optFormals BC stmtBlock { 
                                $$ = new Function_Declaration_Node(new Type_Node(Datatype::null_type, nullptr), new Identifier_Node(std::string($2)), $4, $6); 
                            }
                        ;

optFormals              :   { $$ = nullptr; }
                        |   formals { $$ = $1; }
                        ;

formals                 :   variable { $$ = new std::vector<Variable_Declaration_Node*>(); $$->push_back($1); }
                        |   formals COMMA variable { $1->push_back($3); $$ = $1; }
                        ;

classDecl               :   CLASS IDENTIFIER optExtends optImplements CBO fields CBC { 
                                $$ = new Class_Declaration_Node(new Identifier_Node(std::string($2)), $3, $4, $6); 
                            }
                        ;

optExtends              :   EXTENDS IDENTIFIER { $$ = new Identifier_Node(std::string($2)); }
                        |   { $$ = nullptr; }
                        ;

optImplements           :   IMPLEMENTS identifiers { $$ = $2; }
                        |   { $$ = nullptr; }
                        ;

fields                  :   { $$ = new std::vector<Declaration_Node*>(); }
                        |   fields field { $1->push_back($2); $$ = $1; }
                        ;

field                   :   variableDecl { $$ = $1; }
                        |   functionDecl { $$ = $1; }
                        ;

interfaceDecl           :   INTERFACE IDENTIFIER CBO prototypes CBC { 
                                $$ = new Interface_Declaration_Node(new Identifier_Node(std::string($2)), $4); 
                            }
                        ;

prototypes              :   { $$ = new std::vector<Prototype_Node*>(); }
                        |   prototypes prototype { $1->push_back($2); $$ = $1; }
                        ;

prototype               :   type IDENTIFIER BO formals BC SEMICOLON { 
                                $$ = new Prototype_Node($1, new Identifier_Node(std::string($2)), $4); 
                            }
                        |   VOID IDENTIFIER BO formals BC SEMICOLON { 
                                $$ = new Prototype_Node(nullptr, new Identifier_Node(std::string($2)), $4); 
                            }
                        ;

stmts                   :   { $$ = new std::vector<AST_Node*>(); } 
                        |   stmts stmt { $1->push_back($2); $$ = $1; }
                        |   stmts variableDecl { $1->push_back($2); $$ = $1; }
                        ;

stmtBlock               :   CBO stmts CBC { $$ = new Statement_Block_Node($2); }
                        ;

variableDecl            :   variable SEMICOLON {
                                $$ = $1;
                            }
                        ;

variable                :   type IDENTIFIER {
                                $$ = new Variable_Declaration_Node($1, new Identifier_Node(std::string($2)));
                            }
                        ;

type                    :   INT { $$ = new Type_Node(Datatype::int_type, nullptr); }
                        |   DOUBLE { $$ = new Type_Node(Datatype::double_type, nullptr); }
                        |   BOOL { $$ = new Type_Node(Datatype::bool_type, nullptr); }
                        |   STRING { $$ = new Type_Node(Datatype::string_type, nullptr); }
                        |   IDENTIFIER { $$ = new Type_Node(Datatype::identifier_type, new Identifier_Node(std::string($1))); }
                        |   type SBO SBC { $$ = $1; }
                        ;

stmt                    :   ifStmt { $$ = $1; }
                        |   expression SEMICOLON { $$ = $1; }
                        |   whileStmt { $$ = $1; }
                        |   forStmt { $$ = $1; }
                        |   breakStmt { $$ = $1; }
                        |   returnStmt { $$ = $1; }
                        |   printStmt { $$ = $1; }
                        |   stmtBlock { $$ = $1; }
                        ;

ifStmt                  :   IF BO expression BC stmtBlock optElse { $$ = new If_Statement_Node($3, $5, $6); }
                        ;

optElse                 :   { $$ = nullptr; }
                        |   ELSE stmtBlock { $$ = $2; }
                        ;

whileStmt               :   WHILE BO expression BC stmtBlock { $$ = new While_Statement_Node($3, $5); }
                        ;

forStmt                 :   FOR BO expression SEMICOLON expression SEMICOLON expression BC stmtBlock {  $$ = new For_Statement_Node($3, $5, $7, $9); }
                        ;
                        
returnStmt              :   RETURN expression SEMICOLON { $$ = new Return_Statement_Node($2); }
                        ;

breakStmt               :   BREAK SEMICOLON { $$ = new Break_Statement_Node(); }
                        ;
                        
printStmt               :   PRINT BO expressionList BC SEMICOLON { $$ = new Print_Statement_Node($3); }
                        ;

expressionList          :   expression { $$ = new std::vector<Expression_Node*>(); $$->push_back($1); }
                        |   expressionList COMMA expression { $1->push_back($3); $$ = $1; }
                        ;


expression              :   expression OR expression { $$ = new Comparation_Expression_Node($1, $3, Operator_Type::OR); }
                        |   expression AND expression { $$ = new Comparation_Expression_Node($1, $3, Operator_Type::AND); }
                        |   expression EQUALEQUAL expression { $$ = new Comparation_Expression_Node($1, $3, Operator_Type::EQUALEQUAL); }
                        |   expression NOTEQUAL expression { $$ = new Comparation_Expression_Node($1, $3, Operator_Type::NOTEQUAL); }
                        |   expression LESS expression { $$ = new Comparation_Expression_Node($1, $3, Operator_Type::LESS); }
                        |   expression LESSEQUAL expression { $$ = new Comparation_Expression_Node($1, $3, Operator_Type::LESSEQUAL); }
                        |   expression GREATER expression { $$ = new Comparation_Expression_Node($1, $3, Operator_Type::GREATER); }
                        |   expression GREATEREQUAL expression { $$ = new Comparation_Expression_Node($1, $3, Operator_Type::GREATEREQUAL); }
                        |   expression PLUS expression { $$ = new Comparation_Expression_Node($1, $3, Operator_Type::PLUS); }
                        |   expression MINUS expression { $$ = new Comparation_Expression_Node($1, $3, Operator_Type::MINUS); }
                        |   expression MUL expression { $$ = new Comparation_Expression_Node($1, $3, Operator_Type::MUL); }
                        |   expression DIV expression { $$ = new Comparation_Expression_Node($1, $3, Operator_Type::DIV); }
                        |   expression MOD expression { $$ = new Comparation_Expression_Node($1, $3, Operator_Type::MOD); }
                        |   expression EQUAL expression { $$ = new Comparation_Expression_Node($1, $3, Operator_Type::EQUAL); }
                        |   NOT expression { $$ = new Comparation_Expression_Node($2, nullptr, Operator_Type::NOT); }
                        |   MINUS expression { $$ = new Comparation_Expression_Node($2, nullptr, Operator_Type::MINUS); }
                        |   expression SBO expression SBC { $$ = new Array_Expression_Node($1, $3); }
                        |   expression DOT IDENTIFIER optActualList { $$ = new Call_Expression_Node($1, new Identifier_Node(std::string($3)), $4); }
                        |   IDENTIFIER { $$ = new Identifier_Expression_Node(new Identifier_Node(std::string($1))); }
                        |   constant { $$ = $1; }
                        |   READINTEGER BO BC { $$ = new ReadInteger_Expression_Node(); }
                        |   READLINE BO BC { $$ = new ReadLine_Expression_Node(); }
                        |   NEW BO IDENTIFIER BC { $$ = new New_Expression_Node(new Identifier_Node(std::string($3))); }
                        |   NEWARRAY BO expression COMMA type BC { $$ = new NewArray_Expression_Node($3, $5); }
                        |   THIS { $$ = new This_Expression_Node(); } 
                        |   BO expression BC { $$ = $2; }
                        ;

optActualList           :   { $$ = nullptr; }
                        |   BO actualList BC { $$ = $2; }
                        ;

actualList              :   actuals { $$ = $1; }
                        |   { $$ = nullptr; }
                        ;

actuals                 :   expression { $$ = new std::vector<Expression_Node*>(); $$->push_back($1); }
                        |   actuals COMMA expression { $1->push_back($3); $$ = $1; }
                        ;

constant                :   INT_VALUE { $$ = new Int_Constant_Expression_Node($1); }
                        |   DOUBLE_VALUE { $$ = new Double_Constant_Expression_Node($1); }
                        |   _TRUE { $$ = new Boolean_Constant_Expression_Node(true); }
                        |   _FALSE { $$ = new Boolean_Constant_Expression_Node(false); }
                        |   STRING_VALUE { $$ = new String_Constant_Expression_Node($1); }
                        |   _NULL { $$ = new Null_Constant_Expression_Node(); }
                        ;

%%

void yyerror(char *s)
{
	fprintf(stderr, "error: %s\n", s);
}