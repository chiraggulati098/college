// WAP to identify keywords
#include <stdio.h>
#include <string.h>

int main()  {
    char input[100];
    printf("Enter a string: ");
    fgets(input, 100, stdin);
    printf("Entered input: %s\n", input);

    int n = strlen(input);

    char keywordList[32][9] = {"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};

    char c[2];
    c[1] = '\0';

    char buffer[20] = "";
    for (int i = 0; i < n; i++) {
        if (input[i] == ' ' || i == n - 1)    {
            for (int j = 0; j < 32; j++)    {
                if (strcmp(buffer, keywordList[j]) == 0) {
                    printf("%s\n", buffer);
                    break;
                }
            }

            strcpy(buffer, "");
        }   else    {
            c[0] = input[i];
            strcat(buffer, c);
        }
    }

    return 0;
}
