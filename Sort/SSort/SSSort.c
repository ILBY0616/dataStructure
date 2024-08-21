#include <stdio.h>

// 统一重点：ToDo
// 统一提示：中文
// 统一注释：代码上方
// 统一状态：-1失败，0成功，1其他

// ToDo一趟排序后，通过比较将未排序序列中最小元素放在已排序序列末尾，即最终位置，length个数据要length-1趟排序完
// SimpleSelectionSort

void sortData(int data[], int length)
{
    // ToDo选择
    for (int i = 1; i < length; i++)
    {
        // ToDo比较
        int min = i;
        for (int j = i + 1; j <= length; j++)
            if (data[j] < data[min])
                min = j;
        // ToDo交换
        if (min != i)
        {
            data[0] = data[i];
            data[i] = data[min];
            data[min] = data[0];
        }
    }
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
    sortData(data, 7);
    printData(data, 7);
    return 0;
}
