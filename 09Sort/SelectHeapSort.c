#include <stdio.h>

// 输入序列
void inputData(int* data, int length);
// 调整大根堆
void adjustHeap(int* data, int root, int length);
// 建造大根堆
void buildHeap(int* data, int length);
// 堆选择排序
void heapSort(int* data, int length, int sortSum);
// 打印序列
void printHeap(int* data, int length);

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\09Sort.SelectHeapSort.exe
// 9 8 7 6 5 4 3 2 1 0
// 0 1 2 3 4 5 6 7 8 9
//
// Process finished with exit code 0

int main()
{
    int data[10];
    int length = 10, sortSum = 10;
    inputData(data, length);
    heapSort(data, length, sortSum);
    printHeap(data, length);
    return 0;
}

void inputData(int* data, int length)
{
    for (int i = 0; i < length; i++)
    {
        scanf("%d", &data[i]);
    }
}

void adjustHeap(int* data, int root, int length)
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

void buildHeap(int* data, int length)
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
// 3. 插入与删除
// 插入：插入堆尾，调整
// 删除：根尾互换，调整
// 根次大值一定在根下层

// 排序思想：
// 堆排序是一种基于堆数据结构的排序算法。堆是一种完全二叉树，满足堆的性质（大根堆：父节点大于或等于子节点）。
// 堆排序的核心思想是通过调整堆，使堆顶元素始终为最大元素。首先建立一个大根堆，然后将堆顶元素与堆的最后一个元素交换位置，
// 使得堆的最大元素进入已排序部分。接着对剩下的元素重新调整堆，重复这一过程直到堆中只剩下一个元素。堆排序的时间复杂度为 O(nlog_2^n)，
// 比快速排序的最坏情况 O(n^2) 更稳定，适合处理大数据。
// 排序操作：
// 1. 排序趟数：堆排序需要进行 n-1 趟排序，首先构建大根堆，接着将堆顶元素交换到数组末尾并调整堆。
// 2. 比较次数：每次调整堆时，需要比较父节点与其子节点，总的比较次数约为 O(nlog_2^n)，每次调整堆的时间复杂度为 O(log_2^n)。
// 3. 移动次数：每次交换堆顶元素与最后一个元素时，涉及两个元素的移动。总的移动次数较少，主要集中在交换操作中。
// 4. 交换次数：每次堆顶元素与最后一个元素交换，通常在每一趟排序中都进行一次交换，总的交换次数为 O(n)。
void heapSort(int* data, int length, int sortSum)
{
    buildHeap(data, length);
    for (int i = length - 1; i > length - sortSum - 1; i--)
    {
        int max = data[0];
        data[0] = data[i];
        data[i] = max;
        adjustHeap(data, 0, i);
    }
}

void printHeap(int* data, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}
