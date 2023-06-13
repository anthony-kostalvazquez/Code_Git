#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "SingleLinkedQueue.h"


//====================Color Implementation====================//
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

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
    struct MGraph *retgraph = malloc(sizeof(struct MGraph*));
    
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

//prints a graph as a matrix (NOW with colours)
void PrintMGraph(struct MGraph *graph)
{
    printf("Graph Adjacency Matrix\n");
    for (int row = 0; row < graph->verticies; row++)
    {
        //prints the top and bottom indicators
        if(row == 0)
        {
            printf("   ");
            for (int i = 0; i < graph->verticies; i++)
            {
                printf(GRN "[%d]" RESET, i);
            }
            printf("\n");
        }
        printf(GRN "[%d]" RESET, row);

        for (int col = 0; col < graph->verticies; col++)
        {
            printf(" %d ", (graph->adjmatrix)[row][col].edgeWeight);
        }
        printf("\n");
    }
    
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

//returns a queue of BFS walk of vertices from startVertex
struct LinkedQueue* oneSourceBFS(int startVertex, struct MGraph *graph)
{
    struct LinkedQueue *outQ = createQueue();
    struct LinkedQueue *tmpQ = createQueue();
    bool visited[graph->verticies];
    for (int i = 0; i < graph->verticies; i++)
    {
        visited[i] = false;
    }
    
    int current;

    enqueue(startVertex, &tmpQ);
    while(!isEmpty(tmpQ))
    {
        current = dequeue(&tmpQ);
        enqueue(current, &outQ);
        visited[current] = true;
        for (int i = 0; i < graph->verticies; i++)
        {
            if (((graph->adjmatrix)[current][i].edgeWeight != 0) && !(visited[i]))
            {
                enqueue(i, &tmpQ);
                visited[i] = true;
            }
            
        }

    }

    return(outQ);
}



//====================Adjacency List Graph====================//

