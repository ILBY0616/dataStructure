#include <stdio.h>

// 直接插入排序
void insertSort(int data[], int length);
// 打印序列
void printInsert(int data[], int length);

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\09Sort.InsertStraightSort.exe
// 9 8 7 6 5 4 3 2 1 0
// 0 1 2 3 4 5 6 7 8 9
//
// Process finished with exit code 0

int main()
{
    int data[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    printInsert(data, 10);
    insertSort(data, 10);
    printInsert(data, 10);
    return 0;
}

// 排序思想：
// 直接插入排序是一种简单的排序算法，它的基本思想是将待排序元素逐个插入到已排序序列中。每次将待排序序列中的第一个元素插入到已排序序列中的适当位置。
// 具体做法是从第二个元素开始，依次与前面的已排序元素进行比较，将较大的元素向后移动，直到找到合适的位置。
// 这种排序方法适用于数据量较小或者序列本身基本有序的情况，虽然在最坏情况下其时间复杂度为 O(n^2)，但是对于基本有序的序列来说，性能表现较好。
// 排序操作：
// 1. 排序趟数：直接插入排序需要进行 n-1 次排序操作，每次将一个待排序元素插入到已排序序列中。
// 2. 比较次数：每次插入一个元素时，需要与已排序的元素逐一比较，直到找到合适的位置。最坏情况下，比较次数为 O(n^2)，而最佳情况下（已排序序列）为 O(n)。
// 3. 移动次数：每次插入元素时，已排序序列中大于该元素的部分都需要后移。最坏情况下，每个元素都需要移动到最前面，总的移动次数为 O(n^2)。
// 4. 交换次数：在直接插入排序中，没有显式的交换操作，而是通过移动元素来实现排序，因此交换次数为 0。
void insertSort(int data[], int length)
{
    for (int i = 1; i < length; i++)
    {
        if (data[i] < data[i - 1])
        {
            int temp = data[i];
            int j = i - 1;
            // 比较
            while (j >= 0 && data[j] > temp)
            {
                // 移动
                data[j + 1] = data[j];
                j--;
            }
            // 插入
            data[j + 1] = temp;
        }
    }
}

void printInsert(int data[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}
