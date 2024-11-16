#include <stdio.h>
#include <limits.h>


int func(int k)
{
    if (k%2 != 0)
        return 3*k + 1;
    else if (k%2 == 0)
        return k/2;

}


int main()
{
    int a , count = 1 ,max = INT_MIN;
    scanf("%d", &a);

    while (a != 1)
    {
        printf("%d ", a);
        a = func(a);
        if (a > max)
        {
            max = a;
        }
        count++;
        
    }
    
    printf("1\nLength = %i Max = %i" ,count ,max);
    return 0;

}

