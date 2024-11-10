	/* To show the use of stack in function calls */	 	 	
#include<stdio.h>
#include<malloc.h>


#include <sys/types.h>
// header for boolean data types true/false
#include <stdbool.h>

#define CHAR_MIN '\0'



// defining a new user-defined
// data type STACK -> mySTACK
typedef struct STACK
{
    char *array;
    int max_size;
    int top;
}mySTACK;


// operation supported on STACK
mySTACK* init_stack(int max_size);
void push(mySTACK *s, char x);
void show_stack(mySTACK *s);
char pop(mySTACK *s);
char get_top(mySTACK *s);
void delete_stack(mySTACK *s);
bool check_stack_overflow(mySTACK *s);
bool check_stack_underflow(mySTACK *s);

bool isBalanced(const char* str, ssize_t max_size);

// Custom getline function
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);

int main()
{
    
    bool flag_balanced;

    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    // printf("Enter a line of text (Ctrl+D to end input):\n");
    nread = my_getline(&line, &len, stdin);

    if (nread != -1) {
        
       //  printf("You entered: %s\n", line);
    } else {
        printf("Error or end of file.\n");
    }


    flag_balanced = isBalanced(line, nread);
    if(flag_balanced)
    {
        printf("Balanced\n");

    }
    else
        printf("NOT Balanced\n");

    free(line);

   
    return 0;
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


// Function to check if the given string is balanced
bool isBalanced(const char* str,  ssize_t max_size) 
{
    // Fill  the code here
   mySTACK* s;
   s = init_stack(max_size);
   int k = 0;
   while(k<max_size){
       if(str[k] == '(' || str[k] == '[' || str[k] == '{'){
           push(s, str[k]);
       }
       else if(str[k] == '}' || str[k] == ')' || str[k] == ']'){
           char j = pop(s);
           if (j != getOpener(str[k])){
               return 0;
           }
       }
       k++;
   }
   if(s->top != -1){
       return 0;
   }
   else {
       return 1;
   }
}


//STACK

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
        //printf("Stack is empty ! \n");
        return;
    }
    //printf("Stack elements : ");
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
        //printf("Stack overflow ! \n");
    }
}

char pop(mySTACK *s)
{

    if (s->top == -1)
    {
        //printf("Stack underflow !\n");
        return '9';
    }
    else
    {
        int poppedElement = s->array[s->top];
        s->top--;
        return poppedElement;
    }
}




// Custom getline function to read a line of character array
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
    if (lineptr == NULL || n == NULL || stream == NULL) 
    {
        return -1;  // Invalid arguments
    }

    // Initialize buffer if it is NULL
    if (*lineptr == NULL) 
    {
        *n = 0; // Initialize size to 0
        *lineptr = (char *)malloc(128); // Start with an initial buffer size
        if (*lineptr == NULL) {
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
            if (new_lineptr == NULL) {
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
