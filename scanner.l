%{
#include "parser.tab.h"


void printToken(int, int, char* , char*);
void printError(int, int, char*);
void printStringError(int, int);

%}
%option yylineno


    /*  DEFINICIONES  */

CHAR                        ((\\[n|t|\"|\\])|[^\\\"])+
INVCHAR						((\\[^n|t|\"|\\])|[^\\\"])+
ID                          [a-zA-Z_]([a-zA-Z0-9_]{0,30})
HEXNUM                      0[X|x][0-9a-fA-F]+
DECNUM                      [-]?[0-9]+
DOUBLE                      [-]?[0-9]+(.[0-9]+)?


%%
    /* Comentarios */

\/\/(.*)                    ;
\/\*(.|\n)*\*\/             ;

    /*   OPERADORES   */

\+                          {   printToken(yylineno, 0, "PLUS", "");
                                return PLUS; }
\-                          {   printToken(yylineno, 0, "MINUS", "");
                                return MINUS; }
\*                          {   printToken(yylineno, 0, "MUL", "");
                                return MUL; }
\/                          {   printToken(yylineno, 0, "DIV", "");
                                return DIV; }
\%                          {   printToken(yylineno, 0, "MOD", "");
                                return MOD; }
\<\=                        {   printToken(yylineno, 0, "LESSEQUAL", "");
                                return LESSEQUAL; }
\<                          {   printToken(yylineno, 0, "LESS", "");
                                return LESS; }
\>\=                        {   printToken(yylineno, 0, "GREATEREQUAL", "");
                                return GREATEREQUAL; }
\>                          {   printToken(yylineno, 0, "GREATER", "");
                                return GREATER; }
\=\=                        {   printToken(yylineno, 0, "EQUALEQUAL", "");
                                return EQUALEQUAL; }
\=                          {   printToken(yylineno, 0, "EQUAL", "");
                                return EQUAL; }
\!\=                        {   printToken(yylineno, 0, "NOTEQUAL", "");
                                return NOTEQUAL; }
\&\&                        {   printToken(yylineno, 0, "AND", "");
                                return AND; }
\|\|                        {   printToken(yylineno, 0, "OR", "");
                                return OR; }
\!                          {   printToken(yylineno, 0, "NOT", "");
                                return NOT; }
\;                          {   printToken(yylineno, 0, "SEMICOLON", "");
                                return SEMICOLON; }
\,                          {   printToken(yylineno, 0, "COMMA", "");
                                return COMMA; }
\.                          {   printToken(yylineno, 0, "DOT", "");
                                return DOT; }
\[                          {   printToken(yylineno, 0, "SBO", "");
                                return SBO; }
\]                          {   printToken(yylineno, 0, "SBC", "");
                                return SBC; }
\(                          {   printToken(yylineno, 0, "BO", "");
                                return BO; }
\)                          {   printToken(yylineno, 0, "BC", "");
                                return BC; }
\{                          {   printToken(yylineno, 0, "CBO", "");
                                return CBO; }
\}                          {   printToken(yylineno, 0, "CBC", "");
                                return CBC; }

    /*   KEYWORDS     */

void                        {   printToken(yylineno, 0, "VOID", "");
                                return VOID;
                            }
int                         {   printToken(yylineno, 0, "INT", "");
                                return INT;
                            }
double                      {   printToken(yylineno, 0, "DOUBLE", "");
                                return DOUBLE;
                            }
bool                        {   printToken(yylineno, 0, "BOOL", "");
                                return BOOL;
                            }
string                      {   printToken(yylineno, 0, "STRING", "");
                                return STRING;
                            }
class                       {   printToken(yylineno, 0, "CLASS", "");
                                return CLASS;
                            }
interface                   {   printToken(yylineno, 0, "INTERFACE", "");
                                return INTERFACE;
                            }
null                        {   printToken(yylineno, 0, "NULL", "");
                                return _NULL;
                            }
this                        {   printToken(yylineno, 0, "THIS", "");
                                return THIS;
                            }
extends                     {   printToken(yylineno, 0, "EXTENDS", "");
                                return EXTENDS;
                            }
implements                  {   printToken(yylineno, 0, "IMPLEMENTS", "");
                                return IMPLEMENTS;
                            }
for                         {   printToken(yylineno, 0, "FOR", "");
                                return FOR;
                            }
while                       {   printToken(yylineno, 0, "WHILE", "");
                                return WHILE;
                            }
if                          {   printToken(yylineno, 0, "IF", "");
                                return IF;
                            }
else                        {   printToken(yylineno, 0, "ELSE", "");
                                return ELSE;
                            }
return                      {   printToken(yylineno, 0, "RETURN", "");
                                return RETURN;
                            }
break                       {   printToken(yylineno, 0, "BREAK", "");
                                return BREAK;
                            }
New                         {   printToken(yylineno, 0, "NEW", "");
                                return NEW;
                            }
NewArray                    {   printToken(yylineno, 0, "NEWARRAY", "");
                                return NEWARRAY;
                            }
Print                       {   printToken(yylineno, 0, "PRINT", "");
                                return PRINT;
                            }
ReadInteger                 {   printToken(yylineno, 0, "READINTEGER", "");
                                return READINTEGER;
                            }
ReadLine                    {   printToken(yylineno, 0, "READLINE", "");
                                return READLINE;
                            }
true                        {   printToken(yylineno, 0, "TRUE", "");
                                return _TRUE;
                            }
false                       {   printToken(yylineno, 0, "FALSE", "");
                                return _FALSE;
                            }


    /*  VALUES  */

{HEXNUM}                    {   printToken(yylineno, 0, "INT_VALUE", strdup(yytext));
                                return INT_VALUE;
                            }
{DECNUM}                    {   printToken(yylineno, 0, "INT_VALUE", strdup(yytext));
                                return INT_VALUE; 
                            }
{DOUBLE}                    {   printToken(yylineno, 0, "DOUBLE_VALUE", strdup(yytext));
                                return DOUBLE_VALUE;
                            }
\"{CHAR}*\"                 {   printToken(yylineno, 0, "STRING_VALUE", strdup(yytext));
                                return STRING_VALUE;
                            }
\"{CHAR}*                   {   printStringError(yylineno, 0);
                                return INVALID_STRING;
                            }
\'{CHAR}?\'                 {   printToken(yylineno, 0, "CHAR_VALUE", strdup(yytext));
                                return CHAR_VALUE; 
                            }
\"{INVCHAR}*\"		        {   printError(yylineno, 0, strdup(yytext));
                                return INVALID_STRING;
							}
\"{INVCHAR}*                {   printStringError(yylineno, 0);
                                return INVALID_STRING;
                            }
\'{INVCHAR}?\'		        {   printError(yylineno, 0, strdup(yytext));
                                return INVALID_CHAR;
                            }							
							
{ID}                        {   printToken(yylineno, 0, "IDENTIFIER", strdup(yytext));
                                return IDENTIFIER; 
                            }


    /* OTHER */
\n                          ;
[ ]                         ;
.                           {   printError(yylineno, 0, strdup(yytext));
								return INVALID_CHAR;
							}

%%

void printToken(int line, int column, char* yytokentype, char* sType){
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
}

void printError(int line, int column, char* sType){
	printf("%d:%d: Lexical Error: Invalid character %s\n", line, column, sType);
}

void printStringError(int line, int column){
	printf("%d:%d: Lexical Error: Unclosed string.", line, column);
}

int main(int argc, char **argv)
{
    ++argv, --argc;
    yyin = fopen(argv[0], "r");
    printf("        -------------------------------------------------------------------------\n");
	printf("\t| Line\t\t| Column\t| Token\t\t\t| Value\t\t|\n");
    printf("        -------------------------------------------------------------------------\n");
    if(argc > 1){
        while(1)
            yylex();
    } else{
        yyparse();
    }
}