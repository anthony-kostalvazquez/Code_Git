#define NDEBUG

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <assert.h>

#include "../AnthonysCLib/Sort.h"
//#include "../AnthonysCLib/Arrays.h"

int main()
{
    int arr[] = {9,7,5,4,10,6,1,3,8,2};
    PrintIntArray(arr, 1, 10);

    QuickSort(arr, 0, 9);

    PrintIntArray(arr, 1, 10);


}