#include <ATGraph.h>
#include <LBTree.h>
#include <SLList.h>

// 实现带头结点单链表的简单选择排序算法
void sortSLList(SLList list)
{
    SLList pointer = list->next;
    while (pointer != NULL)
    {
        SLList currentMin = pointer, nextMin = pointer->next;
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
        if (currentMin != pointer)
        {
            int data = pointer->data;
            pointer->data = currentMin->data;
            currentMin->data = data;
        }
        // 进入下轮查找
        pointer = pointer->next;
    }
}

// 编写邻接表存储图转换为逆邻接表存储图的程序
void getInverseATGraph(ATGraph originGraph, ATGraph* inverseGraph)
{
    // 初始化逆邻接表值
    (*inverseGraph)->vertexSum = originGraph->vertexSum;
    (*inverseGraph)->edgeSum = originGraph->edgeSum;
    for (int i = 0; i < originGraph->vertexSum; i++)
    {
        (*inverseGraph)->vertex[i].data = originGraph->vertex[i].data;
        (*inverseGraph)->vertex[i].first = NULL;
    }
    // 遍历原邻接表，建立逆邻接表
    for (int i = 0; i < originGraph->vertexSum; i++)
    {
        Edge* edge = originGraph->vertex[i].first;
        while (edge != NULL)
        {
            Edge* newEdge = malloc(sizeof(Edge));
            if (newEdge != NULL)
            {
                newEdge->index = i;
                newEdge->weight = edge->weight;
                newEdge->next = (*inverseGraph)->vertex[edge->index].first;
                (*inverseGraph)->vertex[edge->index].first = newEdge;
            }
            edge = edge->next;
        }
    }
}

// 编写交换链式二叉树左右子树的程序
void swapChild(LBTree tree)
{
    if (tree != NULL)
    {
        LBTree pointer = tree->left;
        tree->left = tree->right;
        tree->right = pointer;
        swapChild(tree->left);
        swapChild(tree->right);
    }
}

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\10App.2021.exe
// 5 2 3 1 4
// 1 2 3 4 5
// Input vertexSum edgeSum:
// 4 3
// Input vertex 0's value:
// a
// Input vertex 1's value:
// b
// Input vertex 2's value:
// c
// Input vertex 3's value:
// d
// Input startIndex endIndex weight:
// 0 1 1
// Input startIndex endIndex weight:
// 1 2 2
// Input startIndex endIndex weight:
// 2 3 3
// ATGraph:
// a->1
// b->2
// c->3
// d
// ATGraph:
// a
// b->0
// c->1
// d->2
// ab^^c^^
// abc
// acb
//
// Process finished with exit code 0

int main()
{
    SLList list = NULL;
    int data[5] = {5, 2, 3, 1, 4};
    buildSLListByTail(data, 5, &list);
    printSLList(list);
    sortSLList(list);
    printSLList(list);
    destroySLList(&list);

    ATGraph originGraph = NULL, inverseGraph = NULL;
    initiateATGraph(&originGraph);
    initiateATGraph(&inverseGraph);
    createDATGraph(originGraph);
    printATGraph(originGraph);
    getInverseATGraph(originGraph, &inverseGraph);
    printATGraph(inverseGraph);
    destroyATGraph(&originGraph);
    destroyATGraph(&inverseGraph);

    LBTree tree = NULL;
    buildLBTree(&tree);
    preOrderLBTree(tree);
    printf("\n");
    swapChild(tree);
    preOrderLBTree(tree);
    printf("\n");
    destroyLBTree(&tree);
    return 0;
}
