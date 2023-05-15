/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    *returnSize = 2;
    int* output_ptr;
    output_ptr = (int*)malloc(*returnSize);

    for (int i = 0; i < numsSize; i++)
    {

        for (int j = i+1; j < numsSize; j++)
        {
            if(   (*(nums + i) + *(nums + j)) == target  )
            {
                output_ptr[0] = i;
                output_ptr[1] = j;
                

                return(output_ptr);
            }
        }
    }
}


int main()
{
    int returnSize;
    int nums[] = {3,3};
    int target = 6;

    int *output_ptr = twoSum(nums, sizeof(nums) / sizeof(nums[0]),target , &returnSize);


    for (int i = 0; i < 2; i++)
    {
        printf("%d \n", output_ptr[i]);
    }
    printf("%d", returnSize);

    return(0);
}