#include <LBTree.h>
#include <SLList.h>

// 直接插入排序带头结点单链表
bool insertSortList(SLList list)
{
    if (list == NULL || list->next == NULL)
    {
        return false;
    }
    SLList inserPrior = list->next;
    SLList inserCurrent = list->next->next;
    while (inserCurrent != NULL)
    {
        SLList findPrior = list, findCurrent = list->next;
        // 找到合适位置
        while (findCurrent->data <= inserCurrent->data)
        {
            findPrior = findPrior->next;
            findCurrent = findCurrent->next;
        }
        // 插入合适位置
        SLList pointer = inserCurrent;
        inserPrior->next = inserCurrent->next;
        inserCurrent = inserPrior->next;
        pointer->next = findCurrent;
        findPrior->next = pointer;
    }
    return true;
}

// 求结点在二叉树中的父结点
void findParentNode(LBTree tree, LBTree child, LBTree* parent)
{
    if (tree != NULL)
    {
        if (tree->left == child || tree->right == child)
        {
            *parent = tree;
        }
        findParentNode(tree->left, child, parent);
        findParentNode(tree->right, child, parent);
    }
}

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\10App.2020.exe
// 9 7 5 3 1
// 1 3 5 7 9
// ab^^c^^
// a
// Process finished with exit code 0

int main()
{
    SLList list = NULL;
    int data[5] = {9, 7, 5, 3, 1};
    buildSLListByTail(data, 5, &list);
    printSLList(list);
    insertSortList(list);
    printSLList(list);
    destroySLList(&list);

    LBTree tree = NULL, child = NULL, parent = NULL;
    buildLBTree(&tree);
    child = tree->left;
    findParentNode(tree, child, &parent);
    printf("%c", parent->data);
    destroyLBTree(&tree);
    return 0;
}
