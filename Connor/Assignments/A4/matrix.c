#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

// none of these functions below should alter the original matrix.
// assume that the allocation of memory will never fail. (yeah right)

int **transpose(int ** mat, int sizeRow, int sizeCol)
{
    // here, we want to first figure out how many columns we have, then assign each of those rows in a column an amount they can hold
    int ** ptr = malloc(sizeof(int *) * sizeCol);
    for (int i = 0; i < sizeCol; i++)
    {
        *(ptr + i) = malloc(sizeof(int) * sizeRow);
        for (int j = 0; j < sizeRow; j++)
        {
           *(*(ptr + i) + j) = *(*(mat + j) + i);
        }
    }

    return ptr;
}

int *sumRows(int ** mat, int sizeRow, int sizeCol)
{
    int * ptr = malloc(sizeRow * sizeof(int));
    int sum = 0;

    for (int i = 0; i < sizeRow; i++)
    {
        for (int j = 0; j < sizeCol; j++)
        {
            sum += mat[i][j];
        }
        ptr[i] = sum;
        sum = 0;
    }
    return ptr;
}

int outlierRow(int ** mat, int sizeRow, int sizeCol, int num)
{
    int difference = -1;
    int outlierIndex = 0;
    int * rowSums = sumRows(mat, sizeRow, sizeCol);

    for (int i = 0; i < sizeRow; i++)
    {
        int curr = abs(rowSums[i] - num);
        if (curr > difference) 
        {
            difference = curr;
            outlierIndex = i;
        }
    }
    free(rowSums);
    return outlierIndex;
}

int **multiplyScalar(int ** mat, int sizeRow, int sizeCol, int scale) 
{
   int **ptr = malloc(sizeof(int *) * sizeRow);
   for (int i = 0; i < sizeRow; i++)
   {
        *(ptr + i) = malloc(sizeof(int) * sizeCol);
   }

   for (int i = 0; i < sizeRow; i++)
   {
       for (int j = 0; j < sizeCol; j++)
       {
           *(*(ptr + i) + j) = *(*(mat + i) + j) * scale;
       }
   }

   return ptr;
}

int **subMatrix(int ** mat, int sizeRow, int sizeCol, int row, int col)
{
    int ** ptr = NULL;
    if (row > sizeRow || col > sizeCol)
    {
        return ptr; 
    }
    ptr = malloc(sizeof(int *) * row);
    for (int i = 0; i < row ; i++)
    {
        *(ptr + i) = malloc(sizeof(int) * col);
    }
    
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            *(*(ptr + i) + j) = *(*(mat + i) + j);
        }
    }
    return ptr;
}

int **subMatrixScalar(int ** mat, int sizeRow, int sizeCol, int row, int col, int scale)
{
    int **ptr = subMatrix(mat, sizeRow, sizeCol, row, col);
    if (ptr == NULL)
    {
        return NULL;
    }

    return multiplyScalar(ptr, row, col, scale);
}

int **resize(int **mat, int sizeRow, int sizeCol, int row, int col, int def)
{
    if (sizeRow > row || sizeCol > col)
    {
        return NULL;
    }

    int **ptr = malloc(sizeof(int *) * row);
    if (ptr == NULL) 
    {
        return NULL;
    }

    for (int i = 0; i < row; i++)
    {
        ptr[i] = malloc(sizeof(int) * col);
        if (ptr[i] == NULL) 
        {
            for (int j = 0; j < i; j++)
            {
                free(ptr[j]);
            }
            free(ptr);
            return NULL;
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i < sizeRow && j < sizeCol)
            {
                ptr[i][j] = mat[i][j]; 
            }
            else
            {
                ptr[i][j] = def; 
            }
        }
    }

    return ptr;
}

