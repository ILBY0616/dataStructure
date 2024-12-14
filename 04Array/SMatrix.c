#include <SMatrix.h>

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
