#include <stdio.h>

// 直接选择排序
void selectSort(int data[], int length);
// 打印序列
void printSelect(int data[], int length);

int main()
{
    int data[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    printSelect(data, 10);
    selectSort(data, 10);
    printSelect(data, 10);
    return 0;
}

// 以首个元素为已排序序列，以剩余元素为待排序序列
// 在待排序序列中选择最小元素放在已排序序列末尾
// 每一趟排序确定一个元素最终位置，n个数据要n-1趟排序完
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
