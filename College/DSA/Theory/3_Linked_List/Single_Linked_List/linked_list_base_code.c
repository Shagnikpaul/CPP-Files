#include "stdio.h"
#include "stdlib.h"

typedef struct Node
{
    int age;
    char name[100];
    char grade;

    struct Node *next;
} Node;



typedef struct VowConNode {
    int vow;
    int conl

} VowConNode;
typedef struct linkedlist
{
    Node *head;

} Linkedlist;

int main()
{
    //// write da code here...
    // declaring a new head
    Node *head;
    head = malloc(sizeof(Node));
    Node *temp = head;
    printf("Node address = %p and data = %d", temp, temp->data);

    return 0;
}