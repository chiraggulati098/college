#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NON_TERMINALS 100
#define MAX_PROD_RULE_LEN 100

void removeLeftRecursion(char nonTerminals[MAX_NON_TERMINALS], char grammar[numProdRules][MAX_PROD_RULE_LEN], int numProdRules) {
    
}

int main() {
    int nonTerminalNum = 0, numProdRules = 0;   
    char nonTerminals[MAX_NON_TERMINALS];
    
    printf("Enter the number of non terminal states (total): ");
    scanf("%d", &nonTerminalNum);
    
    printf("\nEnter non terminals:\n");
    for (int i = 0; i < nonTerminalNum; i++)    {
        getchar();
        scanf("%c", &nonTerminals[i]);
    }
    
    for (int i = 0; i < nonTerminalNum; i++)    {
        printf("%c\n", nonTerminals[i]);
    }
    
    printf("Enter the number of production rules: ");
    scanf("%d", &numProdRules);
    
    printf("\nEnter production rules:\n");
    char grammar[numProdRules][MAX_PROD_RULE_LEN];
    for (int i = 0; i < numProdRules + 1; i++)  {
        fgets(grammar[i], sizeof(grammar[i]), stdin);
        
    }
    
    for (int i = 0; i < numProdRules + 1; i++)  {
        printf("%s", grammar[i]);
    }
    
    printf("\nProcessing Grammars:\n");
    for (int i = 0; i < numProdRules + 1; i++)  {
        removeLeftRecursion(nonTerminals, grammar[i], numProdRules);
    }

    return 0;
}