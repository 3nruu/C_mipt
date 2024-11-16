#include <stdio.h>


float yearfrac(int n ,int year)
{
    if (year % 4 == 0)
    {
        return n/366.0;
    }
    else
    {
        return n/365.0;
    }
    

}

int main()
{
    int year , n;
    scanf("%i %i",&year , &n);
    printf("%f\n", yearfrac(n , year));
}
