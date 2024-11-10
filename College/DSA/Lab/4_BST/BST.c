#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode
{
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
} BSTNode;

typedef struct BST
{
    BSTNode *root;

} BST;

BST *init_BST();
void add_node(BST *b, int x);
void inorder(BST *b1, BSTNode *root);
void preorder(BST *b1, BSTNode *root);
void postorder(BST *b1, BSTNode *root);

int main()
{
    BST *b1;
    int x, choice;
    b1 = init_BST();

    while (1)
    {
        scanf("%d", &choice);
        // printf("Choice=%d\n", choice);
        //  For initialization of link list
        if (choice == 0)
        {
            b1 = init_BST();
        }
        else if (choice == 1)
        { // insert element x into BST
            scanf("%d", &x);
            add_node(b1, x);
        }
        else if (choice == 2) // do the inorder traversal of BST
        {
            inorder(b1, b1->root);
            printf("\n");
        }

        else if (choice == 3)
        {
            preorder(b1, b1->root);
            printf("\n");
        }
        else if (choice == 4)
        {
            postorder(b1, b1->root);
            printf("\n");
        }
        else
            break;
    }
    return 0;
}

// TO initialize BST
BST *init_BST()
{
    BST *b;
    b = malloc(sizeof(BST));
    if (b == NULL)
        return NULL;
    b->root = NULL;
    return b;
}

// Complete this function to add a node to BST
void add_node(BST *b, int x)
{
    // WRITE YOUR CODE BELOW! ....
    BSTNode *new_node;
    new_node = malloc(sizeof(BSTNode));
    new_node->data = x;
    new_node->left = NULL;
    new_node->right = NULL;

    if (b->root == NULL)
    {
        b->root = new_node;
    }

    else
    {
        BSTNode *temp = b->root;
        while (1)
        {
            if (temp->data == x)
            {
                printf("DUPLICATE ELEMENT %d NOT INSERTED\n", x);
                return;
            }

            if (temp->data > x)
            {
                if (temp->left != NULL)
                {
                    temp = temp->left;
                    continue;
                }
                else
                {
                    temp->left = new_node;
                    return;
                }
            }
            else
            {
                if (temp->right != NULL)
                {
                    temp = temp->right;
                    continue;
                }
                else
                {
                    temp->right = new_node;
                    return;
                }
            }
        }
    }
}

//  inorder traversal of BST
// Complete this function to do inorder traversal of BST
void inorder(BST *b1, BSTNode *root)
{

    // WRITE YOUR CODE BELOW! ....
    if (root != NULL)
    {
        inorder(b1, root->left);
        printf("%d, ", root->data);
        inorder(b1, root->right);
    }
}

// Write preorder traversal of BST tree
void preorder(BST *b1, BSTNode *root)
{
    // WRITE YOUR CODE BELOW! ....
    if (root != NULL)
    {
        printf("%d, ", root->data);
        preorder(b1, root->left);
        preorder(b1, root->right);
    }
}

// Write the post order traversal of BST tree
void postorder(BST *b1, BSTNode *root)
{
    // WRITE YOUR CODE BELOW! ....
    if (root != NULL)
    {
        postorder(b1, root->left);
        postorder(b1, root->right);
        printf("%d, ", root->data);
    }
}
