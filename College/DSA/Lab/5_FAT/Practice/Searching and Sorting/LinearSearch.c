#include <stdio.h>

void linearSearch(int *arr, int n, int key, int *ans);

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d, ", &arr[i]);
    }
    int key;
    scanf("%d", &key);
    int ans[2];
    ans[0] = -1;
    ans[1] = 0;
    linearSearch(arr, n, key, ans);
    printf("%d\n", ans[0]);
    printf("%d\n", ans[1]);
    return 0;
}

void linearSearch(int *arr, int n, int key, int *ans)
{
    for (int i = 0; i < n; i++)
    {
        ans[1]++;
        if (key == arr[i])
        {
            ans[0] = i;
            return;
        }
    }
    ans[0] = -1;
    return;
}
