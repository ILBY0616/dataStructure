#include <stdio.h>

#define size 100
#define type int

typedef struct Triple
{
    int i, j;
    type data;
} Triple;

typedef struct Matrix
{
    Triple t[size];
    int row, column, length;
} Matrix;

Matrix initiateMatrix(type data[size][size], int row, int column)
{
    Matrix m;
    m.row = row;
    m.column = column;
    m.length = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (data[i][j] != 0)
            {
                m.t[m.length].i = i;
                m.t[m.length].j = j;
                m.t[m.length++].data = data[i][j];
            }
        }
    }
    return m;
}

Matrix transposeMatrix(Matrix m)
{
    Matrix matrix;
    matrix.row = m.column;
    matrix.column = m.row;
    matrix.length = m.length;
    if (m.length > 0)
    {
        int num[m.column];
        int pos[m.column];
        for (int i = 0; i < m.column; i++)
        {
            num[i] = 0;
        }
        for (int i = 0; i < m.length; i++)
        {
            num[m.t[i].j]++;
        }
        pos[0] = 0;
        for (int i = 1; i < m.column; i++)
        {
            pos[i] = pos[i - 1] + num[i - 1];
        }
        for (int i = 0; i < m.length; i++)
        {
            int col = m.t[i].j;
            int index = pos[col];
            matrix.t[index].i = m.t[i].j;
            matrix.t[index].j = m.t[i].i;
            matrix.t[index].data = m.t[i].data;
            pos[col]++;
        }
    }
    return matrix;
}

void printMatrix(Matrix m)
{
    int length = 0;
    for (int i = 0; i < m.row; i++)
    {
        for (int j = 0; j < m.column; j++)
        {
            if (length < m.length && m.t[length].i == i && m.t[length].j == j)
            {
                printf("%d ", m.t[length++].data);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}


int main()
{
    type data[size][size] = {{1, 2, 3}, {4, 5, 6}};
    Matrix m = initiateMatrix(data, 2, 3);
    printMatrix(m);
    m = transposeMatrix(m);
    printMatrix(m);
    return 0;
}
