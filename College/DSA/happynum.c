#include "stdio.h"
int digitSum(int n)
{
    int s = 0;
    while (n != 0)
    {
        int d = n % 10;
        s += d * d;
        n /= 10;
    }
    return s;
}

int main()
{
    int n = 2;
    if (n == 1)
        printf("yes");
    int k = digitSum(n);
    printf("%d \n", k);
    while (k != 4)
    {
        if (k == 1)
        {
            printf("yes");
            break;
        }
        else
        {
            k = digitSum(k);
            printf("%d \n", k);
        }
    }
    printf("no");

    return 0;
}