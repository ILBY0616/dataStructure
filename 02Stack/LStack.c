#include "LStack.h"
#include <stdio.h>

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\02Stack.LStack.exe
// 10 9 8 7 6 5 4 3 2 1
// Process finished with exit code 0

int main()
{
    int i;
    LStack stack = NULL;
    initiateLStack(&stack);
    for (i = 0; i < 10; i++)
    {
        pushLStack(&stack, i + 1);
    }
    for (int j = 0; j < i; j++)
    {
        printf("%d ", getLStack(stack));
        popLStack(&stack);
    }
    destroyLStack(&stack);
    return 0;
}