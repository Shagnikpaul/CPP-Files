#include "stdio.h"
#include <stdlib.h>
struct Node
{
  int value;
  struct Node *next;
};

void LinkedListTraversal(struct Node *head)
{
  if (head->next == NULL)
    printf("%d ", head->value);
  else
  {
    printf("%d ", head->value);
    LinkedListTraversal(head->next);
  }
}

int main()
{
  struct Node *head = (struct Node *)malloc(sizeof(struct Node));
  struct Node *second;
  struct Node *third;
  struct Node *fourth;

  // more nodes with linking...
  second = (struct Node *)malloc(sizeof(struct Node));
  third = (struct Node *)malloc(sizeof(struct Node));
  fourth = (struct Node *)malloc(sizeof(struct Node));
  head->value = 12;
  head->next = second;
  second->value = 13;
  second->next = third;
  third->value = 14;
  third->next = fourth;
  fourth->value = 15;
  fourth->next = NULL;
  LinkedListTraversal(head);
  return 0;
}
