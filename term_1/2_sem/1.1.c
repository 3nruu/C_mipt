#include <stdio.h>
int main()
{
    int a[1000];
    int n;
    scanf("%i", &n);
    for (int i = 0; i < n; ++i)
        scanf("%i", &a[i]);

    for (int i = 0; i < 2*n; ++i)
        a[i+n] = a[i];

    n = 2*n;



    for (int i = 0; i < n; ++i)
        printf("%i ", a[i]);
    printf("\n");
}