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

int rob(int* nums, int numsSize)
{
    int Profit_1 = 0;
    int Profit_2 = 0;
    int CurrentProfit = 0;

    for(int i = 0; i < numsSize; i++)
    {
        printf("i = %d, p1 = %d, p2 = %d, currp = %d \n",i,Profit_1,Profit_2,CurrentProfit);

        CurrentProfit = max((Profit_1 + nums[i]), Profit_2);

        Profit_1 = Profit_2;
        Profit_2 = CurrentProfit;
    }

    return(CurrentProfit);
}




int main()
{
    int nums[] = {1};

    printf("%d \n", rob(nums, 1));

    return 0;
}