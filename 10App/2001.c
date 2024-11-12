#include <stdio.h>

void change1(int a)
{
    int b = 2;
    a = b;
}

void change2(int* a)
{
    int b = 2;
    *a = b;
}

int main()
{
    int a = 1;
    printf("%d %d\n", a, &a);
    change1(a);
    printf("%d %d\n", a, &a);

    printf("%d %d\n", a, &a);
    change2(&a);
    printf("%d %d\n", a, &a);

    return 0;
}
