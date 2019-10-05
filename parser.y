%{


%}

%token VOID INT DOUBLE BOOL STRING CLASS INTERFACE _NULL THIS EXTENDS IMPLEMENTS FOR WHILE IF ELSE RETURN BREAK NEW NEWARRAY PRINT READINTEGER READLINE TRUE FALSE 
%token <ival> INT_VALUE 
%token <cval> CHAR_VALUE 
%token <sval> STRING_VALUE 
%token <sval> IDENTIFIER 
%token PLUS MINUS MUL DIV MOD LESS LESSEQUAL GREATER GREATEREQUAL EQUALEQUAL EQUAL NOTEQUAL AND OR NOT 
%token SEMICOLON COMMA DOT SBO SBC BO BC CBO CBC

%type <program> program
%type <statement> statement 
%type <statements> statements 

%%

program         : statements {};

statements      : statement {}
                | statements statement {}
                ;

statement       : VOID {}
                ;

%%