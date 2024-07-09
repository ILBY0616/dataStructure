#include <stdio.h>
#include <stdlib.h>

#define type int

typedef struct Node
{
    type data;
    struct Node *prior, *next;
} Node;

Node* initiateList()
{
    Node* n = (Node*)malloc(sizeof(Node));
    if (n != NULL)
    {
        n->prior = NULL;
        n->next = NULL;
    }
    return n;
}

void buildList(Node* n)
{
    Node* p = n;
    type data;
    while (scanf("%d", &data) != EOF)
    {
        Node* buildNode = (Node*)malloc(sizeof(Node));
        if (buildNode != NULL)
        {
            buildNode->data = data;
            buildNode->prior = p;
            buildNode->next = NULL;
            p->next = buildNode;
            p = buildNode;
        }
    }
}

int insert(Node* n, int location, type data)
{
    int result = -1;
    Node* p = n;
    while (p->next != NULL && location > 1)
    {
        p = p->next;
        location--;
    }
    Node* insertNode = (Node*)malloc(sizeof(Node));
    if (insertNode != NULL)
    {
        insertNode->data = data;
        insertNode->next = p->next;
        if (p->next != NULL)
        {
            p->next->prior = insertNode;
        }
        p->next = insertNode;
        insertNode->prior = p;
        result = 0;
    }
    return result;
}

int deleteNode(Node* n, int location)
{
    int result = -1;
    Node* p = n;
    while (p->next != NULL && location > 1)
    {
        p = p->next;
        location--;
    }
    Node* deleteNode = p->next;
    if (deleteNode != NULL)
    {
        p->next = deleteNode->next;
        if (deleteNode->next != NULL)
        {
            deleteNode->next->prior = p;
        }
        free(deleteNode);
        result = 0;
    }
    return result;
}

void printList(Node* n)
{
    Node* p = n->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void destroyList(Node* n) {
    Node* p = n;
    while (p != NULL) {
        Node* temp = p;
        p = p->next;
        free(temp);
    }
}
int main()
{
    system("chcp 65001");

    Node* list = initiateList();
    if (list == NULL)
    {
        printf("初始化链表失败\n");
        return -1;
    }

    printf("请输入链表元素，输入EOF结束：\n");
    buildList(list);

    printf("当前链表：\n");
    printList(list);

    insert(list, 2, 100);
    printf("在位置2插入元素100后：\n");
    printList(list);

    deleteNode(list, 3);
    printf("删除位置3的元素后：\n");
    printList(list);

    destroyList(list);
    return 0;
}
