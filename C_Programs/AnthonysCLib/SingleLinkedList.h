#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Single_Linked_List_Node
{
    int value;
    struct Single_Linked_List_Node* next;
};
typedef struct Single_Linked_List_Node SLL_T;

//prints out the entire linked list given the head
void printlist(SLL_T *head)
{
    SLL_T *temp = head;

    while (temp != NULL)
    {
        printf("%d -", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

//creates a new node and puts the value in it and returns a pointer to it
SLL_T *create_new_node(int value)
{
    SLL_T *result = malloc(sizeof(SLL_T));
    result->value = value;
    result->next = NULL;
    return result;
}

//takes linked list and returns the length of it
int LengthList(struct SLL_T* head)
{
    int length = 0;
    for (SLL_T *i = head; i != NULL; i = i->next)
    {
        length++;
    }

    return(length);
}

//takes a linked list and an int and returns the node at that integer
SLL_T* ReturnIndex(SLL_T* head, int indx)
{
    SLL_T* tmp = head;

    for (int i = 0; i < indx; i++)
    {
        tmp = tmp->next;
    }

    return(tmp);
}

//returns the middle node of a linked list
SLL_T* middleNode(SLL_T* head)
{
    int length = LengthList(head);
    int middle = ceil(length / 2);
    return(ReturnIndex(head, middle));
}

//inserts a node at the head of a list
//updates head pointer to itself
//returns a pointer to 
SLL_T *insert_at_head(SLL_T **head, SLL_T *SLL_To_insert)
{
    SLL_To_insert->next = *head;
    *head = SLL_To_insert;
    return SLL_To_insert;
}

//finds a node and returns its position if its not in the list it will return null
SLL_T *find_node(SLL_T *head, int value)
{
    SLL_T *tmp = head;
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

//inserts a new node after the specified node
SLL_T *insert_after_node(SLL_T *SLL_To_insert_after, SLL_T* new_node)
{
    new_node->next = SLL_To_insert_after->next;
    SLL_To_insert_after->next = new_node;
}

//Deletes a linked list given the head
void DeleteList(SLL_T **head)
{
    SLL_T *tmp = (*head)->next;
    while(tmp != NULL)
    {
        free(*head);
        *head = tmp;
        tmp = tmp->next;
    }
    free(*head);
}