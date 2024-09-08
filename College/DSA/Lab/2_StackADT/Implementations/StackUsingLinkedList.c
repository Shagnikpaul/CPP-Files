#include "stdio.h"
#include "stdlib.h"

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct linkedlist
{
    Node *top;
    int current_size;
} Stack;

void push(Stack *s, int x);
int pop(Stack *s);
void displayStack(Stack *s);
Stack *init();

int main()
{

    // sample data
    // head

    Stack *s;
    s = init();
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 77);
    printf("Popped : %d\n", pop(s));
    printf("Popped : %d\n", pop(s));
    printf("Popped : %d\n", pop(s));
    printf("Popped : %d\n", pop(s));
    printf("Popped : %d\n", pop(s));
    push(s, 77);
    push(s, 88);
    push(s, 100);
    displayStack(s);
    return 0;
}

Stack *init()
{
    Stack *s = malloc(sizeof(Stack));
    s->current_size = 0;
    return s;
}

void displayStack(Stack *s)
{
    if (s->top == NULL)
    {
        printf("Stack is Empty !!\n");
    }
    Node *temp;
    temp = s->top;
    while (temp != NULL)
    {
        if (temp->next == NULL)
            printf("%d\n", temp->data);
        else
            printf("%d, ", temp->data);
        temp = temp->next;
    }
    return;
}

void push(Stack *s, int x)
{
    Node *n = malloc(sizeof(Node));
    n->data = x;
    if (s->top == NULL)
    {
        s->top = n;
        n->next = NULL;
    }
    else
    {
        n->next = s->top;
        s->top = n;
    }
}

int pop(Stack *s)
{
    if (s->top == NULL)
    {
        return -9999;
    }
    else
    {
        int x = s->top->data;
        s->top = s->top->next;
        return x;
    }
}