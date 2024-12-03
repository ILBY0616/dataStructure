#include <LBTree.h>
#include <LQueue.h>
#include <SStack.h>
#include <stdio.h>

// 用顺序栈和链队判断回文
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

// 递归统计链二叉树结点数
void getTotal(LBTree tree, int* total)
{
    if (tree != NULL)
    {
        (*total)++;
        getTotal(tree->left, total);
        getTotal(tree->right, total);
    }
}

// 用邻接矩阵定义、创建、深度优先遍历图
// 见AMGraph.h中

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\10App.2013.exe
// YES
// ab^^c^^
// 3
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

    int total = 0;
    LBTree tree = NULL;
    buildLBTree(&tree);
    getTotal(tree, &total);
    printf("%d\n", total);
    destroyLBTree(&tree);
    return 0;
}
