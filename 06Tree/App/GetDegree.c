#include "LBTree.h"

int getDegree2Node(LBTree t)
{
    if (t == NULL)
    {
        return 0;
    }
    else if (t->left != NULL && t->right != NULL)
    {
        return getDegree2Node(t->left) + getDegree2Node(t->right) + 1;
    }
    else
    {
        return getDegree2Node(t->left) + getDegree2Node(t->right);
    }
}

int getDegree1Node(LBTree t)
{
    if (t == NULL)
    {
        return 0;
    }
    else if (t->left != NULL && t->right != NULL)
    {
        return getDegree2Node(t->left) + getDegree2Node(t->right);
    }
    else
    {
        return getDegree2Node(t->left) + getDegree2Node(t->right) + 1;
    }
}

int getDegree0Node(LBTree t)
{
    if (t == NULL)
    {
        return 0;
    }
    if (t->left == NULL && t->right == NULL)
    {
        return 1;
    }
    return getDegree2Node(t->left) + getDegree2Node(t->right);
}
