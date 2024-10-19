#include "SSList.h"

// 删除顺序表中所有值为x的元素
bool deleteX01(SSList l,type x)
{
    if (l == NULL)
    {
        return false;
    }
    int i = 0, j = 0;
    while (j < l->length)
    {
        if (l->data[j] == x)
        {
            i++;
        }
        else
        {
            l->data[j - i] = l->data[j];
        }
        j++;
    }
    l->length = l->length - i;
    return true;
}

// 删除顺序表中所有值为x的元素
bool deleteX02(SSList l,type x)
{
    if (l == NULL)
    {
        return false;
    }
    int i = 0, j = 0;
    while (j < l->length)
    {
        if (l->data[j] != x)
        {
            l->data[i++] = l->data[j];
        }
        j++;
    }
    l->length = i;
    return true;
}

int main()
{
    SSList l = NULL;
    initiateSSList(&l);
    for (int i = 0; i < 10; i++)
    {
        insertSSList(l, l->length, i % 5);
    }
    printSSList(l);
    deleteX01(l, 2);
    printSSList(l);
    for (int i = 0; i < 10; i++)
    {
        insertSSList(l, l->length, i % 5);
    }
    printSSList(l);
    deleteX02(l, 2);
    printSSList(l);
    destroySSList(&l);
    return 0;
}
