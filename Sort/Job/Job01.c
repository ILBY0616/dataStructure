#include <stdio.h>

// 统一重点：ToDo
// 统一提示：中文
// 统一注释：代码上方
// 统一状态：-1失败，0成功，1其他

// ToDo一趟排序后，通过枢轴元素将未排序序列划分为两部分，枢轴往右为奇数，枢轴往左为偶数，而枢轴元素处在最终位置
// QuickSort

int sortData(int data[], int low, int high)
{
    data[0] = data[low];
    // ToDo划分
    while (low < high)
    {
        // ToDo比较
        while (low < high && (data[high]%2)==0)
            high--;
        data[low] = data[high];
        // ToDo比较
        while (low < high && (data[low]%2)==1)
            low++;
        data[high] = data[low];
    }
    // ToDo交换
    data[low] = data[0];
    return low;
}

void printData(int data[], int length)
{
    for (int i = 1; i <= length; i++)
    {
        printf("%d", data[i]);
    }
    printf("\n");
}

int main()
{
    int data[8] = {0, 7, 6, 5, 4, 3, 2, 1};
    printData(data, 7);
    sortData(data, 1, 7);
    printData(data, 7);
    return 0;
}