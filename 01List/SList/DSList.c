#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define newSize 10
#define type int

typedef struct List
{
    type* data;
    int size, length;
} List, *DSList;

bool initiateDSList(DSList* list);
int selectDSList(DSList list, type data);
bool insertDSList(DSList list, int location, type data);
bool deleteDSList(DSList list, int location);
bool printDSList(DSList list);
bool destroyDSList(DSList* list);

int main()
{
    DSList list;
    if (!initiateDSList(&list))
    {
        printf("Failed to initiate list.\n");
        return 1;
    }
    printf("Inserting elements 1 to 10...\n");
    for (int i = 0; i < 10; i++)
    {
        if (!insertDSList(list, i, i + 1))
        {
            printf("Failed to insert %d at position %d.\n", i + 1, i);
        }
    }
    printf("Current List: ");
    printDSList(list);
    int target = 5;
    int position = selectDSList(list, target);
    printf("%d is at position %d\n", target, position);
    if (deleteDSList(list, 3))
    {
        printf("Deleted element at position 3.\n");
    }
    else
    {
        printf("Failed to delete element at position 3.\n");
    }
    printf("List after deletion: ");
    printDSList(list);
    if (insertDSList(list, 2, 99))
    {
        printf("Inserted 99 at position 2.\n");
    }
    else
    {
        printf("Failed to insert 99 at position 2.\n");
    }
    printf("Final List: ");
    printDSList(list);
    if (deleteDSList(list, 0))
    {
        printf("Deleted first element.\n");
    }
    printf("List after deleting first element: ");
    printDSList(list);
    if (deleteDSList(list, list->length - 1))
    {
        printf("Deleted last element.\n");
    }
    printf("List after deleting last element: ");
    printDSList(list);
    while (list->length > 0)
    {
        deleteDSList(list, 0);
    }
    printf("List after deleting all elements: ");
    printDSList(list);
    destroyDSList(&list);
    printf("List destroyed.\n");
    return 0;
}

bool initiateDSList(DSList* list)
{
    *list = (DSList)malloc(sizeof(List));
    if (*list == NULL)
    {
        return false;
    }
    (*list)->data = (type*)malloc(newSize * sizeof(type));
    if ((*list)->data == NULL)
    {
        return false;
    }
    (*list)->size = newSize;
    (*list)->length = 0;
    return true;
}

int selectDSList(DSList list, type data)
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

bool insertDSList(DSList list, int location, type data)
{
    if (list == NULL || location < 0 || location > list->length)
    {
        return false;
    }
    if (list->length == list->size)
    {
        list->size += newSize;
        list->data = (type*)realloc(list->data, list->size * sizeof(type));
        if (list->data == NULL)
        {
            return false;
        }
    }
    for (int i = list->length; i > location; i--)
    {
        list->data[i] = list->data[i - 1];
    }
    list->data[location] = data;
    list->length++;
    return true;
}

bool deleteDSList(DSList list, int location)
{
    if (list == NULL || list->length == 0 || location < 0 || location > list->length - 1)
    {
        return false;
    }
    for (int i = location; i < list->length - 1; i++)
    {
        list->data[i] = list->data[i + 1];
    }
    list->length--;
    return true;
}

bool printDSList(DSList list)
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

bool destroyDSList(DSList* list)
{
    if (*list == NULL)
    {
        return false;
    }
    free((*list)->data);
    free(*list);
    *list = NULL;
    return true;
}
