#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Cell_Objects
{
    int row;
    int column;
    char cell_type;
    bool visited;
};
typedef struct Cell_Objects CELL_T;

struct Double_Linked_Stack_Node
{
    struct Cell_Objects cell;
    struct Double_Linked_Stack_Node *next;
    struct Double_Linked_Stack_Node *prev;
};
typedef struct Double_Linked_Stack_Node DLSNODE_T;

//prints out the whole stack
void printStack(DLSNODE_T *top)
{
    DLSNODE_T *temp = top;
    CELL_T current_cell;
    
    printf("TOP--> ");
    
    
    while(temp != NULL)
    {
        current_cell = temp->cell;
        printf("%c ", current_cell.cell_type);
        temp = temp->next;
    }

}

//prints out a cells values
void print_cell(CELL_T *cell_to_print)
{
    printf("row = %d, column = %d, cell type = %c, visited %d\n", cell_to_print->row, cell_to_print->column, cell_to_print->cell_type, cell_to_print->visited);
}

//Creates a new node in a stack given all the cell inputs and outputs a pointer to it
DLSNODE_T *create_new_node(CELL_T *Cell_To_Add)
{
    //allocating the mem
    DLSNODE_T *result = (DLSNODE_T *) malloc(sizeof( DLSNODE_T ));

    result->cell = *Cell_To_Add;
    result->next = NULL;
    result->prev = NULL;
    return result;
}

//Creates a new cell given the inputs and returns a pointer to it
CELL_T *create_new_cell(int row_in, int column_in, char cell_type_in, bool visited_in)
{
    CELL_T* return_cell = (CELL_T *)malloc(sizeof( CELL_T ));

    //strcpy(return_cell->cell_type, cell_type_in);
    return_cell->row = row_in;
    return_cell->column = column_in;
    return_cell->cell_type = cell_type_in;
    return_cell->visited = visited_in;


    return(return_cell);
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
void push(DLSNODE_T **top, CELL_T *Cell_To_Insert)
{

    //makes new node with the value
    DLSNODE_T *node_to_insert = create_new_node(Cell_To_Insert);

    node_to_insert->next = *top;
    *top = node_to_insert;
}

//Removes the item from the top of the stack and returns a pointer to the cell it stored
//updates the stack top

CELL_T pop(DLSNODE_T **top)
{
    if((!(isEmpty(*top))) && ((*top)->next == NULL))
    {
        DLSNODE_T *tmp = *top;

        CELL_T return_cell = tmp->cell;


        *top = (*top)->next;

        free(tmp);
        return(return_cell);
    }
    else if( !(isEmpty(*top)))
    {
        DLSNODE_T *tmp = *top;

        CELL_T return_cell = tmp->cell;

        *top = (*top)->next;
        (*top)->prev = NULL;

        free(tmp);
        return(return_cell);
    }
    else
    {
        printf("UNDERFLOW in pop- Cannot remove from an empty stack\n");
    }
}


//prints out the top value if the list is not empty
CELL_T peek(DLSNODE_T *top)
{
    if( !(isEmpty(top)))
    {
        return(top->cell);
    }
    else
    {
        printf("UNDERFLOW in peek- Cannot Peek at an empty stack");
    }
}