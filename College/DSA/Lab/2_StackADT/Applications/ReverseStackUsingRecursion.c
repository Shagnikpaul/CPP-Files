#include "stdio.h"
#include "malloc.h"

typedef struct Stack
{
    int *array;
    int max_size;
    int top;
} Stack;
// calling struct Stack -> just Stack

Stack *init(int size);
void displayStack(Stack *s);
void push(Stack *s, int x);
int pop(Stack *s);
void reverseStack(Stack* s);
void insertAtBottom(Stack* s, int k);
int main()
{
    //// write da code here...
    Stack *s = init(4);
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    printf("OG Stack : \n");
    displayStack(s);
    reverseStack(s);
    printf("Reversed Stack : \n");
    displayStack(s);
    return 0;
}

Stack *init(int size)
{
    Stack *s;
    s = malloc(sizeof(Stack));
    if (s == NULL)
    {
        return NULL;
    }

    s->array = (int *)malloc(size * sizeof(int));
    if (s->array == NULL)
    {
        free(s);
        return NULL;
    }

    s->max_size = size - 1;
    s->top = -1;

    return s;
}

void reverseStack(Stack *s)
{
    if (s->top == -1)
    {
        return;
    }
    else
    {
        int k = pop(s);
        reverseStack(s);
        insertAtBottom(s,k);
    }
}


void insertAtBottom(Stack* s, int k){
    if(s->top == -1){
        push(s,k);
        return;
    }
    int temp = pop(s);
    insertAtBottom(s,k);
    push(s,temp);
}

void displayStack(Stack *s)
{
    if (s->top == -1)
    {
        printf("Stack is empty ! \n");
        return;
    }
    printf("Stack elements : ");
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d, ", s->array[i]);
    }
    printf("\n\n");
}

void push(Stack *s, int x)
{
    if (s->top <= (s->max_size - 1))
    {
        s->top++;
        s->array[s->top] = x;
    }
    else
    {
        printf("Stack overflow ! \n");
    }
}

int pop(Stack *s)
{

    if (s->top == -1)
    {
        printf("Stack underflow !\n");
        return -1;
    }
    else
    {
        int poppedElement = s->array[s->top];
        s->top--;
        return poppedElement;
    }
}