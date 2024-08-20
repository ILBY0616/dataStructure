#include <stdio.h>

typedef enum { Red, White, Blue, Error } color;

// 统一重点：ToDo
// 统一提示：中文
// 统一注释：代码上方
// 统一状态：-1失败，0成功，1其他

// ToDo遍历三次，两两比较交换两次，Red在data[1]，White在data[2]，剩下的自然有序
// ExchangeSort

char* toString(color data)
{
    switch (data)
    {
    case Red:
        return "Red";
    case White:
        return "White";
    case Blue:
        return "Blue";
    default:
        return "Error";
    }
}

void sortData(color data[], int length)
{
    for (int i = 1; i <= length; i++)
    {
        if (data[i] == Red)
        {
            data[0] = data[1];
            data[1] = data[i];
            data[i] = data[0];
        }
        if (data[i] == White)
        {
            data[0] = data[2];
            data[2] = data[i];
            data[i] = data[0];
        }
    }
}

void printData(color data[], int length)
{
    for (int i = 1; i <= length; i++)
    {
        printf("%s", toString(data[i]));
    }
    printf("\n");
}

int main()
{
    color data[4] = {Error, Blue, Red, White};
    printData(data, 3);
    sortData(data, 3);
    printData(data, 3);
    return 0;
}
