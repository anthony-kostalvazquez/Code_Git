#include <stdio.h>
#include <stdlib.h>

int INPUT_ARR_1[] = {9,9,9,9,9,9,9};
int INPUT_ARR_2[] = {9,9,9,9};


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

//takes a linked list in reverse order and returns the integer it represents
int Integer_From_Reverse_Linked_List(node_t *head)
{
    int return_int = 0;
    int i = 1;

    while(head != NULL)
    {
        return_int += (head->val)*i;
        i = i*10;
        head = head->next;
    }

    return(return_int);
}

//Takes a link list and flips it
node_t *List_Flip(node_t *head)
{
    node_t *return_head = NULL;
    
    while(head != NULL)
    {
        insert_at_head(&return_head, create_new_node(head->val));
        head = head->next;
    }

    return(return_head);
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    node_t *Return_List_Head = NULL;
    node_t *temp;
    int carryover = 0;

    //calculating the sum into a linked list in the correct order
    while(l1 != NULL || l2 != NULL || carryover != 0)
    {

        //initalizing
        int added_digits = 0;

        //adding the numbers from the linked lists and incrementing
        if(l1 != NULL)
        {
            added_digits += l1->val;
            l1 = l1->next;
            printf("adding l1 = %d\n", added_digits);
        }
        if(l2 != NULL)
        {
            added_digits += l2->val;
            printf("adding l2 = %d\n", l2->val);
            l2 = l2->next;
        }

        printf("added digits + carryover = %d\n", added_digits + carryover);
        


        //creating a new node and putting the digits in 
        temp = create_new_node((added_digits + carryover) % 10);
        printf("%d\n", temp->val);
        Return_List_Head = insert_at_head(&Return_List_Head, temp);

        //incrementing the caryover if needed
        if((added_digits + carryover) >= 10)
        {
            carryover = 1;
        }
        else
        {
            carryover = 0;
        }

    }
    

    /*
    node_t *Return_List_Head = NULL;
    node_t *temp;
    
    //we calculate the output integer
    int added_int = Integer_From_Reverse_Linked_List(l1) + Integer_From_Reverse_Linked_List(l2);

    //then we put it into a linked list
    do
    {
        temp = create_new_node(added_int%10);
        Return_List_Head = insert_at_head(&Return_List_Head, temp);
        added_int = added_int / 10;
    } while (added_int != 0);
    */

    //Return a flipped list
    return(List_Flip(Return_List_Head));
}

int main()
{
    node_t *headl1 = NULL, *headl2 = NULL;
    node_t *tmp;

    for (int i = 0; i < sizeof(INPUT_ARR_1)/sizeof(INPUT_ARR_1[0]); i++)
    {
        insert_at_head(&headl1, create_new_node(INPUT_ARR_1[i]));
    }
    
    for (int i = 0; i < sizeof(INPUT_ARR_2)/sizeof(INPUT_ARR_2[0]); i++)
    {
        insert_at_head(&headl2, create_new_node(INPUT_ARR_2[i]));
    }


    printlist(headl1);
    printlist(headl2);

    tmp = addTwoNumbers(headl1,headl2);

    printlist(tmp);

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