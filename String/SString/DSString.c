#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DSString
{
    char* data;
    int length;
} DSString;

int buildString(DSString* s, char* data)
{
    int result;
    int length = strlen(data);
    int size = length + 2;
    s->data = (char*)malloc(size * sizeof(char));
    s->length = 0;
    if (s->data != NULL)
    {
        // 复制串
        s->data[0] = '￥';
        for (int i = 1; i <= length; i++)
        {
            s->data[i] = data[i - 1];
        }
        s->data[length + 1] = '\0';
        // 求串长
        s->length = length;
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
    DSString s;
    int result = buildString(&s, string);
    printf("%s %d %d", s.data, s.length, result);
}
