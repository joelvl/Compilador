%{
#include "parser.tab.h"
%}

CHAR (\.|[^\"])

%%
    /*   OPERADORES   */

\+                          { return PLUS; }
\-                          { return MINUS; }
\*                          { return MUL; }
\/                          { return DIV; }
\%                          { return MOD; }
\<                          { return LESS; }
\<\=                        { return LESSEQUAL; }
\>                          { return GREATER; }
\>\=                        { return GREATEREQUAL; }
\=\=                        { return EQUALEQUAL; }
\=                          { return EQUAL; }
\!\=                        { return NOTEQUAL; }
\&\&                        { return AND; }
\|\|                        { return OR; }
\!                          { return NOT; }
\;                          { return SEMICOLON; }
\,                          { return COMMA; }
\.                          { return DOT; }
\[                          { return SBO; }
\]                          { return SBC; }
\(                          { return BO; }
\)                          { return BC; }
\{                          { return CBO; }
\}                          { return CBC; }

    /*   KEYWORDS     */

void                        {
                                return VOID;
                            }
int                         {
                                return INT;
                            }
double                      {
                                return DOUBLE;
                            }
bool                        {
                                return BOOL;
                            }
string                      {
                                return STRING;
                            }
class                       {
                                return CLASS;
                            }
interface                   {
                                return INTERFACE;
                            }
null                        {
                                return _NULL;
                            }
this                        {
                                return THIS;
                            }
extends                     {
                                return EXTENDS;
                            }
implements                  {
                                return IMPLEMENTS;
                            }
for                         {
                                return FOR;
                            }
while                       {
                                return WHILE;
                            }
if                          {
                                return IF;
                            }
else                        {
                                return ELSE;
                            }
return                      {
                                return RETURN;
                            }
break                       {
                                return BREAK;
                            }
New                         {
                                return NEW;
                            }
NewArray                    {
                                return NEWARRAY;
                            }
Print                       {
                                return PRINT;
                            }
ReadInteger                 {
                                return READINTEGER;
                            }
ReadLine                    {
                                return READLINE;
                            }
true                        {
                                return TRUE;
                            }
false                       {
                                return FALSE;
                            }
0[X|x][0-9a-fA-F]+          {
                                return INT_VALUE;
                            }
[0-9]+                      {
                                return INT_VALUE; 
                            }
\"{CHAR}*\"                 { 
                                return STR_VALUE:
                            }
\'{CHAR}?\'                 {
                                return CHAR_VALUE; 
                            }
[a-zA-Z_][a-zA-Z0-9_]{0,30} {
                                return IDENTIFIER; 
                            }

    /* Comentarios */

\/\/(.*)                    ;
\/\*(.|\n)*\*\/             ;
\n                          ;
[ ]                         ;
.                           { printf("ERROR."); }

%%
int main(int argc, char **argv)  
{    
    ++argv, --argc;     
    if ( argc &gt; 0 )            
        yyin = fopen( argv[0], "r" );    
    else            
        yyin = stdin;   
    yylex();    
}