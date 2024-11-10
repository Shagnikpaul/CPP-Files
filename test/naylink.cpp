#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
} *tail, *newnode, *temp, *head;

void insert(int input)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = input;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
        tail = head;
    }
    else
    {
        tail->next = newnode;
        newnode->next = head;
        tail = newnode;
    }
}

void deleteend()
{
    temp = head;
    while (temp->next != tail)
    {
        temp = temp->next;
    }
    struct node *end;
    end = temp->next;
    tail = temp;
    temp->next = head;
    cout << "popped element is: " << end->data << endl;
    delete end;
}

void deleteAtEndRecursively(struct node *t)
{
    if (t->next == tail)
    {
        struct node *end;
        end = t->next;
        tail = t;
        t->next = head;
        cout << "popped element is: " << end->data << endl;
        delete end;
        return;
    }
    else
    {
        deleteAtEndRecursively(t->next);
    }
}

void displayRecursive(struct node *t)
{
    if (t == tail)
    {
        cout << t->data << ", ";
        cout << endl;
        return;
    }
    cout << t->data << ", ";
    displayRecursive(t->next);
}

void display()
{
    temp = head;
    while (temp != tail)
    {
        cout << temp->data << " ";
        temp = temp->next;
    };
    cout << tail->data << endl;
}

int main()
{
    insert(5);
    insert(7);
    insert(10);
    insert(20);
    displayRecursive(head);
    // deleteend();
    deleteAtEndRecursively(head);
    display();
    // insert(34);
}