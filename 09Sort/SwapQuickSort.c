#include <stdio.h>

// 划分左右序列
int divideData(int data[], int low, int high);
// 快速交换排序
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

// 快速排序的交换更加宽广，不是两两通过temp交换，而是nn通过temp交换
// 这个交换的过程称之为划分，每次划分首先确定枢纽元素，然后以枢纽元素将整个序列划为左右两半，左边<=枢纽元素<=右边
// 每趟划分将一个枢纽元素确定在最终位置
// 采用递归实现产生了递归工作栈空间消耗
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
