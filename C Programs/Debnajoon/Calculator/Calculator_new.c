#include <stdio.h>
int sum(int arr[], int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s = s + arr[i];
    }
    return s;
}
int main()
{
    printf("Enter 1 for Summation\nEnter 2 for Subtraction\nEnter 3 for multiplication\nEnter 4 for Division\n Enter anything else to exit.");
    int ch;
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
    {
        printf("Enter the number of terms you want to add");
        int n;
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            if ((i + 1) % 10 == 1)
            {
                printf("Enter the %dst number\n ", (i + 1));
                scanf("%d", &arr[i]);
            }
            else if ((i + 1) % 10 == 2)
            {
                printf("Enter the %dnd number\n", (i + 1));
                scanf("%d", &arr[i]);
            }
            else if ((i + 1) % 10 == 3)
            {
                printf("Enter the %drd number\n", (i + 1));
                scanf("%d", &arr[i]);
            }
            else
            {
                printf("Enter the %dth number\n", (i + 1));
                scanf("%d", &arr[i]);
            }
        }
        int sum1 = sum(arr, n);
        printf("Sum is %d", sum1);
        break;
    }

    default:
        break;
    }
    return 0;
}