#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//#include "Arrays.h"


//BUBBLE Sorts the given array
//O(n^2)
void BubbleSort(int *array, int size)
{
    //printf("Staring array\n");
    //PrintIntArray(array, 1);
    int temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j+i+1 < size; j++)
        {
            if(array[j] > array[j+1])
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
        //printf("\nWorking array");
        //PrintIntArray(array, 1);

    }
    //printf("Final array\n");
    //PrintIntArray(array, 2);
}

//Partition function for quick sort
int Partition(int *list, int low, int high)
{
    //choosing the pivot to be the last element
    int pivot = list[high];

    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if(list[j] < pivot)
        {
            i++;
            ArraySwap(list,i ,j );
        }
    }
    ArraySwap(list,high ,i+1);
    return(i+1);
}

//sorts a given array in O(nlog(n)) time
void QuickSort(int *List, int low, int high)
{
    if(low < high)
    {
        int p = Partition(List, low, high);

        QuickSort(List, low, p - 1);
        QuickSort(List, p+1, high);
    }
}

