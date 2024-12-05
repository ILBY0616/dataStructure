#ifndef DMATRIX_H
#define DMATRIX_H

#include <stdio.h>

// 压缩矩阵
typedef struct DMatrix
{
    int data[100];
    int row, column, length;
} DMatrix;

// 创建压缩矩阵
DMatrix initiateDMatrix(int data[100][100], int row, int column);
// 相乘压缩矩阵
void multiplyDMatrix(DMatrix leftMatrix, DMatrix rightMatrix, int finalMatrix[100][100]);
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
        // 压缩对称矩阵
        for (int j = 0; j <= i; j++)
        {
            matrix.data[matrix.length++] = data[i][j];
        }
    }
    return matrix;
}

inline void multiplyDMatrix(DMatrix leftMatrix, DMatrix rightMatrix, int finalMatrix[100][100])
{
    for (int i = 0; i < leftMatrix.row; i++)
    {
        for (int j = 0; j < rightMatrix.column; j++)
        {
            finalMatrix[i][j] = 0;
            for (int k = 0; k < leftMatrix.column; k++)
            {
                // left[i][k]索引
                int leftIndex = i >= k ? i * (i + 1) / 2 + k : k * (k + 1) / 2 + i;
                // right[k][j]索引
                int rightIndex = k >= j ? k * (k + 1) / 2 + j : j * (j + 1) / 2 + k;
                // 计算final[i][j]
                finalMatrix[i][j] += leftMatrix.data[leftIndex] * rightMatrix.data[rightIndex];
            }
        }
    }
}

inline void printDMatrix(DMatrix matrix)
{
    for (int i = 0; i < matrix.row; i++)
    {
        for (int j = 0; j < matrix.column; j++)
        {
            int k = i >= j ? (1 + i) * i / 2 + j : (j + 1) * j / 2 + i;
            printf("%d ", matrix.data[k]);
        }
        printf("\n");
    }
}

#endif
