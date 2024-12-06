#include <AMGraph.h>

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\08Graph.AMGraph.exe
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
// DFS:
// abc
// BFS:
// abc
// AMGraph:
// ^ 1 ^ ^
// ^ ^ 2 ^
// 3 ^ ^ ^
// ^ ^ ^ ^
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
// DFS:
// abc
// BFS:
// abc
// AMGraph:
// ^ 1 3 ^
// 1 ^ 2 ^
// 3 2 ^ ^
// ^ ^ ^ ^
//
// Process finished with exit code 0

int main()
{
    bool visited[100];
    AMGraph graph = NULL;
    initiateAMGraph(&graph);
    createDAMGraph(graph);
    for (int i = 0; i < 100; i++)
    {
        visited[i] = false;
    }
    printf("DFS:\n");
    DFSAMGraph(graph, 0, visited);
    printf("\n");
    for (int i = 0; i < 100; i++)
    {
        visited[i] = false;
    }
    printf("BFS:\n");
    BFSAMGraph(graph, 0, visited);
    printf("\n");
    printAMGraph(graph);
    destroyAMGraph(&graph);
    initiateAMGraph(&graph);
    createUAMGraph(graph);
    for (int i = 0; i < 100; i++)
    {
        visited[i] = false;
    }
    printf("DFS:\n");
    DFSAMGraph(graph, 0, visited);
    printf("\n");
    for (int i = 0; i < 100; i++)
    {
        visited[i] = false;
    }
    printf("BFS:\n");
    BFSAMGraph(graph, 0, visited);
    printf("\n");
    printAMGraph(graph);
    destroyAMGraph(&graph);
    return 0;
}
