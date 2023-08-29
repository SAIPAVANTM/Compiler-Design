%{
#include<stdio.h>
%}

%%
[0-3][0-9]"/"[0-1][0-9]"/"[0-9][0-9][0-9][0-9]    { printf("Valid date\n"); return 0; }
.|\n    { printf("Invalid date\n"); return 0; }
%%

int yywrap() {return 1;}

int main(int argc, char * argv[])
{
	yyin = fopen(argv[1],"r");
	yylex();
	return 0;
}