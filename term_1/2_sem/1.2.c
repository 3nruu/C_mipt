#include <stdio.h>

int main()
{
    int a[1000];
    int n , q , b;
    scanf("%i", &n);
    for (int i = 0; i < n; ++i)
        scanf("%i", &a[i]);
    
    scanf("%i %i", &q , &b);

    for (int i = n; i > b + 1; --i)
        a[i] = a[i - 1];
    
    
    a[b+1] = q;

    ++n;

    for (int i = 0; i < n; ++i)
        printf("%i ", a[i]);
    printf("\n");
}