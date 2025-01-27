#include <stdio.h>

int main()  {
    int rows, cols;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int arr1[rows][cols], arr2[rows][cols];

    printf("\nEnter elements of Matrix 1:\n");
    for (int i = 0; i < rows; i++)  {
        for (int j = 0; j < cols; j++)  {
            scanf("%d", &arr1[i][j]);
        }
    }

    printf("\nEnter elements of Matrix 2:\n");
    for (int i = 0; i < rows; i++)  {
        for (int j = 0; j < cols; j++)  {
            scanf("%d", &arr2[i][j]);
        }
    }

    printf("\nMatrix 1:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d  ", arr1[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix 2:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d  ", arr2[i][j]);
        }
        printf("\n");
    }

    printf("\nSum of Matrices:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d  ", arr1[i][j] + arr2[i][j]);
        }
        printf("\n");
    }

    return 0;
}