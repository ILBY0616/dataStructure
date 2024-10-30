#include <stdbool.h>
#include <stdlib.h>

// 找到递增序列中T[i]=i的下标
int findData(int T[], int n)
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

// A、B为两个起始下标为0的n阶对称矩阵，用两个起始下标为0一维数组压缩存储了两个矩阵的下三角元素，编写A、B矩阵相乘的函数
bool matrixMultiplication(int* A, int* B, int** C, int n)
{
    // 异常提前退出程序
    if (A == NULL || B == NULL || C == NULL || n < 1)
    {
        return false;
    }
    // 进行矩阵乘法计算，对称矩阵相乘等于对称矩阵
    for (int i = 0; i < n; i++) // 遍历每一行
    {
        for (int j = 0; j <= i; j++) // 遍历下三角
        {
            int a, b, c = 0; // c存储 C[i][j] 的结果
            for (int k = 0; k < n; k++)
            {
                // 计算 A[i][k] 和 B[k][j] 的索引，使用压缩存储
                if (i >= k)
                {
                    a = i * (i + 1) / 2 + k;
                }
                else
                {
                    a = k * (k + 1) / 2 + i;
                }
                if (j >= k)
                {
                    b = j * (j + 1) / 2 + k;
                }
                else
                {
                    b = k * (k + 1) / 2 + j;
                }
                // 累加乘积
                c += A[a] * B[b];
            }
            // 存储结果到 C[i][j]
            C[i][j] = c;
            C[j][i] = c;
        }
    }
    return true;
}

// 双向交替冒泡排序，一趟大的放后，一趟小的放前
bool DoubleBubble(int* a, int n)
{
    // 检查数组是否为空
    if (a == NULL || n <= 1)
    {
        return false;
    }
    int i = 0, j = n - 1, k; // i指向前端，j指向后端，k用来交换
    // 当i和j没有相遇时，继续循环
    while (i < j)
    {
        int f = 0; // f检查状态，暂存变量
        // 从前向后冒泡，大元素往后移动
        for (k = i; k < j; k++)
        {
            if (a[k] > a[k + 1])
            {
                // 记录发生交换,暂存交换变量
                f = a[k];
                a[k] = a[k + 1];
                a[k + 1] = f;
                f = (f != 0 ? f : 1);
            }
        }
        // 如果没有发生交换，说明数组已排序，提前退出
        if (f == 0)
        {
            break;
        }
        j--; // 后端边界左移
        f = 0; // 重置交换标志
        // 从后向前冒泡，小元素往前移动
        for (k = j; k > i; k--)
        {
            if (a[k] < a[k - 1])
            {
                // 记录发生交换,暂存交换变量
                f = a[k];
                a[k] = a[k - 1];
                a[k - 1] = f;
                f = (f != 0 ? f : 1);
            }
        }
        // 如果没有发生交换，说明数组已排序，提前退出
        if (f == 0)
        {
            break;
        }
        i++; // 前端边界右移
    }
    return true;
}

int main()
{
    return 0;
}