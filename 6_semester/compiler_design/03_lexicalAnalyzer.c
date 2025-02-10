#include <stdio.h>
#include<string.h>
#include <ctype.h>

int main()  {
    char inputString[100];
    printf("Enter string for Lexical Analyzer: ");
    fflush(stdout);
    fgets(inputString, 100, stdin);
    fflush(stdin);

    printf("Let's Analyse %s\n", inputString);
    fflush(stdout);
    int identifierCount = 0, numberCount = 0;
    char buffer;
    
    for (int i = 0; i < strlen(inputString); i++) {
        buffer = inputString[i];
        if (buffer == ' ' || buffer == '\0')  {
            continue;
        }
        
        if (isdigit(buffer))    {
            numberCount ++;
            printf("%c is a number\n", buffer);
            fflush(stdout);
        }
        else if (isalpha(buffer))   {
            identifierCount ++;
            printf("%c is an identifier\n", buffer);
            fflush(stdout);
        }
        else if (buffer == '+' || buffer == '-' || buffer == '/' || buffer == '*' || buffer == '=')    {
            printf("%c is an operator\n", buffer);
            fflush(stdout);
        }
    }

    printf("\n");
    printf("Total identifiers: %d\n", identifierCount);
    fflush(stdout);
    printf("Total numbers: %d", numberCount);
    fflush(stdout);

    printf("\n");
}