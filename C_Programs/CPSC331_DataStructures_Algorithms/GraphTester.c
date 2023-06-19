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

    struct MGraph *graph3 = NewGraph(5);
    graph3->adjmatrix[0][1].edgeWeight = 10;
    graph3->adjmatrix[0][3].edgeWeight = 30;
    graph3->adjmatrix[0][4].edgeWeight = 100;
    graph3->adjmatrix[1][2].edgeWeight = 50;
    graph3->adjmatrix[2][4].edgeWeight = 10;
    graph3->adjmatrix[3][2].edgeWeight = 20;
    graph3->adjmatrix[3][4].edgeWeight = 60;
    PrintMGraph(graph3);


    int *costlist = DIJKSTRA(graph3, 0);
    printf("output\n");
    for (int i = 0; i < graph3->verticies; i++)
    {
        printf("%d\n", costlist[i]);
    }

    int **APSP = DijkstraAPSP(graph3);
    for (int i = 0; i < graph3->verticies; i++)
    {
        printf("from %d = [",i);
        for (int j = 0; j < graph3->verticies; j++)
        {
        printf("%d, ", APSP[i][j]);
        }
        printf("]\n");
    }
    
    






    return 0;
}