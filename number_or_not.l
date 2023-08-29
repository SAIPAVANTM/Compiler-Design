%%
[0-9]     printf("Digit: %s\n", yytext);
.         printf("Not a digit: %s\n", yytext);
%%

int yywrap() {return 1;}

int main() {
    yylex();
    return 0;
}
