#include "LBTree.h"

bool isPalindrome(char data[])
{
    char stack[100];
    char queue[100];
    int top = -1, front = 0, rear = 0, length = strlen(data);
    for (int i = 0; i < length; i++)
    {
        stack[++top] = data[i];
        queue[rear++] = data[i];
    }
    for (int j = 0; j < length; j++)
    {
        if (stack[top--] != queue[front++])
        {
            return false;
        }
    }
    return true;
}

LBTree findNode(LBTree tree, type data)
{
    while (tree != NULL && tree->data != data)
    {
        if (tree->data < data)
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


