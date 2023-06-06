#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "../AnthonysCLib/HashTable.h"

#define TABLE_SIZE 9937

int main()
{
    NODE_T **table = CreateHashTable(TABLE_SIZE);
    assert(table[2] == NULL);
    

    printf("10 => %d\n", hash(10, TABLE_SIZE) );
    printf("100 => %d\n", hash(100, TABLE_SIZE));
    printf("105 => %d\n", hash(105, TABLE_SIZE));
    printf("103 => %d\n", hash(103, TABLE_SIZE));
    printf("1010 => %d\n", hash(1010, TABLE_SIZE));

    add(10, table, TABLE_SIZE);

    add(10, table, TABLE_SIZE);
    add(100, table, TABLE_SIZE);
    add(105, table, TABLE_SIZE);
    add(103, table, TABLE_SIZE);
    add(1010, table, TABLE_SIZE);

    NODE_T *tmp = NULL;
    PrintHashTable(table, TABLE_SIZE);
    tmp = HashSearch(105, table, TABLE_SIZE);
    printf("our return now has val of = %d\n", tmp->value);
    tmp->value = 22;



    PrintHashTable(table, TABLE_SIZE);
    DeleteHashTable(table, TABLE_SIZE);
    return 0;
}

