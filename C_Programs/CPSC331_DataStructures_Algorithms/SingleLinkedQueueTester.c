#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "SingleLinkedQueue.h"


int main()
{
    printf("Creating a new queue of integers\n");
    LQUEUE_T *queue = createQueue();
    printf("Starting with an empty queue\n");
    q.printQueue();
    q.enqueue(new Integer(1));
    q.printQueue();
    q.enqueue(new Integer(2));
    q.printQueue();
    q.enqueue(new Integer(3));
    q.printQueue();
    /*
    printf("Dequeued: " + q.dequeue());
    q.printQueue();
    printf("Dequeued: " + q.dequeue());
    q.printQueue();
    printf("Dequeued: " + q.dequeue());
    q.printQueue();
    q.enqueue(new Integer(4));
    q.printQueue();
    printf("Dequeued: " + q.dequeue());
    q.printQueue();
    */

    return 0;
}