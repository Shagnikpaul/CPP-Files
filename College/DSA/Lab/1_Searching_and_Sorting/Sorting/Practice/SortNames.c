#include "stdio.h"
#include "string.h"
int main()
{
    char *names[] = {"Hello",
                     "There",
                     "Lmao", "Aakaash", "Hello, World!",
                     "Welcome to C programming.",
                     "123",
                     "This is an example of an array of strings.",
                     "Have a great day!"};
    int n = sizeof(names) / sizeof(char *);

    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(names[j], names[min]) < 0)
            {
                min = j;
            }
        }
        char *t = names[min];
        names[min] = names[i];
        names[i] = t;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", names[i]);
    }
    return 0;
}