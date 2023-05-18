#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node* next;
};
typedef struct node node_t;

//prints out the entire linked list given the head
void printlist(node_t *head)
{
    node_t *temp = head;

    while (temp != NULL)
    {
        printf("%d -", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

//creates a new node and puts the value in it and returns a pointer to it
node_t *create_new_node(int value)
{
    node_t *result = malloc(sizeof(node_t));
    result->value = value;
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
        if (tmp->value == value)
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

int main()
{
    node_t *head = NULL;
    node_t *tmp;

    for (int i = 0; i < 25; i++)
    {
        tmp = create_new_node((i));
        insert_at_head(&head,tmp);

    }

    tmp = find_node(head, 13);
    printf("found node with value %d\n", tmp->value);

    insert_after_node(tmp, create_new_node(75));


    printlist(head);

    return 0;
}