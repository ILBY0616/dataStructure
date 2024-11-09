typedef struct CQueue
{
    int data[10];
    int size, front, count;
} CQueue;

void inCQueue(CQueue queue, int data);
int outCqueue(CQueue queue);

int main()
{
    CQueue queue;
    queue.size = 10;
    queue.front = 0;
    queue.count = 0;
    return 0;
}

void inCQueue(CQueue queue, int data)
{
    if (queue.count < queue.size - 1)
    {
        int rear = (queue.front + queue.count + 1) % queue.size;
        queue.data[rear] = data;
    }
}

int outCqueue(CQueue queue)
{
    if (queue.count > 0)
    {
        queue.count--;
        return queue.data[++queue.front];
    }
}
