#include <LBTree.h>
#include <LQueue.h>
#include <SStack.h>
#include <stdio.h>

// 用顺序栈和链队判断回文
bool isPalindrome(SStack stack, LQueue queue, int data[], int length)
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

// 递归先序遍历二叉树
void preOrderByRecursion(LBTree tree)
{
    if (tree != NULL)
    {
        printf("%c", tree->data);
        preOrderByRecursion(tree->left);
        preOrderByRecursion(tree->right);
    }
}

// 递归中序遍历二叉树
void inOrderByRecursion(LBTree tree)
{
    if (tree != NULL)
    {
        inOrderByRecursion(tree->left);
        printf("%c", tree->data);
        inOrderByRecursion(tree->right);
    }
}

// 递归后序遍历二叉树
void postOrderByRecursion(LBTree tree)
{
    if (tree != NULL)
    {
        postOrderByRecursion(tree->left);
        postOrderByRecursion(tree->right);
        printf("%c", tree->data);
    }
}

// 创建大小无序长度为20000的顺序表，运用堆排序的思想打印出前20大的数
// 见SelectHeap.h中

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\10App.2016.exe
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
