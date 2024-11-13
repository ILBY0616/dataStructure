#include "LQueue.h"
#include <stdio.h>

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\03Queue.LQueue.exe
// 1 2 3 4 5 6 7 8 9 10
// Process finished with exit code 0

int main()
{
    int i, data;
    LQueue queue = NULL;
    initiateLQueue(&queue);
    for (i = 0; i < 10; i++)
    {
        data = i + 1;
        inLQueue(queue, data);
    }
    for (int j = 0; j < i; j++)
    {
        getLQueue(queue, &data);
        printf("%d ", data);
        outLQueue(queue, &data);
    }
    destroyLQueue(&queue);
    return 0;
}
