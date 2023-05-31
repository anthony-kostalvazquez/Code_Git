#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Double_Linked_Stack_Node
{
    int value;
    struct Double_Linked_Stack_Node *next;
    struct Double_Linked_Stack_Node *prev;
};

typedef struct Double_Linked_Stack_Node DLSNODE_T;

//prints out the whole stack
void printStack(DLSNODE_T *top)
{
    DLSNODE_T *tmp = top;

    printf("TOP--> ");
    while(tmp != NULL)
    {
        printf("%d", tmp->value);
        if(tmp->next != NULL)
        {
            printf(", ");
        }
        tmp = tmp->next;
    }
    printf("\n");
}

//creates a new node in a stack
DLSNODE_T *create_new_node(int value)
{
    DLSNODE_T *result = (DLSNODE_T *) malloc(sizeof( DLSNODE_T ));
    result->value = value;
    result->next = NULL;
    result->prev = NULL;
    return result;
}

//answers the questions is the stack empty with a bool
bool isEmpty(DLSNODE_T *top)
{
    if(top == NULL)
    {
        return(true);
    }
    else
    {
        return(false);
    }
}

//answers the questions is the stack full with a bool
bool isFull(DLSNODE_T *top)
{
    return(false);
}

//If the stack is not full it adds an element to the top
//Updates the top element
void push(DLSNODE_T **top, int value_to_insert)
{
    DLSNODE_T *temp = *top;

    //makes new node with the value
    DLSNODE_T *node_to_insert = create_new_node(value_to_insert);

    //points new node to the old top
    node_to_insert->next = temp;
    node_to_insert->prev = NULL;

    //points the previous tops prev to the new one and makes sure its not the first one in the stack
    if ((*top) != NULL)
    {
        (*top)->prev = node_to_insert;
    }

    //updates top node
    *top = node_to_insert;
}

//Removes the item from the top of the stack and returns the value it stored
//updates the stack top
int pop(DLSNODE_T **top)
{
    if((!(isEmpty(*top))) && ((*top)->next == NULL))
    {
        DLSNODE_T *tmp = *top;

        int return_int = tmp->value;
        *top = (*top)->next;

        free(tmp);
        return(return_int);
    }
    else if( !(isEmpty(*top)))
    {
        DLSNODE_T *tmp = *top;

        int return_int = tmp->value;

        *top = (*top)->next;
        (*top)->prev = NULL;

        free(tmp);
        return(return_int);
    }
    else
    {
        printf("UNDERFLOW in pop- Cannot remove from an empty stack\n");
    }
}

//prints out the top value if the list is not empty
int peek(DLSNODE_T *top)
{
    if( !(isEmpty(top)))
    {
        return(top->value);
    }
    else
    {
        printf("UNDERFLOW in peek- Cannot Peek at an empty stack");
    }
}