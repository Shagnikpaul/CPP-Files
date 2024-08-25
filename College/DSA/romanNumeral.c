#include "stdio.h"
#include <string.h>

int val(char ch)
{
    int val=-1;
    switch (ch)
    {
    case 'C':
        val = 100;
        break;
    case 'I':
        val = 1;
        break;
    case 'V':
        val = 5;
        break;
    case 'X':
        val = 10;
        break;
    case 'L':
        val = 50;
        break;
    case 'D':
        val = 500;
        break;
    case 'M':
        val = 1000;
        break;
    default:
        break;
    }
    return val;
}

int main()
{
    //// write da code here...
    char s[] = "MCMXCIV";
    int lastval=-1;
    int num = 0;
    char *p = s;
    int l = strlen(p);
    for (int i = l-1;i>=0;i--){
        if(val(s[i]) < lastval){
            num = num - val(s[i]);
        }
        else{
            num += val(s[i]);
        }
        //printf("\ngot val = %d \n",num);
        lastval = val(s[i]);
    }
    //printf("val = %d",num);
    return 0;
}
