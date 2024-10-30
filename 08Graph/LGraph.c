#include <stdlib.h>
#include <stdio.h>

#define type int
#define size 100

typedef struct Edge
{
    type data;
    struct Edge* next;
} Edge;

typedef struct Vertex
{
    type data;
    Edge* first;
} Vertex;

typedef struct Graph
{
    Vertex vertexList[size];
    int vertexSum, edgeSum;
} Graph;

// 创建有向图
void createDGraph(Graph* graph);
// 创建无向图
void createUGraph(Graph* graph);
// 打印邻接表
void printGraph(Graph* graph);
// 销毁邻接表
void destroyGraph(Graph* graph);

int main()
{
    Graph graph;
    createDGraph(&graph);
    printGraph(&graph);
    destroyGraph(&graph);
    createUGraph(&graph);
    printGraph(&graph);
    destroyGraph(&graph);
    return 0;
}

void createDGraph(Graph* graph)
{
    printf("请输入顶点的数量和边的数量:\n");
    scanf("%d %d", &graph->vertexSum, &graph->edgeSum);
    for (int i = 0; i < graph->vertexSum; i++)
    {
        printf("请输入顶点 %d 的值: ", i);
        scanf("%d", &graph->vertexList[i].data);
        graph->vertexList[i].first = NULL;
    }
    for (int i = 0; i < graph->edgeSum; i++)
    {
        type startVertex, endVertex;
        printf("请输入边的起点和终点: ");
        scanf("%d %d", &startVertex, &endVertex);
        Edge* edge = malloc(sizeof(Edge));
        if (edge != NULL)
        {
            edge->data = endVertex;
            edge->next = graph->vertexList[startVertex].first;
            graph->vertexList[startVertex].first = edge;
        }
    }
}

void createUGraph(Graph* graph)
{
    printf("请输入顶点的数量和边的数量:\n");
    scanf("%d %d", &graph->vertexSum, &graph->edgeSum);
    for (int i = 0; i < graph->vertexSum; i++)
    {
        printf("请输入顶点 %d 的值: ", i);
        scanf("%d", &graph->vertexList[i].data);
        graph->vertexList[i].first = NULL;
    }
    for (int i = 0; i < graph->edgeSum; i++)
    {
        type startVertex, endVertex;
        printf("请输入边的起点和终点: ");
        scanf("%d %d", &startVertex, &endVertex);
        Edge* edge1 = malloc(sizeof(Edge));
        Edge* edge2 = malloc(sizeof(Edge));
        if (edge1 != NULL && edge2 != NULL)
        {
            edge1->data = endVertex;
            edge1->next = graph->vertexList[startVertex].first;
            graph->vertexList[startVertex].first = edge1;
            edge2->data = startVertex;
            edge2->next = graph->vertexList[endVertex].first;
            graph->vertexList[endVertex].first = edge2;
        }
    }
}

void printGraph(Graph* graph)
{
    for (int i = 0; i < graph->vertexSum; i++)
    {
        printf("顶点 %d: ", graph->vertexList[i].data);
        Edge* edge = graph->vertexList[i].first;
        while (edge != NULL)
        {
            printf("-> %d ", edge->data);
            edge = edge->next;
        }
        printf("\n");
    }
}

void destroyGraph(Graph* graph)
{
    for (int i = 0; i < graph->vertexSum; i++)
    {
        Edge* edge = graph->vertexList[i].first;
        while (edge != NULL)
        {
            Edge* temp = edge;
            edge = edge->next;
            free(temp);
        }
        graph->vertexList[i].first = NULL;
    }
    graph->vertexSum = 0;
    graph->edgeSum = 0;
}
