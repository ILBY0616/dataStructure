#include <stdio.h>
#include <string.h>

// sizeof()计算字节 包括\0
// strlen()计算长度 排除\0

int main()
{
    char a = 'a';
    char b[] = {'a', 'b'};
    char c[4] = {'a', 'b', 'c', '\0'};
    char d[5] = {'a', 'b', 'c', 'd'};
    char e[6] = {'e'};
    char* f = "abcdef";

    int size = sizeof(a);
    int length = 1;
    printf("%c %d %d \n", a, size, length);

    size = sizeof(b);
    length = strlen(b);
    printf("%s %d %d \n", b, length, size);

    size = sizeof(c);
    length = strlen(c);
    printf("%s %d %d \n", c, length, size);

    size = sizeof(d);
    length = strlen(d);
    printf("%s %d %d \n", d, length, size);

    size = sizeof(e);
    length = strlen(e);
    printf("%s %d %d \n", e, length, size);

    size = sizeof(f);
    length = strlen(f);
    printf("%s %d %d \n", f, length, size);

    return 0;
}
