#include <stdio.h>

void modifyData(char a, char* b, char* c)
{
    a = 'A';
    *b = 'B';
    c = b;
    printf("%c %c %c\n", a, *b, *c);
}

int main()
{
    char a = 'a', b = 'b', c = 'c';
    modifyData(a, &b, &c);
    printf("%c %c %c\n", a, b, c);
}
