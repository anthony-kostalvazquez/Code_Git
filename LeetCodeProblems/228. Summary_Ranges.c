#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>


char **summaryRanges(int* nums, int numsSize, int* returnSize)
{
    int SeqCount = 0;
    char **ReturnArr = (char**)malloc(numsSize * sizeof(char*));

    int loopcount = 0;
    int stlen = ((log10(INT_MAX) + 2) * 2) + 3;



    for (int i = 0; i < numsSize; i++)
    {
        SeqCount = 0;
        printf("i = %d\n", i);
        //sees how long the undisturbed sequential list is
        while(i < numsSize-1 && nums[i] + 1 == nums[i + 1])
        {
            SeqCount++;
            i++;
        }

        if(SeqCount == 0)
        {
            ReturnArr[loopcount] = (char*)malloc( sizeof(char *) * stlen);

            sprintf(ReturnArr[loopcount], "%d", nums[i]);
        }
        else
        {
            ReturnArr[loopcount] = (char*)malloc( sizeof(char *) * stlen);

            sprintf(ReturnArr[loopcount], "%d->%d",nums[i - SeqCount], nums[i]);
        }



        loopcount++;
  
        
    }

    *returnSize = loopcount;

    return(ReturnArr);
}

int main()
{
    int input[] = {0,2,3,4,6,8,9};
    int NumSize = 6;
    int retnumsize = 0;


    char **ReturnArr = summaryRanges(input, NumSize, &retnumsize);

    for (int i = 0; i < retnumsize; i++)
    {
        printf("%s, ", ReturnArr[i]);
    }
    
    

    



    return(0);
}

