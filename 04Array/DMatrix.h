#ifndef DMATRIX_H
#define DMATRIX_H

#include <stdio.h>

typedef struct Matrix
{
    int data[100];
    int row, column, length;
} Matrix, DMatrix;

// 创建压缩矩阵
DMatrix initiateDMatrix(int data[100][100], int row, int column);
// 打印压缩矩阵
void printDMatrix(DMatrix matrix);

inline DMatrix initiateDMatrix(int data[100][100], int row, int column)
{
    DMatrix matrix;
    matrix.row = row;
    matrix.column = column;
    matrix.length = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            matrix.data[matrix.length++] = data[i][j];
        }
    }
    return matrix;
}

inline void printDMatrix(DMatrix matrix)
{
    for (int i = 0; i < matrix.length; i++)
    {
        printf("%d ", matrix.data[i]);
    }
    for (int i = 0; i < matrix.row; i++)
    {
        printf("\n");
        for (int j = 0; j < matrix.column; j++)
        {
            int k = i >= j ? (1 + i) * i / 2 + j : (j + 1) * j / 2 + i;
            if (k < matrix.length)
            {
                printf("%d ", matrix.data[k]);
            }
            else
            {
                printf("0 ");
            }
        }
    }
}

#endif
