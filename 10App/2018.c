#include <ATGraph.h>
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
    a->next = NULL;
    b->next = NULL;
    k->next = i != NULL ? i : j;
}

// 统计邻接表存储的有向图中出度为零的结点数
int getZeroSum(ATGraph graph)
{
    int sum = 0;
    for (int i = 0; i < graph->vertexSum; i++)
    {
        if (graph->vertex[i].first == NULL)
        {
            sum++;
        }
    }
    return sum;
}

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\10App.2018.exe
// 1 2 3 4 5
// 5 6 7 8 9
// 1 2 3 4 5 5 6 7 8 9
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

    ATGraph graph = NULL;
    initiateATGraph(&graph);
    createDATGraph(graph);
    printf("%d", getZeroSum(graph));
    destroyATGraph(&graph);
    return 0;
}
