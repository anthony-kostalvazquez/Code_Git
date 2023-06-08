#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void ArraySwap(int *array, int in1, int in2)
{
    int tmp = array[in1];
    array[in1] = array[in2];
    array[in2] = tmp;
}

//Partition function for quick sort
int Partition(int *list, int low, int high)
{
    //choosing the pivot to be the last element
    int pivot = list[high];

    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if(list[j] < pivot)
        {
            i++;
            ArraySwap(list,i ,j );
        }
    }
    ArraySwap(list,high ,i+1);
    return(i+1);
}

//sorts a given array in O(nlog(n)) time
void QuickSort(int *List, int low, int high)
{
    if(low < high)
    {
        int p = Partition(List, low, high);

        QuickSort(List, low, p - 1);
        QuickSort(List, p+1, high);
    }
}

bool canMakeArithmeticProgression(int* arr, int arrSize)
{
    printf("starting array\n");
    PrintIntArray(arr, 1, arrSize);

    //first i sort the array using quick sort (code above) this is a very standard alg sometimes built into languages
    QuickSort(arr, 0, arrSize-1);

    printf("After sort\n");
    PrintIntArray(arr, 1, arrSize);

    //find the common difference
    int CommonDiff = arr[1] - arr[0];

    //iterate through the list and ensure that every successive term is a common difference away
    //note it also wont enter this loop if its empty or of size 1
    for (int i = 1; i < arrSize; i++)
    {
        printf("%d \n", arr[i] - arr[i-1]);
        if(arr[i] - arr[i-1] != CommonDiff)
        {
            return false;
        }
    }
    
    //if it makes it through the loop without returning false return true
    return true;
}





int main()
{
    int arr[] = {3,5,1};
    
    printf("%d", canMakeArithmeticProgression(arr,3));



}