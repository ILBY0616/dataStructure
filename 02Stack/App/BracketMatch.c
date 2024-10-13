#include <string.h>
#include <stdio.h>

#define size 10

void bracketMatch(char data[])
{
    char stack[size];
    int top = -1;
    for (int i = 0; i < strlen(data); i++)
    {
        // 右括号出栈
        if (data[i] == ')' || data[i] == ']')
        {
            if (top != -1 && (stack[top] == '(' && data[i] == ')' || stack[top] == '[' && data[i] == ']'))
            {
                printf("%c%c", stack[top], data[i]);
                top--;
            }
            else
            {
                break;
            }
        }
        // 左括号入栈
        else
        {
            stack[++top] = data[i];
        }
    }
}

int main()
{
    char data[6] = {'[', '(', ')', '(', ')', ']'};
    bracketMatch(data);
    return 0;
}
