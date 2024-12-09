#include <SMatrix.h>

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\04Array.SMatrix.exe
// 1 2 3
// 4 5 6
// 1 4
// 2 5
// 3 6
// 1 2 3
// 4 5 6
//
// Process finished with exit code 0

int main()
{
    int data[100][100] = {{1, 2, 3}, {4, 5, 6}};
    SMatrix matrix = createSMatrix(data, 2, 3);
    printSMatrix(matrix);
    matrix = easyTranspose(matrix);
    printSMatrix(matrix);
    matrix = quickTranspose(matrix);
    printSMatrix(matrix);
    return 0;
}
