#include <stdio.h>

void add(int sum[], int word[], int length)
{

    int res[length];
    int s;
    int carry = 0;
    for (int i = length - 1; i >= 0; i--)
    {
        s = sum[i] + word[i] + carry;
        res[i] = s % 2;
        carry = s / 2;
    }

    while (carry)

    {

        for (int i = length - 1; i >= 0; i--)
        {
            s = res[i] + carry;
            res[i] = s % 2;
            carry = s / 2;
        }
    }

    for (int i = 0; i < length; i++)
    {
        sum[i] = res[i];
    }
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
    int bits;
    int n;
    printf("Enter the no. of bits in a dataword : ");
    scanf("%d", &bits);
    printf("Enter the no. of datawords : ");
    scanf("%d", &n);

    int data[n][bits];
    int sum[100] = {0};
    int word[100];
    for (int i = 0; i < n; i++)
    {
        printf("Enter dataword %d: ", (i + 1));
        for (int j = 0; j < bits; j++)
            scanf("%1d", &data[i][j]);

        add(sum, data[i], bits);
    }
    onesComp(sum, bits);
    printf("\nChecksum : ");
    for (int i = 0; i < bits; i++)
    {
        printf("%d", sum[i]);
    }
    printf("\n");
    int data2[n][bits];
    int sum2[100] = {0};
    for (int i = 0; i < n; i++)
    {
        printf("Enter dataword %d: ", (i + 1));
        for (int j = 0; j < bits; j++)
            scanf("%1d", &data2[i][j]);

        add(sum2, data2[i], bits);
    }
    int new_cs[bits];
    printf("Enter the new CS : ");
    for (int i = 0; i < bits; i++)
    {
        scanf("%1d", &new_cs[i]);
    }
    add(sum2, new_cs, bits);
    onesComp(sum2, bits);
    printf("\nNew Checksum : ");
    for (int i = 0; i < bits; i++)
    {
        printf("%d", sum2[i]);
    }
    return 0;
}