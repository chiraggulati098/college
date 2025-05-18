#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PROD 100
#define MAX_PROD_LEN 100
#define MAX_SYMBOLS 50
#define MAX_SYMBOL_LEN 10

struct Set {
    char symbols[MAX_SYMBOLS][MAX_SYMBOL_LEN];
    int count;
};

struct Production {
    char lhs[MAX_SYMBOL_LEN];
    char rhs[MAX_PROD][MAX_PROD_LEN];
    int rhsCount;
};

struct FirstFollowSet {
    char nonTerminal[MAX_SYMBOL_LEN];
    struct Set first;
    struct Set follow;
};

struct Production productions[MAX_PROD];
int prodCount = 0;
struct FirstFollowSet sets[MAX_PROD];
int setCount = 0;
char startSymbol[MAX_SYMBOL_LEN];

int findSetIndex(const char *nonTerminal) {
    for (int i = 0; i < setCount; i++) {
        if (strcmp(sets[i].nonTerminal, nonTerminal) == 0) {
            return i;
        }
    }
    return -1;
}

int findProdIndex(const char *nonTerminal) {
    for (int i = 0; i < prodCount; i++) {
        if (strcmp(productions[i].lhs, nonTerminal) == 0) {
            return i;
        }
    }
    return -1;
}

void addToSet(struct Set *set, const char *symbol) {
    if (strcmp(symbol, "E") == 0) return;
    for (int i = 0; i < set->count; i++) {
        if (strcmp(set->symbols[i], symbol) == 0) {
            return;
        }
    }
    strcpy(set->symbols[set->count], symbol);
    set->count++;
}

int hasEpsilon(struct Set *set) {
    for (int i = 0; i < set->count; i++) {
        if (strcmp(set->symbols[i], "E") == 0) {
            return 1;
        }
    }
    return 0;
}

void findFirst(const char *nonTerminal, struct Set *result) {
    int setIndex = findSetIndex(nonTerminal);
    if (setIndex != -1 && sets[setIndex].first.count > 0) {
        *result = sets[setIndex].first;
        return;
    }

    result->count = 0;
    int prodIndex = findProdIndex(nonTerminal);
    if (prodIndex == -1) {
        return;
    }

    for (int i = 0; i < productions[prodIndex].rhsCount; i++) {
        char *rule = productions[prodIndex].rhs[i];
        if (strcmp(rule, "E") == 0) {
            char epsilon[MAX_SYMBOL_LEN] = "E";
            addToSet(result, epsilon);
            continue;
        }

        int j = 0;
        int continueEpsilon = 1;
        while (j < strlen(rule) && continueEpsilon) {
            char symbol[MAX_SYMBOL_LEN] = "";
            symbol[0] = rule[j];
            symbol[1] = '\0';

            if (isupper(rule[j])) {
                struct Set firstOfSymbol;
                findFirst(symbol, &firstOfSymbol);
                for (int k = 0; k < firstOfSymbol.count; k++) {
                    addToSet(result, firstOfSymbol.symbols[k]);
                }
                if (!hasEpsilon(&firstOfSymbol)) {
                    continueEpsilon = 0;
                }
            } else {
                addToSet(result, symbol);
                continueEpsilon = 0;
            }
            j++;
        }
        if (continueEpsilon && j == strlen(rule)) {
            char epsilon[MAX_SYMBOL_LEN] = "E";
            addToSet(result, epsilon);
        }
    }

    if (setIndex == -1) {
        setIndex = setCount++;
        strcpy(sets[setIndex].nonTerminal, nonTerminal);
    }
    sets[setIndex].first = *result;
}

void findFollow() {
    for (int i = 0; i < setCount; i++) {
        sets[i].follow.count = 0;
    }

    int startIndex = findSetIndex(startSymbol);
    if (startIndex != -1) {
        addToSet(&sets[startIndex].follow, "$");
    }

    int changed = 1;
    while (changed) {
        changed = 0;
        for (int i = 0; i < prodCount; i++) {
            char *lhs = productions[i].lhs;
            int lhsSetIndex = findSetIndex(lhs);

            for (int j = 0; j < productions[i].rhsCount; j++) {
                char *rhs = productions[i].rhs[j];
                for (int k = 0; k < strlen(rhs); k++) {
                    if (!isupper(rhs[k])) continue;

                    char nonTerminal[MAX_SYMBOL_LEN] = "";
                    nonTerminal[0] = rhs[k];
                    nonTerminal[1] = '\0';
                    int ntSetIndex = findSetIndex(nonTerminal);
                    if (ntSetIndex == -1) continue;

                    struct Set followOfNT = sets[ntSetIndex].follow;

                    int l = k + 1;
                    int continueEpsilon = 1;
                    struct Set firstOfNext;
                    firstOfNext.count = 0;

                    while (l < strlen(rhs) && continueEpsilon) {
                        char symbol[MAX_SYMBOL_LEN] = "";
                        symbol[0] = rhs[l];
                        symbol[1] = '\0';

                        if (isupper(rhs[l])) {
                            struct Set firstOfSymbol;
                            findFirst(symbol, &firstOfSymbol);
                            for (int m = 0; m < firstOfSymbol.count; m++) {
                                addToSet(&firstOfNext, firstOfSymbol.symbols[m]);
                            }
                            if (!hasEpsilon(&firstOfSymbol)) {
                                continueEpsilon = 0;
                            }
                        } else {
                            addToSet(&firstOfNext, symbol);
                            continueEpsilon = 0;
                        }
                        l++;
                    }

                    int oldCount = sets[ntSetIndex].follow.count;
                    for (int m = 0; m < firstOfNext.count; m++) {
                        addToSet(&sets[ntSetIndex].follow, firstOfNext.symbols[m]);
                    }

                    if (continueEpsilon || l == strlen(rhs)) {
                        for (int m = 0; m < sets[lhsSetIndex].follow.count; m++) {
                            addToSet(&sets[ntSetIndex].follow, sets[lhsSetIndex].follow.symbols[m]);
                        }
                    }

                    if (sets[ntSetIndex].follow.count > oldCount) {
                        changed = 1;
                    }
                }
            }
        }
    }
}

int main() {
    int numProductions;
    printf("Enter the number of productions: ");
    scanf("%d", &numProductions);
    getchar();

    for (int i = 0; i < numProductions; i++) {
        char production[MAX_PROD_LEN];
        printf("Enter production %d (e.g., S->Aa|b|E): ", i + 1);
        fgets(production, MAX_PROD_LEN, stdin);
        production[strcspn(production, "\n")] = '\0';

        char *arrowPos = strstr(production, "->");
        if (arrowPos == NULL) {
            continue;
        }

        char lhs[MAX_SYMBOL_LEN];
        strncpy(lhs, production, arrowPos - production);
        lhs[arrowPos - production] = '\0';

        if (i == 0) {
            strcpy(startSymbol, lhs);
        }

        char rhs[MAX_PROD_LEN];
        strcpy(rhs, arrowPos + 2);

        char *token = strtok(rhs, "|");
        int prodIndex = -1;
        for (int j = 0; j < prodCount; j++) {
            if (strcmp(productions[j].lhs, lhs) == 0) {
                prodIndex = j;
                break;
            }
        }
        if (prodIndex == -1) {
            prodIndex = prodCount++;
            strcpy(productions[prodIndex].lhs, lhs);
            productions[prodIndex].rhsCount = 0;
        }
        while (token != NULL) {
            strcpy(productions[prodIndex].rhs[productions[prodIndex].rhsCount], token);
            productions[prodIndex].rhsCount++;
            token = strtok(NULL, "|");
        }
    }

    for (int i = 0; i < prodCount; i++) {
        struct Set result;
        findFirst(productions[i].lhs, &result);
    }

    findFollow();

    printf("\nFollow Sets for the given grammar:\n");
    for (int i = 0; i < setCount; i++) {
        printf("Follow(%s) = { ", sets[i].nonTerminal);
        for (int j = 0; j < sets[i].follow.count; j++) {
            if (j > 0) printf(", ");
            printf("%s", sets[i].follow.symbols[j]);
        }
        printf(" }\n");
    }

    return 0;
}