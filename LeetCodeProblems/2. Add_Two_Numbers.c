#include <stdio.h>
#include <stdlib.h>

int INPUT_ARR_1[] = {3,4,2};
int INPUT_ARR_2[] = {4,6,5};


//linked list implementation
struct ListNode
{
    int val;
    struct ListNode *next;
};
typedef struct ListNode node_t;

//prints out the entire linked list given the head
void printlist(node_t *head)
{
    node_t *temp = head;

    while (temp != NULL)
    {
        printf("%d -", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

//creates a new node and puts the value in it and returns a pointer to it
node_t *create_new_node(int value)
{
    node_t *result = malloc(sizeof(node_t));
    result->val = value;
    result->next = NULL;
    return result;
}

//inserts a node at the head of a list
//updates head pointer to itself
//returns a pointer to 
node_t *insert_at_head(node_t **head, node_t *node_to_insert)
{
    node_to_insert->next = *head;
    *head = node_to_insert;
    return node_to_insert;
}

//finds a node 
node_t *find_node(node_t *head, int value)
{
    node_t *tmp = head;
    while(tmp != NULL)
    {
        if (tmp->val == value)
        {
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}

//inserts a new node after the specified node
node_t *insert_after_node(node_t *node_to_insert_after, node_t* new_node)
{
    new_node->next = node_to_insert_after->next;
    node_to_insert_after->next = new_node;
}


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    node_t *temp;

    while(l1 != NULL)
    {
    }
}

int main()
{
    node_t *headl1 = NULL, *headl2 = NULL;
    node_t *tmp;

    for (int i = 0; i < sizeof(INPUT_ARR_1)/sizeof(INPUT_ARR_1[0]); i++)
    {
        insert_at_head(&headl1, create_new_node(INPUT_ARR_1[i]));
        insert_at_head(&headl2, create_new_node(INPUT_ARR_2[i]));
    }


    printlist(headl1);
    printlist(headl2);

    addTwoNumbers(headl1,headl2);


    /*
    struct ListNode l1,l2;
    
    struct ListNode nn;
    l1.val = INPUT_ARR_1[0];
    l1.next = &nn;

    struct ListNode nn1;
    nn.val = INPUT_ARR_1[1];
    nn.next = &nn1;

    nn1.val = INPUT_ARR_1[2];
    nn1.next = NULL;

    addTwoNumbers(&l1, &l2);
    */



    return(0);
}