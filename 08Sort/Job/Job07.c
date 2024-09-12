#include <stdio.h>

// 统一重点：ToDo
// 统一提示：中文
// 统一注释：代码上方
// 统一状态：-1失败，0成功，1其他

// ToDo数据存储在1-m+n范围，前m个序列增序，前n个序列增序，现要求整个序列增序
// MergeSort

int temp[8] = {0};

void sortData(int data[], int m, int n)
{
    int i, j, k;
    for (i = 1; i <= m + n; i++)
        temp[i] = data[i];
    for (i = 1, j = m + 1, k = 1; i <= m && j <= m + n; k++)
    {
        if (temp[i] <= temp[j])
            data[k] = temp[i++];
        else
            data[k] = temp[j++];
    }
    while (i <= m)
    {
        data[k++] = temp[i++];
    }
    while (j <= m + n)
    {
        data[k++] = temp[j++];
    }
}

void printData(int data[], int length)
{
    for (int i = 1; i <= length; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}

int main()
{
    int data[8] = {0, 1, 3, 5, 7, 2, 4, 6};
    printData(data, 7);
    sortData(data, 4, 3);
    printData(data, 7);
    return 0;
}
