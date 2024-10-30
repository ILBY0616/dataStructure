#include <stdio.h>
#define size 100
#define type int

int searchData(type data[size], type key, int length)
{
    data[0] = key;
    int i = length;
    while (data[i] != key)
    {
        i--;
    }
    return i;
}

int main()
{
    // type data[10] = {0, 7, 6, 5, 4, 3, 2, 1};
    // printf("%d", searchData(data, -1, 7));
    // return 0;
}
