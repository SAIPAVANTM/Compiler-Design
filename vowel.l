%%
[aeiouAEIOU]    printf("%s is a vowel\n", yytext);
[bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ]   printf("%s is a consonant\n", yytext);
.               printf("%s is not a valid character\n", yytext);
%%

int yywrap() {return 1;}

int main() {
    yylex();
    return 0;
}
