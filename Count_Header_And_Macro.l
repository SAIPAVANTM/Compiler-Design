%{
	int m, h;
%}

%%
^#define {m++;}
^#include {h++;}
%%

int yywrap(){return 1;}

int main(int argc, char * argv[])
{
	yyin=fopen(argv[1], "r");
	yylex();
	printf("No of macros:%d", m);
	printf("Npo of header files: %d", h);
	return 0;
}