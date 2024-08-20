#define newSize 5
#define type int
#include <stdlib.h>

typedef struct Node
{
    type data;
    struct Node* next;
} Node;

typedef struct LQueue
{
    Node *front, *rear;
} LQueue;

LQueue* initiateQueue()
{
    LQueue* q = (LQueue*)malloc(sizeof(LQueue));
    q->front = (Node*)malloc(sizeof(Node));
    q->front->next = NULL;
    q->rear = q->front;
    return q;
}

int getStatus(LQueue q)
{
    if (q.front == q.rear)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int inQueue(LQueue* q, type data)
{
    Node* n = (Node*)malloc(sizeof(Node));
    if (n == NULL)
    {
        return -1;
    }
    else
    {
        n->data = data;
        n->next = NULL;
        q->rear->next = n;
        q->rear = n;
        return 0;
    }
}

int outQueue(LQueue* q, type* data)
{
    if (q->front == q->rear)
    {
        return -1;
    }
    else
    {
        Node* p = q->front->next;
        *data = p->data;
        q->front->next = p->next;
        if (q->rear == p)
        {
            q->rear = q->front;
        }
        free(p);
        return 0;
    }
}

void destroyQueue(LQueue* q)
{
    while (q->front->next != NULL)
    {
        Node* p = q->front->next;
        q->front->next = p->next;
        free(p);
    }
    free(q->front);
    free(q);
}
