#ifndef SQUEUE_H
#define SQUEUE_H

#include <stdbool.h>
#include <stdlib.h>

// 循环队
typedef struct SQueue
{
    int data[100];
    int size, front, rear;
}* SQueue;

// 开辟循环队
bool initiateSQueue(SQueue* queue);
// 读队
bool getSQueue(SQueue queue, int* data);
// 入队
bool inSQueue(SQueue queue, int data);
// 出队
bool outSQueue(SQueue queue, int* data);
// 销毁循环队
void destroySQueue(SQueue* queue);

inline bool initiateSQueue(SQueue* queue)
{
    if (*queue != NULL)
    {
        return false;
    }
    *queue = (SQueue)malloc(sizeof(struct SQueue));
    if (*queue == NULL)
    {
        return false;
    }
    (*queue)->size = 100;
    (*queue)->front = (*queue)->rear = 0;
    return true;
}

inline bool getSQueue(SQueue queue, int* data)
{
    if (queue == NULL || queue->rear == queue->front)
    {
        return false;
    }
    *data = queue->data[queue->front];;
    return true;
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

inline bool outSQueue(SQueue queue, int* data)
{
    if (queue == NULL || queue->rear == queue->front)
    {
        return false;
    }
    *data = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->size;
    return true;
}

inline void destroySQueue(SQueue* queue)
{
    free(*queue);
    *queue = NULL;
}

#endif
