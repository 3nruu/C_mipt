#include <stdio.h>

void alice(int a);
void bob(int b);


void alice(int a)
{
    a = 3*a + 1;
    printf("Alice: %i \n" , a);
    bob(a);
}

void bob(int b)
{
    
    while (b % 2 == 0)
    {
        b /= 2;
        printf("Bob: %i \n" , b);
    }
    
     if (b == 1)
    {
        return;
    }

    alice(b);
}



int main()
{
    int a ;
    scanf("%i" , &a);
    alice(a);
}