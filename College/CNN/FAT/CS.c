#include "stdio.h"

void sumi(int *sum, int *word, int n)
{
    int res[n];
    int c = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int k = sum[i] + word[i] + c;
        c = k / 2;
        res[i] = k % 2;
    }

    while (c)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            int k = res[i] + c;
            c = k / 2;
            res[i] = k % 2;
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        sum[i] = res[i];
    }
}

int c(int *word, int n)
{

    for (int i = n - 1; i >= 0; i--)
    {
        word[i] ^= 1;
    }
}

int main()
{
    //// write da code here...
    int n;
    int wordLength;

    printf("Enter the no of data : ");
    scanf("%d", &n);

    printf("Entert he legnth of each word : ");
    scanf("%d", &wordLength);

    int sum[100] = {0};
    int word[wordLength];

    for (int i = 0; i < n; i++)
    {
        printf("Enter DATA %d", (i + 1));
        for (int j = 0; j < wordLength; j++)
        {
            scanf("%1d", &word[j]);
        }
        sumi(sum, word, wordLength);
    }

    c(sum, wordLength);

    printf("Calculated CS : ");
    for (int i = 0; i < wordLength; i++)
    {
        printf("%d", sum[i]);
    }

    return 0;
}