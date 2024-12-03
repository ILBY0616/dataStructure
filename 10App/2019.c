#include <SStack.h>
#include <stdlib.h>
#include <stdio.h>

// 编写循环队列，只有头指针和结点数，实现入队出队函数
typedef struct Queue
{
    int data[10];
    int size, front, count;
}* Queue;

void inQueue(Queue queue, int data)
{
    if (queue->count <= queue->size)
    {
        int rear = (queue->front + queue->count) % queue->size;
        queue->data[rear] = data;
        queue->count++;
    }
}

void outQueue(Queue queue, int* data)
{
    if (queue->count > 0)
    {
        *data = queue->data[queue->front--];
        queue->count--;
    }
}

// 查找有序数组中值为key的下标，找不到则插入到合适位置，保持数组有序
int findKeyIndex(int* data, int* length, int key)
{
    int low = 0, mid = 0, high = *length - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (data[mid] == key)
        {
            return mid;
        }
        if (data[mid] > key)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    for (int i = *length; i > mid; i--)
    {
        data[i] = data[i - 1];
    }
    (*length)++;
    data[mid] = key;
    return -1;
}

// 十进制正整数化为八进制正整数
void baseConversion(SStack stack, int data)
{
    while (data > 0)
    {
        pushSStack(stack, data % 8);
        data /= 8;
    }
    while (stack->top != -1)
    {
        popSStack(stack, &data);
        printf("%d", data);
    }
}

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\10App.2019.exe
// 0 1 2 3 4 5 6 7 8 9
// -1
// 12
// Process finished with exit code 0

int main()
{
    Queue queue = malloc(sizeof(struct Queue));
    queue->size = 10;
    queue->front = 0;
    queue->count = 0;
    for (int i = 0; i < queue->size; i++)
    {
        inQueue(queue, i);
    }
    for (int i = 0; i < queue->size; i++)
    {
        printf("%d ", queue->data[i]);
    }
    printf("\n");
    free(queue);

    int data[100] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int length = 10;
    int key = 10;
    printf("%d\n", findKeyIndex(data, &length, key));

    SStack stack;
    initiateSStack(&stack);
    baseConversion(stack, 10);
    destroySStack(&stack);
    return 0;
}
