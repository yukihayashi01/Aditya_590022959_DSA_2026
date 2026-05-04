//Implement 2x2D array and perform sum and difference between each of them
//Aditya Venkatesh
//SAP :- 590022959
//Batch :- B40



#include <stdio.h>
#include <stdlib.h>
int** allocateMatrix(int r, int c) 
{
    int **matrix = (int **)malloc(r * sizeof(int *));
    for (int i = 0; i < r; i++) 
    {
        matrix[i] = (int *)malloc(c * sizeof(int));
    }
    return matrix;
}

void freeMatrix(int **matrix, int r) 
{
    for (int i = 0; i < r; i++) 
    {
        free(matrix[i]);
    }
    free(matrix);
}

int main() 
{
    int r, c;
    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);
    
    int **A = allocateMatrix(r, c);
    int **B = allocateMatrix(r, c);
    int **Sum = allocateMatrix(r, c);
    int **Diff = allocateMatrix(r, c);
    
    printf("\nEnter elements of Matrix A:\n");
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            scanf("%d", &A[i][j]);
            
    printf("\nEnter elements of Matrix B:\n");
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            scanf("%d", &B[i][j]);

    for(int i=0; i<r; i++) 
    {
        for(int j=0; j<c; j++) 
        {
            Sum[i][j] = A[i][j] + B[i][j];
            Diff[i][j] = A[i][j] - B[i][j];
        }
    }

    printf("\n--- Resulting Sum Matrix ---\n");
    for(int i=0; i<r; i++) 
    {
        for(int j=0; j<c; j++) printf("%d ", Sum[i][j]);
        printf("\n");
    }

    printf("\n--- Resulting Difference Matrix ---\n");
    for(int i=0; i<r; i++) 
    {
        for(int j=0; j<c; j++) printf("%d ", Diff[i][j]);
        printf("\n");
    }
    freeMatrix(A, r);
    freeMatrix(B, r);
    freeMatrix(Sum, r);
    freeMatrix(Diff, r);

    return 0;
}

