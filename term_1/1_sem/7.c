#include <stdio.h>
#include <math.h>

int main()
{
    int n , m;

    scanf("%d %d", &n, &m);
    
    int sum = 0;

    
    for (int i = 1; i <= n; ++i)
    {

        for (int j = 1; j <= m; ++j)
            sum += pow(-1 ,-(i+j))*i*j;
    }

    printf("%i" , sum);
    return 0;
}