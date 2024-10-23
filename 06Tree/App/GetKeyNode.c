#include "LBTree.h"

void getKeyNode(LBTree t, LBTree* p,type k)
{
    if (t != NULL)
    {
        if (t->data == k)
        {
            *p = t;
        }
        getKeyNode(t->left, p, k);
        getKeyNode(t->right, p, k);
    }
}
