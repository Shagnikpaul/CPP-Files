#include "stdio.h"

void divide(int *dividend, int *divisor, int dividendLength, int divisorLength, int *rem)
{
    for (int i = 0; i < dividendLength - divisorLength+1; i++)
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
    printf("Enter the number of bits in the data: ");
    scanf("%d", &n);
    printf("Enter the degree of the polynomial : ");
    int degree;
    scanf("%d", &degree);
    int senderCode[n + degree];
    printf("Enter the %d bit data : ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%1d", &senderCode[i]);
    }
    int divisor[degree + 1];
    for (int i = 0; i < degree; i++)
    {
        senderCode[n + i] = 0;
    }
    printf("Initial sender side code : ");
    for (int i = 0; i < n + degree; i++)
    {
        printf("%d", senderCode[i]);
    }
    printf("\nEnter the %d bit binary of polynomial : ", degree + 1);
    for (int i = 0; i <= degree; i++)
    {

        scanf("%1d", &divisor[i]);
    }

    printf("Data : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d", senderCode[i]);
    }
    printf("\nDivisor : ");
    for (int i = 0; i < degree + 1; i++)
    {
        printf("%d", divisor[i]);
    }
    int rem[degree];
    // printf("Initial CRC : ");
    divide(senderCode, divisor, n + degree, degree + 1, rem);
    printf("\nRemainder : ");
    for (int i = 0; i < degree; i++)
        printf("%d", rem[i]);
    return 0;
}