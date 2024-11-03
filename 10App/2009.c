#include <stdbool.h>
#include <stdio.h>

typedef struct Stack
{
    char* data;
    int length;
} Stack, *SStack;

typedef struct Node
{
    char data;
    struct Node* next;
} Node, *LQueue;

bool iniStacck();
bool iniQueue();
bool popStack();
bool pushStack();

int main()
{
    printf("Hello, World!\n");
    return 0;
}
