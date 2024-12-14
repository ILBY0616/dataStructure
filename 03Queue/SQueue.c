#include <SQueue.h>
#include <stdio.h>

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
