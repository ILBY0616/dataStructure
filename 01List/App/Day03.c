#include "SSList.h"

// 逆转顺序表
bool reverseArray01(SSList l)
{
    if (l == NULL)
    {
        return false;
    }
    for (int i = 0; i < l->length / 2; i++)
    {
        type temp = l->data[i];
        l->data[i] = l->data[l->length - i - 1];
        l->data[l->length - i - 1] = temp;
    }
    return true;
}

// 逆转顺序表
bool reverseArray02(SSList l, int low, int high)
{
    if (l == NULL)
    {
        return false;
    }
    if (low < high)
    {
        type temp = l->data[low];
        l->data[low] = l->data[high];
        l->data[high] = temp;
        reverseArray02(l, low + 1, high - 1);
    }
    return true;
}

int main()
{
    SSList l;
    initiateSSList(&l);
    insertSSList(l, 0, 1);
    insertSSList(l, 1, 2);
    insertSSList(l, 2, 3);
    insertSSList(l, 3, 4);
    insertSSList(l, 4, 5);
    reverseArray01(l);
    printSSList(l);
    reverseArray02(l, 0, l->length - 1);
    printSSList(l);
    destroySSList(&l);
    return 0;
}
