#include "DSList.h"

// 合并两个有序顺序表成为新有序顺序表
bool mergeDSList(DSList a, DSList b, DSList c)
{
    if (a->length + b->length > c->size)
    {
        return false;
    }
    int i = 0, j = 0, k = 0;
    while (i < a->length && j < b->length)
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

int main()
{
    DSList a, b, c;
    initiateDSList(&a);
    initiateDSList(&b);
    initiateDSList(&c);
    insertDSList(a, 0, 1);
    insertDSList(a, 1, 3);
    insertDSList(a, 2, 5);
    insertDSList(b, 0, 2);
    insertDSList(b, 1, 4);
    insertDSList(b, 2, 6);
    printDSList(a);
    printDSList(b);
    if (mergeDSList(a, b, c))
    {
        printDSList(c);
    }
    destroyDSList(&a);
    destroyDSList(&b);
    destroyDSList(&c);
    return 0;
}
