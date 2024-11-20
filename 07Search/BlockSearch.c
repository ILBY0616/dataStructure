#include <stdio.h>

// 分块查找
int blockSearch(int data[], int key, int blockSize, int length);

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\07Search.BlockSearch.exe
// 5
// Process finished with exit code 0

int main()
{
    int data[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    printf("%d", blockSearch(data, 5, 3, 10));
    return 0;
}

int blockSearch(int data[], int key, int blockSize, int length)
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
