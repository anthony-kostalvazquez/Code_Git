#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int value;
    struct Node *next;
};
typedef struct Node QUEUE_NODE_T;

struct LinkedQueue
{
    struct Node *front;
    struct Node *rear;
};
typedef struct LinkedQueue LQUEUE_T;

//prints the queue with front and rear markers
void printQueue(LQUEUE_T *queue)
{

    printf("rear-> ");
    if(queue)
    //itterates through all of the nodes of queue
    for(QUEUE_NODE_T *i = queue->rear; i != NULL; i = i->next)
    {
        printf("%d", i->value);
        if(i->next != NULL)
        {
            printf(", ");
        }
    }

    printf(" <-front\n");
}

//creates a new node with an integer element
QUEUE_NODE_T *newNode(int element)
{
    QUEUE_NODE_T *tmp = (QUEUE_NODE_T*)malloc(sizeof(QUEUE_NODE_T));
    tmp->value = element;
    tmp->next = NULL;
    return tmp;
}

//creates a new Queue and sets front and read to null
LQUEUE_T *createQueue()
{
    LQUEUE_T *tmp = (LQUEUE_T *)malloc(sizeof(QUEUE_NODE_T));
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
// rear [enqueue]->[val]->[val]->[val] front
void enqueue(int element, LQUEUE_T *queue)
{
    QUEUE_NODE_T *nn = newNode(element);
    nn->next = queue->rear;
    queue->rear = nn;

    if(queue->front == NULL)
    {
        queue->front = queue->rear;
    }
}

//this will remove the front element of the queue and return its value
//rear [val]->[val]->[val] front
int dequeue(LQUEUE_T *queue)
{

    int return_value = queue->front->value;


    if (queue->front == queue->rear)
    {
        free(queue->front);
        queue->front = NULL;
        queue->rear = NULL;

    }
    else
    {
        //create a temporary pointer
        QUEUE_NODE_T *tmp = queue->rear;
        //climb through the queue until you find the second to last node
        while(tmp->next != queue->front)
        {
 
            tmp = tmp->next;
        }
        //now that tmp is a pointer to the second to last node we update this to front and delete the last node
        free(tmp->next);

        queue->front = tmp;
        queue->front->next = NULL;
    }
    return(return_value);
}

//takes a queue of indexes and checks an array and returns the min value at that index and deques it
//queue = ind1, ind2
//array = value 1
// returns min( array[ind]  )
int FindMinIn(int *array, LQUEUE_T *queue)
{
    //set the record and min index to the rear value
    QUEUE_NODE_T *index = queue->rear;
    int record = array[index->value];
    int min_index = index->value;
    index = index->next;

    while(index != NULL)
    {
        if(record < array[index->value])
        {
            record = array[index->value];
            min_index = index->value;
        }

        index = index->next;
    }

    //dequeues it 


    return(min_index);
}