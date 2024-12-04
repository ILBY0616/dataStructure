#include <stdbool.h>
#include <AMGraph.h>
#include <LBTree.h>

// 判断输入序列是否是回文
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

// 返回二叉排序树中值为key的结点
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

// 求解邻接矩阵存储的有向图中指定顶点到所有其他顶点路径之和的最小值
void getMinPathAMGraph(AMGraph graph, int startIndex, int* prior, int* distance,bool* visited)
{
    for (int i = 0; i < graph->vertexSum; i++)
    {
        // 初始化最短距离
        distance[i] = INT_MAX;
        // 初始化访问状态
        visited[i] = false;
        // 初始化前驱结点
        prior[i] = -1;
    }
    distance[startIndex] = 0;
    for (int i = 0; i < graph->vertexSum; i++)
    {
        // 查找当前所有未访问顶点中距离最小的顶点
        int minNode = -1;
        int minDistance = INT_MAX;
        for (int j = 0; j < graph->vertexSum; j++)
        {
            if (visited[j] == false && distance[j] < minDistance)
            {
                minDistance = distance[j];
                minNode = j;
            }
        }
        if (minNode == -1)
        {
            break;
        }
        // 更改最小顶点访问状态和所有结点最短距离
        visited[minNode] = true;
        for (int j = 0; j < graph->vertexSum; j++)
        {
            if (visited[j] == false && 0 < graph->edge[minNode][j] && graph->edge[minNode][j] < INT_MAX)
            {
                int newDistance = distance[minNode] + graph->edge[minNode][j];
                if (newDistance < distance[j])
                {
                    distance[j] = newDistance;
                    prior[j] = minNode;
                }
            }
        }
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
// 2 3 3
// 10
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
    LBTree tree = NULL, node = NULL;
    buildLBTree(&tree);
    node = findKeyNode(tree, key);
    if (node != NULL)
    {
        printf("%c in tree\n", node->data);
    }
    else
    {
        printf("k not in tree\n");
    }
    destroyLBTree(&tree);

    int prior[100];
    int distance[100];
    bool visited[100];
    int pathSum = 0;
    int startIndex = 0;
    AMGraph graph = NULL;
    initiateAMGraph(&graph);
    createDAMGraph(graph);
    getMinPathAMGraph(graph, startIndex, prior, distance, visited);
    for (int i = 0; i < graph->vertexSum; i++)
    {
        pathSum += distance[i];
    }
    printf("%d", pathSum);
    destroyAMGraph(&graph);
    return 0;
}
