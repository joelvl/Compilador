%{
#include "ast.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

extern "C" int yylex();
extern "C" int yyparse();
extern "C" void yyerror(char *s);
extern "C" int yywrap(void)
{
    return 1;
}

extern union node yylval;
extern class AST_Node * start;
%}
%locations

%token VOID INT DOUBLE BOOL STRING CLASS INTERFACE _NULL THIS EXTENDS IMPLEMENTS FOR WHILE IF ELSE RETURN BREAK NEW NEWARRAY PRINT READINTEGER READLINE _TRUE _FALSE
%token PLUS MINUS MUL DIV MOD LESS LESSEQUAL GREATER GREATEREQUAL EQUALEQUAL EQUAL NOTEQUAL AND OR NOT
%token SEMICOLON COMMA DOT SBO SBC DBO BO BC CBO CBC

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

%nonassoc EQUAL
%left OR
%left AND
%nonassoc NOTEQUAL EQUALEQUAL
%nonassoc GREATER GREATEREQUAL LESS LESSEQUAL
%left PLUS MINUS
%left MUL DIV MOD
%left NOT
%nonassoc SBO DOT

%%  //TERMINALES MAYUS - NO TERMINALES MINUS

program
    : decls {
        $$ = new AST_Program($1);
        start = $$;
    };

decls
    : decl {
        $$ = new std::vector<Declaration_Node*>();
        $$->push_back($1);
    }
    | decls decl {
        $1->push_back($2);
        $$ = $1;
    };

decl
    : variableDecl {
        $$ = $1;
    }
    | functionDecl {
        $$ = $1;
    }
    | classDecl {
        $$ = $1;
    }
    | interfaceDecl {
        $$ = $1;
    };

identifiers
    : IDENTIFIER {
        $$ = new std::vector<Identifier_Node*> ();
        $$->push_back(new Identifier_Node(std::string($1)));
    }
    | identifiers IDENTIFIER {
        $1->push_back(new Identifier_Node(std::string($2)));
        $$ = $1;
    };

functionDecl
    : type IDENTIFIER BO optFormals BC stmtBlock {
        Identifier_Node* identifier = new Identifier_Node(std::string($2));
        identifier->setPos(@2.first_line, @2.first_column);
        $$ = new Function_Declaration_Node($1, identifier, $4, $6);
        $$->setPos(@1.first_line, @1.first_column);
    }
    | VOID IDENTIFIER BO optFormals BC stmtBlock {
        Identifier_Node* identifier = new Identifier_Node(std::string($2));
        Type_Node* type = new Type_Node(Datatype::null_type, nullptr);
        type->setPos(@1.first_line, @1.first_column);
        identifier->setPos(@2.first_line, @2.first_column);
        $$ = new Function_Declaration_Node(type, identifier, $4, $6);
    };

optFormals
    : {
        $$ = nullptr;
    }
    | formals {
        $$ = $1;
    };

formals
    : variable {
        $$ = new std::vector<Variable_Declaration_Node*>();
        $$->push_back($1);
    }
    | formals COMMA variable {
        $1->push_back($3);
        $$ = $1;
    };

classDecl
    : CLASS IDENTIFIER optExtends optImplements CBO fields CBC {
        Identifier_Node* identifier = new Identifier_Node(std::string($2));
        identifier->setPos(@2.first_line, @2.first_column);
        $$ = new Class_Declaration_Node(identifier, $3, $4, $6);
        $$->setPos(@1.first_line, @1.first_column);
    };

optExtends
    : EXTENDS IDENTIFIER {
        $$ = new Identifier_Node(std::string($2));
        $$->setPos(@2.first_line, @2.first_column);
    }
    | {
        $$ = nullptr;
    };

optImplements
    : IMPLEMENTS identifiers {
        $$ = $2;
    }
    | {
        $$ = nullptr;
    };

fields
    : {
        $$ = new std::vector<Declaration_Node*>();
    }
    | fields field {
        $1->push_back($2);
        $$ = $1;
    };

field
    : variableDecl {
        $$ = $1;
    }
    | functionDecl {
        $$ = $1;
    }
    | classDecl {
        $$ = $1;
    };

interfaceDecl
    : INTERFACE IDENTIFIER CBO prototypes CBC {
        Identifier_Node* identifier = new Identifier_Node(std::string($2));
        identifier->setPos(@2.first_line, @2.first_column);
        $$ = new Interface_Declaration_Node(identifier, $4);
        $$->setPos(@1.first_line, @1.first_column);
    };

prototypes
    : {
        $$ = new std::vector<Prototype_Node*>();
    }
    | prototypes prototype {
        $1->push_back($2);
        $$ = $1;
    };

prototype
    : type IDENTIFIER BO optFormals BC SEMICOLON {
        Identifier_Node* identifier = new Identifier_Node(std::string($2));
        identifier->setPos(@2.first_line, @2.first_column);
        $$ = new Prototype_Node($1, identifier, $4);
        $$->setPos(@1.first_line, @1.first_column);
    }
    | VOID IDENTIFIER BO optFormals BC SEMICOLON {
        Identifier_Node* identifier = new Identifier_Node(std::string($2));
        identifier->setPos(@2.first_line, @2.first_column);
        Type_Node* type = new Type_Node(Datatype::null_type);
        $$ = new Prototype_Node(type, identifier, $4);
        $$->setPos(@1.first_line, @1.first_column);
    };

stmts
    : {
        $$ = new std::vector<AST_Node*>();
    }
    | stmts stmt {
        $1->push_back($2);
        $$ = $1;
    }
    | stmts variableDecl {
        $1->push_back($2);
        $$ = $1;
    };

stmtBlock
    : CBO stmts CBC {
        $$ = new Statement_Block_Node($2);
        $$->setPos(@1.first_line, @1.first_column);
    };

variableDecl
    : variable SEMICOLON {
            $$ = $1;
        };

variable
    : type IDENTIFIER {
        Identifier_Node* identifier = new Identifier_Node(std::string($2));
        identifier->setPos(@2.first_line, @2.first_column);
        $$ = new Variable_Declaration_Node($1,identifier);
        $$->setPos(@1.first_line, @1.first_column);
    };

type
    : INT {
        $$ = new Type_Node(Datatype::int_type, nullptr);
        $$->setPos(@1.first_line, @1.first_column);
    }
    | DOUBLE {
        $$ = new Type_Node(Datatype::double_type, nullptr);
        $$->setPos(@1.first_line, @1.first_column);
    }
    | BOOL {
        $$ = new Type_Node(Datatype::bool_type, nullptr);
        $$->setPos(@1.first_line, @1.first_column);
    }
    | STRING {
        $$ = new Type_Node(Datatype::string_type, nullptr);
        $$->setPos(@1.first_line, @1.first_column);
    }
    | IDENTIFIER {
        $$ = new Type_Node(Datatype::identifier_type, new Identifier_Node(std::string($1)));
        $$->setPos(@1.first_line, @1.first_column);
    }
    | type DBO {
        $$ = $1;
        $$->setAsArray();
    };

stmt
    : ifStmt {
        $$ = $1;
    }
    | expression SEMICOLON {
        $$ = $1;
    }
    | whileStmt {
        $$ = $1;
    }
    | forStmt {
        $$ = $1;
    }
    | breakStmt {
        $$ = $1;
    }
    | returnStmt {
        $$ = $1;
    }
    | printStmt {
        $$ = $1;
    }
    | stmtBlock {
        $$ = $1;
    };

ifStmt
    : IF BO expression BC stmtBlock optElse {
        $$ = new If_Statement_Node($3, $5, $6);
        $$->setPos(@1.first_line, @1.first_column);
    };

optElse
    : {
        $$ = nullptr;
    }
    | ELSE stmtBlock {
        $$ = $2;
    };

whileStmt
    : WHILE BO expression BC stmtBlock {
        $$ = new While_Statement_Node($3, $5);
        $$->setPos(@1.first_line, @1.first_column);
    };

forStmt
    : FOR BO expression SEMICOLON expression SEMICOLON expression BC stmtBlock {
        $$ = new For_Statement_Node($3, $5, $7, $9);
        $$->setPos(@1.first_line, @1.first_column);
    };

returnStmt
    : RETURN expression SEMICOLON {
        $$ = new Return_Statement_Node($2);
        $$->setPos(@1.first_line, @1.first_column);
    }
    | RETURN SEMICOLON {
        $$ = new Return_Statement_Node(new Null_Constant_Expression_Node());
        $$->setPos(@1.first_line, @1.first_column);
    };

breakStmt
    : BREAK SEMICOLON {
        $$ = new Break_Statement_Node();
        $$->setPos(@1.first_line, @1.first_column);
    };

printStmt
    : PRINT BO expressionList BC SEMICOLON {
        $$ = new Print_Statement_Node($3);
        $$->setPos(@1.first_line, @1.first_column);
    };

expressionList
    : expression {
        $$ = new std::vector<Expression_Node*>();
        $$->push_back($1);
    }
    | expressionList COMMA expression { 
        $1->push_back($3); 
        $$ = $1;
    };


expression
    : expression OR expression {
        $$ = new Comparation_Expression_Node($1, $3, Operator_Type::OR);
        $$->setPos(@1.first_line, @1.first_column);
    }
    | expression AND expression {
        $$ = new Comparation_Expression_Node($1, $3, Operator_Type::AND);
        $$->setPos(@1.first_line, @1.first_column);
    }
    | expression EQUALEQUAL expression {
        $$ = new Comparation_Expression_Node($1, $3, Operator_Type::EQUALEQUAL);
        $$->setPos(@1.first_line, @1.first_column);
    }
    | expression NOTEQUAL expression {
        $$ = new Comparation_Expression_Node($1, $3, Operator_Type::NOTEQUAL);
        $$->setPos(@1.first_line, @1.first_column);
    }
    | expression LESS expression {
        $$ = new Comparation_Expression_Node($1, $3, Operator_Type::LESS);
        $$->setPos(@1.first_line, @1.first_column);
    }
    | expression LESSEQUAL expression {
        $$ = new Comparation_Expression_Node($1, $3, Operator_Type::LESSEQUAL);
        $$->setPos(@1.first_line, @1.first_column);
    }
    | expression GREATER expression {
        $$ = new Comparation_Expression_Node($1, $3, Operator_Type::GREATER);
        $$->setPos(@1.first_line, @1.first_column);
    }
    | expression GREATEREQUAL expression {
        $$ = new Comparation_Expression_Node($1, $3, Operator_Type::GREATEREQUAL);
        $$->setPos(@1.first_line, @1.first_column);
    }
    | expression PLUS expression {
        $$ = new Comparation_Expression_Node($1, $3, Operator_Type::PLUS);
        $$->setPos(@1.first_line, @1.first_column);
    }
    | expression MINUS expression {
        $$ = new Comparation_Expression_Node($1, $3, Operator_Type::MINUS);
        $$->setPos(@1.first_line, @1.first_column);
    }
    | expression MUL expression {
        $$ = new Comparation_Expression_Node($1, $3, Operator_Type::MUL);
        $$->setPos(@1.first_line, @1.first_column);
    }
    | expression DIV expression {
        $$ = new Comparation_Expression_Node($1, $3, Operator_Type::DIV);
        $$->setPos(@1.first_line, @1.first_column);
    }
    | expression MOD expression {
        $$ = new Comparation_Expression_Node($1, $3, Operator_Type::MOD);
        $$->setPos(@1.first_line, @1.first_column);
    }
    | expression EQUAL expression {
        $$ = new Comparation_Expression_Node($1, $3, Operator_Type::EQUAL);
        $$->setPos(@1.first_line, @1.first_column);
    }
    | NOT expression {
        $$ = new Comparation_Expression_Node($2, nullptr, Operator_Type::NOT);
        $$->setPos(@1.first_line, @1.first_column);
    }
    | MINUS expression {
        $$ = new Comparation_Expression_Node($2, nullptr, Operator_Type::MINUS);
        $$->setPos(@1.first_line, @1.first_column);
    }
    | expression SBO expression SBC {
        $$ = new Array_Expression_Node($1, $3);
        $$->setPos(@1.first_line, @1.first_column);
    }
    | expression DOT IDENTIFIER optActualList {
        Identifier_Node* identifier = new Identifier_Node(std::string($3));
        identifier->setPos(@3.first_line, @3.first_column);
        $$ = new Call_Expression_Node($1, identifier, $4);
        $$->setPos(@1.first_line, @1.first_column);
    }
    | IDENTIFIER BO actualList BC {
        Identifier_Node* identifier = new Identifier_Node(std::string($1));
        identifier->setPos(@1.first_line, @1.first_column);
        $$ = new Call_Expression_Node(nullptr, identifier, $3);
        $$->setPos(@1.first_line, @1.first_column);
    }
    | IDENTIFIER {
        Identifier_Node* identifier = new Identifier_Node(std::string($1));
        identifier->setPos(@1.first_line, @1.first_column);
        $$ = new Identifier_Expression_Node(identifier);
        $$->setPos(@1.first_line, @1.first_column);
    }
    | constant {
        $$ = $1;
    }
    | READINTEGER BO BC {
        $$ = new ReadInteger_Expression_Node();
        $$->setPos(@1.first_line, @1.first_column);
    }
    | READLINE BO BC {
        $$ = new ReadLine_Expression_Node();
        $$->setPos(@1.first_line, @1.first_column);
    }
    | NEW BO IDENTIFIER BC {
        Identifier_Node* identifier = new Identifier_Node(std::string($3));
        identifier->setPos(@3.first_line, @3.first_column);
        $$ = new New_Expression_Node(identifier);
        $$->setPos(@1.first_line, @1.first_column);
    }
    | NEWARRAY BO expression COMMA type BC {
        $$ = new NewArray_Expression_Node($3, $5);
        $$->setPos(@1.first_line, @1.first_column);
    }
    | THIS {
        $$ = new This_Expression_Node(); 
        $$->setPos(@1.first_line, @1.first_column);
    }
    | BO expression BC {
        $$ = $2;
    };

optActualList
    : {
        $$ = nullptr;
    }
    | BO actualList BC {
        $$ = $2;
    };

actualList
    : actuals {
        $$ = $1;
    }
    | {
        $$ = new std::vector<Expression_Node*>();
    };

actuals
    : expression {
        $$ = new std::vector<Expression_Node*>();
        $$->push_back($1);
    }
    | actuals COMMA expression {
        $1->push_back($3);
        $$ = $1;
    };

constant
    : INT_VALUE {
        $$ = new Int_Constant_Expression_Node($1);
        $$->setPos(@1.first_line, @1.first_column);
    }
    | DOUBLE_VALUE {
        $$ = new Double_Constant_Expression_Node($1);
        $$->setPos(@1.first_line, @1.first_column);
    }
    | _TRUE {
        $$ = new Boolean_Constant_Expression_Node(true);
        $$->setPos(@1.first_line, @1.first_column);
    }
    | _FALSE {
        $$ = new Boolean_Constant_Expression_Node(false);
        $$->setPos(@1.first_line, @1.first_column);
    }
    | STRING_VALUE {
        $$ = new String_Constant_Expression_Node(std::string($1));
        $$->setPos(@1.first_line, @1.first_column);
    }
    | _NULL {
        $$ = new Null_Constant_Expression_Node();
        $$->setPos(@1.first_line, @1.first_column);
    };

%%

void yyerror(char *s)
{
	fprintf(stderr, "\tError: %s\n", s);
}