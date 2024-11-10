// Implementation of Linear Queue
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define INT_MIN -9999


typedef struct QUEUE
{
    int *array;
    int rear; int front;
    int size; int max_size;
} myQueue; 

myQueue* init_Queue(int max_size);
void enQueue(myQueue * q, int x);
int deQueue(myQueue *q);
void show_queue(myQueue *q);
void printQueue(myQueue *Q);
bool isQueueOverflow(myQueue *q);
bool isQueueUnderflow(myQueue *q);


int main()
{
    myQueue *q;
    int choice=0, x, max_size;
    scanf("%d", &max_size);
    while(1)
    {   
        scanf("%d", &choice);
        // printf("Choice=%d\n", choice);
        if(choice==0)
        {
               q = init_Queue(max_size);
               // printQueue(q);
        }
        else if(choice==1)
        {     
               // printf("Enter the elements to be inserted \n");
                scanf("%d", &x);
                enQueue(q, x);
                // printQueue(q);
                //show_queue(q);
             
        }
        else if(choice==2)
        {
                // Delete element
                x = deQueue(q);
                if(x!= INT_MIN)
                    printf("%d\n", x);
               
        }
        else if(choice ==3)
        {
            printf("%d\n", isQueueOverflow(q));
        }
        else if(choice==4)
        {
                // print queue items
                show_queue(q);
                
        }
        else if(choice ==5)
        {
             printf("%d\n", isQueueUnderflow(q));
        }
        else if(choice ==9)
            break;
        else
            printf("Invalid choice\n");
    }
    return 0;
}


myQueue* init_Queue(int max_size)
{
    // Fill Your COde here
    myQueue* q;
    q = malloc(sizeof(myQueue));
    if(!q){
        return NULL;
    }
    
    q->array = malloc(max_size*sizeof(int));
    if(!q->array){
        free(q);
        return NULL;
    }
    q->rear = -1;
    q->front = -1;
    q->max_size = max_size;
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
    // Fill Your COde here
    if(isQueueOverflow(Q)){
        printf("Queue Overflow\n");
        return;
    }
    else {
        if(Q->front == -1){
            Q->front = 0;
        }
        Q->rear++;
        Q->array[Q->rear] = x;
    }
}


// fill your code here
int deQueue(myQueue *Q)
{
    // Fill Your COde here
    
    if(isQueueUnderflow(Q)){
        printf("Queue Underflow\n");
        return INT_MIN;
    }
    else {
        int x = Q->array[Q->front];
        Q->front++;
        return x;
    }
}

// fill your code here
void show_queue(myQueue *Q)
{
    // Fill Your COde here
    if(!isQueueUnderflow(Q)){
        for(int i=Q->front;i<=Q->rear;i++){
            if(i != Q->rear)
            printf("%d, ",Q->array[i]);
            else
            printf("%d\n",Q->array[i]);
            
        }
    }
}

bool isQueueOverflow(myQueue *Q)
{
    // Fill Your COde here
    if(Q->rear == (Q->max_size - 1)){
        return true;
    }
    else {
        return false;
    }

}
bool isQueueUnderflow(myQueue *Q)
{
    // Fill Your COde here
    if(Q->front == -1 || (Q->front > Q->rear)){
        return true;
    }
    else {
        return false;
    }
}