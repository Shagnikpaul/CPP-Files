#include "stdio.h"

int main(int argc, char const *argv[])
{
  int a = 21;
  int *b = &a;

  //NULL POINTER...

  int* nulpt = NULL;


  printf("%p", *b);
  return 0;
}
