#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define  size 10
#define type char

typedef struct Node
{
    type data;
    struct Node* next;
} Node;

typedef Node* LString;

LString initiateString(char* data)
{
    LString head = NULL;
    LString tail = NULL;
    for (int i = 0; i < strlen(data); i++)
    {
        LString node = malloc(sizeof(Node));
        if (node != NULL)
        {
            node->data = data[i];
            node->next = NULL;
        }
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
    return head;
}

int matchPattern(LString main, LString pattern)
{
    if (main == NULL || pattern == NULL)
    {
        return -1;
    }
    int location = 0;
    LString i = main;
    while (i != NULL)
    {
        LString j = i;
        LString k = pattern;
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

void destroy(LString s)
{
    LString temp = s;
    while (temp != NULL)
    {
        s = temp->next;
        free(temp);
        temp = s;
    }
}

int main()
{
    char* a = "goodgoogle";
    char* b = "google";
    LString main = initiateString(a);
    LString pattern = initiateString(b);
    LString temp = NULL;
    temp = main;
    while (temp != NULL)
    {
        printf("%c", temp->data);
        temp = temp->next;
        if (temp == NULL)
        {
            printf("\n");
        }
    }
    temp = pattern;
    while (temp != NULL)
    {
        printf("%c", temp->data);
        temp = temp->next;
        if (temp == NULL)
        {
            printf("\n");
        }
    }
    printf("%d", matchPattern(main, pattern));
    destroy(main);
    destroy(pattern);
    return 0;
}
