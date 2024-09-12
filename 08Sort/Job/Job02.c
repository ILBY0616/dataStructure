#include <stdio.h>

// 统一重点：ToDo
// 统一提示：中文
// 统一注释：代码上方
// 统一状态：-1失败，0成功，1其他

// ToDo从后往前两两比较，大的在后小的在前，k趟冒泡后确定第k小的元素在最终位置
// BubbleSort

void sortData(int data[], int length,int kth)
{
    for (int i = 1; i <= kth; i++)
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
    sortData(data, 7,4);
    printData(data, 7);
    return 0;
}
