#include "stdio.h"
void dih(int *code, int *div, int n, int m, int *rem)
{
    for (int i = 0; i < n - m + 1; i++)
    {
        if (code[i] == 1)
        {
            for (int j = 0; j < m; j++)
            {
                code[i + j] ^= div[j];
            }
        }
    }
    int k = 0;
    for (int i = n - m + 1; i < n; i++)
    {
        rem[k++] = code[i];
    }
}

int main()
{
    //// write da code here...
    int n;
    printf("Enter the no of bits in data : ");
    scanf("%d", &n);

    int degree;
    printf("Enter the degree : ");
    scanf("%d", &degree);

    int code[n + degree];
    int poly[degree + 1];
    int rem[degree];

    printf("Enter the data : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%1d", &code[i]);
    }
    for (int i = n; i < n + degree; i++)
    {
        code[i] = 0;
    }

    printf("Enter the poly : ");
    for (int i = 0; i < degree + 1; i++)
    {
        scanf("%1d", &poly[i]);
    }

    printf("\nCode before crc calc : ");
    for (int i = 0; i < n + degree; i++)
    {
        printf("%d", code[i]);
    }
    printf("\n");
    dih(code, poly, n + degree, degree + 1, rem);

    printf("\nrem after crc calc : ");
    for (int i = 0; i < degree; i++)
    {
        printf("%d", rem[i]);
    }
    int k = 0;
    for (int i = n; i < n + degree; i++)
    {
        code[i] = rem[k++];
    }

    printf("Enter the %d-bit receiver side code : ", (n + degree));
    int code2[n + degree];
    for (int i = 0; i < n + degree; i++)
    {
        scanf("%1d", &code2[i]);
    }
    int rem2[degree];
    dih(code2, poly, n + degree, degree + 1, rem2);

    int ok = 1;
    for (int i = 0; i < degree; i++)
    {
        if (rem2[i] != 0)
        {
            ok = 0;
            break;
        }
    }

    if (ok)
    {
        printf("No error detected .... ");
    }
    else
    {
        printf("Yes error detected .... ");
    }

    printf("\n");
    return 0;
}