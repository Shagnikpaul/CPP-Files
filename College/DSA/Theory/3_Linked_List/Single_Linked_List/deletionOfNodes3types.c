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
void deleteAtBeginning(Linkedlist *l);
void deleteAtLast(Linkedlist *l);
void deleteAtPosition(Linkedlist *l, int pos);

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
    deleteAtPosition(l,5);
    traverse(l);
    return 0;
}

void traverse(Linkedlist *l)
{
    Node *temp = l->head;
    if (temp == NULL)
    {
        printf("Linked List is empty !!\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d, ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return;
}

void deleteAtBeginning(Linkedlist *l)
{
    if (l->head == NULL)
    {
        printf("List is empty !! cant delete anymore.\n");
        return;
    }

    Node *temp = l->head;
    l->head = l->head->next;
    free(temp);
}

void deleteAtLast(Linkedlist *l)
{
    if (l->head == NULL)
    {
        printf("List is empty !! cant delete anymore.\n");
        return;
    }
    else if (l->head->next == NULL)
    {
        Node *t = l->head;
        l->head = NULL;
        free(t);
        return;
    }

    Node *temp = l->head;
    Node *temp2 = l->head;
    while (temp->next != NULL)
    {
        temp2 = temp;
        temp = temp->next;
    }
    temp2->next = NULL;
    free(temp);
}

void deleteAtPosition(Linkedlist *l, int pos)
{
    if (l->head == NULL)
    {
        printf("List is empty !! cant delete anymore.\n");
        return;
    }

    if (pos == 1)
    {
        Node *temp = l->head;
        l->head = l->head->next;
        free(temp);
        return;
    }

    int count = 1;

    Node *t = l->head;
    Node *t2 = l->head;
    while (t != NULL && (count <= (pos - 1)))
    {
        t2 = t;
        t = t->next;
        count++;
    }

    if (t == NULL)
    {
        printf("Out of range position\n");
        return;
    }
    t2->next = t->next;
    free(t);
}
