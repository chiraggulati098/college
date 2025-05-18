#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char precedence(char a, char b) {
    if (a == '+' && b == '+') return '>';
    if (a == '+' && b == '*') return '<';
    if (a == '+' && b == 'i') return '<';
    if (a == '+' && b == '$') return '>';

    if (a == '*' && b == '+') return '>';
    if (a == '*' && b == '*') return '>';
    if (a == '*' && b == 'i') return '<';
    if (a == '*' && b == '$') return '>';

    if (a == 'i' && b == '+') return '>';
    if (a == 'i' && b == '*') return '>';
    if (a == 'i' && b == '$') return '>';

    if (a == '$' && b == '+') return '<';
    if (a == '$' && b == '*') return '<';
    if (a == '$' && b == 'i') return '<';
    if (a == '$' && b == '$') return '=';

    return 'e';
}

int isOperator(char c) {
    return c == '+' || c == '*';
}

int isOperand(char c) {
    return c == 'i';
}

int main() {
    char input[MAX], stack[MAX];
    int top = -1, index = 0;
    char a, action;

    printf("Enter expression (identifiers as 'i', e.g., i+i*i): ");
    scanf("%s", input);
    strcat(input, "$");

    stack[++top] = '$';
    a = input[index];

    while (1) {
        char topSymbol = stack[top];

        while (top >= 0 && !isOperator(topSymbol) && topSymbol != '$' && topSymbol != 'i') {
            top--;
            topSymbol = stack[top];
        }

        action = precedence(topSymbol, a);

        if (action == '<' || action == '=') {
            stack[++top] = a;
            a = input[++index];
        } else if (action == '>') {
            char symbol = stack[top--];
            if (isOperand(symbol) || isOperator(symbol)) {
                stack[++top] = 'E';
                printf("Reduced by E -> %c\n", symbol);
            } else {
                printf("Syntax Error during reduction.\n");
                return 0;
            }
        } else if (action == 'e') {
            printf("Syntax Error! Invalid expression.\n");
            return 0;
        }

        if (top == 1 && stack[top] == 'E' && a == '$') {
            printf("Input string is successfully parsed.\n");
            break;
        }
    }

    return 0;
}