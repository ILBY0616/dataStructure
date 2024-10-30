#include <stdio.h>

// 统一重点：ToDo
// 统一提示：中文
// 统一注释：代码上方
// 统一状态：-1失败，0成功，1其他

// ToDo
// CountSort

void sortData(int data[], int length)
{
    int temp[length];
    int count[length];
    for (int i = 0; i < length; i++)
    {
        temp[i] = data[i];
        count[i] = 0;
    }
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (temp[i] <= temp[j])
                count[j]++;
            else
                count[i]++;
        }
    }
    for (int i = 0; i < length; i++)
    {
        data[count[i]] = temp[i];
    }
}

void printData(int data[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}

int main()
{
    int data[8] = {8, 7, 6, 5, 4, 3, 2, 1};
    printData(data, 8);
    sortData(data, 8);
    printData(data, 8);
    return 0;
}
