#include "DLList.h"

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
    // 检查
    if (list == NULL || location < 0 || location > list->data)
    {
        return false;
    }
    // 查找
    DLList temp = list;
    while (location > 0)
    {
        temp = temp->next;
        location--;
    }
    // 插入
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
    // 检查
    if (list == NULL || list->next == NULL || location < 0 || location > list->data - 1)
    {
        return false;
    }
    // 查找
    DLList temp = list;
    while (location > 0)
    {
        temp = temp->next;
        location--;
    }
    // 删除
    DLList node = temp->next;
    temp->next = node->next;
    if (node->next != NULL)
    {
        node->next->prior = temp;
    }
    free(node);
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
    DLList slow = list->next;
    DLList fast = list->next;
    int length = 1;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        length++;
    }
    if (fast != NULL)
    {
        length = length * 2 - 1;
    }
    else
    {
        length = length * 2;
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
