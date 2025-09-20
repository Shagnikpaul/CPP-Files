#include "stdio.h"

void add(int sum[], int data[], int length)
{
    int s;
    int res[length];
    int carry = 0;
    for (int i = length - 1; i >= 0; i--)
    {
        int s = sum[i] + data[i] + carry;
        res[i] = s % 2;
        carry = s / 2;
    }

    while (carry)
    {
        for (int i = length - 1; i >= 0; i--)
        {
            int s = res[i] + carry;
            res[i] = s % 2;
            carry = s / 2;
        }
    }

    for (int i = 0; i < length; i++)
        sum[i] = res[i];
}

void onesComp(int data[], int length)
{
    for (int i = 0; i < length; i++)
    {
        data[i] ^= 1;
    }
}

int main()
{
    //// write da code here...
    int n;
    int bits;
    printf("Enter the number of bits in the dataword : ");
    scanf("%d", &bits);
    printf("Enter the number of datawords : ");
    scanf("%d", &n);
    int sum[100] = {0};
    int data[n][bits];

    for (int i = 0; i < n; i++)
    {
        printf("Enter dataword %d: ", (i + 1));
        for (int j = 0; j < bits; j++)
        {
            scanf("%1d", &data[i][j]);
        }
        add(sum, data[i], bits);
    }
    onesComp(sum, bits);
    printf("CS  : ");
    for (int i = 0; i < bits; i++)
    {
        printf("%d", sum[i]);
    }

    int sum2[100] = {0};
    int data2[n][bits];
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter dataword %d: ", (i + 1));
        for (int j = 0; j < bits; j++)
        {
            scanf("%1d", &data2[i][j]);
        }
        add(sum2, data2[i], bits);
    }
    printf("\nEnter the new CS : ");
    int new_cs[bits];
    for (int i = 0; i < bits; i++)
    {
        scanf("%1d", &new_cs[i]);
    }
    add(sum2, new_cs, bits);
    onesComp(sum2, bits);
    printf("\nNEW CS  : ");
    for (int i = 0; i < bits; i++)
    {
        printf("%d", sum2[i]);
    }
    return 0;
}