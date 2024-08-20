#define maxSize 10
#define length 6
#define type char
#include <stdio.h>

// 统一重点：ToDo
// 统一提示：中文
// 统一注释：代码上方
// 统一状态：-1栈空或失败 0栈余或成功 1栈满或其他

// 顺序栈
typedef struct SStack
{
    type data[maxSize];
    int top;
} SStack;

void initiateStack(SStack* s)
{
    s->top = -1;
}

int getStatus(SStack* s)
{
    int result;
    if (s->top == -1)
    {
        result = -1;
    }
    else if (s->top + 1 == maxSize)
    {
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}

int getTop(SStack* s,type* data)
{
    int result;
    if (s->top == -1)
    {
        result = -1;
    }
    else
    {
        *data = s->data[s->top];
        result = 0;
    }
    return result;
}

int pushData(SStack* s,type data)
{
    int result;
    if (s->top + 1 == maxSize)
    {
        result = 1;
    }
    else
    {
        s->data[++s->top] = data;
        result = 0;
    }
    return result;
}

int popData(SStack* s,type* data)
{
    int result;
    if (s->top == -1)
    {
        result = -1;
    }
    else
    {
        *data = s->data[s->top--];
        result = 0;
    }
    return result;
}

void destroyStack(SStack* s)
{
    s->top = -1;
}

int matchBracket(SStack* s,type inData[length],type outData[length])
{
    int result = 0, sum = 0;
    for (int i = 0; i < length; i++)
    {
        if (inData[i] == '(' || inData[i] == '[')
        {
            if (i + 1 != length)
            {
                pushData(s, inData[i]);
            }
            else
            {
                destroyStack(s);
                result = 1;
                break;
            }
        }
        else
        {
            type topData;
            if (getTop(s, &topData) == 0)
            {
                if ((topData == '(' && inData[i] == ')') || (topData == '[' && inData[i] == ']'))
                {
                    popData(s, &topData);
                    outData[sum++] = topData;
                    outData[sum++] = inData[i];
                }
                else
                {
                    destroyStack(s);
                    result = 1;
                    break;
                }
            }
            else
            {
                result = -1;
                break;
            }
        }
    }
    return result;
}

int main()
{
    type inData[length] = {'(', '[', '(', ')', ']', '['};
    type outData[length] = {0};
    SStack s;
    initiateStack(&s);
    int result = matchBracket(&s, inData, outData);
    for (int i = 0; i < length; i++)
    {
        printf("%c", outData[i]);
    }
    printf("\n");
    for (int i = 0; i <= s.top; i++)
    {
        printf("%c", s.data[i]);
    }
    printf("\n");
    printf("%d", result);
    printf("\n");
    return 0;
}
