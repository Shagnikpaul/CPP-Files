#include "stdio.h"
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct DoublyLinkedList
{
    Node *head;
    Node *tail;
} DoublyLinkedList;

void displayDLforward(DoublyLinkedList *l);
void displayDLreverse(DoublyLinkedList *l);

int main()
{
    //// write da code here...
    Node *one;
    one = malloc(sizeof(Node));
    one->data = 1;
    one->prev = NULL;

    Node *two;
    two = malloc(sizeof(Node));
    two->data = 2;
    two->prev = one;

    Node *three;
    three = malloc(sizeof(Node));
    three->data = 3;
    three->prev = two;

    Node *four;
    four = malloc(sizeof(Node));
    four->data = 4;
    four->prev = three;
    four->next = NULL;

    one->next = two;
    two->next = three;
    three->next = four;

    DoublyLinkedList *d;
    d = malloc(sizeof(DoublyLinkedList));
    d->head = one;
    d->tail = four;

    displayDLforward(d);
    displayDLreverse(d);
    return 0;
}

void displayDLforward(DoublyLinkedList *l)
{
    if (l->head == NULL)
    {
        printf("List is empty !!\n");
        return;
    }

    Node *t = l->head;
    while (t != NULL)
    {
        printf("%d, ", t->data);
        t = t->next;
    }
    printf("\n");
}

void displayDLreverse(DoublyLinkedList *l)
{
    if (l->tail == NULL)
    {
        printf("List is empty !!\n");
        return;
    }
    Node *t = l->tail;
    while (t != NULL)
    {
        printf("%d, ", t->data);
        t = t->prev;
    }
    printf("\n");
}
