/*
23BCT0266
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char binStr[65];
    int result = 0;
    int digitVal;
    size_t len;
    printf("\n\n23BCT0266\n\n");
    if (printf("Enter a binary number: "), scanf("%64s", binStr) != 1)
        return 0;
    len = strlen(binStr);
    printf("\n\n23BCT0266\n\n");
    for (size_t idx = 0; idx < len; ++idx)
    {
        char ch = binStr[idx];
        if (ch == '0')
        {
            printf("D -> 0\n");
            printf("D.val = 0\n");
            digitVal = 0;
        }
        else if (ch == '1')
        {
            printf("D -> 1\n");
            printf("D.val = 1\n");
            digitVal = 1;
        }
        else
        {
            printf("Invalid input\n");
            return 0;
        }

        if (idx == 0)
        {
            printf("B -> D\n");
            printf("B.val = D.val = %d\n", digitVal);
            result = digitVal;
        }
        else
        {
            printf("B -> B D\n");
            printf("B.val = B.val * 2 + D.val = %d * 2 + %d = %d\n", result, digitVal, result * 2 + digitVal);
            result = result * 2 + digitVal;
        }

        printf("B.val = %d\n", result);
    }

    printf("%d\n", result);
    return 0;
}
