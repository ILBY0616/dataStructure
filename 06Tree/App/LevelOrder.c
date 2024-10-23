#include "LBTree.h"

// 从上到下，从左到右
void levelOrder01(LBTree tree)
{
    if (tree != NULL)
    {
        LBTree queue[size];
        int front = 0, rear = 0;
        // 入根队
        queue[rear++] = tree;
        // 出子队
        while (front != rear)
        {
            LBTree node = queue[front++];
            if (node != NULL)
            {
                printf("%c", node->data);
                queue[rear++] = node->left;
                queue[rear++] = node->right;
            }
        }
    }
}

// 从上到下，从右到左
void levelOrder02(LBTree tree)
{
    if (tree != NULL)
    {
        LBTree queue[size];
        int front = 0, rear = 0;
        // 入根队
        queue[rear++] = tree;
        // 出子队
        while (front != rear)
        {
            LBTree node = queue[front++];
            if (node != NULL)
            {
                printf("%c", node->data);
                queue[rear++] = node->right;
                queue[rear++] = node->left;
            }
        }
    }
}

// 从下到上，从右到左
void levelOrder03(LBTree tree)
{
    if (tree != NULL)
    {
        LBTree queue[size];
        int front = 0, rear = 0;
        // 入根队
        queue[rear++] = tree;
        // 出子队
        while (front != rear)
        {
            LBTree node = queue[front++];
            if (node != NULL)
            {
                printf("%c", node->data);
                queue[rear++] = node->right;
                queue[rear++] = node->left;
            }
        }
    }
}
