#ifndef SSTRING_H
#define SSTRING_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// 顺序串
typedef struct SString
{
    char data[100];
    int size, length;
}* SString;

// 创建顺序串
bool buildSString(char* data, SString* string);
// 获取新下标
void getNext(SString string, int next[]);
// 获取新下标
void getNextVal(SString string, int next[], int nextVal[]);
// 匹配顺序串
int matchSString(SString mainString, SString subString);
// 打印顺序串
void printSString(SString string);
// 销毁顺序串
void destroySString(SString* string);

inline bool buildSString(char* data, SString* string)
{
    if (*string != NULL)
    {
        return false;
    }
    *string = malloc(sizeof(struct SString));
    if (*string == NULL)
    {
        return false;
    }
    int i = 0;
    (*string)->size = 100;
    while (i < strlen(data) && i < (*string)->size)
    {
        (*string)->data[i] = data[i];
        i++;
    }
    (*string)->data[i] = '\0';
    (*string)->length = strlen(data);
    return true;
}

inline void getNext(SString string, int next[])
{
    next[0] = -1;
    int i = 0, j = -1;
    while (i < string->length - 1)
    {
        if (j == -1 || string->data[i] == string->data[j])
        {
            next[++i] = ++j;
        }
        else
        {
            j = next[j];
        }
    }
}

inline void getNextVal(SString string, int next[], int nextVal[])
{
    nextVal[0] = -1;
    for (int i = 1; i < string->length; i++)
    {
        if (string->data[i] == string->data[next[i]])
        {
            nextVal[i] = nextVal[next[i]];
        }
        else
        {
            nextVal[i] = next[i];
        }
    }
}

inline int matchSString(SString mainString, SString subString)
{
    if (mainString == NULL || subString == NULL || mainString->length < subString->length)
    {
        return -1;
    }
    int i = 0, j = 0;
    int next[subString->length];
    int nextVal[subString->length];
    getNext(subString, next);
    getNextVal(subString, next, nextVal);
    while (i < mainString->length && j < subString->length)
    {
        if (j == -1 || mainString->data[i] == subString->data[j])
        {
            i++;
            j++;
        }
        else
        {
            j = nextVal[j];
        }
    }
    return subString->length == j ? i - j : -1;
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
