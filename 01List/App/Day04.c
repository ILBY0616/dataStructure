#include "SSList.h"

// 删除顺序表中所有值为x的元素
void deleteX01(List l,type x)
{
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
}

// 删除顺序表中所有值为x的元素
void deleteX02(List l,type x)
{
    int i = 0, j = 0;
    while (j < l->length)
    {
        if (l->data[j] != x)
        {
            l->data[i++] = l->data[j];
        }
    }
    l->length = i;
}
