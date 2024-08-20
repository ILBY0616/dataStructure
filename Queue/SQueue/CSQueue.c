#define maxSize 6
#define type int

typedef struct CSQueue
{
    type data[maxSize];
    int front, rear;
} CSQueue;

void initiateQueue(CSQueue* q)
{
    q->front = q->rear = 0;
}

int getStatus(CSQueue* q)
{
    int result;
    if (q->front == q->rear)
    {
        result = -1;
    }
    else if ((q->rear + 1) % maxSize == q->front)
    {
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}

int inQueue(CSQueue* q,type data)
{
    int result;
    if ((q->rear + 1) % maxSize == q->front)
    {
        result = -1;
    }
    else
    {
        q->data[q->rear] = data;
        q->rear = (q->rear + 1) % maxSize;
        result = 0;
    }
    return result;
}

int outQueue(CSQueue* q,type* data)
{
    int result;
    if (q->front == q->rear)
    {
        result = -1;
    }
    else
    {
        *data = q->data[q->front];
        q->front = (q->front + 1) % maxSize;
        result = 0;
    }
    return result;
}

void destroy(CSQueue* q)
{
    q->front = q->rear = 0;
}
