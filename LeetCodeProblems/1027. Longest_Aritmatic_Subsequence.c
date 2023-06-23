#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

//We want to choose a prime here that is larger than 2xmaxlength (2000)
#define TABLE_SIZE 2053

struct KeyValuePair
{
    int key;
    int value;
};


int hash(int x) 
{
    x = ((x >> 16) ^ x) * 0x45d9f3b; // >> is unsigned right shift
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;

    return(abs(x) % TABLE_SIZE);
}

//adds a value to the hash map
void add(int item, int*array)
{
    int i = hash(item);
    array[i]++;
}




int longestArithSeqLength(int* nums, int numsSize)
{
    int record = 1;

    //here we initalize an array of hashmaps (one for every element in nums)
    int **HashList = malloc(sizeof(int *) * numsSize);
    for (int i = 0; i < numsSize; i++)
    {
        HashList[i] = calloc(sizeof(int ) * numsSize, sizeof(int ));
    }

    add(10, HashList[0]);

    for (int j = 0; j < numsSize; j++)
    {
        if(HashList[0] != 0)
        {
            printf("%d, %d" j, );
        }
    }
    

    


    return(record + 1);
}


int main()
{
    int arr[] = {3,6,9,12};
    
    printf("%d", longestArithSeqLength(arr, 4));



}