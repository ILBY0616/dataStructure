#include <stdio.h>

// 计数排序
void countSort(int data[], int length);
// 打印序列
void printCount(int data[], int length);

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\09Sort.CountSort.exe
// 9 8 7 6 5 4 3 2 1 0
// 0 1 2 3 4 5 6 7 8 9
//
// Process finished with exit code 0

int main()
{
    int data[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    printCount(data, 10);
    countSort(data, 10);
    printCount(data, 10);
    return 0;
}

// 通过比较每一个元素比其小元素的个数实现序列排序
void countSort(int data[], int length)
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

void printCount(int data[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}
