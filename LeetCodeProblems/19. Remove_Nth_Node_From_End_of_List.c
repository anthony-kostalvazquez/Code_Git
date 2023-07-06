#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//Definition for singly-linked list.
struct ListNode{
    int val;
    struct ListNode *next;
};


void RemoveNode(int index, struct ListNode* head)
{
    struct ListNode *NodeBeforeIndex = head;
    struct ListNode *NodeToRemove = head;
    printf("index = %d\n", index);

    //Sets the NodeBeforeIndex and NodeToRemove to the proper positions
    for (int i = 0; i < index - 1 && index != 0; i++)
    {
        NodeBeforeIndex = NodeBeforeIndex->next;
    }
    NodeToRemove = NodeBeforeIndex->next;

    //Removes the node
    printf("Removing index = %d, value = %d\n", index, NodeToRemove->val);
    NodeBeforeIndex->next = NodeToRemove->next;

    
    free(NodeToRemove);
}



struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    struct ListNode *ListPonter = head;
    
    int size = 0;     //the size of the list
    int position = 0; //the position of the node to remove from the front (0 indexed)

    //finds size of the list
    while (ListPonter != NULL)
    {
        size++;
        ListPonter = ListPonter->next;
    }
    position = size - n;


    if (size == 1)
    {
        head = NULL;
    }
    else if(position == 0)
    {
        head = head->next;
    }
    else
    {
        RemoveNode(position, head);
    }



    return(head);
}