#include "stdio.h"

int sub(int a, int b)
{
    return a - b;
}

int main()
{
    //// write da code here...
    int (*sub_ptr)(int, int);

    sub_ptr = &sub;
    int x = sub_ptr(2, 6);
    printf("Result : %d", x);
    return 0;
}