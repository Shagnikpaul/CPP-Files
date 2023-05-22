#include <stdio.h>
int main()
{
    printf("Enter the value of n ");
    int n;
    scanf("%d",&n);
    int a = 0;
    for (int i = n; i >= 0; i--)
    {
        for (int j = i; j >= a; j--)
        {
            printf("%d",j);
        }
        a++;
        printf("\n");
    }
}