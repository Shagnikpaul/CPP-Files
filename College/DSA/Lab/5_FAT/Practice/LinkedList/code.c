#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int data;
    struct ListNode *next;
} ListNode;

typedef struct LinkList
{
    ListNode *head;
} LinkList;

LinkList *init_link_list();
void traverse_link_list(LinkList *l1);
void insertAtBeg(LinkList *l, int data);
void insertAtLast(LinkList *l, int data);
int deleteAtFirst(LinkList *l);
int deleteAtLast(LinkList *l);
void printList(LinkList *l);

int main()
{
    LinkList *l;
    int choice = 0, x;
    l = init_link_list();
    while (1)
    {
        scanf("%d", &choice);
        // printf("Choice=%d\n", choice);
        // For initialization of link list
        if (choice == 0)
        {
            l = init_link_list();
            // printf("l = %p, l->head=%p\n", l, l->head);
        }
        else if (choice == 1)
        { // insert at begining
            // printf("Enter the elements to be inserted \n");
            scanf("%d", &x);
            insertAtBeg(l, x);
        }
        else if (choice == 2)
        {
            // insert at last
            scanf("%d", &x);
            insertAtLast(l, x);
            // printList(head);
        }
        else if (choice == 3)
        {
            // print link list elements seperated by comma and space
            printList(l);
        }
        else if (choice == 5)
        {
            int k = deleteAtFirst(l);
            printf("%d\n", k);
        }
        else if (choice == 6)
        {
            int k = deleteAtLast(l);
            printf("%d\n", k);
        }
        else
            break;
    }
    return 0;
}

LinkList *init_link_list()
{
    LinkList *l1;
    l1 = malloc(sizeof(LinkList));
    if (l1 == NULL)
        return NULL;
    l1->head = NULL;
    return l1;
}

void insertAtBeg(LinkList *l, int x)
{

    // Write your code here!

    ListNode *node;
    node = malloc(sizeof(ListNode));
    node->data = x;

    if (l->head == NULL)
    {
        node->next = NULL;
    }
    else
    {
        node->next = l->head;
    }

    l->head = node;
}

void printList(LinkList *l)
{
    if (l->head == NULL)
    {
        return;
    }
    ListNode *temp = l->head;
    while (temp != NULL)
    {
        if (temp->next == NULL)
            printf("%d", temp->data);
        else
            printf("%d, ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertAtLast(LinkList *l, int x)
{
    // Write your code here!

    ListNode *node;
    node = malloc(sizeof(ListNode));
    node->data = x;
    node->next = NULL;

    if (l->head == NULL)
    {
        l->head = node;
        return;
    }

    ListNode *temp = l->head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = node;
}

int deleteAtFirst(LinkList *l)
{
    if (l->head == NULL)
        return 0;

    int x = l->head->data;
    ListNode *t = l->head;
    l->head = l->head->next;
    free(t);
    return x;
}
int deleteAtLast(LinkList *l)
{
    if (l->head == NULL)
        return 0;

    ListNode *t = l->head;
    ListNode *prev = NULL;
    while (t->next != NULL)
    {
        prev = t;
        t = t->next;
    }
    int x = t->data;
    prev->next = NULL;
    free(t);
    return x;
}
