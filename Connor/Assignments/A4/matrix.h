#ifndef MATRIX_H
#define MATRIX_H

int **transpose(int ** mat, int sizeRow, int sizeCol);
int *sumRows(int ** mat, int sizeRow, int sizeCol);
int outlierRow(int ** mat, int sizeRow, int sizeCol, int num);
int **multiplyScalar(int ** mat, int sizeRow, int sizeCol, int scale);
int **subMatrix(int ** mat, int sizeRow, int sizeCol, int row, int col);
int **subMatrixScalar(int ** mat, int sizeRow, int sizeCol, int row, int col, int scale);
int **resize(int ** mat, int sizeRow, int sizeCol, int row, int col, int def);

#endif
