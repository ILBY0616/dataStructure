#include "LStack.h"
#include <stdio.h>

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\02Stack.LStack.exe
// 10 9 8 7 6 5 4 3 2 1
// Process finished with exit code 0

int main()
{
    int i, data;
    LStack stack = NULL;
    initiateLStack(&stack);
    for (i = 0; i < 10; i++)
    {
        data = i + 1;
        pushLStack(&stack, data);
    }
    for (int j = 0; j < i; j++)
    {
        getLStack(stack, &data);
        printf("%d ", data);
        popLStack(&stack, &data);
    }
    destroyLStack(&stack);
    return 0;
}
