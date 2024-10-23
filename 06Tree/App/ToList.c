#include "LBTree.h"

void toList(LBTree t, LBTree* head, LBTree* tail)
{
    if (t != NULL)
    {
        if (*head == NULL || *tail == NULL)
        {
            *head = t;
            *tail = t;
        }
        else
        {
            (*tail)->right = t;
            *tail = t;
        }
        toList(t->left, head, tail);
        toList(t->right, head, tail);
    }
}
