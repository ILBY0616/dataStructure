#include <stdio.h>

// 合并有序数据
void mergeData(int data[], int low, int mid, int high);
// 二路归并排序
void mergeSort(int data[], int low, int high);
// 打印序列
void printMerge(int data[], int length);

int main()
{
    int data[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    printMerge(data, 10);
    mergeSort(data, 0, 9);
    printMerge(data, 10);
    return 0;
}

int copy[10];

void mergeData(int data[], int low, int mid, int high)
{
    int i, j, k;
    // 复制数据
    for (k = low; k <= high; k++)
    {
        copy[k] = data[k];
    }
    // 二路归并
    for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++)
    {
        if (copy[i] <= copy[j])
        {
            data[k] = copy[i++];
        }
        else
        {
            data[k] = copy[j++];
        }
    }
    // 拼接剩余部分
    while (i <= mid)
    {
        data[k++] = copy[i++];
    }
    // 拼接剩余部分
    while (j <= high)
    {
        data[k++] = copy[j++];
    }
}

// 首先将序列划分为两个序列
// 递归使得两个序列有序（数量为一，天然有序）
// 归并为一个有序表
void mergeSort(int data[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(data, low, mid);
        mergeSort(data, mid + 1, high);
        mergeData(data, low, mid, high);
    }
}

void printMerge(int data[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}
