#include <stdio.h>
#include <stdlib.h>

//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

int findLength(struct ListNode* head)
{
    int size = 0;
    while(head != NULL)
    {
        size++;
        head = head->next;
    }


    return size;
}





struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* returnListHead = NULL;
    int l1_Length = findLength(l1);
    int l2_Length = findLength(l2);

    printf("l1 length = %d, l2 length = %d",l1_Length,l2_Length);





    return returnListHead;
}