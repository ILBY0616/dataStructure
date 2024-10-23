#include "LBTree.h"

void swapLBtree(LBTree t)
{
    if (t != NULL)
    {
        swapLBtree(t->left);
        swapLBtree(t->right);
        LBTree temp = t->left;
        t->left = t->right;
        t->right = temp;
    }
}
