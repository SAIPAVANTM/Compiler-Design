%%
.    putchar(toupper(yytext[0]));
%%

int yywrap() {return 1;}

int main() {
    yylex();
    return 0;
}
