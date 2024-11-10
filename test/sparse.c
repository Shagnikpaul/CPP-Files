#include "stdio.h"
#include "stdlib.h"

typedef struct Node
{
    int data;
    int row;
    int column;
    struct Node *next;
} Node;

typedef struct linkedlist
{
    Node *head;

} Linkedlist;

void traverse(Linkedlist *l);
void addAtBeginning(Linkedlist *l, int x, int row, int col);
void delete(Linkedlist *l, int row, int col);

int main()
{

    // sample data
    // head

    int matrix[3][3] = {{0, 0, 19}, {0, 0, 0}, {33, 0, 0}};
    Node *head = malloc(sizeof(Node));
    int k = 0;
    Linkedlist *l;
    l = malloc(sizeof(Linkedlist));
    l->head = NULL;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {

            if (matrix[i][j] != 0)
            {
                if (k == 0)
                {
                    addAtBeginning(l, matrix[i][j], i, j);
                }
                else
                {
                    addAtBeginning(l, matrix[i][j], i, j);
                }
                k++;
            }
        }
    }
    if (k == 0)
    {
        printf("No non zero elements present in the matrix !!\n");
    }
    traverse(l);
    delete (l, 1, 3);
    traverse(l);
    return 0;
}

void traverse(Linkedlist *l)
{
    Node *temp = l->head;
    while (temp != NULL)
    {
        printf("%d, ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    return;
}

void addAtBeginning(Linkedlist *l, int x, int row, int col)
{
    Node *newnode = malloc(sizeof(Node));
    newnode->data = x;
    newnode->column = col;
    newnode->row = row;
    if (l->head == NULL)
    {
        newnode->next = NULL;
    }
    else
    {
        newnode->next = l->head;
    }
    l->head = newnode;
}

void delete(Linkedlist *l, int row, int col)
{
    row--;
    col--;
    Node *temp = l->head;
    if (temp == NULL)
    {
        return;
    }
    Node *temp2;
    while ((temp->column != col) && (temp->row != row))
    {
        temp2 = temp;      // before
        temp = temp->next; // that
    }
    temp2->next = temp->next;
    free(temp);
}