#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define type int

typedef struct Node
{
    type data;
    struct Node* next;
} Node;

typedef struct Queue
{
    Node *front, *rear;
} Queue, *LQueue;

bool initiateLQueue(LQueue* queue);
type getLQueue(LQueue queue);
bool inLQueue(LQueue queue, type data);
type outLQueue(LQueue queue);
bool destroyLQueue(LQueue* queue);

int main()
{
    int i = 0;
    type data[10];
    LQueue queue = NULL;
    initiateLQueue(&queue);
    while (scanf("%d ", &data[i]) == 1)
    {
        inLQueue(queue, data[i]);
        i++;
    }
    for (int j = 0; j < i; j++)
    {
        data[j] = outLQueue(queue);
        printf("%d ", data[j]);
    }
    destroyLQueue(&queue);
    return 0;
}

bool initiateLQueue(LQueue* queue)
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

type getLQueue(LQueue queue)
{
    if (queue == NULL || queue->front == NULL)
    {
        return -1;
    }
    return queue->front->data;
}

bool inLQueue(LQueue queue, type data)
{
    if (queue == NULL)
    {
        return false;
    }
    Node* node = malloc(sizeof(Node));
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

type outLQueue(LQueue queue)
{
    if (queue == NULL || queue->front == NULL)
    {
        return -1;
    }
    type data = queue->front->data;
    Node* node = queue->front;
    queue->front = queue->front->next;
    free(node);
    return data;
}

bool destroyLQueue(LQueue* queue)
{
    if (*queue == NULL || (*queue)->front == NULL || (*queue)->rear == NULL)
    {
        return false;
    }
    while ((*queue)->front != NULL)
    {
        Node* node = (*queue)->front;
        (*queue)->front = (*queue)->front->next;
        free(node);
    }
    (*queue)->rear = NULL;
    free(queue);
    *queue = NULL;
    return true;
}
