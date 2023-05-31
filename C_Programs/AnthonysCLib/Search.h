#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//takes an array and a value and searches for it sequentially then returns the index or -1 if it is not contained
int SequentialSearch(int val, int* array)
{
    for (int i = 0; array[i] != '\0'; i++)
    {
        if(array[i] == val)
        {
            return(i);
        }
    }

    return(-1);
}