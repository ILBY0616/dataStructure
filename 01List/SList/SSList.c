#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define type int
#define size 100

typedef struct List
{
    type data[size];
    int length;
} List, *SSList;

bool initiateSSList(SSList* list);
int selectSSList(SSList list, type data);
bool insertSSList(SSList list, int location, type data);
bool deleteSSList(SSList list, int location);
bool printSSList(SSList list);
bool destroySSList(SSList* list);

int main()
{
    SSList list;
    if (!initiateSSList(&list))
    {
        printf("Failed to initiate list.\n");
        return 1;
    }
    for (int i = 0; i < 10; i++)
    {
        if (!insertSSList(list, i, i + 1))
        {
            printf("Failed to insert %d at position %d.\n", i + 1, i);
        }
    }
    printf("Current List: ");
    printSSList(list);
    int target = 5;
    int position = selectSSList(list, target);
    printf("%d is at position %d\n", target, position);
    if (deleteSSList(list, 3))
    {
        printf("Deleted element at position 3.\n");
    }
    else
    {
        printf("Failed to delete element at position 3.\n");
    }
    printf("List after deletion: ");
    printSSList(list);
    if (insertSSList(list, 2, 99))
    {
        printf("Inserted 99 at position 2.\n");
    }
    else
    {
        printf("Failed to insert 99 at position 2.\n");
    }
    printf("Final List: ");
    printSSList(list);
    destroySSList(&list);
    printf("List destroyed.\n");
    return 0;
}

bool initiateSSList(SSList* list)
{
    *list = (SSList)malloc(sizeof(List));
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

bool destroySSList(SSList* list)
{
    if (*list == NULL)
    {
        return false;
    }
    free(*list);
    *list = NULL;
    return true;
}
