#include <stdio.h>

// QuickSort
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

void sortData(int data[], int low, int high)
{
    if (low < high)
    {
        int pivot = divideData(data, low, high);
        sortData(data, low, pivot - 1);
        sortData(data, pivot + 1, high);
    }
}

void printData(int data[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}

int main()
{
    int data[8] = {8, 7, 6, 5, 4, 3, 2, 1};
    printData(data, 8);
    sortData(data, 0, 7);
    printData(data, 8);
    return 0;
}
