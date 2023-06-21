#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))


int FindMax(int *array, int length)
{
    int max = array[0];
    for (int i = 0; i < length; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
        
    }
    
    return max;
}

int FindMin(int *array, int length)
{
    int min = array[0];
    for (int i = 0; i < length; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
        
    }
    
    return min;
}

long long TotalCost(int* nums, int* cost, int size, int ChangeTo)
{
    long long TotalCost = 0;
    for (int j = 0; j < size; j++)
    {
        TotalCost += (long long)abs( nums[j] - ChangeTo) * (long long)cost[j];
    }


    return(TotalCost);
}

long long minCost(int* nums, int numsSize, int* cost, int costSize)
{
    int mid;
    int low = FindMin(nums, numsSize) - 1;
    int high = FindMax(nums, numsSize) + 1;

    while(high - low > 1)
    {
        mid = (low + high) / 2;
        printf("mid = %d, cost(mid) = %lld, cost mid+1 = %lld\n", mid,TotalCost(nums, cost, numsSize, mid),TotalCost(nums, cost, numsSize, mid + 1));

        if (TotalCost(nums, cost, numsSize, mid) <= TotalCost(nums, cost, numsSize, mid + 1))
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }

    



    return(MIN(TotalCost(nums, cost, numsSize, low), TotalCost(nums, cost, numsSize, high)));
}



int main()
{
    int nums[14] = {576257,268115,512826,523563,927189,39253,720661,35147,552624,847824,354489,760949,734966,571013};
    int cost[14] = {842872,273313,503060,139143,367612,217125,271272,407727,199063,120280,819193,935689,624116,453146};
    int cost_size = 14;
    int nums_size = 14;


    printf("the output is %lld \n", minCost(nums, nums_size, cost, cost_size));


    return 0;
}