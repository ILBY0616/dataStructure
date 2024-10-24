#include <stdbool.h>
#include <limits.h>
#include <string.h>

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node, *LBTree;

// 用栈和队列判断回文
bool isPalindrome(char* a)
{
    char stack[100];
    char queue[100];
    int top = -1, front = 0, rear = 0, length = strlen(a);
    for (int i = 0; i < length; i++)
    {
        // 入栈
        stack[++top] = a[i];
        // 入队
        queue[rear++] = a[i];
    }
    for (int j = 0; j < length; j++)
    {
        // 出栈出队逐一比较
        if (stack[top--] != queue[front++])
        {
            return false;
        }
    }
    return true;
}

// 在二叉排序树中找到值为X的结点
LBTree findNode(LBTree t, int X)
{
    while (t != NULL && t->data != X)
    {
        if (t->data < X)
        {
            t = t->right;
        }
        else
        {
            t = t->left;
        }
    }
    return t;
}

// 在n个顶点的有向图中，找到顶点v到所有其他城市的路径之和的最短路径和，有向图用邻接矩阵存储，边的代价从0到100
int findMinCost(int** a, int v, int n)
{
    int dist[n]; // 存储从顶点v到其他顶点的最短距离
    bool visited[n]; // 标记顶点是否已经找到最短路径
    int totalCost = 0; // 最短路径和

    // 初始化距离和访问标记
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX; // 初始距离为无穷大
        visited[i] = false; // 初始化所有顶点未访问
    }

    dist[v] = 0; // 顶点v到自身的距离为0

    // Dijkstra算法的核心步骤
    for (int i = 0; i < n - 1; i++)
    {
        // 找到未访问的顶点中距离最小的顶点
        int minDist = INT_MAX;
        int u = -1;
        for (int j = 0; j < n; j++)
        {
            if (!visited[j] && dist[j] < minDist)
            {
                minDist = dist[j];
                u = j;
            }
        }

        // 标记找到的顶点为已访问
        if (u == -1) break; // 无法继续找到更短的路径
        visited[u] = true;

        // 更新从顶点u到其他未访问顶点的最短距离
        for (int j = 0; j < n; j++)
        {
            if (!visited[j] && a[u][j] != INT_MAX && dist[u] != INT_MAX && dist[u] + a[u][j] < dist[j])
            {
                dist[j] = dist[u] + a[u][j];
            }
        }
    }

    // 计算顶点v到所有其他顶点的最短路径之和
    for (int i = 0; i < n; i++)
    {
        if (dist[i] != INT_MAX)
        {
            totalCost += dist[i];
        }
    }

    return totalCost;
}

int main()
{
    return 0;
}