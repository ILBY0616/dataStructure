#include <stdbool.h>
#include <stdio.h>

// 找到递增数组data[]中data[i]=i的下标
bool findIndex(int data[], int length, int* index)
{
    if (length < 1)
    {
        return false;
    }
    int low = 0, high = length - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (data[mid] == mid)
        {
            *index = mid;
            return true;
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
    return false;
}

// 双向交替冒泡排序，一趟大的放后，一趟小的放前
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

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\10App.2006.exe
// 4
// 0 1 2 3 4 5 6 7 8 9
//
// Process finished with exit code 0

int main()
{
    int index = -1;
    int data[10] = {9, 8, 7, 6, 4, 5, 3, 2, 1, 0};
    findIndex(data, 10, &index);
    printf("%d\n", index);

    doubleBubble(data, 10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
    return 0;
}
