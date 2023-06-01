#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//BUBBLE Sorts the given array
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