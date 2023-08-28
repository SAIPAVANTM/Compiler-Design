#include <stdio.h>
#include <string.h>

#define MAX_LINES 100

int main() {
    char code[MAX_LINES][100] = {
        "int x = 5;",
        "int y = 10;",
        "int z = 0;",
        "",
        "if (x > y) {",
        "    z = x + y;",
        "} else {",
        "    z = x - y;",
        "}",
        "",
        "// remove: Dead code that will be eliminated",
        "if (z < 0) {",
        "    printf(\"Z is negative.\\n\");",
        "}",
        "",
        "printf(\"Result: %d\\n\", z);"
    };
    
    int lineCount = sizeof(code) / sizeof(code[0]);

    // Dead code elimination
    int usedLines[MAX_LINES] = { 0 };  // Assume no lines are used initially
	int i;
    for (i = 0; i < lineCount; i++) {
        // Check if the line is used based on the code analysis
        if (strstr(code[i], "remove") == NULL) {
            usedLines[i] = 1;
        }
    }

    // Display optimized code
    printf("Optimized code:\n");
    for (i = 0; i < lineCount; i++) {
        if (usedLines[i]) {
            printf("%s\n", code[i]);
        }
    }

    return 0;
}

