#include <stdio.h>
int main()
{
  printf("Enter the value of n");
  int n, c = 0, a = 1;
  scanf("%d", &n);
  for (int i = 1; i <= (2 * n - 1); i++)
  {
    for (int j = (2 * n - 1); j > i; j--)
    { // for spacing
      printf(" ");
    }
    if (c == 0)
    {
      for (int j = 1; j <= a; j++)
        printf("%d ", j);
      for (int j = a - 1; j >= 1; j--)
        printf("%d ", j);
      c = 1;
    }
    else if (c == 1)
    {
      for (int j = 1; j <= a; j++)
        printf("%d ", j);
      for (int j = a; j >= 1; j--)
        printf("%d ", j);
      a++;
      c = 0;
    }
    printf("\n");
  }
}