#include <SQueue.h>
#include <stdio.h>

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\03Queue.SQueue.exe
// 1 2 3 4 5 6 7 8 9 10
// Process finished with exit code 0

int main()
{
    int i, data;
    SQueue queue = NULL;
    initiateSQueue(&queue);
    for (i = 0; i < 10; i++)
    {
        data = i + 1;
        inSQueue(queue, data);
    }
    for (int j = 0; j < i; j++)
    {
        getSQueue(queue, &data);
        printf("%d ", data);
        outSQueue(queue, &data);
    }
    destroySQueue(&queue);
    return 0;
}
