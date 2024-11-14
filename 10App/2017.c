#include <LBTree.h>
#include <SLList.h>

// 判断带头结点单链表是否中心对称
bool judgeSymmetry(SLList list)
{
    if (list == NULL)
    {
        return false;
    }
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

// 求带头结点单链表a和b的交集c
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

// 递归计算二叉树的高度
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

// 计算二叉树的宽度
int getWidth(LBTree tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    LBTree queue[100];
    int front = -1, rear = -1, last = 0, width = 0;
    queue[++rear] = tree;
    while (front != rear)
    {
        if (rear == last)
        {
            width = rear - front > width ? rear - front : width;
        }
        LBTree node = queue[++front];
        if (node->left != NULL)
        {
            queue[++rear] = node->left;
        }
        if (node->right != NULL)
        {
            queue[++rear] = node->right;
        }
        if (front == last)
        {
            last = rear;
        }
    }
    return width;
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


    if (judgeSymmetry(c))
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
    createLBTree(&tree);
    printf("%d %d\n", getHeight(tree), getWidth(tree));
    destroyLBTree(&tree);
    return 0;
}
