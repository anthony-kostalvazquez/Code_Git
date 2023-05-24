#include <stdio.h>
#include <stdlib.h>

int INPUT_ARR_1[] = {4,2,1};
int INPUT_ARR_2[] = {4,3,1};

struct ListNode {
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

//takes a list and sorts the elements using a bubble sort method
void sort_list(node_t **unsorted_list)
{
    printf("We are now in the sort list function\n");
    printlist(*unsorted_list);
    //initalizing for later use
    int temp_int = 0;

    //this starts at the first element of the unsorted list an iterates through
    for(node_t *i = *unsorted_list; i != NULL; i = i->next)
    {
        printf("\n\ni = %d\n", i->val);
        //this starts at the second element of the unsorted list and iterates through
        for(node_t *j = i->next; j != NULL; j = j->next)
        {
            printf("j = %d\n", j->val);
            //if value at position i is greater than its next value it will swap them
            if(i->val > j->val)
            {
                printf("swaping i for j \n");
                //swapping the values at positions i and j
                temp_int = i->val;
                i->val = j->val;
                j->val = temp_int;
                printlist(*unsorted_list);
            }
        }
    }
    
}


//Merges two sorted lists and returns a sorted list
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    node_t *unsorted_list = NULL;
    node_t *tmp;

    //takes all the elements from l1 and puts them into the return list
    tmp = list1;
    while(tmp != NULL)
    {
        insert_at_head(&unsorted_list, create_new_node(tmp->val));
        tmp = tmp->next;
    }

    //takes all the elements from l2 and puts them into the return list
    tmp = list2;
    while(tmp != NULL)
    {
        insert_at_head(&unsorted_list, create_new_node(tmp->val));
        tmp = tmp->next;
    }

    //sorts the list
    sort_list(&unsorted_list);

    return(unsorted_list);
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

    tmp = mergeTwoLists(headl1,headl2);

    printf("final list: ");
    printlist(tmp);

    return(0);
}