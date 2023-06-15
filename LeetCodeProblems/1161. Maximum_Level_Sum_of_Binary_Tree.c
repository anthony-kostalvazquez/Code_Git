#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


//Definition for a binary tree node.
struct TreeNode 
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct Node
{
    struct TreeNode *value;
    struct Node *next;
};
typedef struct Node QUEUE_NODE_T;

struct LinkedQueue
{
    struct Node *front;
    struct Node *rear;
    int size;
};
typedef struct LinkedQueue LQUEUE_T;

//creates a new node with an integer element
QUEUE_NODE_T *newNode(struct TreeNode *treenode)
{
    QUEUE_NODE_T *tmp = (QUEUE_NODE_T*)malloc(sizeof(QUEUE_NODE_T));
    tmp->value = treenode;
    tmp->next = NULL;
    return tmp;
}

//creates a new Queue and sets front and read to null
LQUEUE_T *createQueue()
{
    LQUEUE_T *tmp = (LQUEUE_T *)malloc(sizeof(int) + 2*sizeof( struct Node *) );
    tmp->front = NULL;
    tmp->rear = NULL;
    tmp->size = 0;
    return tmp;

}

//checks if the queue is empty
bool isEmpty(LQUEUE_T *queue)
{
    return(queue->front == NULL);
}

// FIFO this will add from the rear and push the front up
// rear [enqueue]->[val]->[val]->[val] front
void enqueue (struct TreeNode *treenode, LQUEUE_T *queue)
{
    QUEUE_NODE_T *nn = newNode(treenode);
    nn->next = queue->rear;
    queue->rear = nn;

    if(queue->front == NULL)
    {
        queue->front = queue->rear;
    }
    (queue->size)++;
}

//this will remove the front element of the queue and return its value
//rear [val]->[val]->[val] front
struct TreeNode *dequeue(LQUEUE_T **queue)
{

    struct TreeNode *treenode = (*queue)->front->value;


    if ((*queue)->front == (*queue)->rear)
    {
        free((*queue)->front);
        (*queue)->front = NULL;
        (*queue)->rear = NULL;

    }
    else
    {
        //create a temporary pointer
        QUEUE_NODE_T *tmp = (*queue)->rear;
        //climb through the queue until you find the second to last node
        while(tmp->next != (*queue)->front)
        {
            tmp = tmp->next;
        }
        //now that tmp is a pointer to the second to last node we update this to front and delete the last node
        free(tmp->next);

        (*queue)->front = tmp;
        (*queue)->front->next = NULL;
    }

    ((*queue)->size)--;
    return(treenode);
}


int maxLevelSum(struct TreeNode* root)
{

    //initalize the queue and visited array
    LQUEUE_T *Q = createQueue();

    //initalize some values we will need
    int level_sum = 0;
    int level_size = 0;
    
    int level = 1;
    int ret_val = 1;
    int record = root->val;
    struct TreeNode * removed;
    
    enqueue(root, Q);
    while(!isEmpty(Q))
    {
        
        level_size = Q->size;
        level_sum = 0;

        for (int i = 0; i < level_size; i++)
        {
            removed = dequeue(&Q);
            
            level_sum += removed->val;
            
            if (removed->left != NULL)
            {
                enqueue(removed->left, Q);
            }
            if (removed->right != NULL)
            {
                enqueue(removed->right, Q);
            }
        }

        if(level_sum > record)
        {
            record = level_sum;
            ret_val = level;
        }

        level++;
        
    }


    return ret_val;
}