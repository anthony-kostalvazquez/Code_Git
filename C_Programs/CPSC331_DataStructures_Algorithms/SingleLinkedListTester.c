//gcc SingleLinkedListTester.c -I.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "../AnthonysCLib/SingleLinkedList.h"

int main()
{
    SLL_T *head = NULL;
    SLL_T *tmp;

    for (int i = 0; i < 25; i++)
    {
        tmp = create_new_node((i));
        insert_at_head(&head,tmp);

    }

    tmp = find_node(head, 13);
    printf("found node with value %d\n", tmp->value);

    insert_after_node(tmp, create_new_node(75));

    printlist(head);

    DeleteList(&head);

    //printlist(head);

    return 0;
}