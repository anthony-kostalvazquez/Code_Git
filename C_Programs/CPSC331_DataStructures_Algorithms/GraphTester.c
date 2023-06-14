#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../AnthonysCLib/Graphs.h"




int main()
{
    struct MGraph *graph = NewGraph(10);
    PrintMGraph(graph);


    int edges = 5;
    int verticies = 4;
    int in_array[5][2] = {{2,0},{1,0},{3,1},{3,2},{1,3}};

    int **edge_arr = malloc(sizeof(int) * verticies);
    for (int i = 0; i < edges; i++)
    {
        edge_arr[i] = malloc(sizeof(int) * 2);
        edge_arr[i] = in_array[i];
    }
    
    


    struct MGraph *graph2 = MakeGraphFromEdges(edge_arr, edges, verticies);
    PrintMGraph(graph2);

    struct LinkedQueue* queue= oneSourceBFS(2, graph2);
    printQueue(queue);


    //sSHasCycle(graph2, 0);
    //printf("HasSsCycle = %d", sSHasCycle(graph2, 0, visited));



    printf("HasCycle = %d", HasCycle(graph2));





    return 0;
}