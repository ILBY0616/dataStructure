#define maxSize 10
#define type int

typedef struct SQueue
{
    type data[maxSize];
    int front, rear;
} SQueue;

void initiateQueue(SQueue* q)
{
    q->front = q->rear = 0;
}

int getStatus(SQueue* q)
{
    int result;
    if (q->front == q->rear)
    {
        result = -1;
    }
    else if ((q->rear + 1) == maxSize)
    {
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}

int getHead(SQueue* q,type* data)
{
    int result;
    if (q->front == q->rear)
    {
        result = -1;
    }
    else
    {
        *data = q->data[q->front];
        result = 0;
    }
    return result;
}

int inQueue(SQueue* q,type data)
{
    int result;
    if ((q->rear + 1) == maxSize)
    {
        result = -1;
    }
    else
    {
        q->data[q->rear++] = data;
        result = 0;
    }
    return result;
}

int outQueue(SQueue* q,type* data)
{
    int result;
    if (q->front == q->rear)
    {
        result = -1;
    }
    else
    {
        *data = q->data[q->front++];
        result = 0;
    }
    return result;
}
