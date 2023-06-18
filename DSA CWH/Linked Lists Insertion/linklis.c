#include "stdio.h"
#include "stdlib.h"
struct node
{
  struct node *next;
  int value;
};

struct node * insertAtEnd(struct node *head, int num)
{
  struct node *p = head;
  while (p->next != NULL)
  {
    p = p->next;
  }
  struct node *new_node = (struct node *) malloc(sizeof(struct node));
  new_node->value = num;
  new_node->next = NULL;
  p->next = new_node;
  return head;
}

void insertAtIndex(struct node *head, int pos, int num)
{
  int c = 1;
  struct node *new_node = (struct node *) malloc(sizeof(struct node));
  new_node->value = num;
  while (c < (pos-1))
  {
    head = head->next;
    c++;
  }
  new_node->next = head->next;
  head->next = new_node;
}

struct node *insertAtBegin(struct node *head, int num)
{
  struct node *new_head = (struct node *)malloc(sizeof(struct node));
  new_head->next = head;
  new_head->value = num;
  return new_head;
}

void display(struct node *head)
{
  if (head->next == NULL)
  {
    printf("%d ", head->value);
    printf("\n\n");
    return;
  }
  else
  {
    printf("%d, ", head->value);
    display(head->next);
  }
}

int main()
{
  //// write da code here...
  // starting node  / head...

  struct node *head = (struct node *)malloc(sizeof(struct node));

  struct node *second = (struct node *)malloc(sizeof(struct node));

  struct node *third = (struct node *)malloc(sizeof(struct node));

  struct node *fourth = (struct node *)malloc(sizeof(struct node));

  struct node *fifth = (struct node *)malloc(sizeof(struct node));

  head->value = 21;
  head->next = second;
  second->value = 31;
  second->next = third;
  third->value = 91;
  third->next = fourth;
  fourth->value = 11;
  fourth->next = fifth;
  fifth->value = 61;
  fifth->next = NULL;

  display(head);
  head = insertAtBegin(head, 99);
  display(head);

  insertAtIndex(head, 2, 76);
  display(head);

  head = insertAtEnd(head, 65);
  display(head);

  return 0;
}