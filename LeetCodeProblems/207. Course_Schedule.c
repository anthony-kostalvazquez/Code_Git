#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//#include "../C_Programs/AnthonysCLib/Graphs.h"

//====================Vertex Implementation====================//
struct vertex
{
    int id; //name of the node
    int edgeWeight; // weight of the incoming edge to this vertex
};
typedef struct vertex VERTEX_T;

//makes and aloctaes a vertex
VERTEX_T *CreateVertex(int id,int weight)
{
    VERTEX_T *tmp = malloc(sizeof(VERTEX_T));
    tmp->edgeWeight = weight;
    tmp->id = id;

    return(tmp);
}

//====================Adjacency Matrix Graph====================//
struct MGraph
{
    int verticies;
    VERTEX_T **adjmatrix;
};

//creates a new graph and initates all of the edgeweights to 0 and ids to 1->size
struct MGraph *NewGraph(int verticies)
{
    //allocte the graph struct
    struct MGraph *retgraph = malloc(sizeof(struct MGraph));
    
    //allocate the matrix
    VERTEX_T **matrix = (VERTEX_T **)malloc(sizeof(VERTEX_T) * verticies);
    for (int i = 0; i < verticies; i++)
    {
        matrix[i] = malloc(sizeof(VERTEX_T) * verticies);
        
        for (int j = 0; j < verticies; j++)
        {
            matrix[i][j].edgeWeight = 0;
            matrix[i][j].id = i;
        }
        
    }
    

    retgraph->adjmatrix = matrix;
    retgraph->verticies = verticies;

    return(retgraph);
}

//make an adjacency matrix from a list of edges
struct MGraph *MakeGraphFromEdges(int **edge_list, int edges, int verticies)
{
    struct MGraph *retgraph = NewGraph(verticies);

    int currow, curcol;

    for (int i = 0; i < edges; i++)
    {
        currow = edge_list[i][0];
        curcol = edge_list[i][1];
        (retgraph->adjmatrix)[currow][curcol].edgeWeight = 1; 
    }

    retgraph->verticies = verticies;
    
    return(retgraph);
}

//checks if a walk from a single source has a cycle
//PAINFULLY RECURSIVE
bool sSHasCycle(struct MGraph *graph, int startVertex, bool *visited)
{
    int i = 0;
    visited[startVertex] = true;
    printf("called with start = %d, \n visited = ",startVertex);

    for (int i = 0; i < graph->verticies; i++)
    {
        printf("%d ",visited[i]);
    }
    printf("\n");
    for (i = 0; i < graph->verticies; i++)
    {
        if(((graph->adjmatrix)[startVertex][i].edgeWeight != 0))
        {
            printf("checking (%d,%d), i = %d\n", startVertex, i, i);
            if(!(visited[i]))
            {
                if(sSHasCycle(graph, i, visited))
                {
                    printf("returning true\n");
                    return true;

                }
            } 
            else
            {
                printf("returning true\n");
                return(true);
            }
        }
            
    }

    visited[i] = false;

    return(false);
}

//checks if a graph is acylic (meaning it has no cycles)
bool HasCycle(struct MGraph *graph)
{
    bool visited[graph->verticies];
    for (int i = 0; i < graph->verticies; i++)
    {
        for (int i = 0; i < graph->verticies; i++)
        {
            visited[i] = false;
        }
        if(sSHasCycle(graph, i, visited))
        {
            return true;
        }
    }

    return false;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize)
{
    struct MGraph *graph = MakeGraphFromEdges(prerequisites, prerequisitesSize, numCourses);

    return(!HasCycle(graph));
}

int main()
{
    int numCourses = 4;
    int prerequisitesSize = 5;
    int prerequisitesColSize = 2;

    int in_array[5][2] = {{2,0},{1,0},{3,1},{3,2},{1,3}};


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