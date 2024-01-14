#include<stdio.h>
int main()
{
    int i,j;
    int k =65; /* ASCII Value*/

    for(i=1;i<=5;i++)
    {
        k=65;
        for(j=1;j<=i;j++)
        {
            printf("%c ",k);
            k++;
        }
        printf("\n");
    }
    return 0;
}
