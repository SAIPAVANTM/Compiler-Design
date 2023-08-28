%{
int w=0,l=0,c=0;
%}

%%
[a-zA-Z]+ {w++; c+=yyleng;}
\n {l++; c++;}
. {c++;}
%%

int yywrap() {return 1;}

int main(int argc,char * argv[])
{
	yyin = fopen(argv[1],"r");
	yylex();
	printf("No of Lines = %d\n",l);
	printf("No of Words = %d\n",w);
	printf("No of Characters = %d\n",c);
	return 0;
}