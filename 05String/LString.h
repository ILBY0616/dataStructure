#ifndef LSTRING_H
#define LSTRING_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct StringNode
{
    char data;
    struct StringNode* next;
} StringNode, *LString;

// 创建链串
bool createLString(char* data, LString* string);
// 匹配链串
int matchLString(LString mainString, LString patternString);
// 打印链串
void printLString(LString string);
// 销毁链串
void destroyLString(LString* string);

inline bool createLString(char* data, LString* string)
{
    if (*string != NULL)
    {
        return false;
    }
    LString head = NULL;
    LString tail = NULL;
    for (int i = 0; i < strlen(data); i++)
    {
        LString node = malloc(sizeof(StringNode));
        if (node != NULL)
        {
            node->data = data[i];
            node->next = NULL;
            if (head == NULL || tail == NULL)
            {
                head = node;
                tail = node;
            }
            else
            {
                tail->next = node;
                tail = node;
            }
        }
        else
        {
            i--;
        }
    }
    *string = head;
    return true;
}

inline int matchLString(LString mainString, LString patternString)
{
    if (mainString == NULL || patternString == NULL)
    {
        return -1;
    }
    int location = 0;
    LString i = mainString;
    while (i != NULL)
    {
        LString j = i;
        LString k = patternString;
        while (j != NULL && k != NULL && j->data == k->data)
        {
            j = j->next;
            k = k->next;
        }
        if (k == NULL)
        {
            return location;
        }
        location++;
        i = i->next;
    }
    return -1;
}

inline void printLString(LString string)
{
    while (string != NULL)
    {
        printf("%c", string->data);
        string = string->next;
    }
    printf("\n");
}

inline void destroyLString(LString* string)
{
    while (*string != NULL)
    {
        LString node = *string;
        *string = (*string)->next;
        free(node);
    }
}

#endif