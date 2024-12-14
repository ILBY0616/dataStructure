#include <SStack.h>
#include <stdio.h>

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
