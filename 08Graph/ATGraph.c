#include <ATGraph.h>

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\08Graph.ATGraph.exe
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
// ATGraph:
// a->1
// b->2
// c->0
// d
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
// acb
// BFS:
// acb
// ATGraph:
// a->2->1
// b->2->0
// c->0->1
// d
//
// Process finished with exit code 0

int main()
{
    bool visited[100];
    ATGraph graph = NULL;
    initiateATGraph(&graph);
    createDATGraph(graph);
    for (int i = 0; i < 100; i++)
    {
        visited[i] = false;
    }
    printf("DFS:\n");
    DFSATGraph(graph, 0, visited);
    printf("\n");
    for (int i = 0; i < 100; i++)
    {
        visited[i] = false;
    }
    printf("BFS:\n");
    BFSATGraph(graph, 0, visited);
    printf("\n");
    printATGraph(graph);
    destroyATGraph(&graph);
    initiateATGraph(&graph);
    createUATGraph(graph);
    for (int i = 0; i < 100; i++)
    {
        visited[i] = false;
    }
    printf("DFS:\n");
    DFSATGraph(graph, 0, visited);
    printf("\n");
    for (int i = 0; i < 100; i++)
    {
        visited[i] = false;
    }
    printf("BFS:\n");
    BFSATGraph(graph, 0, visited);
    printf("\n");
    printATGraph(graph);
    destroyATGraph(&graph);
    return 0;
}
