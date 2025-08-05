#include "stdio.h"
#include <stdlib.h>

int countParityBit(int dataBitCount)
{
  int r = 1;
  while ((1 << r) < (dataBitCount + r + 1))
  {
    r++;
  }
  return r;
}

int isPowerOfTwo(int n)
{
  if (n == 0 || n < 0)
    return 0;
  if ((n & (n - 1)) == 0)
    return 1;
  else
    return 0;
}

void calculateParity(int *code, int l)
{
  int j = 0;
  for (int i = 1; i <= l; i++)
  {
    if (isPowerOfTwo(i) || i == 1)
    {
      // printf("\nj is %d\n", j);
      int checkBit = 1 << j++;

      int parity = 0;
      for (int k = 1; k <= l; k++)
      {
        if (code[k] != -1 && ((checkBit & k) != 0))
        {
          //printf("\nconsidered position %d with value %d\n", k, code[k]);
          parity ^= code[k];
        }
      }
      //printf("Parity bit %d : %d \n", i, parity);
      code[i] = parity;
    }
  }
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

  int k = n - 1;
  int parityBitCount = countParityBit(n);

  int *code = malloc(sizeof(int) * (parityBitCount + n + 1));

  for (int i = 1; i <= (parityBitCount + n); i++)
  {
    if (isPowerOfTwo(i))
    {
      code[i] = -1;
    }
    else
    {
      code[i] = input[k--] - '0';
    }
  }

  printf("Code till now : \n");
  for (int i = (parityBitCount + n); i >= 1; i--)
  {
    printf("%d, ", code[i]);
  }
  printf("\n");
  calculateParity(code, parityBitCount + n);
  printf("Code after : \n");
  for (int i = (parityBitCount + n); i >= 1; i--)
  {
    printf("%d, ", code[i]);
  }


  printf("\nIn which bit do you need error pls type a number in range of 1 to %d : \n", n);
  int errorBitPosition = -1;
  scanf("%d", &errorBitPosition);
  if (errorBitPosition != -1 && (errorBitPosition <= n && errorBitPosition >= 1))
  {
    k = 1;
    for (int i = 2; i <= n + parityBitCount; i++)
    {
      if (isPowerOfTwo(i))
      {
        k++;
      }
      else
      {
        if (errorBitPosition == (i - k))
        {
          code[i] ^= 1;
          break;
        }
      }
    }

    printf("Code after flipping : \n");
    for (int i = (parityBitCount + n); i >= 1; i--)
    {
      printf("%d, ", code[i]);
    }
    printf("\n");

    calculateParity(code, parityBitCount + n);
    printf("new : \n");
    for (int i = (parityBitCount + n); i >= 1; i--)
    {
      printf("%d, ", code[i]);
    }
    printf("\n");
    k = 1;
    int k1 = 0;
    int co = 0;
    while(k <= parityBitCount){
      co += (1 << k1) * code[1 << k1];
      k1++;
      k++;
    }
    printf("Estimated error position : %d", co);
  }
  else
  {
    printf("No error selected so no error detected... \n");
  }
  printf("\n");
  return 0;
}