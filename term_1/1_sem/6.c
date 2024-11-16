#include <stdio.h>
#include <limits.h>


int func(int k)
{
    if (k%2 != 0)
        return 3*k + 1;
    else if (k%2 == 0)
        return k/2;

}


int len(int a)
{
    int count = 1 ;
    while (a != 1)
    {
        a = func(a);
        count++; 
    }
    return count;

}

int main()
{
    int a , b;

    scanf("%d %d", &a, &b);
    
    int max_length = 0 , length;
    int best_n = a;
    
    for (int i = a; i <= b; ++i)
    {
        length = len(i);
        if (length > max_length)
        {
            max_length = length;
            best_n = i;
        }
    }
    printf("%d %d\n", best_n, max_length);
    
    return 0;
}