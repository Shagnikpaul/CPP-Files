#include "stdio.h"
int main()
{
  int a = 21;
  int *p = &a;
  printf("p = %d \n", p);
  printf("(p-1) = %d\n", (p - 1));
  printf("++p = %d \n", ++p); // adds 4 bytes to p not 1

  /*
    Arrays...

  */
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  printf("arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} \n");
  printf("arr[4] = %d \n", arr[4]);
  printf("&arr[4] = %d \n", &arr[4]);
  printf("(arr + 4) = %d \n",(arr + 4));

  printf("&arr[4] (value) = %d \n", *(&arr[4]));
  printf("(arr + 4) (value) = %d \n", *(arr + 4));
  return 0;
}