#include "stdio.h"
#include "stdlib.h"
struct node
{
  struct node *next;
  int value;
};

struct node * deleteAtFirst(struct node *head)
{
  struct node * ptr = head; // creating an extra copy just for the free() function to work and to also return the updated head
  head = head->next;
  free(ptr);
  return head;
}

void deleteAtIndex(struct node *head, int index)
{
  int c = 1;
  struct node *ptr = head;
  while(c<(index-1))
  {
    ptr = ptr -> next;
    c++;
  }
  struct node *nextptr = ptr->next;
  struct node *next_p = nextptr->next;
  free(nextptr);
  // nextptr = nextptr->next;
  ptr->next = next_p;
  
  
}

void deleteLast(struct node *head)
{
  struct node *ptr = head;
  struct node *ptr2 = head->next;
  while(ptr2->next != NULL)
  {
    ptr = ptr->next;
    ptr2 = ptr2->next;
  }

  ptr->next = NULL;


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

  // display(head);
  // head = deleteAtFirst(head);
  display(head);
  deleteAtIndex(head, 3);
  display(head);
  deleteLast(head);
  display(head);
  return 0;
}