#include <stdio.h>

int main()
{
    int a[1000] , b[1000] , c[1000];
    int n ;
    scanf("%i", &n);
    for (int i = 0; i < n; ++i)
        scanf("%i", &a[i]);


    int n1 = 0 , n2 = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 == 0) {
            b[n1] = a[i];
            ++n1;
        
        }   else{
            c[n2] = a[i];
            ++n2;
        }
    }
    
    for (int i = 0; i < n1; ++i)
        printf("%i ", b[i]);
    printf("\n");

    for (int i = 0; i < n2; ++i)
        printf("%i ", c[i]);
    printf("\n");


    int k = 0;

    for(int i = 0 ; i < n1; ++i)
        a[k] = c[i];
        ++k;
        
    for(int i = 0 ; i < n2; ++i)
        a[k] = b[i];
        ++k;



    for (int i = 0; i < k; ++i)
        printf("%i ", a[i]);
    printf("\n");
}