#include <stdio.h>

// 基数排序
void radixSort(int* data, int length)
{
    int max = data[0];
    for (int i = 1; i < length; i++)
    {
        if (data[i] > max)
        {
            max = data[i];
        }
    }
    int maxDigit = 0;
    while (max != 0)
    {
        max /= 10;
        maxDigit++;
    }
    int count[10];
    int temp[length];
    int divisor = 1;
    for (int digit = 0; digit < maxDigit; digit++)
    {
        for (int i = 0; i < 10; i++)
        {
            count[i] = 0;
        }
        for (int i = 0; i < length; i++)
        {
            int bucket = (data[i] / divisor) % 10;
            count[bucket]++;
        }
        for (int i = 1; i < 10; i++)
        {
            count[i] += count[i - 1];
        }
        for (int i = length - 1; i >= 0; i--)
        {
            int bucket = (data[i] / divisor) % 10;
            temp[--count[bucket]] = data[i];
        }
        for (int i = 0; i < length; i++)
        {
            data[i] = temp[i];
        }
        divisor *= 10;
    }
}

// 打印序列
void printData(int* data, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", data[i]);
    }
}

// 排序思想：
// 基数排序是一种通过逐位排序来实现整体排序的算法。它通过位数这一标准进行多次排序，不依赖于元素之间的比较。
// 每次排序依赖于当前位数字的值，使用稳定排序（本例中是计数排序）来保持相同元素的相对顺序。
// 基数排序适用于数字排序，尤其当数字的范围较小或位数较少时，效率较高。
// 基数排序不基于比较和交换操作，而是通过稳定排序方法对每一位进行排序。它可以分为高位优先排序和低位优先排序，本例采用低位优先排序（即从最低位到最高位排序）。
// 排序操作：
// 1. 排序趟数：排序的趟数等于最大数的位数。如果最大数有 d 位，则需要 d 趟排序。
// 2. 比较次数：基数排序并不直接进行元素之间的比较。每一趟排序中，系统只会根据当前位的数字进行分配，因此没有传统排序算法中的比较操作。
// 3. 移动次数：每一趟排序会遍历所有元素，每个元素根据当前位的数字值进行移动，总的移动次数大约为 O(n)，每趟排序的复杂度为 O(n)。
// 4. 交换次数：基数排序没有直接的交换操作，数据位置的重排通过稳定排序（计数排序）来完成。

int main()
{
    int data[100] = {
        99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77,
        76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52,
        51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27,
        26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0
    };
    int length = 100;
    radixSort(data, length);
    printData(data, length);
    return 0;
}
