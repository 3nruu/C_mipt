#include <stdio.h>

void print_even(int a , int b)
{
    for (int i = a; i <= b; i++)
        if (i%2 == 0)
        {
            printf("%i " , i);
        }
}

int main()
{
    int m , n ;
    scanf("%i %i" , &n , &m);
    print_even(n , m);
}