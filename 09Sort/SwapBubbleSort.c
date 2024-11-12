#include <stdio.h>

// 双向冒泡排序
void doubleBubble(int data[], int length);
// 冒泡交换排序
void bubbleSort(int data[], int length);
// 打印序列
void printBubble(int data[], int length);

int main()
{
    int data[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    printBubble(data, 10);
    doubleBubble(data, 10);
    printBubble(data, 10);
    bubbleSort(data, 10);
    printBubble(data, 10);
    return 0;
}

void doubleBubble(int data[], int length)
{
    int i = 0, j = length - 1, k;
    while (i < j)
    {
        int flag = 0;
        for (k = i; k < j; k++)
        {
            if (data[k] > data[k + 1])
            {
                flag = data[k];
                data[k] = data[k + 1];
                data[k + 1] = flag;
                flag = flag != 0 ? flag : 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
        j--;
        flag = 0;
        for (k = j; k > i; k--)
        {
            if (data[k] < data[k - 1])
            {
                flag = data[k];
                data[k] = data[k - 1];
                data[k - 1] = flag;
                flag = flag != 0 ? flag : 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
        i++;
    }
}

// n个元素通过n-1趟冒泡实现排序，每一趟冒泡将一个当前最大元素放到最终位置
// 每一趟包括比较和交换，比较次数无关于待排序序列初始状态，只有关于待排序序列长度，交换次数既相关待排序序列初始状态，又相关待排序序列长度
void bubbleSort(int data[], int length)
{
    for (int i = 0; i < length; i++)
    {
        // 冒泡
        int flag = 0;
        for (int j = 0; j < length - i - 1; j++)
        {
            // 比较
            if (data[j] < data[j + 1])
            {
                // 交换
                int value = data[j];
                data[j] = data[j + 1];
                data[j + 1] = value;
                flag++;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}

void printBubble(int data[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}
