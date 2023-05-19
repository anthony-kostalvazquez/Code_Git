#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Linked_Stack_Node
{
    int value;
    struct Linked_Stack_Node *next;
};
typedef struct Linked_Stack_Node LSNODE_T;

void printStack(LSNODE_T *top)
{
    LSNODE_T *tmp = top;

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
LSNODE_T *create_new_node(int value)
{
    LSNODE_T *result = malloc(sizeof( LSNODE_T ));
    result->value = value;
    result->next = NULL;
    return result;
}

//answers the questions is the stack empty with a bool
bool isEmpty(LSNODE_T *top)
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
bool isFull(LSNODE_T *top)
{
    return(false);
}

//If the stack is not full it adds an element to the top
//Updates the top element
void push(LSNODE_T **top, int value_to_insert)
{
    LSNODE_T *node_to_insert = create_new_node(value_to_insert);
    node_to_insert->next = *top;
    *top = node_to_insert;
}

//Removes the item from the top of the stack and returns the value it stored
//updates the stack top
int pop(LSNODE_T **top)
{
    if( !(isEmpty(*top)))
    {
        LSNODE_T *tmp = *top;
        int return_int = tmp->value;
        *top = (*top)->next;
        free(tmp);
        return(return_int);
    }
    else
    {
        printf("UNDERFLOW in pop- Cannot remove from an empty stack\n");
    }
}

//prints out the top value if the list is not empty
int peek(LSNODE_T *top)
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