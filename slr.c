#include <stdio.h>
#include <string.h>

#define NUM_STATES 10
#define NUM_SYMBOLS 6

// Define constants for symbols and actions
enum Symbols {
    SYMBOL_E,
    SYMBOL_PLUS,
    SYMBOL_MULTIPLY,
    SYMBOL_ID,
    SYMBOL_LPAREN,
    SYMBOL_RPAREN
};

enum Actions {
    ACTION_SHIFT,
    ACTION_REDUCE,
    ACTION_ACCEPT,
    ACTION_ERROR
};

// Define parsing table
int parsing_table[NUM_STATES][NUM_SYMBOLS] = {
    { 5, -1, -1, 4, -1, -1 },
    { -1, 6, -1, -1, -1, -1 },
    { -1, -1, 7, -1, -1, -1 },
    { -1, -1, -1, 8, -1, -1 },
    { 5, -1, -1, 4, -1, -1 },
    { -1, -1, -1, 9, -1, 10 },
    { 5, -1, -1, 4, -1, -1 },
    { 5, -1, -1, 4, -1, -1 },
    { -1, 6, -1, -1, 11, -1 },
    { -1, -1, 7, -1, -1, 12 }
};

// Parsing stack
int stack[100];
int top = -1;

// Input string
char input[100];
int input_index = 0;

// Push element onto stack
void push(int value) {
    stack[++top] = value;
}

// Pop element from stack
int pop() {
    return stack[top--];
}

// Perform SLR parsing
void slrParse() {
    push(0);
    int action, state, symbol;

    while (1) {
        state = stack[top];
        symbol = input[input_index] - '0'; // Convert char to int

        action = parsing_table[state][symbol];

        if (action == ACTION_SHIFT) {
            push(symbol);
            push(parsing_table[state][NUM_SYMBOLS - 1]);
            input_index++;
        } else if (action == ACTION_REDUCE) {
            // Perform reduce action
            // You need to handle different production rules here
            pop(); // Remove symbols that were reduced
            push(parsing_table[stack[top - 1]][stack[top]]);
        } else if (action == ACTION_ACCEPT) {
            printf("Input parsed successfully!\n");
            break;
        } else {
            printf("Error in parsing.\n");
            break;
        }
    }
}

int main() {
    printf("Enter the input string: ");
    scanf("%s", input);

    strcat(input, "$"); // Add end marker

    slrParse();

    return 0;
}
