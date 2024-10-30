#include <stdio.h>

// HeapSort
void adjustHead(int data[], int root, int length)
{
    int temp = data[root];
    // 比较
    for (int i = 2 * root; i <= length; i *= 2)
    {
        // 选择
        if (i < length && data[i] < data[i + 1])
            i++;
        if (temp < data[i])
        {
            data[root] = data[i];
            root = i;
        }
        else
            break;
    }
    // 下坠
    data[root] = temp;
}

void buildHeap(int data[], int length)
{
    for (int i = length / 2; i >= 0; i--)
    {
        adjustHead(data, i, length);
    }
}

void sortData(int data[], int length)
{
    // 建造
    buildHeap(data, length);
    for (int i = length; i > 1; i--)
    {
        // 交换
        data[0] = data[1];
        data[1] = data[i];
        data[i] = data[0];
        // 调整
        adjustHead(data, 1, i - 1);
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
    int data[100] = {0, 6, 1, 5, 9, 8, 4, 7};
    printData(data, 8);
    sortData(data, 8);
    printData(data, 8);
    return 0;
}
