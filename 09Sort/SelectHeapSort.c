#include <stdio.h>

// 调整大根堆
void adjustHeap(int data[], int root, int length);
// 建造大根堆
void buildHeap(int data[], int length);
// 堆选择排序
void heapSort(int data[], int length);
// 打印序列
void printHeap(int data[], int length);

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\09Sort.SelectHeapSort.exe
// 9 8 7 6 5 4 3 2 1 0
// 0 1 2 3 4 5 6 7 8 9
//
// Process finished with exit code 0

int main()
{
    int data[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    printHeap(data, 10);
    heapSort(data, 10);
    printHeap(data, 10);
    return 0;
}

void adjustHeap(int data[], int root, int length)
{
    int max = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;
    if (left < length && data[left] > data[max])
    {
        max = left;
    }
    if (right < length && data[right] > data[max])
    {
        max = right;
    }
    if (max != root)
    {
        int temp = data[root];
        data[root] = data[max];
        data[max] = temp;
        adjustHeap(data, max, length);
    }
}

void buildHeap(int data[], int length)
{
    for (int i = (length / 2) - 1; i >= 0; i--)
    {
        adjustHeap(data, i, length);
    }
}

// 1. 建立大根堆
// 首先，将待排序数组转换为大根堆，确保每个父节点大于或等于其子节点。对于大根堆，最大元素在堆的根结点。
// 2. 堆排序过程
// 通过以下步骤完成排序：
// 将堆的根节点与堆的最后一个元素交换，并将堆的大小减1。
// 对新的根节点进行调整，使其重新满足大根堆的性质。
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
