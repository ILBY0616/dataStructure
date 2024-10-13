#include <stdio.h>

// BubbleSort
void sortData(int data[], int length)
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
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
                flag++;
            }
        }
        if (flag == 0)
        {
            break;
        }
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
