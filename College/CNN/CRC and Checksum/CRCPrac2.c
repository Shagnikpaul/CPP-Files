#include <stdio.h>

void divide(int *dividend, int *divisor, int dividendLength, int divisorLength, int *rem)
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

    printf("No of bits in the data: ");
    int n;
    scanf("%d", &n);
    int data[n];
    printf("Enter the data: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%1d", &data[i]);
    }
    printf("Enter the degree of the polynomial: ");
    int poly_degree;
    scanf("%d", &poly_degree);
    int divisor[poly_degree + 1];
    printf("Enter the binary form of the polynomial (length = %d) : ", (poly_degree + 1));
    for (int i = 0; i < poly_degree + 1; i++)
    {
        scanf("%1d", &divisor[i]);
    }

    printf("Data : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d", data[i]);
    }
    printf("\n");
    printf("Divisor :");
    for (int i = 0; i <= poly_degree; i++)
    {
        printf("%d", divisor[i]);
    }
    int senderSideCRCCode[n + poly_degree];
    int k = 0;

    // append polynomial degree of zeroes to the crc code...
    for (int i = 0; i < n + poly_degree; i++)
    {
        if (i < n)
        {
            senderSideCRCCode[i] = data[k++];
        }
        else
        {
            senderSideCRCCode[i] = 0;
        }
    }

    // printf("\nCRC Code before calculation in the sender side : ");
    // for (int i = 0; i < n + poly_degree; i++)
    // {
    //     printf("%d", senderSideCRCCode[i]);
    // }
    int remainder[poly_degree];
    divide(senderSideCRCCode, divisor, n + poly_degree, poly_degree + 1, remainder);

    printf("\nCRC Remainder: ");
    for (int i = 0; i < poly_degree; i++)
    {
        printf("%d", remainder[i]);
    }
    printf("\n");
    k = 0;
    int z = 0;
    for (int i = 0; i < n + poly_degree; i++)
    {
        if (i < n)
        {
            senderSideCRCCode[i] = data[k++];
        }
        else
        {
            senderSideCRCCode[i] = remainder[z++];
        }
    }

    printf("\nCRC Code after calculation in the sender side : ");
    for (int i = 0; i < n + poly_degree; i++)
    {
        printf("%d", senderSideCRCCode[i]);
    }

    int recieverSideData[n + poly_degree];
    printf("\nEnter the %d bit reciever side data (data + crc remainder) : ", (n + poly_degree));
    for (int i = 0; i < n + poly_degree; i++)
    {
        scanf("%1d", &recieverSideData[i]);
    }
    divide(recieverSideData, divisor, n + poly_degree, poly_degree + 1, remainder);
    // printf("\nNew CRC Remainder: ");
    for (int i = 0; i < poly_degree; i++)
    {
        if (remainder[i] == 1)
        {
            printf("Error detected remainder is not zero");
            return 0;
        }
    }
    printf("No error detected remainder is 0");
    return 0;
}