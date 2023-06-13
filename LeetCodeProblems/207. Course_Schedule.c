#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct MGraph
{
    int verticies;
    int **adjmatrix;
};

struct MGraph *NewGraph()
{
    //allocte the graph struct
    struct MGraph *retgraph = malloc(sizeof(struct MGraph*));
    
    //allocate the matrix
    int **matrix = (int **)malloc(sizeof(int*));

    retgraph->adjmatrix = matrix;
    retgraph->verticies = 0;

    return(retgraph);
}


//make an adjacency matrix from a list of edges
struct MGraph *MakeMatrixFromEdges(int **edge_list, int edges, int verticies, struct MGraph *graph)
{
    graph->adjmatrix = realloc(graph->adjmatrix, sizeof(int*) * verticies);
    for (int i = 0; i < verticies; i++)
    {
        (graph->adjmatrix)[i] = calloc(verticies, sizeof(int*));
    }
    

    int current_node;
    for (int i = 0; i < edges; i++)
    {
        current_node = edge_list[i][0];
        (graph->adjmatrix)[][]


        
    }
    
}



bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize)
{
    bool ret_val = false;
    

    



    return false;
}

int main()
{
    int numCourses = 2;
    int prerequisitesSize = 2;
    int prerequisitesColSize = 2;

    int in_array[2][2] = {{1,0},{0,1}};


    //allocates the mem for the prereq array
    int **prerequisites = (int **)malloc(sizeof(int*) * prerequisitesSize);
    for (int i = 0; i < prerequisitesSize; i++)
    {
        prerequisites[i] = malloc(sizeof(int*) * prerequisitesColSize);
        prerequisites[i] = in_array[i];
    }


    printf("%d", canFinish(numCourses, prerequisites, prerequisitesSize, &prerequisitesColSize));

    return 0;
}