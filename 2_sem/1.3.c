#include <stdio.h>

int main()
{
    int a[1000];
    int n , q , b;
    scanf("%i", &n);
    for (int i = 0; i < n; ++i)
        scanf("%i", &a[i]);
    
    scanf("%i",&b);

    for (int i = b; i <n - 1; ++i)
        a[i] = a[i + 1];
    
    
    --n;

    for (int i = 0; i < n; ++i)
        printf("%i ", a[i]);
    printf("\n");
}