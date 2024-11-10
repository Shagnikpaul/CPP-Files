/* To show the use of stack in function calls */
#include <stdio.h>
#include <malloc.h>

// header for boolean data types true/false
#include <stdbool.h>

#define INT_MIN -9999

// defining a new user-defined
// data type STACK -> mySTACK
typedef struct STACK
{
    int *array;
    int max_size;
    int top;
} mySTACK;

// operation supported on STACK
mySTACK *init_stack(int max_size);
void push(mySTACK *s, int x);
void show_stack(mySTACK *s);
int pop(mySTACK *s);
int get_top(mySTACK *s);
void delete_stack(mySTACK *s);
bool check_stack_overflow(mySTACK *s);
bool check_stack_underflow(mySTACK *s);

int main()
{
    int op_code, max_size;
    int new_element, poped_element;
    bool flag_empty, flag_full;

    scanf("%d", &max_size);
    mySTACK *s1 = NULL;
    while (1)
    {
        scanf("%d", &op_code);
        // printf("Op_code =%d\n", op_code);
        if (op_code == 0)
        {
            s1 = init_stack(max_size); // Calling init_STACK
        }
        else if (op_code == 1)
        {
            scanf("%d", &new_element);
            push(s1, new_element); // Calling push function on STACK
        }
        else if (op_code == 2)
        {
            poped_element = pop(s1); // Calling pop in STACK
            printf("%d\n", poped_element);
        }
        else if (op_code == 3)
        {
            flag_empty = check_stack_underflow(s1);
            printf("%d\n", flag_empty);
        }
        else if (op_code == 4)
        {
            show_stack(s1); // printing element of STACK
        }
        else if (op_code == 5)
        {
            flag_full = check_stack_overflow(s1);
            printf("%d\n", flag_full);
        }
        else if (op_code == 6)
        {
            int top_element = get_top(s1);
            printf("%d\n", top_element);
        }
        else if (op_code == 9)
            break; // break the infinite menu driven while loop
    }

    return 0;
}

mySTACK *init_stack(int max_size)
{
    mySTACK *s;
    // Allocate memory for stack
    s = malloc(sizeof(mySTACK));
    if (s == NULL)
        return NULL;
    // allocate memory for array
    s->array = malloc(sizeof(int) * max_size);
    // free the stack memory if array memory not allocated
    if (s->array == NULL)
    {
        free(s);
        return NULL;
    }
    // Assigning the max_size and top
    s->max_size = max_size;
    s->top = -1;
    return s;
}

void push(mySTACK *s, int x)
{
    // Write your code here!
    if (check_stack_overflow(s))
    {
        printf("STACK overflow\n");
        return;
    }
    else
    {
        s->top++;
        s->array[s->top] = x;
    }
}

void show_stack(mySTACK *s)
{
    // Write your code here!
    if (!check_stack_underflow(s))
    {
        for (int i = 0; i <= s->top; i++)
        {
            if (i != s->top)
                printf("%d, ", s->array[i]);
            else
                printf("%d\n", s->array[i]);
        }
    }
}

int pop(mySTACK *s)
{
    // Write your code here!
    if (check_stack_underflow(s))
    {
        printf("STACK Underflow\n");
        return INT_MIN;
    }
    else
    {
        int x = s->array[s->top];
        s->top--;
        return x;
    }
}

int get_top(mySTACK *s)
{
    // Write your code here!
    if (check_stack_underflow(s))
    {
        return INT_MIN;
    }
    else
    {
        return s->array[s->top];
    }
}

bool check_stack_overflow(mySTACK *s)
{
    // Write your code here!
    if (s->top == (s->max_size - 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool check_stack_underflow(mySTACK *s)
{
    // Write your code here!
    if (s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void delete_stack(mySTACK *s)
{
    if (s)
    {
        if (s->array)
            free(s->array);
        free(s);
    }
}