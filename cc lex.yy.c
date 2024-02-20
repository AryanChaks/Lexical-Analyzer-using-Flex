%{
int COMMENT=0;
%}
identifier [a-zA-Z][a-zA-Z0-9]*
%%
#.* {printf("\n%s is a preprocessor directive",yytext);}
int |
float |
char |
double |
while |
for |
struct |
typedef |
do |
if |
break |
continue |
void |
switch |
return |
else |
goto {printf("\n\t%s is a keyword",yytext);}
"/*" {COMMENT=1;}{printf("\n\t %s is a COMMENT",yytext);}
{identifier}\( {if(!COMMENT)printf("\nFUNCTION \n\t%s",yytext);}
\{  {if(!COMMENT)printf("\n BLOCK BEGINS");}
\}  {if(!COMMENT)printf("BLOCK ENDS ");}
{identifier}(\[[0-9]*\])? {if(!COMMENT) printf("\n %s IDENTIFIER",yytext);}
\".*\" {if(!COMMENT)printf("\n\t %s is a STRING",yytext);}
[0-9]+ {if(!COMMENT) printf("\n %s is a NUMBER ",yytext);}
\)(\:)? {if(!COMMENT)printf("\n\t");ECHO;printf("\n");}
\( ECHO;
= {if(!COMMENT)printf("\n\t %s is an ASSIGNMENT OPERATOR",yytext);}
\<= |
\>= |
\< |
== |
\> {if(!COMMENT) printf("\n\t%s is a RELATIONAL OPERATOR",yytext);}
%%
int main(int argc, char **argv)
{
FILE *file;
file=fopen("var.c","r");
if(!file)
{
printf("could not open the file");
exit(0);
}
yyin=file;
yylex();
printf("\n");
return(0);
}
int yywrap()
{
return(1);
}

%{
#include<string.h>
#include<stdio.h>
int line = 0;
#define YYSTYPE char *
%}
alpha [A-Za-z_]
digit [0-9]
%option yylineno
%%
[ \t\n] {yylval = strdup(yytext);}
":" {yylval = strdup(yytext);return T_colon;}
"?" {yylval = strdup(yytext);return T_ques;}
"while" {yylval = strdup(yytext);return WHILE;}
"for" {yylval = strdup(yytext);return FOR;}
"if" {yylval = strdup(yytext);return IF;}
7
"else" {yylval = strdup(yytext);return ELSE;}
"cout" {yylval = strdup(yytext);return COUT;}
"endl" {yylval = strdup(yytext);return ENDL;}
"break" {yylval = strdup(yytext);return BREAK;}
"continue" {yylval = strdup(yytext);return CONTINUE;}
"int" {yylval = strdup(yytext);return INT;}
"float" {yylval = strdup(yytext);return FLOAT;}
"char" {yylval = strdup(yytext);return CHAR;}
"void" {yylval = strdup(yytext);return VOID;}
"#include" {yylval = strdup(yytext);return INCLUDE;}
"main()" {yylval = strdup(yytext);return MAINTOK;}
{digit}+ {yylval = strdup(yytext);return NUM;}
{digit}+.{digit}+ {yylval = strdup(yytext);return FLOAT;}
{alpha}({alpha}|{digit})* {yylval = strdup(yytext);return ID;}
{alpha}({alpha}|{digit})*"\.h"? {yylval = strdup(yytext);return H;}
\".*\" {yylval = strdup(yytext);return STRING;}
"<" {yylval = strdup(yytext);return T_lt;}
8
">" {yylval = strdup(yytext);return T_gt;}
"=" {yylval = strdup(yytext);return T_eq;}
"<=" {yylval = strdup(yytext);return T_lteq;}
">=" {yylval = strdup(yytext);return T_gteq;}
"==" {yylval = strdup(yytext);return T_eqeq;}
"!=" {yylval = strdup(yytext);return T_neq;}
"+" {yylval = strdup(yytext);return T_pl;}
"-" {yylval = strdup(yytext);return T_min;}
"*" {yylval = strdup(yytext);return T_mul;}
"/" {yylval = strdup(yytext);return T_div;}
"++" {yylval = strdup(yytext);return T_incr;}
"--" {yylval = strdup(yytext);return T_decr;}
"!" {yylval = strdup(yytext);return T_neq;}
"||" {yylval = strdup(yytext);return T_or;}
"&&" {yylval = strdup(yytext);return T_and;}
. return yytext[0];
%%
