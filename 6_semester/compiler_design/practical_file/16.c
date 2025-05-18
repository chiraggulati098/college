#include <stdio.h>
#include <string.h>

char input[100];
int pos = 0;

char peek() {
    return input[pos];
}

void advance() {
    pos++;
}

int match(char expected) {
    if (peek() == expected) {
        advance();
        return 1;
    }
    return 0;
}

int E();
int E_();
int T();
int T_();
int F();

int E() {
    if (T()) {
        return E_();
    }
    return 0;
}

int E_() {
    if (peek() == '+') {
        advance();
        if (T()) {
            return E_();
        }
        return 0;
    }
    return 1;  // ε
}

int T() {
    if (F()) {
        return T_();
    }
    return 0;
}

int T_() {
    if (peek() == '*') {
        advance();
        if (F()) {
            return T_();
        }
        return 0;
    }
    return 1;  // ε
}

int F() {
    if (match('i')) {
        return 1;
    } else if (match('(')) {
        if (E()) {
            return match(')');
        }
        return 0;
    }
    return 0;
}

int main() {
    printf("Enter expression (use 'i' as operand, e.g., i+i*i): ");
    scanf("%s", input);
    strcat(input, "$");  // Add end marker

    if (E() && peek() == '$') {
        printf("Expression is valid and successfully parsed.\n");
    } else {
        printf("Invalid expression.\n");
    }

    return 0;
}