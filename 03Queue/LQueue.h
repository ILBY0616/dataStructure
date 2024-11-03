#ifndef LQUEUE_H
#define LQUEUE_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct QueueNode
{
    int data;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue
{
    QueueNode *front, *rear;
} Queue, *LQueue;

// 开辟链队
bool initiateLQueue(LQueue* queue);
// 读队
int getLQueue(LQueue queue);
// 入队
bool inLQueue(LQueue queue, int data);
// 出队
int outLQueue(LQueue queue);
// 销毁链队
bool destroyLQueue(LQueue* queue);

inline bool initiateLQueue(LQueue* queue)
{
    if (*queue != NULL)
    {
        return false;
    }
    *queue = (LQueue)malloc(sizeof(Queue));
    if (*queue != NULL)
    {
        (*queue)->front = NULL;
        (*queue)->rear = NULL;
    }
    return true;
}

inline int getLQueue(LQueue queue)
{
    if (queue == NULL || queue->front == NULL)
    {
        return -1;
    }
    return queue->front->data;
}

inline bool inLQueue(LQueue queue, int data)
{
    if (queue == NULL)
    {
        return false;
    }
    QueueNode* node = malloc(sizeof(QueueNode));
    if (node != NULL)
    {
        node->data = data;
        node->next = NULL;
        if (queue->front == NULL)
        {
            queue->front = node;
            queue->rear = node;
        }
        else
        {
            queue->rear->next = node;
            queue->rear = node;
        }
    }
    return true;
}

inline int outLQueue(LQueue queue)
{
    if (queue == NULL || queue->front == NULL)
    {
        return -1;
    }
    int data = queue->front->data;
    QueueNode* node = queue->front;
    queue->front = queue->front->next;
    free(node);
    return data;
}

inline bool destroyLQueue(LQueue* queue)
{
    if (*queue == NULL || (*queue)->front == NULL || (*queue)->rear == NULL)
    {
        return false;
    }
    while ((*queue)->front != NULL)
    {
        QueueNode* node = (*queue)->front;
        (*queue)->front = (*queue)->front->next;
        free(node);
    }
    (*queue)->rear = NULL;
    free(queue);
    *queue = NULL;
    return true;
}

#endif
