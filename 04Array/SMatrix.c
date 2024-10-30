#include <stdbool.h>
#include <stdio.h>

#define type int
#define size 10

typedef struct Triple
{
    type data;
    int row, column;
} Triple;

typedef struct Matrix
{
    Triple data[size];
    int row, column, length;
} Matrix;

// 创建稀疏矩阵
Matrix initiateMatrix(type data[size][size], int row, int column);
// 转置稀疏矩阵
Matrix transposeMatrix(Matrix matrix);
// 打印稀疏矩阵
void printMatrix(Matrix matrix);

int main()
{
    type data[size][size] = {{1, 2, 3}, {4, 5, 6}};
    Matrix matrix = initiateMatrix(data, 2, 3);
    printMatrix(matrix);
    matrix = transposeMatrix(matrix);
    printMatrix(matrix);
    return 0;
}

Matrix initiateMatrix(type data[size][size], int row, int column)
{
    Matrix matrix;
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

Matrix transposeMatrix(Matrix matrix)
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

void printMatrix(Matrix matrix)
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
