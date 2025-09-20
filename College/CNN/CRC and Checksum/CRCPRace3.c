#include "stdio.h"
void divide(int *dividend, int *divisor, int dividendLegth, int divisorLength, int *rem)
{
    for (int i = 0; i < dividendLegth - divisorLength + 1; i++)
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
    for (int i = dividendLegth - divisorLength + 1; i < dividendLegth; i++)
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
    printf("Enter the degree of the polynomial : ");
    scanf("%d", &degree);

    printf("Enter the data : ");
    int data[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%1d", &data[i]);
    }

    printf("Enter the polynomial binary : ");
    int poly[degree + 1];
    for (int i = 0; i < degree + 1; i++)
    {
        scanf("%1d", &poly[i]);
    }
    int senderCode[degree + n];
    for (int i = 0; i < n + degree; i++)
    {
        if (i < n)
        {
            senderCode[i] = data[i];
        }
        else
        {
            senderCode[i] = 0;
        }
    }
    int rem[degree];
    divide(senderCode, poly, degree + n, degree + 1, rem);

    printf("Sender side code : ");
    int k = 0;
    for (int i = 0; i < n + degree; i++)
    {
        if (i < n)
        {
            printf("%d", data[i]);
        }
        else
        {
            printf("%d", rem[k++]);
        }
    }

    return 0;
}