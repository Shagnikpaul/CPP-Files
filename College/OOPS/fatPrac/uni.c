#include "stdio.h"

struct store
{

    union
    {
        struct
        {
        } i1;

        struct i2
        {
        } i2;
    } item;
};

int main()
{
    //// write da code here...
    typedef unsigned int kk;

    kk joe = 21;
    printf("%d", joe);
    struct store s11;
    s11.item.i2;

    return 0;
}