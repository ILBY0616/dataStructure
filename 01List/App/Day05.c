#include "SSList.h"

bool deleteX(List l,type a,type b)
{
    if (l == NULL || l->length == 0 || a > b)
    {
        return false;
    }
    int i = 0, j = 0;
    while (i < l->length)
    {
        if (a <= l->data[i] && l->data[i] <= b)
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
    return true;
}

void deleteX02(List l,type a,type b)
{
    int i = 0, j = 0;
    while (i < l->length)
    {
        if (a > l->data[i] || l->data[i] > b)
        {
            l->data[j++] = l->data[i];
        }
    }
    l->length = j;
}
