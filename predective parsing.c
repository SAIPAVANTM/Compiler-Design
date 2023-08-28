#include <stdio.h>
#include <string.h>

// Define grammar rules
char *grammar[] = {
    "S -> E",
    "E -> E + T",
    "E -> T",
    "T -> T * F",
    "T -> F",
    "F -> ( E )",
    "F -> id"
};

// Define parsing table (simplified for demonstration)
char actionTable[6][4][10] = {
    { "", "", "", "" },         // 0
    { "", "s3", "", "" },       // 1
    { "s4", "", "s5", "" },     // 2
    { "", "", "", "accept" },   // 3
    { "", "s3", "", "" },       // 4
    { "s4", "", "s5", "" }      // 5
};

int goToTable[6][3] = {
    { 1, 2, 0 },
    { 0, 0, 0 },
    { 0, 0, 6 },
    { 0, 0, 0 },
    { 0, 2, 0 },
    { 0, 0, 0 }
};

// SLR parsing function
void slrParse(const char *input) {
    char stack[100];
    int top = 0;
    int state = 0;
    int i = 0,j;

    stack[top] = '0';

    while (1) {
        char lookahead = input[i];
        char action[10];
        strcpy(action, actionTable[state][lookahead - 'a']);

        if (strcmp(action, "") == 0) {
            printf("Error: Invalid input\n");
            break;
        }

        if (strcmp(action, "accept") == 0) {
            printf("Input accepted!\n");
            break;
        }

        if (action[0] == 's') {
            state = action[1] - '0';
            stack[++top] = lookahead;
            stack[++top] = state + '0';
            i++;
        } else if (action[0] == 'r') {
            int production = action[1] - '0';
            int reduceLength = strlen(grammar[production]) - 4; // Length of right-hand side
            for (j = 0; j < 2 * reduceLength; j++) {
                top--;
            }
            char nonTerminal = grammar[production][0];
            state = goToTable[stack[top] - '0'][nonTerminal - 'A'];
            stack[++top] = nonTerminal;
            stack[++top] = state + '0';
        }
    }
}

int main() {
    char input[100];

    // Get input from user
    printf("Enter the input string: ");
    scanf("%s", input);

    // Call the SLR parsing function
    slrParse(input);

    return 0;
}

