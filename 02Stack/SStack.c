#include "SStack.h"
#include <stdio.h>

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\02Stack.SStack.exe
// 10 9 8 7 6 5 4 3 2 1
// Process finished with exit code 0

int main()
{
    int i, data;
    SStack stack = NULL;
    initiateSStack(&stack);
    for (i = 0; i < 10; i++)
    {
        data = i + 1;
        pushSStack(stack, data);
    }
    for (int j = 0; j < i; j++)
    {
        getSStack(stack, &data);
        printf("%d ", data);
        popSStack(stack, &data);
    }
    destroySStack(&stack);
    return 0;
}
