#include <stdio.h>
#include <limits.h>

int main()
{

int n , flag1 , flag2;

scanf("%i", &n);

int min = INT_MAX;
int max = INT_MIN;
flag1 = 0;
flag2 = 0;

for (int i = 0; i < n; ++i)
{

    int a ;

    scanf("%i", &a);

    if (a % 2 == 0)
        {
        flag1 = 1;
        if (a < min ) 
            min = a;
        }
    
    else
        {
        flag2 = 1;
        if (a > min)
            max = a;
        }
}

if (flag1) 
        printf("Min_even = %d\n", min);
    else 
        printf("Min_even = None\n");

    if (flag2) 
        printf("Max_odd = %d\n", max);
    else 
        printf("Max_odd = None\n");

}