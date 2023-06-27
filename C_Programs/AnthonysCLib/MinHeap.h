#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

struct MinHeap
{
    int size;
    int *QArray;
};

//takes two array indexes and the array and swaps the values
void ArraySwap(int *array, int in1, int in2)
{
    int tmp = array[in1];
    array[in1] = array[in2];
    array[in2] = tmp;
}

//will create a new heap and allocate the memory
struct MinHeap* NewHeap()
{
    struct MinHeap* tmp = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    tmp->QArray = NULL;
    tmp->size = 0;

    return tmp;
}

//prints the heap 
void PrintHeap(struct MinHeap* heap)
{
    printf("=====Array Representation=====\n[");
    for (int v = 0; v < heap->size; v++)
    {
        printf("%d,", heap->QArray[v]);
    }
    printf("]\n");
    
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
            printf("%d", heap->QArray[j]);
            j++;
        }
        printf("\n");
        
    }
    
}

//enques the given value into the min heap and maintains the minheap properties
void MinHEnqueue(struct MinHeap* heap, int value)
{
    heap->QArray = (int *)realloc(heap->QArray, sizeof(int*) * (heap->size + 1));
    heap->QArray[heap->size] = value;

    //fix the heap
    int location = heap->size;
    int parent = (location-1)/2;

    /*for maxH
    while(location > 0 && heap->QArray[location] < heap->QArray[parent])
    */
    while(location > 0 && heap->QArray[location] < heap->QArray[parent])
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
    int *array = heap->QArray;
    int swapWith;
    int left = 2*location + 1;
    int right = 2*location + 2;
    int node_to_sink = array[location];
    
    if(left > size - 1) //reached a leaf
    {
        return;
    }
    else if (left == size - 1) //this means we have a node with only 1 child
    {
        if (array[left] < node_to_sink)
        {
            ArraySwap(array, left, node_to_sink);
        }
    }
    else //The node has 2 children
    {
        //decides what child to swap with
        if (array[left] > array[right])
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
int MinHDequeue(struct MinHeap* heap)
{
    //gets min value from the 0 position
    int min = heap->QArray[0];

    //replaces the 0 position with the size-1 position
    heap->QArray[0] = heap->QArray[heap->size - 1];

    //sinks the new 0 position to its proper place
    HSink(0, heap);

    //adjusts the queue size
    heap->QArray = (int *)realloc(heap->QArray, sizeof(int*) * (heap->size - 1));
    heap->size--;

    return(min);
}