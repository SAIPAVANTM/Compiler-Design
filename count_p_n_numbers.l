%{
#include<stdio.h>
int n=0;
int p=0;
%}

%%
-?[0-9]+ {if (yytext[0] == '-') n++; else p++;}
.|\n
%%

int yywrap() {return 1;}

int main(int argc, char * argv[]){
yyin = fopen(argv[1], "r");
yylex();
printf("Positive numbers : %d",p);
printf("Negative numbers : %d", n);
return 0;
}