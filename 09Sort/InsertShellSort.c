#include <stdio.h>

// 希尔插入排序
void shellSort(int data[], int length);
// 打印序列
void printShell(int data[], int length);

int main()
{
    int data[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    printShell(data, 10);
    shellSort(data, 10);
    printShell(data, 10);
    return 0;
}

void shellSort(int data[], int length)
{
    for (int d = length / 2; d >= 1; d = d / 2)
    {
        // 分割
        for (int i = d; i < length; i += d)
        {
            if (data[i] < data[i - d])
            {
                int temp = data[i];
                int j = i - d;
                // 比较
                while (j >= 0 && data[j] > temp)
                {
                    // 移动
                    data[j + d] = data[j];
                    j -= d;
                }
                // 插入
                data[j + d] = temp;
            }
        }
    }
}

void printShell(int data[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}
