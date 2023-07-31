#include "stdio.h"
#include "string.h"
int main()
{
  char st[] = "hello";
  char st2[] = "world";
  printf("Concated string of st , st2 = %s \n", strcat(st, st2)); 
  printf("Length of st = %d", strlen(st));
  return 0;
}