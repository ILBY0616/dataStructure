#include <stddef.h>
#include <stdio.h>

#include "SLList.h"
#include "LBTree.h"

// 直接插入排序带头结点单链表
bool sortSLList(SLList list);
// 求结点在二叉树中的父结点
void findParent(LBTree tree, LBTree child, LBTree* parent);

int main()
{
    SLList list = NULL;
    int data[5] = {5, 2, 3, 1, 4};
    buildSLListByTail(data, 5, &list);
    printSLList(list);
    sortSLList(list);
    printSLList(list);
    destroySLList(&list);

    LBTree tree = NULL, child = NULL, parent = NULL;
    createLBTree(&tree);
    child = tree->left;
    findParent(tree, child, &parent);
    printf("%c", parent->data);
    destroyLBTree(&tree);
    return 0;
}

bool sortSLList(SLList list)
{
    if (list == NULL || list->next == NULL)
    {
        return false;
    }
    SLList inserPrior = list->next;
    SLList inserNext = list->next;
    while (inserNext != NULL)
    {
        SLList findPrior = list, findNext = list->next;
        // 找到合适位置
        while (findNext->data < inserNext->data)
        {
            findPrior = findPrior->next;
            findNext = findNext->next;
        }
        // 插入合适位置
        SLList temp = inserNext;
        inserPrior->next = inserNext->next;
        inserNext = inserNext->next;
        temp->next = findNext;
        findPrior->next = temp;
    }
    return true;
}

void findParent(LBTree tree, LBTree child, LBTree* parent)
{
    if (tree->left == child || tree->right == child)
    {
        *parent = tree;
        return;
    }
    findParent(tree->left, child, parent);
    findParent(tree->right, child, parent);
}
