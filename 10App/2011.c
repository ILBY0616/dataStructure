#include <LBTree.h>
#include <SLList.h>

// 移到带头结点单链表中最小结点到最前面
void minToHead(SLList list)
{
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
}

// 查找数组最大值
int findMaxValue(int* data, int length)
{
    if (length > 0)
    {
        int a = data[length - 1];
        int b = findMaxValue(data, length - 1);
        return a > b ? a : b;
    }
    return data[0];
}

// 统计链式二叉树中叶子结点数目和非叶结点数目
void getNodeSum(LBTree tree, int* leafSum, int* branchSum)
{
    if (tree != NULL)
    {
        if (tree->left != NULL || tree->right != NULL)
        {
            (*branchSum)++;
        }
        else
        {
            (*leafSum)++;
        }
        getNodeSum(tree->left, leafSum, branchSum);
        getNodeSum(tree->right, leafSum, branchSum);
    }
}

// 编写邻接表存储图的定义、创建程序
// 见08Graph.ATGraph.h中

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
    minToHead(list);
    printSLList(list);
    destroySLList(&list);

    printf("%d\n", findMaxValue(data, 5));

    int leafSum = 0, branchSum = 0;
    LBTree tree = NULL;
    buildLBTree(&tree);
    getNodeSum(tree, &leafSum, &branchSum);
    printf("%d %d", leafSum, branchSum);
    destroyLBTree(&tree);
    return 0;
}
