#include "stdio.h"

int cpb(int x)
{
    int r = 1;
    while (1 << r < (x + r + 1))
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

void pc(int *code, int l)
{
    int j = 0;
    for (int i = 1; i <= l; i++)
    {
        if (is2(i))
        {
            int checkBit = 1 << j++;
            int parity = 0;
            for (int k = 1; k <= l; k++)
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
    int n;
    printf("Enter the length of the data : ");
    scanf("%d", &n);
    int p = cpb(n);
    int code[p + n + 1];
    printf("Enter the data: ");
    char inp[100];
    scanf("%s", &inp);
    int k = n - 1;
    for (int i = 1; i <= p + n; i++)
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

    printf("Recieved code : ");
    for (int i = p + n; i >= 1; i--)
    {
        printf("%d ", code[i]);
    }
    printf("\n");

    pc(code, n + p);

    printf("Hamming Code senders side : ");
    for (int i = p + n; i >= 1; i--)
    {
        printf("%d", code[i]);
    }
    printf("\n");

    printf("In RECEIVE : \n\n");
    printf("Enter the %d bit data : ", (n + p));
    int code2[n + p + 1];
    for (int i = n + p; i >= 1; i--)
    {
        scanf("%1d", &code2[i]);
    }

    printf("Inputtted code :  : ");
    for (int i = p + n; i >= 1; i--)
    {
        printf("%d ", code2[i]);
    }
    printf("\n");

    pc(code2, n + p);
    int estim = 0;
    for (int i = 1; i <= n + p; i++)
    {
        if (is2(i))
        {
            estim += code2[i] * i;
        }
    }

    printf("ESTIMARED : %d", estim);
    code2[estim] ^= 1;
    printf("\nCORRENCTED CODE : ");
    for (int i = p + n; i >= 1; i--)
    {
        if (!is2(i))
        {
            printf("%d ", code2[i]);
        }
    }
}