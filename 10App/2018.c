#include <LBTree.h>
#include <SLList.h>

// 生成有序带头结点单链表a和b的有序并集c
void mergeSortList(SLList a, SLList b, SLList c)
{
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
}

// 统计邻接表存储的有向图中出度为零的结点数

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
    return 0;
}
