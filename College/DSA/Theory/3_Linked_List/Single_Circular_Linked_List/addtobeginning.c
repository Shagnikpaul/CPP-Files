#include "stdio.h"
#include "stdlib.h"

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct circularlinkedlist
{
    Node *head;

} CircularLinkedList;

void traverse(CircularLinkedList *l);
void addatbeginning(CircularLinkedList *l, int x);

int main()
{
    //// write da code here...
    CircularLinkedList *c;
    c = malloc(sizeof(CircularLinkedList));
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
    four->next = one;

    c->head = one;
    traverse(c);
    traverse(c);
    return 0;
}

void traverse(CircularLinkedList *l)
{
    Node *temp = l->head;
    do
    {
        printf("%d, ", temp->data);
        temp = temp->next;
        /* code */
    } while (temp != l->head);
    printf("\n");
}

void addatbeginning(CircularLinkedList *l, int x)
{
    
}
