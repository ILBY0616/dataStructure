#include <stdio.h>

int copy[100];

// 合并数据
void mergeData(int* data, int low, int mid, int high)
{
    int i, j, k;
    // 复制数据
    for (k = low; k <= high; k++)
    {
        copy[k] = data[k];
    }
    // 二路归并
    for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++)
    {
        if (copy[i] <= copy[j])
        {
            data[k] = copy[i++];
        }
        else
        {
            data[k] = copy[j++];
        }
    }
    // 拼接余留
    while (i <= mid)
    {
        data[k++] = copy[i++];
    }
    // 拼接余留
    while (j <= high)
    {
        data[k++] = copy[j++];
    }
}

// 归并排序
void mergeSort(int* data, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(data, low, mid);
        mergeSort(data, mid + 1, high);
        mergeData(data, low, mid, high);
    }
}

// 打印序列
void printMerge(int* data, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", data[i]);
    }
}

// 排序思想：
// 归并排序是一种分治算法，它通过递归地将数组分为两个子数组，直到每个子数组只有一个元素，天然有序。
// 然后，归并操作将这些有序的子数组合并成一个有序的大数组。归并排序每次将两个有序的子数组合并成一个有序的数组，直到整个数组排序完成。
// 归并排序是基于比较的排序算法，它每次比较两个元素并决定其顺序。它适用于任何数据类型的排序，特别是当数据量较大时，归并排序具有较好的性能表现，时间复杂度为 O(nlog_2^n)。
// 排序操作：
// 1. 排序趟数：归并排序的排序趟数由递归的深度决定，深度为 log_2^n。在每一层递归中，归并排序都会把一个较大的数组分成两个较小的数组。
//    最终会进行 log_2^n 次递归，每次递归都将整个数组划分成小的部分。
// 2. 比较次数：每一趟归并操作中，需要比较两个元素的大小关系，确定它们的顺序。每个子数组的元素在合并时，最多进行 n 次比较。
//    因此，整个排序过程的比较次数为 O(nlog_2^n)。
// 3. 移动次数：在归并过程中，每个元素需要移动到正确的位置，所有元素的移动总数大约为 O(n)，每次合并时都需要移动元素。
// 4. 交换次数：归并排序没有交换操作。每次合并操作时，只是通过赋值来重排元素的位置。

int main()
{
    int data[100] = {
        99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77,
        76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52,
        51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27,
        26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0
    };
    int low = 0, high = 99, length = 100;
    mergeSort(data, low, high);
    printMerge(data, length);
    return 0;
}
