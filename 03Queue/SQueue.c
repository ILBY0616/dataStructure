#include "SQueue.h"
#include <stdio.h>

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\03Queue.SQueue.exe
// 1 2 3 4 5 6 7 8 9 10
// Process finished with exit code 0

int main()
{
    int i;
    SQueue queue = NULL;
    initiateSQueue(&queue);
    for (i = 0; i < 10; i++)
    {
        inSQueue(queue, i + 1);
    }
    for (int j = 0; j < i; j++)
    {
        printf("%d ", getSQueue(queue));
        outSQueue(queue);
    }
    destroySQueue(&queue);
    return 0;
}
