#include "SSList.h"

// 去除有序顺序表重复元素
void removeSame(List l)
{
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
}
