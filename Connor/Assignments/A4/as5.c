#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

void printMatrix(int **mat, int sizeRow, int sizeCol) {
    for (int i = 0; i < sizeRow; i++) {
        for (int j = 0; j < sizeCol; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows = 2, cols = 3;

    int **matrix = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = malloc(cols * sizeof(int));
    }

    matrix[0][0] = 1; matrix[0][1] = 2; matrix[0][2] = 3;
    matrix[1][0] = 4; matrix[1][1] = 5; matrix[1][2] = 6;

    printf("Original Matrix:\n");
    printMatrix(matrix, rows, cols);

    int **transposedMatrix = transpose((int **)matrix, rows, cols);

    printf("Transposed Matrix:\n");
    printMatrix(transposedMatrix, cols, rows);  // The size is swapped for the transposed matrix

    for (int i = 0; i < cols; i++) {
        free(transposedMatrix[i]);
    }
      
    int *rowSums = sumRows(matrix, rows, cols);

    printf("Row sums:\n");
    for (int i = 0; i < rows; i++)
    {
        printf("Sum of row %d: %d\n", i, *(rowSums + i));
    }

    printf("Outlier index: %d\n", outlierRow(matrix, rows, cols, 5));
    int **scaledMatrix = multiplyScalar(matrix, rows, cols, 5);
    printf("Scaled Matrix by 5\n");
    printMatrix(scaledMatrix, rows, cols); 
    
    int **subOfMatrix = subMatrix(matrix, rows, cols, 2, 1);
    printf("subMatrix size of (2,3)\n");
    printMatrix(subOfMatrix, 2, 1);

    int **scaledSubMatrix = subMatrixScalar(matrix, rows, cols, 2, 2, 3);
    printf("SubMatrix Scalar (2x2) multiplied by 3:\n");
    printMatrix(scaledSubMatrix, 2, 2);

    int newRow = 4, newCol = 6, defaultValue = 0;
    int **resizedMat = resize(matrix, rows, cols, newRow, newCol, defaultValue);

    if (resizedMat)
    {
        printf("\nResized Matrix:\n");
        printMatrix(resizedMat, newRow, newCol);

        for (int i = 0; i < newRow; i++)
        {
            free(resizedMat[i]);
        }
        free(resizedMat);
    }
    else
    {
        printf("\nResize failed. New dimensions are too small.\n");
    }

    for (int i = 0; i < rows; i++)
    {
        free(matrix[i]);
        free(scaledMatrix[i]);
    }

    free(matrix);
    free(scaledMatrix);
    free(rowSums);
    free(transposedMatrix);
    free(subOfMatrix);
    free(scaledSubMatrix);
    return 0;
}
