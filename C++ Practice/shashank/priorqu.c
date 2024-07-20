#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int front = -1, rear = -1, in_arr[SIZE];;

void input(int);
void delete_priority(int);
void check(int);
void display();

int main()
{
    int choice, n;
    while (1)
    {
        printf("\n1 - Insert an element into queue");
        printf("\n2 - Delete an element from queue");
        printf("\n3 - Display queue elements");
        printf("\n4 - Exit");
        printf("\nEnter the choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("\nEnter value to be inserted : ");
                scanf("%d",&n);
                input(n);
                break;
            case 2:
                printf("\nEnter value to delete : ");
                scanf("%d",&n);
                delete_priority(n);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice!!");

        }
    }
    return 0;
}



void input(int data)
{
    int n;
    if (rear >= SIZE - 1)
    {
        printf("\nOVERFLOW no more elements can insert ");
        return;
    }
    if ((front == -1) && (rear == -1))
    {
        front++;
        rear++;
        in_arr[rear] = data;
        return;
    }
    else
        check(data);
    rear++;
}

void check(int data)
{
    int i,j,n;

    for (i = 0; i <= rear; i++)
    {
        if (data >= in_arr[i])
        {
            for (j = rear + 1; j > i; j--)
            {
                in_arr[j] = in_arr[j - 1];
            }
            in_arr[i] = data;
            return;
        }
    }
    in_arr[i] = data;
}

void delete_priority(int data)
{
    int i;

    if ((front==-1) && (rear==-1))
    {
        printf("\nIt reached to the end of the array, no more elemnts ");
        return;
    }

    for (i = 0; i <= rear; i++)
    {
        if (data == in_arr[i])
        {
            for (; i < rear; i++)
            {
                in_arr[i] =in_arr[i + 1];
            }

        in_arr[i] = -99;

        rear--;

        if (rear == -1)
            front = -1;
        return;
        }
    }
    printf("\n%d No such element to delete in the array", data);
}

void display()
{
    if ((front == -1) && (rear == -1))
    {
        printf("\nNo Element found!!");
        return;
    }

    for (; front <= rear; front++)
    {
        printf(" %d ", in_arr[front]);
    }

    front = 0;
}