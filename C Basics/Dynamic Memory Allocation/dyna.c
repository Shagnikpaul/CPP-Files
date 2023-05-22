#include "stdio.h"
#include <stdlib.h>
int main()
{
//// write da code here... 
  int* ptr = (int*) malloc(3 * sizeof(int)); // basically creating an array of size 3
  
  for(int i = 0; i < 3; i++)
  {
    printf("Enter element %d", (i+1));
    scanf("%d",&ptr[i]);
  }
  for (int i = 0; i < 12; i++) // till 3 it will print expected values but after that only garbage values...
  {
    printf("Element %d is %d \n", (i + 1),ptr[i]);
     
  }
  // int* ptr2  = (int*) calloc(10, sizeof(int));
  // int* ptr3 = (int*) realloc(ptr2, 4*sizeof(int));
  // free(ptr3);
  return 0;
}