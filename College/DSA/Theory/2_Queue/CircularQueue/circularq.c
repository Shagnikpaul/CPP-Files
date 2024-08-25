#include "stdio.h"
#include "stdlib.h"
/*
Basic Circular queue defination...
*/
typedef struct CircularQueue
{
    int *arr;
    int front;
    int back;
    int size;
} CircularQueue;

/*
#### Algorithm to check if the queue is full.
In order to check if the queue is full see what the next element is after the current rear pointer if the next element is front of the circular queue then the queue must be full since we came back to same position after one round so a full round was made.

#### Adding an element to the queue.
In order to add an element do circular increment then add it by assignment...
*/
void enqueue(CircularQueue *q, int x);

int dequeue(CircularQueue *q);

void display(CircularQueue *q);

int main()
{
    int max_size = 3;
    CircularQueue *q;
    q = malloc(sizeof(CircularQueue));
    q->size = max_size;
    q->arr = malloc(sizeof(int) * max_size);
    q->front = q->back = -1;
    enqueue(q, 23);
    enqueue(q, 233);
    enqueue(q, 123);
    enqueue(q, 93);
    int k = dequeue(q);
    printf("Removed %d\n", k);
    printf("back is now %d and front is %d\n", q->back, q->front);
    enqueue(q, 3);
    enqueue(q, 44);
    k = dequeue(q);
    printf("Removed %d\n", k);
    k = dequeue(q);
    printf("Removed %d\n", k);
    k = dequeue(q);
    printf("Removed %d\n", k);
    k = dequeue(q);
    printf("Removed %d\n", k);
    enqueue(q, 100);
    enqueue(q, 100);
    enqueue(q, 100);
    enqueue(q, 100);
    return 0;
}

void enqueue(CircularQueue *q, int x)
{
    // printf("trying to add %d\n", x);
    if ((q->back + 1) % q->size == q->front)
    {
        printf("Queue is full !! : can't add %d\n", x);
    }
    else
    {
        if (q->front == -1)
        {
            q->front = 0;
            q->back = 0;
        }
        else
        {
            q->back = (q->back + 1) % q->size;
        }
        q->arr[q->back] = x;
        printf("added %d successfully and back is now %d and front is %d\n", x, q->back, q->front);
    }
}

int dequeue(CircularQueue *q)
{
    int a = -1;
    if (q->front == -1)
    {
        printf("Queue is empty !! \n");
        return a;
    }
    a = q->arr[q->front];
    //printf("a = %d\n", a);
    // if we have only one element in the queue right now then there is no use of incrementing front now we should reset front and rear value to re use the space...
    if (q->back == q->front)
    {
        q->front = q->back = -1;
    }
    else
    {
        q->front = (q->front + 1) % q->size;
    }
    return a;
}

void display(CircularQueue *q)
{
    for (int i = q->front; i <= q->back; i++)
    {
        printf("%d, ", q->arr[i]);
    }
    printf("\n\n");
}
