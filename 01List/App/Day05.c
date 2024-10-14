#include "SSList.h"

// 删除顺序表指定范围元素
void deleteAToB01(List l,type a,type b)
{
    int i = 0, j = 0;
    while (j < l->length)
    {
        if (a <= l->data[j] && l->data[j] <= b)
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

// 删除顺序表指定范围元素
void deleteAToB02(List l,type a,type b)
{
    int i = 0, j = 0;
    while (j < l->length)
    {
        if (b < l->data[j] || l->data[j] < a)
        {
            l->data[i++] = l->data[j];
        }
        j++;
    }
    l->length = i;
}
