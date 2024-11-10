#include <iostream>
#include <stdlib.h>
using namespace std;
int sz = 5;
int cnt = 0;
struct node
{
    int data;
    struct node *next;
} *head, *tail, *newnode, *temp;

void enqueue()
{
    if (cnt < sz)
    {
        cnt++;
        newnode = (struct node *)malloc(sizeof(struct node));
        cout << "Enter the element to enqueue: ";
        cin >> newnode->data;
        newnode->next = NULL;
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
    }
    else
    {
        cout << "Queue overflow!" << endl;
    }
}
void dequeue()
{
    if (head == NULL)
        cout << "Queue empty";
    else
    {
        temp = head;
        head = head->next;
        cout << "Popped element is: " << temp->data << endl;
    }
}
void display()
{
    if (head == NULL)
        cout << "Queue Underflow!";
    else
    {
        temp = head;
        while (temp != tail->next)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}
int main()
{
    enqueue();
    enqueue();
    enqueue();
    enqueue();
    enqueue();
    display();
    enqueue();
    dequeue();
    display();
    dequeue();
    display();
    dequeue();
    display();
    dequeue();
    display();
    dequeue();
    display();
}