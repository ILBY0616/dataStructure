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

// 以首个元素为已排序序列，以剩余元素为待排序序列
// 逐个在待排序序列中选择元素与已排序序列中的元素通过比较大小找到合适位置
// 移动元素空出合适位置，然后插入待排序元素
// n个元素进行n-1趟排序，每趟排序包含比较移动插入，比较次数、移到次数、插入次数取决于待排序序列初始状态
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
