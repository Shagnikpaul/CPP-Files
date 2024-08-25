#include "stdio.h"
#include "stdlib.h"
int main()
{
    int digits[] = {9,8,9};
    int returnSize = 0;
    int digitsSize = 3;
    int carry = 0;
    if ((digits[digitsSize - 1] + 1) > 9)
    {
        digits[digitsSize - 1] = (digits[digitsSize - 1] + 1) % 10;
        carry = 1;
        for (int i = digitsSize - 2; i >= 0; i--)
        {
            if (carry != 0)
            {
                if ((digits[i] + 1) > 9)
                {
                    digits[i] = (digits[i] + 1) % 10;
                    carry = 1;
                }
                else
                {
                    digits[i]++;
                    carry = 0;
                    break;
                }
            }
        }
    }
    else
    {
        digits[digitsSize - 1]++;
        returnSize = digitsSize;
    }
    int* returnarr;
    if(carry == 1){
        returnSize = digitsSize + 1;
        returnarr = (int*)malloc(returnSize * sizeof(int));
        returnarr[0] = carry;
        for(int i = 1; i<returnSize;i++){
            returnarr[i] = digits[i-1];
        }
    }
    else{
        returnSize = digitsSize;
        returnarr = (int*)malloc(digitsSize * sizeof(int));
        for(int i = 0; i<returnSize;i++){
            returnarr[i] = digits[i];
        }
    }
    
    for(int i=0;i<returnSize;i++){
        printf("%d, ",returnarr[i]);
    }
    return 0;
}