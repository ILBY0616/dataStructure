#include <LBTree.h>
#include <SStack.h>
#include <stdio.h>

// 十进制正整数化为八进制正整数
void baseConversion(SStack stack, int data)
{
    while (data > 0)
    {
        pushSStack(stack, data % 8);
        data /= 8;
    }
    while (stack->top != -1)
    {
        popSStack(stack, &data);
        printf("%d", data);
    }
    printf("\n");
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

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\10App.2015.exe
// 12
// ab^^c^^
// abc
// bac
// bca
//
// Process finished with exit code 0

int main()
{
    SStack stack;
    initiateSStack(&stack);
    baseConversion(stack, 10);
    destroySStack(&stack);

    LBTree tree = NULL;
    createLBTree(&tree);
    preOrderByRecursion(tree);
    printf("\n");
    inOrderByRecursion(tree);
    printf("\n");
    postOrderByRecursion(tree);
    printf("\n");
    destroyLBTree(&tree);
    return 0;
}
