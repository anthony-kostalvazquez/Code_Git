//gcc Linked_Stack_Implementation.c -I.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "LinkedStack.h"

int main()
{
    //this is to test the implementation
    LSNODE_T *top = NULL;

    printf("Creating a new stack of integers \n");
    printStack(top);
    push(&top, 4);
    printStack(top);
    printf("The peek of the stack is: %d\n", peek(top));
    push(&top, 2);
    printStack(top);
    printf("The peek of the stack is: %d\n", peek(top));
    push(&top,5);
    printStack(top);
    printf("The peek of the stack is: %d\n", peek(top));
    push(&top, 7);
    printStack(top);
    printf("The peek of the stack is: %d\n", peek(top));
    printf("Popped: %d\n", pop(&top));
    printf("The peek of the stack is: %d\n", peek(top));
    
    printf("Clearning the stack\n");  
    printStack(top);
    while (!isEmpty(top))
    {
        pop(&top);
        printStack(top);
    } 
    printf("Attempting a pop on an empty stack\n");
    pop(&top);
    printf("Creating a another stack\n");
    for (int i = 0; i < 10; i++)
    {
        push(&top, (9 - i));
        printf("Pushed %d\n", (9 - i) );
    }

    printStack(top);
    printf("Pushing one more element\n");
    push(&top, 10);  
    printf("Pushed 10\n");
    printStack(top);



    return 0;
}
