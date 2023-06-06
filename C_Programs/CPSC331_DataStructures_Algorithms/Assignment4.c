#define NDEBUG

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <assert.h>

#include "../AnthonysCLib/Arrays.h"
#include "../AnthonysCLib/Search.h"
#include "../AnthonysCLib/Sort.h"
#include "../AnthonysCLib/HashTable.h"

#define TABLE_SIZE 9937

int main()
{
    //Starts the print off
    printf("Size\tSequential Search Time\tBinary Search time\tHash Search Time\n");


    //initalizes the variables to time the various searches
    clock_t start, end;
    double cpu_time_used;
    int tmpss = 0;
    int tmpbs = 0;


    //You will generate 99 distinct random numbers between 0 and 5000 and store them in an array of size 100. Add 5001 as the 100th cell in the array.
    int E_size = 100;
    int *ElementsArray = InitRandIntArray(E_size, 5000, true);
    ElementsArray[99] = 5001;


    //creates random search arrays of size 1,000 - 1,000,000 
    for (int S_size = 1000; S_size <= 1000000; S_size = S_size + 1000)
    {
        
        //generate an array of integers called the search array. This is the array to be searched. the values in the array are from 0 to 5000.
        int *SearchArray = InitRandIntArray(S_size, 5000, false);
    

        //resets the times to 0
        double SeqTime = 0;
        double BinTime = 0;
        double HashTime = 0;

        //--------------------SEQUENTIAL SEARCH--------------------//
        for (int i = 0; i < E_size; i++)
        {
            start = clock();
            tmpss = SequentialSearch(ElementsArray[i], SearchArray, S_size);
            end = clock();

            SeqTime += ((double) (end - start)) / CLOCKS_PER_SEC;
    
            assert(tmpss == -1 || SearchArray[tmpss] == ElementsArray[i]);
        }

        //--------------------HASH SEARCH--------------------//
        start = clock();
        NODE_T **SearchHashTable = HashTabFromArray(SearchArray, TABLE_SIZE, S_size);
        end = clock();
        printf("Hash table creation took %f\n", ((double) (end - start)) / CLOCKS_PER_SEC);
        //PrintHashTable(table, TABLE_SIZE);
        NODE_T *tmphs = NULL;

        for (int i = 0; i < E_size; i++)
        {
            start = clock();
            tmphs = HashSearch(ElementsArray[i], SearchHashTable, TABLE_SIZE);
            end = clock();

            HashTime += ((double) (end - start)) / CLOCKS_PER_SEC;


            assert(tmphs == NULL || tmphs->value == ElementsArray[i]);
        }

        //--------------------BINARY SEARCH--------------------//
        //sorting the search array
        start = clock();
        BubbleSort(SearchArray, S_size);
        end = clock();
        printf("Bubble sort took %f\n", ((double) (end - start)) / CLOCKS_PER_SEC);
        for (int i = 0; i < E_size; i++)
        {
            start = clock();
            tmpbs = BinarySearch(ElementsArray[i], SearchArray, 0, S_size);
            end = clock();
            
            BinTime += ((double) (end - start)) / CLOCKS_PER_SEC;
            assert(tmpbs == -1 || SearchArray[tmpbs] == ElementsArray[i]);
        }

        printf("%d\t%f\t%f\t%f\n",S_size, SeqTime, BinTime, HashTime);
        
        //frees the memory of the search array and hash table
        free(SearchArray);
        DeleteHashTable(SearchHashTable, TABLE_SIZE);
    }

    

    free(ElementsArray);
    return 0;
}