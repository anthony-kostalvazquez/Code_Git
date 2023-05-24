#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int value;
    struct Node *next;
};
typedef struct Node NODE_T;

struct LinkedQueue
{
    struct Node *front;
    struct Node *rear;
};
typedef struct LinkedQueue LQUEUE_T;

//prints the queue with front and rear markers
void printQueue(LQUEUE_T *queue)
{
    NODE_T 
    printf("rear ->");
    for()

    printf("<-- front")
}

//creates a new node with an integer element
NODE_T *newNode(int element)
{
    NODE_T *tmp = (NODE_T*)malloc(sizeof(NODE_T));
    tmp->value = element;
    tmp->next = NULL;
    return tmp;
}

//creates a new Queue and sets front and read to null
LQUEUE_T *createQueue()
{
    LQUEUE_T *tmp = (LQUEUE_T *)malloc(sizeof(NODE_T));
    tmp->front = NULL;
    tmp->rear = NULL;
    return tmp;

}

//checks if the queue is empty
bool isEmpty(LQUEUE_T *queue)
{
    return(queue->front == NULL);
}

//always returns false
bool isFull(LQUEUE_T *queue)
{
    return(false);
}

// FIFO this will add from the rear and push the front up
// rear [val]->[val]->[val] front
void enqueue (int element, LQUEUE_T **queue)
{
    NODE_T *nn = newNode(element);
    nn->next = (*queue)->rear;
    (*queue)->rear = nn;

    if((*queue)->front = NULL)
    {
        (*queue)->front = (*queue)->rear;
    }
}

int dequeue (LQUEUE_T)
{

}