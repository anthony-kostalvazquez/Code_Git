#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int prev = INT_MAX;
int ans = INT_MAX;



//returns the min of two ints
int MIN(int x, int y)
{
    if(x >= y)
    {
        return y;
    }
    else
    {
        return x;
    }
}

//returns an inorder list of the nodes in an array
void InOrderTransversalArray(struct TreeNode* root)
{
    if(root->left != NULL)
    {
        InOrderTransversalArray(root->left);
    }
    ans = MIN(ans, abs(root->val - prev));
    prev = root->val;
    if(root->right != NULL)
    {
        InOrderTransversalArray(root->right);
    }
}


//the minimum absolute difference is going to be the difference between the smallest node and the second smallest node
int getMinimumDifference(struct TreeNode* root)
{
    InOrderTransversalArray(root);
    return ans;
}