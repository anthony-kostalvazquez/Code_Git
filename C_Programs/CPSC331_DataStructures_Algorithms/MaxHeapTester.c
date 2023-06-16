#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "../AnthonysCLib/MinHeap.h"

int main()
{
    struct MinHeap* heap = NewHeap();
    MinHEnqueue(heap, 35);
    MinHEnqueue(heap, 36);
    MinHEnqueue(heap, 31);
    MinHEnqueue(heap, 3);
    MinHEnqueue(heap, 10);
    MinHEnqueue(heap, 12);
    MinHEnqueue(heap, 19);
    MinHEnqueue(heap, 17);
    MinHEnqueue(heap, 14);
    PrintHeap(heap);

    printf("\nmin value is = %d\n", MinHDequeue(heap));
    PrintHeap(heap);

    free(heap);
    return(0);
}