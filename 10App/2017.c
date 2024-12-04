#include <LBTree.h>
#include <SLList.h>

// 判断带头结点单链表是否中心对称
bool isSymmetry(SLList list)
{
    char stack[100];
    char queue[100];
    int top = -1, front = -1, rear = -1;
    SLList node = list->next;
    while (node != NULL)
    {
        stack[++top] = node->data;
        queue[++rear] = node->data;
        node = node->next;
    }
    while (top != -1 && front != rear)
    {
        if (stack[top--] != queue[++front])
        {
            return false;
        }
    }
    return true;
}

// 生成带头结点单链表a和b的交集c
bool getIntersection(SLList a, SLList b, SLList c)
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
                break;
            }
        }
    }
    return true;
}

// 计算链式二叉树的高度和宽度
// 见06Tree.LBTree.h
int getHeight(LBTree tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    int leftHeight = getHeight(tree->left);
    int rightHeight = getHeight(tree->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\10App.2017.exe
// 1 2 3 4 5
// 5 6 7 8 9
// 5
// right
// ab^^c^^
// 2 2
//
// Process finished with exit code 0

int main()
{
    SLList a = NULL, b = NULL, c = NULL;
    int dataA[5] = {1, 2, 3, 4, 5};
    int dataB[5] = {5, 6, 7, 8, 9};
    buildSLListByTail(dataA, 5, &a);
    buildSLListByTail(dataB, 5, &b);
    initiateSLList(&c);
    getIntersection(a, b, c);
    printSLList(a);
    printSLList(b);
    printSLList(c);


    if (isSymmetry(c))
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

    LBTree tree = NULL;
    buildLBTree(&tree);
    printf("%d", getHeight(tree));
    destroyLBTree(&tree);
    return 0;
}
