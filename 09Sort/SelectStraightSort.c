#include <stdio.h>

// 简单选择排序
void selectSort(int data[], int length);
// 打印序列
void printSelect(int data[], int length);

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\09Sort.SelectStraightSort.exe
// 9 8 7 6 5 4 3 2 1 0
// 0 1 2 3 4 5 6 7 8 9
//
// Process finished with exit code 0

int main()
{
    int data[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    printSelect(data, 10);
    selectSort(data, 10);
    printSelect(data, 10);
    return 0;
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
void selectSort(int data[], int length)
{
    // 选择
    for (int i = 0; i < length; i++)
    {
        // 比较
        int min = i;
        for (int j = i + 1; j < length; j++)
        {
            if (data[j] < data[min])
            {
                min = j;
            }
        }
        // 交换
        if (min != i)
        {
            int temp = data[i];
            data[i] = data[min];
            data[min] = temp;
        }
    }
}

void printSelect(int data[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}
