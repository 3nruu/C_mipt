#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    double pi = 0;
    scanf("%i", &n);

    for (int i = 1 ; i <= n ; i++)
    {
        pi += 4.0*pow(-1 , i+ 1 )/(2*i -1);

    }

    printf("%lf\n", pi);
    return 0;

}
