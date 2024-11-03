#include <stdio.h>

// 折半插入排序
void foldSort(int data[], int length);
// 打印序列
void printFold(int data[], int length);

int main()
{
    int data[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    printFold(data, 10);
    foldSort(data, 10);
    printFold(data, 10);
    return 0;
}

void foldSort(int data[], int length)
{
    for (int i = 1; i < length; i++)
    {
        int temp = data[i];
        int low = 0, high = i - 1;
        // 查找
        while (low <= high)
        {
            int mid = (low + high) / 2;
            // 比较
            if (temp < data[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        // 移动
        for (int j = i - 1; j >= high + 1; j--)
            data[j + 1] = data[j];
        // 插入
        data[high + 1] = temp;
    }
}

void printFold(int data[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}
