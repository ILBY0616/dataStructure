#include <stdio.h>

// 冒泡排序
void bubbleSort(int* data, int length)
{
    for (int i = length; i > 1; i--)
    {
        // 冒泡
        int flag = 0;
        for (int j = 1; j < i; j++)
        {
            // 比较
            if (data[j] > data[j + 1])
            {
                // 交换
                data[0] = data[j];
                data[j] = data[j + 1];
                data[j + 1] = data[0];
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}

// 打印序列
void printData(int* data, int length)
{
    for (int i = 1; i <= length; i++)
    {
        printf("%d ", data[i]);
    }
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

int main()
{
    int data[101] = {
        101, 100, 99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77,
        76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52,
        51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27,
        26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1
    };
    int length = 100;
    bubbleSort(data, length);
    printData(data, length);
    return 0;
}