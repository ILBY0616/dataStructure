#include <stdio.h>
#include <stdbool.h>

#define type int
#define size 100

typedef struct Node
{
    type value;
    bool sign;
} Node;

typedef struct Tree
{
    Node data[size];
    int length;
} Tree, *SBTree;

void initiateSBTree(SBTree tree);
void preOrder(SBTree tree);
void inOrder(SBTree tree);
void postOrder(SBTree tree);
void levelOrder(SBTree tree);
int getHeight(SBTree tree);
void destroySBTree(SBTree tree);


// 测试代码
int main()
{
    Tree tree;
    SBTree sbTree = &tree;

    // 初始化树
    initiateSBTree(sbTree);

    // 遍历树
    preOrder(sbTree);
    inOrder(sbTree);
    postOrder(sbTree);
    levelOrder(sbTree);

    // 获取树的高度
    printf("树的高度: %d\n", getHeight(sbTree));

    // 销毁树
    destroySBTree(sbTree);

    return 0;
}


void initiateSBTree(SBTree tree)
{
    tree->length = 0; // 初始化长度为0
    for (int i = 0; i < size; i++)
    {
        tree->data[i].sign = false; // 所有节点默认不存在
    }

    printf("请输入节点的值（输入-1表示节点不存在，最多%d个节点）：\n", size);
    for (int i = 0; i < size; i++)
    {
        int value;
        scanf("%d", &value);

        if (value == -1)
            break; // 输入-1表示不再输入节点

        tree->data[i].value = value;
        tree->data[i].sign = true; // 标记节点存在
        tree->length++; // 增加节点数
    }
}

// 先序遍历
void preOrder(SBTree tree)
{
    printf("先序遍历：\n");
    for (int i = 0; i < tree->length; i++)
    {
        if (tree->data[i].sign)
        {
            printf("%d ", tree->data[i].value);
        }
    }
    printf("\n");
}

// 中序遍历
void inOrder(SBTree tree)
{
    printf("中序遍历：\n");
    for (int i = 0; i < tree->length; i++)
    {
        if (tree->data[i].sign)
        {
            printf("%d ", tree->data[i].value);
        }
    }
    printf("\n");
}

// 后序遍历
void postOrder(SBTree tree)
{
    printf("后序遍历：\n");
    for (int i = 0; i < tree->length; i++)
    {
        if (tree->data[i].sign)
        {
            printf("%d ", tree->data[i].value);
        }
    }
    printf("\n");
}

// 层序遍历
void levelOrder(SBTree tree)
{
    printf("层序遍历：\n");
    for (int i = 0; i < tree->length; i++)
    {
        if (tree->data[i].sign)
        {
            printf("%d ", tree->data[i].value);
        }
    }
    printf("\n");
}

// 获取树的高度
int getHeight(SBTree tree)
{
    int height = 0;
    int i = tree->length - 1;

    while (i >= 0 && !tree->data[i].sign)
    {
        i--; // 从最后一个节点开始，找到最后存在的节点
    }

    // 使用完全二叉树的公式来计算高度：高度 = log2(节点数) + 1
    while (i >= (1 << height) - 1)
    {
        height++;
    }
    return height;
}

// 销毁树
void destroySBTree(SBTree tree)
{
    tree->length = 0;
    for (int i = 0; i < size; i++)
    {
        tree->data[i].sign = false;
    }
    printf("树已销毁。\n");
}
