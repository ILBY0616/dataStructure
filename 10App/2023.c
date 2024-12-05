#include <AMGraph.h>
#include <LBTree.h>
#include <SLList.h>
#include <stdio.h>

// 删除递增有序带头结点单链表中值在(a,b)区间的元素
void purgeSLList(SLList list, int a, int b)
{
    SLList prior = list, current = list->next;
    while (current != NULL)
    {
        if (a < current->data && current->data < b)
        {
            prior->next = current->next;
            free(current);
            current = prior->next;
        }
        else
        {
            prior = current;
            current = current->next;
        }
    }
}

// 编写高为height的顺序存储二叉树data[1,n]转换为链式存储二叉树的程序
void toLBTree(LBTree* tree, char* data, int length)
{
    LBTree node[length];
    for (int i = 0; i < length; i++)
    {
        node[i] = (LBTree)malloc(sizeof(struct LBTreeNode));
        if (node[i] != NULL)
        {
            if (data[i] != '^')
            {
                node[i]->data = data[i];
                node[i]->left = NULL;
                node[i]->right = NULL;
            }
            else
            {
                node[i] = NULL;
            }
        }
    }
    for (int i = 0; i < length; i++)
    {
        if (node[i] != NULL)
        {
            if (2 * i + 1 < length && node[2 * i + 1] != NULL)
            {
                node[i]->left = node[2 * i + 1];
            }
            if (2 * i + 2 < length && node[2 * i + 2] != NULL)
            {
                node[i]->right = node[2 * i + 2];
            }
        }
    }
    *tree = node[0];
}

// 统计邻接矩阵存储的有向图中出度为零的结点数
int getZeroSum(AMGraph graph)
{
    int sum = 0;
    for (int i = 0; i < graph->vertexSum; i++)
    {
        int flag = 0;
        for (int j = 0; j < graph->vertexSum; j++)
        {
            if (0 < graph->edge[i][j] && graph->edge[i][j] < INT_MAX)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            sum++;
        }
    }
    return sum;
}

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\10App.2023.exe
// 1 2 3 4 5 6 7 8 9 10
// 1 2 9 10
// abcdefghi
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
// 1
// Process finished with exit code 0

int main()
{
    SLList list = NULL;
    int intData[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    buildSLListByTail(intData, 10, &list);
    printSLList(list);
    purgeSLList(list, 2, 9);
    printSLList(list);
    destroySLList(&list);

    LBTree tree = NULL;
    char charData[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
    toLBTree(&tree, charData, 10);
    levelOrderLBTree(tree);
    printf("\n");
    destroyLBTree(&tree);

    AMGraph graph = NULL;
    initiateAMGraph(&graph);
    createDAMGraph(graph);
    printf("%d", getZeroSum(graph));
    destroyAMGraph(&graph);
    return 0;
}
