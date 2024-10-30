#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define size 100

typedef struct String
{
    char data[size];
    int length;
} String;

typedef String* SString;

SString initiateString(char* data)
{
    SString s = malloc(sizeof(String));
    if (s != NULL)
    {
        int i = 0;
        while (i < strlen(data))
        {
            s->data[i] = data[i];
            i++;
        }
        s->data[i] = '\0';
        s->length = strlen(data);
    }
    return s;
}

int* getNext(SString pattern)
{
    int* next = malloc(pattern->length * sizeof(int));
    if (next != NULL)
    {
        next[0] = -1;
        if (pattern->length > 1)
        {
            next[1] = 0;
        }
        int i = 2;
        int j = 0;
        while (i < pattern->length)
        {
            if (j == -1 || pattern->data[i - 1] == pattern->data[j])
            {
                i++;
                j++;
                next[i - 1] = j;
            }
            else
            {
                j = next[j];
            }
        }
    }
    return next;
}

int matchPattern(SString main, SString pattern)
{
    if (main == NULL || pattern == NULL || main->length < pattern->length)
    {
        return -1;
    }
    int i = 0, j = 0, location;
    int* next = getNext(pattern);
    while (i < main->length && j < pattern->length)
    {
        if (j == -1 || main->data[i] == pattern->data[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }
    if (j == pattern->length)
    {
        location = i - j;
    }
    else
    {
        location = -1;
    }
    free(next);
    return location;
}

void destroy(SString s)
{
    free(s);
}

int main()
{
    char* a = "goodgoogle";
    char* b = "google";
    SString main = initiateString(a);
    SString pattern = initiateString(b);
    printf("%s\n", main->data);
    printf("%s\n", pattern->data);
    printf("%d", matchPattern(main, pattern));
    destroy(main);
    destroy(pattern);
    return 0;
}
