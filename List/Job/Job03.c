#include <stdio.h>
#include <stdlib.h>

#define newSize 10
#define type int

// 统一重点：ToDo
// 统一提示：提示需要中文
// 统一注释：注释在代码上方
// 统一状态：-1失败，0成功，1其他

// 动态顺序表
typedef struct
{
    type* data;
    int size, length;
} DSList;

// 初始化线性表
void initiateList(DSList* l)
{
    l->data = (type*)malloc(newSize * sizeof(type));
    l->size = newSize;
    l->length = 0;
}

// 删除所有与data相等的数，要求时间复杂度O(n)，空间复杂度O(1)
void jop03(DSList* l, type data)
{
    int sum = 0;
    for (int i = 0; i < l->length; i++)
    {
        if (l->data[i] != data)
        {
            // 统计不等值
            l->data[sum] = l->data[i];
            sum++;
        }
    }
    // 删除相等值
    l->length = sum;
}

int main()
{
    system("chcp 65001");
    DSList l;
    initiateList(&l);
    printf("当前数组元素：");
    for (int i = 0; i < l.size; i++)
    {
        // 填充一些重复的值
        l.data[i] = i % 3;
        printf("%d ", l.data[i]);
        l.length++;
    }
    printf("\n");

    // 删除所有值为1的元素
    jop03(&l, 1);

    printf("删除后的数组元素：");
    for (int i = 0; i < l.length; i++)
    {
        printf("%d ", l.data[i]);
    }
    printf("\n");

    free(l.data);
    return 0;
}
