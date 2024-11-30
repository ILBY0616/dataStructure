#include <stdbool.h>
#include <LBTree.h>

// 用栈和队列判断输入序列是否是回文
bool isPalindrome()
{
    char stack[100];
    char queue[100];
    int top = -1, front = -1, rear = -1;
    char data;
    while (scanf("%c", &data) == 1 && data != '@')
    {
        // 输入字符入栈入队
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
LBTree findKeyNode(LBTree tree, char key)
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

// 用邻接矩阵存储n的顶点有向图，计算从某一顶点出发到其他所有顶点路径的和的最小值
// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\10App.2007.exe
// abcba@
// YES
// ji^^k^^
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
