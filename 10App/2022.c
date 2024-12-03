#include <LBTree.h>
#include <SLList.h>
#include <stdio.h>

// 求带头结点单链表a和b的交集c
bool getIntersection(SLList a, SLList b, SLList c)
{
    if (a == NULL || b == NULL || c == NULL)
    {
        return false;
    }
    for (SLList i = a->next; i != NULL; i = i->next)
    {
        for (SLList j = b->next; j != NULL; j = j->next)
        {
            if (j->data == i->data)
            {
                SLList k = malloc(sizeof(ListNode));
                if (k != NULL)
                {
                    k->data = j->data;
                    k->next = c->next;
                    c->next = k;
                }
                break;
            }
        }
    }
    return true;
}

// 奇数在前偶数在后
void oddToFront(int* data, int length)
{
    for (int i = 0; i < length; i++)
    {
        int flag = 0;
        for (int j = 0; j < length - i - 1; j++)
        {
            if (data[j] % 2 == 0 && data[j + 1] % 2 == 1)
            {
                flag = data[j];
                data[j] = data[j + 1];
                data[j + 1] = flag;
                flag = flag != 0 ? flag : 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}

void levelOrder(LBTree tree)
{
    if (tree != NULL)
    {
        LBTree queue[100];
        int front = -1, rear = -1;
        // 入队
        queue[++rear] = tree;
        while (front != rear)
        {
            // 出队
            LBTree node = queue[++front];
            printf("%c", node->data);
            if (node->left != NULL)
            {
                queue[++rear] = node->left;
            }
            if (node->right != NULL)
            {
                queue[++rear] = node->right;
            }
        }
    }
}

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\10App.2022.exe
// 1 2 3 4 5
// 5 6 7 8 9
// 5
// 1 3 5 7 2 4 6 8
// ab^^c^^
// abc
// Process finished with exit code 0

int main()
{
    SLList a = NULL, b = NULL, c = NULL;
    int dataA[5] = {1, 2, 3, 4, 5};
    int dataB[5] = {5, 6, 7, 8, 9};
    buildSLListByTail(dataA, 5, &a);
    buildSLListByTail(dataB, 5, &b);
    initiateSLList(&c);
    getIntersection(a, b, c);
    printSLList(a);
    printSLList(b);
    printSLList(c);
    destroySLList(&a);
    destroySLList(&b);
    destroySLList(&c);

    int data[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    oddToFront(data, 8);
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");

    LBTree tree = NULL;
    buildLBTree(&tree);
    levelOrder(tree);
    destroyLBTree(&tree);
    return 0;
}
