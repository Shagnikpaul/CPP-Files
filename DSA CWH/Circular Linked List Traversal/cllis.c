#include "stdio.h"
#include "stdlib.h"


struct node
{
  struct node *next;
  int value;
};

int main()
{
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
  fifth->next = head;
    return 0;
}
