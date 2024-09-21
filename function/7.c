#include <stdio.h>

int count_even(int a[] , int n)
{
    int k = -1;
    for (int i = 0; i <= n ; i++)
    {
        if (a[i] % 2 ==0)
        k++;
    }

    return k;
}




int main() {
    int a[1000];
    int n;
    

    scanf("%i", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%i", &a[i]);
    }

    printf("%i" ,count_even(a ,n));

    return 0;
}
