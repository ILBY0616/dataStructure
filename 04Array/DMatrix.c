#include <DMatrix.h>

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\04Array.DMatrix.exe
// 1 0 1
// 0 2 0
// 1 0 0
// 1 0 0
// 0 2 0
// 0 0 3
// 1 0 3
// 0 4 0
// 1 0 0
//
// Process finished with exit code 0

int main()
{
    int row = 3, column = 3;
    int leftArray[100][100] = {{1, 0, 1}, {0, 2, 0}, {1, 0, 0}};
    int rightArray[100][100] = {{1, 0, 0}, {0, 2, 0}, {0, 0, 3}};
    int finalArray[100][100];
    // 压缩对称矩阵
    DMatrix leftMatrix = initiateDMatrix(leftArray, row, column);
    DMatrix rightMatrix = initiateDMatrix(rightArray, row, column);
    // 打印对称矩阵
    printDMatrix(leftMatrix);
    printDMatrix(rightMatrix);
    // 对称矩阵相乘
    multiplyDMatrix(leftMatrix, rightMatrix, finalArray);
    // 打印矩阵乘积
    for (int i = 0; i < leftMatrix.row; i++)
    {
        for (int j = 0; j < rightMatrix.column; j++)
        {
            printf("%d ", finalArray[i][j]);
        }
        printf("\n");
    }
    return 0;
}
