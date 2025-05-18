#include <stdio.h>
#include <string.h>

#define MAX_STACK 100
#define MAX_INPUT 100

struct Stack {
    char items[MAX_STACK][MAX_INPUT];
    int top;
};

void initStack(struct Stack *s) {
    s->top = 0;
}

void push(struct Stack *s, const char *item) {
    if (s->top < MAX_STACK) {
        strcpy(s->items[s->top], item);
        s->top++;
    }
}

void pop(struct Stack *s, char *item) {
    if (s->top > 0) {
        s->top--;
        strcpy(item, s->items[s->top]);
    }
}

int stackSize(struct Stack *s) {
    return s->top;
}

int reduce(struct Stack *s) {
    if (stackSize(s) < 2) return 0;

    char top1[MAX_INPUT], top2[MAX_INPUT];
    pop(s, top1);
    pop(s, top2);

    if (strcmp(top2, "a") == 0 && strcmp(top1, "b") == 0) {
        printf("Reduce: a b -> S\n");
        push(s, "S");
        return 1;
    } else {
        push(s, top2);
        push(s, top1);
        return 0;
    }
}

int shiftReduceParser(char *input) {
    struct Stack stk;
    initStack(&stk);
    char modifiedInput[MAX_INPUT];
    strcpy(modifiedInput, input);
    strcat(modifiedInput, "$");

    int i = 0;
    while (i < strlen(modifiedInput)) {
        char symbol[MAX_INPUT] = "";
        symbol[0] = modifiedInput[i];
        symbol[1] = '\0';
        if (strcmp(symbol, "$") == 0) break;

        printf("Shift: %s\n", symbol);
        push(&stk, symbol);
        i++;

        while (reduce(&stk));
    }

    if (stackSize(&stk) == 1 && strcmp(stk.items[stk.top - 1], "S") == 0) {
        printf("Input accepted.\n");
        return 1;
    } else {
        printf("Input rejected.\n");
        return 0;
    }
}

int main() {
    char input[MAX_INPUT];
    printf("Enter input string (e.g., ab): ");
    scanf("%s", input);

    shiftReduceParser(input);

    return 0;
}