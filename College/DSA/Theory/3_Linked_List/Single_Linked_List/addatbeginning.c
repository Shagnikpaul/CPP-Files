#include "stdio.h"
#include "stdlib.h"

typedef struct Node
{
    int data;
    int row;
    int col;
    struct Node *next;
} Node;

typedef struct linkedlist
{
    Node *head;

} Linkedlist;

void traverse(Linkedlist *l);
void deleteAtBeginning(Linkedlist *l, int x);

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
    deleteAtBeginning(l, 80);
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

void deleteAtBeginnin(Strudent link, VowCon l), int x, char* name, char gradeint age)
{
    node n= mal
    n->name = 
    n-
    n->

    int con
    int vow

    for(int i=0;i<name;i++){
        name[i] == 'a'
        vow++;
        con++
    }
    Node n

}
{
    Node *newnode = malloc(sizeof(Node));
    newnode->data = x;
    newnode->next = l->head;
    l->head = newnode;
}
