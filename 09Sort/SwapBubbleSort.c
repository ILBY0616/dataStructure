#include <stdio.h>

// 冒泡排序
void bubbleSort(int* data, int length);
// 打印序列
void printBubble(int* data, int length);

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\09Sort.SwapBubbleSort.exe
// 9 8 7 6 5 4 3 2 1 0
// 0 1 2 3 4 5 6 7 8 9
//
// Process finished with exit code 0

int main()
{
    int data[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    printBubble(data, 10);
    bubbleSort(data, 10);
    printBubble(data, 10);
    return 0;
}

// 排序思想：
// 冒泡排序是一种基于比较和交换的简单排序算法。其基本思想是通过多次比较相邻元素并交换它们的位置，将较大的元素逐步冒泡到序列的末尾，直到整个序列有序。
// 每次遍历序列，比较相邻元素的大小关系，并交换它们的位置，最大或最小元素将逐步“浮动”到序列的末尾。冒泡排序适用于数据量较小或接近有序的场景。
// 在最坏情况下，冒泡排序的时间复杂度为 O(n^2)，但是在序列本身基本有序时，可以提前结束，时间复杂度达到 O(n)。
// 排序操作：
// 1. 排序趟数：冒泡排序最多需要进行 n-1 次排序趟数，因为每一趟都会将一个最大（或最小）元素放到最终位置。
// 2. 比较次数：每次遍历序列时，比较相邻的元素。每一趟比较的次数与待排序序列的长度成正比，即每次外层循环进行 n-i-1 次比较。
// 3. 移动次数：元素的移动是通过交换实现的，移动次数与交换次数相同。最坏情况下，每个元素都可能需要交换，导致 O(n^2) 的移动次数。
// 4. 交换次数：每次有相邻元素比较时，如果顺序错误，则进行交换。交换次数与元素的初始顺序密切相关，最坏情况下需要交换 O(n^2) 次。
void bubbleSort(int* data, int length)
{
    for (int i = 0; i < length; i++)
    {
        // 冒泡
        int flag = 0;
        for (int j = 0; j < length - i - 1; j++)
        {
            // 比较
            if (data[j] > data[j + 1])
            {
                // 交换
                int value = data[j];
                data[j] = data[j + 1];
                data[j + 1] = value;
                flag++;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}

void printBubble(int* data, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}
