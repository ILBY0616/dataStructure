#include <stdio.h>
#include <stdlib.h>

#define newSize 10
#define type int

// 统一重点：ToDo
// 统一提示：中文
// 统一注释：代码上方
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

// 反转线性表
void jop02(DSList* l)
{
    // ToDo int(3/2)=1，float(3/2)=0.5
    for (int i = 0; i < l->length / 2; i++)
    {
        // 交换数据
        type temp = l->data[i];
        l->data[i] = l->data[l->length - 1 - i];
        l->data[l->length - 1 - i] = temp;
    }
}

int main()
{
    system("chcp 65001");
    DSList l;
    initiateList(&l);

    // 填充动态数组
    printf("当前数组元素：");
    for (int i = 0; i < l.size; i++)
    {
        l.data[i] = i + 1; // 填充1到newSize的值
        printf("%d ", l.data[i]);
        l.length++;
    }
    printf("\n");

    // 反转数组
    jop02(&l);

    // 打印反转后的数组
    printf("当前数组元素：");
    for (int i = 0; i < l.length; i++)
    {
        printf("%d ", l.data[i]);
    }
    printf("\n");

    // 释放动态数组
    free(l.data);

    return 0;
}
