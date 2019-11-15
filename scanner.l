%{
#include "ast.h"
#include "parser.tab.h"
#include <cstring>

#define YY_DECL extern "C" int yylex()

void printToken(int, int, char* , char*);
void printError(int, int, char*);
void printStringError(int, int);

extern union node yylval;

int column = 1;

%}
%option yylineno


    /*  DEFINICIONES  */

CHAR                        ((\\[n|t|\"|\\])|[^\\\"])+
INVCHAR						((\\[^n|t|\"|\\])|[^\\\"])+
ID                          [a-zA-Z_]([a-zA-Z0-9_]{0,30})
HEXNUM                      0[X|x][0-9a-fA-F]+
DECNUM                      [-]?[0-9]+
DOUBLE                      [-]?[0-9]+(.[0-9]+)?
TAG                         [ \t\r\\]

%%

    /* Comentarios */

\/\/(.*)                    ;
\/\*(.|\n)*\*\/             ;

    /*   OPERADORES   */

\+ {
    printToken(yylineno, yyleng, "PLUS", nullptr);
    return PLUS;
}
\- {
    printToken(yylineno, yyleng, "MINUS", nullptr);
    return MINUS;
}
\* {
    printToken(yylineno, yyleng, "MUL", nullptr);
    return MUL;
}
\/ {
    printToken(yylineno, yyleng, "DIV", nullptr);
    return DIV;
}
\% {
    printToken(yylineno, yyleng, "MOD", nullptr);
    return MOD;
}
\<\= {
    printToken(yylineno, yyleng, "LESSEQUAL", nullptr);
    return LESSEQUAL;
}
\< {
    printToken(yylineno, yyleng, "LESS", nullptr);
    return LESS;
}
\>\= {
    printToken(yylineno, yyleng, "GREATEREQUAL", nullptr);
    return GREATEREQUAL;
}
\> {
    printToken(yylineno, yyleng, "GREATER", nullptr);
    return GREATER;
}
\=\= {
    printToken(yylineno, yyleng, "EQUALEQUAL", nullptr);
    return EQUALEQUAL;
}
\= {
    printToken(yylineno, yyleng, "EQUAL", nullptr);
    return EQUAL;
}
\!\= {
    printToken(yylineno, yyleng, "NOTEQUAL", nullptr);
    return NOTEQUAL;
}
\&\& {
    printToken(yylineno, yyleng, "AND", nullptr);
    return AND;
}
\|\| {
    printToken(yylineno, yyleng, "OR", nullptr);
    return OR;
}
\! {
    printToken(yylineno, yyleng, "NOT", nullptr);
       return NOT;
}
\; {
    printToken(yylineno, yyleng, "SEMICOLON", nullptr);
       return SEMICOLON;
}
\, {
    printToken(yylineno, yyleng, "COMMA", nullptr);
       return COMMA;
}
\. {
    printToken(yylineno, yyleng, "DOT", nullptr);
       return DOT;
}
\[ {
    printToken(yylineno, yyleng, "SBO", nullptr);
       return SBO;
}
\] {
    printToken(yylineno, yyleng, "SBC", nullptr);
       return SBC;
}
\( {
    printToken(yylineno, yyleng, "BO", nullptr);
       return BO;
}
\) {
    printToken(yylineno, yyleng, "BC", nullptr);
       return BC;
}
\{ {
    printToken(yylineno, yyleng, "CBO", nullptr);
       return CBO; 
}
\} { 
    printToken(yylineno, yyleng, "CBC", nullptr);
       return CBC;
}
\n { 
    column = 0; 
}

    /*   KEYWORDS     */

void                        {   printToken(yylineno, yyleng, "VOID", nullptr);
                                   return VOID;
                            }
int {
    printToken(yylineno, yyleng, "INT", nullptr);
    return INT;
}
double {
    printToken(yylineno, yyleng, "DOUBLE", nullptr);
    return DOUBLE;
}
bool {   
    printToken(yylineno, yyleng, "BOOL", nullptr);
    return BOOL;
}
string {
    printToken(yylineno, yyleng, "STRING", nullptr);
    return STRING;
}
class {
    printToken(yylineno, yyleng, "CLASS", nullptr);
    return CLASS;
}

interface {
    printToken(yylineno, yyleng, "INTERFACE", nullptr);
    return INTERFACE;
}

null {
    printToken(yylineno, yyleng, "NULL", nullptr);
    return _NULL;
}

this {
    printToken(yylineno, yyleng, "THIS", nullptr);
    return THIS;
}

extends {
    printToken(yylineno, yyleng, "EXTENDS", nullptr);
    return EXTENDS;
}

implements {
    printToken(yylineno, yyleng, "IMPLEMENTS", nullptr);
    return IMPLEMENTS;
}

for {
    printToken(yylineno, yyleng, "FOR", nullptr);
    return FOR;
}
while {
    printToken(yylineno, yyleng, "WHILE", nullptr);
    return WHILE;
}

if {
    printToken(yylineno, yyleng, "IF", nullptr);
    return IF;
}

else {
    printToken(yylineno, yyleng, "ELSE", nullptr);
    return ELSE;
}

return {
    printToken(yylineno, yyleng, "RETURN", nullptr);
    return RETURN;
}

break {
    printToken(yylineno, yyleng, "BREAK", nullptr);
    return BREAK;
}

New {
    printToken(yylineno, yyleng, "NEW", nullptr);
    return NEW;
}

NewArray {
    printToken(yylineno, yyleng, "NEWARRAY", nullptr);
    return NEWARRAY;
}

Print {
    printToken(yylineno, yyleng, "PRINT", nullptr);
    return PRINT;
}

ReadInteger {
    printToken(yylineno, yyleng, "READINTEGER", nullptr);
    return READINTEGER;
}

ReadLine {
    printToken(yylineno, yyleng, "READLINE", nullptr);
    return READLINE;
}

true {
    printToken(yylineno, yyleng, "TRUE", nullptr);
    return _TRUE;
}

false {
    printToken(yylineno, yyleng, "FALSE", nullptr);
    return _FALSE;
}

    /*  VALUES  */

{HEXNUM} {
    printToken(yylineno, yyleng, "INT_VALUE", strdup(yytext));
    return INT_VALUE;
}
{DECNUM} {
    printToken(yylineno, yyleng, "INT_VALUE", strdup(yytext));
    return INT_VALUE; 
}
{DOUBLE} {
    char *ptr;
    yylval.dval = strtod(yytext, &ptr);
    printToken(yylineno, yyleng, "DOUBLE_VALUE", strdup(yytext));
    return DOUBLE_VALUE;
}
\"{CHAR}*\" {
    yylval.sval = strdup(yytext);
    printToken(yylineno, yyleng, "STRING_VALUE", strdup(yytext));
    return STRING_VALUE;
}

\"{CHAR}* {
    printStringError(yylineno, yyleng);
    return INVALID_STRING;
}
\'{CHAR}?\' {
    yylval.sval = strdup(yytext);
    printToken(yylineno, yyleng, "CHAR_VALUE", strdup(yytext));
    return CHAR_VALUE; 
}
\"{INVCHAR}*\" {
    printError(yylineno, yyleng, strdup(yytext));
    return INVALID_STRING;
}
\"{INVCHAR}* {
    printStringError(yylineno, yyleng);
    return INVALID_STRING;
}
\'{INVCHAR}?\' {
    printError(yylineno, yyleng, strdup(yytext));
    return INVALID_CHAR;
}							
							
{ID} {
    yylval.sval = strdup(yytext);
    printToken(yylineno, yyleng, "IDENTIFIER", strdup(yytext));
    return IDENTIFIER; 
}
{TAG} {
    column+=yyleng;
}



    /* OTHER */
. {
    printError(yylineno, yyleng, strdup(yytext));
    return INVALID_CHAR;
}

%%

void printNSpaces(int n){
    for(int i = 0; i < n ; i++){
        printf(" ");
    }
}

void printToken(int line, int lenToken, char *yytokentype, char *sType){
    printf("        ║ %d\t\t║ %d\t\t║", line, column);

    printf(" %s", yytokentype);
    printNSpaces(22 - strlen(yytokentype));
    
    if (sType) {
        printf("║ %s", sType);
        printNSpaces(22 - strlen(sType));
    } else {
        printf("║");
        printNSpaces(23);
    }
    printf("║\n");
    printf("        ╠═══════════════╬═══════════════╬═══════════════════════╬═══════════════════════╣\n");
    column += lenToken;
}

void printError(int line, int column, char* sType){
	printf("%d:%d: Lexical Error: Invalid character %s\n", line, column, sType);
}

void printStringError(int line, int column){
	printf("%d:%d: Lexical Error: Unclosed string.", line, column);
}