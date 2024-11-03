#include "LQueue.h"
#include <stdio.h>

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\03Queue.LQueue.exe
// 1 2 3 4 5 6 7 8 9 10
// Process finished with exit code 0

int main()
{
    int i;
    LQueue queue = NULL;
    initiateLQueue(&queue);
    for (i = 0; i < 10; i++)
    {
        inLQueue(queue, i + 1);
    }
    for (int j = 0; j < i; j++)
    {
        printf("%d ", getLQueue(queue));
        outLQueue(queue);
    }
    destroyLQueue(&queue);
    return 0;
}
