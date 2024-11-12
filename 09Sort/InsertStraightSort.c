#include <stdio.h>

// 直接插入排序
void insertSort(int data[], int length);
// 打印序列
void printInsert(int data[], int length);

int main()
{
    int data[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    printInsert(data, 10);
    insertSort(data, 10);
    printInsert(data, 10);
    return 0;
}

void insertSort(int data[], int length)
{
    for (int i = 1; i < length; i++)
    {
        if (data[i] < data[i - 1])
        {
            int temp = data[i];
            int j = i - 1;
            // 比较
            while (j >= 0 && data[j] > temp)
            {
                // 移动
                data[j + 1] = data[j];
                j--;
            }
            // 插入
            data[j + 1] = temp;
        }
    }
}

void printInsert(int data[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}
