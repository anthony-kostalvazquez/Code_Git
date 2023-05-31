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
    //initalizes the variables i need to time the various searches
    clock_t start, end;
    double cpu_time_used;

    //You will generate 99 distinct random numbers between 0 and 5000 and store them in an array of size 100. Add 5001 as the 100th cell in the array.
    int E_size = 100;
    int *ElementsArray;
    ElementsArray = InitRandIntArray(E_size, 5000, true);
    ElementsArray[99] = 5001;

    //generate an array of integers called the search array. This is the array to be searched. The array size n is between 1000 and 1,000,000 and the values in the array are from 0 to 5000. 
    int S_size = (rand() % (1000000 - 1000) + 1000);
    int *SearchArray;
    SearchArray = InitRandIntArray(S_size, 5000, false);

    //SEARCHES
    for (int S_size = 1000; i < count; i++)
    {
        /* code */
    }
    

    //----------SEQUENTIAL SEARCH----------//
    start = clock();
    //searches the search array for the elements in the elements array
    for (int i = 0; ElementsArray[i] != '\0'; i++)
    {
        int tmp = SequentialSearch(ElementsArray[i], SearchArray);
        
        assert(SearchArray[tmp] == ElementsArray[i] || tmp == -1);
    }
    end = clock();

    //printing off the time taken
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("The sequential search took %f seconds to execute\n", cpu_time_used);


    //----------BINARY SEARCH----------//
    BubbleSort(SearchArray);

    start = clock();
    //searches the search array for the elements in the elements array
    for (int i = 0; ElementsArray[i] != '\0'; i++)
    {
        int tmp = BinarySearch(ElementsArray[i], SearchArray, 0, S_size);

        assert(SearchArray[tmp] == ElementsArray[i] || tmp == -1);
    }
    end = clock();

    //printing off the time taken
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("The sequential search took %f seconds to execute\n", cpu_time_used);

    /*
    for (int i = 0; i < 10000; i++)
    {
        int randnum = rand() % 5000;
        printf("the index of %d is %d\n", i, SequentialSearch(i, ElementsArray));
    }

    for (int i = 0; ElementsArray[i] != '\0'; i++)
    {
        int tmp = SequentialSearch(ElementsArray[i], SearchArray);
        printf("the index of %d is %d\nPROOF E_ARR[%d] = %d & S_ARR[%d] = %d\n",ElementsArray[i], tmp, i, ElementsArray[i], tmp, SearchArray[tmp]);
    }

    PrintIntArray(ElementsArray, 2);

    */

   








    return 0;
}