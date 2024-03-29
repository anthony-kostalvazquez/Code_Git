#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

//takes two array indexes and the array and swaps the values
void ArraySwap(int *array, int in1, int in2)
{
    int tmp = array[in1];
    array[in1] = array[in2];
    array[in2] = tmp;
}

//prints arrays (look inside for the different formats)
//Format = 0 prints line by line
//Format = 1 prints with commas
//Format = 2 prints line by line with indexes
void PrintIntArray(int *ptr, int format, int size)
{
    for (int i = 0; i < size; i++)
    {
        if(format == 0)
        {
            printf("%d \n", ptr[i]);
        }
        else if(format == 1)
        {
            printf("%d ,", ptr[i]);
            if (i == (size - 1))
            {
                printf("\n");
            }
            
        }
        else if(format == 2)
        {
            printf("[%d] = %d \n", i, ptr[i]);
        }

    }
}

//initializes an array with random ints if IsUnique == True you will get a list with no duplicates
int *InitRandIntArray(int size, int IntRangeMax, bool IsUnique)
{
    //sets the time as the random seed
    srand(time(NULL));

    //allocates the mem based on size
    int *OutArr = malloc(sizeof(int) * (size + 1));

    if(!IsUnique)
    {
        for (int i = 0; i < size; i++)
        {
            OutArr[i] = rand() % IntRangeMax;
        }
    }
    //this is the Knuth Algorithm (Will be in ascending order)
    else
    {
        int in, im;
        im = 0;

        for (in = 0; in < IntRangeMax && im < size; ++in) {
            int rn = IntRangeMax - in;
            int rm = size - im;
            if (rand() % rn < rm)    
                OutArr[im++] = in;
        }
    }

    return(OutArr);
}