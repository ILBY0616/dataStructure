#include "SLList.h"

// 合并两个循环单链表
void judgeSymmetry(SLList* a, SLList* b)
{
    SLList tailA = *a, tailB = *b;
    while (tailA->next != *a)
    {
        tailA = tailA->next;
    }
    while (tailB->next != *b)
    {
        tailB = tailB->next;
    }
    tailA->next = *b;
    tailB->next = *a;
}

int main()
{
    return 0;
}
