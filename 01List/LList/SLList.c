#include "SLList.h"

bool initiateSLList(SLList* list)
{
    if (*list != NULL)
    {
        return false;
    }
    *list = (SLList)malloc(sizeof(Node));
    if (*list == NULL)
    {
        return false;
    }
    (*list)->next = NULL;
    return true;
}

bool buildSLListByHead(type data[], int length, SLList* list)
{
    if (*list != NULL)
    {
        return false;
    }
    initiateSLList(list);
    for (int i = 0; i < length; i++)
    {
        SLList node = malloc(sizeof(Node));
        if (node != NULL)
        {
            node->data = data[i];
            node->next = (*list)->next;
            (*list)->next = node;
        }
        else
        {
            i--;
        }
    }
    return true;
}

bool buildSLListByTail(type data[], int length, SLList* list)
{
    if (*list != NULL)
    {
        return false;
    }
    initiateSLList(list);
    SLList tail = *list;
    for (int i = 0; i < length; i++)
    {
        SLList node = malloc(sizeof(Node));
        if (node != NULL)
        {
            node->data = data[i];
            node->next = NULL;
            tail->next = node;
            tail = tail->next;
        }
        else
        {
            i--;
        }
    }
    return true;
}

SLList selectSLList(SLList list, type data)
{
    if (list != NULL)
    {
        SLList temp = list->next;
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

bool insertSLList(SLList list, int location, type data)
{
    // 检查
    if (list == NULL || location < 0 || location > getLengthSLList(list))
    {
        return false;
    }
    // 查找
    SLList temp = list;
    while (location > 0)
    {
        temp = temp->next;
        location--;
    }
    // 插入
    SLList node = malloc(sizeof(Node));
    if (node != NULL)
    {
        node->data = data;
        node->next = temp->next;
        temp->next = node;
    }
    return true;
}

bool deleteSLList(SLList list, int location)
{
    // 检查
    if (list == NULL || list->next == NULL || location < 0 || location > getLengthSLList(list) - 1)
    {
        return false;
    }
    // 查找
    SLList temp = list;
    while (location > 0)
    {
        temp = temp->next;
        location--;
    }
    // 删除
    SLList node = temp->next;
    temp->next = node->next;
    free(node);
    return true;
}

bool printSLList(SLList list)
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

int getLengthSLList(SLList list)
{
    if (list == NULL || list->next == NULL)
    {
        return 0;
    }
    SLList slow = list->next;
    SLList fast = list->next;
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

void destroySLList(SLList* list)
{
    SLList temp = *list;
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
//     SLList list = NULL;
//     type data[5] = {1, 2, 3, 4, 5};
//     buildSLListByHead(data, 5, &list);
//     printSLList(list);
//     destroySLList(&list);
//     buildSLListByTail(data, 5, &list);
//     printSLList(list);
//     int target = 3;
//     SLList position = selectSLList(list, target);
//     printf("%d is %d\n", position->data, target);
//     insertSLList(list, 2, 99);
//     printSLList(list);
//     deleteSLList(list, 4);
//     printSLList(list);
//     printf("%d\n", getLengthSLList(list));
//     destroySLList(&list);
//     return 0;
// }
