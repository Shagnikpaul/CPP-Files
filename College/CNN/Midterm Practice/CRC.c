#include "stdio.h"

void calc(int *divi, int *divisor, int n, int m, int *rem, int *code) // n total m divisor
{
    for (int i = 0; i < n - m + 1; i++)
    {
        if (code[i] == 1)
        {
            for (int j = 0; j < m; j++)
            {
                code[i + j] ^= divisor[j];
            }
        }
    }
    int k = 0;
    for (int i = n - m + 1; i < n; i++)
    {
        rem[k++] = code[i];
    }
    return;
}

int main()
{

    int n;
    int degree;

    printf("NO of bits in the data : ");
    scanf("%d", &n);

    printf("Degree of the divisor polynomial : ");

    scanf("%d", &degree);

    int code[degree + n];
    int rem[degree];
    printf("Enter the data : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%1d", &code[i]);
    }
    /*
        data length -> n + degree
        rem length -> degree
        dvisor length -> 1 + degree

    */
    printf("Enter the divisor (%d bit length) : ", (degree + 1));
    int poly[degree + 1];
    for (int i = 0; i < degree + 1; i++)
    {
        scanf("%1d", &poly[i]);
    }

    for (int i = n; i < degree + n; i++)
    {
        code[i] = 0;
    }

    printf("Previuos Code : ");
    for (int i = 0; i < degree + n; i++)
    {
        printf("%d", code[i]);
    }
    printf("\n");
    calc(code, poly, n + degree, degree + 1, rem, code);

    printf("Remainder : ");
    for (int i = 0; i < degree; i++)
    {
        printf("%d", rem[i]);
    }

    return 0;
}