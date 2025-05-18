#include <stdio.h>
#include <string.h>
#define MAX_CODE 10000

void remove_spaces_comments(char *code, char *result) {
    int i = 0, j = 0;
    int in_single_quote = 0, in_double_quote = 0;
    int in_single_comment = 0, in_multi_comment = 0;
    while (code[i] != '\0') {
        if (!in_single_quote && !in_double_quote && !in_multi_comment && code[i] == '/' && code[i + 1] == '/') {
            in_single_comment = 1;
            i += 2;
            continue;
        }
        if (in_single_comment && code[i] == '\n') {
            in_single_comment = 0;
            i++;
            continue;
        }
        if (!in_single_quote && !in_double_quote && !in_single_comment && code[i] == '/' && code[i + 1] == '*') {
            in_multi_comment = 1;
            i += 2;
            continue;
        }
        if (in_multi_comment && code[i] == '*' && code[i + 1] == '/') {
            in_multi_comment = 0;
            i += 2;
            continue;
        }
        if (!in_single_comment && !in_multi_comment) {
            if (code[i] == '\'' && !in_double_quote) {
                in_single_quote = !in_single_quote;
            }
            else if (code[i] == '\"' && !in_single_quote) {
                in_double_quote = !in_double_quote;
            }
        }
        if (!in_single_comment && !in_multi_comment) {
            if (in_single_quote || in_double_quote) {
                result[j++] = code[i];
            }
            else if (code[i] != ' ' && code[i] != '\t' && code[i] != '\n') {
                result[j++] = code[i];
            }
        }
        i++;
    }
    result[j] = '\0';
}

int main() {
    char code[MAX_CODE], result[MAX_CODE], line[1000];
    int code_idx = 0;
    printf("Enter the source code (empty line to stop):\n");
    while (fgets(line, sizeof(line), stdin)) {
        line[strcspn(line, "\n")] = '\0';
        if (strlen(line) == 0) {
            break;
        }
        if (code_idx + strlen(line) + 1 < MAX_CODE) {
            strcpy(code + code_idx, line);
            code_idx += strlen(line);
            code[code_idx++] = '\n';
        }
    }
    code[code_idx] = '\0';
    remove_spaces_comments(code, result);
    printf("\nCode after removing spaces, tabs, and comments:\n%s\n", result);
    return 0;
}