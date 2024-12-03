#include <LBTree.h>
#include <SLList.h>

// 将带头结点单链表中最小结点移到最前面
bool minToFront(SLList list)
{
    if (list == NULL || list->next == NULL)
    {
        return false;
    }
    SLList priorMin = list, currentMin = list->next, priorFind = list, currentFind = list->next;
    while (currentFind != NULL)
    {
        if (currentFind->data < currentMin->data)
        {
            priorMin = priorFind;
            currentMin = currentFind;
        }
        priorFind = priorFind->next;
        currentFind = currentFind->next;
    }
    priorMin->next = currentMin->next;
    currentMin->next = list->next;
    list->next = currentMin;
    return true;
}

// 递归找到数组最大值
int findMaxValue(int data[], int length)
{
    if (length > 0)
    {
        int a = data[length - 1];
        int b = findMaxValue(data, length - 1);
        return a > b ? a : b;
    }
    return data[0];
}

// 计算叶子结点数目和非叶结点数目
void countNode(LBTree tree, int* leafNode, int* branchNode)
{
    if (tree != NULL)
    {
        if (tree->left != NULL || tree->right != NULL)
        {
            (*branchNode)++;
        }
        else
        {
            (*leafNode)++;
        }
        countNode(tree->left, leafNode, branchNode);
        countNode(tree->right, leafNode, branchNode);
    }
}

// 用邻接矩阵定义、创建图
// 见AMGraph.h中

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\10App.2011.exe
// -1 -2 -3 -4 -5
// -5 -1 -2 -3 -4
// -1
// ab^^c^^
// 2 1
// Process finished with exit code 0

int main()
{
    int data[5] = {-1, -2, -3, -4, -5};
    SLList list = NULL;
    buildSLListByTail(data, 5, &list);
    printSLList(list);
    minToFront(list);
    printSLList(list);
    destroySLList(&list);

    printf("%d\n", findMaxValue(data, 5));

    int leafNode = 0, branchNode = 0;
    LBTree tree = NULL;
    buildLBTree(&tree);
    countNode(tree, &leafNode, &branchNode);
    printf("%d %d", leafNode, branchNode);
    destroyLBTree(&tree);
    return 0;
}
