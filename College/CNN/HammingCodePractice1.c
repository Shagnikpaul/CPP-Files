#include "stdio.h"
#include "stdlib.h"
int isPowerOfTwo(int n)
{
    if (n < 0 || n == 0)
        return 0;
    if ((n & (n - 1)) == 0)
        return 1;
    else
        return 0;
}

int calculateParityBitCount(int n)
{
    int r = 1;
    while ((1 << r) < (n + r + 1))
    {
        r++;
    }
    return r;
}

void calculateParity(int *code, int len)
{
    int j = 0;
    for (int i = 1; i <= len; i++)
    {
        if (isPowerOfTwo(i) || i == 1)
        {
            int checkBit = 1 << j++;
            int parity = 0;
            for (int k = 1; k <= len; k++)
            {
                if (code[k] != -1 && (checkBit & k) != 0)
                {
                    parity ^= code[k];
                }
            }
            code[i] = parity;
        }
    }
}

int main()
{
    //// write da code here...

    int n;
    printf("Enter the number of bits in the data : ");
    scanf("%d", &n);
    getchar();

    char inp[100];
    printf("Enter the data : ");
    fgets(inp, 100, stdin);
    int parityBitCount = calculateParityBitCount(n);
    int *code = malloc(sizeof(int) * (n + parityBitCount + 1));

    int k = n - 1;

    for (int i = 1; i <= (n + parityBitCount); i++)
    {
        if (isPowerOfTwo(i))
            code[i] = -1;
        else
            code[i] = (inp[k--] - '0');
    }
    printf("\nParity Bit count %d\n", parityBitCount);
    printf("\nBefore parity calculation the hamming code looks like this \n");
    for (int i = (n + parityBitCount); i >= 1; i--)
    {
        printf("%d, ", code[i]);
    }
    printf("\n");

    calculateParity(code, parityBitCount + n);

    printf("After parity calculation the hamming code looks like this \n");
    for (int i = (n + parityBitCount); i >= 1; i--)
    {
        printf("%d, ", code[i]);
    }
    printf("\n");

    printf("Enter the position of error you want if any (within 1 to %d)\n", n);
    int errorPosition;
    scanf("%d", &errorPosition);

    for (int i = 1; i <= parityBitCount + n; i++)
    {
        if (isPowerOfTwo(i))
        {
            continue;
        }
        else if (errorPosition == 1)
        {
            code[i] ^= 1;
            break;
        }
        else
        {
            errorPosition--;
        }
    }

    printf("After fliping the bit hamming code looks like this \n");
    for (int i = (n + parityBitCount); i >= 1; i--)
    {
        printf("%d, ", code[i]);
    }
    printf("\n");

    calculateParity(code, parityBitCount + n);

    int estimate = 0;
    for (int i = 1; i <= parityBitCount + n; i++)
    {
        if (isPowerOfTwo(i) || i == 1)
        {
            estimate += code[i] * i;
        }
    }

    printf("\n Estimated position : %d th Bit of the hamming code.\n", estimate);

    return 0;
}