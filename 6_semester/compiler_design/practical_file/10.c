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
    int rhsLengths[MAX_PROD];
};

struct FirstFollowSet {
    char nonTerminal[MAX_SYMBOL_LEN];
    struct Set first;
    struct Set follow;
};

struct ParseTableEntry {
    char terminal[MAX_SYMBOL_LEN];
    char rule[MAX_PROD_LEN];
};

struct Production productions[MAX_PROD];
int prodCount = 0;
struct FirstFollowSet sets[MAX_PROD];
int setCount = 0;
struct ParseTableEntry parseTable[MAX_PROD][MAX_SYMBOLS];
int parseTableCounts[MAX_PROD];

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

void findFirst(const char *symbol, struct Set *result, int isNonTerminal) {
    result->count = 0;
    if (!isNonTerminal) {
        addToSet(result, symbol);
        return;
    }

    int setIndex = findSetIndex(symbol);
    if (setIndex != -1 && sets[setIndex].first.count > 0) {
        *result = sets[setIndex].first;
        return;
    }

    int prodIndex = findProdIndex(symbol);
    if (prodIndex == -1) return;

    for (int i = 0; i < productions[prodIndex].rhsCount; i++) {
        char *rule = productions[prodIndex].rhs[i];
        if (strcmp(rule, "E") == 0) {
            char epsilon[MAX_SYMBOL_LEN] = "E";
            addToSet(result, epsilon);
            continue;
        }

        int j = 0;
        int continueEpsilon = 1;
        while (j < productions[prodIndex].rhsLengths[i] && continueEpsilon) {
            char *symbol = productions[prodIndex].rhs[i] + j * MAX_SYMBOL_LEN;
            struct Set firstOfSymbol;
            findFirst(symbol, &firstOfSymbol, isupper(symbol[0]));
            for (int k = 0; k < firstOfSymbol.count; k++) {
                addToSet(result, firstOfSymbol.symbols[k]);
            }
            if (!hasEpsilon(&firstOfSymbol)) {
                continueEpsilon = 0;
            }
            j++;
        }
        if (continueEpsilon) {
            char epsilon[MAX_SYMBOL_LEN] = "E";
            addToSet(result, epsilon);
        }
    }

    if (setIndex == -1) {
        setIndex = setCount++;
        strcpy(sets[setIndex].nonTerminal, symbol);
    }
    sets[setIndex].first = *result;
}

void computeFirstSets() {
    int changed = 1;
    while (changed) {
        changed = 0;
        for (int i = 0; i < prodCount; i++) {
            char *nonTerminal = productions[i].lhs;
            int setIndex = findSetIndex(nonTerminal);
            if (setIndex == -1) {
                setIndex = setCount++;
                strcpy(sets[setIndex].nonTerminal, nonTerminal);
            }
            struct Set prevFirst = sets[setIndex].first;

            for (int j = 0; j < productions[i].rhsCount; j++) {
                char *rule = productions[i].rhs[j];
                if (strcmp(rule, "E") == 0) {
                    char epsilon[MAX_SYMBOL_LEN] = "E";
                    addToSet(&sets[setIndex].first, epsilon);
                    continue;
                }

                int k = 0;
                int continueEpsilon = 1;
                while (k < productions[i].rhsLengths[j] && continueEpsilon) {
                    char *symbol = productions[i].rhs[j] + k * MAX_SYMBOL_LEN;
                    struct Set firstOfSymbol;
                    findFirst(symbol, &firstOfSymbol, isupper(symbol[0]));
                    for (int m = 0; m < firstOfSymbol.count; m++) {
                        addToSet(&sets[setIndex].first, firstOfSymbol.symbols[m]);
                    }
                    if (!hasEpsilon(&firstOfSymbol)) {
                        continueEpsilon = 0;
                    }
                    k++;
                }
                if (continueEpsilon) {
                    char epsilon[MAX_SYMBOL_LEN] = "E";
                    addToSet(&sets[setIndex].first, epsilon);
                }
            }

            if (sets[setIndex].first.count != prevFirst.count) {
                changed = 1;
            }
        }
    }
}

void findFollow() {
    for (int i = 0; i < setCount; i++) {
        sets[i].follow.count = 0;
    }

    int startIndex = findSetIndex("E");
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
                for (int k = 0; k < productions[i].rhsLengths[j]; k++) {
                    char *symbol = productions[i].rhs[j] + k * MAX_SYMBOL_LEN;
                    if (!isupper(symbol[0])) continue;

                    int ntSetIndex = findSetIndex(symbol);
                    if (ntSetIndex == -1) continue;

                    struct Set firstOfNext;
                    firstOfNext.count = 0;
                    int continueEpsilon = 1;
                    int l = k + 1;
                    while (l < productions[i].rhsLengths[j] && continueEpsilon) {
                        char *nextSymbol = productions[i].rhs[j] + l * MAX_SYMBOL_LEN;
                        struct Set firstOfSymbol;
                        findFirst(nextSymbol, &firstOfSymbol, isupper(nextSymbol[0]));
                        for (int m = 0; m < firstOfSymbol.count; m++) {
                            addToSet(&firstOfNext, firstOfSymbol.symbols[m]);
                        }
                        if (!hasEpsilon(&firstOfSymbol)) {
                            continueEpsilon = 0;
                        }
                        l++;
                    }

                    int oldCount = sets[ntSetIndex].follow.count;
                    for (int m = 0; m < firstOfNext.count; m++) {
                        addToSet(&sets[ntSetIndex].follow, firstOfNext.symbols[m]);
                    }

                    if (continueEpsilon || l == productions[i].rhsLengths[j]) {
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

void buildParseTable() {
    for (int i = 0; i < prodCount; i++) {
        parseTableCounts[i] = 0;
    }

    for (int i = 0; i < prodCount; i++) {
        char *nonTerminal = productions[i].lhs;
        int ntIndex = findSetIndex(nonTerminal);

        for (int j = 0; j < productions[i].rhsCount; j++) {
            struct Set firstOfRule;
            firstOfRule.count = 0;
            int k = 0;
            int continueEpsilon = 1;
            while (k < productions[i].rhsLengths[j] && continueEpsilon) {
                char *symbol = productions[i].rhs[j] + k * MAX_SYMBOL_LEN;
                struct Set firstOfSymbol;
                findFirst(symbol, &firstOfSymbol, isupper(symbol[0]));
                for (int m = 0; m < firstOfSymbol.count; m++) {
                    addToSet(&firstOfRule, firstOfSymbol.symbols[m]);
                }
                if (!hasEpsilon(&firstOfSymbol)) {
                    continueEpsilon = 0;
                }
                k++;
            }
            if (continueEpsilon) {
                char epsilon[MAX_SYMBOL_LEN] = "E";
                addToSet(&firstOfRule, epsilon);
            }

            for (int m = 0; m < firstOfRule.count; m++) {
                if (strcmp(firstOfRule.symbols[m], "E") != 0) {
                    int idx = parseTableCounts[ntIndex]++;
                    strcpy(parseTable[ntIndex][idx].terminal, firstOfRule.symbols[m]);
                    strcpy(parseTable[ntIndex][idx].rule, productions[i].rhs[j]);
                }
            }

            if (hasEpsilon(&firstOfRule)) {
                for (int m = 0; m < sets[ntIndex].follow.count; m++) {
                    int idx = parseTableCounts[ntIndex]++;
                    strcpy(parseTable[ntIndex][idx].terminal, sets[ntIndex].follow.symbols[m]);
                    strcpy(parseTable[ntIndex][idx].rule, productions[i].rhs[j]);
                }
            }
        }
    }
}

int parse(const char *input) {
    char stack[100][MAX_SYMBOL_LEN];
    int stackTop = 0;
    strcpy(stack[stackTop++], "$");
    strcpy(stack[stackTop++], "E");

    int inputIndex = 0;
    while (stackTop > 0) {
        char *top = stack[--stackTop];
        char currentSymbol[MAX_SYMBOL_LEN] = "";
        if (inputIndex < strlen(input)) {
            currentSymbol[0] = input[inputIndex];
            currentSymbol[1] = '\0';
        } else {
            strcpy(currentSymbol, "$");
        }

        if (!isupper(top[0]) && strcmp(top, currentSymbol) == 0) {
            inputIndex++;
        } else if (isupper(top[0])) {
            int ntIndex = findSetIndex(top);
            int found = 0;
            for (int i = 0; i < parseTableCounts[ntIndex]; i++) {
                if (strcmp(parseTable[ntIndex][i].terminal, currentSymbol) == 0) {
                    char *rule = parseTable[ntIndex][i].rule;
                    if (strcmp(rule, "E") != 0) {
                        int len = strlen(rule) / MAX_SYMBOL_LEN;
                        for (int j = len - 1; j >= 0; j--) {
                            char symbol[MAX_SYMBOL_LEN];
                            strncpy(symbol, rule + j * MAX_SYMBOL_LEN, MAX_SYMBOL_LEN);
                            symbol[MAX_SYMBOL_LEN - 1] = '\0';
                            strcpy(stack[stackTop++], symbol);
                        }
                    }
                    found = 1;
                    break;
                }
            }
            if (!found) return 0;
        } else {
            return 0;
        }
    }

    return inputIndex == strlen(input);
}

void initProductions() {
    strcpy(productions[prodCount].lhs, "E");
    strcpy(productions[prodCount].rhs[0], "T");
    strcpy(productions[prodCount].rhs[0] + MAX_SYMBOL_LEN, "E'");
    productions[prodCount].rhsLengths[0] = 2;
    productions[prodCount].rhsCount = 1;
    prodCount++;

    strcpy(productions[prodCount].lhs, "E'");
    strcpy(productions[prodCount].rhs[0], "+");
    strcpy(productions[prodCount].rhs[0] + MAX_SYMBOL_LEN, "T");
    strcpy(productions[prodCount].rhs[0] + 2 * MAX_SYMBOL_LEN, "E'");
    productions[prodCount].rhsLengths[0] = 3;
    strcpy(productions[prodCount].rhs[1], "E");
    productions[prodCount].rhsLengths[1] = 1;
    productions[prodCount].rhsCount = 2;
    prodCount++;

    strcpy(productions[prodCount].lhs, "T");
    strcpy(productions[prodCount].rhs[0], "F");
    strcpy(productions[prodCount].rhs[0] + MAX_SYMBOL_LEN, "T'");
    productions[prodCount].rhsLengths[0] = 2;
    productions[prodCount].rhsCount = 1;
    prodCount++;

    strcpy(productions[prodCount].lhs, "T'");
    strcpy(productions[prodCount].rhs[0], "*");
    strcpy(productions[prodCount].rhs[0] + MAX_SYMBOL_LEN, "F");
    strcpy(productions[prodCount].rhs[0] + 2 * MAX_SYMBOL_LEN, "T'");
    productions[prodCount].rhsLengths[0] = 3;
    strcpy(productions[prodCount].rhs[1], "E");
    productions[prodCount].rhsLengths[1] = 1;
    productions[prodCount].rhsCount = 2;
    prodCount++;

    strcpy(productions[prodCount].lhs, "F");
    strcpy(productions[prodCount].rhs[0], "id");
    productions[prodCount].rhsLengths[0] = 1;
    strcpy(productions[prodCount].rhs[1], "(");
    strcpy(productions[prodCount].rhs[1] + MAX_SYMBOL_LEN, "E");
    strcpy(productions[prodCount].rhs[1] + 2 * MAX_SYMBOL_LEN, ")");
    productions[prodCount].rhsLengths[1] = 3;
    productions[prodCount].rhsCount = 2;
    prodCount++;
}

int main() {
    initProductions();
    computeFirstSets();
    findFollow();
    buildParseTable();

    char input[100];
    printf("Enter input string: ");
    scanf("%s", input);

    if (parse(input)) {
        printf("Input string is accepted by the LL(1) parser.\n");
    } else {
        printf("Input string is not accepted by the LL(1) parser.\n");
    }

    return 0;
}