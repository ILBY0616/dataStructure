#ifndef DMATRIX_H
#define DMATRIX_H

#include <stdio.h>

// 稠密矩阵
typedef struct Matrix
{
    int data[100];
    int row, column, length;
} Matrix, DMatrix;

// 创建压缩矩阵
DMatrix initiateDMatrix(int data[100][100], int row, int column);
// 相乘压缩矩阵
void multiplyDMartrix(DMatrix leftFactor, DMatrix rightFactor, int finalProduct[100][100]);
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

inline void multiplyDMartrix(DMatrix leftFactor, DMatrix rightFactor, int finalProduct[100][100])
{
    for (int i = 0; i < leftFactor.row; i++)
    {
        for (int j = 0; j < rightFactor.column; j++)
        {
            // finalProduct[i][j] != finalProduct[j][i];
            finalProduct[i][j] = 0;
            // finalProduct[i][j]等于leftFactor[i]行与rightFactor[j]列的乘积累加
            for (int k = 0; k < leftFactor.column; k++)
            {
                // leftFactor[i][k]索引
                int leftIndex = i >= k ? i * (i + 1) / 2 + k : k * (k + 1) / 2 + i;
                // rightFactor[k][j]索引
                int rightIndex = k >= j ? k * (k + 1) / 2 + j : j * (j + 1) / 2 + k;
                // 计算finalProduct[i][j]
                finalProduct[i][j] += leftFactor.data[leftIndex] * rightFactor.data[rightIndex];
            }
        }
    }
}

inline void printDMatrix(DMatrix matrix)
{
    for (int i = 0; i < matrix.length; i++)
    {
        printf("%d ", matrix.data[i]);
    }
    printf("\n");
    for (int i = 0; i < matrix.row; i++)
    {
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
        printf("\n");
    }
}

#endif
