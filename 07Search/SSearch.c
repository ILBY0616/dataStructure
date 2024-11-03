#include <stdio.h>

// 顺序查找
int sequenceSearch(int data[], int key, int length);

int main()
{
    int data[10] = {0, 8, 2, 6, 4, 5, 3, 7, 1, 9};
    printf("%d", sequenceSearch(data, 5, 10));
    return 0;
}

int sequenceSearch(int data[], int key, int length)
{
    data[0] = key;
    int i = length - 1;
    while (data[i] != key)
    {
        i--;
    }
    return i;
}
