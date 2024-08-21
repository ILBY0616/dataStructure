#include <stdio.h>

// 统一重点：ToDo
// 统一提示：中文
// 统一注释：代码上方
// 统一状态：-1失败，0成功，1其他

int isHeap(int data[], int length)
{
    int result = 0;
    for (int i = length / 2; i >= 1; i--)
    {
        if (2 * i <= length && data[i] > data[2 * i])
            result = -1;
        if (2 * i + 1 <= length && data[i] > data[2 * i + 1])
            result = -1;
    }
    return result;
}

int main()
{
    int data[100] = {0, 1, 2, 6, 4, 5, 6, 7};
    printf("%d", isHeap(data, 7));
    return 0;
}
