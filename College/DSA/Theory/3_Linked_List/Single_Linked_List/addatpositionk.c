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
void addAtposK(Linkedlist *l, int k, int x);

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
    addAtposK(l,2,21);
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

void addAtposK(Linkedlist *l, int k, int x)
{
    Node *newnode = malloc(sizeof(Node));
    newnode->data = x;
    if(l->head == NULL && k == 1){
        l->head = newnode;
        newnode->next = l->head->next;
        return;
    }
    else {
        Node* temp = l->head;
        while ((temp != NULL) && --k!=1 )
        {
            temp = temp->next;
        }
        if(temp == NULL){
            printf("Not in range !!\n");
            return;
        }
        newnode->next = temp->next;
        temp->next = newnode; 
    }
}
