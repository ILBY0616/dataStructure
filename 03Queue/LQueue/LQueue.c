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
} Queue;

typedef Queue* LQueue;

LQueue initiateQueue(LQueue q)
{
    q = (LQueue)malloc(sizeof(Queue));
    if (q != NULL)
    {
        q->front = NULL;
        q->rear = NULL;
    }
    return q;
}

type getFront(LQueue q)
{
    if (q == NULL || q->front == NULL)
    {
        return -1;
    }
    return q->front->data;
}

LQueue inQueue(LQueue q, type data)
{
    if (q == NULL)
    {
        return q;
    }
    Node* node = malloc(sizeof(Node));
    if (node != NULL)
    {
        node->data = data;
        node->next = NULL;
        if (q->front == NULL)
        {
            q->front = node;
            q->rear = node;
        }
        else
        {
            q->rear->next = node;
            q->rear = node;
        }
    }
    return q;
}

LQueue outQueue(LQueue q,type* data)
{
    if (q == NULL || q->front == NULL)
    {
        return q;
    }
    *data = q->front->data;
    Node* node = q->front;
    q->front = q->front->next;
    free(node);
    return q;
}

bool destroyQueue(LQueue q)
{
    if (q == NULL || q->front == NULL || q->rear == NULL)
    {
        return false;
    }
    while (q->front != NULL)
    {
        Node* node = q->front;
        q->front = q->front->next;
        free(node);
    }
    q->rear = NULL;
    free(q);
    return true;
}


int main()
{
    int i = 0;
    type data[10];
    LQueue q = NULL;
    q = initiateQueue(q);
    while (scanf("%d ", &data[i]) == 1)
    {
        inQueue(q, data[i]);
        i++;
    }
    for (int j = 0; j < i; j++)
    {
        q = outQueue(q, &data[j]);
        printf("%d ", data[j]);
    }
    destroyQueue(q);
    return 0;
}
