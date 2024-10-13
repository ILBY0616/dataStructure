#include "SSList.h"

void deleteX01(List l,type x)
{
    int i = 0, j = 0;
    while (i < l->length)
    {
        if (l->data[i] == x)
        {
            j++;
        }
        else
        {
            l->data[i - j] = l->data[i];
        }
        i++;
    }
    l->length = l->length - j;
}

void deleteX02(List l,type x)
{
    int i = 0, j = 0;
    while (i < l->length)
    {
        if (l->data[i] != x)
        {
            l->data[j++] = l->data[i];
        }
    }
    l->length = j;
}
