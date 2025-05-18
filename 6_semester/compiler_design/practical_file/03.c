#include <stdio.h>
#include <string.h>

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

int main() {
    char word[100];
    printf("Enter a word: ");
    scanf("%99s", word);

    if (isKeyword(word)) {
        printf("%s is a C keyword.\n", word);
    } else {
        printf("%s is NOT a C keyword.\n", word);
    }

    return 0;
}