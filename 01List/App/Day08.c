#include "SSList.h"

// 逆转顺序表中元素，f起始序号，r结束序号
void reverseData(SSList l, int f, int r)
{
    for (int i = f; i <= (f + r) / 2; i++)
    {
        type temp = l->data[i];
        l->data[i] = l->data[f + r - i];
        l->data[f + r - i] = temp;
    }
}

// 将前p个元素整体移到顺序表后面
void reverseArray(SSList l, int p)
{
    reverseData(l, 0, p - 1);
    reverseData(l, p, l->length - 1);
    reverseData(l, 0, l->length - 1);
}

int main()
{
    SSList l = NULL;
    initiateSSList(&l);
    for (int i = 0; i < 10; i++)
    {
        insertSSList(l, l->length, i);
    }
    printSSList(l);
    reverseArray(l, 5);
    printSSList(l);
    destroySSList(&l);
    return 0;
}
