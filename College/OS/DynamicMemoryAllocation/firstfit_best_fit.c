#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the number of memory partitions: ");
    scanf("%d", &n);

    int blocks[n];
    int blocks2[n];

    printf("Enter the size of each partition (space-separated): ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &blocks[i]);
        blocks2[i] = blocks[i];
    }

    int m;
    printf("Enter the number of data blocks to insert: ");
    scanf("%d", &m);

    int inse[m];
    printf("Enter the size of each data block (space-separated): ");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &inse[i]);
    }

    int firstFit[n];
    int bestFit[n];
    for (int i = 0; i < n; i++)
    {
        firstFit[i] = 0;
        bestFit[i] = 0;
    }

    printf("\nFIRST FIT ALLOCATION\n");

    for (int i = 0; i < m; i++)
    {
        int isInserted = 0;
        for (int j = 0; j < n; j++)
        {
            if (inse[i] <= blocks[j])
            {
                blocks[j] -= inse[i];
                firstFit[j] += inse[i];
                printf("Block %d (size %d) allocated to Partition %d\n", i + 1, inse[i], j + 1);
                isInserted = 1;
                break;
            }
        }
        if (!isInserted)
        {
            printf("Block %d (size %d) could NOT be allocated\n", i + 1, inse[i]);
        }
    }

    printf("\nRemaining partition sizes after FIRST FIT:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Partition %d: %d\n", i + 1, blocks[i]);
    }

    printf("\nBEST FIT ALLOCATION\n");

    for (int i = 0; i < m; i++)
    {
        int minDiff = 9999999;
        int minIndex = -1;

        for (int j = 0; j < n; j++)
        {
            if (inse[i] <= blocks2[j] && (blocks2[j] - inse[i]) < minDiff)
            {
                minDiff = blocks2[j] - inse[i];
                minIndex = j;
            }
        }

        if (minIndex != -1)
        {
            blocks2[minIndex] -= inse[i];
            bestFit[minIndex] += inse[i];
            printf("Block %d (size %d) allocated to Partition %d\n", i + 1, inse[i], minIndex + 1);
        }
        else
        {
            printf("Block %d (size %d) could NOT be allocated\n", i + 1, inse[i]);
        }
    }

    printf("\nRemaining partition sizes after BEST FIT:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Partition %d: %d\n", i + 1, blocks2[i]);
    }

    printf("\nAllocation process completed.\n");
    return 0;
}
