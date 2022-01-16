#include <cstdio>

int n, x, a[10005];

int main()
{
    scanf("%d %d", &n, &x);
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    
    for (int i = 0; i < n; i++)
    {
        if (a[i] < x)
        {
            printf("%d ", a[i]);
        }
    }
}
