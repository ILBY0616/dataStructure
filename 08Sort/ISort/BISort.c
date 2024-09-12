#include <stdio.h>

// 统一重点：ToDo
// 统一提示：中文
// 统一注释：代码上方
// 统一状态：-1失败，0成功，1其他

// ToDo直接折半找到合适位置，然后整体移动元素，最后插入
// BinaryInsertionSort

void sortData(int data[], int length)
{
    for (int i = 2; i <= length; i++)
    {
        data[0] = data[i];
        int low = 1, high = i - 1;
        // ToDo查找
        while (low <= high)
        {
            int mid = (low + high) / 2;
            // ToDo比较
            if (data[0] < data[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        // ToDo移动
        for (int j = i - 1; j >= high + 1; j--)
            data[j + 1] = data[j];
        // ToDo插入
        data[high + 1] = data[0];
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
