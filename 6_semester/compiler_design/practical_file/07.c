#include <stdio.h>
#include <string.h>

#define MAX_PROD 100
#define MAX_PROD_LEN 100
#define MAX_NON_TERM 20

void findCommonPrefix(const char *a, const char *b, char *commonPrefix) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0' && a[i] == b[i]) {
        commonPrefix[i] = a[i];
        i++;
    }
    commonPrefix[i] = '\0';
}

void splitAlternatives(const char *rhs, char alternatives[][MAX_PROD_LEN], int *altCount) {
    char temp[MAX_PROD_LEN];
    int tempIdx = 0;
    *altCount = 0;
    int i = 0;

    while (rhs[i] != '\0') {
        if (rhs[i] == '|') {
            temp[tempIdx] = '\0';
            strcpy(alternatives[*altCount], temp);
            (*altCount)++;
            tempIdx = 0;
        } else {
            temp[tempIdx++] = rhs[i];
        }
        i++;
    }
    temp[tempIdx] = '\0';
    strcpy(alternatives[*altCount], temp);
    (*altCount)++;
}

void leftFactoring(char productions[][MAX_PROD_LEN], int numProductions) {
    char newProductions[MAX_PROD][MAX_PROD_LEN];
    int newProdCount = 0;

    for (int i = 0; i < numProductions; i++) {
        char *arrowPos = strstr(productions[i], "->");
        if (arrowPos == NULL) {
            continue;
        }

        char lhs[MAX_NON_TERM];
        strncpy(lhs, productions[i], arrowPos - productions[i]);
        lhs[arrowPos - productions[i]] = '\0';

        char rhs[MAX_PROD_LEN];
        strcpy(rhs, arrowPos + 2);

        char rhsAlternatives[MAX_PROD][MAX_PROD_LEN];
        int altCount = 0;
        splitAlternatives(rhs, rhsAlternatives, &altCount);

        if (altCount > 1) {
            char commonPrefix[MAX_PROD_LEN] = "";
            findCommonPrefix(rhsAlternatives[0], rhsAlternatives[1], commonPrefix);

            if (strlen(commonPrefix) > 0) {
                char newNonTerminal[MAX_NON_TERM];
                strcpy(newNonTerminal, lhs);
                strcat(newNonTerminal, "'");

                char newProd[MAX_PROD_LEN];
                snprintf(newProd, MAX_PROD_LEN, "%s -> %s%s", lhs, commonPrefix, newNonTerminal);
                strcpy(newProductions[newProdCount++], newProd);

                for (int j = 0; j < altCount; j++) {
                    char suffix[MAX_PROD_LEN];
                    strcpy(suffix, rhsAlternatives[j] + strlen(commonPrefix));
                    if (strlen(suffix) > 0) {
                        snprintf(newProd, MAX_PROD_LEN, "%s -> %s", newNonTerminal, suffix);
                        strcpy(newProductions[newProdCount++], newProd);
                    }
                }
            } else {
                for (int j = 0; j < altCount; j++) {
                    snprintf(newProductions[newProdCount++], MAX_PROD_LEN, "%s -> %s", lhs, rhsAlternatives[j]);
                }
            }
        } else {
            strcpy(newProductions[newProdCount++], productions[i]);
        }
    }

    printf("After Left Factoring:\n");
    for (int i = 0; i < newProdCount; i++) {
        printf("%s\n", newProductions[i]);
    }
}

int main() {
    char productions[MAX_PROD][MAX_PROD_LEN];
    int numProductions;

    printf("Enter the number of productions: ");
    scanf("%d", &numProductions);
    getchar();

    if (numProductions > MAX_PROD) {
        printf("Too many productions. Maximum allowed is %d.\n", MAX_PROD);
        return 1;
    }

    for (int i = 0; i < numProductions; i++) {
        printf("Enter production %d: ", i + 1);
        fgets(productions[i], MAX_PROD_LEN, stdin);
        productions[i][strcspn(productions[i], "\n")] = '\0';
    }

    leftFactoring(productions, numProductions);

    return 0;
}