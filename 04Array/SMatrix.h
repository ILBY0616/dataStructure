#ifndef SMATRIX_H
#define SMATRIX_H

#include <stdbool.h>
#include <stdio.h>

// 三元组表
typedef struct Triple
{
    int data;
    int row, column;
} Triple;

// 稀疏矩阵
typedef struct Matrix
{
    Triple data[100];
    int row, column, length;
} Matrix, SMatrix;

// 创建稀疏矩阵
SMatrix initiateSMatrix(int data[100][100], int row, int column);
// 简单转置矩阵
SMatrix easyTranspose(SMatrix matrix);
// 快速转置矩阵
SMatrix quickTranspose(SMatrix matrix);
// 打印稀疏矩阵
void printSMatrix(SMatrix matrix);

inline SMatrix initiateSMatrix(int data[100][100], int row, int column)
{
    SMatrix matrix;
    matrix.row = row;
    matrix.column = column;
    matrix.length = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (data[i][j] != 0)
            {
                matrix.data[matrix.length].row = i;
                matrix.data[matrix.length].column = j;
                matrix.data[matrix.length++].data = data[i][j];
            }
        }
    }
    return matrix;
}

inline SMatrix easyTranspose(SMatrix matrix)
{
    // 空值处理
    if (matrix.length == 0)
    {
        return matrix;
    }
    // 按列排序
    for (int i = 0; i < matrix.length; i++)
    {
        for (int j = 0; j < matrix.length - i - 1; j++)
        {
            if (matrix.data[j].column > matrix.data[j + 1].column)
            {
                Triple triple = matrix.data[j];
                matrix.data[j] = matrix.data[j + 1];
                matrix.data[j + 1] = triple;
            }
        }
    }
    // 行列互换
    for (int k = 0; k < matrix.length; k++)
    {
        int index = matrix.data[k].row;
        matrix.data[k].row = matrix.data[k].column;
        matrix.data[k].column = index;
    }
    int scale = matrix.row;
    matrix.row = matrix.column;
    matrix.column = scale;
    return matrix;
}

inline SMatrix quickTranspose(SMatrix matrix)
{
    if (matrix.length == 0)
    {
        return matrix;
    }
    SMatrix transposeMatrix;
    transposeMatrix.row = matrix.column;
    transposeMatrix.column = matrix.row;
    transposeMatrix.length = matrix.length;
    int zeroSum[matrix.column];
    int firstIndex[matrix.column];
    for (int i = 0; i < matrix.column; i++)
    {
        zeroSum[i] = 0;
        firstIndex[i] = -1;
    }
    for (int i = 0; i < matrix.length; i++)
    {
        zeroSum[matrix.data[i].column]++;
    }
    firstIndex[0] = 0;
    for (int i = 1; i < matrix.column; i++)
    {
        firstIndex[i] = firstIndex[i - 1] + zeroSum[i - 1];
    }
    for (int i = 0; i < matrix.length; i++)
    {
        int column = matrix.data[i].column;
        int index = firstIndex[column];
        transposeMatrix.data[index].row = matrix.data[i].column;
        transposeMatrix.data[index].column = matrix.data[i].row;
        transposeMatrix.data[index].data = matrix.data[i].data;
        firstIndex[column]++;
    }
    return transposeMatrix;
}

inline void printSMatrix(SMatrix matrix)
{
    for (int i = 0; i < matrix.row; i++)
    {
        for (int j = 0; j < matrix.column; j++)
        {
            bool flag = false;
            for (int k = 0; k < matrix.length; k++)
            {
                if (matrix.data[k].row == i && matrix.data[k].column == j)
                {
                    printf("%d ", matrix.data[k].data);
                    flag = true;
                    break;
                }
            }
            if (flag == false)
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

#endif
