#include <stdio.h>
#include <stdlib.h>

#define type char

typedef struct Node
{
    type data;
    struct Node *left, *right;
} Node;

Node* buildTreeByFront()
{
    Node* n;
    type data;
    scanf("%c", &data);
    if (data == '#')
    {
        n = NULL;
    }
    else
    {
        n = (Node*)malloc(sizeof(Node));
        if (n != NULL)
        {
            n->data = data;
            n->left = buildTreeByFront(n->left);
            n->right = buildTreeByFront(n->right);
        }
    }
    return n;
}

Node* buildTreeByMiddle()
{
    Node* n;
    type data;
    scanf("%c", &data);
    if (data == '#')
    {
        n = NULL;
    }
    else
    {
        n = (Node*)malloc(sizeof(Node));
        if (n != NULL)
        {
            n->left = buildTreeByMiddle(n->left);
            n->data = data;
            n->right = buildTreeByMiddle(n->right);
        }
    }
    return n;
}

Node* buildTreeByBack()
{
    Node* n;
    type data;
    scanf("%c", &data);
    if (data == '#')
    {
        n = NULL;
    }
    else
    {
        n = (Node*)malloc(sizeof(Node));
        if (n != NULL)
        {
            n->left = buildTreeByBack(n->left);
            n->right = buildTreeByBack(n->right);
            n->data = data;
        }
    }
    return n;
}

void destroyTree(Node* n)
{
    if(n)
    {
        if(n->left)
        {
            destroyTree(n->left);
        }
        if(n->right)
        {
            destroyTree(n->right);
        }
        free(n);
    }
}


int main()
{
    Node* front = buildTreeByFront();
    Node* middle = buildTreeByMiddle();
    Node* back = buildTreeByBack();
    destroyTree(front);
    destroyTree(middle);
    destroyTree(back);
    return 0;
}
