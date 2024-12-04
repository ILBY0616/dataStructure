#include <stdio.h>

// 找到递增互异整数数组中data[i]=i的下标i
int findIndex(int* data, int length)
{
    int low = 0, high = length - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (data[mid] == mid)
        {
            return mid;
        }
        if (data[mid] > mid)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

// 编写压缩存储的对称矩阵乘法程序
// 见04Array.DMartrix.h中

// 编写实现双向交替冒泡排序算法的程序
void doubleBubble(int* data, int length)
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

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\10App.2006.exe
// 4
// 0 1 2 3 4 5 6 7 8 9
//
// Process finished with exit code 0

int main()
{
    int length = 10;
    int data[10] = {9, 8, 7, 6, 4, 5, 3, 2, 1, 0};
    printf("%d\n", findIndex(data, length));

    doubleBubble(data, length);
    for (int i = 0; i < length; i++)
    {
        printf("%d ", data[i]);
    }
    return 0;
}
