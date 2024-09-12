#include <stdio.h>

int main()
{
    int a[1000];
    int n , b1 , b2;
    scanf("%i", &n);
    for (int i = 0; i < n; ++i)
        scanf("%i", &a[i]);
    
    scanf("%i %i",&b1 , &b2);

    for (int i = b2 ; i < n; ++i)
        a[b1 + i - (b2)] = a[i];
        
    
    n = n - (b2 - b1);

    for (int i = 0; i < n; ++i)
        printf("%i ", a[i]);
    printf("\n");
}