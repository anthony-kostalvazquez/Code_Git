#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

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


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int TotalSize = nums1Size + nums2Size;
    int MergeLimit = ceil(TotalSize / 2);
    int MergeList[TotalSize];

    int i = 0;
    int j = 0;

    //int Val1 = 0;
    //int Val2 = 0;
    
    while(i + j < MergeLimit)
    {
        while(i < nums1Size && j < nums2Size && nums1[i] <= nums2[j])
        {
            MergeList[i + j] = nums1[i];
            printf("adding %d, i = %d\n", nums1[i], i);
            i++;
        }
        if(j < nums2Size)
        {
            MergeList[i + j] = nums2[j];
            printf("adding %d\n", nums2[j]);
            j++;
        }

        while(i < nums1Size && j < nums2Size && nums1[i] >= nums2[j])
        {
            MergeList[i + j] = nums2[j];
            printf("adding %d, i = %d\n", nums2[j], j);
            j++;
        }
        if(i < nums1Size)
        {
            MergeList[i + j] = nums1[i];
            printf("adding %d\n", nums1[i]);
            i++;
        }
    }

    PrintIntArray(MergeList, 1, TotalSize);
    
    if (TotalSize % 2 != 0)
    {
        return MergeList[MergeLimit];
    }
    else
    {
        return (MergeList[MergeLimit] + MergeList[MergeLimit - 1]) / 2.0;
    }

}


int main()
{
    int nums1[2] = {1,2};
    int nums1Size = 2;
    int nums2[2] = {3,4};
    int nums2Size = 2;

    printf("output is %f", findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size));



    return 0;
}