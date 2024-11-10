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
void addAtBeginning(DoublyLinkedList *l, int data);
void addAtEnd(DoublyLinkedList *l, int data);
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
    addAtEnd(d, 23);
    addAtEnd(d, 2300);
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

void addAtBeginning(DoublyLinkedList *l, int data)
{
    Node *t;
    t = malloc(sizeof(Node));
    t->data = data;
    t->next = l->head;
    t->prev = NULL;
    l->head->prev = t;
    l->head = t;
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

void addAtEnd(DoublyLinkedList *l, int data)
{

    Node *t;
    t = malloc(sizeof(Node));
    t->data = data;

    if (l->head == NULL)
    {
        t->next = NULL;
        t->prev = NULL;
        l->head = t;
        l->tail = t;
        return;
    }

    if (l->head->next == NULL)
    {
        t->prev = l->head;
        t->next = NULL;
        l->tail = t;
        return;
    }

    Node *temp;
    temp = l->head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = t;
    t->prev = temp;
    l->tail = t;
}
