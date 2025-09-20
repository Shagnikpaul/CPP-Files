#include "stdio.h"

void div(int *dividend, int *divisor, int dividendLength, int divisorLength, int *rem)
{
    for (int i = 0; i < dividendLength - divisorLength + 1; i++)
    {
        if (dividend[i] == 1)
        {
            for (int j = 0; j < divisorLength; j++)
            {
                dividend[i + j] ^= divisor[j];
            }
        }
    }

    int k = 0;
    for (int i = dividendLength - divisorLength + 1; i < dividendLength; i++)
    {
        rem[k++] = dividend[i];
    }
}

int main()
{
    //// write da code here...
    int n;
    int degree;
    printf("Enter the number of bits in the data : ");
    scanf("%d", &n);
    printf("Enter the degree of the poly : ");
    scanf("%d", &degree);

    printf("DATA : ");
    int senderCode[n + degree];
    for (int i = 0; i < n; i++)
    {
        scanf("%1d", &senderCode[i]);
    }
    printf("polynomial : ");
    int divisor[degree + 1];
    for (int i = 0; i < degree + 1; i++)
    {
        scanf("%1d", &divisor[i]);
    }
    for (int i = n; i < n + degree; i++)
    {
        senderCode[i] = 0;
    }
    int rem[degree];
    div(senderCode, divisor, n + degree, degree + 1, rem);

    printf("Remaindedr  : ");
    for (int i = 0; i < degree; i++)
    {
        printf("%d", rem[i]);
    }

    return 0;
}