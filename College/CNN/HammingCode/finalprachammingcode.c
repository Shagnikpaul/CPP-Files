#include "stdio.h"
#include "stdlib.h"

int countParityBit(int n)
{
    int r = 1;
    while ((1 << r) < (n + r + 1))
    {
        r++;
    }
    return r;
}

int powerOfTwo(int x)
{
    if (x == 0 || x < 0)
    {
        return 0;
    }

    if ((x & (x - 1)) == 0)
        return 1;
    else
        return 0;
}

void parityCalculation(int *code, int l)
{
    int j = 0;
    for (int i = 1; i <= l; i++)
    {
        if (powerOfTwo(i) || i == 1)
        {
            int parity = 0;
            int checkBit = 1 << j++;
            for (int k = 1; k <= l; k++)
            {
                if (code[k] != -1 && (k & checkBit))
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
    char inp[100];

    int n;
    printf("Enter the number of bits in data");
    scanf("%d", &n);
    int parityBitCount = countParityBit(n);

    getchar();
    printf("Enter the data: ");
    fgets(inp, 100, stdin);

    int *code = malloc(sizeof(int) * (n + parityBitCount + 1));

    int k = n - 1;
    for (int i = 1; i <= parityBitCount + n + 1; i++)
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

    printf("\nHamming Code before parity bit calculation : \n");
    for (int i = parityBitCount + n; i >= 1; i--)
    {
        printf("%d, ", code[i]);
    }
    printf("\n");
    parityCalculation(code, parityBitCount + n);
    printf("\nHamming Code after parity bit calculation : \n");
    for (int i = parityBitCount + n; i >= 1; i--)
    {
        printf("%d, ", code[i]);
    }
    printf("\n");

    printf("Enter the bit position in data you want error in (type out of range for no error) range - 1 to %d\n", n);
    int errorPosition;
    scanf("%d", &errorPosition);

    for (int i = 1; i <= parityBitCount + n; i++)
    {
        if (!(powerOfTwo(i) || i == 1))
        {
            if (errorPosition == 1)
            {
                code[i] ^= 1;
                break;
            }
            else
            {
                errorPosition--;
            }
        }
    }

    printf("\nHamming Code after bit flipping : \n");
    for (int i = parityBitCount + n; i >= 1; i--)
    {
        printf("%d, ", code[i]);
    }
    printf("\n");

    parityCalculation(code, parityBitCount + n);

    int estimate = 0;
    for (int i = 1; i <= parityBitCount + n; i++)
    {
        if (powerOfTwo(i) || i == 1)
        {
            estimate += (code[i] * i);
        }
    }

    printf("Estimated error position : %d", estimate);

    return 0;
}