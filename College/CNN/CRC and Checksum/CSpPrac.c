#include "stdio.h"

void add(int sum[], int word[], int length)
{
    int s;
    int res[length];
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
        sum[i] = res[i];
}

void onesComp(int sum[], int length)
{
    for (int i = 0; i < length; i++)
    {
        sum[i] ^= 1;
    }
}

int main()
{
    //// write da code here...
    int n;
    int bits;
    printf("No of datawords : ");
    scanf("%d", &n);
    printf("No of bits in each dataword : ");
    scanf("%d", &bits);
    int data1[n][bits];
    int sum[100] = {0};
    int word[100];

    printf("Enter the datas \n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter dataword %d : ", (i + 1));
        for (int j = 0; j < bits; j++)
        {
            scanf("%1d", &word[j]);
        }
        add(sum, word, bits);
    }
    onesComp(sum, bits);

    printf("CS : ");
    for (int j = 0; j < bits; j++)
    {
        printf("%d", sum[j]);
    }

    printf("\n");

    int data2[n][bits];
    int sum2[100] = {0};

    printf("Enter the datas \n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter dataword %d : ", (i + 1));
        for (int j = 0; j < bits; j++)
        {
            scanf("%1d", &word[j]);
        }
        add(sum2, word, bits);
    }
    printf("Enter the CS \n");
    for (int j = 0; j < bits; j++)
    {
        scanf("%1d", &word[j]);
    }
    add(sum2, word, bits);
    onesComp(sum2, bits);
    printf("NEW CS : ");
    for (int j = 0; j < bits; j++)
    {
        printf("%d", sum2[j]);
    }
    return 0;
}