#include "SLList.h"

bool minToFront(SLList list);

bool findMaxValue(int data[], int length);

int main()
{
    return 0;
}

bool minToFront(SLList list)
{
    if (list == NULL || list->next == NULL)
    {
        return false;
    }
    SLList priorMin = list, currentMin = list->next, priorFind = list, currentFind = list->next;
    while (currentFind != NULL)
    {
        if (currentFind->data < currentMin->data)
        {
            priorMin = priorFind;
            currentMin = currentFind;
        }
        priorFind = priorFind->next;
        currentFind = currentFind->next;
    }
    priorMin->next = currentMin->next;
    currentMin->next = list->next;
    list->next = currentMin;
    return true;
}

bool findMaxValue(int data[], int length)
{
    if (length < 0)
    {
        return false;
    }
    return true;
}
