#include "SLList.h"

// 合并两个循环单链表
void judgeSymmetry(List* a, List* b)
{
    List tailA = *a, tailB = *b;
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
