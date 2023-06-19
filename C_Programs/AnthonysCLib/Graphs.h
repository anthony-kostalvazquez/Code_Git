#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

#include "SingleLinkedQueue.h"

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

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

//====================Min Heap Implementation====================//
struct MinHeap
{
    int size;
    VERTEX_T *QArray;
};

//takes two array indexes and the array and swaps the values
void ArraySwap(VERTEX_T *array, int in1, int in2)
{
    VERTEX_T tmp = array[in1];
    array[in1] = array[in2];
    array[in2] = tmp;
}

//will create a new heap and allocate the memory
struct MinHeap* NewHeap()
{
    struct MinHeap* tmp = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    tmp->QArray = NULL;
    tmp->size = 0;
}

//prints the heap 
void PrintHeap(struct MinHeap* heap)
{
    //printf("=====Array Representation=====\n[");
    for (int v = 0; v < heap->size; v++)
    {
        printf("(%d,%d)", heap->QArray[v].id, heap->QArray[v].edgeWeight);
    }
    printf("]\n");
    
    /*
    //since heaps are always complete this is the max height
    double height = ceil(log2((double)(heap->size + 1)));
    //since heaps are always complete this is the max width
    double width = pow(2,height);
    double numspaces = 0;
    int j = 0;
    //printf("height = %f, %f\n",height,width);

    for (double i = 1; i <= height; i++)
    { 
        numspaces = (width / (pow(2,i)));
        //printf("num spaces = %f, number = %f, j = %d\n", numspaces, pow(2,i) + 1, j); 

        while(j < pow(2,i) - 1 && j < heap->size)
        {
            //prints white space
            for (int l = 0; l < numspaces; l++)
            {
                printf(" ");
            }

            //prints the value in the array
            printf("(%d,%d)", heap->QArray[j].id, heap->QArray[j].edgeWeight);
            j++;
        }
        printf("\n");
        
    }
    */
}

//enques the given value into the max heap and maintains the minheap properties
void MinHEnqueue(struct MinHeap* heap, int id, int edgeweight)
{
    heap->QArray = (VERTEX_T *)realloc(heap->QArray, sizeof(VERTEX_T*) * (heap->size + 1));
    heap->QArray[heap->size].edgeWeight = edgeweight;
    heap->QArray[heap->size].id = id;

    //fix the heap
    int location = heap->size;
    int parent = (location-1)/2;

    /*for maxH
    while(location > 0 && heap->QArray[location] < heap->QArray[parent])
    */
    while(location > 0 && heap->QArray[location].edgeWeight < heap->QArray[parent].edgeWeight)
    {
        ArraySwap(heap->QArray, location, parent);
        location = parent;
        parent = (location-1)/2;
    }

    heap->size++;
}

//Will continue to sink the given integer in the array of the heap until it is in its proper location
void HSink(int location, struct MinHeap* heap)
{
    int size = heap->size;
    VERTEX_T *array = heap->QArray;
    int swapWith;
    int left = 2*location + 1;
    int right = 2*location + 2;
    int node_to_sink = array[location].edgeWeight;
    
    if(left > size - 1) //reached a leaf
    {
        return;
    }
    else if (left == size - 1) //this means we have a node with only 1 child
    {
        if (array[left].edgeWeight < node_to_sink)
        {
            ArraySwap(array, left, node_to_sink);
        }
    }
    else //The node has 2 children
    {
        //decides what child to swap with
        if (array[left].edgeWeight > array[right].edgeWeight)
        {
            swapWith = right;
        }
        else
        {
            swapWith = left;
        }
        
        if (node_to_sink > swapWith)
        {
            ArraySwap(array, swapWith, location);
            HSink(swapWith, heap);
        }
    }
}

//deques the top value (THE MIN)
VERTEX_T MinHDequeue(struct MinHeap* heap)
{
    //gets min value from the 0 position
    VERTEX_T min = heap->QArray[0];

    //replaces the 0 position with the size-1 position
    heap->QArray[0] = heap->QArray[heap->size - 1];

    //sinks the new 0 position to its proper place
    HSink(0, heap);

    //adjusts the queue size
    heap->QArray = (VERTEX_T *)realloc(heap->QArray, sizeof(VERTEX_T*) * (heap->size - 1));
    heap->size--;

    return(min);
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
//basically this will return a list of verticies that are reachable from the specified vertex
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

    enqueue(startVertex, tmpQ);
    while(!isEmpty(tmpQ))
    {
        current = dequeue(tmpQ);
        enqueue(current, outQ);
        visited[current] = true;
        for (int i = 0; i < graph->verticies; i++)
        {
            if (((graph->adjmatrix)[current][i].edgeWeight != 0) && !(visited[i]))
            {
                enqueue(i, tmpQ);
                visited[i] = true;
            }
            
        }

    }

    return(outQ);
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

        printf("\n\nNEW CALL\n\n");
        if(sSHasCycle(graph, i, visited))
        {
            return true;
        }
    }

    return false;
}

//returns a queue of DFS walk of vertices from startVertex

//Returns the cost of the shortest path from s to every other vertex [Dijkstra’s Algorithm]
int *DIJKSTRA(struct MGraph *graph, int vertex)
{
    //initialize cost list
    int *CostList = malloc(sizeof(int*) * graph->verticies);

    //setting the costs of all the edges pointing from the starting vertex
    for (int j = 0; j < graph->verticies; j++)
    {
        if (graph->adjmatrix[vertex][j].edgeWeight == 0)
        {
            CostList[j] = INT_MAX;
        }
        else
        {
            CostList[j] = graph->adjmatrix[vertex][j].edgeWeight;
        }
    }

    //initialize ToCheck without the starting vertex
    struct MinHeap *ToCheck = NewHeap();
    for (int i = 1; i < graph->verticies; i++)
    {
        MinHEnqueue(ToCheck, i, CostList[i]);
    }

    //main loop
    VERTEX_T w;
    VERTEX_T v;
    printf("ToCheck V-S = ");
    PrintHeap(ToCheck);

    printf("Cost List = [");
    for (int bla = 0; bla < graph->verticies; bla++)
    {
        printf("%d, ", CostList[bla]);
    }
    printf("] \n IN MAIN LOOP \n\n");

    while (ToCheck->size != 1)
    {
        //finds the vertex w in ToCheck where CostList[w] is minimum
        w = MinHDequeue(ToCheck);

        printf("ToCheck V-S = ");
        PrintHeap(ToCheck);

        printf("Cost List = [");
        for (int bla = 0; bla < graph->verticies; bla++)
        {
            printf("%d, ", CostList[bla]);
        }
        printf("]\n");
        
        
        printf("w = %d\n", w.id);

        for (int ver = 0; ver < ToCheck->size; ver++)
        {
            v = ToCheck->QArray[ver];
            if(graph->adjmatrix[w.id][v.id].edgeWeight != 0)
            {
                if (!(CostList[v.id] == INT_MAX && CostList[w.id] == INT_MAX))
                {
                    printf("\tCost List = [");
                    for (int bla = 0; bla < graph->verticies; bla++)
                    {
                        printf("%d, ", CostList[bla]);
                    }
                    printf("]\n");

                    
                    printf("\t%d, %d, %d\n", v.id ,CostList[v.id], CostList[w.id] + graph->adjmatrix[w.id][v.id].edgeWeight);

                    CostList[v.id] = MIN(CostList[v.id], CostList[w.id] + graph->adjmatrix[w.id][v.id].edgeWeight);

                    ToCheck->QArray[ver].edgeWeight = CostList[v.id];
                    HSink(v.id, ToCheck);
                }
            }
            
        }
    }

    return(CostList);
}

int **DijkstraAPSP(struct MGraph *graph)
{
    //allocate mem for the return
    int **ret_array = (int **)malloc(sizeof(int **) * graph->verticies);
    for (int i = 0; i < graph->verticies; i++)
    {
        ret_array[i] = (int *)malloc(sizeof(int *) * graph->verticies);
    }

    for (int vertex = 0; vertex < graph->verticies; vertex++)
    {
        ret_array[vertex] = DIJKSTRA(graph, vertex);
    }
    

    return(ret_array);
}

//====================Adjacency List Graph====================//
