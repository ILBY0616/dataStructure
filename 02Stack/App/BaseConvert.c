#include <stdio.h>

#define size 10

void baseConvert(int data)
{
    int stack[size];
    int top = -1;
    // 进栈
    while (data != 0)
    {
        // 求余
        stack[++top] = data % 8;
        // 取整
        data = data / 8;
    }
    // 出栈
    while (top != -1)
    {
        printf("%d", stack[top--]);
    }
}

int main()
{
    baseConvert(1348);
    return 0;
}
