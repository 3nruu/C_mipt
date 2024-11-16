#include <stdio.h>


int trib(int x)
{
    if (x == 0 || x == 1)
        return 0;
    if (x == 2)
        return 1;
    
    int trib0 = 0 , trib1 = 0 , trib2 = 1 , tribqq;

    for(int i = 3 ; i <= x ; i++)
    {
        tribqq = trib0 + trib1 + trib2;
        trib0 = trib1;
        trib1 =trib2;
        trib2 = tribqq;
    }

    return trib2;

}

int main()
{
    int a ;
    scanf("%i" , &a);
    printf("%i" , trib(a));
}