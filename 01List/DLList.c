#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define type int

typedef struct Node
{
    type data;
    struct Node *prior, *next;
} Node, *DLList;

bool initiateDLList(DLList* list);
bool buildDLListByHead(type data[], int length, DLList* list);
bool buildDLListByTail(type data[], int length, DLList* list);
DLList selectDLList(DLList list, type data);
bool insertDLList(DLList list, int location, type data);
bool deleteDLList(DLList list, int location);
bool printDLList(DLList list);
int getLengthDLList(DLList list);
void destroyDLList(DLList* list);

int main()
{
    DLList list = NULL;
    type data[5] = {1, 2, 3, 4, 5};
    buildDLListByHead(data, 5, &list);
    printDLList(list);
    destroyDLList(&list);
    buildDLListByTail(data, 5, &list);
    printDLList(list);
    int target = 3;
    DLList position = selectDLList(list, target);
    if (position != NULL)
    {
        printf("%d is found\n", target);
    }
    else
    {
        printf("%d is not found\n", target);
    }
    insertDLList(list, 2, 99);
    printDLList(list);
    deleteDLList(list, 4);
    printDLList(list);
    printf("Length: %d\n", getLengthDLList(list));
    destroyDLList(&list);
    return 0;
}

bool initiateDLList(DLList* list)
{
    if (*list != NULL)
    {
        return false;
    }
    *list = (DLList)malloc(sizeof(Node));
    if (*list == NULL)
    {
        return false;
    }
    (*list)->prior = NULL;
    (*list)->next = NULL;
    return true;
}

bool buildDLListByHead(type data[], int length, DLList* list)
{
    if (*list != NULL)
    {
        return false;
    }
    initiateDLList(list);
    for (int i = 0; i < length; i++)
    {
        DLList node = malloc(sizeof(Node));
        if (node != NULL)
        {
            node->data = data[i];
            node->next = (*list)->next;
            node->prior = *list;
            if ((*list)->next != NULL)
            {
                (*list)->next->prior = node;
            }
            (*list)->next = node;
        }
        else
        {
            i--;
        }
    }
    return true;
}

bool buildDLListByTail(type data[], int length, DLList* list)
{
    if (*list != NULL)
    {
        return false;
    }
    initiateDLList(list);
    DLList tail = *list;
    for (int i = 0; i < length; i++)
    {
        DLList node = malloc(sizeof(Node));
        if (node != NULL)
        {
            node->data = data[i];
            node->next = NULL;
            node->prior = tail;
            tail->next = node;
            tail = node;
        }
        else
        {
            i--;
        }
    }
    return true;
}

DLList selectDLList(DLList list, type data)
{
    if (list != NULL)
    {
        DLList temp = list->next;
        while (temp != NULL)
        {
            if (temp->data == data)
            {
                return temp;
            }
            temp = temp->next;
        }
    }
    return NULL;
}

bool insertDLList(DLList list, int location, type data)
{
    if (list == NULL || location < 0)
    {
        return false;
    }
    DLList temp = list;
    while (location > 0 && temp->next != NULL)
    {
        temp = temp->next;
        location--;
    }
    DLList node = malloc(sizeof(Node));
    if (node != NULL)
    {
        node->data = data;
        node->prior = temp;
        node->next = temp->next;
        if (temp->next != NULL)
        {
            temp->next->prior = node;
        }
        temp->next = node;
    }
    return true;
}

bool deleteDLList(DLList list, int location)
{
    if (list == NULL || list->next == NULL || location < 0)
    {
        return false;
    }
    DLList temp = list->next;
    while (location > 0 && temp->next != NULL)
    {
        temp = temp->next;
        location--;
    }
    if (temp == NULL)
    {
        return false;
    }
    if (temp->prior != NULL)
    {
        temp->prior->next = temp->next;
    }
    if (temp->next != NULL)
    {
        temp->next->prior = temp->prior;
    }
    free(temp);
    return true;
}

bool printDLList(DLList list)
{
    if (list == NULL)
    {
        return false;
    }
    list = list->next;
    while (list != NULL)
    {
        printf("%d ", list->data);
        list = list->next;
    }
    printf("\n");
    return true;
}

int getLengthDLList(DLList list)
{
    if (list == NULL || list->next == NULL)
    {
        return 0;
    }
    DLList temp = list->next;
    int length = 0;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}

void destroyDLList(DLList* list)
{
    DLList temp = *list;
    while (temp != NULL)
    {
        *list = (*list)->next;
        free(temp);
        temp = *list;
    }
    *list = NULL;
}
