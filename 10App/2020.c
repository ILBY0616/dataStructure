#include <AMGraph.h>
#include <ATGraph.h>
#include <LBTree.h>
#include <SLList.h>

// 实现带头结点单链表的直接插入排序算法
void sortSLList(SLList list)
{
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
}

// 查找结点key在链式二叉树中的父结点
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

// 编写邻接矩阵存储图转换为邻接表存储图的程序
void toATGraph(AMGraph amGraph, ATGraph* atGraph)
{
    // 初始化邻接表
    (*atGraph)->vertexSum = amGraph->vertexSum;
    (*atGraph)->edgeSum = amGraph->edgeSum;
    for (int i = 0; i < amGraph->vertexSum; i++)
    {
        (*atGraph)->vertex[i].data = amGraph->vertex[i];
        (*atGraph)->vertex[i].first = NULL;
    }
    // 遍历邻接矩阵，建立邻接表
    for (int i = 0; i < amGraph->vertexSum; i++)
    {
        for (int j = 0; j < amGraph->vertexSum; j++)
        {
            if (0 < amGraph->edge[i][j] && amGraph->edge[i][j] < INT_MAX)
            {
                Edge* edge = malloc(sizeof(Edge));
                if (edge != NULL)
                {
                    edge->index = j;
                    edge->weight = amGraph->edge[i][j];
                    edge->next = (*atGraph)->vertex[i].first;
                    (*atGraph)->vertex[i].first = edge;
                }
            }
        }
    }
}

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\10App.2020.exe
// 9 7 5 3 1
// 1 3 5 7 9
// ab^^c^^
// a
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
// AMGraph:
// ^ 1 ^ ^
// ^ ^ 2 ^
// ^ ^ ^ 3
// ^ ^ ^ ^
// ATGraph:
// a->1
// b->2
// c->3
// d
//
// Process finished with exit code 0

int main()
{
    SLList list = NULL;
    int data[5] = {9, 7, 5, 3, 1};
    buildSLListByTail(data, 5, &list);
    printSLList(list);
    sortSLList(list);
    printSLList(list);
    destroySLList(&list);

    LBTree tree = NULL, child = NULL, parent = NULL;
    buildLBTree(&tree);
    child = tree->left;
    findParentNode(tree, child, &parent);
    printf("%c\n", parent->data);
    destroyLBTree(&tree);

    AMGraph amGraph = NULL;
    ATGraph atGraph = NULL;
    initiateAMGraph(&amGraph);
    initiateATGraph(&atGraph);
    createDAMGraph(amGraph);
    toATGraph(amGraph, &atGraph);
    printAMGraph(amGraph);
    printATGraph(atGraph);
    destroyAMGraph(&amGraph);
    destroyATGraph(&atGraph);
    return 0;
}
