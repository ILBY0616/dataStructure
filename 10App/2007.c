#include <stdbool.h>
#include <AMGraph.h>
#include <LBTree.h>

// 用栈和队列判断输入序列是否是回文
bool isPalindrome()
{
    char stack[100];
    char queue[100];
    int top = -1, front = -1, rear = -1;
    char data;
    while (scanf("%c", &data) == 1 && data != '@')
    {
        // 输入字符入栈入队
        stack[++top] = data;
        queue[++rear] = data;
    }
    while (top != -1 && front != rear)
    {
        // 出栈出队逐一比较
        if (stack[top--] != queue[++front])
        {
            return false;
        }
    }
    return true;
}

// 在二叉排序树中找到值为X的结点
LBTree findKeyNode(LBTree tree, char key)
{
    while (tree != NULL && tree->data != key)
    {
        if (tree->data < key)
        {
            tree = tree->right;
        }
        else
        {
            tree = tree->left;
        }
    }
    return tree;
}

// 用邻接矩阵存储n的顶点有向图，计算从某一顶点出发到其他所有顶点路径的和的最小值
void dijkstraAMGraph(AMGraph graph, int startIndex)
{
    int prior[graph->vertexSum];
    int distance[graph->vertexSum];
    bool visited[graph->vertexSum];
    for (int i = 0; i < graph->vertexSum; i++)
    {
        distance[i] = INT_MAX;
        visited[i] = false;
        prior[i] = -1;
    }
    distance[startIndex] = 0;
    for (int i = 0; i < graph->vertexSum; i++)
    {
        int minDistance = INT_MAX;
        int u = -1;
        for (int j = 0; j < graph->vertexSum; j++)
        {
            if (!visited[j] && distance[j] < minDistance)
            {
                minDistance = distance[j];
                u = j;
            }
        }
        if (u == -1)
        {
            break;
        }
        visited[u] = true;
        for (int v = 0; v < graph->vertexSum; v++)
        {
            if (!visited[v] && graph->edge[u][v] < INT_MAX && graph->edge[u][v] > 0)
            {
                int newDist = distance[u] + graph->edge[u][v];
                if (newDist < distance[v])
                {
                    distance[v] = newDist;
                    prior[v] = u;
                }
            }
        }
    }
    for (int i = 0; i < graph->vertexSum; i++)
    {
        printf("%c\t", graph->vertex[i]);
        if (distance[i] == INT_MAX)
        {
            printf(" \t");
        }
        else
        {
            printf("%d\t", distance[i]);
        }
        if (distance[i] != INT_MAX)
        {
            int path[graph->vertexSum], pathIndex = 0;
            for (int v = i; v != -1; v = prior[v])
            {
                path[pathIndex++] = v;
            }
            for (int j = pathIndex - 1; j >= 0; j--)
            {
                printf("%c", graph->vertex[path[j]]);
                if (j > 0) printf("->");
            }
        }
        printf("\n");
    }
}

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\10App.2007.exe
// abcba@
// YES
// ji^^k^^
// k in tree
// Input vertexSum edgeSum:
// 4 3
// Input vertex 0's value:
// a
// Input vertex 1's value:
// b
// Input vertex 2's value:
// c
// Input vertex 3's value:
// d
// Input startIndex endIndex weight:
// 0 1 1
// Input startIndex endIndex weight:
// 1 2 2
// Input startIndex endIndex weight:
// 2 0 3
// a       0       a
// b       1       a->b
// c       3       a->b->c
// d
//
// Process finished with exit code 0

int main()
{
    if (isPalindrome())
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    getchar();

    char key = 'k';
    LBTree tree = NULL, pointer = NULL;
    buildLBTree(&tree);
    pointer = findKeyNode(tree, key);
    if (pointer != NULL)
    {
        printf("%c in tree\n", pointer->data);
    }
    else
    {
        printf("k not in tree\n");
    }
    destroyLBTree(&tree);

    AMGraph graph = NULL;
    initiateAMGraph(&graph);
    createDAMGraph(graph);
    dijkstraAMGraph(graph, 0);
    destroyAMGraph(&graph);
    return 0;
}
