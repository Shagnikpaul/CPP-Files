#include "stdio.h"

int noOfOnes(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        int d = n % 2;
        if (d == 1)
        {
            return (1 + noOfOnes(n / 2));
        }
        else
        {
            return (0 + noOfOnes(n / 2));
        }
    }
}

int main()
{
    //// write da code here...
    printf("Enter a number : ");
    int x;
    scanf("%d", &x);

    printf("No of ones in %d = %d\n", x, noOfOnes(x));
    return 0;
}