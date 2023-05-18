#include <stdio.h>
#include <stdlib.h>

int INPUT_ARR_1[] = {2,4,3};
int INPUT_ARR_2[] = {5,6,4};


//linked list implementation
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    while(l1 != NULL)
    {
        printf("%d \n", l1->val);
        l1 = l1->next;
        break;
    }
}

int main()
{
    struct ListNode *l1 , *l2;
    //l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    //l1->next = NULL;
    //l1->val = INPUT_ARR_1[0];

    l1 = NULL;
    for (int i = 1; i < sizeof(INPUT_ARR_1)/sizeof(INPUT_ARR_1[0]); i++)
    {
        struct ListNode nn;
        nn.val = INPUT_ARR_1[i];
        nn.next = l1;
        l1 = &nn;
    }



    
    addTwoNumbers(l1,l2);


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