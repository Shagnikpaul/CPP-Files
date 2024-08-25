#include "stdio.h"
#include <string.h>
int main()
{
    //// write da code here...
    char input[150];
    printf("Enter the string : ");
    fgets(input,150,stdin);
    int count = 0;
    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] == '(')
        {
            count++;
        }
        else if (input[i] == ')')
        {
            count--;
        }
        else if (input[i] >= 97 && input[i] <= 122)
        {
            printf("%d ", count);
        }
    }

    return 0;
}