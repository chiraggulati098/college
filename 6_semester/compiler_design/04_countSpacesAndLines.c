// WAP to count number of spaces and number of lines
#include <stdio.h>
#include <string.h>

#define MAX_LINES 10
#define MAX_LEN 1000

int calcSpaces(char input[MAX_LINES][MAX_LEN], int lineNum)   {
    int numSpaces = 0;
    for (int j = 0; j < strlen(input[lineNum]); j++)    {
        if (input[lineNum][j] == ' ')   {
            numSpaces += 1;
        }
    }
    return numSpaces;
}

int main() {
    char input[MAX_LINES][MAX_LEN];
    int numLines = 0;
    int numSpaces = 0;
    
    printf("Enter a string: \n");
    
    for (int i = 0; i < MAX_LINES; i++) {
        fgets(input[i], MAX_LEN, stdin);
        
        if (input[i][0] == '\n')    {
            numLines = i;
            break;
        }
        
        numSpaces += calcSpaces(input, i);
    }
    
    printf("You entered:\n");
    for (int i = 0; i < numLines; i++)   {
        printf("%s", input[i]);
    }
    
    printf("Number of lines: %d\n", numLines);
    printf("Number of spaces: %d\n", numSpaces);
    
    printf("\n");

    return 0;
}