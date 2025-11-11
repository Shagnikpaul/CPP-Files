#include "stdio.h"

int cpb(int x)
{
    int r = 1;
    while ((1 << r) < (1 + r + x))
    {
        r++;
    }
    return r;
}

int is2(int x)
{
    if (x == 0 || x < 0)
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

void pbb(int *code, int n)
{
    int j = 0;
    for (int i = 1; i <= n; i++)
    {
        if (is2(i))
        {
            int checkBit = 1 << j++;
            int parity = 0;
            for (int k = 1; k <= n; k++)
            {
                if (code[k] != -1 && (checkBit & k))
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
    printf("No of data bits : ");
    scanf("%d", &n);
    char inp[100];

    int p = cpb(n);

    printf("Enter the data : ");
    scanf("%s", &inp);

    int k = n - 1;
    int code[n + p + 1];
    for (int i = 1; i <= n + p; i++)
    {
        if (is2(i))
        {
            code[i] = -1;
        }
        else
        {
            code[i] = inp[k--] - '0';
        }
    }

    printf("Code before hamming code calculation : ");
    for (int i = n + p; i >= 1; i--)
    {
        printf("%d, ", code[i]);
    }
    printf("\n");
    pbb(code, n + p);
    printf("Code after hamming code calculation : ");
    for (int i = n + p; i >= 1; i--)
    {
        printf("%d, ", code[i]);
    }

    printf("Enter the %d-bit receiver side code : ");
    int code2[n + p + 1];
    for (int i = n + p; i >= 1; i--)
    {
        scanf("%1d", &code2[i]);
    }

    printf("Code before hamming code calculation : ");
    for (int i = n + p; i >= 1; i--)
    {
        printf("%d, ", code2[i]);
    }
    printf("\n");
    pbb(code2, n + p);
    printf("Code after hamming code calculation : ");
    for (int i = n + p; i >= 1; i--)
    {
        printf("%d, ", code2[i]);
    }

    int est = 0;
    for (int i = 1; i <= n + p; i++)
    {
        if (is2(i))
        {
            est += (code2[i] * i);
        }
    }

    printf("Esimated error position : %d \n", est);

    printf("\n");
    return 0;
}