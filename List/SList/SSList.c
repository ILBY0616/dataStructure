#include <stdio.h>
#include <stdlib.h>

#define maxSize 100
#define type int

// 统一重点：ToDo
// 统一提示：中文
// 统一注释：代码上方
// 统一状态：-1失败，0成功，1其他

// 静态顺序表
typedef struct
{
    type data[maxSize];
    int size, length;
} SSList;

// 初始化线性表
void initiateList(SSList* l)
{
    l->size = maxSize;
    l->length = 0;
}

// 获取线性表长度
int getLength(SSList* l)
{
    return l->length;
}

// 查找线性表位置
int getLocation(SSList* l, type data)
{
    for (int i = 0; i < l->length; i++)
    {
        if (l->data[i] == data)
        {
            return i + 1;
        }
    }
    return -1;
}

// 获取线性表状态
int getStatue(SSList* l)
{
    return l->length > 0 ? 1 : 0;
}

// ToDo
// 插入元素
int insertElem(SSList* l, int location, type data)
{
    // 检查
    if (location < 1 || location > l->length + 1 || l->length >= l->size)
    {
        return -1;
    }

    // 后移
    for (int i = l->length; i >= location; i--)
    {
        l->data[i] = l->data[i - 1];
    }

    // 插入
    l->data[location - 1] = data;
    l->length++;
    return 0;
}

// ToDo
// 删除元素
int deleteElem(SSList* l, int location)
{
    // 检查
    if (location < 1 || location > l->length)
    {
        return -1;
    }

    // 前移
    for (int i = location - 1; i < l->length - 1; i++)
    {
        l->data[i] = l->data[i + 1];
    }

    // 删除
    l->length--;
    return 0;
}

// 更新元素
int updateElem(SSList* l, int location, type data)
{
    // 检查
    if (location < 1 || location > l->length)
    {
        return -1;
    }

    // 更新
    l->data[location - 1] = data;
    return 0;
}

// 查找元素
type selectElem(SSList* l, int location)
{
    // 检查
    if (location < 1 || location > l->length)
    {
        return -1;
    }

    // 查找
    return l->data[location - 1];
}

// 销毁线性表
void destroyList(SSList* l)
{
    l->size = 0;
    l->length = 0;
}

// 菜单函数
void menu()
{
    SSList list;
    initiateList(&list);
    int choice, location, result;
    type data;

    // 显示菜单
    printf("1. 插入元素\n");
    printf("2. 删除元素\n");
    printf("3. 更新元素\n");
    printf("4. 查找元素\n");
    printf("5. 获取长度\n");
    printf("6. 获取位置\n");
    printf("7. 获取状态\n");
    printf("8. 退出系统\n");

    while (1)
    {
        printf("输入你的选择: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // 插入元素
            printf("输入插入位置和插入数据: ");
            scanf("%d %d", &location, &data);
            result = insertElem(&list, location, data);
            if (result == 0)
            {
                printf("元素插入成功。\n");
            }
            else
            {
                printf("元素插入失败。\n");
            }
            break;

        case 2:
            // 删除元素
            printf("输入删除位置: ");
            scanf("%d", &location);
            result = deleteElem(&list, location);
            if (result == 0)
            {
                printf("元素删除成功。\n");
            }
            else
            {
                printf("元素删除失败。\n");
            }
            break;

        case 3:
            // 更新元素
            printf("输入更新位置和更新数据: ");
            scanf("%d %d", &location, &data);
            result = updateElem(&list, location, data);
            if (result == 0)
            {
                printf("元素更新成功。\n");
            }
            else
            {
                printf("元素更新失败。\n");
            }
            break;

        case 4:
            // 查找元素
            printf("输入查找位置: ");
            scanf("%d", &location);
            data = selectElem(&list, location);
            if (data != -1)
            {
                printf("位置 %d 处的元素是 %d。\n", location, data);
            }
            else
            {
                printf("元素查找失败。\n");
            }
            break;

        case 5:
            // 获取长度
            printf("线性表的长度: %d\n", getLength(&list));
            break;

        case 6:
            // 查找元素位置
            printf("输入数据以获取其位置: ");
            scanf("%d", &data);
            location = getLocation(&list, data);
            if (location != -1)
            {
                printf("元素 %d 位于位置 %d。\n", data, location);
            }
            else
            {
                printf("未找到元素。\n");
            }
            break;

        case 7:
            // 获取状态
            if (getStatue(&list))
            {
                printf("线性表不为空。\n");
            }
            else
            {
                printf("线性表为空。\n");
            }
            break;

        case 8:
            // 销毁退出
            destroyList(&list);
            exit(0);

        default:
            // 无效选择
            printf("无效选择。\n");
            break;
        }
    }
}

// 主函数
int main()
{
    system("chcp 65001");
    menu();
    return 0;
}
