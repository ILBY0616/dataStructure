#include <stdio.h>

// 计数排序
void countSort(int* data, int length);
// 打印序列
void printCount(int* data, int length);

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\09Sort.CountSort.exe
// 9 8 7 6 5 4 3 2 1 0
// 0 1 2 3 4 5 6 7 8 9
//
// Process finished with exit code 0

int main()
{
    int data[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    printCount(data, 10);
    countSort(data, 10);
    printCount(data, 10);
    return 0;
}

// 排序思想：
// 计数排序是一种基于元素值而非比较的排序算法。通过统计每个元素在序列中小于其值的元素个数，确定该元素在排序后序列中的位置。
// 该算法首先遍历数组，比较每一对元素的大小关系，记录每个元素的排名信息，然后根据排名直接生成排序后的序列。
// 适合用于元素取值范围较小的整数序列，不需要元素之间的直接比较操作，理论上可达到线性时间复杂度。
// 排序操作：
// 1. 排序趟数：两次完整遍历。第一次遍历统计元素的排名，第二次遍历根据排名生成有序数组。
// 2. 比较次数：使用双重循环比较元素，每个元素与其后所有元素比较，共计 n(n-1)/2 次比较。
// 3. 移动次数：将每个元素放入新位置，每个元素仅需移动一次，总计 n 次。
// 4. 交换次数：无直接交换操作，仅有统计和赋值过程。
void countSort(int* data, int length)
{
    int temp[length];
    int count[length];
    for (int i = 0; i < length; i++)
    {
        temp[i] = data[i];
        count[i] = 0;
    }
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (temp[i] <= temp[j])
                count[j]++;
            else
                count[i]++;
        }
    }
    for (int i = 0; i < length; i++)
    {
        data[count[i]] = temp[i];
    }
}

void printCount(int* data, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}
