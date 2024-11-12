#include <stdio.h>

// 折半插入排序
void foldSort(int data[], int length);
// 打印序列
void printFold(int data[], int length);

int main()
{
    int data[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    printFold(data, 10);
    foldSort(data, 10);
    printFold(data, 10);
    return 0;
}

// 以首个元素为已排序序列，以剩余元素为待排序序列
// 逐个在待排序序列中选择元素与已排序序列中的元素通过折半查找找到合适位置
// 移动元素空出合适位置，然后插入待排序元素
// n个元素进行n-1趟排序，每趟排序包含比较移动插入，移到次数、插入次数取决于待排序序列初始状态
// 主要优化在于由逐一比较查找合适位置改为折半查找合适位置，因而比较次数不取决于待排序序列初始状态、
void foldSort(int data[], int length)
{
    for (int i = 1; i < length; i++)
    {
        int temp = data[i];
        int low = 0, high = i - 1;
        // 查找
        while (low <= high)
        {
            int mid = (low + high) / 2;
            // 比较
            if (temp < data[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        // 移动
        for (int j = i - 1; j >= high + 1; j--)
            data[j + 1] = data[j];
        // 插入
        data[high + 1] = temp;
    }
}

void printFold(int data[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}
