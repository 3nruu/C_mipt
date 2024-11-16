#include <stdio.h>

void cube(float* px)
{
    *px *= (*px) * (*px);
}


int main()
{
    float a = 1.5;
    float* p = &a;
    cube(p);
    printf("%f" , a);
    return 0;
}