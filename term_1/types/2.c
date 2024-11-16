#include <stdio.h>


long long fact(int n)
{
    long long result = 1;
    for (int i = 1; i <= n; ++i)
        result *= i;
    return result;

}

int main()
{
    int n , k;
    scanf("%i %i",&n , &k);
    printf("%lli\n", fact(n)/fact(n - k));
}
