#include <stdio.h>

// 找到递增数组T[1-n]中T[i]=i的下标
int findI(int T[], int n);
// A、B为两个起始下标为0的n阶对称矩阵，用两个起始下标为0一维数组压缩存储了两个矩阵的下三角元素，编写A、B矩阵相乘的函数，注意结果不一定是对称矩阵
// 见DMatrix void multiplyDMartrix(DMatrix leftFactor, DMatrix rightFactor, int finalProduct[100][100]);
// 双向交替冒泡排序，一趟大的放后，一趟小的放前
// 见SwapBubbleSort void doubleBubble(int data[], int length);

int main()
{
    int data[10] = {9, 8, 7, 6, 4, 5, 3, 2, 1, 0};
    printf("%d\n", findI(data, 10));
    return 0;
}

int findI(int T[], int n)
{
    if (n < 1)
    {
        return -1;
    }
    int low = 1, high = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (T[mid] == mid)
        {
            return mid;
        }
        if (T[mid] > mid)
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
