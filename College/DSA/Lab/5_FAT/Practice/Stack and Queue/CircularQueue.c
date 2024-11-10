// Implementation of Circular Queue
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INT_MIN -99999

typedef struct CircularQUEUE
{
    int *array;
    int rear;
    int front;
    int size;
    int max_size;
} myQueue;

myQueue *init_Queue(int max_size);
void enQueue(myQueue *q, int x);
int deQueue(myQueue *q);
void show_queue(myQueue *q);
void printQueue(myQueue *Q);
bool isQueueOverflow(myQueue *q);
bool isQueueUnderflow(myQueue *q);

int main()
{
    myQueue *q;
    int choice = 0, x, max_size;
    scanf("%d", &max_size);
    while (1)
    {
        scanf("%d", &choice);
        // printf("Choice=%d\n", choice);
        if (choice == 0)
        {
            q = init_Queue(max_size);
            // printQueue(q);
        }
        else if (choice == 1)
        {
            // printf("Enter the elements to be inserted \n");
            scanf("%d", &x);
            enQueue(q, x);
            // printQueue(q);
            // show_queue(q);
        }
        else if (choice == 2)
        {
            // Delete element
            x = deQueue(q);
            if (x != INT_MIN)
                printf("%d\n", x);
        }
        else if (choice == 3)
        {
            printf("%d\n", isQueueOverflow(q));
        }
        else if (choice == 4)
        {
            // print queue items
            show_queue(q);
        }
        else if (choice == 5)
        {
            printf("%d\n", isQueueUnderflow(q));
        }
        else if (choice == 9)
            break;
        else
            printf("Invalid choice\n");
    }
    return 0;
}

myQueue *init_Queue(int max_size)
{
    // Fill your code here

    myQueue *q;
    q = malloc(sizeof(myQueue));

    if (q == NULL)
    {
        return NULL;
    }

    q->array = malloc(max_size * sizeof(int));
    if (!q->array)
    {
        free(q);
        return NULL;
    }

    q->max_size = max_size;
    q->front = -1;
    q->rear = -1;
    q->size = 0;
    return q;
}
void printQueue(myQueue *Q)
{
    printf("\n Queue structure details: \n");
    printf("\t Queue Adress: %p\n", Q);
    printf("\t Q->array:%p\n", Q->array);
    printf("\t Q->max_size:%d\n", Q->max_size);
    printf("Q->front: %d, Q->rear: %d \n", Q->front, Q->rear);
    printf("\n");
}

// fill your code here!
void enQueue(myQueue *Q, int x)
{
    // Fill your code here
    if (isQueueOverflow(Q))
    {
        printf("Queue Overflow\n");
        return;
    }
    else
    {
        if (Q->front == -1)
        {
            Q->front = 0;
            Q->rear = 0;
        }
        else
        {
            Q->rear = (Q->rear + 1) % Q->max_size;
        }
        Q->array[Q->rear] = x;
    }
}

// fill your code here
int deQueue(myQueue *Q)
{
    // Fill your code here
    if (isQueueUnderflow(Q))
    {
        printf("Queue Underflow\n");
        return INT_MIN;
    }
    else
    {
        int x = Q->array[Q->front];
        if (Q->front == Q->rear)
        {
            Q->front = -1;
            Q->rear = -1;
        }
        else
        {
            Q->front = (Q->front + 1) % Q->max_size;
        }
        return x;
    }
}

// fill your code here
void show_queue(myQueue *Q)
{
    // Fill your code here

    if (Q->front > Q->rear)
    {

        for (int i = Q->front; i < Q->max_size; i++)
        {

            printf("%d, ", Q->array[i]);
        }

        for (int i = 0; i <= Q->rear; i++)
        {
            if (i != (Q->rear))
                printf("%d, ", Q->array[i]);
            else
                printf("%d\n", Q->array[i]);
        }
    }
    else
    {
        for (int i = Q->front; i <= Q->rear; i++)
        {
            if (i != Q->rear)
                printf("%d, ", Q->array[i]);
            else
                printf("%d\n", Q->array[i]);
        }
    }
}

bool isQueueOverflow(myQueue *Q)
{
    // Fill your code here
    if ((Q->rear + 1) % Q->max_size == Q->front)
        return 1;
    else
        return 0;
}
bool isQueueUnderflow(myQueue *Q)
{
    // Fill your code here
    if (Q->front == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}