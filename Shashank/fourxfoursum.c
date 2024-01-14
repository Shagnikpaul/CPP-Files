#include<stdio.h>

int main()
{
    int matrix1[4][4];
    int s = 0;
    printf("Enter 16 elements of the 4x4 matrix");
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            scanf("%d",&matrix1[i][j]);
        }
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(i == j)
            s=s+matrix1[i][j];
        }
    }
    printf("Sum is %d",s);
}