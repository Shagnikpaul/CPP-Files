#include <stdio.h>
#include <ctype.h>
int main()
{
    //// write da code here...
    int s;
    float f;
    if(scanf("%f",&f))
    {
        s=(int)f;
        if(s==f)
        {
            printf("int");
        }
        else
        {
            printf("float");
        }
        
        
    }
    else
    {
        printf("s");
    }
    return 0;
}