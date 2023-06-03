#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "../AnthonysCLib/HashTable.h"



int main()
{
    HASH_T* table = NULL;

    for (int i = 0; i < 1000; i++)
    {
        
    }
    

    printf("10 => %d\n", hash(10));
    printf("100 => %d\n", hash(100));
    printf("105 => %d\n", hash(105));
    printf("103 => %d\n", hash(103));
    printf("1010 => %d\n", hash(1010));

    return 0;
}

