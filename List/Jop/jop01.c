#include <stdio.h>
#include <stdlib.h>

#define newSize 10
#define type int

// 动态顺序表
typedef struct
{
    type* data;
    int size, length;
} DSList;

// 初始化线性表（通过指针）
void initiateList(DSList* l)
{
    l->data = (type*)malloc(newSize * sizeof(type));
    l->size = newSize;
    l->length = 0;
}

// 查找最小元素 删除最小元素 返回最小元素 填补最小元素
int jop01(DSList* l, type* data)
{
    // 检查
    if (l->length == 0 || l->size == 0)
    {
        return -1;
    }

    // 查找最小元素并记录位置
    type value = l->data[0];
    int location = 0; // 从0开始
    for (int i = 1; i < l->length; i++)
    {
        if (value > l->data[i])
        {
            value = l->data[i];
            location = i;
        }
    }
    // 更新传出参数data的值
    *data = value;

    // 删除最小元素并填补
    l->data[location] = l->data[l->length - 1];
    l->length--; // 更新长度

    return 0;
}

int main()
{
    system("chcp 65001");

    DSList l;
    type data = -1;
    initiateList(&l); // 传入指针

    // ToDo 初始化后只有size没有length
    // 填充动态数组
    printf("当前数组元素：");
    for (int i = 0; i < l.size; i++)
    {
        l.data[i] = i + 1; // 填充1到newSize的值
        printf("%d ", l.data[i]);
        l.length++;
    }

    // 传入指针
    int result = jop01(&l, &data);
    if (result == -1)
    {
        printf("\n程序失败，报错数字：%d\n", result);
    }
    else
    {
        printf("\n程序成功，最小值为：%d\n", data);
        printf("当前数组元素：");
        for (int j = 0; j < l.length; j++)
        {
            printf("%d ", l.data[j]);
        }
        printf("\n");
    }

    // 释放内存
    free(l.data);
    return 0;
}
