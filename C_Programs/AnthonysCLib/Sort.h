#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Arrays.h"

//BUBBLE Sorts the given array
void BubbleSort(int *array)
{
    printf("Staring array\n");
    PrintIntArray(array, 1);
    int temp;
    for (int i = 0; array[i] != '\0'; i++)
    {
        for (int j = 0; array[j+i] != '\0'; j++)
        {
            if(array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        printf("Working array\n");
        PrintIntArray(array, 1);

    }
    printf("Final array\n");
    PrintIntArray(array, 2);
}