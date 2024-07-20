#include "stdio.h"
int main()
{
  //// write da code here... 
  char name[] = "Shagnik";
  char* ptr;
  ptr = name;
  while (*ptr != '\0')
  {
    printf("%c", *ptr);
    printf(".");
    ptr++;
  }
   
  return 0;
}