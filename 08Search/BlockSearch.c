#include <stdio.h>

// 分块查找
int blockSearch(int* data, int key, int blockSize, int length)
{
    // 向上取整进行分块
    int blockSum = (length + blockSize - 1) / blockSize;
    for (int i = 0; i < blockSum; i++)
    {
        int blockStart = i * blockSize;
        int blockEnd = (i + 1) * blockSize < length ? (i + 1) * blockSize : length;
        // 块外查找
        if (data[blockStart] <= key && key <= data[blockEnd - 1])
        {
            // 块内查找
            for (int j = blockStart; j < blockEnd; j++)
            {
                if (data[j] == key)
                {
                    return j;
                }
            }
            break;
        }
    }
    return -1;
}

int main()
{
    int data[100] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
        30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57,
        58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85,
        86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99
    };
    int key = 5, length = 100, blockSize = 10;
    printf("%d", blockSearch(data, key, blockSize, length));
    return 0;
}
