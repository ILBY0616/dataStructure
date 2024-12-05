#ifndef LQUEUE_H
#define LQUEUE_H

#include <stdbool.h>
#include <stdlib.h>

// 链队
typedef struct LQueueNode
{
    int data;
    struct LQueueNode* next;
} LQueueNode;

typedef struct LQueue
{
    LQueueNode *front, *rear;
}* LQueue;

// 开辟链队
bool initiateLQueue(LQueue* queue);
// 读队
bool getLQueue(LQueue queue, int* data);
// 入队
bool inLQueue(LQueue queue, int data);
// 出队
bool outLQueue(LQueue queue, int* data);
// 销毁链队
void destroyLQueue(LQueue* queue);

inline bool initiateLQueue(LQueue* queue)
{
    if (*queue != NULL)
    {
        return false;
    }
    *queue = (LQueue)malloc(sizeof(struct LQueue));
    if (*queue == NULL)
    {
        return false;
    }
    (*queue)->front = NULL;
    (*queue)->rear = NULL;
    return true;
}

inline bool getLQueue(LQueue queue, int* data)
{
    if (queue == NULL || queue->front == NULL || queue->rear == NULL)
    {
        return false;
    }
    *data = queue->front->data;
    return true;
}

inline bool inLQueue(LQueue queue, int data)
{
    if (queue == NULL)
    {
        return false;
    }
    LQueueNode* node = malloc(sizeof(LQueueNode));
    if (node == NULL)
    {
        return false;
    }
    node->data = data;
    node->next = NULL;
    if (queue->front == NULL)
    {
        queue->front = node;
    }
    else
    {
        queue->rear->next = node;
    }
    queue->rear = node;
    return true;
}

inline bool outLQueue(LQueue queue, int* data)
{
    if (queue == NULL || queue->front == NULL || queue->rear == NULL)
    {
        return false;
    }
    *data = queue->front->data;
    LQueueNode* node = queue->front;
    queue->front = queue->front->next;
    free(node);
    return true;
}

inline void destroyLQueue(LQueue* queue)
{
    while (*queue != NULL && (*queue)->front != NULL)
    {
        LQueueNode* node = (*queue)->front;
        (*queue)->front = (*queue)->front->next;
        free(node);
    }
    (*queue)->rear = NULL;
    free(*queue);
    *queue = NULL;
}

#endif
