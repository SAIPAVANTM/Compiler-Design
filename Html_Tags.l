%{
#include<stdio.h>
%}

%%
"<"[^>]*">" {printf("HTML tag : %s\n",yytext);}
.|\n
%%

int yywrap() {return 1;}

int main(int argc, char * argv[]){
yyin = fopen(argv[1],"r");
yylex();
return 0;
}