#include <stdio.h>

// 希尔排序
void shellSort(int* data, int length)
{
    for (int d = length / 2; d >= 1; d = d / 2)
    {
        // 分割
        for (int i = 1 + d; i <= length; i += d)
        {
            if (data[i] < data[i - d])
            {
                data[0] = data[i];
                int j = i - d;
                // 比较
                while (j >= 1 && data[j] > data[0])
                {
                    // 移动
                    data[j + d] = data[j];
                    j -= d;
                }
                // 插入
                data[j + d] = data[0];
            }
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
// 希尔排序是插入排序的一种改进算法，它通过将序列分割成若干个子序列来优化排序过程。首先，以一个间隔序列（gap）将整个序列分成若干个子序列,
// 然后对每个子序列进行插入排序。通过不断减少间隔序列的步长，最终在步长为1时，对整个序列进行插入排序。
// 这种分组排序的思想大大减少了移动元素的次数，从而提高了排序效率。希尔排序的核心思想是先通过较大的间隔进行排序，使得序列部分有序，然后
// 通过更小的间隔逐步优化，直到最终排序完成。
// 排序操作：
// 1. 排序趟数：希尔排序的排序趟数取决于间隔序列的选择。最常见的间隔序列是初始间隔为 n / 2，每次减半，直到间隔为 1。排序的总趟数是与间隔序列的
//    长度有关的，通常为 O(log_2^n)。
// 2. 比较次数：每次进行插入排序时，需要在子序列中进行元素比较，比较次数取决于子序列的大小和元素的分布情况。总体而言，随着步长减小，比较次数逐渐增加。
//    每趟排序中，最坏的比较次数为 O(n)，但由于有多个子序列，实际比较次数会少于普通插入排序。
// 3. 移动次数：由于是插入排序的变种，每次排序会涉及元素的移动。最坏情况下，每个元素可能需要移动多次，整体移动次数为 O(n^2)。
//    不过，通过分组排序，希尔排序大大减少了实际的移动次数，因此在大多数情况下，它的效率要高于普通的插入排序。
// 4. 交换次数：与普通插入排序类似，希尔排序也没有显式的交换操作，元素的重排是通过移动完成的。交换次数可以认为是 0。

int main()
{
    int data[101] = {
        101, 100, 99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77,
        76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52,
        51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27,
        26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1
    };
    int length = 100;
    shellSort(data, length);
    printData(data, length);
    return 0;
}
