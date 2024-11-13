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

// 递归查找链二叉排序树值为key的结点
LBTree findKeyNode(LBTree tree, char key)
{
    if (tree != NULL)
    {
        if (tree->data == key)
        {
            return tree;
        }
        LBTree pointer;
        if (tree->data < key)
        {
            pointer = findKeyNode(tree->right, key);
        }
        else
        {
            pointer = findKeyNode(tree->left, key);
        }
        return pointer;
    }
    return NULL;
}

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\10App.2014.exe
// YES
// ij^^k^^
// k in tree
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

    char key = 'k';
    LBTree tree = NULL, pointer = NULL;
    createLBTree(&tree);
    pointer = findKeyNode(tree, key);
    if (pointer != NULL)
    {
        printf("%c in tree\n", pointer->data);
    }
    else
    {
        printf("k not in tree\n");
    }
    destroyLBTree(&tree);
    return 0;
}
