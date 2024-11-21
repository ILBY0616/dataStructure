#include <stdio.h>

// 折半插入排序
void foldSort(int data[], int length);
// 打印序列
void printFold(int data[], int length);

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\09Sort.InsertFoldSort.exe
// 9 8 7 6 5 4 3 2 1 0
// 0 1 2 3 4 5 6 7 8 9
//
// Process finished with exit code 0

int main()
{
    int data[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    printFold(data, 10);
    foldSort(data, 10);
    printFold(data, 10);
    return 0;
}

// 排序思想：
// 折半插入排序是一种改进的插入排序，采用折半查找的方式来确定待插入元素的位置，从而减少比较次数。
// 插入排序的基本思想是将待排序序列分为已排序序列和未排序序列，初始时已排序序列只有一个元素，然后从未排序序列中依次取出元素，
// 并将其插入到已排序序列的合适位置。在普通的插入排序中，插入位置通过顺序比较来确定，而折半插入排序通过二分查找（折半查找）来定位插入位置，
// 使得比较次数大大减少。
// 排序操作：
// 1. 排序趟数：折半插入排序的排序趟数与普通插入排序相同，为 n - 1 次。每次都从未排序序列中取出一个元素并插入到已排序序列中。
// 2. 比较次数：由于使用了折半查找来确定插入位置，因此每次查找的比较次数为 O(log_2^n)，这使得比较次数相比普通插入排序减少。
//    每一趟排序的比较次数为 O(log_2^n)，因此总的比较次数为 O(nlog_2^n)。
// 3. 移动次数：每趟排序中，待插入元素后的所有元素都需要向后移动以腾出插入位置，最多需要移动 i 次（i 从 1 到 n-1）。
//    所以总的移动次数为 O(n^2)，与普通插入排序相同。
// 4. 交换次数：没有直接的交换操作，只有移动元素的操作，因此交换次数为 0。所有的重排操作通过移动元素来完成。
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
