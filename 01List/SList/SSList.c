#include "SSList.h"

bool initiateSSList(SSList* list)
{
    *list = (SSList)malloc(sizeof(Node));
    if (*list == NULL)
    {
        return false;
    }
    (*list)->length = 0;
    return true;
}

int selectSSList(SSList list, type data)
{
    if (list != NULL)
    {
        for (int i = 0; i < list->length; i++)
        {
            if (list->data[i] == data)
            {
                return i;
            }
        }
    }
    return -1;
}

bool insertSSList(SSList list, int location, type data)
{
    // 检查
    if (list == NULL || list->length == size || location < 0 || location > list->length)
    {
        return false;
    }
    // 后移
    for (int i = list->length; i > location; i--)
    {
        list->data[i] = list->data[i - 1];
    }
    // 插入
    list->data[location] = data;
    list->length++;
    return true;
}

bool deleteSSList(SSList list, int location)
{
    // 检查
    if (list == NULL || list->length == 0 || location < 0 || location > list->length - 1)
    {
        return false;
    }
    // 前移
    for (int i = location; i < list->length - 1; i++)
    {
        list->data[i] = list->data[i + 1];
    }
    // 删除
    list->length--;
    return true;
}

bool printSSList(SSList list)
{
    if (list == NULL)
    {
        return false;
    }
    for (int i = 0; i < list->length; i++)
    {
        printf("%d ", list->data[i]);
    }
    printf("\n");
    return true;
}

void destroySSList(SSList* list)
{
    if (*list != NULL)
    {
        free(*list);
        *list = NULL;
    }
}

// int main()
// {
//     SSList list;
//     initiateSSList(&list);
//     for (int i = 0; i < 10; i++)
//     {
//         insertSSList(list, i, i + 1);
//     }
//     printSSList(list);
//     int target = 5;
//     int position = selectSSList(list, target);
//     printf("%d in %d\n", target, position);
//     deleteSSList(list, 3);
//     insertSSList(list, 2, 99);
//     printSSList(list);
//     destroySSList(&list);
//     return 0;
// }
