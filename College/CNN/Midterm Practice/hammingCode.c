#include "stdio.h"

int countPB(int n)
{
    int r = 1;
    while ((1 << r) < (n + r + 1))
    {
        r++;
    }
    return r;
}

int isPowerTwo(int x)
{
    if (x < 0 || x == 0)
        return 0;

    if ((x & (x - 1)) == 0)
        return 1;
    else
        return 0;
}

int cPar(int n, int *code)
{
    int j = 0;
    for (int k = 1; k <= n; k++)
    {
        if (isPowerTwo(k))
        {
            int parity = 0;
            int checkBit = 1 << j++;
            for (int z = 1; z <= n; z++)
            {
                if (code[z] != -1 && (checkBit & z))
                {
                    parity ^= code[z];
                }
            }
            code[k] = parity;
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of bits in data : ");
    scanf("%d", &n);
    int pbCount = countPB(n);
    getchar();
    printf("Enter the data : ");
    char inp[100];
    fgets(inp, 100, stdin);

    int code[pbCount + n + 1];
    int k = n - 1;
    for (int i = 1; i <= n + pbCount; i++)
    {
        if (isPowerTwo(i))
        {
            code[i] = -1;
        }
        else
        {
            code[i] = inp[k--] - '0';
        }
    }

    printf("Data before hamming code calculation : ");
    for (int i = pbCount + n; i >= 1; i--)
    {
        printf("%d ", code[i]);
    }
    printf("\n");
    cPar(pbCount + n, code);

    printf("Data after hamming code calculation : ");
    for (int i = pbCount + n; i >= 1; i--)
    {
        printf("%d ", code[i]);
    }
    printf("\n");

    printf("Enter the %d-bit data in the receiver side: ", (n + pbCount));
    int code2[n + pbCount + 1];
    char inp2[100];
    fgets(inp2, 100, stdin);
    k = n + pbCount - 1;

    for (int i = 1; i <= n + pbCount; i++)
    {
        code2[i] = inp2[k--] - '0';
    }

    printf("Receiver side code : ");
    for (int i = pbCount + n; i >= 1; i--)
    {
        printf("%d ", code2[i]);
    }
    printf("\n");

    cPar(n + pbCount, code2);

    printf("Receiver side code after again hamming calculation : ");
    for (int i = pbCount + n; i >= 1; i--)
    {
        printf("%d ", code2[i]);
    }
    printf("\n");

    int estimate = 0;
    for (int i = 1; i <= pbCount + n; i++)
    {
        if (isPowerTwo(i) || i == 1)
        {
            estimate += (code2[i] * i);
        }
    }

    printf("Estimated error position : %d\n", estimate);

    code2[estimate] ^= 1;
    printf("Corrected Data : ");
    for (int i = pbCount + n; i >= 1; i--)
    {
        if (!isPowerTwo(i))
            printf("%d ", code2[i]);
    }
    printf("\n");
    return 0;
}