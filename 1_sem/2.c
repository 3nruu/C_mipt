#include <stdio.h>

int main()
{
    int a , b , c;
    scanf("%d %d %d", &a, &b, &c);

    if (b-a == 1 && c-b ==1)

        printf("Consecutive Increasing");

    else if (b-a == -1 && c-b == -1)

        printf("Consecutive Decreasing");

    else if (b-a > 0 && c-b > 0)
        
        printf("Increasing");

    else if (b-a < 0 && c-b < 0)
        
        printf("Decreasing");

    else
        printf("None");



    return 0;

}   