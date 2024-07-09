#include <stdio.h>
#include <stdlib.h>

#define maxSize 100
#define type int

// 统一重点：ToDo
// 统一提示：中文
// 统一注释：代码上方
// 统一状态：-1失败，0成功，1其他

// 顺序栈
typedef struct SStack
{
    type data[maxSize];
    int top;
} SStack;

void initiateStack(SStack* s)
{
    s->top = -1;
}

int getStatus(SStack* s)
{
    int result;
    if (s->top == -1)
    {
        result = -1;
    }
    else if (s->top + 1 == maxSize)
    {
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}

int getTop(SStack* s,type* data)
{
    int result;
    if (s->top == -1)
    {
        result = -1;
    }
    else
    {
        *data = s->data[s->top];
        result = 0;
    }
    return result;
}

int push(SStack* s,type data)
{
    int result;
    if (s->top + 1 == maxSize)
    {
        result = -1;
    }
    else
    {
        s->data[++s->top] = data;
        result = 0;
    }
    return result;
}

int pop(SStack* s,type* data)
{
    int result;
    if (s->top == -1)
    {
        result = -1;
    }
    else
    {
        *data = s->data[s->top--];
        result = 0;
    }
    return result;
}

void destroy(SStack* s)
{
    s->top = -1;
}

void displayMenu()
{
    printf("菜单\n");
    printf("1.初始化栈\n");
    printf("2.获取栈状态\n");
    printf("3.获取栈顶元素\n");
    printf("4.入栈操作\n");
    printf("5.出栈操作\n");
    printf("6.销毁栈\n");
    printf("7.退出\n");
    printf("\n");
}

void menu()
{
    SStack stack;
    int choice, status;
    type data;

    while (1)
    {
        printf("请输入您的选择: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            initiateStack(&stack);
            printf("栈初始化成功\n");
            break;
        case 2:
            status = getStatus(&stack);
            if (status == -1)
            {
                printf("栈状态: 栈空\n");
            }
            else if (status == 1)
            {
                printf("栈状态: 栈满\n");
            }
            else
            {
                printf("栈状态: 栈余\n");
            }
            break;
        case 3:
            if (getTop(&stack, &data) == 0)
            {
                printf("栈顶元素: %d\n", data);
            }
            else
            {
                printf("获取栈顶元素失败\n");
            }
            break;
        case 4:
            printf("请输入要入栈的元素: ");
            scanf("%d", &data);
            if (push(&stack, data) == 0)
            {
                printf("元素 %d 入栈成功\n", data);
            }
            else
            {
                printf("元素 %d 入栈失败\n", data);
            }
            break;
        case 5:
            if (pop(&stack, &data) == 0)
            {
                printf("元素 %d 出栈成功\n", data);
            }
            else
            {
                printf("出栈失败\n");
            }
            break;
        case 6:
            destroy(&stack);
            printf("栈销毁成功\n");
            break;
        case 7:
            printf("退出程序\n");
            exit(0);
        default:
            printf("无效的选择，请重新输入\n");
        }
    }
}

int main()
{
    system("chcp 65001");
    displayMenu();
    menu();
    return 0;
}
