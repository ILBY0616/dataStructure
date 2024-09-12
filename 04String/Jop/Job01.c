#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

int matchPattern(SSString main, SSString pattern)
{
    int i = 1, j = 1, location;
    while (i <= main.length && j <= pattern.length)
    {
        if (main.data[i] == pattern.data[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 2;
            j = 1;
        }
    }
    if (j - 1 == pattern.length)
    {
        location = i - j + 1;
    }
    else
    {
        location = -1;
    }
    return location;
}

int main()
{
    system("chcp 65001");
    char* a = "ababdabc";
    char* b = "abc";
    SSString main, pattern;

    buildString(&main, a);
    buildString(&pattern, b);

    printf("%s %d \n", main.data, main.length);
    printf("%s %d \n", pattern.data, pattern.length);
    printf("%d", matchPattern(main, pattern));
}
