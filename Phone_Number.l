%{
#include<stdio.h>
%}

%%
[0-9]{10} printf("Valid phone number : %s\n",yytext);
.|\n
%%

int yywrap() {return 1;}

int main(int argc , char * argv[]){
yyin = fopen(argv[1],"r");
yylex();
return 0;
}
