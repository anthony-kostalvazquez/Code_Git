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

//finds a node 
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
    NODE_T *tmp = (*head)->next;
    while(tmp != NULL)
    {
        free(*head);
        *head = tmp;
        tmp = tmp->next;
    }
    free(*head);
}

//======================================================HASH IMPLEMENTATION======================================================//

//Change the parameters here
#define TABLE_SIZE 9973
int hash(int x) 
{
    x = ((x >> 16) ^ x) * 0x45d9f3b; // >> is unsigned right shift
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;

    return(abs(x) % TABLE_SIZE);
}

struct Hash_table
{
    //table of linked list heads
    NODE_T *head_array[TABLE_SIZE];
};
typedef struct Hash_table HASH_T;


void clear(HASH_T *table)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        DeleteList(&((table->head_array)[i]));
    }
}

void add(int item, HASH_T* table)
{
    int i = hash(item);

    insert_at_head()
}
//remove(T item);
//contains(T item);


