#ifndef DMATRIX_H
#define DMATRIX_H

#include <stdio.h>

// 稠密矩阵
typedef struct DMatrix
{
    int data[100];
    int row, column, length;
} DMatrix;

// 创建稠密矩阵
DMatrix createDMatrix(int data[100][100], int row, int column);
// 相乘稠密矩阵
void multiplyDMatrix(DMatrix leftMatrix, DMatrix rightMatrix, int finalMatrix[100][100]);
// 打印稠密矩阵
void printDMatrix(DMatrix matrix);

inline DMatrix createDMatrix(int data[100][100], int row, int column)
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
                int leftIndex = i >= k ? (1 + i) * i / 2 + k : (1 + k) * k / 2 + i;
                // right[k][j]索引
                int rightIndex = k >= j ? (1 + k) * k / 2 + j : (1 + j) * j / 2 + k;
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
            int k = i >= j ? (1 + i) * i / 2 + j : (1 + j) * j / 2 + i;
            printf("%d ", matrix.data[k]);
        }
        printf("\n");
    }
}

#endif
