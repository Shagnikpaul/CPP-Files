
#include <stdio.h>
#include <math.h>

// Function to check if a number is a power of two
int isPowerOfTwo(int n)
{
    if (n < 1)
        return 0;
    return (n & (n - 1)) == 0;
}

int main()
{
    int m, r = 0, i, j, k;
    // Input the number of data bits
    printf("Enter the number of data bits: ");
    scanf("%d", &m);
    int data[m];
    // Input the data bits
    printf("Enter the data bits: ");
    for (i = 0; i < m; i++)
    {
        scanf("%d", &data[i]);
    }

    // Calculate the number of redundant bits required for Hamming code
    while ((1 << r) < (m + r + 1))
    {
        r++;
    }

    // Initialize the Hamming code array
    int hamming[m + r + 1];
    // Place the data and redundant bits in their respective positions
    for (i = 1, j = 0, k = 0; i <= m + r; i++)
    {
        if (i == (1 << k))
        {
            hamming[i] = 0; // Placeholder for redundant bit
            k++;
        }
        else
        {
            hamming[i] = data[j++]; // Place data bit
        }
    }

    // Calculate parity bits for each redundant position
    for (i = 0; i < r; i++)
    {
        int parity = 0;
        for (j = 1; j <= m + r; j++)
        {
            // Check if the j-th bit is covered by the i-th parity bit
            if (j & (1 << i))
            {
                parity ^= hamming[j]; // XOR to calculate parity
            }
        }
        hamming[(1 << i)] = parity; // Set the calculated parity bit
    }

    // Output the final Hamming code
    printf("\nHamming code: ");
    for (i = 1; i <= m + r; i++)
    {
        printf("%d ", hamming[i]);
    }
    printf("\n");

    return 0;
}