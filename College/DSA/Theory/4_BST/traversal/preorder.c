#include "stdio.h"
#include <stdlib.h>
typedef struct BinaryTreeNode
{
    int data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
} BinaryTreeNode;

void inOrderTraversalRecursive(BinaryTreeNode *root);
void inOrderTraversalIterative(BinaryTreeNode *root);

int main()
{
    //// write da code here...
    BinaryTreeNode *root;
    root = malloc(sizeof(BinaryTreeNode));
    root->data = 1;

    BinaryTreeNode *left, *right;
    left = malloc(sizeof(BinaryTreeNode));
    right = malloc(sizeof(BinaryTreeNode));

    left->data = 2;
    right->data = 3;
    left->left = NULL;
    left->right = NULL;
    right->left = NULL;
    right->right = NULL;
    root->left = left;
    root->right = right;

    inOrderTraversalRecursive(root);
    return 0;
}

void inOrderTraversalRecursive(BinaryTreeNode *root)
{
    if (root)
    {
        printf("%d, ", root->data);
        inOrderTraversalRecursive(root->left);
        inOrderTraversalRecursive(root->right);
    }
}

void inOrderTraversalIterative(BinaryTreeNode *root)
{
}
