#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define type int
#define size 10

typedef struct Queue
{
    type data[size];
    int front, rear;
} Queue, *SQueue;

bool initiateSQueue(SQueue* queue);
type getSQueue(SQueue queue);
bool inSQueue(SQueue queue, type data);
type outSQueue(SQueue queue);
bool destroySQueue(SQueue* queue);

int main()
{
    int i = 0;
    type data[size];
    SQueue queue = NULL;
    initiateSQueue(&queue);
    while (scanf("%d ", &data[i]) == 1)
    {
        inSQueue(queue, data[i]);
        i++;
    }
    for (int j = 0; j < i; j++)
    {
        printf("%d ", outSQueue(queue));
    }
    destroySQueue(&queue);
    return 0;
}

bool initiateSQueue(SQueue* queue)
{
    if (*queue != NULL)
    {
        return false;
    }
    *queue = (SQueue)malloc(sizeof(Queue));
    if (*queue != NULL)
    {
        (*queue)->front = (*queue)->rear = 0;
    }
    return true;
}

type getSQueue(SQueue queue)
{
    if (queue == NULL || queue->front == queue->rear)
    {
        return -1;
    }
    return queue->data[queue->front];
}

bool inSQueue(SQueue queue, type data)
{
    if (queue == NULL || (queue->rear + 1) % size == queue->front)
    {
        return false;
    }
    queue->data[queue->rear] = data;
    queue->rear = (queue->rear + 1) % size;
    return true;
}

type outSQueue(SQueue queue)
{
    if (queue == NULL || queue->front == queue->rear)
    {
        return -1;
    }
    type data = queue->data[queue->front];
    queue->front = (queue->front + 1) % size;
    return data;
}

bool destroySQueue(SQueue* queue)
{
    if (*queue == NULL)
    {
        return false;
    }
    free(*queue);
    *queue = NULL;
    return true;
}
