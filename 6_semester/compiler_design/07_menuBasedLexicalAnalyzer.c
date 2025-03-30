#include <stdio.h>
#include <string.h>
#include <ctype.h>

// List of C keywords
const char* keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default",
    "do", "double", "else", "enum", "extern", "float", "for", "goto",
    "if", "inline", "int", "long", "register", "restrict", "return",
    "short", "signed", "sizeof", "static", "struct", "switch", "typedef",
    "union", "unsigned", "void", "volatile", "while", "_Alignas", "_Alignof",
    "_Atomic", "_Bool", "_Complex", "_Generic", "_Imaginary", "_Noreturn",
    "_Static_assert", "_Thread_local"
};

// Function to check if a string is a keyword
int isKeyword(char str[]) {
    int totalKeywords = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < totalKeywords; i++) {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

// Function to check if a string is a valid identifier
int isValidIdentifier(char str[]) {
    if (!(isalpha(str[0]) || str[0] == '_'))
        return 0;
    for (int i = 1; str[i] != '\0'; i++) {
        if (!(isalnum(str[i]) || str[i] == '_'))
            return 0;
    }
    return 1;
}

// Function to check if a string is a constant (basic digit presence check)
int containsDigit(char str[]) {
    int hasDigit = 0, hasAlpha = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i]))
            hasDigit = 1;
        else if (isalpha(str[i]))
            hasAlpha = 1;
    }
    return (hasDigit && !hasAlpha);  // Ensures it is a valid number
}

// Function to count lines and spaces in a given text
void countLinesAndSpaces(char str[], int* lines, int* spaces) {
    *lines = 0;
    *spaces = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ')
            (*spaces)++;
        else if (str[i] == '\n')
            (*lines)++;
    }
}

int main() {
    int choice;
    char input[1000];

    do {
        printf("\n===== Mini Lexical Analyzer Menu =====\n");
        printf("1. Check Keyword\n");
        printf("2. Check Identifier\n");
        printf("3. Check Constant\n");
        printf("4. Count Spaces and Lines\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume newline left in buffer

        switch (choice) {
            case 1:
                printf("Enter word: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = '\0';  // Remove newline
                if (isKeyword(input))
                    printf("'%s' is a C keyword.\n", input);
                else
                    printf("'%s' is NOT a C keyword.\n", input);
                break;

            case 2:
                printf("Enter word: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = '\0';
                if (isValidIdentifier(input))
                    printf("'%s' is a valid identifier.\n", input);
                else
                    printf("'%s' is NOT a valid identifier.\n", input);
                break;

            case 3:
                printf("Enter a string: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = '\0';
                if (containsDigit(input))
                    printf("The string '%s' is a constant.\n", input);
                else
                    printf("The string '%s' is NOT a constant.\n", input);
                break;

            case 4: {
                printf("Enter multiline text (end input with '~' on a new line):\n");
                int i = 0;
                char ch;
                while ((ch = getchar()) != '~' && i < sizeof(input) - 1) {
                    input[i++] = ch;
                }
                input[i] = '\0';

                int lines, spaces;
                countLinesAndSpaces(input, &lines, &spaces);
                printf("Lines: %d\nSpaces: %d\n", lines, spaces);
                break;
            }

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}