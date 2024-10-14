#include "SSList.h"

// 逆转顺序表中元素，f起始序号，r结束序号
void reverseData(List l, int f, int r)
{
    for (int i = f; i < (f + r) / 2; i++)
    {
        type temp = l->data[i];
        l->data[i] = l->data[f + r - i];
        l->data[f + r - i] = temp;
    }
}

// 逆转父顺序表中p前后子顺序表
void reverseArray(List l, int p)
{
    reverseData(l, 0, p - 1);
    reverseData(l, p, l->length - 1);
    reverseData(l, 0, l->length - 1);
}
