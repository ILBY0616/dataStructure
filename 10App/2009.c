#include <LBTree.h>
#include <LQueue.h>
#include <SStack.h>
#include <stdio.h>

// 设计顺序栈和链队判断回文
bool isPalindrome(SStack stack, LQueue queue, int* data, int length)
{
    for (int i = 0; i < length; i++)
    {
        // 入栈
        pushSStack(stack, data[i]);
        // 入队
        inLQueue(queue, data[i]);
    }
    for (int j = 0; j < length; j++)
    {
        int stackData, queueData;
        // 出栈
        popSStack(stack, &stackData);
        // 出队
        outLQueue(queue, &queueData);
        if (stackData != queueData)
        {
            return false;
        }
    }
    return true;
}

// 设计链式二叉树的创建、先序遍历、中序遍历、后续遍历程序
void preOrderByRecursion(LBTree tree)
{
    if (tree != NULL)
    {
        printf("%c", tree->data);
        preOrderByRecursion(tree->left);
        preOrderByRecursion(tree->right);
    }
}

void inOrderByRecursion(LBTree tree)
{
    if (tree != NULL)
    {
        inOrderByRecursion(tree->left);
        printf("%c", tree->data);
        inOrderByRecursion(tree->right);
    }
}

void postOrderByRecursion(LBTree tree)
{
    if (tree != NULL)
    {
        postOrderByRecursion(tree->left);
        postOrderByRecursion(tree->right);
        printf("%c", tree->data);
    }
}

// 编写邻接矩阵存储图的创建、广度优先遍历程序
// 见08Graph.AMGraph.h中

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\10App.2009.exe
// YES
// ab^^c^^
// abc
// bac
// bca
//
// Process finished with exit code 0


int main()
{
    int data[6] = {1, 2, 3, 3, 2, 1};
    SStack stack = NULL;
    LQueue queue = NULL;
    initiateSStack(&stack);
    initiateLQueue(&queue);
    if (isPalindrome(stack, queue, data, 6))
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    destroySStack(&stack);
    destroyLQueue(&queue);

    LBTree tree = NULL;
    buildLBTree(&tree);
    preOrderByRecursion(tree);
    printf("\n");
    inOrderByRecursion(tree);
    printf("\n");
    postOrderByRecursion(tree);
    printf("\n");
    destroyLBTree(&tree);
    return 0;
}
