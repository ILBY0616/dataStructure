#include <LBTree.h>
#include <SLList.h>

// 合并带头结点有序单链表a和b到c，使c仍然有序
bool mergeSortList(SLList a, SLList b, SLList c)
{
    if (a == NULL || b == NULL || c == NULL || c->next != NULL)
    {
        return false;
    }
    SLList i = a->next, j = b->next, k = c;
    while (i != NULL && j != NULL)
    {
        if (i->data < j->data)
        {
            k->next = i;
            i = i->next;
        }
        else
        {
            k->next = j;
            j = j->next;
        }
        k = k->next;
    }
    k->next = i != NULL ? i : j;
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

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\10App.2018.exe
// 1 2 3 4 5
// 5 6 7 8 9
// 1 2 3 4 5 5 6 7 8 9
// abd^^e^^cf^^g^^
// 3 4
//
// Process finished with exit code 0

int main()
{
    SLList a = NULL, b = NULL, c = NULL;
    int dataA[5] = {1, 2, 3, 4, 5};
    int dataB[5] = {5, 6, 7, 8, 9};
    buildSLListByTail(dataA, 5, &a);
    buildSLListByTail(dataB, 5, &b);
    printSLList(a);
    printSLList(b);
    initiateSLList(&c);
    mergeSortList(a, b, c);
    printSLList(c);
    destroySLList(&a);
    destroySLList(&b);
    destroySLList(&c);

    LBTree tree = NULL;
    createLBTree(&tree);
    printf("%d %d\n", getHeight(tree), getWidth(tree));
    destroyLBTree(&tree);
    return 0;
}
