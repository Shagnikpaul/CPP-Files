
#include<iostream>
using namespace std;

struct node{
    string data[100];
    struct node* next;
}*head,*tail,*newnode,*temp;

void insert()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->next=NULL;
    for(int i=0;i<3;i++)
    {
        cout<<"Enter String: ";
        string input;
        cin>>input;
        newnode->data[i]=input;
    }
    if(head==NULL)
    {
        head=newnode;
        tail=head;
    }
    else{
        tail->next=newnode;
        tail=newnode;
    }
}
void reverse()
{
    temp=head;
    while(temp!=NULL)
    {
        string brr[3];
        for(int i=2;i>=0;i--)
        {
            brr[3-i-1]=temp->data[i];
        }


        for(int i=0;i<3;i++)
        {
            temp->data[i]=brr[i];
        }        
        temp=temp->next;
    }
}

void display()
{
    temp=head;
    if(head==NULL) cout<<"list is empty";
    while(temp!=NULL)
    {
        for(int i=0;i<3;i++)
        {
            cout<<temp->data[i]<<" ";
        }
        temp=temp->next;
    }
}

int main()
{
    head=NULL;
    insert();
    display();
}
