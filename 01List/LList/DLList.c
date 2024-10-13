#include "DLList.h"

// 建立链表
bool initiateList(List* list)
{
    *list = (List)malloc(sizeof(Node));
    if (*list == NULL)
    {
        return false;
    }
    (*list)->data = 0;
    (*list)->prior = NULL;
    (*list)->next = NULL;
    return true;
}

// 插入数据
bool insertData(List list, int location, type data)
{
    // 检查
    if (list == NULL || location < 0 || location > list->data)
    {
        return false;
    }
    // 查找
    List temp = list;
    while (location > 0)
    {
        temp = temp->next;
        location--;
    }
    // 插入
    List node = malloc(sizeof(Node));
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
        list->data++;
    }
    return true;
}

// 删除数据
bool deleteData(List list, int location)
{
    // 检查
    if (list == NULL || list->next == NULL || location < 0 || location > list->data - 1)
    {
        return false;
    }
    // 查找
    List temp = list;
    while (location > 0)
    {
        temp = temp->next;
        location--;
    }
    // 删除
    List node = temp->next;
    temp->next = node->next;
    if (node->next != NULL)
    {
        node->next->prior = temp;
    }
    free(node);
    list->data--;
    return true;
}

// 查找数据
List selectData(List list, type data)
{
    if (list != NULL)
    {
        List temp = list->next;
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

// 销毁链表
void destroyList(List* list)
{
    List temp = *list;
    while (temp != NULL)
    {
        *list = (*list)->next;
        free(temp);
        temp = *list;
    }
}
