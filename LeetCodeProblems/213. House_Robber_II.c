#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//takes two ints and returns the max
int max(int i, int j)
{
    if(i <= j)
    {
        return(j);
    }

    return(i);
}

//original alg from house robber I
int rob1(int* nums, int numsSize, int start, int end)
{
    int Profit_1 = 0;
    int Profit_2 = 0;
    int CurrentProfit = 0;

    for(int i = start; i < end; i++)
    {
        printf("i = %d, p1 = %d, p2 = %d, currp = %d \n",i,Profit_1,Profit_2,CurrentProfit);

        CurrentProfit = max((Profit_1 + nums[i]), Profit_2);

        Profit_1 = Profit_2;
        Profit_2 = CurrentProfit;
    }



    return(CurrentProfit);
}

int robII(int* nums, int numsSize)
{
    if(numsSize == 1)
    {
        return(nums[0]);
    }

    return(max( rob1(nums, numsSize, 0, numsSize-1) , rob1(nums, numsSize, 1, numsSize) ) );
}


int main()
{
    int nums[] = {2,7,9,3,1};

    printf("%d \n", rob(nums, 5));

    return 0;
}