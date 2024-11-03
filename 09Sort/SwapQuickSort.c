#include <stdio.h>

// 划分左右序列
int divideData(int data[], int low, int high);
// 快速交换排序
void quickSort(int data[], int low, int high);
// 打印序列
void printQuick(int data[], int length);

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
