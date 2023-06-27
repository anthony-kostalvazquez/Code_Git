#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

struct MinHeap
{
    int size;
    int QArray[100000];
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
void HSink(int index, struct MinHeap* h)
{
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    int min = index;
 
    // Checking whether our left or child element
    // is at right index or not to avoid index error
    if (left >= h->size || left < 0)
        left = -1;
    if (right >= h->size || right < 0)
        right = -1;
 
    // store left or right element in min if
    // any of these is smaller that its parent
    if (left != -1 && h->QArray[left] < h->QArray[index])
        min = left;
    if (right != -1 && h->QArray[right] < h->QArray[min])
        min = right;
 
    // Swapping the nodes
    if (min != index) {
        int temp = h->QArray[min];
        h->QArray[min] = h->QArray[index];
        h->QArray[index] = temp;
 
        // recursively calling for their child elements
        // to maintain min heap
        HSink(min, h);
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
    heap->size--;

    return(min);
}


//want to hire k workers
long long totalCost(int* costs, int costsSize, int k, int candidates)
{
    if(costsSize == 1)
    {
        return costs[0];
    }

    long long T_Cost = 0;
    int hired = 0;
    int leftindex = 0;
    int rightindex = costsSize - 1;

    //construct the left and the right heap
    struct MinHeap* LeftHeap = NewHeap();
    struct MinHeap* RightHeap = NewHeap();
    while( LeftHeap->size + RightHeap->size < costsSize && leftindex < candidates)
    {
        MinHEnqueue(LeftHeap, costs[leftindex]);
        leftindex++;
        if(LeftHeap->size + RightHeap->size < costsSize)
        {
            MinHEnqueue(RightHeap, costs[rightindex]);
            rightindex--;
        }
    }

    //printf("\nLeftIndex = %d, RightIndex = %d\n",leftindex,rightindex);
    //PrintHeap(LeftHeap);
    //PrintHeap(RightHeap);
    //printf("\n");

    //main loop
    while(hired < k)
    {
        
        if(RightHeap->size == 0 || LeftHeap->size != 0 && LeftHeap->QArray[0] <= RightHeap->QArray[0])//if the left heap has the min value
        {
            T_Cost += MinHDequeue(LeftHeap);
            
            if(leftindex <= rightindex)
            {
                MinHEnqueue(LeftHeap, costs[leftindex]);
                leftindex++;
            }
        }
        else
        {
            T_Cost += MinHDequeue(RightHeap);
            
            if(leftindex < rightindex)
            {
                MinHEnqueue(RightHeap, costs[rightindex]);
                rightindex--;
            }
        }
        hired++;
        
        //printf("LeftIndex = %d, RightIndex = %d\n",leftindex,rightindex);
        //PrintHeap(LeftHeap);
        //PrintHeap(RightHeap);
        //printf("\n");
    }

    free(RightHeap);
    free(LeftHeap);
    return T_Cost;
}


int main()
{
    int cost[225] = {211,169,4359,2335,3956,658,1371,1516,4637,2588,4166,250,4866,3122,1197,61,292,1616,4857,4067,1428,4912,3071,3108,2221,1932,4183,4101,727,2715,64,357,1186,2444,3766,3978,1962,1648,871,2961,1164,4792,1528,2064,2653,179,2780,3732,2881,1165,623,362,2371,1353,4219,4438,3765,4567,1372,4669,1496,3353,4147,33,4378,4634,1331,3014,3723,3271,433,1065,2345,4445,4077,2708,1303,2666,3311,1546,3078,4467,1683,414,4282,3510,478,2858,4805,1113,783,3999,2685,1025,3111,2394,2985,2693,1068,1806,690,4867,4178,1726,1680,1860,155,96,1500,4250,286,4145,771,1728,2677,353,1163,4876,2066,3910,2578,1298,3321,3236,1152,3140,2294,2200,69,3027,3675,3594,74,3575,2279,4874,1071,3085,1786,4596,1584,42,411,3962,2704,4411,1926,1300,4533,2119,3924,1034,128,911,4717,4767,1669,3669,2936,2099,3395,2487,2539,4722,122,642,4680,4813,708,4938,4156,1152,2789,699,4724,4159,1766,2662,492,2612,330,2010,458,161,794,2062,4281,717,3486,3331,474,4734,1869,4817,2796,1511,146,3857,3471,3674,45,519,3035,3830,4566,957,4705,3194,1524,2668,903,2833,2118,929,266,1177,3297,1681,400,2635,1962,1682,2116,603,1521};
    int cost_size = 225;
    int k = 222;
    int candidates = 2;


    printf("the output is %lld \n", totalCost(cost, cost_size, k, candidates));


    return 0;

}