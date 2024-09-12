#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define size 10
#define type int

typedef struct Queue
{
    type data[size];
    int front, rear;
} Queue;

typedef Queue* SQueue;

SQueue initiateQueue(SQueue q)
{
    q = (SQueue)malloc(sizeof(Queue));
    if (q != NULL)
    {
        q->front = q->rear = 0;
    }
    return q;
}

type getFront(SQueue q)
{
    if (q == NULL || q->front == q->rear)
    {
        return -1;
    }
    return q->data[q->front];
}

bool inQueue(SQueue q, type data)
{
    if (q == NULL || (q->rear + 1) % size == q->front)
    {
        return false;
    }
    q->data[q->rear] = data;
    q->rear = (q->rear + 1) % size;
    return true;
}

type outQueue(SQueue q)
{
    if (q == NULL || q->front == q->rear)
    {
        return -1;
    }
    type data = q->data[q->front];
    q->front = (q->front + 1) % size;
    return data;
}

void destroyQueue(SQueue q)
{
    free(q);
}

int main()
{
    int i = 0;
    type data[size];
    SQueue q = NULL;
    q = initiateQueue(q);
    while (scanf("%d ", &data[i]) == 1)
    {
        inQueue(q, data[i]);
        i++;
    }
    for (int j = 0; j < i; j++)
    {
        printf("%d ", outQueue(q));
    }
    destroyQueue(q);
    return 0;
}
