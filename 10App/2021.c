#include <ATGraph.h>
#include <LBTree.h>
#include <SLList.h>

// 简单选择排序带头结点单链表（一趟排序可以确定最终位置，可以只交换值不换指针）
bool straightSelectSortSLList(SLList list)
{
    if (list == NULL || list->next == NULL)
    {
        return false;
    }
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
    return true;
}

// 求n个结点的逆邻接表
ATGraph createInverseGraph(ATGraph graph)
{
    ATGraph inverseGraph = NULL;
    initiateATGraph(&inverseGraph);
    inverseGraph->vertexSum = graph->vertexSum;
    inverseGraph->edgeSum = graph->edgeSum;
    // 初始化逆邻接表的顶点
    for (int i = 0; i < inverseGraph->vertexSum; i++)
    {
        inverseGraph->vertex[i].data = graph->vertex[i].data;
        inverseGraph->vertex[i].first = NULL;
    }
    // 遍历原图的邻接表，构建逆邻接表
    for (int i = 0; i < graph->vertexSum; i++)
    {
        Edge* edge = graph->vertex[i].first;
        while (edge != NULL)
        {
            int targetIndex = -1;
            // 找到目标顶点的索引
            for (int j = 0; j < graph->vertexSum; j++)
            {
                if (graph->vertex[j].data == edge->data)
                {
                    targetIndex = j;
                    break;
                }
            }
            // 添加逆边
            if (targetIndex != -1)
            {
                Edge* inverseEdge = malloc(sizeof(Edge));
                if (inverseEdge != NULL)
                {
                    inverseEdge->data = graph->vertex[i].data; // 原顶点成为目标顶点的边
                    inverseEdge->next = inverseGraph->vertex[targetIndex].first;
                    inverseGraph->vertex[targetIndex].first = inverseEdge;
                }
            }
            edge = edge->next;
        }
    }
    return inverseGraph;
}

// 递归交换左右子树
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
// 2 1
// Input vertex 0's value:
// a
// Input vertex 1's value:
// b
// Input startIndex endIndex:
// 0 1
// ATGraph:
// a->b
// b
// ATGraph:
// a
// b->a
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
    straightSelectSortSLList(list);
    printSLList(list);
    destroySLList(&list);

    ATGraph graph = NULL;
    initiateATGraph(&graph);
    createDATGraph(graph);
    printATGraph(graph);
    ATGraph inverseGraph = createInverseGraph(graph);
    printATGraph(inverseGraph);
    destroyATGraph(&graph);
    destroyATGraph(&inverseGraph);
    getchar();

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
