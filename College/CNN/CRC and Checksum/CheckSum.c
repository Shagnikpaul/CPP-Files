#include <stdio.h>

void addWords(int sum[], int word[], int length)
{
    int carry = 0;
    int result[100];

    for (int i = length - 1; i >= 0; i--)
    {
        int s = sum[i] + word[i] + carry;
        result[i] = s % 2;
        carry = s / 2;
    }

    // Handle carry wraparound
    while (carry)
    {
        for (int i = length - 1; i >= 0; i--)
        {
            int s = result[i] + carry;
            result[i] = s % 2;
            carry = s / 2;
        }
    }

    // Copy back result
    for (int i = 0; i < length; i++)
        sum[i] = result[i];
}

void onesComplement(int word[], int length)
{
    for (int i = 0; i < length; i++)
    {
        word[i] = word[i] ^ 1; // flip bit
    }
}

int main()
{
    int length, n;
    printf("Enter length of each dataword: ");
    scanf("%d", &length);

    printf("Enter number of datawords: ");
    scanf("%d", &n);

    int sum[100] = {0};
    int word[100];
    int initial_data[n][length];
    int x = 0;
    printf("Enter the datawords (in binary):\n");
    for (int i = 0; i < n; i++)
    {
        printf("Dataword %d: ", i + 1);
        for (int j = 0; j < length; j++)
            scanf("%1d", &word[j]); // read each digit directly into int
        for (int j = 0; j < length; j++)
        {
            initial_data[x][j] = word[j];
        }
        x++;
        addWords(sum, word, length);
    }

    onesComplement(sum, length);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < length; j++)
        {
            printf("%d", initial_data[i][j]);
        }
        printf(" ");
    }

    printf(" | ");
    for (int i = 0; i < length; i++)
    {
        printf("%d", sum[i]);
    }

    int sum2[100] = {0};
    int new_data[n][length];
    printf("\nEnter the datawords (in binary):\n");
    for (int i = 0; i < n; i++)
    {
        printf("Dataword %d: ", i + 1);
        for (int j = 0; j < length; j++)
            scanf("%1d", &word[j]); // read each digit directly into int

        for (int j = 0; j < length; j++)
            new_data[i][j] = word[j];

        addWords(sum2, word, length);
    }
    printf("Enter CS : ");
    for (int j = 0; j < length; j++)
        scanf("%1d", &word[j]); // read each digit directly into int
    addWords(sum2, word, length);
    onesComplement(sum2, length);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < length; j++)
        {
            printf("%d", new_data[i][j]);
        }
        printf(" ");
    }
    printf(" ");
    for (int i = 0; i < length; i++)
    {
        printf("%d", sum2[i]);
    }

    for (int i = 0; i < length; i++)
    {
        if (sum2[i] != 0)
        {
            printf("\nError detected since  check sum is not zero \n");
            return 0;
        }
    }
    printf("\nNo Error detected since check sum is zero. \n");
    return 0;
}