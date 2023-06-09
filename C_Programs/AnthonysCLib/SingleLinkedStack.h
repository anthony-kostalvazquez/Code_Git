#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct NODE{
    int val;
    int min;
    struct NODE* next;
};
typedef struct NODE NODE_T;

typedef struct{
    int size;
    struct NODE *top;
} MinStack;

//returns the min of two ints
int MIN(int x, int y)
{
    if(x >= y)
    {
        return y;
    }
    else
    {
        return x;
    }
}

//creates a new node with the given value and min 
NODE_T* NewNode(int value, int min)
{
    NODE_T *tmp = malloc(sizeof(NODE_T));
    tmp->next = NULL;
    tmp->val = value;
    tmp->min = min;

    return(tmp);
}

//allocates mem to a new stack type and sets its min to 0
MinStack* minStackCreate() 
{
    MinStack *tmp = malloc(sizeof(MinStack));
    tmp->size = 0;
    tmp->top = NULL;

    return(tmp);
}

//checks if the stack is empty
bool isEmpty(MinStack* obj)
{
    if(obj->size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//prints the stack
void PrintStack(MinStack *stack)
{

    for (NODE_T *tmp = stack->top; tmp != NULL; tmp = tmp->next)
    {
        if(tmp == stack->top)
        {
            printf("%d <---- TOP (min = %d, size = %d)\n", tmp->val, tmp->min, stack->size);
        }
        else
        {
            printf("%d \n", tmp->val);
        }

    }
    
}

//pushes a value to the top of the stack
void minStackPush(MinStack* obj, int val) 
{
    //update the stacks min value
    int minimum;
    if(obj->size == 0)
    {
        minimum = val;
    }
    else
    {
        minimum = MIN((obj->top)->min, val);
    }

    //update the stack size
    obj->size++; 

    //makes new node
    NODE_T *nn = NewNode(val, minimum);

    //points it to the stack
    nn->next = obj->top;

    //changes the stack to to the new node location
    obj->top = nn;
}

void minStackPop(MinStack* obj)
{
    if(!isEmpty(obj))
    {
        NODE_T *tmp = obj->top;
        obj->top = (obj->top)->next;
        free(tmp);

        obj->size--;
    }
    else
    {
        printf("UNDERFLOW in pop- Cannot remove from an empty stack\n");
    }
}

int minStackTop(MinStack* obj) 
{
    return((obj->top)->val);
}

int minStackGetMin(MinStack* obj) 
{
    return((obj->top)->min);
}

void minStackFree(MinStack* obj) 
{

    while(!isEmpty(obj))
    {
        minStackPop(obj);

    }
    free(obj);
}