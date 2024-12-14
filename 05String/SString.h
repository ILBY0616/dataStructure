#ifndef SSTRING_H
#define SSTRING_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// 顺序串
typedef struct SString
{
    char* data;
    int size, length;
}* SString;

// 建造顺序串
bool buildSString(char* data, SString* string);
// 获取新下标
void getNext(SString string, int next[]);
// 匹配顺序串
int matchSString(SString mainString, SString subString);
// 打印顺序串
void printSString(SString string);
// 销毁顺序串
void destroySString(SString* string);

inline bool buildSString(char* data, SString* string)
{
    if (data == NULL || *string != NULL)
    {
        return false;
    }
    *string = malloc(sizeof(struct SString));
    if (*string == NULL)
    {
        return false;
    }
    (*string)->size = 2 * strlen(data);
    (*string)->data = malloc((*string)->size * sizeof(char));
    (*string)->length = strlen(data);
    if ((*string)->data == NULL)
    {
        return false;
    }
    int i = 0;
    while (i < (*string)->length)
    {
        (*string)->data[i] = data[i];
        i++;
    }
    (*string)->data[i] = '\0';
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
            i++;
            j++;
            next[i] = string->data[i] == string->data[j] ? next[j] : j;
        }
        else
        {
            j = next[j];
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
    getNext(subString, next);
    while (i < mainString->length && j < subString->length)
    {
        if (j == -1 || mainString->data[i] == subString->data[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }
    return j == subString->length ? i - j : -1;
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
    if (*string != NULL)
    {
        free(*string);
        *string = NULL;
    }
}

#endif
