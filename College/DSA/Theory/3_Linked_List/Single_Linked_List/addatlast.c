#include "stdio.h"
#include "stdlib.h"

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct linkedlist
{
    Node *head;

} Linkedlist;

void traverse(Linkedlist *l);
void addAtLast(Linkedlist *l, int x);

int main()
{

    // sample data
    // head
    Node *one;
    one = malloc(sizeof(Node));
    one->data = 1;

    Node *two;
    two = malloc(sizeof(Node));
    two->data = 2;

    Node *three;
    three = malloc(sizeof(Node));
    three->data = 3;

    Node *four;
    four = malloc(sizeof(Node));
    four->data = 4;

    one->next = two;
    two->next = three;
    three->next = four;
    four->next = NULL;

    Linkedlist *l;
    l = malloc(sizeof(Linkedlist));
    l->head = one;

    traverse(l);
    addAtLast(l, 34);
    printf("\n");
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

    return;
}

void addAtLast(Linkedlist *l, int x)
{
    Node *newnode = malloc(sizeof(Node));
    newnode->data = x;
    newnode->next = NULL;
    if(l->head == NULL){
        l->head = newnode;
    }
    else {
        Node* temp = l->head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode; 
    }
}
