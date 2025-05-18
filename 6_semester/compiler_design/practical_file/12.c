#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STACK 100
#define MAX_EXPR 100

struct Stack {
    char items[MAX_STACK];
    int top;
};

struct StringStack {
    char items[MAX_STACK][MAX_EXPR];
    int top;
};

void initStack(struct Stack *s) {
    s->top = 0;
}

void initStringStack(struct StringStack *s) {
    s->top = 0;
}

void push(struct Stack *s, char item) {
    if (s->top < MAX_STACK) {
        s->items[s->top] = item;
        s->top++;
    }
}

void pushString(struct StringStack *s, const char *item) {
    if (s->top < MAX_STACK) {
        strcpy(s->items[s->top], item);
        s->top++;
    }
}

char pop(struct Stack *s) {
    if (s->top > 0) {
        s->top--;
        return s->items[s->top];
    }
    return '\0';
}

void popString(struct StringStack *s, char *item) {
    if (s->top > 0) {
        s->top--;
        strcpy(item, s->items[s->top]);
    }
}

int stackEmpty(struct Stack *s) {
    return s->top == 0;
}

int stringStackEmpty(struct StringStack *s) {
    return s->top == 0;
}

char stackTop(struct Stack *s) {
    if (s->top > 0) {
        return s->items[s->top - 1];
    }
    return '\0';
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void infixToPostfix(const char *infix, char *postfix) {
    struct Stack opStack;
    initStack(&opStack);
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];
        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(&opStack, ch);
        } else if (ch == ')') {
            while (!stackEmpty(&opStack) && stackTop(&opStack) != '(') {
                postfix[j++] = pop(&opStack);
            }
            pop(&opStack);
        } else {
            while (!stackEmpty(&opStack) && precedence(stackTop(&opStack)) >= precedence(ch)) {
                postfix[j++] = pop(&opStack);
            }
            push(&opStack, ch);
        }
    }

    while (!stackEmpty(&opStack)) {
        postfix[j++] = pop(&opStack);
    }
    postfix[j] = '\0';
}

void generateTAC(const char *postfix) {
    struct StringStack s;
    initStringStack(&s);
    int tempCount = 1;

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];
        if (isalnum(ch)) {
            char temp[MAX_EXPR] = "";
            temp[0] = ch;
            temp[1] = '\0';
            pushString(&s, temp);
        } else {
            char op2[MAX_EXPR], op1[MAX_EXPR];
            popString(&s, op2);
            popString(&s, op1);
            char tempName[MAX_EXPR];
            sprintf(tempName, "t%d", tempCount++);
            printf("%s = %s %c %s\n", tempName, op1, ch, op2);
            pushString(&s, tempName);
        }
    }
}

int main() {
    char infix[MAX_EXPR], postfix[MAX_EXPR];
    printf("Enter an arithmetic expression (e.g., a+b*c): ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("\nPostfix Expression: %s\n", postfix);
    printf("\nThree Address Code:\n");
    generateTAC(postfix);

    return 0;
}