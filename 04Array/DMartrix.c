#include "DMatrix.h"

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\04Array.DMartrix.exe
// 1 0 1 0 0 1
// 1 0 0
// 0 1 0
// 0 0 1
// Process finished with exit code 0

int main()
{
    int data[100][100] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    DMatrix matrix = initiateDMatrix(data, 3, 3);
    printDMatrix(matrix);
    return 0;
}
