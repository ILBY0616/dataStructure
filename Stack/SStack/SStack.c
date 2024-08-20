#define maxSize 10
#define type int

// 统一重点：ToDo
// 统一提示：中文
// 统一注释：代码上方
// 统一状态：-1栈空，0栈余，1栈满

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
