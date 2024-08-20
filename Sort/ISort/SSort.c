#include <stdio.h>

// 统一重点：ToDo
// 统一提示：中文
// 统一注释：代码上方
// 统一状态：-1失败，0成功，1其他

// ToDo在不同增量d下进行直接插入排序，d=1时已经基本有序，此时整体直接插入排序
// ShellSort

void sortData(int data[], int length)
{
    for (int d = length / 2; d >= 1; d = d / 2)
    {
        // ToDo分割
        for (int i = 1 + d; i <= length; i += d)
        {
            // ToDo比较
            if (data[i] < data[i - d])
            {
                data[0] = data[i];
                int j;
                // ToDo移动
                for (j = i - d; j > 0 && data[j] > data[0]; j -= d)
                    data[j + d] = data[j];
                // ToDo插入
                data[j + d] = data[0];
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
