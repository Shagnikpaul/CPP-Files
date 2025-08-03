#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *insertAtBegin(struct Node *head, int data){
    struct Node *ptr =(struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next=head->next;
    head->next = ptr;
    return head;
}
struct Node *insertAtEnd(struct Node *head, int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    while (p->next!=NULL)
    {
        p = p->next;
    }
    ptr->data=data;
    p->next = ptr;
    ptr->next=NULL;
    return head;
    
}
struct Node *deleteAtbegin(struct Node *head){
    struct Node *p=head->next;
    head->next=p->next;
    free(p);
    return head;

}
struct Node *deleteAtEnd(struct Node *head){
    struct Node *p = head;
    struct Node *q = p->next;
    while (q->next!=NULL)
    {
        q = q->next;
        p = p->next;
    }
    p->next = NULL;
    free(q);
    return head;

}
struct Node *deleteNode(struct Node *head, int index){
    struct Node *p = head;
    struct Node *q = p->next;
    int i=0;
    while (i!=index-1)
    {
        p=p->next;
        q=q->next;
        i++;
    }
    p->next=q->next;
    free(q);
    return head;
}
struct Node *display(struct Node* head){
    struct Node *ptr = head;
    while (ptr!=NULL)
    {
        printf("%d ",ptr->next->data);
        ptr=ptr->next;
    }
    printf("\n");
}

int main(){
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *first = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));

    head->next=first;
    
    first->data = 10;
    first->next = second;

    second->data = 20;
    second->next = NULL;


    insertAtBegin(head, 30);
    insertAtEnd(head, 40);
    // deleteAtbegin(head);
    // deleteAtbegin(head);
    // deleteAtEnd(head);
    deleteNode(head, 4);
    deleteNode(head,1);
    display(head);
    return 0;
}