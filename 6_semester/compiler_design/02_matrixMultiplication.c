#include <stdio.h>

int main()  {
    int r1, c1, r2, c2;

    while (1)   {
        printf("Enter number of rows and columns for 1st Matrix: ");
        scanf("%d %d", &r1, &c1);

        printf("Enter number of rows and columns for 2nd Matrix: ");
        scanf("%d %d", &r2, &c2);

        if (c1 == r2)   {
            break;
        }   else    {
            printf("FAILED: Number of columns of 1st Matrix should be equal to number of rows of 2nd Matrix.\n\n");
        }
    }

    int arr1[r1][c1], arr2[r1][c1], mul[r1][c2];

    printf("\nEnter elements of Matrix 1:\n");
    for (int i = 0; i < r1; i++)  {
        for (int j = 0; j < c1; j++)  {
            scanf("%d", &arr1[i][j]);
        }
    }

    printf("\nEnter elements of Matrix 2:\n");
    for (int i = 0; i < r2; i++)  {
        for (int j = 0; j < c2; j++)  {
            scanf("%d", &arr2[i][j]);
        }
    }

    printf("\nMatrix 1:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            printf("%d  ", arr1[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix 2:\n");
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d  ", arr2[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < r1; i++)    {
        for (int j = 0; j < c2; j++)    {
            mul[i][j] = 0;
            for (int k = 0; k < c1; k++)    {
                mul[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    printf("\nMatrix Multiplication Resultant:\n");
    for (int i = 0; i < r1; i++)    {
        for (int j = 0; j < c2; j++)    {
            printf("%d  ", mul[i][j]);
        }
        printf("\n");
    }

    return 0;
}