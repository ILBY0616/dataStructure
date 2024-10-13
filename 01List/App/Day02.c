#include "SSList.h"

bool mergeList(List a, List b, List c)
{
    if (a->length + b->length > c->length)
    {
        return false;
    }
    int i = 0, j = 0, k = 0;
    while (i < a->length || j < b->length)
    {
        if (a->data[i] <= b->data[j])
        {
            c->data[k++] = a->data[i++];
        }
        else
        {
            c->data[k++] = b->data[j++];
        }
    }
    while (i < a->length)
    {
        c->data[k++] = a->data[i++];
    }
    while (j < b->length)
    {
        c->data[k++] = b->data[j++];
    }
    c->length = a->length + b->length;
    return true;
}
