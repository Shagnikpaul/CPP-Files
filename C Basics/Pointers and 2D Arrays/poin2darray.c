#include "stdio.h"
int main()
{
//// write da code here... 
  int arr[3][3];
  int* ptr = arr[0];
  int* ptr2 = &arr[0][0];
  printf("Pointer of arr[0] = %p and pointer of &arr[0][0] = %p \n",ptr,ptr2);
  printf("Pointer arr + 1 = %p and pointer of arr[1] = %p \n",(arr+1),arr[1]);
  printf("Pointer *(arr + 1) + 2 = %p and pointer of arr[1][2] = %p \n", *(arr + 1)+2, &arr[1][2]);

  printf("Pointer of arr + 1 = %d and pointer of &arr + 1 = %d \n",arr+1, &arr+1);
  // accessing any element in 2d array using pointers = arr[i][j] = *(*(arr + i) + j) or *(arr[i] + j)
  return 0;
}
