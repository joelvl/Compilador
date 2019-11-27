%{
#include "ast.h"
#include "parser.tab.h"
#include <cstring>

#define YY_DECL extern "C" int yylex()

int yycolumn = 1;

#define YY_USER_ACTION yylloc.first_line = yylloc.last_line = yylineno; \
    yylloc.first_column = yycolumn; yylloc.last_column = yycolumn + yyleng - 1; \
    yycolumn += yyleng; \
    yylval.sval = strdup(yytext);

void printToken(int, int, char* , char*);
void printError(int, int, char*);
void printStringError(int, int);
void yyerror(char* s);

extern union node yylval;
extern bool printTokenTable;

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

\/\/(.*) ;
\/\*(.|\n)*\*\/ ;

    /*   OPERADORES   */

\+ {
    printToken(yylineno, yyleng, "PLUS", strdup(yytext));
    return PLUS;
}
\- {
    printToken(yylineno, yyleng, "MINUS", strdup(yytext));
    return MINUS;
}
\* {
    printToken(yylineno, yyleng, "MUL", strdup(yytext));
    return MUL;
}
\/ {
    printToken(yylineno, yyleng, "DIV", strdup(yytext));
    return DIV;
}
\% {
    printToken(yylineno, yyleng, "MOD", strdup(yytext));
    return MOD;
}
\<\= {
    printToken(yylineno, yyleng, "LESSEQUAL", strdup(yytext));
    return LESSEQUAL;
}
\< {
    printToken(yylineno, yyleng, "LESS", strdup(yytext));
    return LESS;
}
\>\= {
    printToken(yylineno, yyleng, "GREATEREQUAL", strdup(yytext));
    return GREATEREQUAL;
}
\> {
    printToken(yylineno, yyleng, "GREATER", strdup(yytext));
    return GREATER;
}
\=\= {
    printToken(yylineno, yyleng, "EQUALEQUAL", strdup(yytext));
    return EQUALEQUAL;
}
\= {
    printToken(yylineno, yyleng, "EQUAL", strdup(yytext));
    return EQUAL;
}
\!\= {
    printToken(yylineno, yyleng, "NOTEQUAL", strdup(yytext));
    return NOTEQUAL;
}
\&\& {
    printToken(yylineno, yyleng, "AND", strdup(yytext));
    return AND;
}
\|\| {
    printToken(yylineno, yyleng, "OR", strdup(yytext));
    return OR;
}
\! {
    printToken(yylineno, yyleng, "NOT", strdup(yytext));
       return NOT;
}
\; {
    printToken(yylineno, yyleng, "SEMICOLON", strdup(yytext));
       return SEMICOLON;
}
\, {
    printToken(yylineno, yyleng, "COMMA", strdup(yytext));
       return COMMA;
}
\. {
    printToken(yylineno, yyleng, "DOT", strdup(yytext));
       return DOT;
}
\[\] {
    printToken(yylineno, yyleng, "DBO", strdup(yytext));
       return DBO;
}
\[ {
    printToken(yylineno, yyleng, "SBO", strdup(yytext));
       return SBO;
}
\] {
    printToken(yylineno, yyleng, "SBC", strdup(yytext));
       return SBC;
}
\( {
    printToken(yylineno, yyleng, "BO", strdup(yytext));
       return BO;
}
\) {
    printToken(yylineno, yyleng, "BC", strdup(yytext));
       return BC;
}
\{ {
    printToken(yylineno, yyleng, "CBO", strdup(yytext));
       return CBO; 
}
\} { 
    printToken(yylineno, yyleng, "CBC", strdup(yytext));
       return CBC;
}
\n { 
    yycolumn = 1;
}

    /*   KEYWORDS     */

void {
    printToken(yylineno, yyleng, "VOID", strdup(yytext));
    return VOID;
}
int {
    printToken(yylineno, yyleng, "INT", strdup(yytext));
    return INT;
}
double {
    printToken(yylineno, yyleng, "DOUBLE", strdup(yytext));
    return DOUBLE;
}
bool {   
    printToken(yylineno, yyleng, "BOOL", strdup(yytext));
    return BOOL;
}
string {
    printToken(yylineno, yyleng, "STRING", strdup(yytext));
    return STRING;
}
class {
    printToken(yylineno, yyleng, "CLASS", strdup(yytext));
    return CLASS;
}

interface {
    printToken(yylineno, yyleng, "INTERFACE", strdup(yytext));
    return INTERFACE;
}

null {
    printToken(yylineno, yyleng, "NULL", strdup(yytext));
    return _NULL;
}

this {
    printToken(yylineno, yyleng, "THIS", strdup(yytext));
    return THIS;
}

extends {
    printToken(yylineno, yyleng, "EXTENDS", strdup(yytext));
    return EXTENDS;
}

implements {
    printToken(yylineno, yyleng, "IMPLEMENTS", strdup(yytext));
    return IMPLEMENTS;
}

for {
    printToken(yylineno, yyleng, "FOR", strdup(yytext));
    return FOR;
}
while {
    printToken(yylineno, yyleng, "WHILE", strdup(yytext));
    return WHILE;
}

if {
    printToken(yylineno, yyleng, "IF", strdup(yytext));
    return IF;
}

else {
    printToken(yylineno, yyleng, "ELSE", strdup(yytext));
    return ELSE;
}

return {
    printToken(yylineno, yyleng, "RETURN", strdup(yytext));
    return RETURN;
}

break {
    printToken(yylineno, yyleng, "BREAK", strdup(yytext));
    return BREAK;
}

new|New {
    printToken(yylineno, yyleng, "NEW", strdup(yytext));
    return NEW;
}

NewArray {
    printToken(yylineno, yyleng, "NEWARRAY", strdup(yytext));
    return NEWARRAY;
}

Print {
    printToken(yylineno, yyleng, "PRINT", strdup(yytext));
    return PRINT;
}

ReadInteger {
    printToken(yylineno, yyleng, "READINTEGER", strdup(yytext));
    return READINTEGER;
}

ReadLine {
    printToken(yylineno, yyleng, "READLINE", strdup(yytext));
    return READLINE;
}

true {
    printToken(yylineno, yyleng, "TRUE", strdup(yytext));
    return _TRUE;
}

false {
    printToken(yylineno, yyleng, "FALSE", strdup(yytext));
    return _FALSE;
}

    /*  VALUES  */

{HEXNUM} {
    yylval.ival = strtol(yytext, 0, 16);
    printToken(yylineno, yyleng, "INT_VALUE", strdup(yytext));
    return INT_VALUE;
}
{DECNUM} {
    yylval.ival = strtol(yytext, 0, 10);
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
    //yycolumn+=yyleng;
}

<<EOF>> {
    if (printTokenTable)
        printf(" ╚═══════════════╩═══════════════╩═══════════════════════╩═══════════════════════╝\n");
    return 0;
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
    if (!printTokenTable){
        return;
    }
    printf(" ╠═══════════════╬═══════════════╬═══════════════════════╬═══════════════════════╣\n");
    printf(" ║ %d\t\t ║ %d\t\t ║", yylineno, yylloc.first_column);

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
}

void printError(int line, int column, char* sType){
	printf("\t%d:%d: Lexical Error: Invalid character %s\n", line, column, sType);
}

void printStringError(int line, int column){
	printf("\t%d:%d: Lexical Error: Unclosed string.", line, column);
}