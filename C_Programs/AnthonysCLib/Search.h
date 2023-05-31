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

//array must be a sorted list
//recursive alg to search through a array for val and return the index
int BinarySearch(int val, int* array, int low, int high)
{
    if(low > high)
    {
        return(-1);
    }
    int mid = (low + high)/2;
    if(val == array[mid])
    {
        return mid;
    }
    else if(val < array[mid])
    {
        return BinarySearch(val, array, low, mid-1);
    }
    else
    {
        return BinarySearch(val, array, mid+1, high);
    }
}