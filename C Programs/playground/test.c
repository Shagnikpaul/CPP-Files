#include "stdio.h"

void fun21(int n)
{
  int i = 0;
  if (n > 1)
    fun21(n - 1);
  for (i = 0; i < n; i++)
    printf(" * ");
  printf("\n");
}

int main()
{
  
  fun21(10);
  return 0;
}


