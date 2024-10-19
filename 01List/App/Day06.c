#include "SSList.h"

// 去除有序顺序表重复元素
bool removeSame(SSList l)
{
    if (l == NULL)
    {
        return false;
    }
    int i = 0, j = 0;
    while (j < l->length)
    {
        if (l->data[i] != l->data[j])
        {
            l->data[++i] = l->data[j];
        }
        j++;
    }
    l->length = i + 1;
    return true;
}

int main()
{
    SSList l = NULL;
    initiateSSList(&l);
    insertSSList(l, l->length, 1);
    insertSSList(l, l->length, 1);
    insertSSList(l, l->length, 2);
    insertSSList(l, l->length, 2);
    insertSSList(l, l->length, 3);
    insertSSList(l, l->length, 3);
    printSSList(l);
    removeSame(l);
    printSSList(l);
    destroySSList(&l);
    return 0;
}
