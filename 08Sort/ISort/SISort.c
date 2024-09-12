#include <stdio.h>

// 统一重点：ToDo
// 统一提示：中文
// 统一注释：代码上方
// 统一状态：-1失败，0成功，1其他

// ToDo比较一个移动一个，直到找到合适位置插入
// StraightInsertionSort

void sortData(int data[], int length)
{
    for (int i = 2; i <= length; i++)
    {
        // ToDo比较
        if (data[i] < data[i - 1])
        {
            data[0] = data[i];
            int j;
            // ToDo移动
            for (j = i - 1; j > 0 && data[j] > data[0]; j--)
                data[j + 1] = data[j];
            // ToDo插入
            data[j + 1] = data[0];
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
