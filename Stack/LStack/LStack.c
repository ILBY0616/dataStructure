#include <stdio.h>
#include <stdlib.h>

#define newSize 10
#define type int

// 统一重点：ToDo
// 统一提示：中文
// 统一注释：代码上方
// 统一状态：-1失败，0成功，1其他

// 链栈
typedef struct LStack
{
    type data;
    struct LStack* next;;
} LStack;

LStack* initiateStack()
{
    LStack* s = (LStack*)malloc(sizeof(LStack));
    s->next = NULL;
    return s;
}

int getStatus(LStack* s)
{
    int result;
    if (s->next == NULL)
    {
        result = -1;
    }
    else
    {
        result = 0;
    }
    return result;
}

int getTop(LStack* s,type* data)
{
    int result;
    if (s->next == NULL)
    {
        result = -1;
    }
    else
    {
        *data = s->next->data;
        result = 0;
    }
    return result;
}

int push(LStack* s,type data)
{
    int result;
    LStack* p = (LStack*)malloc(sizeof(LStack));
    if (p == NULL)
    {
        result = -1;
    }
    else
    {
        p->data = data;
        p->next = s->next;
        s->next = p;
        result = 0;
    }
    return result;
}

int pop(LStack* s,type* data)
{
    int result;
    if (s->next == NULL)
    {
        result = -1;
    }
    else
    {
        LStack* p = s->next;
        *data = p->data;
        s->next = p->next;
        free(p);
        result = 0;
    }
    return result;
}

void destroy(LStack* s)
{
    while (s->next != NULL)
    {
        LStack* p = s->next;
        s->next = p->next;
        free(p);
    }
    free(s);
}
