#include "stdio.h"

struct hello
{
    int x;
    char name[50];
    float val;
};

typedef struct koniko
{
    int k;
    float f;
} k;

int joe(k k1, k k2)
{
    return k1.k + k2.k;
}

int main()
{
    //// write da code here...
    struct hello h1 = {1, "wadqw", 3.4};

    struct hello hs[20];

    k k1;
    k1.f = 3.34;
    k1.k = 12;

    // for (int i = 0; i < 20; i++)
    // {
    //     scanf("%d %s %f", &hs[i].x, hs[i].name, &hs[i].val);
    // }

    printf("%d", h1.x);
    printf(" %s", h1.name);
    printf("%d ", joe(k1, k1));
    return 0;
}