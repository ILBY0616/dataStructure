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
