#include <stdio.h>
#include <math.h>

int main()
{
    int x1 , y1, x2 , y2;
    float r1 , r2;
    float ro = 0;
    scanf("%i %i %f\n", &x1 , &y1 , &r1);
    scanf("%i %i %f", &x2 , &y2 , &r2);

    ro = pow( pow((x1 - x2) , 2.0) + pow((y1 - y2) , 2.0) , 0.5 );

 
    if (r1 + r2 > ro)
    {
        printf("Intersect");
    }
    else if (r1 + r2 < ro)
    {
        printf("Do not intersect");
    }
    else if (r1 + r2 == ro)
    {
        printf("Touch");
    }

    return 0;

}
