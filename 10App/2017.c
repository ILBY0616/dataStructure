#include "SLList.h"
#include "LBTree.h"

// 判断带头结点单链表是否中心对称
bool judgeSLListSymmetry(SLList list)
{
    if (list == NULL)
    {
        return false;
    }
    char stack[100];
    char queue[100];
    int top = -1, front = 0, rear = 0;
    SLList node = list->next;
    while (node != NULL)
    {
        stack[++top] = node->data;
        queue[rear++] = node->data;
        node = node->next;
    }
    while (top != -1 && front != rear)
    {
        if (stack[top--] != queue[front++])
        {
            return false;
        }
    }
    return true;
}

// 求带头结点单链表a和b的交集c
bool generateIntersection(SLList a, SLList b, SLList c)
{
    if (a == NULL || b == NULL || c == NULL)
    {
        return false;
    }
    for (SLList i = a->next; i != NULL; i = i->next)
    {
        for (SLList j = b->next; j != NULL; j = j->next)
        {
            if (j->data == i->data)
            {
                SLList k = malloc(sizeof(ListNode));
                if (k != NULL)
                {
                    k->data = j->data;
                    k->next = c->next;
                    c->next = k;
                }
                else
                {
                    return false;
                }
                break;
            }
        }
    }
    return true;
}

// 计算二叉树的高度和宽度
// 见LBTree int getHeightLBTree(LBTree tree); int getWidthLBTree(LBTree tree);

int main()
{
    SLList a = NULL, b = NULL, c = NULL;
    int dataA[5] = {1, 2, 3, 4, 5};
    int dataB[5] = {5, 6, 7, 8, 9};
    buildSLListByTail(dataA, 5, &a);
    buildSLListByTail(dataB, 5, &b);
    initiateSLList(&c);
    generateIntersection(a, b, c);
    printSLList(a);
    printSLList(b);
    printSLList(c);
    if (judgeSLListSymmetry(c))
    {
        printf("right\n");
    }
    else
    {
        printf("error\n");
    }
    destroySLList(&a);
    destroySLList(&b);
    destroySLList(&c);
    return 0;
}
