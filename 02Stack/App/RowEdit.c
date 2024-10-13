#include <stdio.h>

#define size 100

void rowEdit()
{
    char stack[size];
    int top = -1;
    char data = getchar();
    while (data != '^')
    {
        switch (data)
        {
        case '#':
            if (top != -1)
            {
                top--;
            }
            break;
        case '@':
            if (top != -1)
            {
                int i = top;
                while (i != -1 && stack[i] != '\n')
                {
                    i--;
                }
                top = i;
            }
            break;
        default:
            if (top != size - 1)
            {
                stack[++top] = data;
            }
            break;
        }
        data = getchar();
    }
    stack[top + 1] = '\0';
    printf("%s", stack);
}

int main()
{
    rowEdit();
    return 0;
}
