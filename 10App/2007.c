#include <stdbool.h>
#include <LBTree.h>

// 用栈和队列判断回文
bool isPalindrome()
{
    char stack[100];
    char queue[100];
    int top = -1, front = -1, rear = -1;
    char data;
    while (scanf("%c", &data) == 1 && data != '@')
    {
        // 入栈入队
        stack[++top] = data;
        queue[++rear] = data;
    }
    while (top != -1 && front != rear)
    {
        // 出栈出队逐一比较
        if (stack[top--] != queue[++front])
        {
            return false;
        }
    }
    return true;
}

// 在二叉排序树中找到值为X的结点
LBTree findKeyNode(LBTree tree, int key)
{
    while (tree != NULL && tree->data != key)
    {
        if (tree->data < key)
        {
            tree = tree->right;
        }
        else
        {
            tree = tree->left;
        }
    }
    return tree;
}

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\10App.2007.exe
// abcba@
// YES
// ij^^k^^
// k in tree
//
// Process finished with exit code 0

int main()
{
    if (isPalindrome())
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    getchar();

    char key = 'k';
    LBTree tree = NULL, pointer = NULL;
    buildLBTree(&tree);
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
