#include <stdio.h>

// 统一重点：ToDo
// 统一提示：中文
// 统一注释：代码上方
// 统一状态：-1失败，0成功，1其他

// ToDo
// MergeSort

int temp[8];

void mergeData(int data[], int low, int mid, int high)
{
    int i, j, k;
    for (k = low; k <= high; k++)
        temp[k] = data[k];
    for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++)
    {
        if (temp[i] <= temp[j])
            data[k] = temp[i++];
        else
            data[k] = temp[j++];
    }
    while (i <= mid)
        data[k++] = temp[i++];
    while (j <= high)
        data[k++] = temp[j++];
}

void sortData(int data[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        sortData(data, low, mid);
        sortData(data, mid + 1, high);
        mergeData(data, low, mid, high);
    }
}

void printData(int data[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d", data[i]);
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
