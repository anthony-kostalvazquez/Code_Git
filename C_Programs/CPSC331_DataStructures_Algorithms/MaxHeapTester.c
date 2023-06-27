#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "../AnthonysCLib/MinHeap.h"

int main()
{
    struct MinHeap* heap = NewHeap();
    MinHEnqueue(heap, 2);
    MinHEnqueue(heap, 9);
    MinHEnqueue(heap, 39);
    MinHEnqueue(heap, 42);
    MinHEnqueue(heap, 44);
    MinHEnqueue(heap, 65);
    MinHEnqueue(heap, 86);
    MinHEnqueue(heap, 88);
    MinHEnqueue(heap, 59);
    MinHEnqueue(heap, 50);
    PrintHeap(heap);

    printf("\nmin value is = %d\n", MinHDequeue(heap));
    PrintHeap(heap);

    free(heap);
    return(0);
}