#include <stdio.h>
#include <limits.h>

int main()
{

int n;

scanf("%i", &n);

int max = INT_MIN;
int k = 1;

for (int i = 0; i < n; ++i)
{
    int a;
    scanf("%i", &a);
    if (a > max)
    max = a;
    else if (a == max)
        k++;
}

printf("%i %i", max , k);
}
