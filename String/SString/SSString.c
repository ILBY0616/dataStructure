#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxSize 10

typedef struct SSString
{
    char data[maxSize];
    int length;
} SSString;

int buildString(SSString* s, char* data)
{
    int result;
    s->length = strlen(data);
    if (s->length + 2 <= maxSize)
    {
        s->data[0] = '￥';
        for (int i = 1; i <= s->length; i++)
        {
            s->data[i] = data[i - 1];
        }
        s->data[s->length + 1] = '\0';
        result = 0;
    }
    else
    {
        result = -1;
    }
    return result;
}

int main()
{
    system("chcp 65001");
    char* string = "abc";
    SSString s;
    int result = buildString(&s, string);
    printf("%s %d %d", s.data, s.length, result);
}
