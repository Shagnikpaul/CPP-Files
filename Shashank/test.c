#include <stdio.h>
int main()
{
    int i, j, n;
    printf("enter the elements:");
    scanf("%d", &n);
    int a[n];
    int b[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        b[i] = 0;
    }
    for (j = 0; j < n; j++)
    {
        int c = 0;
        for (i = 0; i < n; i++)
        {
            if (a[j] == a[i])
            {
                c++;
                b[i] = a[j];
            }
        }
        if (c > 1 && a[j]!=b[j])
        {
            printf("%d", a[j]);
        }
    }
}