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

\+                          {   printToken(yylineno, yyleng, "PLUS", "");
                                return PLUS; }
\-                          {   printToken(yylineno, yyleng, "MINUS", "");
                                return MINUS; }
\*                          {   printToken(yylineno, yyleng, "MUL", "");
                                return MUL; }
\/                          {   printToken(yylineno, yyleng, "DIV", "");
                                return DIV; }
\%                          {   printToken(yylineno, yyleng, "MOD", "");
                                return MOD; }
\<\=                        {   printToken(yylineno, yyleng, "LESSEQUAL", "");
                                return LESSEQUAL; }
\<                          {   printToken(yylineno, yyleng, "LESS", "");
                                return LESS; }
\>\=                        {   printToken(yylineno, yyleng, "GREATEREQUAL", "");
                                return GREATEREQUAL; }
\>                          {   printToken(yylineno, yyleng, "GREATER", "");
                                return GREATER; }
\=\=                        {   printToken(yylineno, yyleng, "EQUALEQUAL", "");
                                return EQUALEQUAL; }
\=                          {   printToken(yylineno, yyleng, "EQUAL", "");
                                return EQUAL; }
\!\=                        {   printToken(yylineno, yyleng, "NOTEQUAL", "");
                                return NOTEQUAL; }
\&\&                        {   printToken(yylineno, yyleng, "AND", "");
                                return AND; }
\|\|                        {   printToken(yylineno, yyleng, "OR", "");
                                return OR; }
\!                          {   printToken(yylineno, yyleng, "NOT", "");
                                return NOT; }
\;                          {   printToken(yylineno, yyleng, "SEMICOLON", "");
                                return SEMICOLON; }
\,                          {   printToken(yylineno, yyleng, "COMMA", "");
                                return COMMA; }
\.                          {   printToken(yylineno, yyleng, "DOT", "");
                                return DOT; }
\[                          {   printToken(yylineno, yyleng, "SBO", "");
                                return SBO; }
\]                          {   printToken(yylineno, yyleng, "SBC", "");
                                return SBC; }
\(                          {   printToken(yylineno, yyleng, "BO", "");
                                return BO; }
\)                          {   printToken(yylineno, yyleng, "BC", "");
                                return BC; }
\{                          {   printToken(yylineno, yyleng, "CBO", "");
                                return CBO; }
\}                          {   printToken(yylineno, yyleng, "CBC", "");
                                return CBC; }
\n                          {   column = 1; }

    /*   KEYWORDS     */

void                        {   printToken(yylineno, yyleng, "VOID", "");
                                return VOID;
                            }
int                         {   printToken(yylineno, yyleng, "INT", "");
                                return INT;
                            }
double                      {   printToken(yylineno, yyleng, "DOUBLE", "");
                                return DOUBLE;
                            }
bool                        {   printToken(yylineno, yyleng, "BOOL", "");
                                return BOOL;
                            }
string                      {   printToken(yylineno, yyleng, "STRING", "");
                                return STRING;
                            }
class                       {   printToken(yylineno, yyleng, "CLASS", "");
                                return CLASS;
                            }
interface                   {   printToken(yylineno, yyleng, "INTERFACE", "");
                                return INTERFACE;
                            }
null                        {   printToken(yylineno, yyleng, "NULL", "");
                                return _NULL;
                            }
this                        {   printToken(yylineno, yyleng, "THIS", "");
                                return THIS;
                            }
extends                     {   printToken(yylineno, yyleng, "EXTENDS", "");
                                return EXTENDS;
                            }
implements                  {   printToken(yylineno, yyleng, "IMPLEMENTS", "");
                                return IMPLEMENTS;
                            }
for                         {   printToken(yylineno, yyleng, "FOR", "");
                                return FOR;
                            }
while                       {   printToken(yylineno, yyleng, "WHILE", "");
                                return WHILE;
                            }
if                          {   printToken(yylineno, yyleng, "IF", "");
                                return IF;
                            }
else                        {   printToken(yylineno, yyleng, "ELSE", "");
                                return ELSE;
                            }
return                      {   printToken(yylineno, yyleng, "RETURN", "");
                                return RETURN;
                            }
break                       {   printToken(yylineno, yyleng, "BREAK", "");
                                return BREAK;
                            }
New                         {   printToken(yylineno, yyleng, "NEW", "");
                                return NEW;
                            }
NewArray                    {   printToken(yylineno, yyleng, "NEWARRAY", "");
                                return NEWARRAY;
                            }
Print                       {   printToken(yylineno, yyleng, "PRINT", "");
                                return PRINT;
                            }
ReadInteger                 {   printToken(yylineno, yyleng, "READINTEGER", "");
                                return READINTEGER;
                            }
ReadLine                    {   printToken(yylineno, yyleng, "READLINE", "");
                                return READLINE;
                            }
true                        {   printToken(yylineno, yyleng, "TRUE", "");
                                return _TRUE;
                            }
false                       {   printToken(yylineno, yyleng, "FALSE", "");
                                return _FALSE;
                            }


    /*  VALUES  */

{HEXNUM}                    {   printToken(yylineno, yyleng, "INT_VALUE", strdup(yytext));
                                return INT_VALUE;
                            }
{DECNUM}                    {   printToken(yylineno, yyleng, "INT_VALUE", strdup(yytext));
                                return INT_VALUE; 
                            }
{DOUBLE}                    {   printToken(yylineno, yyleng, "DOUBLE_VALUE", strdup(yytext));
                                return DOUBLE_VALUE;
                            }
\"{CHAR}*\"                 {   printToken(yylineno, yyleng, "STRING_VALUE", strdup(yytext));
                                return STRING_VALUE;
                            }
\"{CHAR}*                   {   printStringError(yylineno, yyleng);
                                return INVALID_STRING;
                            }
\'{CHAR}?\'                 {   printToken(yylineno, yyleng, "CHAR_VALUE", strdup(yytext));
                                return CHAR_VALUE; 
                            }
\"{INVCHAR}*\"		        {   printError(yylineno, yyleng, strdup(yytext));
                                return INVALID_STRING;
							}
\"{INVCHAR}*                {   printStringError(yylineno, yyleng);
                                return INVALID_STRING;
                            }
\'{INVCHAR}?\'		        {   printError(yylineno, yyleng, strdup(yytext));
                                return INVALID_CHAR;
                            }							
							
{ID}                        {   printToken(yylineno, yyleng, "IDENTIFIER", strdup(yytext));
                                return IDENTIFIER; 
                            }
{TAG}                      {column+=yyleng;}



    /* OTHER */
.                           {   printError(yylineno, yyleng, strdup(yytext));
								return INVALID_CHAR;
							}


%%

void printToken(int line, int lenToken, char *yytokentype, char *sType){
    int n = 10; 
    int len = strlen(yytokentype);
    n = n - len;
    printf("\t| %d\t\t| %d\t\t|", line, column);
    printf(" %s", yytokentype);
    for(int i = 0; i < n ; i++){
        printf(" ");
    }
    printf("\t\t| %s\t\t|\n", sType);
    printf("        -------------------------------------------------------------------------\n");
    column += lenToken;
}

void printError(int line, int column, char* sType){
	printf("%d:%d: Lexical Error: Invalid character %s\n", line, column, sType);
}

void printStringError(int line, int column){
	printf("%d:%d: Lexical Error: Unclosed string.", line, column);
}