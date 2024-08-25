#include "stdio.h"
#include <stdlib.h>

typedef struct Queue
{
    int *arr;
    int max_size;
    int front;
    int back;
} Queue;

Queue *init(Queue *q, int max);
void enqueue(Queue *q, int x);
int dequeue(Queue *q);
void display(Queue *q);
int isFull(Queue *q);
int isEmpty(Queue *q);

int main()
{
    //// write da code here...
    int n;
    printf("Enter the size of the queue you want: ");
    scanf("%d", &n);
    Queue *q;
    q = init(q, n);
    printf("front = %d and back = %d and max size = %d\n\n\n", q->front, q->back, q->max_size);
    int flag = 1;
    int ele;
    while (flag)
    {
        int choice;
        printf("Enter 1 to add elements to the queue.\n");
        printf("Enter 2 to remove elements from the queue.\n");
        printf("Enter 3 to display the elements of the queue.\n");
        printf("Enter any other number to exit the program.\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (!isFull(q))
            {
                printf("Enter the number you want to insert to queue : ");
                scanf("%d", &ele);
            }
            else
            {
                ele = -1;
            }
            enqueue(q, ele);
            break;
        case 2:
            ele = dequeue(q);
            if (ele != -1)
            {
                printf("Removed %d\n", ele);
            }
            break;
        case 3:
            display(q);
            break;
        default:
            flag = 0;
            break;
        }
    }
    return 0;
}

Queue *init(Queue *q, int max)
{
    q = malloc(sizeof(Queue));
    if (q == NULL)
    {
        return NULL;
    }

    q->arr = (int *)malloc(sizeof(int) * max);
    if (q == NULL)
    {
        free(q);
        return NULL;
    }

    q->front = -1;
    q->back = -1;
    q->max_size = max;
    return q;
}

void enqueue(Queue *q, int x)
{
    if (isFull(q))
    {
        printf("Queue is full !!\n\n");
        return;
    }
    if (q->front == -1 && q->back == -1)
    {
        q->front = 0;
        q->back = 0;
        q->arr[q->back] = x;
        return;
    }
    q->back++;
    q->arr[q->back] = x;
    printf("\nback is %d\n\n", q->back);
}

int dequeue(Queue *q)
{

    if (isEmpty(q))
    {
        printf("Queue is already empty !!\n\n");
        return -1;
    }
    int a = q->arr[q->front];
    q->front++;
    return a;
}

void display(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty !!\n\n");
        return;
    }
    for (int i = q->front; i <= q->back; i++)
    {
        printf("%d, ", q->arr[i]);
    }
    printf("\n\n");
}

int isFull(Queue *q)
{
    if ((q->back) == (q->max_size - 1))
    {
        return 1;
    }
    return 0;
}

int isEmpty(Queue *q)
{
    if (q->back==q->front)
    {
        q->front = -1;
        q->back = -1;
        return 1;
    }
    return 0;
}
