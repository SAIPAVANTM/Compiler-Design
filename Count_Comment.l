%{
int comment=0;
int in_comment = 0;
%}

%%
"//" {comment++;}
"/*"    { in_comment = 1; }
"*/"    { if (in_comment) { comment++; in_comment = 0; } }
.|\n    { if (in_comment) ; }
%%

int yywrap() {return 1;}
int main(int argc , char * argv[])
{
yyin = fopen(argv[1],"r");
yylex();
printf("Number of comments : %d",comment);
return 0;
}