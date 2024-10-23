#include "SBTree.h"

// 查找顺序二叉树两个结点的公共祖先
int findAncestry(SBTree t, int i, int j)
{
    if (t.length < 3 || i < 0 || j < 0 || i >= t.length || j >= t.length)
    {
        return -1;
    }
    while (t.data[i].sign && t.data[j].sign && i != j)
    {
        if (i > j)
        {
            i /= 2;
        }
        else
        {
            j /= 2;
        }
    }
    return i;
}
