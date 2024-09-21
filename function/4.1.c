#include <stdio.h>


int sum_of_digits_rec(int x , int sum)
{

    if (x != 0)
    {
        sum += x % 10;
        x /= 10;
        sum = sum_of_digits_rec(x , sum);
    }
    return sum;
    
}

int main()
{
    int a , sum;
    scanf("%i" , &a);
    printf("%i" , sum_of_digits_rec(a , 0));
}