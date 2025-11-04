#include "stdio.h"

void add(int *sum, int *word, int n)
{
    int c = 0;
    int res[n];
    for (int i = n - 1; i >= 0; i--)
    {
        res[i] = (sum[i] + word[i] + c) % 2;
        c = (sum[i] + word[i] + c) / 2;
    }
    while (c)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            res[i] = (res[i] + c) % 2;
            c = (res[i] + c) / 2;
        }
    }

    for (int i = 0; i < n; i++)
        sum[i] = res[i];
}

void onC(int *x, int n)
{
    for (int i = 0; i < n; i++)
    {
        x[i] ^= 1;
    }
}

int main()
{

    int n;
    int wordLength;

    printf("No of words");
    scanf("%d", &n);

    printf("Length of each word");
    scanf("%d", &wordLength);

    int sum[100] = {0};
    int word[100];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < wordLength; j++)
        {
            scanf("%1d", &word[j]);
        }
        add(sum, word, wordLength);
    }
    printf("SUM = ");
    for (int i = 0; i < wordLength; i++)
        printf("%d ", sum[i]);
    printf("\n");
    onC(sum, wordLength);

    printf("CS = ");
    for (int i = 0; i < wordLength; i++)
        printf("%d ", sum[i]);
    printf("\n");

    return 0;
}