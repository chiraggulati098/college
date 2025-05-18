#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

char* toPostfix(char* expr) {
    char* postfix = (char*)malloc(MAX);
    char stack[MAX];
    int top = -1, k = 0;

    for (int i = 0; expr[i]; i++) {
        char ch = expr[i];
        if (isalnum(ch)) {
            postfix[k++] = ch;
        } else if (ch == '(') {
            stack[++top] = ch;
        } else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[k++] = stack[top--];
            }
            if (top != -1) top--;
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
                postfix[k++] = stack[top--];
            }
            stack[++top] = ch;
        }
    }

    while (top != -1) {
        postfix[k++] = stack[top--];
    }
    postfix[k] = '\0';

    return postfix;
}

void generateIR(char* postfix, char* lhs) {
    char* stack[MAX];
    int top = -1, tempVar = 1;

    for (int i = 0; postfix[i]; i++) {
        char ch = postfix[i];
        if (isalnum(ch)) {
            char* str = (char*)malloc(2);
            str[0] = ch;
            str[1] = '\0';
            stack[++top] = str;
        } else {
            char* op2 = stack[top--];
            char* op1 = stack[top--];
            char temp[10];
            sprintf(temp, "t%d", tempVar++);
            printf("%s = %s %c %s\n", temp, op1, ch, op2);
            char* result = (char*)malloc(strlen(temp) + 1);
            strcpy(result, temp);
            stack[++top] = result;
            free(op1);
            free(op2);
        }
    }

    printf("%s = %s\n", lhs, stack[top--]);
    free(stack[top + 1]);
}

int main() {
    char input[MAX];
    printf("Enter assignment statement (e.g., a=b+c*d): ");
    scanf("%s", input);

    char lhs[MAX], rhs[MAX];
    char* eq = strchr(input, '=');
    if (eq == NULL) {
        printf("Invalid input format!\n");
        return 1;
    }

    int pos = eq - input;
    strncpy(lhs, input, pos);
    lhs[pos] = '\0';
    strcpy(rhs, input + pos + 1);

    char* postfix = toPostfix(rhs);

    printf("\nIntermediate Representation (Three-Address Code):\n");
    generateIR(postfix, lhs);

    free(postfix);
    return 0;
}
