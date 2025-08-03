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
int delete_BST(BST *b1, int x);

int main()
{
    BST *b1;
    int x, choice, del_element;
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
        else if (choice == 5) // search an element x
            continue;
        else if (choice == 6) // delete an element x
        {
            scanf("%d", &x);
            del_element = delete_BST(b1, x);
            printf("%d\n", del_element);
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
    if (root)
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
    if (root)
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
    if (root)
    {
        postorder(b1, root->left);
        postorder(b1, root->right);
        printf("%d, ", root->data);
    }
}

void findSuccessor(BSTNode *root, int x, int *s)
{
    if (root == NULL)
    {
        return;
    }

    findSuccessor(root->left, x, s);
    if (root->data > x)
    {
        if ((*s == -1) || (*s != -1 && *s > root->data))
            *s = root->data;
    }
    findSuccessor(root->right, x, s);
}

// Write code for deleteion of element x from BST
int delete_BST(BST *b, int x)
{
    // WRITE YOUR CODE BELOW! ....
    if (b->root == NULL)
    {
        return -9999;
    }

    BSTNode *temp, *parent;
    temp = b->root;
    parent = NULL;
    while (temp->data != x)
    {
        parent = temp;
        if (temp->data < x)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
        if (temp == NULL)
        {
            return -9999;
        }
    }

    // single child case
    if (temp->left != NULL && temp->right == NULL)
    {
        if (parent->left == temp)
        {
            parent->left = temp->left;
        }
        else
        {
            parent->right = temp->left;
        }
        free(temp);
        return x;
    }

    if (temp->left == NULL && temp->right != NULL)
    {
        if (parent->left == temp)
        {
            parent->left = temp->right;
        }
        else
        {
            parent->right = temp->right;
        }
        free(temp);
        return x;
    }

    // no child case
    if (temp->left == NULL && temp->right == NULL)
    {
        if (parent->left == temp)
        {
            parent->left = NULL;
        }
        else
        {
            parent->right = NULL;
        }
        free(temp);
        return x;
    }

    // two child case
    if (temp->left != NULL && temp->right != NULL)
    {
        // printf("tow chol\n");
        int s = -1;
        findSuccessor(b->root, temp->data, &s);
        if (s == -1)
        {
            return -9999;
        }
        else
        {
            x = temp->data;
            temp->data = delete_BST(b, s);
            return x;
        }
    }
    return x;
}