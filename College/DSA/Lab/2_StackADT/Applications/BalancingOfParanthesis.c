#include "stdio.h"
#include "malloc.h"
#include "string.h"

typedef struct Stack
{
    char *array;
    int max_size;
    int top;
} Stack;
// calling struct Stack -> just Stack

Stack *init(int size);
void displayStack(Stack *s);
void push(Stack *s, char x);
char pop(Stack *s);
int isBalanced(char *str, int n, Stack *s);
char getOpener(char ch);

int main()
{
    char s[40];
    printf("Enter expression : \n");
    fgets(s, 40, stdin);
    Stack *st = init(strlen(s));
    printf("Balanced ? %d\n", isBalanced(s, strlen(s), st));
}

char getOpener(char ch)
{
    char s;
    switch (ch)
    {
    case ')':
        s = '(';
        break;
    case '}':
        s = '{';
        break;
    case ']':
        s = '[';
        break;
    }
    return s;
}

int isBalanced(char *str, int n, Stack *s)
{
    int k = 0;
    while (k < n)
    {
        if (str[k] == '(' || str[k] == '{' || str[k] == '[')
        {
            push(s, str[k]);
        }
        else if (str[k] == ')' || str[k] == '}' || str[k] == ']')
        {
            char ch = pop(s);
            if (ch != getOpener(str[k]))
                return 0;
        }
        k++;
    }
    if (s->top != -1)
        return 0;
    else
        return 1;
}

Stack *init(int size)
{
    Stack *s;
    s = malloc(sizeof(Stack));
    if (s == NULL)
    {
        return NULL;
    }

    s->array = malloc(size * sizeof(int));
    if (s->array == NULL)
    {
        free(s);
        return NULL;
    }

    s->max_size = size - 1;
    s->top = -1;

    return s;
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

void push(Stack *s, char x)
{
    if (s->top < (s->max_size - 1))
    {
        s->top++;
        s->array[s->top] = x;
    }
    else
    {
        printf("Stack overflow ! \n");
    }
}

char pop(Stack *s)
{

    if (s->top == -1)
    {
        printf("Stack underflow !\n");
        return '9';
    }
    else
    {
        int poppedElement = s->array[s->top];
        s->top--;
        return poppedElement;
    }
}