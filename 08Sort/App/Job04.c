#include <stdio.h>

// 统一重点：ToDo
// 统一提示：中文
// 统一注释：代码上方
// 统一状态：-1失败，0成功，1其他

// ToDo冒泡length/2趟，一半小的在前面，一半大的在后面，此时前后序列个数差最小，前后序列和数差最大
// BubbleSort

void sortData(int data[], int length)
{
    for (int i = 1; i <= length/2; i++)
    {
        // ToDo冒泡
        for (int j = length; j > i; j--)
        {
            // ToDo比较
            if (data[j] < data[j - 1])
            {
                // ToDo交换
                data[0] = data[j];
                data[j] = data[j - 1];
                data[j - 1] = data[0];
            }
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
