#include <stdio.h>

typedef struct Node
{
    int data;
    int rank;
    struct Node *prior, *next;
} Node, *List;

// 设头指针为L的带有表头结点的非循环双向链表，其每个结点中除有pred
// (前驱指针)、data(数据)和next(后继指针)域外，还有一个访问频度域
// fireg。在链表被启用前，其值均初始化为零。每当在链表中进行一次Locate
// (L,x)运算时，令元素值为X的结点中freq域的值增加1，并使此链表中结点
// 保持按访问频度非(递减)的顺序排列，同时，最近访问的结点拍在频度相
// 同的结点前面，以便使频繁访问的结点总是靠近表头。使编写符合上述要求
// 的Locate(L,x)
// 运算的算法，该运算为函数过程，返回找到结点的地址，类
// 型为指针型。
List getLocation(List* l, int data)
{
    List p = (*l)->next;
    while (p != NULL && p->data != data)
    {
        p = p->next;
    }
    if (p != NULL)
    {
        p->rank++;
        p->prior->next = p->next;
        p->next->prior = p->prior;
        List q = (*l)->next;
        while (q != NULL)
        {
            if (p->rank >= q->rank)
            {
                p->prior = q->prior;
                p->next = q;
                p->prior->next = p;
                p->next->prior = p;
            }
        }
        return p;
    }
    return NULL;
}
