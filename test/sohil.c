#include "stdio.h"
int main()
{
    //// write da code here...
    int asize, bsize, csize;
    char a[10], b[10], c[20];
    printf("Enter the First Array Size:\n");
    scanf("%d", &asize);
    printf("Enter the First Array Elements:\n");
    scanf("%s", a);
    
  

    printf("Enter the second array size:\n");
    scanf("\n%d", &bsize);
    printf("Enter the Second array elements:\n");
    scanf("%s", b);
    
    
    for(int i = 0; i < asize; i++)
    {
      	c[i] = a[i];
    }
    csize = asize + bsize;

    for(int i = 0, j = asize; j < csize && i < bsize; i++, j++)
    {
    	c[j] = b[i];
    }
    printf("a[%d] array elements after merging \n", csize);
    for(int i = 0; i < csize; i++)
    {
    	printf("%c",c[i]);
    }
    return 0;
}