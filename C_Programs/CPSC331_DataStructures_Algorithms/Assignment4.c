#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <assert.h>

#include "../AnthonysCLib/Arrays.h"
#include "../AnthonysCLib/Search.h"
#include "../AnthonysCLib/Sort.h"

//#define NDEBUG



int main()
{
    //initalizes the variables to time the various searches
    clock_t start, end;
    double cpu_time_used;


    //You will generate 99 distinct random numbers between 0 and 5000 and store them in an array of size 100. Add 5001 as the 100th cell in the array.
    int E_size = 100;
    int *ElementsArray = InitRandIntArray(E_size, 5000, true);
    ElementsArray[99] = 5001;

    //creates random search arrays of size 1,000 - 1,000,000 
    for (int S_size = 5000; S_size <= 5005; S_size++)
    {
        
        //generate an array of integers called the search array. This is the array to be searched. the values in the array are from 0 to 5000.
        int *SearchArray = InitRandIntArray(S_size, 5000, false);

        //resets the times to 0
        double SeqTime = 0;
        double BinTime = 0;
        double HashTime = 0;
        int tmp = 0;

        //searches the search array for the elements in the elements array
        for (int i = 0; i < E_size; i++)
        {
            //--------------------SEQUENTIAL SEARCH--------------------//
            start = clock();
            int tmp1 = SequentialSearch(ElementsArray[i], SearchArray, S_size);
            end = clock();

            SeqTime += ((double) (end - start)) / CLOCKS_PER_SEC;
            //assert(tmp == -1 || SearchArray[tmp] == ElementsArray[i]);
            //--------------------HASH SEARCH--------------------//



            //--------------------BINARY SEARCH--------------------//
            BubbleSort(SearchArray, S_size);
            start = clock();
            tmp = BinarySearch(ElementsArray[i], SearchArray, 0, S_size);
            end = clock();
            
            BinTime += ((double) (end - start)) / CLOCKS_PER_SEC;
            //assert(tmp == -1 || SearchArray[tmp] == ElementsArray[i]);
        }
    
        printf("for array of size %d Sequential search took %fs\n", S_size, SeqTime);
        printf("for array of size %d Binary search took %fs\n", S_size, BinTime);
    
        //frees the memory of the search array
        free(SearchArray);
    }

    

    free(ElementsArray);
    return 0;
}