#include<stdio.h>

int main(int argc, char const *argv[])
{
    int n,s=0;
    printf("Enter the no. of rows: ");
    scanf("%d",&n);
    s = n*(n+1)/2;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            printf("%d  ",s);
            s--;
        }
        printf("\n");
    }
    return 0;
}
