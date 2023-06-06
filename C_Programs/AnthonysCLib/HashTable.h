#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>


//======================================================Linked List IMPLEMENTATION======================================================//
struct Linked_List_Node
{
    int value;
    struct Linked_List_Node* next;
};
typedef struct Linked_List_Node NODE_T;

//prints out the entire linked list given the head
void printlist(NODE_T *head)
{
    NODE_T *temp = head;
    printf("head -> ");

    while (temp != NULL)
    {
        printf("%d", temp->value);
        temp = temp->next;
        if(temp != NULL)
        {
            printf("->");
        }
    }
    printf("\n");
}

//creates a new node and puts the value in it and returns a pointer to it
NODE_T *create_new_node(int value)
{
    NODE_T *result = malloc(sizeof(NODE_T));
    result->value = value;
    result->next = NULL;
    return result;
}

//inserts a node at the head of a list
//updates head pointer to itself
//returns a pointer to 
NODE_T *insert_at_head(NODE_T **head, NODE_T *NODE_To_insert)
{
    NODE_To_insert->next = *head;
    *head = NODE_To_insert;
    return NODE_To_insert;
}

//finds a node and returns its position if its not in the list it will return null
NODE_T *find_node(NODE_T *head, int value)
{
    NODE_T *tmp = head;
    while(tmp != NULL)
    {
        if (tmp->value == value)
        {
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}

//Deletes a linked list given the head
void DeleteList(NODE_T **head)
{   
    if(*head != NULL)
    {
        NODE_T *tmp = (*head)->next;
        while(tmp != NULL)
        {
            free(*head);
            *head = tmp;
            tmp = tmp->next;
        }
    }
    free(*head);
}

//======================================================HASH IMPLEMENTATION======================================================//

//Change the parameters here

int hash(int x, int size) 
{
    x = ((x >> 16) ^ x) * 0x45d9f3b; // >> is unsigned right shift
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;

    return(abs(x) % size);
}

//creates an array of *NODE_T and initalizes them to NULL
NODE_T **CreateHashTable(int size)
{
    NODE_T **OutArr = malloc(sizeof(NODE_T *)* size);
    NODE_T *tmp;

    for (int i = 0; i < size; i++)
    {
        //NODE_T *tmp = malloc(sizeof(NODE_T));
        NODE_T *tmp = NULL;
        OutArr[i] = tmp;
    }
    
    return(OutArr);
}

void DeleteHashTable(NODE_T **table, int size)
{
    for (int i = 0; i < size; i++)
    {
        DeleteList(&(table[i]));
    }
    free(table);
}

void add(int item, NODE_T **table, int size)
{
    int i = hash(item, size);

    NODE_T *tmp = create_new_node(item);
    insert_at_head(&table[i], tmp);
}

void PrintHashTable(NODE_T **table, int size)
{
    for (int i = 0; i < size; i++)
    {
        if(table[i] != NULL)
        {
            printf("Index(hash) = %d LIST: ", i);
            printlist(table[i]);
        }
    }
    
}

//takes an array and size and outputs a hash table with those values
NODE_T ** HashTabFromArray(int *array, int hash_size, int arr_size)
{
    NODE_T **table = CreateHashTable(hash_size);

    for (int i = 0; i < arr_size; i++)
    {
        add(array[i], table, hash_size);
    }
    return(table);
}

//searches the hash table for the value
//retuns a NULL node if it doesn't have it
//returns the node if it does have it
NODE_T *HashSearch(int item, NODE_T **table, int size)
{
    NODE_T *RetNode = NULL;
    int i = hash(item, size);

    if (table[i] != NULL)
    {
        RetNode = find_node(table[i], item);
        //printf("found at position %d\n", i);
    }


    return(RetNode);
}

/*
void remove(int item, NODE_T **table, int size)
{
    int i = hash(item, size);

    find_node()

}
*/


