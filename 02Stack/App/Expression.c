#include <stdio.h>
#include <string.h>

#define size 100
#define type char

void convert(type* data)
{
    char sign[size];
    char number[size];
    int signTop = -1, numberTop = -1;
    for (int i = 0; i < strlen(data); i++)
    {
        if(data[i]){}
    }
}

int main()
{
    type data[size] = {'(','(','9','/','(','7','-','(','1','+','1',')',')',')','*','3',')','-','(','2','+','(','1','+','1',')',')'};
    return 0;
}
