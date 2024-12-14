#include <stdio.h>

// 直接插入排序
void insertSort(int* data, int length)
{
    for (int i = 2; i <= length; i++)
    {
        if (data[i] < data[i - 1])
        {
            data[0] = data[i];
            int j = i - 1;
            // 比较
            while (j >= 1 && data[j] > data[0])
            {
                // 移动
                data[j + 1] = data[j];
                j--;
            }
            // 插入
            data[j + 1] = data[0];
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
// 直接插入排序是一种简单的排序算法，它的基本思想是将待排序元素逐个插入到已排序序列中。每次将待排序序列中的第一个元素插入到已排序序列中的适当位置。
// 具体做法是从第二个元素开始，依次与前面的已排序元素进行比较，将较大的元素向后移动，直到找到合适的位置。
// 这种排序方法适用于数据量较小或者序列本身基本有序的情况，虽然在最坏情况下其时间复杂度为 O(n^2)，但是对于基本有序的序列来说，性能表现较好。
// 排序操作：
// 1. 排序趟数：直接插入排序需要进行 n-1 次排序操作，每次将一个待排序元素插入到已排序序列中。
// 2. 比较次数：每次插入一个元素时，需要与已排序的元素逐一比较，直到找到合适的位置。最坏情况下，比较次数为 O(n^2)，而最佳情况下（已排序序列）为 O(n)。
// 3. 移动次数：每次插入元素时，已排序序列中大于该元素的部分都需要后移。最坏情况下，每个元素都需要移动到最前面，总的移动次数为 O(n^2)。
// 4. 交换次数：在直接插入排序中，没有显式的交换操作，而是通过移动元素来实现排序，因此交换次数为 0。

int main()
{
    int data[101] = {
        101, 100, 99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77,
        76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52,
        51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27,
        26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1
    };
    int length = 100;
    insertSort(data, length);
    printData(data, length);
    return 0;
}