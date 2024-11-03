#include <stddef.h>

#include "SLList.h"
#include "LBTree.h"
#include "ATGraph.h"

// 简单选择排序带头结点单链表（只交换值不换指针）
bool sortSLList(SLList list);
// 求n个结点的逆邻接表
void createInverseGraph(Graph* original, Graph* inverse);
// 递归交换左右子树
void swapChild(LBTree tree);

int main()
{
    SLList list = NULL;
    int data[5] = {5, 2, 3, 1, 4};
    buildSLListByTail(data, 5, &list);
    printSLList(list);
    sortSLList(list);
    printSLList(list);
    destroySLList(&list);

    LBTree tree = NULL;
    createLBTree(&tree);
    preOrderByRecursion(tree);
    swapChild(tree);
    preOrderByRecursion(tree);
    destroyLBTree(&tree);

    return 0;
}

bool sortSLList(SLList list)
{
    if (list == NULL || list->next == NULL)
    {
        return false;
    }
    SLList current = list->next;
    while (current != NULL)
    {
        SLList currentMin = current, nextMin = current->next;
        // 找到这轮最小
        while (nextMin != NULL)
        {
            if (nextMin->data < currentMin->data)
            {
                currentMin = nextMin;
            }
            nextMin = nextMin->next;
        }
        // 交换最小数据
        if (currentMin != current)
        {
            int temp = currentMin->data;
            currentMin->data = current->data;
            current->data = temp;
        }
        // 进入下轮查找
        current = current->next;
    }
    return true;
}

// void createInverseGraph(Graph* original, Graph* inverse)
// {
//     // 初始化逆图
//     inverse->vertexSum = original->vertexSum;
//     inverse->edgeSum = original->edgeSum;
//
//     for (int i = 0; i < inverse->vertexSum; i++)
//     {
//         inverse->vertexList[i].data = original->vertexList[i].data;
//         inverse->vertexList[i].first = NULL;
//     }
//
//     // 遍历原图的边，反转边的方向
//     for (int i = 0; i < original->vertexSum; i++)
//     {
//         Edge* edge = original->vertexList[i].first;
//         while (edge != NULL)
//         {
//             Edge* newEdge = malloc(sizeof(Edge));
//             if (newEdge != NULL)
//             {
//                 newEdge->data = i; // 反转方向
//                 newEdge->next = inverse->vertexList[edge->data].first;
//                 inverse->vertexList[edge->data].first = newEdge;
//             }
//             edge = edge->next;
//         }
//     }
// }

void swapChild(LBTree tree)
{
    if (tree != NULL)
    {
        LBTree temp = tree->left;
        tree->left = tree->right;
        tree->right = temp;
        swapChild(tree->left);
        swapChild(tree->right);
    }
}
