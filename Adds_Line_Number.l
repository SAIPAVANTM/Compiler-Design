%{
int line_number = 0;
%}

%%
^(.*)\n printf("%d\t%s", ++line_number,yytext);
%%

int yywrap() {return 1;}
int main(int argc, char * argv[]){
yyin = fopen(argv[1],"r");
yylex();
fclose(yyin);
return 0;
}