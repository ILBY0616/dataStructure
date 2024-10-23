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

// int main()
// {
//     DLList list = NULL;
//     type data[5] = {1, 2, 3, 4, 5};
//     buildDLListByHead(data, 5, &list);
//     printDLList(list);
//     destroyDLList(&list);
//     buildDLListByTail(data, 5, &list);
//     printDLList(list);
//     int target = 3;
//     DLList position = selectDLList(list, target);
//     printf("%d is %d\n", position->data, target);
//     insertDLList(list, 2, 99);
//     printDLList(list);
//     deleteDLList(list, 4);
//     printDLList(list);
//     printf("%d\n", getLengthDLList(list));
//     destroyDLList(&list);
//     return 0;
// }