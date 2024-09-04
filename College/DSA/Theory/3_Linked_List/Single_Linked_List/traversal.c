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

void traverse(Node *head);

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

    
    traverse(one);
    return 0;
}

void traverse(Node *head)
{
    while (head != NULL)
    {
        printf("%d, ",head->data);
        head = head->next;
    }
    
    return;
}