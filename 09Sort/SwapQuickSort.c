#include <stdio.h>

// 划分序列
int divideData(int data[], int low, int high);
// 快速排序
void quickSort(int data[], int low, int high);
// 打印序列
void printQuick(int data[], int length);

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\09Sort.SwapQuickSort.exe
// 9 8 7 6 5 4 3 2 1 0
// 0 1 2 3 4 5 6 7 8 9
//
// Process finished with exit code 0

int main()
{
    int data[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    printQuick(data, 10);
    quickSort(data, 0, 9);
    printQuick(data, 10);
    return 0;
}

int divideData(int data[], int low, int high)
{
    int temp = data[low];
    // 划分
    while (low < high)
    {
        // 比较
        while (low < high && temp <= data[high])
        {
            high--;
        }
        data[low] = data[high];
        // 比较
        while (low < high && temp >= data[low])
        {
            low++;
        }
        data[high] = data[low];
    }
    // 交换
    data[low] = temp;
    return low;
}

// 排序思想：
// 快速排序是一种基于分治思想的排序算法。它通过一个枢纽元素将数组划分为两部分，左边部分的所有元素小于等于枢纽元素，右边部分的所有元素大于等于枢纽元素。
// 然后递归地对左右两部分进行相同的操作，直到所有子数组的元素有序。快速排序的核心思想是每次划分能够将一个元素确定到最终的位置。
// 快速排序的平均时间复杂度为 O(nlog_2^n)，最坏情况下是 O(n^2)，但是通过优化选择枢纽元素，可以减少最坏情况的发生。
// 排序操作：
// 1. 排序趟数：每次递归调用快速排序时，都会对左右子序列进行划分。递归的最大深度为 n，最小为 log_2^n。
// 2. 比较次数：每次划分都会比较左右两个元素，直到它们满足排序条件。每一趟划分的比较次数大约是当前子序列的长度。
// 3. 移动次数：每次比较并交换元素时，都会将元素从一个位置移动到另一个位置，最坏情况下需要 O(n^2) 次交换。
// 4. 交换次数：每次划分过程中会进行交换操作，将比枢纽元素大的元素放到右边，小的放到左边。交换次数是递归深度的函数，与元素的初始顺序有关。
void quickSort(int data[], int low, int high)
{
    if (low < high)
    {
        int pivot = divideData(data, low, high);
        quickSort(data, low, pivot - 1);
        quickSort(data, pivot + 1, high);
    }
}

void printQuick(int data[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}
