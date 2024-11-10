#include "stdio.h"

typedef struct BinaryTreeNode
{
    int data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
} BinaryTreeNode;



int main()
{
    //// write da code here...
    BinaryTreeNode* root;
    root = malloc(sizeof(BinaryTreeNode));
    root->data = 2;
    
    BinaryTreeNode *left, *right;
    left = malloc(sizeof(BinaryTreeNode));
    right = malloc(sizeof(BinaryTreeNode));

    left->data = 2;
    right->data = 3;
    root->left = left;
    root->right = right;

    return 0;
}