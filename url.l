%{
#include<stdio.h>
%}

%%
(http:\/\/|https:\/\/)[a-zA-Z0-9\/\.\-]+ printf("URL : %s\n",yytext);
.|\n
%%

int yywrap() {return 1;}

int main(int argc,char * argv[]){
	yyin = fopen(argv[1],"r");
	yylex();
	return 0;
}