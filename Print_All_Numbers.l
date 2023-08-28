%{
#include<stdio.h>
%}

%%
[0-9]+ printf("\nInteger : %s\n",yytext);
%%

int yywrap() {return 1;}

int main(int argc, char * argv[])
{
yyin = fopen(argv[1],"r");
yylex();
return 0;
}