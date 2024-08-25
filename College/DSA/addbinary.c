#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

char* toBinaryString(int n){
    int count=0;
    int multiplier=1;
    int res = 0;
    while(n!=0){
        int d = n%2;
        res = res + d * multiplier;
        multiplier*=10;
        count++;
        n/=2;
    }
    char* c = (char*) malloc(count * sizeof(char));
    count--;
    //printf("res : %d\n",res);
    while (res != 0)
    {
        int d = res % 10;
        //printf("%d\n",d);
        c[count--] = d + '0';
        res /= 10;
    }
    return c;
    
}


int toBinaryInt(char *ch, int n)
{
    int res=0;
    int multiplier = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        res = res + (ch[i] - '0') * (int) pow(2, multiplier);
        multiplier ++;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    char a[] = "1100";
    char b[] = "1";
    int anum = toBinaryInt(a, strlen(a));
    int bnum = toBinaryInt(b, strlen(b));
    int cnum = anum + bnum;
    char* c = toBinaryString(cnum);
    printf("%s",c);
    return 0;
}
