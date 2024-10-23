#include "LBTree.h"

// 找到先序遍历第k个结点值
void getKthValue(LBTree t, int* k)
{
    if (t != NULL && *k >= 0)
    {
        (*k)--;
        if (*k == 0)
        {
            printf("%c", t->data);
            return;
        }
        getKthValue(t->left, k);
        getKthValue(t->right, k);
    }
}
