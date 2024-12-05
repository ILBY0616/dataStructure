#include <SStack.h>
#include <stdio.h>

// 设计编写顺序栈实现进制转换的程序
void baseConversion(SStack stack, int data)
{
    while (data > 0)
    {
        pushSStack(stack, data % 8);
        data /= 8;
    }
    while (stack->top != -1)
    {
        popSStack(stack, &data);
        printf("%d", data);
    }
}

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\10App.2010.exe
// 12
// Process finished with exit code 0

int main()
{
    SStack stack;
    initiateSStack(&stack);
    baseConversion(stack, 10);
    destroySStack(&stack);
    return 0;
}
