#include <stdio.h>


void print_binary(int x)
{
    if (x < 2) {
        printf("%d", x);
        return;
    }
    print_binary(x/2);
    printf("%i" , x % 2);
}

int main()
{
    int a ;
    scanf("%i" , &a);
    print_binary(a);
}