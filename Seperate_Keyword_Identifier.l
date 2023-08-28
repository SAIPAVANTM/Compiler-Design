%{
#include<stdio.h>
#include<string.h>
%}

%%
int|float|char|if|else|while {printf("Keyword : %s\n",yytext);}
[a-zA-Z][a-zA-Z0-9_]* {printf("Identifier : %s\n",yytext);}
%%

int yywrap() {return 1;}

int main(int argc , char * argv[])
{
	yyin = fopen(argv[1],"r");
	yylex();
	return 0;
}