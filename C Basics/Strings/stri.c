#include "stdio.h"
int main()
{
//// write da code here... 

    /*
    using scanf to recieve a string with spaces 
    scanf ( "%[^\n]s", name ) ;
    */    

    char str[] = {'s','a','m','\0'}; // always make the last element '\0'
    char str3[67];
    char str4[] = "jbqdwub";
    gets(str3); // to accept a string easily
    puts(str3); // to print a string easily
    puts(str4);
    char name[] = "Shagnik Paul";
    int l = strlen(name);
    printf("%d",l);
    return 0;
}