#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>





double maxProbability(int n, int** edges, int edgesSize, int* edgesColSize, double* succProb, int succProbSize, int start, int end)
{
    





}






int main()
{
    int n = 3;
    int edgesSize = 3;
    int edgesColSize = 2; 

    int **edges = malloc(sizeof(int *) * edgesSize);
    for (int i = 0; i < edgesSize; i++)
    {
        edges[i] = malloc(sizeof(int *) * edgesColSize);   
    }
    
    int **edgeslist[3][2] = {{0,1},{1,2},{0,2}};
    edges = edgeslist;




    int edgesSize = 3;
    int edgesColSize = 2; 
    double succProb[3] = {0.5,0.5,0.2};
    int succProbSize = 3;
    int start = 0;
    int end = 2;

    printf("Output is = %f", maxProbability(n, edges, edgesSize, edgesColSize, succProb, succProbSize, start, end));

    return 0;
}
