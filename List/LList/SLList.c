#include <stdio.h>
#include <stdlib.h>

#define type int

typedef struct Node {
    type data;
    struct Node* next;
} Node;

Node* initiateList() {
    Node* n = (Node*)malloc(sizeof(Node));
    if (n == NULL) {
        return NULL;
    }
    n->next = NULL;
    return n;
}

int getLength(Node* n) {
    int length = 0;
    Node* p = n->next;
    while (p != NULL) {
        p = p->next;
        length++;
    }
    return length;
}

int getLocation(Node* n, type data) {
    int location = 1;
    Node* p = n->next;
    while (p != NULL && p->data != data) {
        p = p->next;
        location++;
    }
    if (p == NULL) {
        location = -1;
    }
    return location;
}

int getSatus(Node* n) {
    return n->next != NULL ? 0 : -1;
}

int insertElemByFront(Node* n, int location, type data) {
    int result = -1;
    Node* p = n;
    while (p != NULL && location - 1 > 0) {
        p = p->next;
        location--;
    }
    if (p != NULL) {
        Node* insertNode = (Node*)malloc(sizeof(Node));
        if (insertNode != NULL) {
            insertNode->data = data;
            insertNode->next = p->next;
            p->next = insertNode;
            result = 0;
        }
    }
    return result;
}

int insertElemByBack(Node* n, type data) {
    int result = -1;
    Node* insertNode = (Node*)malloc(sizeof(Node));
    if (insertNode != NULL) {
        insertNode->data = data;
        insertNode->next = n->next;
        n->next = insertNode;
        result = 0;
    }
    return result;
}

int deleteElemByFront(Node* n, int location, type* data) {
    int result = -1;
    Node* p = n;
    while (p != NULL && location - 1 > 0) {
        p = p->next;
        location--;
    }
    if (p != NULL && p->next != NULL) {
        Node* deleteNode = p->next;
        p->next = deleteNode->next;
        *data = deleteNode->data;
        free(deleteNode);
        result = 0;
    }
    return result;
}

int deleteElemByBack(Node* n, type* data) {
    int result = -1;
    if (n->next != NULL) {
        Node* deleteNode = n->next;
        *data = deleteNode->data;
        n->next = deleteNode->next;
        free(deleteNode);
        result = 0;
    }
    return result;
}

int updateElemByFront(Node* n, int location, type data) {
    int result = -1;
    Node* p = n;
    while (p != NULL && location > 0) {
        p = p->next;
        location--;
    }
    if (p != NULL) {
        p->data = data;
        result = 0;
    }
    return result;
}

int updateElemByBack(Node* n, type data) {
    int result = -1;
    if (n != NULL) {
        n->data = data;
        result = 0;
    }
    return result;
}

Node* selectElemByLocation(Node* n, int location) {
    Node* p = n;
    while (p != NULL && location > 0) {
        p = p->next;
        location--;
    }
    return p;
}

Node* selectElemByData(Node* n, type data) {
    Node* p = n;
    while (p != NULL && p->data != data) {
        p = p->next;
    }
    return p;
}

void buildListByFront(Node *n)
{
    Node* p = n;
    type data;
    while (scanf("%d",&data)!=EOF)
    {
        Node* buildNode=(Node*)malloc(sizeof(Node));
        if (buildNode != NULL) {
            buildNode->data=data;
            buildNode->next=p->next;
            p->next=buildNode;
        }
    }
}

void buildListByBack(Node *n)
{
    Node* p = n;
    type data;
    while (scanf("%d",&data)!=EOF)
    {
        Node* buildNode=(Node*)malloc(sizeof(Node));
        if (buildNode != NULL) {
            buildNode->data=data;
            buildNode->next=NULL;
            p->next=buildNode;
            p=buildNode;
        }
    }
}

void destroyList(Node* n) {
    Node* p = n;
    while (p != NULL) {
        Node* temp = p;
        p = p->next;
        free(temp);
    }
}

int main() {
    system("chcp 65001");

    Node* list = initiateList();
    if (list == NULL) {
        printf("初始化链表失败\n");
        return -1;
    }

    // 测试插入元素（前插法）
    insertElemByFront(list, 1, 10);
    insertElemByFront(list, 1, 20);
    insertElemByFront(list, 1, 30);

    printf("链表长度 (应为3): %d\n", getLength(list));

    // 测试插入元素（后插法）
    insertElemByBack(list, 40);
    insertElemByBack(list, 50);
    printf("链表长度 (应为5): %d\n", getLength(list));

    // 测试查找元素位置
    int location = getLocation(list, 20);
    printf("元素20的位置 (应为2): %d\n", location);

    location = getLocation(list, 50);
    printf("元素50的位置 (应为5): %d\n", location);

    location = getLocation(list, 100);
    printf("元素100的位置 (应为-1): %d\n", location);

    // 测试更新元素
    updateElemByFront(list, 2, 25);
    printf("更新后元素25的位置 (应为2): %d\n", getLocation(list, 25));

    // 测试删除元素（前删法）
    type data;
    deleteElemByFront(list, 2, &data);
    printf("删除位置2的元素 (应为25): %d\n", data);
    printf("链表长度 (应为4): %d\n", getLength(list));

    // 测试删除元素（后删法）
    deleteElemByBack(list, &data);
    printf("删除尾部元素 (应为50): %d\n", data);
    printf("链表长度 (应为3): %d\n", getLength(list));

    // 销毁链表
    destroyList(list);
    return 0;
}
