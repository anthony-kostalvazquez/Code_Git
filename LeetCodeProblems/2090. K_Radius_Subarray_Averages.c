#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* First Try
int* getAverages(int* nums, int numsSize, int k, int* returnSize)
{
    *returnSize = numsSize;
    int *RadiusAverage = (int *)malloc(sizeof(int*) * numsSize);
    int left, right, sum;



    for (int i = 0; i < numsSize; i++)
    {
        left = i - k;
        right = i + k;
        if(left < 0 || right >= numsSize)
        {
            RadiusAverage[i] = -1;
        }
        else
        {
            sum = 0;
            for (int j = left; j <= right; j++)
            {
                sum += nums[j];
            }
            RadiusAverage[i] = sum / (2*k + 1);
        }
    }

    return(RadiusAverage);
}
*/
int* getAverages(int* nums, int numsSize, int k, int* returnSize)
{
    int *RadiusAverage = (int *)malloc(sizeof(int*) * numsSize);
    int window = 2*k + 1;
    long int sum = 0;


    for (int i = 0; i < numsSize; i++)
    {
        sum += nums[i];
        RadiusAverage[i] = -1;
        if(i + 1 >= window)
        {
            RadiusAverage[i - k] = sum / window;
            sum -= nums[(i + 1) - window];
        }
    }


    *returnSize = numsSize;
    return(RadiusAverage);
}


int main()
{
    int nums[9] = {7,4,3,9,1,8,5,2,6};
    int numsize = 9;
    int k = 3;
    int returnsize;

    int *tmp = getAverages(nums, numsize, k, &returnsize);

    for (int i = 0; i < numsize; i++)
    {
        printf("%d, ", tmp[i]);
    }
    




    return 0;
}