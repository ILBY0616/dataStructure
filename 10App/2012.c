#include "LBTree.h"
#include "SLList.h"
#include <stdio.h>

// 统计带头结点单链表中值为data的结点数
int countListNode(SLList list, int data)
{
    int count = 0;
    SLList node = list->next;
    while (node != NULL)
    {
        if (node->data == data)
        {
            count++;
        }
        node = node->next;
    }
    return count;
}

// 递归统计树结点数
int total = 0;

void countTreeNode(LBTree tree)
{
    if (tree != NULL)
    {
        total++;
        countTreeNode(tree->left);
        countTreeNode(tree->right);
    }
}

// 奇数在前偶数在后
void oddToFront(int data[], int length)
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

int main()
{
    int data[8] = {1, 3, 5, 7, 2, 4, 6, 8};
    oddToFront(data, 8);
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", data[i]);
    }
    return 0;
}