#include <stdio.h>

// 简单选择排序
void selectSort(int* data, int length)
{
    // 选择
    for (int i = 1; i <= length; i++)
    {
        // 比较
        int min = i;
        for (int j = i + 1; j <= length; j++)
        {
            if (data[j] < data[min])
            {
                min = j;
            }
        }
        // 交换
        if (min != i)
        {
            data[0] = data[i];
            data[i] = data[min];
            data[min] = data[0];
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
// 选择排序是一种简单的排序算法。
// 它的基本思路是：每一趟从待排序的元素中选出最小的元素，将其与当前未排序部分的第一个元素交换位置。
// 每进行一次选择排序，就能确定一个元素的最终位置。
// 这个过程重复 n-1 次，直到所有元素都被排序。
// 该算法的时间复杂度为 O(n^2)，在元素个数较少时可以使用，但对于较大规模的数据，效率较低。
// 排序操作：
// 1. 排序趟数：对于 n 个元素，总共需要 n-1 趟排序，因为最后一个元素自然排好。
// 2. 比较次数：每一趟排序都需要遍历剩余未排序的元素，查找最小值。对于每一趟，最坏情况下需要进行 n-i 次比较（i 是已排序部分的元素个数）。总的比较次数为 O(n^2)。
// 3. 移动次数：每次选择最小值后，将其与当前元素交换，每次交换会涉及两个元素的交换。总的交换次数也为 O(n^2)。
// 4. 交换次数：每一趟都可能需要交换一次，最坏情况下进行 n-1 次交换。

int main()
{
    int data[101] = {
        101, 100, 99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77,
        76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52,
        51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27,
        26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1
    };
    int length = 100;
    selectSort(data, length);
    printData(data, length);
    return 0;
}
