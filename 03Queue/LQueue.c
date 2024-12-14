#include <LQueue.h>
#include <stdio.h>

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
