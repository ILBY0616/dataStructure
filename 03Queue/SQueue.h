#ifndef SQUEUE_H
#define SQUEUE_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct Queue
{
    int data[100];
    int size, front, rear;
} Queue, *SQueue;

// 开辟顺序队
bool initiateSQueue(SQueue* queue);
// 读队
int getSQueue(SQueue queue);
// 入队
bool inSQueue(SQueue queue, int data);
// 出队
int outSQueue(SQueue queue);
// 销毁顺序队
bool destroySQueue(SQueue* queue);

inline bool initiateSQueue(SQueue* queue)
{
    if (*queue != NULL)
    {
        return false;
    }
    *queue = (SQueue)malloc(sizeof(Queue));
    if (*queue != NULL)
    {
        (*queue)->size = 100;
        (*queue)->front = (*queue)->rear = 0;
    }
    return true;
}

inline int getSQueue(SQueue queue)
{
    if (queue == NULL || queue->front == queue->rear)
    {
        return -1;
    }
    return queue->data[queue->front];
}

inline bool inSQueue(SQueue queue, int data)
{
    if (queue == NULL || (queue->rear + 1) % queue->size == queue->front)
    {
        return false;
    }
    queue->data[queue->rear] = data;
    queue->rear = (queue->rear + 1) % queue->size;
    return true;
}

inline int outSQueue(SQueue queue)
{
    if (queue == NULL || queue->front == queue->rear)
    {
        return -1;
    }
    int data = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->size;
    return data;
}

inline bool destroySQueue(SQueue* queue)
{
    if (*queue == NULL)
    {
        return false;
    }
    free(*queue);
    *queue = NULL;
    return true;
}

#endif
