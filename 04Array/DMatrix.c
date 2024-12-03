#include <DMatrix.h>

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\04Array.DMartrix.exe
// 1 0 2 1 0 0
// 1 0 1
// 0 2 0
// 1 0 0
// 1 0 2 0 0 3
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
    int leftData[100][100] = {{1, 0, 1}, {0, 2, 0}, {1, 0, 0}};
    int rightData[100][100] = {{1, 0, 0}, {0, 2, 0}, {0, 0, 3}};
    int finalData[100][100];
    // 压缩矩阵
    DMatrix leftMatrix = initiateDMatrix(leftData, 3, 3);
    DMatrix rightMatrix = initiateDMatrix(rightData, 3, 3);
    // 打印矩阵
    printDMatrix(leftMatrix);
    printDMatrix(rightMatrix);
    // 矩阵相乘
    multiplyDMartrix(leftMatrix, rightMatrix, finalData);
    // 打印乘积
    for (int i = 0; i < leftMatrix.row; i++)
    {
        for (int j = 0; j < rightMatrix.column; j++)
        {
            printf("%d ", finalData[i][j]);
        }
        printf("\n");
    }
    return 0;
}
