#include <stdio.h>
#include <string.h>

#define MAX_PROD 100
#define MAX_PROD_LEN 50

void removeLeftRecursion(const char *nonTerminal, char productions[][MAX_PROD_LEN], int n) {
    char alpha[MAX_PROD][MAX_PROD_LEN];
    char beta[MAX_PROD][MAX_PROD_LEN];
    int alphaCount = 0, betaCount = 0;

    for (int i = 0; i < n; i++) {
        if (strncmp(productions[i], nonTerminal, strlen(nonTerminal)) == 0) {
            strcpy(alpha[alphaCount], productions[i] + strlen(nonTerminal));
            alphaCount++;
        } else {
            strcpy(beta[betaCount], productions[i]);
            betaCount++;
        }
    }

    if (alphaCount == 0) {
        printf("No left recursion found for %s.\n", nonTerminal);
        return;
    }

    char newNonTerminal[50];
    strcpy(newNonTerminal, nonTerminal);
    strcat(newNonTerminal, "'");

    printf("After removing left recursion:\n");

    for (int i = 0; i < betaCount; i++) {
        printf("%s -> %s%s\n", nonTerminal, beta[i], newNonTerminal);
    }

    for (int i = 0; i < alphaCount; i++) {
        printf("%s -> %s%s\n", newNonTerminal, alpha[i], newNonTerminal);
    }
    printf("%s -> ε\n", newNonTerminal);
}

int main() {
    char nonTerminal[50];
    int n;
    char productions[MAX_PROD][MAX_PROD_LEN];

    printf("Enter the non-terminal (e.g., A): ");
    scanf("%49s", nonTerminal);

    printf("Enter number of productions for %s: ", nonTerminal);
    scanf("%d", &n);

    if (n > MAX_PROD) {
        printf("Too many productions. Maximum allowed is %d.\n", MAX_PROD);
        return 1;
    }

    printf("Enter the productions (example: Aa, b):\n");
    for (int i = 0; i < n; i++) {
        scanf("%49s", productions[i]);
    }

    removeLeftRecursion(nonTerminal, productions, n);

    return 0;
}