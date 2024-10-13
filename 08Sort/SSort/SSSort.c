#include <stdio.h>

// SimpleSelectionSort
void sortData(int data[], int length)
{
    // 选择
    for (int i = 0; i < length; i++)
    {
        // 比较
        int min = i;
        for (int j = i + 1; j < length; j++)
        {
            if (data[j] < data[min])
            {
                min = j;
            }
        }
        // 交换
        if (min != i)
        {
            int temp = data[i];
            data[i] = data[min];
            data[min] = temp;
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
