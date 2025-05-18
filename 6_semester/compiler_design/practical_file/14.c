#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char input[100];
int pos = 0;

void E();  
void T();
void F();

char currentToken() {
    return input[pos];
}

void match(char expected) {
    if (currentToken() == expected) {
        pos++;
    } else {
        printf("\nSyntax Error at position %d!\n", pos);
        exit(1);
    }
}

void F() {
    if (currentToken() == '(') {
        match('(');
        E();
        match(')');
    } else if (isalnum(currentToken())) {
        printf("%c ", currentToken());
        match(currentToken());
    } else {
        printf("\nInvalid character: %c\n", currentToken());
        exit(1);
    }
}

void TPrime() {
    while (currentToken() == '*' || currentToken() == '/') {
        char op = currentToken();
        match(op);
        F();
        printf("%c ", op);
    }
}

void T() {
    F();
    TPrime();
}

void EPrime() {
    while (currentToken() == '+' || currentToken() == '-') {
        char op = currentToken();
        match(op);
        T();
        printf("%c ", op);
    }
}

void E() {
    T();
    EPrime();
}

int main() {
    printf("Enter an arithmetic expression (no spaces, e.g., a+b*c): ");
    scanf("%s", input);

    printf("Postfix (Syntax-Directed Translation): ");
    E();

    if (pos == strlen(input)) {
        printf("\nTranslation successful.\n");
    } else {
        printf("\nError: Unparsed input remains.\n");
    }

    return 0;
}