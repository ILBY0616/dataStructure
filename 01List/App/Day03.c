#include "SSList.h"

// 逆转顺序表
void reverseList01(List l)
{
    for (int i = 0; i < l->length / 2; i++)
    {
        type temp = l->data[i];
        l->data[i] = l->data[l->length - i - 1];
        l->data[l->length - i - 1] = temp;
    }
}

// 逆转顺序表
void reverseList02(type data[], int low, int high)
{
    if (low < high)
    {
        type temp = data[low];
        data[low] = data[high];
        data[high] = temp;
        reverseList02(data, low + 1, high - 1);
    }
}
