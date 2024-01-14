#include <stdio.h>

int sum(int n)
{
    printf("%d \n ",n);
    if(n==1)
    return 1;
    else
    return n + sum(n-1);
}

int main()
{
    int ans = sum(10);
    printf("Sum of first 10 natural numbers is %d",ans);
    return 0;
}
