#include <LStack.h>
#include <stdio.h>

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
