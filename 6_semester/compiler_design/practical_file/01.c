#include <stdio.h>
#include <ctype.h>
#include <string.h>

const char *keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do", "double",
    "else", "enum", "extern", "float", "for", "goto", "if", "int", "long",
    "register", "return", "short", "signed", "sizeof", "static", "struct",
    "switch", "typedef", "union", "unsigned", "void", "volatile", "while",
    NULL
};

const char *operators[] = {
    "+", "-", "*", "/", "%", "++", "--", "==", "!=", ">=", "<=", ">", "<",
    "=", "+=", "-=", "*=", "/=", "&&", "||", "!", "&", "|", "^", "~", "<<", ">>",
    NULL
};

const char symbols[] = ";(){}[],.:";

int is_keyword(const char *token) {
    for (int i = 0; keywords[i] != NULL; i++) {
        if (strcmp(token, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int is_operator(const char *token) {
    for (int i = 0; operators[i] != NULL; i++) {
        if (strcmp(token, operators[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int is_symbol(char c) {
    for (int i = 0; symbols[i] != '\0'; i++) {
        if (c == symbols[i]) {
            return 1;
        }
    }
    return 0;
}

int is_number(const char *token) {
    for (int i = 0; token[i] != '\0'; i++) {
        if (!isdigit(token[i])) {
            return 0;
        }
    }
    return token[0] != '\0';
}

void identify_tokens(const char *code) {
    printf("Tokens found:\n\n");
    int len = strlen(code);
    char token[100];
    int token_idx = 0;

    for (int i = 0; i < len; i++) {
        if (isspace(code[i])) {
            continue;
        }

        token_idx = 0;
        if (isalpha(code[i]) || code[i] == '_') {
            while (i < len && (isalnum(code[i]) || code[i] == '_')) {
                token[token_idx++] = code[i++];
            }
            token[token_idx] = '\0';
            i--;
            if (is_keyword(token)) {
                printf("%s : Keyword\n", token);
            } else {
                printf("%s : Identifier\n", token);
            }
        }
        else if (isdigit(code[i])) {
            while (i < len && isdigit(code[i])) {
                token[token_idx++] = code[i++];
            }
            token[token_idx] = '\0';
            i--;
            printf("%s : Number\n", token);
        }
        else if (ispunct(code[i])) {
            token[0] = code[i];
            token[1] = '\0';
            if (i + 1 < len) {
                token[1] = code[i + 1];
                token[2] = '\0';
                if (is_operator(token)) {
                    printf("%s : Operator\n", token);
                    i++;
                    continue;
                }
                token[1] = '\0';
            }
            if (is_operator(token)) {
                printf("%s : Operator\n", token);
            }
            else if (is_symbol(code[i])) {
                printf("%c : Symbol\n", code[i]);
            }
        }
    }
}

int main() {
    char input_code[1000];
    printf("Enter the C code:\n");
    if (fgets(input_code, sizeof(input_code), stdin) != NULL) {
        input_code[strcspn(input_code, "\n")] = '\0'; 
        identify_tokens(input_code);
    }
    return 0;
}