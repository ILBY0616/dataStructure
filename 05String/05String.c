#include <stdio.h>

int subLength = 6;
int mainLength = 10;

// 简单模式匹配
int easeMatch(char main[], char sub[])
{
    int i = 1, j = 1;
    while (i <= mainLength && j <= subLength)
    {
        if (main[i] == sub[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 2;
            j = 1;
        }
    }
    return j > subLength ? i - j + 1 : 0;
}

// 快速模式匹配
void getNext(char sub[], int next[])
{
    next[1] = 0;
    int i = 1, j = 0;
    while (i < subLength)
    {
        if (j == 0 || sub[i] == sub[j])
        {
            i++;
            j++;
            next[i] = sub[i] == sub[j] ? next[j] : j;
        }
        else
        {
            j = next[j];
        }
    }
}

int quickMatch(char main[], char sub[], int next[])
{
    int i = 1, j = 1;
    while (i <= mainLength && j <= subLength)
    {
        if (j == 0 || main[i] == sub[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }
    return j > subLength ? i - j + 1 : 0;
}

int main()
{
    int next[100];
    char sub[] = " google";
    char main[] = " goodgoogle";
    getNext(sub, next);
    printf("%d ", easeMatch(main, sub));
    printf("%d ", quickMatch(main, sub, next));
    return 0;
}
