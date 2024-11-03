#ifndef SSTRING_H
#define SSTRING_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct String
{
    char data[100];
    int size, length;
} String, *SString;

// 创建顺序串
bool createSString(char* data, SString* string);
// 获取新下标
int* getNext(SString pattern);
// 匹配顺序串
int matchSString(SString mainString, SString patternString);
// 打印顺序串
void printSString(SString string);
// 销毁顺序串
void destroySString(SString* string);

inline bool createSString(char* data, SString* string)
{
    if (*string != NULL)
    {
        return false;
    }
    *string = malloc(sizeof(String));
    if (*string != NULL)
    {
        int i = 0;
        while (i < strlen(data) && i < 100)
        {
            (*string)->data[i] = data[i];
            i++;
        }
        (*string)->data[i] = '\0';
        (*string)->size = 100;
        (*string)->length = strlen(data);
    }
    return true;
}

inline int* getNext(SString pattern)
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

inline int matchSString(SString mainString, SString patternString)
{
    if (mainString == NULL || patternString == NULL || mainString->length < patternString->length)
    {
        return -1;
    }
    int i = 0, j = 0, location;
    int* next = getNext(patternString);
    while (i < mainString->length && j < patternString->length)
    {
        if (j == -1 || mainString->data[i] == patternString->data[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }
    if (j == patternString->length)
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

inline void printSString(SString string)
{
    for (int i = 0; i < string->length; i++)
    {
        printf("%c", string->data[i]);
    }
    printf("\n");
}

inline void destroySString(SString* string)
{
    free(*string);
    *string = NULL;
}

#endif
