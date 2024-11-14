#include <stdio.h>

// 奇数在前偶数在后
void oddToFront(int data[], int length)
{
    for (int i = 0; i < length; i++)
    {
        int flag = 0;
        for (int j = 0; j < length - i - 1; j++)
        {
            if (data[j] % 2 == 0 && data[j + 1] % 2 == 1)
            {
                flag = data[j];
                data[j] = data[j + 1];
                data[j + 1] = flag;
                flag = flag != 0 ? flag : 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}

int main()
{
    int data[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    oddToFront(data, 8);
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", data[i]);
    }
    return 0;
}
