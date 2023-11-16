%{
    int positive_count = 0;
    int negative_count = 0;
%}

%%
[+][0-9]+       { positive_count++; }
[-][0-9]+       { negative_count++; }
.               ; /* Ignore other characters */
\n              ; /* Ignore newline */
%%

int main() {
    yylex();
    printf("Positive count: %d\n", positive_count);
    printf("Negative count: %d\n", negative_count);
    return 0;
}