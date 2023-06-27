#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void PrintMatrix(int **matrix, int RowSize, int ColSize)
{
    for (int row = 0; row < RowSize; row++)
    {
        for (int col = 0; col < ColSize; col++)
        {
            printf("%d ", matrix[row][col]);
        }
        printf("\n");

    }
    
}

int ColumnSum(int *column, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += column[i];
    }
    
    return sum;
}

void sink(int **matrix, int column, int size)
{
    if (size != 1)
    {
        int tmp0, tmp1;
        for (int i = column; i < size - 1; i++)
        {
            if (ColumnSum(matrix[i], 2) < ColumnSum(matrix[i+1], 2) )
            {
                //swap the position
                tmp0 = matrix[i][0];
                tmp1 = matrix[i][1];

                matrix[i][0] = matrix[i + 1][0];
                matrix[i][1] = matrix[i + 1][1];

                matrix[i + 1][0] = tmp0;
                matrix[i + 1][1] = tmp1;
            }
            else
            {
                return;
            }
            
        }
    }
    

}

void rise(int **matrix, int size)
{
    if (size != 1)
    {
        int tmp0, tmp1;
        for (int i = size - 1; i >= 1; i--)
        {
            if (ColumnSum(matrix[i], 2) > ColumnSum(matrix[i-1], 2) )
            {
                //swap the position
                tmp0 = matrix[i][0];
                tmp1 = matrix[i][1];

                matrix[i][0] = matrix[i - 1][0];
                matrix[i][1] = matrix[i - 1][1];

                matrix[i - 1][0] = tmp0;
                matrix[i - 1][1] = tmp1;
            }
            else
            {
                return;
            }
                
        }
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** kSmallestPairs(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize, int** returnColumnSizes)
{
    int **SmallestPairsMaxHeap = (int **)malloc(sizeof(int *) * k);
    *returnColumnSizes = (int *)malloc(sizeof (int) * k);

    int HeapSize = 0;
    for (int n = 0; n < k; n++)
    {
        (*returnColumnSizes)[n] = 2;
        SmallestPairsMaxHeap[n] = (int *)malloc(sizeof(int *) * 2);
    }


    for (int nums1_index = 0; nums1_index < nums1Size; nums1_index++)
    {
        printf("compairing to %d\n", nums1[nums1_index]);
        //while the current pair is still less than the max of the smallest pair heap
        for (int nums2_index = 0; nums2_index < nums2Size; nums2_index++)
        {
            if(HeapSize != k)
            {
                SmallestPairsMaxHeap[HeapSize][0] = nums1[nums1_index];
                SmallestPairsMaxHeap[HeapSize][1] = nums2[nums2_index];

                HeapSize++;
                printf("size = %d\n", HeapSize);
                rise(SmallestPairsMaxHeap, HeapSize);

                PrintMatrix(SmallestPairsMaxHeap, HeapSize, 2);
            }
            else if(ColumnSum(SmallestPairsMaxHeap[0], 2) > nums1[nums1_index] + nums2[nums2_index])
            {
                //replace the max with the new pair
                SmallestPairsMaxHeap[0][0] = nums1[nums1_index];
                SmallestPairsMaxHeap[0][1] = nums2[nums2_index];

                sink(SmallestPairsMaxHeap, 0, HeapSize);
                printf("sinking\n");
                PrintMatrix(SmallestPairsMaxHeap, HeapSize, 2);
            }
            else
            {
                break;
            }
            

        }

    }
    
    *returnSize = HeapSize;
    PrintMatrix(SmallestPairsMaxHeap, *returnSize, 2);
    return(SmallestPairsMaxHeap);
}


int main()
{
    int nums1[3] = {1,1,2};
    int nums1Size = 3;

    int nums2[3] = {1,2,3};
    int nums2Size = 3;

    int k = 2;
    int retSize;
    int* returnColumnSizes;

    kSmallestPairs(nums1, nums1Size, nums2, nums2Size, k, &retSize, &returnColumnSizes);



    return 0;
}