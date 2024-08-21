#include <stdio.h>

// 统一重点：ToDo
// 统一提示：中文
// 统一注释：代码上方
// 统一状态：-1失败，0成功，1其他

// ToDo建造堆，输出堆，调整堆
// HeapSort

void adjustHead(int data[], int root, int length)
{
    data[0] = data[root];
    // ToDo比较
    for (int i = 2 * root; i <= length; i *= 2)
    {
        // ToDo选择
        if (i < length && data[i] < data[i + 1])
            i++;
        if (data[0] < data[i])
        {
            data[root] = data[i];
            root = i;
        }
        else
            break;
    }
    // ToDo下坠
    data[root] = data[0];
}

void buildHeap(int data[], int length)
{
    for (int i = length / 2; i > 0; i--)
        adjustHead(data, i, length);
}

void sortData(int data[], int length)
{
    // ToDo建造
    buildHeap(data, length);
    for (int i = length; i > 1; i--)
    {
        // ToDo输出
        data[0] = data[1];
        data[1] = data[i];
        data[i] = data[0];
        // ToDo调整
        adjustHead(data, 1, i - 1);
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
    int data[100] = {0, 6, 1, 5, 9, 8, 4, 7};
    printData(data, 7);
    sortData(data, 7);
    printData(data, 7);
    return 0;
}
