#include <stdio.h>

int sum_of_digits(int x)
{
    int sum = 0;
    while(x != 0)
    {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main()
{
    int a ;
    scanf("%i" , &a);
    printf("%i" , sum_of_digits(a));
}