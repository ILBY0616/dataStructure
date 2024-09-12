#include <string.h>
#include <stdio.h>

// sizeof()计算字节 包括\0
// strlen()计算长度 排除\0

int main()
{
    char a = 'a';
    char b[2] = {'a', 'b'};
    char c[4] = {'a', 'b', 'c', '\0'};
    char d[5] = {'a', 'b', 'c', 'd','e'};
    char e[6] = {'e'};
    char* f = "abcdef";

    int size = sizeof(a);
    int length = strlen(&a);
    printf("%c %d %d \n", a, size, length);

    size = sizeof(b);
    length = strlen(b);
    printf("%s %d %d \n", b, size, length);

    size = sizeof(c);
    length = strlen(c);
    printf("%s %d %d \n", c, size, length);

    size = sizeof(d);
    length = strlen(d);
    printf("%s %d %d \n", d, size, length);

    size = sizeof(e);
    length = strlen(e);
    printf("%s %d %d \n", e, size, length);

    size = sizeof(f);
    length = strlen(f);
    printf("%s %d %d \n", f, size, length);

    return 0;
}
