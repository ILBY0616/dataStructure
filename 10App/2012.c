#include <SLList.h>
#include <stdio.h>

// 统计带头结点单链表中值为key的结点数
int getKeySum(SLList list, int key)
{
    int sum = 0;
    SLList node = list->next;
    while (node != NULL)
    {
        if (node->data == key)
        {
            sum++;
        }
        node = node->next;
    }
    return sum;
}

// 统计链式二叉树结点数
// 见10App.2008.c中

// 移到所有奇数元素到所有偶数元素前面
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

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\10App.2012.exe
// 1
// 1 3 5 7 2 4 6 8
// Process finished with exit code 0

int main()
{
    int key = 7;
    int length = 8;
    SLList list = NULL;
    int data[8] = {1, 3, 5, 7, 2, 4, 6, 8};
    buildSLListByTail(data, length, &list);
    printf("%d\n", getKeySum(list, key));
    destroySLList(&list);

    oddToFront(data, length);
    for (int i = 0; i < length; i++)
    {
        printf("%d ", data[i]);
    }
    return 0;
}
