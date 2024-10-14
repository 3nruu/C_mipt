#include <stdio.h>
#include <stdlib.h>
#include <math.h>


float* get_geometric_progression(float a, float r, int n) {

    float* pr = (float*)malloc(sizeof(float) * n);

    for (int i = 0; i < n; i++)
    {
        pr[i] = a * pow(r , i);
    }

    return pr;
}


int main()
{
    float a = 1.0 , r = 3.0;
    int n = 10;

    float* pr = get_geometric_progression(a , r , n);

    for (int i = 0; i < n; i++)
    {
        printf("%f ",pr[i]);
    }

    free(pr);

    return 0;
}