%{
#include <stdio.h>
#include <string.h>	
char longest_word[100] = "";
%}

%%
[a-zA-Z]+ {
    if (strlen(yytext) > strlen(longest_word)) {
        strcpy(longest_word, yytext);
    }
}
.|\n ; // Ignore other characters
%%

int yywrap() {return 1;}

int main() {
    yylex();
    printf("Longest word: %s\n", longest_word);
    return 0;
}
