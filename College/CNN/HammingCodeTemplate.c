#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to check if a number is a power of 2
int isPowerOfTwo(int x)
{
    return x && (!(x & (x - 1)));
}

// Calculate number of parity bits required
int calculateParityBits(int m)
{
    int r = 0;
    while ((1 << r) < (m + r + 1))
        r++;
    return r;
}

// Calculate parity for position parityPos
int calcParity(int code[], int size, int parityPos)
{
    int parity = 0;
    for (int i = 1; i <= size; i++)
    {
        if (i & parityPos)
        {
            parity ^= code[i];
        }
    }
    return parity;
}

int main()
{
    int m;
    printf("Enter number of data bits: ");
    scanf("%d", &m);

    int *data = (int *)malloc(m * sizeof(int));
    printf("Enter %d data bits (LSB first):\n", m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &data[i]);
    }

    int r = calculateParityBits(m);
    int totalBits = m + r;
    int *code = (int *)calloc(totalBits + 1, sizeof(int)); // 1-based indexing

    // Insert data bits into code skipping powers of 2
    for (int i = 0, j = 1, k = 0; j <= totalBits; j++)
    {
        if (isPowerOfTwo(j))
        {
            code[j] = 0; // placeholder for parity
        }
        else
        {
            code[j] = data[k++];
        }
    }

    // Calculate and set parity bits
    for (int i = 0; i < r; i++)
    {
        int parityPos = 1 << i;
        code[parityPos] = calcParity(code, totalBits, parityPos);
    }

    // Print encoded code
    printf("Encoded Hamming Code (%d data + %d parity = %d bits):\n", m, r, totalBits);
    for (int i = 1; i <= totalBits; i++)
    {
        printf("%d ", code[i]);
    }

    // Error simulation
    int errorPos;
    printf("\nEnter position to flip (0 for no error): ");
    scanf("%d", &errorPos);
    if (errorPos >= 1 && errorPos <= totalBits)
    {
        code[errorPos] ^= 1;
        printf("Code with error:\n");
        for (int i = 1; i <= totalBits; i++)
        {
            printf("%d ", code[i]);
        }
    }

    // Error detection using syndrome
    int syndrome = 0;
    for (int i = 0; i < r; i++)
    {
        int parityPos = 1 << i;
        int p = calcParity(code, totalBits, parityPos);
        syndrome += p * parityPos;
    }

    if (syndrome == 0)
        printf("\nNo error detected.\n");
    else
        printf("\nError detected at position: %d\n", syndrome);

    free(data);
    free(code);
    return 0;
}
