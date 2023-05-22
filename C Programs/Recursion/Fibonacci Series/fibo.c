#include "stdio.h"

void fib(int a, int b, int n)
{
  if (n == -1)
    return;

  int c = a + b;
  if (a == 0 && b == 1)
  {
    printf("0, 1, ");
    n -= 2;
  }
  else
  {
    printf("%d", c);
    printf(", ");
  }
  fib(b, c, (n - 1));
}

int main()
{
  fib(0, 1, 10);
  return 0;
}
