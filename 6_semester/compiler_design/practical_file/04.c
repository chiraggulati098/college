#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isKeyword(const char *word) {
    const char *keywords[] = {
        "auto", "break", "case", "char", "const", "continue",
        "default", "do", "double", "else", "enum", "extern", "float", "for",
        "goto", "if", "int", "long", "register", "return", "short", "signed",
        "sizeof", "static", "struct", "switch", "typedef", "union",
        "unsigned", "void", "volatile", "while",
        NULL
    };

    for (int i = 0; keywords[i] != NULL; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int isValidIdentifier(const char *s) {
    if (s[0] == '\0') return 0;

    if (!(isalpha(s[0]) || s[0] == '_')) {
        return 0;
    }

    for (int i = 1; s[i] != '\0'; i++) {
        if (!(isalnum(s[i]) || s[i] == '_')) {
            return 0;
        }
    }

    if (isKeyword(s)) {
        return 0;
    }

    return 1;
}

int main() {
    char input[100];
    printf("Enter a string to validate as identifier: ");
    scanf("%99s", input);

    if (isValidIdentifier(input)) {
        printf("%s is a valid identifier.\n", input);
    } else {
        printf("%s is NOT a valid identifier.\n", input);
    }

    return 0;
}