#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

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
    printf("[");
    for (int v = 0; v < heap->size; v++)
    {
        printf("%d,", heap->QArray[v]);
    }
    printf("]\n");
    
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
//want to hire k workers
long long totalCost(int* costs, int costsSize, int k, int candidates)
{
    long long T_Cost = 0;
    int hired = 0;
    int i;

    //construct the left and the right heap
    struct MinHeap* LeftHeap = NewHeap();
    struct MinHeap* RightHeap = NewHeap();
    for (i = 0; i < candidates && i < costsSize; i++)
    {
        MinHEnqueue(LeftHeap, costs[i]);
        if((costsSize - 1) - i > i)
        {
            MinHEnqueue(RightHeap, costs[(costsSize - 1) - i]);
        }
    }

    printf("==DEBUG==\n");
    PrintHeap(LeftHeap);
    PrintHeap(RightHeap);
    printf("\n");

    //main loop
    while(hired < k)
    {
        if(LeftHeap->size != 0 && LeftHeap->QArray[0] <= RightHeap->QArray[0])//if the left heap has the min value
        {
            T_Cost += MinHDequeue(LeftHeap);
            
            if((costsSize - 1) - i > i)
            {
                MinHEnqueue(LeftHeap, costs[i]);
                i++;
            }
        }
        else
        {
            T_Cost += MinHDequeue(RightHeap);
            
            if((costsSize - 1) - i > i)
            {
                MinHEnqueue(RightHeap, costs[(costsSize - 1) - i]);
                i++;
            }
        }
        hired++;
        
        printf("==DEBUG==\n");
        PrintHeap(LeftHeap);
        PrintHeap(RightHeap);
        printf("\n");
    }



    return T_Cost;

}


int main()
{
    int cost[16] = {31,25,72,79,74,65,84,91,18,59,27,9,81,33,17,58};
    int cost_size = 16;
    int k = 11;
    int candidates = 2;


    printf("the output is %lld \n", totalCost(cost, cost_size, k, candidates));


    return 0;

}