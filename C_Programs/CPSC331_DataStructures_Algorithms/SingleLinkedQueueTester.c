#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "SingleLinkedQueue.h"


int main()
{
    printf("Creating a new queue of integers\n");
    LQUEUE_T *queue = createQueue();
    printf("Starting with an empty queue\n");
    printQueue(queue);
    enqueue(1, &queue);
    printQueue(queue);
    enqueue(2, &queue);
    printQueue(queue);
    enqueue(3, &queue);
    printQueue(queue);
    printf("Starting to dequeue\n");
    printf("Dequeued: %d\n", dequeue(&queue));
    printQueue(queue);
    printf("Dequeued: %d\n", dequeue(&queue));
    printQueue(queue);
    printf("Dequeued: %d\n", dequeue(&queue));
    printQueue(queue);
    enqueue(4, &queue);
    printQueue(queue);
    printf("Dequeued: %d\n", dequeue(&queue));
    printQueue(queue);

    return 0;
}