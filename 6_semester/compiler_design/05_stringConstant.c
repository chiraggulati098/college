// WAP to find the string is constant or not
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 1000

int isInteger(char str[]) {
    for (int i = 0; i < strlen(str); i++)   {
        if ((i == 0) && (str[i] == '-'))  {
            continue;
        }
        
        if (!isdigit(str[i]))   {
            return 0;
        }
    }
    
    return 1;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    
    if (isInteger(str)) {
        printf("The string is a constant.\n");
    } else {
        printf("The string is not a constant.\n");
    }

    return 0;
}