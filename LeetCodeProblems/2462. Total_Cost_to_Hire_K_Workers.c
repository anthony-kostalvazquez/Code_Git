#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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


//takes an array and an index and pops it out and moves all of the other elements to the left
//NOTE: THE SIZE OF THE ARRAY DECREASES BY 1!!!!!!
int ArrayPop(int *array, int index, int size)
{
    int poped_int = array[index];

    for (int i = index; i < size - 1 ; i++)
    {
        array[i] = array[i + 1];
    }
    

    return poped_int;
}

//want to hire k workers
long long totalCost(int* costs, int costsSize, int k, int candidates)
{
    long long T_Cost = 0;
    int hired = 0;
    int Cheapest = 0;

    //DEBUG//
    printf("hired = %d, total cost = %lld, cheapest = %d, size = %d, array = ",hired,T_Cost,Cheapest,costsSize);
    PrintIntArray(costs, 1, costsSize);

    while (hired < k)
    {
        Cheapest = 0;
        for (int i = 0; i < candidates && i < costsSize; i++)
        {
            printf("costs[i] = %d, costs[size - i] = %d, cost[cheapest] = %d, cheapest = %d\n",costs[i],costs[costsSize - i],costs[Cheapest],Cheapest);
            if (costs[i] < costs[Cheapest])
            {
                Cheapest = i;
            }
            if(costsSize < candidates)
            {
                if (costs[(costsSize - 1) - i] < costs[Cheapest])
                {
                    Cheapest = (costsSize - 1) - i;
                }
            }
        }
        T_Cost += ArrayPop(costs, Cheapest, costsSize);
        costsSize --;
        hired++;

        //DEBUG//
        printf("hired = %d, total cost = %lld, cheapest = %d, size = %d, array = ",hired,T_Cost,Cheapest,costsSize);
        PrintIntArray(costs, 1, costsSize);
        
    }
    
    




    return T_Cost;
}


int main()
{
    int cost[4] = {1,2,4,1};
    int cost_size = 4;
    int k = 3;
    int candidates = 3;


    printf("the output is %lld \n", totalCost(cost, cost_size, k, candidates));


    return 0;
}