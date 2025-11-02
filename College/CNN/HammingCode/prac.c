#include "stdio.h"
#include "stdlib.h"

int powerOfTwo(int x)
{
    if (x < 0 || x == 0)
    {
        return 0;
    }
    if ((x & (x - 1)) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int countParityBits(int n)
{
    int r = 1;
    while ((1 << r) < (n + r + 1))
        r++;
    return r;
}

int calculateParity(int *data, int n)
{
    int j = 0;
    for (int i = 1; i <= n; i++)
    {
        if (powerOfTwo(i) || i == 1)
        {
            int checkBit = 1 << j++;
            int parity = 0;
            for (int k = 1; k <= n; k++)
            {
                if (data[k] != -1 && (checkBit & k))
                {
                    parity ^= data[k];
                }
            }
            data[i] = parity;
        }
    }
}

int main()
{
    //// write da code here...

    char inp[100];
    int n;
    printf("Enter the no of bits in the data: ");
    scanf("%d", &n);
    getchar();
    printf("Enter the data:");
    fgets(inp, 100, stdin);
    int parityBitsCount = countParityBits(n);
    printf("Parity bit count = %d\n", parityBitsCount);
    int *code = malloc(sizeof(int) * (n + 1 + parityBitsCount));
    int k = n - 1;

    for (int i = 1; i <= (parityBitsCount + n); i++)
    {
        if (powerOfTwo(i))
        {
            code[i] = -1;
        }
        else
        {
            code[i] = inp[k--] - '0';
        }
    }

    printf("\n Now the code before parity bit calculation is \n");
    for (int i = (parityBitsCount + n); i >= 1; i--)
    {
        printf("%d, ", code[i]);
    }
    printf("\n");

    calculateParity(code, parityBitsCount + n);

    printf("\n Now the code after parity bit calculation is \n");
    for (int i = (parityBitsCount + n); i >= 1; i--)
    {
        printf("%d, ", code[i]);
    }
    printf("\n");

    printf("Enter the data-bit position where you want errror if not error enter out of range value : ");
    int errorPosition;
    scanf("%d", &errorPosition);
    printf("\n");

    code[errorPosition] ^= 1;

    printf("Now the code after flipping a bit is \n");
    for (int i = (parityBitsCount + n); i >= 1; i--)
    {
        printf("%d, ", code[i]);
    }
    printf("\n");

    calculateParity(code, parityBitsCount + n);

    int estimate = 0;
    for (int i = 1; i <= n + parityBitsCount; i++)
    {
        if (powerOfTwo(i) || i == 1)
        {
            estimate += (code[i] * i);
        }
    }
    printf("Estimated error position : %d\n", estimate);

    return 0;
}