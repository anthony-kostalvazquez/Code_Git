#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//-----------------------------------------COLOR IMPLEMENTATION-----------------------------------------//
#define BLK   "\e[0;30m"
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

//-----------------------------------------CELL IMPLEMENTATION-----------------------------------------//
struct Cell_Objects
{
    int row;
    int column;
    char cell_type;
    bool visited;
};
typedef struct Cell_Objects CELL_T;

//prints out a cells values
void print_cell(CELL_T *cell_to_print)
{
    printf("(row = %d, column = %d, cell type = %c, visited %d)", cell_to_print->row, cell_to_print->column, cell_to_print->cell_type, cell_to_print->visited);
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

//-----------------------------------------Single linked queue implementation -----------------------------------------//

struct Single_Linked_Queue_Node
{
    CELL_T *cell;
    struct Single_Linked_Queue_Node *next;
};
typedef struct Single_Linked_Queue_Node SLQNODE_T;

struct SingleLinkedQueue
{
    struct Single_Linked_Queue_Node *front;
    struct Single_Linked_Queue_Node *rear;
};
typedef struct SingleLinkedQueue SLQUEUE_T;

//checks if the queue is empty
bool isEmptyQueue(SLQUEUE_T *queue)
{
    return(queue->front == NULL);
}

//always returns false
bool isFullQueue(SLQUEUE_T *queue)
{
    return(false);
}

//prints the queue with front and rear markers
void printQueue(SLQUEUE_T *queue)
{

    printf("rear-> ");
    if(!isEmptyQueue(queue))
    {
        //itterates through all of the nodes of queue
        for(SLQNODE_T *i = queue->rear; i != NULL; i = i->next)
        {
            //printf("%c", (i->cell)->cell_type);
            //print_cell(i->cell);
            printf("(%d, %d)", (i->cell)->row, (i->cell)->column);
            if(i->next != NULL)
            {
                printf(", ");
            }
        }
    }

    printf(" <-front\n");
}

//gets the size of a given queue
int SizeQueue(SLQUEUE_T *queue)
{
    int count = 0;

    if(queue)
    {
    //itterates through all of the nodes of queue
        for(SLQNODE_T *i = queue->rear; i != NULL; i = i->next)
        {
            count++;
        }
    }
    return(count);
}

//creates a new node with an integer element
SLQNODE_T *newNode(CELL_T *cell_to_input)
{
    SLQNODE_T *tmp = (SLQNODE_T*)malloc(sizeof(SLQNODE_T));
    tmp->cell = cell_to_input;
    tmp->next = NULL;
    return tmp;
}

//creates a new Queue and sets front and read to null
SLQUEUE_T *createQueue()
{
    SLQUEUE_T *tmp = (SLQUEUE_T *)malloc(sizeof(SLQNODE_T));
    tmp->front = NULL;
    tmp->rear = NULL;
    return tmp;

}

// FIFO this will add from the rear and push the front up
// rear [enqueue]->[val]->[val]->[val] front
void enqueue (CELL_T *cell_to_input, SLQUEUE_T **queue)
{
    SLQNODE_T *nn = newNode(cell_to_input);
    nn->next = (*queue)->rear;
    (*queue)->rear = nn;

    if((*queue)->front == NULL)
    {
        (*queue)->front = (*queue)->rear;
    }
}

//this will remove the front element of the queue and return its value
//rear [val]->[val]->[val] front
CELL_T *dequeue (SLQUEUE_T **queue)
{
    if(!isEmptyQueue(*queue))
    {
        CELL_T *return_cell = ((*queue)->front)->cell;
        if ((*queue)->front == (*queue)->rear)
        {
            free((*queue)->front);
            (*queue)->front = NULL;
            (*queue)->rear = NULL;

        }
        else
        {
            //create a temporary pointer
            SLQNODE_T *tmp = (*queue)->rear;
            //climb through the queue until you find the second to last node
            while(tmp->next != (*queue)->front)
            {
                tmp = tmp->next;
            }
            //now that tmp is a pointer to the second to last node we update this to front and delete the last node
            free(tmp->next);

            (*queue)->front = tmp;
            (*queue)->front->next = NULL;
        }
        return(return_cell);
    }
    else
    {
        printf("UNDERFLOW in dequeue- Cannot remove from an empty queue\n");
    }
}

//-----------------------------------------Double linked stack implementation -----------------------------------------//
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
    DLSNODE_T *tmp = top;
    CELL_T current_cell;
    
    printf("TOP--> ");
    
    
    while(tmp != NULL)
    {
        current_cell = tmp->cell;
        printf("%c ", current_cell.cell_type);
        tmp = tmp->next;
    }
    
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

//answers the questions is the stack empty with a bool
bool isEmptyStack(DLSNODE_T *top)
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
bool isFullStack(DLSNODE_T *top)
{
    return(false);
}

//If the stack is not full it adds an element to the top
//Updates the top element
void push(DLSNODE_T **top, CELL_T *Cell_To_Insert)
{

    //makes new node with the value
    DLSNODE_T *SLQnode_to_insert = create_new_node(Cell_To_Insert);

    SLQnode_to_insert->next = *top;
    *top = SLQnode_to_insert;
}

//Removes the item from the top of the stack and returns a pointer to the cell it stored
//updates the stack top

CELL_T pop(DLSNODE_T **top)
{
    if((!(isEmptyStack(*top))) && ((*top)->next == NULL))
    {
        DLSNODE_T *tmp = *top;

        CELL_T return_cell = tmp->cell;


        *top = (*top)->next;

        free(tmp);
        return(return_cell);
    }
    else if( !(isEmptyStack(*top)))
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
    if( !(isEmptyStack(top)))
    {
        return(top->cell);
    }
    else
    {
        printf("UNDERFLOW in peek- Cannot Peek at an empty stack");
    }
}