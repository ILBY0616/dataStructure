#include <stdio.h>

// 冒泡交换排序
void bubbleSort(int data[], int length);
// 打印序列
void printBubble(int data[], int length);

int main()
{
    int data[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    printBubble(data, 10);
    bubbleSort(data, 10);
    printBubble(data, 10);
    return 0;
}

void bubbleSort(int data[], int length)
{
    for (int i = 0; i < length; i++)
    {
        // 冒泡
        int flag = 0;
        for (int j = 0; j < length - i - 1; j++)
        {
            // 比较
            if (data[j] > data[j + 1])
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
