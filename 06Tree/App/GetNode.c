#include "LBTree.h"

int getNode(LBTree t)
{
    if (t == NULL)
    {
        return 0;
    }
    return getNode(t->left) + getNode(t->right) + 1;
}
