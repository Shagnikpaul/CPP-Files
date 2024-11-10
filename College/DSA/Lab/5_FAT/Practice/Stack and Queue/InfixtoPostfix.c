#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include <malloc.h>

#include <sys/types.h> // for ssize_t

// header for boolean data types true/false
#include <stdbool.h>

#define CHAR_MIN_T '\0'

// defining a new user-defined
// data type STACK -> mySTACK
typedef struct STACK
{
    char *array;
    int max_size;
    int top;
} mySTACK;

// operation supported on STACK
mySTACK *init_stack(int max_size);
void push(mySTACK *s, char x);
void show_stack(mySTACK *s);
char pop(mySTACK *s);
char get_top(mySTACK *s);
void delete_stack(mySTACK *s);
bool check_stack_overflow(mySTACK *s);
bool check_stack_underflow(mySTACK *s);

bool isBalanced(const char *str, ssize_t max_size);

// Custom getline function
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);

int precedence(char op);
void infixToPostfix(const char *infix, char *postfix, ssize_t max_size);

int main()
{
    char *infix = NULL;
    char *postfix = NULL;

    size_t len = 0;
    ssize_t nread;

    // printf("Enter a line of text (Ctrl+D to end input):\n");
    nread = my_getline(&infix, &len, stdin);

    if (nread != -1)
    {

        //  printf("You entered: %s\n", line);
    }
    else
    {
        printf("Error or end of file.\n");
    }

    postfix = malloc(sizeof(char) * (nread + 1));
    infixToPostfix(infix, postfix, nread);
    printf("%s\n", postfix);

    return 0;
}

// Return precedence of operators
int precedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

// Convert infix expression to postfix expression
void infixToPostfix(const char *infix, char *postfix, ssize_t max_size)
{
    // Fill your code here

    mySTACK *s;
    s = init_stack(max_size);
    int k = 0;
    int p = 0;

    while (k < max_size)
    {
        char c = infix[k];
        if (c == '\n')
        {
            break;
        }

        switch (c)
        {
        case '*':
        case '/':
        case '+':
        case '-':
        case '^':
            if (get_top(s) == '(')
            {
                push(s, c);
            }
            else if (precedence(c) > precedence(get_top(s)))
            {
                push(s, c);
            }
            else
            {
                while (precedence(c) <= precedence(get_top(s)) && (s->top != -1))
                {
                    char u = pop(s);
                    postfix[p++] = u;
                }
                push(s, c);
            }
            break;

        case '(':
            push(s, c);
            break;

        case ')':
            while (get_top(s) != '(' && (s->top != -1))
            {
                postfix[p++] = pop(s);
            }

            if (get_top(s) == '(')
            {
                pop(s);
            }
            break;

        case ' ':
            break;

        default:
            postfix[p++] = c;
            break;
        }
        k++;
    }
    while (s->top != -1)
    {
        postfix[p++] = pop(s);
    }
}

// STACK

mySTACK *init_stack(int size)
{
    mySTACK *s;
    s = malloc(sizeof(mySTACK));
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

void displayStack(mySTACK *s)
{
    if (s->top == -1)
    {
        // printf("Stack is empty ! \n");
        return;
    }
    // printf("Stack elements : ");
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d, ", s->array[i]);
    }
    printf("\n\n");
}

void push(mySTACK *s, char x)
{
    if (s->top < (s->max_size - 1))
    {
        s->top++;
        s->array[s->top] = x;
    }
    else
    {
        // printf("Stack overflow ! \n");
    }
}

char pop(mySTACK *s)
{

    if (s->top == -1)
    {
        // printf("Stack underflow !\n");
        return CHAR_MIN_T;
    }
    else
    {
        int poppedElement = s->array[s->top];
        s->top--;
        return poppedElement;
    }
}

char get_top(mySTACK *s)
{
    if (s->top == -1)
    {
        return CHAR_MIN_T;
    }
    else
    {
        return s->array[s->top];
    }
}

// Custom getline function
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
    if (lineptr == NULL || n == NULL || stream == NULL)
    {
        return -1; // Invalid arguments
    }

    // Initialize buffer if it is NULL
    if (*lineptr == NULL)
    {
        *n = 0;                         // Initialize size to 0
        *lineptr = (char *)malloc(128); // Start with an initial buffer size
        if (*lineptr == NULL)
        {
            return -1; // Allocation failed
        }
        *n = 128;
    }

    size_t pos = 0;
    int c;

    while ((c = fgetc(stream)) != EOF)
    {
        // Check if the buffer needs to be resized
        if (pos >= *n - 1)
        {
            size_t new_size = *n * 2;
            char *new_lineptr = (char *)realloc(*lineptr, new_size);
            if (new_lineptr == NULL)
            {
                return -1; // Allocation failed
            }
            *lineptr = new_lineptr;
            *n = new_size;
        }

        (*lineptr)[pos++] = (char)c;

        // Break on newline character
        if (c == '\n')
        {
            break;
        }
    }

    // Handle end-of-file or empty input
    if (pos == 0 && c == EOF)
    {
        return -1; // No input read
    }

    (*lineptr)[pos] = '\0'; // Null-terminate the string

    return (ssize_t)pos;
}
