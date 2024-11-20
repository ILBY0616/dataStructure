#include <stdio.h>

// 希尔插入排序
void shellSort(int data[], int length);
// 打印序列
void printShell(int data[], int length);

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\09Sort.InsertShellSort.exe
// 9 8 7 6 5 4 3 2 1 0
// 0 1 2 3 4 5 6 7 8 9
//
// Process finished with exit code 0

int main()
{
    int data[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    printShell(data, 10);
    shellSort(data, 10);
    printShell(data, 10);
    return 0;
}

// 以首个元素为已排序序列，以剩余元素为待排序序列
// 逐个在待排序序列中选择元素与已排序序列中的元素通过比较大小找到合适位置
// 移动元素空出合适位置，然后插入待排序元素
// n个元素进行n-1趟排序，每趟排序包含比较移动插入，比较次数、移到次数、插入次数取决于待排序序列初始状态
// 主要优化在于用d切割出了多个子序列，使得在d=1前让整体序列基本有序从而提高排序效率
void shellSort(int data[], int length)
{
    for (int d = length / 2; d >= 1; d = d / 2)
    {
        // 分割
        for (int i = d; i < length; i += d)
        {
            if (data[i] < data[i - d])
            {
                int temp = data[i];
                int j = i - d;
                // 比较
                while (j >= 0 && data[j] > temp)
                {
                    // 移动
                    data[j + d] = data[j];
                    j -= d;
                }
                // 插入
                data[j + d] = temp;
            }
        }
    }
}

void printShell(int data[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}
