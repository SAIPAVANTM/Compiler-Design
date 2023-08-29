%{
#include<stdio.h>
%}

%%
[[:alnum:]]+ printf("Token: %s\n",yytext);
. printf("Token: %c\n",yytext[0]);
\n
%%

int yywrap() {return 1;}

int main(int argc, char * argv[]){
	yyin = fopen(argv[1],"r");
	yylex();
	return 0;
}