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

// 逆转父顺序表中前后子顺序表，a、b两个子顺序表长度
void reverseArray(List l, int a, int b)
{
    reverseData(l, 0, a - 1);
    reverseData(l, a, a + b - 1);
    reverseData(l, 0, a + b - 1);
}
