#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int val;
    int numNeighbors;
    struct Node** neighbors;
};

typedef struct{
    int size;
    struct Node *top;
} MinStack;

//creates a new node with the given value and min 
struct Node* NewQNode(int value)
{
    NODE_T *tmp = malloc(sizeof(NODE_T));
    tmp->next = NULL;
    tmp->val = value;

    return(tmp);
}

//allocates mem to a new stack type and sets its min to 0
MinStack* StackCreate() 
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
            printf("%d <---- TOP (size = %d)\n", tmp->val, stack->size);
        }
        else
        {
            printf("%d \n", tmp->val);
        }

    }
    
}

//pushes a value to the top of the stack
void StackPush(MinStack* obj, int val) 
{


    //update the stack size
    obj->size++; 

    //makes new node
    NODE_T *nn = NewQNode(val);

    //points it to the stack
    nn->next = obj->top;

    //changes the stack to to the new node location
    obj->top = nn;
}

void StackPop(MinStack* obj)
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

int StackTop(MinStack* obj) 
{
    return((obj->top)->val);
}

void StackFree(MinStack* obj) 
{

    while(!isEmpty(obj))
    {
        
    StackPop(obj);

    }
    free(obj);
}


struct Node *cloneGraph(struct Node *s) 
{
    //Does a depth first search of the graph and makes an array of the graphs nodes
    bool visited[99] = {false};
    MinStack *SearchStack = StackCreate;

    struct Node *NodeArray[99];

    bool MoreToSearch = true;
    StackPush();


    while(!isEmpty(SearchStack) && )
    
    //makes copies of all of the graphs nodes





    //takes the array of nodes and constructs an adjacency list
}

