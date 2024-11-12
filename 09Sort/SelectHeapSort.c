#include <stdio.h>

// 调整小根堆
void adjustHeap(int data[], int root, int length);
// 建造小根堆
void buildHeap(int data[], int length);
// 堆选择排序
void heapSort(int data[], int length);
// 打印序列
void printHeap(int data[], int length);

int main()
{
    int data[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    printHeap(data, 10);
    heapSort(data, 10);
    printHeap(data, 10);
    return 0;
}

void adjustHeap(int data[], int root, int length)
{
    int smallest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;
    if (left < length && data[left] < data[smallest])
    {
        smallest = left;
    }
    if (right < length && data[right] < data[smallest])
    {
        smallest = right;
    }
    if (smallest != root)
    {
        int temp = data[root];
        data[root] = data[smallest];
        data[smallest] = temp;
        adjustHeap(data, smallest, length);
    }
}

void buildHeap(int data[], int length)
{
    for (int i = (length / 2) - 1; i >= 0; i--)
    {
        adjustHeap(data, i, length);
    }
}

// 1. 建立小根堆
// 首先，将待排序数组转换为小根堆，确保每个父节点小于或等于其子节点。对于小根堆，最小元素在堆的根结点。
// 2. 堆排序过程
// 通过以下步骤完成排序：
// 将堆的根节点与堆的最后一个元素交换，并将堆的大小减1。
// 对新的根节点进行调整，使其重新满足小根堆的性质。
// 重复上述步骤，直到堆的大小为1。
void heapSort(int data[], int length)
{
    buildHeap(data, length);
    for (int i = length - 1; i > 0; i--)
    {
        int temp = data[0];
        data[0] = data[i];
        data[i] = temp;
        adjustHeap(data, 0, i);
    }
}

void printHeap(int data[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}
