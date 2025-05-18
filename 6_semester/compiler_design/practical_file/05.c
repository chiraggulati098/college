#include <stdio.h>
#include <string.h>

#define MAX_SYMBOLS 100
#define MAX_NAME 50
#define MAX_TYPE 20
#define MAX_SCOPE 20

struct Symbol {
    char name[MAX_NAME];
    char type[MAX_TYPE];
    char scope[MAX_SCOPE];
    int lineNumber;
};

struct SymbolTable {
    struct Symbol table[MAX_SYMBOLS];
    int count;
};

void initSymbolTable(struct SymbolTable *symTab) {
    symTab->count = 0;
}

void insert(struct SymbolTable *symTab, const char *name, const char *type, const char *scope, int lineNumber) {
    for (int i = 0; i < symTab->count; i++) {
        if (strcmp(symTab->table[i].name, name) == 0 && strcmp(symTab->table[i].scope, scope) == 0) {
            printf("Error: Identifier '%s' already declared in scope '%s'.\n", name, scope);
            return;
        }
    }

    if (symTab->count < MAX_SYMBOLS) {
        strncpy(symTab->table[symTab->count].name, name, MAX_NAME - 1);
        symTab->table[symTab->count].name[MAX_NAME - 1] = '\0';
        strncpy(symTab->table[symTab->count].type, type, MAX_TYPE - 1);
        symTab->table[symTab->count].type[MAX_TYPE - 1] = '\0';
        strncpy(symTab->table[symTab->count].scope, scope, MAX_SCOPE - 1);
        symTab->table[symTab->count].scope[MAX_SCOPE - 1] = '\0';
        symTab->table[symTab->count].lineNumber = lineNumber;
        printf("Inserted: %s (%s, %s, Line %d)\n", name, type, scope, lineNumber);
        symTab->count++;
    } else {
        printf("Symbol table is full!\n");
    }
}

void display(struct SymbolTable *symTab) {
    printf("\nSymbol Table:\n");
    printf("---------------------------------------------\n");
    printf("Name\tType\tScope\tLine Number\n");
    printf("---------------------------------------------\n");
    for (int i = 0; i < symTab->count; i++) {
        printf("%s\t%s\t%s\t%d\n", symTab->table[i].name, symTab->table[i].type, 
               symTab->table[i].scope, symTab->table[i].lineNumber);
    }
}

int main() {
    struct SymbolTable symTab;
    initSymbolTable(&symTab);
    int choice;

    do {
        printf("\n1. Insert Identifier\n2. Display Symbol Table\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            char name[MAX_NAME], type[MAX_TYPE], scope[MAX_SCOPE];
            int line;

            printf("Enter identifier name: ");
            scanf("%49s", name);
            printf("Enter type (e.g., int, float): ");
            scanf("%19s", type);
            printf("Enter scope (e.g., global, local): ");
            scanf("%19s", scope);
            printf("Enter line number: ");
            scanf("%d", &line);

            insert(&symTab, name, type, scope, line);
        }
        else if (choice == 2) {
            display(&symTab);
        }
        else if (choice != 3) {
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 3);

    return 0;
}