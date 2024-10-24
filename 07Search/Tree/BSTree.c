#include <stdio.h>
#include <stdlib.h>

// BinarySortTree

typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef Node* PNode;

PNode toList(int data[], int length);
int judgeList(PNode list);

int main()
{
    return 0;
}

PNode toList(int data[], int length)
{
    PNode head = NULL;
    PNode tail = NULL;
    for (int i = 0; i < length; i++)
    {
        PNode temp = malloc(sizeof(Node));
        if (temp != NULL)
        {
            temp->data = data[i];
            temp->right = NULL;
            if (head == NULL || tail == NULL)
            {
                head = temp;
                tail = temp;
            }
            else
            {
                tail->right = temp;
                tail = temp;
            }
        }
        else
        {
            free(head);
            free(tail);
            free(temp);
            head = NULL;
            tail = NULL;
            temp = NULL;
            break;
        }
    }
    return head;
}
