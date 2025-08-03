#include "stdio.h"

int countParityBit(int dataBitCount)
{
  int r = 1;
  while ((1 << r) < (dataBitCount + r + 1))
  {
    r++;
  }
  return r;
}

int main()
{
  //// write da code here...

  int n;
  printf("Enter the number of bits in the data : ");

  scanf("%d", &n);
  char input[100];
  getchar();
  printf("Enter the %d bit data : ", n);
  fgets(input, 100, stdin);

  int data_bits[n];
  for (int i = 0; i < n; i++)
  {
    data_bits[i] = input[i] - '0';
  }

  printf("\n data bits  : \n");
  for (int i = 0; i < n; i++)
  {
    printf("%d, ", data_bits[i]);
  }

  printf("\ndata you entered : %s\n", input);
  int parityBitCount = countParityBit(n);
  int *code = malloc(sizeof(int) * (parityBitCount + n + 1));

  for (int i = 0; i <= (parityBitCount + n); i++)
  {
    
  }
  return 0;
}