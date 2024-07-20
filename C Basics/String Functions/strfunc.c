#define FOUND 1
#define NOTFOUND 0

#include "stdio.h"
#include "string.h"
int main()
{
  char st[] = "hello";
  char st2[] = "world";
  printf("Concated string of st , st2 = %s \n", strcat(st, st2));
  int l = strlen(st);
  printf("Length of st = %d", l);

  char target[23];
  strcpy(target, st);
  puts("\n\n");
  puts(st);

  char string1[] = "Jerry";
  char string2[] = "Ferry";
  int i, j, k;
  i = strcmp(string1, "Jerry");
  j = strcmp(string1, string2);
  k = strcmp(string1, "Jerry boy");
  printf("\n%d %d %d", i, j, k);
  
  return 0;
}