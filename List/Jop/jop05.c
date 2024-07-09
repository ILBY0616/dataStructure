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

// 去重
// 去重
// void jop05(DSList* l)
// {
//     for (int i = 0; i < l->length; i++)
//     {
//         int step = 0;
//         for (int j = i + 1; j < l->length; j++)
//         {
//             if (l->data[j] == l->data[i])
//             {
//                 step++;
//             }
//             else
//             {
//                 l->data[j - step] = l->data[j];
//             }
//         }
//         l->length -= step;
//     }
// }
// 去重
int jop05(DSList* l)
{
    if (l->length <= 1)
    {
        return -1; // 数组长度小于等于1，无需去重
    }

    int i, j;
    for (i = 0, j = 1; j <= l->length; j++)
    {
        if (j < l->length && l->data[i] != l->data[j])
        {
            l->data[++i] = l->data[j]; // 将不重复的元素移到前面
        }
    }
    l->length = i + 1; // 更新数组长度为去重后的长度
    return 0;
}


int main()
{
    system("chcp 65001");
    DSList l;
    initiateList(&l);
    printf("当前数组元素：");
    type temp[newSize] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
    for (int i = 0; i < l.size; i++)
    {
        // 填充一些重复的值
        l.data[i] = temp[i];
        printf("%d ", l.data[i]);
        l.length++;
    }
    printf("\n");

    // 去重
    jop05(&l);

    printf("去重后的数组元素：");
    for (int i = 0; i < l.length; i++)
    {
        printf("%d ", l.data[i]);
    }
    printf("\n");

    free(l.data);
    return 0;
}
