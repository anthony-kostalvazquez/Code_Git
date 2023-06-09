#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

//takes linked list and returns the length of it
int LengthList(struct ListNode* head)
{
    int length = 0;
    for (struct ListNode *i = head; i != NULL; i = i->next)
    {
        length++;
    }

    return(length);
}

//takes a linked list and an int and returns the node at that integer
struct ListNode* ReturnIndex(struct ListNode* head, int indx)
{
    struct ListNode* tmp = head;

    for (int i = 0; i < indx; i++)
    {
        tmp = tmp->next;
    }

    return(tmp);
}

//returns the middle node of a linked list
struct ListNode* middleNode(struct ListNode* head)
{
    int length = LengthList(head);
    int middle = ceil(length / 2);
    return(ReturnIndex(head, middle));
}
