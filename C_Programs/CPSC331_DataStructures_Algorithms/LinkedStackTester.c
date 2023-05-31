//gcc LinkedStackTester.c -I.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//#include "LinkedStack.h"
#include "../AnthonysCLib/DoubleLinkedStack.h"

int main()
{
    //this is to test the implementation of single linked stack
    //LSNODE_T *top = NULL;
    //this is to test the implementation of a double linked stack
    DLSNODE_T *top = NULL;

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
    
    printf("Clearing the stack\n");  
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
    

    free(top);
    return 0;
}
